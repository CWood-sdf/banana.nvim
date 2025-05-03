// TODO: Box.destroy()
const std = @import("std");
const lua = @import("lua_api/lua.zig");

const Hl = @import("hl.zig");
const consts = @import("nvim_api/constants.zig");
const fns = @import("nvim_api/functions.zig");
const tps = @import("nvim_api/types.zig");

const Highlight = u32;

fn codepointLen(char: u8) u8 {
    if (char < 128) {
        return 1;
    }

    if (char < 224) {
        return 2;
    }

    if (char < 240) {
        return 3;
    }

    return 4;
}

const Line = struct {
    chars: std.ArrayListUnmanaged(u8),
    hls: std.ArrayListUnmanaged(Highlight),
    width: u32,

    pub fn init() Line {
        return .{
            .chars = .empty,
            .hls = .empty,
            .width = 0,
        };
    }

    pub fn popLastChar(self: *Line) void {
        var i = @min(self.chars.items.len, 4);
        var popCount: u32 = 1;
        while (i > 0) {
            if (codepointLen(self.chars.items[self.chars.items.len - i]) == i) {
                popCount = i;
                break;
            }
            i -= 1;
        }
        const str = self.chars.items[self.chars.items.len - popCount .. self.chars.items.len];
        const widthDelta = fns.z_nvim_strwidth(str) catch 1;
        for (0..i) |_| {
            _ = self.chars.pop();
            _ = self.hls.pop();
        }
        if (widthDelta > self.width) {
            self.width = 0;
        } else {
            self.width -= @intCast(widthDelta);
        }
    }
    pub fn deinit(self: *Line, alloc: std.mem.Allocator) void {
        self.chars.deinit(alloc);
        self.hls.deinit(alloc);
    }
    pub fn appendWord(self: *Line, ctx: *BoxContext, str: []const u8, hl: Highlight) !void {
        const width = try fns.z_nvim_strwidth(str);
        try self.chars.appendSlice(ctx.alloc, str);
        self.hls.appendNTimes(ctx.alloc, hl, str.len) catch |e| {
            self.chars.shrinkRetainingCapacity(self.chars.items.len - str.len);
            return e;
        };
        self.width += @intCast(width);
    }

    pub fn appendCharNTimes(
        self: *Line,
        ctx: *BoxContext,
        char: u8,
        hl: Highlight,
        n: u32,
    ) !void {
        try self.chars.appendNTimes(ctx.alloc, char, n);
        self.hls.appendNTimes(ctx.alloc, hl, n) catch |e| {
            self.chars.shrinkRetainingCapacity(self.chars.items.len - n);
            return e;
        };
        self.width += n;
    }
    pub fn widthFrom(self: *Line, base: u32) u32 {
        return self.width - base;
    }
};

var contexts: std.ArrayListUnmanaged(?BoxContext) = .empty;

