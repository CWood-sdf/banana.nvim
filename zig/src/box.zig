// TODO: Box.destroy()
const std = @import("std");
const lua = @import("lua_api/lua.zig");

const Hl = @import("hl.zig");
const consts = @import("nvim_api/constants.zig");
const log = @import("log.zig");
const fns = @import("nvim_api/functions.zig");
const tps = @import("nvim_api/types.zig");

const Highlight = u16;

const Id = u16;

const NullableId = struct {
    const Self = @This();
    value: i16,

    pub const nil: Self = .{ .value = -1 };

    pub fn isNull(self: *const Self) bool {
        return self.value < 0;
    }

    pub fn asOptional(self: *const Self) ?u15 {
        if (self.value > 0) {
            return @intCast(self.value);
        }
        return null;
    }

    pub fn set(self: *Self, value: ?u16) void {
        if (value) |val| {
            self.value = @intCast(val);
        } else {
            self.value = -1;
        }
    }

    pub fn init(value: ?u16) Self {
        if (value) |v| {
            return .{
                .value = @intCast(v),
            };
        } else {
            return .{
                .value = -1,
            };
        }
    }
};

const RealNum = i16;

pub fn charwidth(chars: []const u8) !u8 {
    if (chars.len > 4) {
        return error.StrTooBig;
    }
    var byteArr = [_]u8{0} ** 5;
    for (chars, 0..) |c, i| {
        byteArr[i] = c;
    }
    return @intCast(try fns.z_nvim_strwidth(byteArr[0..chars.len]));
}

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

// TODO: Can prolly do some data oriented stuff here: a char is one byte
// and the first bit is 0 if ascii, 1 if an index into a large char array.
// tho this only allows up to 128 independent multibyte chars per line
const Char = packed struct {
    // the actual number
    bytes: u3,
    // the width
    width: u2,
    char: u21,

    // should be placed after double width characters so that they can act like their width
    pub const dummy: Char = .{
        .bytes = 0,
        .width = 0,
        .char = 0,
    };

    pub const space: Char = .{
        .bytes = 1,
        .width = 1,
        .char = ' ',
    };

    const isSized = std.testing.assert(@sizeOf(@This()) == @sizeOf(u16));

    pub fn equals(self: *const Char, other: Char) bool {
        return self.bytes == other.bytes and self.width == other.width and self.char == other.char;
    }

    /// writes the utf8 representation to the byte array
    /// then returns the number of bytes written
    pub fn toBytes(self: *const Char, byteArr: []u8) !u8 {
        if (self.bytes == 0) {
            return 0;
        }
        if (byteArr.len < self.bytes) {
            return error.ArrayTooSmall;
        }

        const bytes = try std.unicode.utf8Encode(self.char, byteArr);
        return bytes;
    }
    pub fn fromAscii(byte: u8) Char {
        return .{
            .bytes = 1,
            .char = byte,
            .width = 1,
        };
    }

    pub fn fromUtf8(bytes: []const u8) !Char {
        if (bytes.len == 0) {
            return error.ArrayTooSmall;
        }
        const byteSize = try std.unicode.utf8ByteSequenceLength(bytes[0]);
        if (bytes.len < byteSize) {
            return error.ArrayTooSmall;
        }
        const codepoint: u21 = try std.unicode.utf8Decode(bytes[0..byteSize]);
        const width = try charwidth(bytes[0..byteSize]);
        if (width > 2) {
            return error.NvimStrWidthTooBig;
        }
        return .{
            .bytes = byteSize,
            .char = codepoint,
            .width = @intCast(width),
        };
    }

    pub fn isDummy(char: Char) bool {
        return char.width == 0;
    }

    pub fn sliceWidth(slice: []const Char) u16 {
        var ret: u16 = 0;
        for (slice) |char| {
            ret += char.width;
        }
        return ret;
    }
};

const Line = struct {
    chars: std.ArrayListUnmanaged(Char),
    hls: std.ArrayListUnmanaged(Highlight),
    width: u16,

    pub fn init() Line {
        return .{
            .chars = .empty,
            .hls = .empty,
            .width = 0,
        };
    }

    pub fn popLastChar(self: *Line) void {
        _ = self.chars.pop();
        _ = self.hls.pop();
        self.width -= 1;
    }
    pub fn deinit(self: *Line, alloc: std.mem.Allocator) void {
        self.chars.deinit(alloc);
        self.hls.deinit(alloc);
    }
    pub fn appendWordToLen(
        self: *Line,
        ctx: *BoxContext,
        str: []const u8,
        hl: Highlight,
        len: u16,
        addNoMatterWhat: bool,
    ) !u16 {
        var i: u16 = 0;
        if (self.width == len and !addNoMatterWhat) {
            return 0;
        }
        while (i < str.len) {
            const char = try Char.fromUtf8(str[i..]);
            if (char.width + self.width > len and !addNoMatterWhat) {
                return i;
            }
            i += char.bytes;
            try self.chars.append(ctx.alloc(), char);
            self.hls.append(ctx.alloc(), hl) catch |e| {
                self.chars.shrinkRetainingCapacity(self.chars.items.len - 1);
                return e;
            };
            if (char.width == 2) {
                try self.chars.append(ctx.alloc(), .dummy);
                self.hls.append(ctx.alloc(), hl) catch |e| {
                    self.chars.shrinkRetainingCapacity(self.chars.items.len - 1);
                    return e;
                };
            } else if (char.width > 2) {
                return error.TripleWidthCharacter;
            }
            self.width += char.width;
            if (self.width >= len) {
                return i;
            }
        }
        return i;
    }
    pub fn appendWord(self: *Line, ctx: *BoxContext, str: []const u8, hl: Highlight) !void {
        _ = try self.appendWordToLen(ctx, str, hl, @as(u16, @intCast(str.len)) + self.width, true);
    }

    pub fn ensureAppendableAt(self: *Line, ctx: *BoxContext, spot: u16) !void {
        if (self.width < spot) {
            try self.chars.appendNTimes(ctx.alloc(), .space, spot - self.width);
            self.hls.appendNTimes(ctx.alloc(), 0, spot - self.width) catch |e| {
                self.chars.shrinkRetainingCapacity(self.width);
                return e;
            };
            self.width = spot;
        }
    }

    /// Appends an ascii char n times
    pub fn appendCharNTimes(
        self: *Line,
        ctx: *BoxContext,
        char: u8,
        hl: Highlight,
        n: u16,
    ) !void {
        try self.chars.appendNTimes(ctx.alloc(), Char.fromAscii(char), n);
        self.hls.appendNTimes(ctx.alloc(), hl, n) catch |e| {
            self.chars.shrinkRetainingCapacity(self.chars.items.len - n);
            return e;
        };
        self.width += n;
    }
    pub fn widthFrom(self: *Line, base: u16) u16 {
        return self.width - base;
    }
};

