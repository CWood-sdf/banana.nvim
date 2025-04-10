const std = @import("std");

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
        // zig fmt: off
        return .{ 
            .lines = .empty, 
            .boxes = .empty,
            .alloc = alloc,
        };
        // zig fmt: on
    }
    pub fn newBox(self: *BoxContext, box: Box) ?*Box {
        self.boxes.append(self.alloc, box) catch return null;
        return &self.boxes.items[self.boxes.items.len - 1];
    }
    pub fn deinit(self: *BoxContext) void {
        for (self.lines.items) |*line| {
            line.deinit(self.alloc);
        }
        self.lines.deinit(self.alloc);
        self.boxes.deinit(self.alloc);
    }
    pub fn stripRightSpace(self: *BoxContext, expectedBg: Hl.HlAttrs) !void {
        _ = self;
        _ = expectedBg;
    }
    pub fn getLine(self: *BoxContext, line: u32) ?*Line {
        while (self.lines.items.len <= line) {
            self.lines.append(self.alloc, Line.init()) catch return null;
        }
        return &self.lines.items[line];
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
        _ = self;
        _ = width;
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
        _ = self;
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
        const line = self.context.getLine(self.currentLine);
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
        const line = self.context.getLine(self.currentLine);
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
        _ = self;
        _ = other;
        _ = left;
        _ = top;
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

pub export fn box_delete_context(ctx: u32) void {
    if (ctx >= contexts.items.len) {
        return;
    }
    if (contexts.items[ctx]) |*context| {
        context.deinit();
    }
    contexts.items[ctx] = null;
}
pub export fn box_context_exists(ctx: u32) bool {
    if (ctx >= contexts.items.len) {
        return false;
    }
    return contexts.items[ctx] != null;
}
pub export fn box_new_from_ctx(ctx: u32, hlgroup: Hl.HlAttrs) ?*Box {
    const context = &contexts.items[ctx].?;
    return context.newBox(Box.newBoxFromContext(context, hlgroup));
}
pub export fn box_new_from_offset(self: *Box, x: u32, y: u32) ?*Box {
    return self.context.newBox(self.newBoxFromOffset(x, y));
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

pub export fn box_set_heigh(self: *Box, height: u32) bool {
    self.setHeight(height) catch return false;

    return true;
}

pub fn box_clean(self: *Box) bool {
    self.clean() catch return false;
    return true;
}

// *kinda* one of thmost needed low level apis

pub export fn box_append_str(self: *Box, str: [*]const u8, len: u32) bool {
    self.appendStr(str[0..len]) catch return false;
    return true;
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