/// This is just supposed to be a structureless buffer for boxes to render to
pub const BoxContext = struct {
    lines: std.ArrayListUnmanaged(Line) = .empty,
    alloc: std.mem.Allocator = std.heap.page_allocator,
    boxes: std.ArrayListUnmanaged(Box) = .empty,

    // ctor/dtor
    pub fn init(alloc: std.mem.Allocator) BoxContext {
        return .{
            .lines = .empty,
            .boxes = .empty,
            .alloc = alloc,
        };
    }
    pub fn newBox(self: *BoxContext, box: Box) ?u32 {
        self.boxes.append(self.alloc, box) catch return null;
        return @intCast(self.boxes.items.len - 1);
    }
    pub fn getBox(self: *const BoxContext, box: u32) ?*Box {
        if (box >= self.boxes.items.len) {
            return null;
        }
        return &self.boxes.items[box];
    }
    pub fn deinit(self: *BoxContext) void {
        for (self.lines.items) |*line| {
            line.deinit(self.alloc);
        }
        self.lines.deinit(self.alloc);
        self.boxes.deinit(self.alloc);
    }
    pub fn stripRightSpace(self: *BoxContext, expectedBg: Highlight) !void {
        _ = self; // autofix
        _ = expectedBg; // autofix
    }

    pub fn getLine(self: *BoxContext, line: u32) ?*Line {
        while (self.lines.items.len <= line) {
            self.lines.append(self.alloc, Line.init()) catch return null;
        }
        return &self.lines.items[line];
    }
    pub fn render(self: *BoxContext, buf: tps.Integer) !void {
        var err = tps.Error{ .type = .None, .msg = @ptrFromInt(0) };
        var arena: tps.Arena = .{
            .current_block = "",
            .size = 0,
            .pos = 0,
        };
        const arr = try self.alloc.alloc(tps.Object, self.lines.items.len);
        defer self.alloc.free(arr);

        for (self.lines.items, 0..) |line, i| {
            arr[i] = tps.stringObject(line.chars.items);
        }
        const replacement: tps.Array = .{
            .size = self.lines.items.len,
            .items = arr.ptr,
            .capacity = self.lines.items.len,
        };
        fns.nvim_buf_set_lines(
            consts.LUA_INTERNAL_CALL,
            @enumFromInt(buf),
            0,
            -1,
            false,
            replacement,
            &arena,
            &err,
        );

        if (err.type != .None) {
            switch (err.type) {
                .Exception => return tps.NvimError.Exception,
                .Validation => return tps.NvimError.Validation,
                else => {},
            }
        }
    }
    pub fn highlight(self: *BoxContext, L: *lua.State, pos: c_int) void {
        // if (!lua.is_function(L, 1)) {
        //     return error.NotAFunction;
        // }
        for (self.lines.items, 0..) |line, row| {
            if (line.hls.items.len == 0) {
                continue;
            }
            var startCol: u32 = 0;
            var currentHl: Highlight = line.hls.items[0];
            for (line.hls.items, 0..) |hl, col| {
                if (currentHl != hl) {
                    if (currentHl != 0) {
                        lua.push_value(L, pos);
                        lua.push_int(L, @intCast(row));
                        lua.push_int(L, @intCast(startCol));
                        lua.push_int(L, @intCast(col));
                        lua.push_int(L, @intCast(currentHl));
                        lua.call(L, 4, 0);
                    }
                    currentHl = hl;
                    startCol = @intCast(col);
                }
            }
            if (startCol != line.hls.items.len - 1 and currentHl != 0) {
                lua.push_value(L, pos);
                lua.push_int(L, @intCast(row));
                lua.push_int(L, @intCast(startCol));
                lua.push_int(L, @intCast(line.hls.items.len));
                lua.push_int(L, @intCast(currentHl));
                lua.call(L, 4, 0);
            }
        }
    }
};