var contexts: std.ArrayListUnmanaged(?BoxContext) = .empty;

/// This is just supposed to be a structureless buffer for boxes to render to
pub const BoxContext = struct {
    lines: std.ArrayListUnmanaged(Line) = .empty,
    arena: std.heap.ArenaAllocator,
    _alloc: std.mem.Allocator,
    boxes: std.ArrayListUnmanaged(Box) = .empty,
    partials: std.ArrayListUnmanaged(PartialRendered) = .empty,

    // ctor/dtor
    pub fn init(allocator: std.mem.Allocator) BoxContext {
        const arena = std.heap.ArenaAllocator.init(allocator);
        return .{
            .lines = .empty,
            .boxes = .empty,
            .arena = arena,
            ._alloc = allocator,
            .partials = .empty,
        };
    }
    pub fn alloc(self: *BoxContext) std.mem.Allocator {
        return self.arena.allocator();
    }
    pub fn deinit(self: *BoxContext) void {
        self.arena.deinit();
        // for (self.lines.items) |*line| {
        //     line.deinit(self.alloc);
        // }
        // self.lines.deinit(self.alloc);
        // self.boxes.deinit(self.alloc);
        // self.partials.deinit(self.alloc);
    }
    pub fn wipe(self: *BoxContext) bool {
        self.lines = .empty;
        self.boxes = .empty;
        self.partials = .empty;
        return self.arena.reset(.free_all);
    }
    pub fn newBox(self: *BoxContext, box: Box) !u16 {
        try self.boxes.append(self.arena.allocator(), box);
        self.boxes.items[self.boxes.items.len - 1] = box;
        return @intCast(self.boxes.items.len - 1);
    }
    pub fn getBox(self: *const BoxContext, box: u16) ?*Box {
        if (box >= self.boxes.items.len) {
            return null;
        }
        return &self.boxes.items[box];
    }
    pub fn newPartial(self: *BoxContext, partial: PartialRendered) !u16 {
        try self.partials.append(self.alloc(), partial);
        self.partials.items[self.partials.items.len - 1] = partial;
        return @intCast(self.partials.items.len - 1);
    }
    pub fn getPartial(self: *const BoxContext, ptl: u16) ?*PartialRendered {
        if (ptl >= self.partials.items.len) {
            return null;
        }
        return &self.partials.items[ptl];
    }
    pub fn stripRightSpace(self: *BoxContext, L: *lua.State, pos: c_int) !void {
        var bannedItems: std.ArrayListUnmanaged(Highlight) = .empty;
        defer bannedItems.deinit(self.alloc());
        var passingItems: std.ArrayListUnmanaged(Highlight) = .empty;
        defer passingItems.deinit(self.alloc());

        try bannedItems.append(self.alloc(), 0);
        try passingItems.append(self.alloc(), 0);
        for (self.lines.items) |*line| {
            if (line.hls.items.len == 0) {
                continue;
            }
            var i: i16 = @intCast(line.chars.items.len - 1);
            while (i >= 0) : (i -= 1) {
                if (i < 0) {
                    break;
                }
                if (line.chars.items[@intCast(i)].isDummy()) {
                    break;
                }
                if (!line.chars.items[@intCast(i)].equals(.space)) {
                    break;
                }
                const currentHl: Highlight = line.hls.items[@intCast(i)];
                var isBanned: ?bool = null;
                if (currentHl == 0) {
                    isBanned = true;
                }
                if (isBanned == null) {
                    for (bannedItems.items) |p| {
                        if (p == currentHl) {
                            isBanned = true;
                            break;
                        }
                    }
                }
                if (isBanned == null) {
                    for (passingItems.items) |p| {
                        if (p == currentHl) {
                            isBanned = false;
                            break;
                        }
                    }
                }
                if (isBanned == null) {
                    lua.push_value(L, pos);
                    lua.push_int(L, @intCast(currentHl));
                    lua.call(L, 2, 1);
                    const top = lua.get_top(L);
                    if (!lua.is_number(L, top)) {
                        return error.BadReturn;
                    }
                    isBanned = lua.to_cast_int(L, top, u8) != 0;
                    if (isBanned.?) {
                        try bannedItems.append(self.alloc(), currentHl);
                    } else {
                        try passingItems.append(self.alloc(), currentHl);
                    }
                }
                if (isBanned.?) {
                    _ = line.hls.pop();
                    _ = line.chars.pop();
                }
            }
        }
        var i: u16 = @intCast(self.lines.items.len);
        while (i > 0) {
            i -= 1;
            const line = self.lines.items[i];
            if (line.chars.items.len == 0) {
                _ = self.lines.pop();
            } else {
                break;
            }
        }
    }

    pub fn getLine(self: *BoxContext, line: u16) !*Line {
        while (self.lines.items.len <= line) {
            try self.lines.append(self.alloc(), Line.init());
        }
        return &self.lines.items[line];
    }
    pub fn render(self: *BoxContext, buf: tps.Integer, lineStart: i64, lineEnd: i64) !void {
        log.write("yuhh rendering buf {}\n", .{buf}) catch {};
        var err = tps.Error{ .type = .None, .msg = @ptrFromInt(0) };
        var arena: tps.Arena = .{
            .current_block = "",
            .size = 0,
            .pos = 0,
        };
        log.write("yuhh creating string table\n", .{}) catch {};
        var arr: std.ArrayListUnmanaged(tps.Object) = .empty;
        defer arr.deinit(self.alloc());

        try arr.ensureTotalCapacity(self.alloc(), self.lines.items.len);

        var lines: std.ArrayListUnmanaged(u8) = .empty;
        defer {
            lines.deinit(self.alloc());
        }
        log.write("Creating string table\n", .{}) catch {};
        const emptyStr = "";
        for (self.lines.items) |*line| {
            const startIndex = lines.items.len;
            for (line.chars.items) |char| {
                var chars = [_]u8{0} ** 4;
                const bytes = try char.toBytes(&chars);
                if (bytes != 0) {
                    try lines.appendSlice(
                        self.alloc(),
                        chars[0..bytes],
                    );
                }
            }
            // TODO: Assumes added characters
            const str = if (lines.items.len != startIndex)
                lines.items[startIndex..]
            else
                emptyStr[0..0];
            log.write(
                "  Created line '{s}'\n",
                .{str},
            ) catch {};
            try lines.append(self.alloc(), 0);
        }
        var startIndex: usize = 0;
        for (lines.items, 0..) |c, i| {
            if (c == 0) {
                const str = lines.items[startIndex..i];
                arr.appendAssumeCapacity(tps.stringObject(str));
                startIndex = i + 1;
            }
        }

        log.write("Buf: {}\n", .{buf}) catch {};

        const replacement: tps.Array = tps.Array.fromSlice(arr.items);
        log.write("yo yo: {}\n", .{buf}) catch {};
        fns.nvim_buf_set_lines(
            consts.LUA_INTERNAL_CALL,
            @enumFromInt(buf),
            lineStart,
            lineEnd,
            true,
            replacement,
            &arena,
            &err,
        );
        log.write("Lines written: {}\n", .{arr.items.len}) catch {};

        if (err.type != .None) {
            switch (err.type) {
                .Exception => {
                    if (err.msg != @as([*]allowzero u8, @ptrFromInt(0))) {
                        var end: u16 = 0;
                        for (err.msg, 0..1000) |c, i| {
                            if (c == 0) {
                                end = @intCast(i);
                                break;
                            }
                        }
                        const msg: [*]const u8 = @ptrCast(err.msg);
                        log.write("Err msg: {s}\n", .{msg[0..end]}) catch {};
                    }
                    return tps.NvimError.Exception;
                },
                .Validation => {
                    return tps.NvimError.Validation;
                },
                else => {},
            }
        }
    }
    pub fn highlight(self: *BoxContext, L: *lua.State, pos: c_int, startLine: u64) void {
        // if (!lua.is_function(L, 1)) {
        //     return error.NotAFunction;
        // }
        for (self.lines.items, 0..) |line, row| {
            if (line.hls.items.len == 0) {
                continue;
            }
            var startCol: u16 = 0;
            var currentHl: Highlight = line.hls.items[0];
            var byte: u16 = 0;
            for (line.hls.items, 0..) |hl, col| {
                if (currentHl != hl) {
                    if (currentHl != 0) {
                        lua.push_value(L, pos);
                        lua.push_int(L, @intCast(row + startLine));
                        lua.push_int(L, @intCast(startCol));
                        lua.push_int(L, @intCast(byte));
                        lua.push_int(L, @intCast(currentHl));
                        lua.call(L, 4, 0);
                    }
                    currentHl = hl;
                    startCol = byte;
                }
                byte += line.chars.items[col].bytes;
            }
            if (startCol != byte) {
                lua.push_value(L, pos);
                lua.push_int(L, @intCast(row + startLine));
                lua.push_int(L, @intCast(startCol));
                lua.push_int(L, @intCast(byte));
                lua.push_int(L, @intCast(currentHl));
                lua.call(L, 4, 0);
            }
        }
    }
    pub fn dumpTo(self: *BoxContext, other: *BoxContext, reason: []const u8) !void {
        var breakLine = Line.init();
        try breakLine.chars.append(other.alloc(), Char.fromAscii('-'));
        try breakLine.hls.append(other.alloc(), 0);
        try breakLine.chars.append(other.alloc(), .space);
        try breakLine.hls.append(other.alloc(), 0);
        breakLine.width = 2;
        try breakLine.appendWord(other, reason, 0);
        try other.lines.append(other.alloc(), breakLine);
        for (self.lines.items) |line| {
            var newLine = Line.init();
            try newLine.chars.appendSlice(other.alloc(), line.chars.items);
            try newLine.hls.appendSlice(other.alloc(), line.hls.items);
            newLine.width = line.width;
            try other.lines.append(other.alloc(), newLine);
        }
    }
    pub fn dumpComment(self: *BoxContext, comment: []const u8) !void {
        var line = Line.init();
        try line.appendWord(self, comment, 0);
        try self.lines.append(self.alloc(), line);
    }
};

