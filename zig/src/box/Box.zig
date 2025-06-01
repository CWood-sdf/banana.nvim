const common = @import("common.zig");
const sub = common.sub;
const log = @import("../log.zig");
const Char = @import("Char.zig").Char;
const Line = @import("Line.zig");
const Id = common.Id;
const Highlight = common.Highlight;
const BoxContext = @import("BoxContext.zig");
const get_context = common.get_context;
const Box = @This();
const std = @import("std");
const subOr = common.subOr;
/// the context that this box renders to
context: Id,
/// x of top left corner of the box from the base of the context
offsetX: u16,
/// y of top left corner of the box from the base of the context
offsetY: u16,
/// the current width of the box
width: u16,
/// the max width of the box (used for wrapping computations)
maxWidth: u16,
/// the current max height of the box, not really used for anything aside from height computes in PartialRendered
maxHeight: u16,
/// the current height of the box
height: u16,
/// the cursor x pos relative to the offset pos
cursorX: u16,
/// the cursor y pos relative to the offset pos
cursorY: u16,
/// the hlgroup
hlgroup: Highlight,
/// is true when the box could potentially have variable sized lines and needs to be "cleaned", eg:
/// ###
/// #####
///  to
/// #####
/// #####
dirty: bool,
// TODO: Need to work on this
// pub fn insertGradientMarker(){}
// pub fn setGradientSize(){}

// TODO: Internal behavior
// pub fn fillString(width){}

pub fn newBoxFromContext(ctx: Id, hlgroup: Highlight) Box {
    // @compileLog(std.fmt.comptimePrint("{}\n", .{@sizeOf(Highlight)}));
    return .{
        .height = 0,
        .context = ctx,
        .offsetX = 0,
        .offsetY = 0,
        .width = 0,
        .maxWidth = std.math.maxInt(@FieldType(Box, "width")),
        .maxHeight = std.math.maxInt(@FieldType(Box, "height")),
        .dirty = false,
        .hlgroup = hlgroup,
        .cursorX = 0,
        .cursorY = 0,
    };
}
pub fn newBoxFromOffset(self: *Box, x: u16, y: u16) Box {
    return .{
        .height = 0,
        .context = self.context,
        .offsetX = self.offsetX + x,
        .offsetY = self.offsetY + y,
        .width = 0,
        .maxWidth = subOr(self.maxWidth, x, 0),
        .maxHeight = subOr(self.maxHeight, y, 0),
        .dirty = false,
        .hlgroup = self.hlgroup,
        .cursorX = 0,
        .cursorY = 0,
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
        .maxWidth = self.maxWidth,
        .maxHeight = self.maxHeight,
        .dirty = false,
        .hlgroup = self.hlgroup,
    };
}

pub fn newBoxBelow(self: *Box) Box {
    return .{
        .height = 0,
        .context = self.context,
        .offsetX = self.offsetX,
        .offsetY = self.offsetY + self.height,
        .width = 0,
        .maxWidth = self.maxWidth,
        .maxHeight = self.maxHeight,
        .dirty = false,
        .hlgroup = self.hlgroup,
        .cursorX = 0,
        .cursorY = 0,
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
        .maxHeight = self.maxHeight,
        .dirty = false,
        .hlgroup = self.hlgroup,
        .cursorX = 0,
        .cursorY = 0,
    };
}

pub fn overlay(self: *Box, x: u16, y: u16, w: u16, h: u16, char: []const u8, hl: Highlight) !void {
    const c = try Char.fromUtf8(char);
    const localOffsetX = self.cursorX + x;
    const localOffsetY = self.cursorY + y;
    var realW = @min(self.maxWidth - localOffsetX, w);
    realW -= realW % c.width;
    const realH = @min(self.maxHeight - localOffsetY, h);
    if (localOffsetX + realW > self.width) {
        self.width = localOffsetX + realW;
        self.dirty = true;
    }
    if (localOffsetY + realH > self.height) {
        self.height = localOffsetY + realH;
    }
    const offsetX = self.offsetX + localOffsetX;
    const offsetY = self.offsetY + localOffsetY;
    const ctx = try self.getContext();
    for (offsetY..offsetY + realH) |i| {
        const line = try ctx.getLine(@intCast(i));
        var xPos = offsetX;
        try line.ensureAppendableAt(ctx, offsetX + realW, 0);
        while (xPos < offsetX + realW) : (xPos += c.width) {
            line._chars.items[xPos + c.width - 1] = .dummy;
            line._chars.items[xPos] = c;
            line._hls.items[xPos] = hl;
        }
    }
}

pub fn getContext(self: *Box) !*BoxContext {
    return try get_context(self.context);
}

pub fn realCursorX(self: *const Box) u16 {
    return self.cursorX + self.offsetX;
}
pub fn realCursorY(self: *const Box) u16 {
    return self.cursorY + self.offsetY;
}