pub const Box = extern struct {
    context: *BoxContext,
    offsetX: u32,
    offsetY: u32,
    width: u32,
    maxWidth: u32,
    height: u32,
    dirty: bool,
    hlgroup: Highlight,
    cursorX: u32,
    cursorY: u32,
    // TODO: Need to work on this
    // pub fn insertGradientMarker(){}
    // pub fn setGradientSize(){}

    // TODO: Internal behavior
    // pub fn fillString(width){}

    pub fn newBoxFromContext(ctx: *BoxContext, hlgroup: Highlight) Box {
        // @compileLog(std.fmt.comptimePrint("{}\n", .{@sizeOf(Highlight)}));
        return .{
            .height = 0,
            .context = ctx,
            .offsetX = 0,
            .offsetY = 0,
            .width = 0,
            .maxWidth = std.math.maxInt(@FieldType(Box, "width")),
            .dirty = false,
            .hlgroup = hlgroup,
            .cursorX = 0,
            .cursorY = 0,
        };
    }
    pub fn newBoxFromOffset(self: *Box, x: u32, y: u32) Box {
        return .{
            .height = 0,
            .context = self.context,
            .offsetX = self.offsetX + x,
            .offsetY = self.offsetY + y,
            .width = 0,
            .maxWidth = std.math.maxInt(@FieldType(Box, "width")),
            .dirty = false,
            .hlgroup = self.hlgroup,
        };
    }

    pub fn newBoxCursored(self: *Box) Box {
        return .{
            .height = 0,
            .context = self.context,
            .offsetX = self.offsetX,
            .offsetY = self.offsetY,
            .cursorX = self.cursorX,
            .cursorY = self.cursorY,
            .width = 0,
            .maxWidth = std.math.maxInt(@FieldType(Box, "width")),
            .dirty = false,
            .hlgroup = self.hlgroup,
        };
    }

    pub fn newBoxRightOf(self: *Box) Box {
        return .{
            .height = 0,
            .context = self.context,
            .offsetX = self.offsetX + self.width,
            .offsetY = self.offsetY,
            .width = 0,
            .maxWidth = std.math.maxInt(@FieldType(Box, "width")),
            .dirty = false,
            .hlgroup = self.hlgroup,
            .cursorX = 0,
            .cursorY = 0,
        };
    }

    // prettry sure this is only used for canvas
    pub fn shrinkWidthTo(self: *Box, width: u32) !void {
        for (self.offsetY..self.offsetY + self.height) |i| {
            const line: *Line = &self.context.lines.items[i];
            while (line.width > width) {
                line.popLastChar();
            }
        }
    }
    pub fn setWidth(self: *Box, width: u32) !void {
        if (self.width == width) {
            return;
        }
        if (self.width < width) {
            try self.expandWidthTo(width);
        } else {
            try self.shrinkWidthTo(width);
        }
    }
    pub fn expandWidthTo(self: *Box, width: u32) !void {
        if (width < self.width) {
            return error.HeightTooSmall;
        }
        if (width == self.width) return;
        self.width = width;
        self.dirty = true;
        try self.clean();
    }
    // TODO: Used for debugging ONLY
    pub fn clone(self: *Box) BoxContext {
        _ = self; // autofix
    }
    // TODO: Unused?
    // pub fn cloneHeightTo(height){}

    pub fn expandHeightTo(self: *Box, height: u32) !void {
        if (height < self.height) {
            return error.HeightTooSmall;
        }
        for (0..self.height - height) |_| {
            try self.context.lines.append(self.context.alloc, Line.init());
            try self.context.lines.items[self.context.lines.items.len - 1].appendCharNTimes(
                self.context,
                ' ',
                self.hlgroup,
                self.width,
            );
        }
    }
    pub fn shrinkHeightTo(self: *Box, height: u32) !void {
        if (height > self.height) {
            return error.HeightTooBig;
        }
        for (0..(self.height - height)) |_| {
            self.context.lines.items[self.context.lines.items.len - 1].deinit(self.context.alloc);
            _ = self.context.lines.pop();
        }
    }
    pub fn setHeight(self: *Box, height: u32) !void {
        if (self.height == height) {
            return;
        }
        if (self.height < height) {
            try self.expandHeightTo(height);
        } else {
            try self.shrinkHeightTo(height);
        }
    }

    pub fn clean(self: *Box) !void {
        if (!self.dirty) {
            return;
        }
        for (self.context.lines.items[self.offsetY .. self.offsetY + self.height]) |*line| {
            if (line.widthFrom(self.offsetX) > self.width) {
                return error.LineTooBig;
            }
            if (line.widthFrom(self.offsetX) < self.width) {
                try line.appendCharNTimes(self.context, ' ', self.hlgroup, self.width - line.widthFrom(self.offsetX));
            }
        }
        self.dirty = false;
    }

    // TODO: Should be removable with offsets. BoxContext should have appendLeft for flex display (could prolly even get away with just renderOver)
    // pub fn append(box, strat){}

    // *kinda* one of the most needed low level apis
    pub fn appendStr(self: *Box, str: []const u8) !void {
        var pushedBytes = 0;

        var isFirst = true;
        while (pushedBytes < str.len) {
            if (!isFirst) {
                self.cursorY += 1;
                self.cursorX = 0;
            }
            const maxWidth = self.maxWidth - self.cursorX;
            const slice = try fns.sliceToWidth(str, maxWidth);
            const strWidth = try fns.z_nvim_strwidth(slice);
            const line = self.context.getLine(self.cursorY + self.offsetY);
            if (line == null) {
                return error.LineIsNull;
            }
            // TODO: Bounds checking and wrapping
            try line.?.appendWord(self.context, slice, self.hlgroup);
            pushedBytes += slice.len;
            self.cursorX += strWidth;
            isFirst = false;
        }
    }

    pub fn updateCursorFrom(self: *Box, other: *Box) void {
        self.cursorX = other.cursorX;
        self.cursorY = other.cursorY;
    }
    // pub fn appendStr(self: *Box, str: [*]const u8, len: u32) bool {
    //     self.appendStr_internal(str[0..len]) catch return false;
    //     return true;
    // }
    pub fn appendWord(self: *Box, str: []const u8, style: Highlight) !void {
        const currentHl = self.hlgroup;
        self.hlgroup = style;
        defer self.hlgroup = currentHl;
        try self.appendStr(str);
    }
    // TODO: Remove in favor of managed splitting
    // pub fn getLine(i){}

    // TODO: Remove in favor of offsets
    // pub fn appendBoxBelow(box, expand){}

    // TODO: Unused
    // pub fn trimWidthLastLine(width, trimStrat){}

    // NOTE: Rendering over should *only* happen from prepared box contexts
    pub fn renderOver(self: *Box, other: *BoxContext, left: u32, top: u32) !void {
        if (self.context == other) {
            return error.SameContext;
        }
        _ = left; // autofix
        _ = top; // autofix
    }
};