pub const Box = struct {
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
            .maxWidth = self.maxWidth - x,
            .maxHeight = self.maxHeight - y,
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

    pub fn getContext(self: *Box) !*BoxContext {
        return try get_context(self.context);
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

    // prettry sure this is only used for canvas
    pub fn shrinkWidthTo(self: *Box, width: u16) !void {
        const context = try self.getContext();
        for (self.offsetY..self.offsetY + self.height) |i| {
            const line: *Line = &context.lines.items[i];
            while (line.width > width) {
                line.popLastChar();
            }
        }
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
    // TODO: Used for debugging ONLY
    pub fn clone(self: *Box) BoxContext {
        _ = self; // autofix
    }

    pub fn setHl(self: *Box, hl: Highlight) void {
        self.hlgroup = hl;
    }

    pub fn shiftRightwardsBy(self: *Box, extra: u16) !void {
        const context = try self.getContext();
        for (context.lines.items[self.offsetY .. self.offsetY + self.height]) |*line| {
            try line.chars.ensureTotalCapacity(
                context.alloc(),
                extra + line.chars.items.len,
            );
            try line.hls.ensureTotalCapacity(
                context.alloc(),
                extra + line.hls.items.len,
            );
            for (0..extra) |_| {
                line.chars.insertAssumeCapacity(self.offsetX, .space);
                line.hls.insertAssumeCapacity(self.offsetX, self.hlgroup);
            }
        }
    }
    pub fn expandHeightTo(self: *Box, height: u16) !void {
        if (height < self.height) {
            return error.HeightTooSmall;
        }
        const context = try self.getContext();
        while (context.lines.items.len < self.offsetY + height) {
            try context.lines.append(context.alloc(), Line.init());
            try context.lines.items[context.lines.items.len - 1].appendCharNTimes(
                context,
                ' ',
                self.hlgroup,
                self.width,
            );
        }
        self.height = height;
    }
    pub fn shrinkHeightTo(self: *Box, height: u16) !void {
        if (height > self.height) {
            return error.HeightTooBig;
        }
        const context = try self.getContext();
        for (0..(self.height - height)) |_| {
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
        if (!self.dirty) {
            return;
        }
        const context = try self.getContext();
        while (context.lines.items.len < self.offsetY + self.height) {
            try context.lines.append(context.alloc(), Line.init());
            try context.lines.items[context.lines.items.len - 1].appendCharNTimes(
                context,
                ' ',
                self.hlgroup,
                self.width,
            );
        }
        log.write("lens: {}, off: {}, height: {}\n", .{ context.lines.items.len, self.offsetY, self.offsetY + self.height }) catch {};
        defer log.write("function done :)\n", .{}) catch {};
        for (context.lines.items[self.offsetY .. self.offsetY + self.height]) |*line| {
            if (line.widthFrom(self.offsetX) > self.width) {
                return error.LineTooBig;
            } else if (line.widthFrom(self.offsetX) < self.width) {
                try line.appendCharNTimes(context, ' ', self.hlgroup, self.width - line.widthFrom(self.offsetX));
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
        if (self.height == 0) {
            self.height = 1;
        }
        const context = try self.getContext();
        while (newStr.len != 0) {
            const maxWidth = self.maxWidth;
            const line = try context.getLine(self.cursorY + self.offsetY);

            if (self.cursorX == 0) {
                try line.ensureAppendableAt(context, self.offsetX);
            }
            const startWidth = line.width;

            const index = try line.appendWordToLen(
                context,
                newStr,
                self.hlgroup,
                maxWidth,
                self.cursorX == 0,
            );
            self.cursorX += line.width - startWidth;
            self.width = @max(self.width, self.cursorX);
            if (self.cursorX >= self.maxWidth) {
                self.cursorX = 0;
                self.height += 1;
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

    pub fn updateCursorFrom(self: *Box, other: *Box) void {
        self.cursorX = other.cursorX;
        self.cursorY = other.cursorY;
        self.width = other.width;
        self.height = other.height;
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
    // TODO: Remove in favor of managed splitting
    // pub fn getLine(i){}

    // TODO: Remove in favor of offsets
    // pub fn appendBoxBelow(box, expand){}

    // TODO: Unused
    // pub fn trimWidthLastLine(width, trimStrat){}

    // NOTE: Rendering over should *only* happen from prepared box contexts
    pub fn renderOver(self: *Box, other: *BoxContext, left: u16, top: u16) !void {
        const context = try self.getContext();
        if (context == other) {
            return error.SameContext;
        }
        _ = left; // autofix
        _ = top; // autofix
    }
};

pub const PartialRendered = struct {
    ctx: Id,
    containerBox: Id,
    box: NullableId,
    dbgCtx: NullableId,
    marginColor: Highlight,
    mainColor: Highlight,

    // TODO: Merge these fields together
    startCursorX: u16,
    startCursorY: u16,
    margin: Pad,
    padding: Pad,
    maxWidth: u16,
    maxHeight: u16,
    sideAlign: RenderAlign,
    verticalAlign: RenderAlign,
    pub const RenderAlign = enum(u2) {
        left = 0,
        center = 1,
        right = 2,
        noexpand = 3,
    };
    pub const Pad = struct {
        left: u16,
        right: u16,
        top: u16,
        bottom: u16,
        pub const zero: Pad = .init(0, 0, 0, 0);
        pub fn init(l: u16, r: u16, t: u16, b: u16) Pad {
            return .{
                .left = l,
                .right = r,
                .top = t,
                .bottom = b,
            };
        }
        pub fn equals(left: Pad, right: Pad) bool {
            return left.left == right.right and left.right == right.right and left.top == right.top and left.bottom == right.bottom;
        }
        pub fn side(self: *Pad) u16 {
            return self.left + self.right;
        }
        pub fn vert(self: *Pad) u16 {
            return self.top + self.bottom;
        }
    };

    pub fn init(containerBox: *Box, containerId: Id) PartialRendered {
        return .{
            .dbgCtx = .nil,
            .ctx = containerBox.context,
            .maxHeight = containerBox.maxHeight,
            .startCursorX = 0,
            .startCursorY = 0,
            .margin = .zero,
            .padding = .zero,
            .containerBox = containerId,
            .box = .nil,
            .marginColor = containerBox.hlgroup,
            .mainColor = 0,
            .sideAlign = .noexpand,
            .verticalAlign = .noexpand,
            .maxWidth = containerBox.maxWidth,
        };
    }

    pub fn setMargin(self: *PartialRendered, margin: Pad) void {
        self.margin = margin;
    }
    pub fn setPadding(self: *PartialRendered, padding: Pad) void {
        self.padding = padding;
    }
    pub fn setMainColor(self: *PartialRendered, main: Highlight) void {
        self.mainColor = main;
    }
    pub fn setMaxWidth(self: *PartialRendered, width: u16) void {
        self.maxWidth = width;
    }
    pub fn setMaxHeight(self: *PartialRendered, height: u16) void {
        self.maxHeight = height;
        self.verticalAlign = .left;
    }
    pub fn getContainer(self: *PartialRendered) !*Box {
        return try get_box(self.ctx, self.containerBox);
    }
    pub fn getContext(self: *PartialRendered) !*BoxContext {
        return try get_context(self.ctx);
    }
    pub fn getBox(self: *PartialRendered) !*Box {
        if (self.box.asOptional()) |id| {
            return try get_box(self.ctx, id);
        }
        return error.BoxNotExist;
    }
    pub fn createBoxTryCursored(self: *PartialRendered) !u16 {
        const containerBox = try self.getContainer();
        if (!self.padding.equals(.zero) or !self.margin.equals(.zero)) {
            return try self.createBox(containerBox.cursorX, 0);
        }
        const context = try self.getContext();
        var box = containerBox.newBoxCursored();
        // dont need to set maxWidth bc its inherited from containerBox
        // self.box.?.maxWidth = self.maxWidth - self.margin.left - self.padding.left - self.margin.right - self.padding.right;
        box.hlgroup = self.mainColor;
        const id = try context.newBox(box);

        self.box.set(id);

        return id;
    }
    pub fn createBox(self: *PartialRendered, offX: u16, offY: u16) !u16 {
        const containerBox = try self.getContainer();
        const noextra = self.padding.equals(.zero) and self.margin.equals(.zero);
        const noexpand =
            self.sideAlign == .noexpand and self.verticalAlign == .noexpand;
        const movable = containerBox.cursorX != 0;
        // if we have an inline el, then we need to make it cursored
        var box = if (noextra and noexpand and movable) blk: {
            self.startCursorX = containerBox.cursorX;
            self.startCursorY = containerBox.cursorY;
            const box = containerBox.newBoxCursored();
            break :blk box;
        } else containerBox.newBoxFromOffset(
            self.margin.left + self.padding.left + offX,
            self.margin.top + self.padding.top + containerBox.cursorY + offY,
        );
        box.maxWidth = self.maxWidth;
        box.hlgroup = self.mainColor;

        const context = try self.getContext();

        const id = try context.newBox(box);

        self.box.set(id);

        return id;
    }

    pub fn setAlign(self: *PartialRendered, al: RenderAlign) void {
        self.sideAlign = al;
    }

    pub fn setVerticalAlign(self: *PartialRendered, al: RenderAlign) void {
        self.verticalAlign = al;
    }

    pub fn getWidth(self: *PartialRendered) !u16 {
        const box = try self.getBox();
        const width = switch (self.sideAlign) {
            .left, .center, .right => self.maxWidth,
            .noexpand => self.padding.side() + self.margin.side() + box.width,
        };
        return width;
    }
    pub fn getHeight(self: *PartialRendered) !u16 {
        const box = try self.getBox();
        const height = switch (self.verticalAlign) {
            .left, .center, .right => self.maxHeight,
            .noexpand => self.padding.vert() + self.margin.vert() + box.height,
        };
        return height;
    }

    pub fn render(self: *PartialRendered) !void {
        const box = try self.getBox();
        const containerBox = try self.getContainer();
        const context = try self.getContext();

        if (self.startCursorX != 0) {
            containerBox.updateCursorFrom(box);
            return;
        }
        const alloc = context.alloc();
        const widthExpansion = switch (self.sideAlign) {
            .left, .center, .right => self.maxWidth - self.padding.side() - self.margin.side() - box.width,
            .noexpand => 0,
        };
        const heightExpansion = switch (self.verticalAlign) {
            .left, .center, .right => self.maxHeight - self.padding.vert() - self.margin.vert() - box.height,
            .noexpand => 0,
        };
        const mainWidth = box.width + widthExpansion;
        const mainHeight = box.height + heightExpansion;
        const offX = containerBox.offsetX;
        const offY = containerBox.offsetY;
        const height = mainHeight + self.padding.top + self.padding.bottom + self.margin.top + self.margin.bottom;
        const width = mainWidth + self.padding.left + self.padding.right + self.margin.left + self.margin.right;

        try box.expandHeightTo(box.height + heightExpansion);
        try box.clean();

        if (width != containerBox.width) {
            containerBox.width = @max(containerBox.width, width);
            containerBox.dirty = true;
        }
        // NOTE: If changing, change the offset line in renderWithMove
        containerBox.cursorY += height;
        containerBox.height += height;
        switch (self.sideAlign) {
            .center => {
                const leftSide = @divFloor(widthExpansion, 2);
                try box.shiftRightwardsBy(leftSide);
                const rightSide = widthExpansion - leftSide;
                for (box.offsetY..box.offsetY + box.height) |i| {
                    const line = try context.getLine(@intCast(i));
                    try line.chars.appendNTimes(alloc, .space, rightSide);
                    try line.hls.appendNTimes(alloc, self.mainColor, rightSide);
                    line.width += 1;
                }
            },
            .right => {
                try box.shiftRightwardsBy(widthExpansion);
            },
            .left => {
                for (box.offsetY..box.offsetY + box.height) |i| {
                    const line = try context.getLine(@intCast(i));
                    log.write("Width expansion yay: {}\n", .{widthExpansion}) catch {};
                    try line.chars.appendNTimes(alloc, .space, widthExpansion);
                    try line.hls.appendNTimes(
                        alloc,
                        self.mainColor,
                        widthExpansion,
                    );
                    line.width += widthExpansion;
                }
            },
            .noexpand => {},
        }
        // for (0..heightExpansion) |i| {
        //     const lineNr = offY + self.padding.top + self.margin.top + box.height + i;
        //     const line = try context.getLine(@intCast(lineNr));
        //     const startX = offX + self.margin.left + self.padding.left;
        //     try line.chars.ensureTotalCapacity(
        //         alloc,
        //         startX + mainWidth,
        //     );
        //     try line.hls.ensureTotalCapacity(
        //         alloc,
        //         startX + mainWidth,
        //     );
        //     @memset(line.chars.items[startX .. startX + mainWidth], .space);
        //     @memset(line.hls.items[startX .. startX + mainWidth], self.mainColor);
        // }

        // set margin and padding
        for (0..height) |i| {
            const line = try context.getLine(offY + @as(u16, @intCast(i)));
            if (i < self.margin.top or i >= height - self.margin.bottom) {
                // all margin
                try line.chars.ensureTotalCapacity(alloc, offX + width);
                const currentStrLen = line.chars.items.len;
                if (currentStrLen < offX + width) {
                    line.chars.appendNTimesAssumeCapacity(.space, offX + width - currentStrLen);
                }
                if (currentStrLen > offX) {
                    @memset(line.chars.items[offX..currentStrLen], .space);
                }
                try line.hls.ensureTotalCapacity(alloc, offX + width);
                if (currentStrLen < offX + width) {
                    line.hls.appendNTimesAssumeCapacity(self.marginColor, offX + width - currentStrLen);
                }
                if (currentStrLen > offX) {
                    @memset(line.hls.items[offX .. offX + width], self.marginColor);
                }
            } else if (i < self.margin.top + self.padding.top or i >= height - self.margin.bottom - self.padding.bottom) {
                // margin l r, middle padding
                try line.chars.ensureTotalCapacity(alloc, offX + width);
                const currentStrLen = line.chars.items.len;
                if (currentStrLen < offX + width) {
                    line.chars.appendNTimesAssumeCapacity(.space, offX + width - currentStrLen);
                }
                if (currentStrLen > offX) {
                    @memset(line.chars.items[offX..currentStrLen], .space);
                }
                try line.hls.ensureTotalCapacity(alloc, offX + width);
                // just set any unused area to margin color, it will be changed later
                // do this bc i REALLY dont want to do complicated logic
                if (currentStrLen < offX + width) {
                    line.hls.appendNTimesAssumeCapacity(self.marginColor, offX + width - currentStrLen);
                }

                @memset(line.hls.items[offX .. offX + self.margin.left], self.marginColor);
                @memset(
                    line.hls.items[offX + self.margin.left .. offX + width - self.margin.right],
                    self.mainColor,
                );
                @memset(
                    line.hls.items[offX + width - self.margin.right .. offX + width],
                    self.marginColor,
                );
            } else {
                // margin + pad l r, middle content{
                const currentStrLen = line.chars.items.len;
                try line.chars.ensureTotalCapacity(alloc, offX + width);
                if (currentStrLen < offX + width) {
                    line.chars.appendNTimesAssumeCapacity(.space, offX + width - currentStrLen);
                }

                const spaceArea = self.margin.left + self.padding.left;
                @memset(line.chars.items[offX .. offX + spaceArea], .space);
                const spaceCont = spaceArea + mainWidth;
                @memset(line.chars.items[offX + spaceCont .. offX + width], .space);
                try line.hls.ensureTotalCapacity(alloc, offX + width);
                if (currentStrLen < offX + width) {
                    line.hls.appendNTimesAssumeCapacity(self.marginColor, offX + width - currentStrLen);
                }
                @memset(line.hls.items[offX .. offX + self.margin.left], self.marginColor);
                @memset(
                    line.hls.items[offX + self.margin.left .. offX + self.margin.left + self.padding.left],
                    self.mainColor,
                );
                @memset(
                    line.hls.items[offX + self.margin.left + self.padding.left + mainWidth .. offX + width - self.margin.right],
                    self.mainColor,
                );
                @memset(
                    line.hls.items[offX + width - self.margin.right .. offX + width],
                    self.marginColor,
                );
            }
        }
    }
    pub fn renderCursoredOverflow(self: *PartialRendered, lineHeight: u16) !bool {
        if (self.startCursorX != 0) {
            try self.render();
            return false;
        }
        const containerBox = try self.getContainer();
        const maxWidth = containerBox.maxWidth - containerBox.cursorX;
        return try self.renderWithMove(maxWidth, 0, containerBox.cursorY + lineHeight);
    }
    pub fn renderWithMove(self: *PartialRendered, maxWidth: u16, toX: u16, toY: u16) !bool {
        try self.render();
        if (self.padding.equals(.zero) and self.margin.equals(.zero)) {
            return false;
        }
        const box = try self.getBox();
        const context = try self.getContext();
        const containerBox = try self.getContainer();
        const alloc = context.alloc();
        const widthExpansion = switch (self.sideAlign) {
            .left, .center, .right => self.maxWidth - self.padding.side() - self.margin.side() - box.width,
            .noexpand => 0,
        };
        const heightExpansion = switch (self.verticalAlign) {
            .left, .center, .right => self.maxHeight - self.padding.vert() - self.margin.vert() - box.height,
            .noexpand => 0,
        };
        const mainWidth = box.width + widthExpansion;
        const width = mainWidth + self.padding.left + self.padding.right + self.margin.left + self.margin.right;
        const height = box.height + heightExpansion + self.padding.top + self.padding.bottom + self.margin.top + self.margin.bottom;
        // yo we gucci
        if (width <= maxWidth) {
            // dont need to save the width before render() bc if
            // - A: the width doesnt increase, that means width is currently bigger
            // than box size, so we just need to recompute if its bigger than boxSize AND cursor
            // - B: The width already increased from width, now it will increase
            // even more with cursor + width
            containerBox.width = @max(
                containerBox.width,
                containerBox.cursorX + width,
            );
            containerBox.cursorX += width;
            // NOTE: to offset the increase at the end of render()
            containerBox.cursorY -= height;
            return false;
        }
        containerBox.cursorX = 0;
        const offX = containerBox.offsetX;
        const offY = containerBox.offsetY;
        for (0..height) |i| {
            const line = try context.getLine(offY + @as(u16, @intCast(i)));
            const count = @min(line.chars.items.len - offX, width);
            const slice = line.chars.items[offX .. offX + count];
            const otherLine = try context.getLine(toY + @as(u16, @intCast(i)));

            if (otherLine.chars.items.len < toX + count) {
                try otherLine.chars.appendNTimes(context.alloc(), .space, toX + count - otherLine.chars.items.len);
                try otherLine.hls.appendNTimes(context.alloc(), self.marginColor, toX + count - otherLine.hls.items.len);
            }
            try otherLine.chars.replaceRange(alloc, toX, count, slice);
            try otherLine.hls.replaceRange(
                alloc,
                toX,
                count,
                line.hls.items[offX .. offX + count],
            );
            @memset(line.chars.items[offX .. offX + count], .space);
            @memset(line.hls.items[offX .. offX + count], self.marginColor);
        }
        return true;
    }
};

pub fn init_boxes() void {
    contexts = .empty;
}

pub fn dumpStruct(obj: anytype, indent: []const u8) void {
    const st = @typeInfo(@TypeOf(obj)).@"struct";
    inline for (st.fields) |field| {
        switch (@typeInfo(@FieldType(@TypeOf(obj), field.name))) {
            .@"struct" => {},
            else => {
                log.write("{s}.{s} = {any}\n", .{ indent, field.name, @field(obj, field.name) }) catch {};
            },
        }
    }
}

fn dumpContexts() void {
    log.write("  ctx ptr: {*}\n", .{contexts.items.ptr}) catch {};
    for (contexts.items, 0..) |ctxn, i| {
        if (ctxn) |ctx| {
            log.write("    ctx {} is not null\n", .{i}) catch {};
            log.write("      .memusage = {}\n", .{ctx.arena.queryCapacity()}) catch {};
            log.write("      .boxes = {*}\n", .{ctx.boxes.items.ptr}) catch {};
            const indent = "          ";
            for (ctx.boxes.items, 0..) |box, j| {
                log.write("      .boxes[{}] = \n", .{j}) catch {};
                dumpStruct(box, indent[0..]);
            }
            log.write("      .partials = {*}\n", .{ctx.partials.items.ptr}) catch {};
            for (ctx.partials.items, 0..) |partial, j| {
                log.write("        .partials[{}] = \n", .{j}) catch {};
                dumpStruct(partial, indent[0..]);
            }
            log.write("    .lines = {*}\n", .{ctx.lines.items.ptr}) catch {};
            for (ctx.lines.items, 0..) |line, j| {
                log.write("      .lines[{}] = \n", .{j}) catch {};
                dumpStruct(line, indent[0..]);
            }
        } else {
            log.write("    ctx {} is null\n", .{i}) catch {};
        }
    }
}

fn dumpObjectToLua(T: type, obj: *const T, L: *lua.State) !void {
    const info = @typeInfo(T).@"struct";
    inline for (info.fields) |field| {
        const name = field.name;
        const luaName = std.fmt.comptimePrint("_debug_{s}", .{name});
        // log.write("Pushing debug field {s} for type {}\n", .{ name, T }) catch {};
        const top = lua.get_top(L);
        switch (@typeInfo(field.type)) {
            .int => {
                lua.push_int(L, std.math.lossyCast(c_int, @field(obj.*, name)));
            },
            .bool => {
                lua.push_bool(L, @field(obj.*, name));
            },
            .float => {
                lua.push_number(L, @field(obj.*, name));
            },
            .@"struct" => {
                switch (field.type) {
                    NullableId => {
                        const val: NullableId = @field(obj.*, name);
                        if (val.isNull()) {
                            lua.push_nil(L);
                        } else {
                            lua.push_int(L, @intCast(val.value));
                        }
                    },
                    PartialRendered.Pad => {
                        const ptr = &@field(obj.*, name);
                        lua.create_table(L, 0, 4);
                        try dumpObjectToLua(PartialRendered.Pad, ptr, L);
                    },
                    else => {
                        @compileError(
                            std.fmt.comptimePrint("omg bad type {}", .{field.type}),
                        );
                    },
                }
            },
            .@"enum" => {
                const value = @field(obj.*, name);
                const str = @tagName(value);
                lua.push_stringslice(L, str);
            },
            else => @compileError(std.fmt.comptimePrint("omg errr {}", .{field.type})),
        }
        lua.set_field(L, top, luaName);
    }
}

const BoxExpect = ExpectStr("Banana.Box2");

pub fn box_dump_box_data(ctx: u16, box: u16, value: BoxExpect) !void {
    const b = try get_box(ctx, box);
    try dumpObjectToLua(Box, b, value.L);
}

const PartialExpect = ExpectStr("Banana.Renderer.PartialRendered2");

pub fn box_dump_pr_data(ctx: u16, pr: u16, value: PartialExpect) !void {
    const p = try get_partial(ctx, pr);
    try dumpObjectToLua(PartialRendered, p, value.L);
}

pub fn get_context(ctx: u16) !*BoxContext {
    // dumpContexts();
    if (ctx >= contexts.items.len) {
        return error.NotFound;
    }
    if (contexts.items[ctx]) |*c| return c;
    return error.NotFound;
}

pub fn get_box(ctx: u16, box: u16) !*Box {
    const context = try get_context(ctx);
    const b = context.getBox(box) orelse return error.NotFound;
    const indent = "  ";
    log.write("  Getting box {}:{}\n", .{ ctx, box }) catch {};
    dumpStruct(b.*, indent[0..]);
    return b;
}
pub fn get_partial(ctx: u16, partial: u16) !*PartialRendered {
    const context = try get_context(ctx);
    const ret = context.getPartial(partial) orelse return error.NotFound;
    const indent = "  ";
    log.write("  Getting partial {}:{}\n", .{ ctx, partial }) catch {};
    dumpStruct(ret.*, indent[0..]);
    return ret;
}

// new context {
/// Returns -1 on failure
/// @return i16 the id of a new box context
pub fn box_context_create() !u16 {
    for (contexts.items, 0..) |item, i| {
        if (item) |_| continue;
        contexts.items[i] = BoxContext.init(std.heap.page_allocator);
        return @intCast(i);
    }
    try contexts.append(std.heap.page_allocator, null);
    const i = contexts.items.len - 1;
    contexts.items[i] = BoxContext.init(std.heap.page_allocator);
    return @intCast(i);
}

pub fn box_context_dump_to(ctx: u16, other: u16, reason: []const u8) !void {
    const self = try get_context(ctx);
    const o = try get_context(other);
    try self.dumpTo(o, reason);
}

pub fn box_context_dump_comment(ctx: u16, comment: []const u8) !void {
    const self = try get_context(ctx);
    try self.dumpComment(comment);
}

// }

// delete context {
/// In all cases, if ctx is valid it will be deleted
/// @param ctx u16 A box context id
/// @return bool whether the context existed or not
pub fn box_context_delete(ctx: u16) bool {
    if (ctx >= contexts.items.len) {
        return false;
    }
    if (contexts.items[ctx]) |*context| {
        context.deinit();
    }
    contexts.items[ctx] = null;
    return true;
}

pub fn box_context_wipe(ctx: u16) bool {
    const context = get_context(ctx) catch return false;
    return context.wipe();
}

// }

// context exists {
/// @retrun ctx u16 a box context id
/// @return bool whether the context exists or not
pub fn box_context_exists(ctx: u16) bool {
    if (ctx >= contexts.items.len) {
        return false;
    }
    return contexts.items[ctx] != null;
}
// }

// partial rendereds {
pub fn box_pr_new(ctx: u16, boxid: u16) !u16 {
    const context = try get_context(ctx);
    const box = try get_box(ctx, boxid);
    const partial = PartialRendered.init(box, boxid);
    return try context.newPartial(partial);
}
pub fn box_pr_set_margin(ctx: u16, partialid: u16, left: u16, right: u16, top: u16, bottom: u16) !void {
    const partial = try get_partial(ctx, partialid);
    partial.setMargin(.init(left, right, top, bottom));
}
pub fn box_pr_set_pad(ctx: u16, partialid: u16, left: u16, right: u16, top: u16, bottom: u16) !void {
    const partial = try get_partial(ctx, partialid);
    partial.setPadding(.init(left, right, top, bottom));
}
pub fn box_pr_set_main_hl(ctx: u16, partialid: u16, hl: Highlight) !void {
    const partial = try get_partial(ctx, partialid);
    partial.setMainColor(hl);
}

pub fn box_pr_get_width(ctx: u16, partialid: u16) !u16 {
    const partial = try get_partial(ctx, partialid);
    return try partial.getWidth();
}
pub fn box_pr_get_height(ctx: u16, partialid: u16) !u16 {
    const partial = try get_partial(ctx, partialid);
    return try partial.getHeight();
}
pub fn box_pr_set_max_height(ctx: u16, partialid: u16, height: u16) !void {
    const partial = try get_partial(ctx, partialid);
    partial.setMaxHeight(height);
}
pub fn box_pr_set_max_width(ctx: u16, partialid: u16, width: u16) !void {
    const partial = try get_partial(ctx, partialid);
    partial.setMaxWidth(width);
}
pub fn box_pr_cursored_box(ctx: u16, partialid: u16) !u16 {
    const partial = try get_partial(ctx, partialid);
    return try partial.createBoxTryCursored();
}
pub fn box_pr_box(ctx: u16, partialid: u16) !u16 {
    const partial = try get_partial(ctx, partialid);
    return try partial.createBox(0, 0);
}
pub fn box_pr_set_align(ctx: u16, partialid: u16, al: u16) !void {
    const partial = try get_partial(ctx, partialid);
    partial.setAlign(@enumFromInt(al));
}
pub fn box_pr_render(ctx: u16, partialid: u16) !void {
    const partial = try get_partial(ctx, partialid);
    try partial.render();
}
pub fn box_pr_render_with_move(ctx: u16, partialid: u16, maxWidth: u16, toX: u16, toY: u16) !bool {
    const partial = try get_partial(ctx, partialid);
    return try partial.renderWithMove(maxWidth, toX, toY);
}
pub fn box_pr_render_cursored(ctx: u16, partialid: u16, lineHeight: u16) !bool {
    const partial = try get_partial(ctx, partialid);
    return try partial.renderCursoredOverflow(lineHeight);
}
// }

// context render {
///
pub fn box_context_render(ctx: u16, buf: u16) !bool {
    const context = try get_context(ctx);
    try context.render(buf, 0, -1);
    return true;
}

pub fn box_context_render_at(ctx: u16, buf: u16, start: i64, _end: i64) !bool {
    const context = try get_context(ctx);
    try context.render(buf, start, _end);
    return true;
}
pub fn box_context_highlight_at(ctx: u16, L: HlExpect, start: u64) !void {
    const context = try get_context(ctx);
    context.highlight(L.L, 2, start);
}

pub fn box_put_cursor_below(ctx: u16, boxOne: u16, boxOther: u16) !void {
    const box1 = try get_box(ctx, boxOne);
    const box2 = try get_box(ctx, boxOther);
    box1.putCursorBelow(box2);
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

/// Here so that functions can get lua functions/tables and document
/// what they want from the type
pub fn ExpectStr(comptime str: []const u8) type {
    return struct {
        L: *lua.State,
        pub const isLua = true;
        pub const T = str;
    };
}

const HlExpect = Expect(fn (line: i16, startCol: i16, endCol: i16, hl: i16) void);
pub fn box_context_highlight(ctx: u16, L: HlExpect) !void {
    const context = try get_context(ctx);
    context.highlight(L.L, 2, 0);
}

pub fn box_shift_right_by(ctx: u16, boxid: u16, extra: u16) !void {
    const box = try get_box(ctx, boxid);
    try box.shiftRightwardsBy(extra);
}

// new box from ctx {
pub fn box_new_from_context(ctx: u16, hlgroup: Highlight) !u16 {
    const context = try get_context(ctx);
    const ret = try context.newBox(Box.newBoxFromContext(ctx, hlgroup));
    return @intCast(ret);
}
// }

// new box from offset {
pub fn box_new_from_offset(ctx: u16, box: u16, x: u16, y: u16) !u16 {
    const self = try get_box(ctx, box);
    const context = try get_context(self.context);
    const ret = try context.newBox(self.newBoxFromOffset(x, y));
    return @intCast(ret);
}
// }

// new box right {
pub fn box_new_right_from(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    const context = try get_context(self.context);
    const ret = try context.newBox(self.newBoxRightOf());
    return @intCast(ret);
}

pub fn box_new_below_from(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    const context = try get_context(self.context);
    const ret = try context.newBox(self.newBoxBelow());
    return @intCast(ret);
}

pub fn box_new_cursored(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    const context = try get_context(self.context);
    const ret = try context.newBox(self.newBoxCursored());
    return @intCast(ret);
}
// }

// prettry sure this is only used for canvas
pub fn box_shrink_width_to(ctx: u16, box: u16, width: u16) !void {
    const self = try get_box(ctx, box);
    try self.shrinkWidthTo(width);
}

pub fn box_update_cursor_from(ctx: u16, box: u16, other: u16) !void {
    const self = try get_box(ctx, box);
    const otherBox = try get_box(ctx, other);
    self.updateCursorFrom(otherBox);
}
pub fn box_set_width(ctx: u16, box: u16, width: u16) !void {
    const self = try get_box(ctx, box);
    try self.setWidth(width);
}

pub fn box_get_hl(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    return self.hlgroup;
}

pub fn box_set_max_width(ctx: u16, box: u16, width: i16) !void {
    const self = try get_box(ctx, box);
    self.maxWidth = @max(width, 0);
}
pub fn box_get_width(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    return @intCast(self.width);
}
pub fn box_expand_width_to(ctx: u16, box: u16, width: u16) !void {
    const self = try get_box(ctx, box);
    try self.expandWidthTo(width);
}

pub fn box_expand_height_to(ctx: u16, box: u16, height: u16) !void {
    const self = try get_box(ctx, box);
    try self.expandHeightTo(height);
}
pub fn box_shrink_height_to(ctx: u16, box: u16, height: u16) !void {
    const self = try get_box(ctx, box);
    try self.shrinkHeightTo(height);
}

pub fn box_set_height(ctx: u16, box: u16, height: u16) !void {
    const self = try get_box(ctx, box);
    try self.setHeight(height);
}

pub fn box_get_height(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    return @intCast(self.height);
}

pub fn box_clean(ctx: u16, box: u16) !void {
    const self = try get_box(ctx, box);
    try self.clean();
}

// *kinda* one of the most needed low level apis
// append str {
pub fn box_append_str(ctx: u16, box: u16, str: []const u8) !void {
    const self = try get_box(ctx, box);
    try self.appendStr(str);
}
// }

// pub fn appendStr(elf: *Box, str: [*]const u8, len: u16) bool {
//     self.appendStr_internal(str[0..len]) catch return false;
//     return true;
// }

// set hl {
pub fn box_set_hl(ctx: u16, box: u16, style: u16) !void {
    const self = try get_box(ctx, box);
    self.hlgroup = style;
}
// }

pub fn box_append_word(ctx: u16, box: u16, str: []const u8, style: Highlight) !void {
    const self = try get_box(ctx, box);
    try self.appendWord(str, style);
}
// TODO: Remove in favor of managed splitting
// pb fn getLine(i){}

// TODO: Remove in fvor of offsets

// pub fn appendBoxBelow(box, expand){}

const StripRightExpect = Expect(fn (hl: Highlight) u16);
pub fn box_context_strip_right_space(ctx: u16, expected_bg: StripRightExpect) !void {
    const context = try get_context(ctx);
    try context.stripRightSpace(expected_bg.L, 2);
}
// TODO: Unused

// pub fn trimWidthLastLine(width, trimStrat){}

// NOTE: Rendering over should *only* happen from prepared box contexts

pub fn box_render_over(ctx: u16, box: u16, otherCtx: u16, left: u16, top: u16) !void {
    const self = try get_box(ctx, box);
    const context = try get_context(otherCtx);
    try self.renderOver(context, left, top);
}