pub fn putCursorBelow(self: *Box, other: *Box) void {
    const target = other.offsetY + other.height;
    if (target < self.offsetY) {
        return;
    }
    self.cursorY += other.height;
    self.height += other.height;
    if (other.width != self.width) {
        self.width = @max(other.width, self.width);
        self.dirty = true;
    }
}

pub fn increaseOffsetBy(self: *Box, left: i16, top: i16) void {
    if (left > 0) {
        self.offsetX += @intCast(left);
    } else if (-left > self.offsetX) {
        @branchHint(.unlikely);
        self.offsetX = 0;
    } else {
        self.offsetX -= @intCast(-left);
    }
    if (top > 0) {
        self.offsetY += @intCast(top);
    } else if (-top > self.offsetY) {
        @branchHint(.unlikely);
        self.offsetY = 0;
    } else {
        self.offsetY -= @intCast(-top);
    }
}

pub fn increaseCursorBy(self: *Box, left: i16, top: i16) void {
    if (left > 0) {
        self.cursorX += @intCast(left);
    } else if (-left > self.cursorX) {
        @branchHint(.unlikely);
        self.cursorX = 0;
    } else {
        self.cursorX -= @intCast(-left);
    }
    if (top > 0) {
        self.cursorY += @intCast(top);
    } else if (-top > self.cursorY) {
        @branchHint(.unlikely);
        self.cursorY = 0;
    } else {
        self.cursorY -= @intCast(-top);
    }
}

// prettry sure this is only used for canvas
pub fn shrinkWidthTo(self: *Box, width: u16) !void {
    const context = try self.getContext();
    for (self.offsetY..self.offsetY + self.height) |i| {
        if (i >= context.lines.items.len) {
            return error.OverindexingShrinkWidth;
        }
        const line: *Line = &context.lines.items[i];
        while (line.width() > width) {
            line.popLastChar();
        }
    }
    self.width = width;
}
pub fn unsafeSetWidth(self: *Box, width: u16) void {
    self.width = width;
}
pub fn setWidth(self: *Box, width: u16) !void {
    if (self.width == width) {
        return;
    }
    if (self.width < width) {
        try self.expandWidthTo(width);
    } else {
        try self.shrinkWidthTo(width);
    }
}
pub fn expandWidthTo(self: *Box, width: u16) !void {
    if (width < self.width) {
        return error.HeightTooSmall;
    }
    if (width == self.width) return;
    self.width = width;
    self.dirty = true;
    try self.clean();
}

pub fn setHl(self: *Box, hl: Highlight) void {
    self.hlgroup = hl;
}

pub fn shiftRightwardsBy(self: *Box, extra: u16) !void {
    const context = try self.getContext();
    if (self.height + self.offsetY > context.lines.items.len) {
        return error.OverindexingShiftRight;
    }

    for (context.lines.items[self.offsetY .. self.offsetY + self.height]) |*line| {
        try line.ensureTotalCapacity(context.alloc(), extra + line.width());
        for (0..extra) |_| {
            try line.insertAscii(context, self.offsetX, ' ', self.hlgroup);
        }
    }
    self.width += extra;
}
pub fn expandHeightTo(self: *Box, height: u16) !void {
    if (height < self.height) {
        return error.HeightTooSmall;
    }
    const context = try self.getContext();
    while (context.lines.items.len < self.offsetY + height) {
        log.write("Appending line!\n", .{}) catch {};
        var line = Line.init();
        try line.ensureAppendableAt(context, self.offsetX, self.hlgroup);
        try line.appendAsciiNTimes(
            context,
            ' ',
            self.hlgroup,
            self.width,
        );
        try context.lines.append(context.alloc(), line);
    }
    self.height = height;
}
pub fn shrinkHeightTo(self: *Box, height: u16) !void {
    if (height > self.height) {
        return error.HeightTooBig;
    }
    const context = try self.getContext();
    for (0..(self.height - height)) |_| {
        if (context.lines.items.len == 0) {
            break;
        }
        context.lines.items[context.lines.items.len - 1].deinit(context.alloc());
        _ = context.lines.pop();
    }
    self.height = height;
}
pub fn setHeight(self: *Box, height: u16) !void {
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
    try self.cleanDbg(null);
}
pub fn cleanDbg(self: *Box, dbg: ?*BoxContext) !void {
    if (!self.dirty) {
        return;
    }
    var buffer = [_]u8{0} ** 300;
    const context = try self.getContext();
    while (context.lines.items.len < self.offsetY + self.height) {
        try context.lines.append(context.alloc(), Line.init());
        try context.lines.items[context.lines.items.len - 1].appendAsciiNTimes(
            context,
            ' ',
            self.hlgroup,
            self.width + self.offsetX,
        );
    }
    log.write("lens: {}, off: {}, height: {}\n", .{ context.lines.items.len, self.offsetY, self.offsetY + self.height }) catch {};
    defer log.write("function done :)\n", .{}) catch {};
    if (dbg) |d| {
        d.dumpComment(try std.fmt.bufPrint(&buffer, "target width: {}", .{self.width})) catch {};
    }
    for (context.lines.items[self.offsetY .. self.offsetY + self.height]) |*line| {
        if (dbg) |d| {
            d.dumpComment(
                try std.fmt.bufPrint(
                    &buffer,
                    "actual width on line: {}",
                    .{line.widthFrom(self.offsetX)},
                ),
            ) catch {};
        }
        if (line.widthFrom(self.offsetX) > self.width) {
            return error.LineTooBig;
        } else if (line.widthFrom(self.offsetX) < self.width) {
            try line.appendAsciiNTimes(context, ' ', self.hlgroup, self.width - line.widthFrom(self.offsetX));
        }
    }
    self.dirty = false;
}

