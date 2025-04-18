const std = @import("std");
const lua = @import("lua_api/lua.zig");

const Hl = @import("hl.zig");
const consts = @import("nvim_api/constants.zig");
const fns = @import("nvim_api/functions.zig");
const tps = @import("nvim_api/types.zig");

const Line = struct {
    chars: std.ArrayListUnmanaged(u8),
    hls: std.ArrayListUnmanaged(Hl.HlAttrs),
    width: u32,

    pub fn init() Line {
        return .{
            .chars = .empty,
            .hls = .empty,
            .width = 0,
        };
    }
    pub fn deinit(self: *Line, alloc: std.mem.Allocator) void {
        self.chars.deinit(alloc);
        self.hls.deinit(alloc);
    }
    pub fn appendWord(self: *Line, ctx: *BoxContext, str: []const u8, hl: Hl.HlAttrs) !void {
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
        hl: Hl.HlAttrs,
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
    pub fn stripRightSpace(self: *BoxContext, expectedBg: Hl.HlAttrs) !void {
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
};

pub const Box = extern struct {
    context: *BoxContext,
    offsetX: u32,
    offsetY: u32,
    width: u32,
    maxWidth: u32,
    height: u32,
    dirty: bool,
    currentLine: u32,
    hlgroup: Hl.HlAttrs,
    // TODO: Need to work on this
    // pub fn insertGradientMarker(){}
    // pub fn setGradientSize(){}

    // TODO: Internal behavior
    // pub fn fillString(width){}

    pub fn newBoxFromContext(ctx: *BoxContext, hlgroup: Hl.HlAttrs) Box {
        // @compileLog(std.fmt.comptimePrint("{}\n", .{@sizeOf(Hl.HlAttrs)}));
        return .{
            .height = 0,
            .context = ctx,
            .offsetX = 0,
            .offsetY = 0,
            .width = 0,
            .maxWidth = std.math.maxInt(@FieldType(Box, "width")),
            .dirty = false,
            .currentLine = 0,
            .hlgroup = hlgroup,
        };
    }
    pub fn newBoxFromOffset(self: *Box, x: u32, y: u32) Box {
        return .{
            .currentLine = 0,
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

    // prettry sure this is only used for canvas
    pub fn shrinkWidthTo(self: *Box, width: u32) !void {
        _ = self; // autofix
        _ = width; // autofix
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
    pub fn clone(
        self: *Box,
    ) BoxContext {
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
        const line = self.context.getLine(self.currentLine + self.offsetY);
        if (line == null) {
            return error.LineIsNull;
        }
        // TODO: Bounds checking and wrapping
        try line.?.appendWord(self.context, str, self.hlgroup);
    }
    // pub fn appendStr(self: *Box, str: [*]const u8, len: u32) bool {
    //     self.appendStr_internal(str[0..len]) catch return false;
    //     return true;
    // }
    pub fn appendWord(self: *Box, str: []const u8, style: Hl.HlAttrs) !void {
        const line = self.context.getLine(self.currentLine + self.offsetY);
        try line.?.appendWord(self.context, str, style);
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
pub export fn box_new_context() i32 {
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

pub fn lua_new_context(state: *lua.State) callconv(.C) c_int {
    const res = box_new_context();
    lua.push_number(state, @floatFromInt(res));
    return 1;
}

pub export fn box_delete_context(ctx: u32) bool {
    if (ctx >= contexts.items.len) {
        return false;
    }
    if (contexts.items[ctx]) |*context| {
        context.deinit();
    }
    contexts.items[ctx] = null;
    return true;
}

pub fn lua_delete_context(state: *lua.State) callconv(.C) c_int {
    const numArgs = lua.get_top(state);
    if (numArgs != 1) {
        lua.push_boolean(state, @intFromBool(false));
        return 1;
    }
    const indexFloat = lua.to_number(state, 1);
    const index: u32 = @intFromFloat(indexFloat);
    const ret = box_delete_context(index);
    lua.push_boolean(state, @intFromBool(ret));
    return 1;
}

pub fn get_context(ctx: u32) ?*BoxContext {
    if (ctx >= contexts.items.len) {
        return null;
    }
    if (contexts.items[ctx]) |*c| return c;
    return null;
}
pub export fn box_context_exists(ctx: u32) bool {
    if (ctx >= contexts.items.len) {
        return false;
    }
    return contexts.items[ctx] != null;
}

pub fn lua_context_exists(state: *lua.State) callconv(.C) c_int {
    const numArgs = lua.get_top(state);
    if (numArgs != 1) {
        lua.push_boolean(state, @intFromBool(false));
        return 1;
    }
    const indexFloat = lua.to_number(state, 1);
    const index: u32 = @intFromFloat(indexFloat);
    const ret = box_context_exists(index);
    lua.push_boolean(state, @intFromBool(ret));
    return 1;
}

pub export fn box_context_render(ctx: u32, buf: u32) bool {
    const context = get_context(ctx) orelse return false;
    context.render(buf) catch return false;
    return true;
}

pub fn lua_context_render(L: *lua.State) callconv(.C) c_int {
    const numArgs = lua.get_top(L);
    if (numArgs != 2) {
        lua.push_bool(L, false);
        return 1;
    }
    const ctx = lua.to_int(L, 1);
    const buf = lua.to_int(L, 2);
    const ret = box_context_render(@intCast(ctx), @intCast(buf));
    lua.push_bool(L, ret);
    return 1;
}
pub export fn box_new_from_ctx(ctx: u32, hlgroup: Hl.HlAttrs) i32 {
    const context = &contexts.items[ctx].?;
    const ret = context.newBox(Box.newBoxFromContext(context, hlgroup));
    if (ret) |r| return @intCast(r);
    return -1;
}

pub fn lua_new_from_ctx(L: *lua.State) callconv(.C) c_int {
    const numArgs = lua.get_top(L);
    if (numArgs != 1) {
        lua.push_number(L, @floatFromInt(-1));
        return 1;
    }
    const ctxFloat = lua.to_number(L, 1);
    const ctx: u32 = @intFromFloat(ctxFloat);
    const ret = box_new_from_ctx(ctx, .{});
    lua.push_number(L, @floatFromInt(ret));
    return 1;
}
pub export fn box_new_from_offset(ctx: u32, box: u32, x: u32, y: u32) i32 {
    const self = box_get(ctx, box) orelse return -1;
    const ret = self.context.newBox(self.newBoxFromOffset(x, y));
    if (ret) |r| return @intCast(r);
    return -1;
}

pub fn lua_new_from_offset(L: *lua.State) callconv(.C) c_int {
    const numArgs = lua.get_top(L);
    if (numArgs != 4) {
        lua.push_int(L, -1);
        return 1;
    }
    const ctx = lua.to_int(L, 1);
    const box = lua.to_int(L, 2);
    const x = lua.to_int(L, 3);
    const y = lua.to_int(L, 4);
    const ret = box_new_from_offset(@intCast(ctx), @intCast(box), @intCast(x), @intCast(y));
    lua.push_int(L, ret);
    return 1;
}

// prettry sure this is only used for canvas
pub export fn box_shrink_width_to(self: *Box, width: u32) bool {
    self.shrinkWidthTo(width) catch return false;
    return true;
}
pub export fn box_set_width(self: *Box, width: u32) bool {
    self.setWidth(width) catch return false;
    return true;
}
pub export fn box_expand_width_to(self: *Box, width: u32) bool {
    self.expandWidthTo(width) catch return false;
    return true;
}

pub fn box_expand_height_to(self: *Box, height: u32) bool {
    self.expandHeightTo(height) catch return false;
    return true;
}
pub export fn box_shrink_height_to(self: *Box, height: u32) bool {
    self.shrinkHeightTo(height) catch return false;
    return true;
}

pub export fn box_set_height(self: *Box, height: u32) bool {
    self.setHeight(height) catch return false;

    return true;
}

pub fn box_clean(self: *Box) bool {
    self.clean() catch return false;
    return true;
}

// *kinda* one of the most needed low level apis

pub export fn box_append_str(self: *Box, str: [*]const u8, len: u32) bool {
    self.appendStr(str[0..len]) catch return false;
    return true;
}

pub export fn box_get(ctx: u32, box: u32) ?*Box {
    const context = get_context(ctx) orelse return null;
    return context.getBox(box);
}

pub fn lua_append_str(L: *lua.State) callconv(.C) c_int {
    const numArgs = lua.get_top(L);
    if (numArgs != 3) {
        lua.push_boolean(L, @intFromBool(false));
        return 1;
    }
    const ctxFloat = lua.to_number(L, 1);
    const ctx: u32 = @intFromFloat(ctxFloat);
    const boxFloat = lua.to_number(L, 2);
    const boxIndex: u32 = @intFromFloat(boxFloat);
    const box = box_get(ctx, boxIndex);
    const str = lua.to_slice(L, 3);
    // std.debug.print("SLICE: {s}\n", .{str});

    if (box == null) {
        lua.push_bool(L, false);
        return 1;
    }
    box.?.appendStr(str) catch {
        lua.push_bool(L, false);
        return 1;
    };
    lua.push_bool(L, true);
    return 1;
}

// pub fn appendStr(elf: *Box, str: [*]const u8, len: u32) bool {
//     self.appendStr_internal(str[0..len]) catch return false;
//     return true;
// }

pub export fn box_append_word(self: *Box, str: [*]const u8, len: u32, style: Hl.HlAttrs) bool {
    self.appendWord(str[0..len], style) catch return false;
    return true;
}
// TODO: Remove in favor of managed splitting
// pb fn getLine(i){}

// TODO: Remove in fvor of offsets

// pub fn appendBoxBelow(box, expand){}

pub export fn box_strip_right_space(ctx: u32, expected_bg: Hl.HlAttrs) bool {
    const context = &contexts.items[ctx].?;
    context.stripRightSpace(expected_bg) catch return false;
    return true;
}
// TODO: Unused

// pub fn trimWidthLastLine(width, trimStrat){}

// NOTE: Rendering over should *only* happen from prepared box contexts

pub export fn box_render_over(self: *Box, other: u32, left: u32, top: u32) bool {
    const ctx = &contexts.items[other].?;
    self.renderOver(ctx, left, top) catch return false;
    return true;
}