pub fn get_context(ctx: u32) ?*BoxContext {
    if (ctx >= contexts.items.len) {
        return null;
    }
    if (contexts.items[ctx]) |*c| return c;
    return null;
}

pub fn get_box(ctx: u32, box: u32) ?*Box {
    const context = get_context(ctx) orelse return null;
    return context.getBox(box);
}

// new context {
/// Returns -1 on failure
/// @return i32 the id of a new box context
pub fn box_context_create() i32 {
    for (contexts.items, 0..) |item, i| {
        if (item) |_| continue;
        contexts.items[i] = BoxContext.init(std.heap.page_allocator);
        return @intCast(i);
    }
    contexts.append(std.heap.page_allocator, null) catch return -1;
    const i = contexts.items.len - 1;
    contexts.items[i] = BoxContext.init(std.heap.page_allocator);
    return @intCast(i);
}

// }

// delete context {
/// In all cases, if ctx is valid it will be deleted
/// @param ctx u32 A box context id
/// @return bool whether the context existed or not
pub fn box_context_delete(ctx: u32) bool {
    if (ctx >= contexts.items.len) {
        return false;
    }
    if (contexts.items[ctx]) |*context| {
        context.deinit();
    }
    contexts.items[ctx] = null;
    return true;
}

// }

// context exists {
/// @retrun ctx u32 a box context id
/// @return bool whether the context exists or not
pub fn box_context_exists(ctx: u32) bool {
    if (ctx >= contexts.items.len) {
        return false;
    }
    return contexts.items[ctx] != null;
}
// }

// context render {
///
pub fn box_context_render(ctx: u32, buf: u32) bool {
    const context = get_context(ctx) orelse return false;
    context.render(buf) catch return false;
    return true;
}

/// Here so that functions can get lua functions/tables and document
/// what they want from the type
pub fn Expect(tp: type) type {
    return struct {
        L: *lua.State,
        pub const isLua = true;
        pub const T = tp;
    };
}

const HlExpect = Expect(fn (line: i32, startCol: i32, endCol: i32, hl: i32) void);
pub fn box_context_highlight(ctx: u32, L: HlExpect) bool {
    const context = get_context(ctx) orelse return false;
    context.highlight(L.L, 2);
    return true;
}

// new box from ctx {
pub fn box_new_from_context(ctx: u32, hlgroup: Highlight) i32 {
    const context = &(contexts.items[ctx] orelse return -1);
    const ret = context.newBox(Box.newBoxFromContext(context, hlgroup));
    if (ret) |r| return @intCast(r);
    return -1;
}
// }

// new box from offset {
pub fn box_new_from_offset(ctx: u32, box: u32, x: u32, y: u32) i32 {
    const self = get_box(ctx, box) orelse return -1;
    const ret = self.context.newBox(self.newBoxFromOffset(x, y));
    if (ret) |r| return @intCast(r);
    return -1;
}
// }

// new box right {
pub fn box_new_right_from(ctx: u32, box: u32) i32 {
    const self = get_box(ctx, box) orelse return -1;
    const ret = self.context.newBox(self.newBoxRightOf());
    if (ret) |r| return @intCast(r);
    return -1;
}