// TODO: Should be removable with offsets. BoxContext should have appendLeft for flex display (could prolly even get away with just renderOver)
// pub fn append(box, strat){}

// *kinda* one of the most needed low level apis
pub fn appendStr(self: *Box, str: []const u8) !void {
    var isFirst: bool = true;
    var newStr = str;
    const context = try self.getContext();
    if (self.height == self.cursorY) {
        self.height += 1;
    }
    while (newStr.len != 0) {
        const maxWidth = self.maxWidth;
        const line = try context.getLine(self.cursorY + self.offsetY);

        try line.ensureAppendableAt(context, self.offsetX + self.cursorX, self.hlgroup);
        const startWidth = line.width();

        const index = try line.appendWordToLen(
            context,
            newStr,
            self.hlgroup,
            try std.math.add(u16, self.offsetX, maxWidth),
            self.cursorX == 0,
        );
        if (index == 0) {
            self.cursorY += 1;
            self.height += 1;
            self.dirty = true;
            self.cursorX = 0;
        } else {
            self.cursorX += try sub(line.width(), startWidth);
            if (self.cursorY == self.height) {
                self.height += 1;
            }
            self.width = @max(self.width, self.cursorX);
            if (self.cursorX >= self.maxWidth) {
                self.cursorX = 0;
                self.cursorY += 1;
                self.dirty = true;
            }
            if (index >= newStr.len) {
                break;
            }
            newStr = newStr[index..];
            isFirst = false;
        }
    }
}

pub fn updateCursorFrom(self: *Box, other: *Box) void {
    self.cursorX = other.cursorX;
    self.cursorY = other.cursorY;
    self.width = @max(other.width, self.width);
    self.height = @max(other.height, self.height);
}
// pub fn appendStr(self: *Box, str: [*]const u8, len: u16) bool {
//     self.appendStr_internal(str[0..len]) catch return false;
//     return true;
// }
pub fn appendWord(self: *Box, str: []const u8, style: Highlight) !void {
    const currentHl = self.hlgroup;
    self.hlgroup = style;
    defer self.hlgroup = currentHl;
    try self.appendStr(str);
}

// NOTE: Rendering over should *only* happen from prepared box contexts
pub fn renderOver(self: *Box, other: *BoxContext, left: u16, top: u16) !void {
    const context = try self.getContext();
    if (context == other) {
        return error.SameContext;
    }
    const offsetX = self.offsetX + self.cursorX + left;
    const offsetY = self.offsetY + self.cursorY + top;
    var actualWidth: u16 = 0;
    defer {
        self.cursorX += actualWidth + left;
        self.width = @max(self.width, self.cursorX);
        log.write("LINE LEN: {}\n", .{other.lines.items.len}) catch {};
        self.height = @max(self.height, self.cursorY + @as(u16, @intCast(other.lines.items.len)) + top);
        log.write("box height post renderOver: {}\n", .{self.height}) catch {};
        if (self.cursorX > self.maxWidth) {
            self.cursorY += @as(u16, @intCast(other.lines.items.len)) + top;
            self.cursorX = 0;
        }
    }
    for (other.lines.items, 0..) |newLine, i| {
        const line = try context.getLine(@as(u16, @intCast(i)) + offsetY);
        try line.ensureAppendableAt(context, offsetX + newLine.width(), self.hlgroup);
        const width = newLine.width();
        actualWidth = @max(width, actualWidth);
        std.mem.copyForwards(
            Char,
            line._chars.items[offsetX .. offsetX + width],
            newLine._chars.items[0..],
        );
        std.mem.copyForwards(
            Highlight,
            line._hls.items[offsetX .. offsetX + width],
            newLine._hls.items[0..],
        );
    }
}