pub fn box_new_cursored(ctx: u32, box: u32) i32 {
    const self = get_box(ctx, box) orelse return -1;
    const ret = self.context.newBox(self.newBoxCursored());
    if (ret) |r| return @intCast(r);
    return -1;
}
// }

// prettry sure this is only used for canvas
pub fn box_shrink_width_to(ctx: u32, box: u32, width: u32) bool {
    const self = get_box(ctx, box) orelse return false;
    self.shrinkWidthTo(width) catch return false;
    return true;
}
pub fn box_update_cursor_from(ctx: u32, box: u32, other: u32) bool {
    const self = get_box(ctx, box) orelse return false;
    const otherBox = get_box(ctx, other) orelse return false;
    self.updateCursorFrom(&otherBox);
    return true;
}
pub fn box_set_width(ctx: u32, box: u32, width: u32) bool {
    const self = get_box(ctx, box) orelse return false;
    self.setWidth(width) catch return false;
    return true;
}

pub fn box_set_max_width(ctx: u32, box: u32, width: i32) bool {
    const self = get_box(ctx, box) orelse return false;
    self.maxWidth = @max(width, 0);
    return true;
}
pub fn box_get_width(ctx: u32, box: u32) i32 {
    const self = get_box(ctx, box) orelse return -1;
    return @intCast(self.width);
}
pub fn box_expand_width_to(ctx: u32, box: u32, width: u32) bool {
    const self = get_box(ctx, box) orelse return false;
    self.expandWidthTo(width) catch return false;
    return true;
}

pub fn box_expand_height_to(ctx: u32, box: u32, height: u32) bool {
    const self = get_box(ctx, box) orelse return false;
    self.expandHeightTo(height) catch return false;
    return true;
}
pub fn box_shrink_height_to(ctx: u32, box: u32, height: u32) bool {
    const self = get_box(ctx, box) orelse return false;
    self.shrinkHeightTo(height) catch return false;
    return true;
}

pub fn box_set_height(ctx: u32, box: u32, height: u32) bool {
    const self = get_box(ctx, box) orelse return false;
    self.setHeight(height) catch return false;
    return true;
}

pub fn box_get_height(ctx: u32, box: u32) i32 {
    const self = get_box(ctx, box) orelse return -1;
    return @intCast(self.height);
}

pub fn box_clean(ctx: u32, box: u32) bool {
    const self = get_box(ctx, box) orelse return false;
    self.clean() catch return false;
    return true;
}

// *kinda* one of the most needed low level apis
// append str {
pub fn box_append_str(ctx: u32, box: u32, str: []const u8) bool {
    const self = get_box(ctx, box) orelse return false;
    self.appendStr(str) catch return false;
    return true;
}
// }

// pub fn appendStr(elf: *Box, str: [*]const u8, len: u32) bool {
//     self.appendStr_internal(str[0..len]) catch return false;
//     return true;
// }

// set hl {
pub fn box_set_hl(ctx: u32, box: u32, style: u32) bool {
    const self = get_box(ctx, box) orelse return false;
    self.hlgroup = style;
    return true;
}
// }

pub fn box_append_word(ctx: u32, box: u32, str: []const u8, style: Highlight) bool {
    const self = get_box(ctx, box) orelse return false;
    self.appendWord(str, style) catch return false;
    return true;
}
// TODO: Remove in favor of managed splitting
// pb fn getLine(i){}

// TODO: Remove in fvor of offsets

// pub fn appendBoxBelow(box, expand){}

pub fn box_strip_right_space(ctx: u32, expected_bg: Highlight) bool {
    const context = &(contexts.items[ctx] orelse return false);
    context.stripRightSpace(expected_bg) catch return false;
    return true;
}
// TODO: Unused

// pub fn trimWidthLastLine(width, trimStrat){}

// NOTE: Rendering over should *only* happen from prepared box contexts

pub fn box_render_over(ctx: u32, box: u32, otherCtx: u32, left: u32, top: u32) bool {
    const self = get_box(ctx, box) orelse return false;
    const context = &contexts.items[otherCtx].?;
    self.renderOver(context, left, top) catch return false;
    return true;
}
