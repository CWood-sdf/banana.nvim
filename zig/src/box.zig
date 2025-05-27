const debug = @import("debug.zig").debug;
const _pr = @import("pr2.zig");
const std = @import("std");
const lua = @import("lua_api/lua.zig");
const Image = @import("Image.zig");

const Hl = @import("hl.zig");
const consts = @import("nvim_api/constants.zig");
const log = @import("log.zig");
const fns = @import("nvim_api/functions.zig");
const tps = @import("nvim_api/types.zig");

pub fn subOr(l: anytype, r: anytype, default: anytype) @TypeOf(l) {
    comptime if (@TypeOf(l) != @TypeOf(r) and @TypeOf(r) != comptime_int) {
        @compileError(std.fmt.comptimePrint(
            "Got two different types to safeSubtract: l={} r={}\n",
            .{ @TypeOf(l), @TypeOf(r) },
        ));
    };
    comptime if (@TypeOf(l) != @TypeOf(default) and @TypeOf(default) != comptime_int) {
        @compileError(std.fmt.comptimePrint(
            "Got two different types to safeSubtract: l={} default={}\n",
            .{ @TypeOf(l), @TypeOf(default) },
        ));
    };

    const T = @TypeOf(l);

    if (comptime @typeInfo(T).int.signedness == .unsigned) {
        if (r > l) {
            return default;
        }
    }
    return l - r;
}
pub fn subMultOr(comptime T: type, l: []const T, comptime default: T) T {
    return subMult(T, l) catch default;
}
pub fn subMult(comptime T: type, l: []const T) !T {
    if (l.len == 0) {
        return error.EmptyArray;
    }
    var ret: T = l[0];
    for (1..l.len) |i| {
        if (comptime @typeInfo(T).int.signedness == .unsigned) {
            if (l[i] > ret) {
                return error.UnsignedSubtractToNegative;
            }
        }
        ret -= l[i];
    }
    return ret;
}
pub fn sub(l: anytype, r: anytype) !@TypeOf(l) {
    // comptime if (@TypeOf(l) != @TypeOf(r)) {
    //     @compileError(std.fmt.comptimePrint(
    //         "Got two different types to safeSubtract: {} {}\n",
    //         .{ @TypeOf(l), @TypeOf(r) },
    //     ));
    // };

    const T = @TypeOf(l);

    if (comptime @typeInfo(T).int.signedness == .unsigned) {
        if (r > l) {
            return error.UnsignedSubtractToNegative;
        }
    }
    return l - r;
}

pub const Highlight = u16;

pub const Id = u16;

pub const NullableId = struct {
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
pub const Char = packed struct(u32) {
    // the actual number
    bytes: u3,
    // the width
    width: u2,
    pad1: u3 = 0,
    char: u21,
    pad2: u3 = 0,

    pub const ordering = getByteOrdering();
    pub const simdLen = std.simd.suggestVectorLength(u32) orelse 1;

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

    pub const ByteOrdering = enum {
        left,
        right,
    };

    pub fn getByteOrdering() ByteOrdering {
        const bytes: u3 = 1;
        const width: u2 = 1;
        const char: u21 = 'a';
        const c: Char = Char.fromAscii(char);
        const cu32: u32 = @bitCast(c);
        // byte 1: bbbw_wppp
        const byte1: u8 = (@as(u8, bytes) << 5) | (@as(u8, width) << 3);
        // byte 2: pppc_cccc
        const byte2: u8 = (char & 0b1_1111_0000_0000_0000_0000) >> 16;
        // byte 3: cccc_cccc
        const byte3: u8 = (char & 0b0_0000_1111_1111_0000_0000) >> 8;
        // byte 4: cccc_cccc
        const byte4: u8 = (char & 0b0_0000_0000_0000_1111_1111);

        comptime std.debug.assert('a' == byte4);

        const ascii: @Vector(1, u8) = @splat('a');
        const b1vec: @Vector(1, u8) = @splat(byte1);
        const b2vec: @Vector(1, u8) = @splat(byte2);
        const b3vec: @Vector(1, u8) = @splat(byte3);

        const interlaced: @Vector(1, u32) = @bitCast(std.simd.interlace(
            .{ ascii, b1vec, b2vec, b3vec },
        ));
        if (@reduce(.Or, interlaced) == cu32) {
            return .left;
        }
        return .right;
    }

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

    pub fn simdToChars(chars: @Vector(simdLen, u8)) @Vector(simdLen, u32) {
        const bytes: u3 = @bitReverse(@as(u3, 1));
        const width: u2 = @bitReverse(@as(u2, 1));
        // byte 1: bbbw_wppp
        const byte1: u8 = (@as(u8, bytes) << 5) | (@as(u8, width) << 3);
        // byte 2: aaaa_aaaa
        const byte2: u8 = 0;
        // byte 3: cccc_cccc
        const byte3: u8 = 0;
        // byte 4: cccc_cppp
        // where a = bits of ascii char

        const b1vec: @Vector(simdLen, u8) = @splat(byte1);
        const b2vec: @Vector(simdLen, u8) = @bitReverse(chars);
        const b3vec: @Vector(simdLen, u8) = @splat(byte3);
        // const actualChars = @bitReverse(chars);
        const actualChars: @Vector(simdLen, u8) = @splat(byte2);
        const ret = if (ordering == .left)
            std.simd.interlace(.{ b1vec, b2vec, b3vec, actualChars })
        else
            std.simd.interlace(.{ actualChars, b3vec, b2vec, b1vec });
        const actualRet: @Vector(simdLen, u32) = @bitCast(ret);
        return @bitReverse(actualRet);
    }
    pub fn canSimd(chars: []const u8) bool {
        if (chars.len < simdLen) {
            return false;
        }
        const charsVec: @Vector(simdLen, u8) = chars[0..simdLen].*;
        const reduction = @reduce(.Or, charsVec);
        return reduction & 0b1000_0000 == 0;
    }
};

pub const Line = struct {
    _chars: std.ArrayListUnmanaged(Char),
    _hls: std.ArrayListUnmanaged(Highlight),

    pub const empty: Line = .{
        ._hls = .empty,
        ._chars = .empty,
    };

    pub fn init() Line {
        return .{
            ._chars = .empty,
            ._hls = .empty,
        };
    }

    pub fn clone(self: *const Line, alloc: std.mem.Allocator) !Line {
        var ret: Line = .empty;
        try ret._chars.appendSlice(alloc, self._chars.items);
        try ret._hls.appendSlice(alloc, self._hls.items);
        return ret;
    }

    pub fn getMemoryUsage(self: *const Line) usize {
        return self._chars.capacity * @sizeOf(Char) + self._hls.capacity * @sizeOf(Highlight);
    }

    pub fn width(self: *const Line) u16 {
        return @intCast(self._chars.items.len);
    }

    pub fn popLastChar(self: *Line) void {
        _ = self._chars.pop();
        _ = self._hls.pop();
    }
    pub fn deinit(self: *Line, alloc: std.mem.Allocator) void {
        self._chars.deinit(alloc);
        self._hls.deinit(alloc);
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
        if (self._hls.items.len != self._chars.items.len) {
            log.write("in appendWordToLen, inequal slices\n", .{}) catch {};
            @panic("inequal slices in appendWordToLen");
        }
        defer {
            if (self._hls.items.len != self._chars.items.len) {
                log.write("after appendWordToLen, inequal slices\n", .{}) catch {};
                @panic("inequal slices after appendWordToLen");
            }
        }
        if (self.width() == len and !addNoMatterWhat) {
            return 0;
        }
        while (i < str.len) {
            if (str.len < i) {
                return error.StrLenTooSmall;
            }
            const availChars = try sub(str.len, i);
            const availWidth = if (self.width() > len) 1 else try sub(len, self.width());
            const charsToUse = @min(availChars, availWidth);
            const rest = str[i..];
            if (Char.canSimd(str[i .. i + charsToUse])) {
                const vec: @Vector(Char.simdLen, u8) = rest[0..Char.simdLen].*;
                const chars = Char.simdToChars(vec);
                const arr: [Char.simdLen]Char = @bitCast(chars);
                try self._chars.appendSlice(ctx.alloc(), &arr);
                self._hls.appendNTimes(ctx.alloc(), hl, arr.len) catch |e| {
                    self._chars.shrinkRetainingCapacity(
                        self._chars.items.len - arr.len,
                    );
                    return e;
                };
                i += Char.simdLen;
            } else {
                const char = try Char.fromUtf8(rest);
                if (char.width + self.width() > len and !addNoMatterWhat) {
                    return i;
                }
                i += char.bytes;
                try self._chars.append(ctx.alloc(), char);
                self._hls.append(ctx.alloc(), hl) catch |e| {
                    self._chars.shrinkRetainingCapacity(self._chars.items.len - 1);
                    return e;
                };
                if (char.width == 2) {
                    try self._chars.append(ctx.alloc(), .dummy);
                    self._hls.append(ctx.alloc(), hl) catch |e| {
                        self._chars.shrinkRetainingCapacity(self._chars.items.len - 1);
                        return e;
                    };
                } else if (char.width > 2) {
                    return error.TripleWidthCharacter;
                }
            }
            if (self.width() >= len) {
                return i;
            }
        }
        return i;
    }
    pub fn appendWord(self: *Line, ctx: *BoxContext, str: []const u8, hl: Highlight) !void {
        _ = try self.appendWordToLen(ctx, str, hl, @as(u16, @intCast(str.len)) + self.width(), true);
    }

    pub fn ensureAppendableAt(self: *Line, ctx: *BoxContext, spot: u16, hl: Highlight) !void {
        if (self._hls.items.len != self._chars.items.len) {
            log.write("inequal slices in ensureAppendableAt\n", .{}) catch {};
            @panic("inequal slices in ensureAppendableAt");
        }
        defer {
            if (self._hls.items.len != self._chars.items.len) {
                log.write("inequal slices after ensureAppendableAt\n", .{}) catch {};
                @panic("inequal slices after ensureAppendableAt");
            }
        }
        const w = self.width();
        if (w > spot) {
            return;
        }
        try self._chars.appendNTimes(ctx.alloc(), .space, spot - w);
        self._hls.appendNTimes(ctx.alloc(), hl, spot - w) catch |e| {
            self._chars.shrinkRetainingCapacity(w);
            return e;
        };
    }
    pub fn appendAscii(
        self: *Line,
        ctx: *BoxContext,
        char: u8,
        hl: Highlight,
    ) !void {
        try self.appendAsciiNTimes(ctx, char, hl, 1);
    }

    pub fn ensureTotalCapacity(self: *Line, alloc: std.mem.Allocator, cap: usize) !void {
        try self._chars.ensureTotalCapacity(alloc, cap);
        try self._hls.ensureTotalCapacity(alloc, cap);
    }

    /// Appends an ascii char n times
    pub fn insertAscii(
        self: *Line,
        ctx: *BoxContext,
        index: u16,
        char: u8,
        hl: Highlight,
    ) !void {
        if (index > self._chars.items.len) {
            return error.OverindexingInsertAscii;
        }
        try self._chars.insert(ctx.alloc(), index, Char.fromAscii(char));
        self._hls.insert(ctx.alloc(), index, hl) catch |e| {
            _ = self._chars.orderedRemove(index);
            return e;
        };
    }

    /// Appends an ascii char n times
    pub fn insertAsciiNTimes(
        self: *Line,
        ctx: *BoxContext,
        index: u16,
        char: u8,
        hl: Highlight,
        n: u16,
    ) !void {
        for (0..n) |_| {
            try self.insertAscii(ctx, index, char, hl);
        }
    }

    /// Appends an ascii char n times
    pub fn appendAsciiNTimes(
        self: *Line,
        ctx: *BoxContext,
        char: u8,
        hl: Highlight,
        n: u16,
    ) !void {
        try self._chars.appendNTimes(ctx.alloc(), Char.fromAscii(char), n);
        self._hls.appendNTimes(ctx.alloc(), hl, n) catch |e| {
            self._chars.shrinkRetainingCapacity(self._chars.items.len - n);
            return e;
        };
    }

    pub fn widthFrom(self: *const Line, base: u16) u16 {
        if (base > self.width()) {
            return 0;
        }
        return self.width() - base;
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
    images: std.ArrayListUnmanaged(Image) = .empty,
    imageLines: std.ArrayListUnmanaged(Line) = .empty,
    partialData: PrDataStack = .empty,

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
        self.images = .empty;
        self.imageLines = .empty;
        self.partialData = .empty;
        return self.arena.reset(.retain_capacity);
    }

    pub fn cloneImage(self: *BoxContext, other: *BoxContext, imageId: u16) !u16 {
        const startLine = self.imageLines.items.len;
        if (imageId >= other.images.items.len) {
            return error.InvalidImageHandle;
        }
        const otherImage = other.images.items[imageId];
        for (other.imageLines.items[otherImage.startIndex..otherImage.endIndex]) |line| {
            const newLine: Line = try line.clone(self.alloc());
            try self.imageLines.append(self.alloc(), newLine);
        }
        const endLine = self.imageLines.items.len;
        try self.images.append(self.alloc(), .{
            .startIndex = @intCast(startLine),
            .endIndex = @intCast(endLine),
        });
        return @intCast(self.images.items.len - 1);
    }
    pub fn newImage(self: *BoxContext, x: u16, y: u16, w: u16, h: u16, overwriteHl: Highlight) !u16 {
        const image = try Image.snap(self, x, y, w, h, overwriteHl);
        try self.images.append(self.alloc(), image);

        return @intCast(self.images.items.len - 1);
    }
    pub fn renderImageOver(self: *BoxContext, imageId: u16, x: u16, y: u16) !void {
        if (imageId >= self.images.items.len) {
            return error.InvalidImageHandle;
        }
        const image = self.images.items[imageId];
        const imageLines = self.imageLines.items[image.startIndex..image.endIndex];
        for (imageLines, 0..) |imageLine, i| {
            const actualY = y + @as(u16, @intCast(i));
            const line = try self.getLine(actualY);
            try line.ensureAppendableAt(self, x + imageLine.width(), 0);
            @memcpy(line._chars.items[x .. x + imageLine.width()], imageLine._chars.items[0..]);
            @memcpy(line._hls.items[x .. x + imageLine.width()], imageLine._hls.items[0..]);
        }
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
            if (line._hls.items.len == 0) {
                continue;
            }
            var i: i16 = @intCast(line._chars.items.len - 1);
            while (i >= 0) : (i -= 1) {
                if (i < 0) {
                    break;
                }
                if (line._chars.items[@intCast(i)].isDummy()) {
                    break;
                }
                if (!line._chars.items[@intCast(i)].equals(.space)) {
                    break;
                }
                const currentHl: Highlight = line._hls.items[@intCast(i)];
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
                    lua.call(L, 1, 1);
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
                    lua.pop(L, 1);
                }
                if (isBanned.?) {
                    line.popLastChar();
                }
            }
        }
        var i: u16 = @intCast(self.lines.items.len);
        while (i > 0) {
            i -= 1;
            const line = self.lines.items[i];
            if (line._chars.items.len == 0) {
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
        for (self.lines.items) |*line| {
            for (line._chars.items) |char| {
                var chars = [_]u8{0} ** 4;
                const bytes = try char.toBytes(&chars);
                if (bytes != 0) {
                    try lines.appendSlice(
                        self.alloc(),
                        chars[0..bytes],
                    );
                }
            }
            try lines.append(self.alloc(), 0);
        }

        var startIndex: usize = 0;
        for (lines.items, 0..) |c, i| {
            if (c == 0) {
                const str = lines.items[startIndex..i];
                if (str.len == 0 and lines.items.len >= 2 and i >= lines.items.len - 2) {
                    continue;
                }
                arr.appendAssumeCapacity(tps.stringObject(str));
                startIndex = i + 1;
            }
        }

        log.write("Buf: {}\n", .{buf}) catch {};

        log.write("yo yo: {}\n", .{buf}) catch {};
        log.write("yo yo: {} with line count {}\n", .{ buf, arr.items.len }) catch {};
        // if (arr.items.len >= 256) {
        //     return;
        // }
        if (arr.items.len >= 256) {
            const clear: tps.Array = tps.Array.fromSlice(arr.items[0..0]);
            fns.nvim_buf_set_lines(
                consts.LUA_INTERNAL_CALL,
                @enumFromInt(buf),
                lineStart,
                lineEnd,
                true,
                clear,
                &arena,
                &err,
            );
        }
        var endIndex = arr.items.len;
        while (endIndex >= 256) : (endIndex -= 255) {
            const replacement: tps.Array = tps.Array.fromSlice(
                arr.items[endIndex - 255 .. endIndex],
            );
            fns.nvim_buf_set_lines(
                consts.LUA_INTERNAL_CALL,
                @enumFromInt(buf),
                lineStart,
                lineStart,
                true,
                replacement,
                &arena,
                &err,
            );
        }

        const replacement: tps.Array = tps.Array.fromSlice(arr.items[0..endIndex]);

        fns.nvim_buf_set_lines(
            consts.LUA_INTERNAL_CALL,
            @enumFromInt(buf),
            lineStart,
            if (arr.items.len < 256) lineEnd else lineStart,
            false,
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
            if (line.width() == 0) {
                continue;
            }
            var startCol: u16 = 0;
            var currentHl: Highlight = line._hls.items[0];
            var byte: u16 = 0;
            for (line._hls.items, 0..) |hl, col| {
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
                byte += line._chars.items[col].bytes;
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
        if (comptime debug) {
            var breakLine = Line.init();
            try breakLine.appendAscii(other, '-', 0);
            try breakLine.appendAscii(other, ' ', 0);
            try breakLine.appendWord(other, reason, 0);
            try other.lines.append(other.alloc(), breakLine);
            for (self.lines.items) |line| {
                var newLine = Line.init();
                try newLine._chars.appendSlice(other.alloc(), line._chars.items);
                try newLine._hls.appendSlice(other.alloc(), line._hls.items);
                try other.lines.append(other.alloc(), newLine);
            }
        }
    }
    pub fn dumpImage(self: *BoxContext, image: []const Line) !void {
        if (comptime debug) {
            try self.lines.appendSlice(self.alloc(), image);
        }
    }
    pub fn dumpComment(self: *BoxContext, comment: []const u8) !void {
        if (comptime debug) {
            var line = Line.init();
            try line.appendWord(self, comment, 0);
            try self.lines.append(self.alloc(), line);
        }
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
};

pub const PartialRendered = _pr.PartialRendered;
pub const RenderAlign = _pr.RenderAlign;
pub const RenderType = _pr.RenderType;
pub const PrDataStack = _pr.PrDataStack;

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

pub fn dumpContexts() void {
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
            // log.write("    .lines = {*}\n", .{ctx.lines.items.ptr}) catch {};
            // for (ctx.lines.items, 0..) |line, j| {
            //     log.write("      .lines[{}] = (widths {}, {})\n", .{
            //         j,
            //         line._chars.items.len,
            //         line._hls.items.len,
            //     }) catch {};
            //     // dumpStruct(line, indent[0..]);
            // }
            log.write("    .partialData = {*}\n", .{&ctx.partialData}) catch {};
            inline for (@typeInfo(@FieldType(@TypeOf(ctx.partialData), "fields")).@"struct".fields) |field| {
                const arr = @field(ctx.partialData.fields, field.name);
                log.write("      .{s} = [{}] {any}\n", .{
                    field.name,
                    arr.items.len,
                    arr.items,
                }) catch {};
                // dumpStruct(line, indent[0..]);
            }
        } else {
            log.write("    ctx {} is null\n", .{i}) catch {};
        }
        break;
    }
}

fn dumpObjectToLua(T: type, obj: *const T, L: *lua.State) !void {
    const info = @typeInfo(T).@"struct";
    inline for (info.fields) |field| {
        const name = field.name;
        const luaName = std.fmt.comptimePrint("_{s}", .{name});
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
                    else => {
                        const ptr = &@field(obj.*, name);
                        lua.create_table(L, 0, 4);
                        try dumpObjectToLua(@TypeOf(ptr.*), ptr, L);
                    },
                }
            },
            .@"enum" => {
                const value = @field(obj.*, name);
                const str = @tagName(value);
                lua.push_stringslice(L, str);
            },
            .void => {},
            else => @compileError(std.fmt.comptimePrint("omg errr {}", .{field.type})),
        }
        lua.set_field(L, top, luaName);
    }
}

const BoxExpect = ExpectStr("Banana.Box");

pub fn box_context_get_memory_usage(ctx: u16) !usize {
    const context = try get_context(ctx);
    // _ = context;
    // return 0;
    return context.arena.queryCapacity();
}
pub fn box_context_data_memory_usage(ctx: u16) !usize {
    const context = try get_context(ctx);
    // _ = context;
    // return 0;
    return context.partialData.getMemoryUsage();
}
pub fn box_context_line_memory_usage(ctx: u16) !usize {
    const context = try get_context(ctx);
    // _ = context;
    // return 0;
    var usage: usize = context.lines.capacity * @sizeOf(Line);
    for (context.lines.items) |line| {
        usage += line.getMemoryUsage();
    }
    return usage;
}
pub fn box_context_pr_memory_usage(ctx: u16) !usize {
    const context = try get_context(ctx);
    // _ = context;
    // return 0;
    return context.partials.capacity * @sizeOf(Box);
}
pub fn box_context_box_memory_usage(ctx: u16) !usize {
    const context = try get_context(ctx);
    // _ = context;
    // return 0;
    return context.boxes.capacity * @sizeOf(Box);
}

pub fn box_dump_box_data(ctx: u16, box: u16, value: BoxExpect) !void {
    const b = try get_box(ctx, box);
    try dumpObjectToLua(Box, b, value.L);
}

const PartialExpect = ExpectStr("Banana.Renderer.PartialRendered");

pub fn box_dump_pr_data(ctx: u16, pr: u16, value: PartialExpect) !void {
    const p = try get_partial(ctx, pr);
    try dumpObjectToLua(PartialRendered, p, value.L);
}

pub fn get_context(ctx: u16) !*BoxContext {
    // dumpContexts();
    if (ctx >= contexts.items.len) {
        return error.ContextNotFound;
    }
    if (contexts.items[ctx]) |*c| return c;
    return error.ContextNotFound;
}

pub fn get_box(ctx: u16, box: u16) !*Box {
    const context = try get_context(ctx);
    const b = context.getBox(box) orelse return error.BoxNotFound;
    // const indent = "  ";
    log.write("  Getting box {}:{}\n", .{ ctx, box }) catch {};
    // dumpStruct(b.*, indent[0..]);
    return b;
}
pub fn get_partial(ctx: u16, partial: u16) !*PartialRendered {
    const context = try get_context(ctx);
    const ret = context.getPartial(partial) orelse return error.PartialNotFound;
    // const indent = "  ";
    log.write("  Getting partial {}:{}\n", .{ ctx, partial }) catch {};
    // dumpStruct(ret.*, indent[0..]);
    return ret;
}

// new context {
pub fn box_context_delete_all() void {
    for (0.., contexts.items) |i, _| {
        _ = box_context_delete(@intCast(i));
    }
}
/// @return i16 the id of a new box context
pub fn box_context_create() !u16 {
    for (contexts.items, 0..) |item, i| {
        if (item) |_| continue;
        contexts.items[i] = BoxContext.init(std.heap.smp_allocator);
        return @intCast(i);
    }
    try contexts.append(std.heap.smp_allocator, null);
    const i = contexts.items.len - 1;
    contexts.items[i] = BoxContext.init(std.heap.smp_allocator);
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

pub fn box_destroy(ctx: u16, boxid: u16) !void {
    const context = try get_context(ctx);

    while (context.boxes.items.len > boxid) {
        _ = context.boxes.pop();
    }
}
// }

// partial rendereds {
pub fn box_pr_new(ctx: u16, boxid: u16) !u16 {
    const context = try get_context(ctx);
    const box = try get_box(ctx, boxid);
    const partial = PartialRendered.init(box, boxid);
    return try context.newPartial(partial);
}
pub fn box_pr_get_bound_box_count(ctx: u16, pr: u16) !u16 {
    const partial = try get_partial(ctx, pr);
    return try partial.getBoundBoxCount();
}

const BoundBoxExpect = ExpectStruct("Banana.Ast.BoundingBox", _pr.BoundBox);
pub fn box_pr_get_bound_box(ctx: u16, pr: u16, n: u16) !BoundBoxExpect {
    const partial = try get_partial(ctx, pr);
    return try partial.getBoundBox(n);
}
pub fn box_pr_set_dbg_ctx(ctx: u16, pr: u16, dbg: ?u16) !void {
    const partial = try get_partial(ctx, pr);
    partial.setDebugContext(dbg);
}
pub fn box_pr_set_margin(ctx: u16, partialid: u16, left: u16, right: u16, top: u16, bottom: u16) !void {
    const partial = try get_partial(ctx, partialid);
    try partial.setMargin(.init(left, right, top, bottom));
}
pub fn box_pr_set_pad(ctx: u16, partialid: u16, left: u16, right: u16, top: u16, bottom: u16) !void {
    const partial = try get_partial(ctx, partialid);
    try partial.setPadding(.init(left, right, top, bottom));
}
pub fn box_pr_set_main_hl(ctx: u16, partialid: u16, hl: Highlight) !void {
    const partial = try get_partial(ctx, partialid);
    try partial.setMainColor(hl);
}

pub fn box_pr_get_min_width(ctx: u16, partialid: u16) !u16 {
    const partial = try get_partial(ctx, partialid);
    return try partial.getMinWidth();
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
    try partial.setMaxHeight(height);
}
pub fn box_pr_set_max_width(ctx: u16, partialid: u16, width: u16, force: ?bool) !void {
    const partial = try get_partial(ctx, partialid);
    try partial.setMaxWidth(width, force orelse false);
}
pub fn box_pr_increase_max_width(ctx: u16, partialid: u16, width: u16) !void {
    const partial = try get_partial(ctx, partialid);
    try partial.setMaxWidth(width, true);
}
pub fn box_pr_box(ctx: u16, partialid: u16) !u16 {
    const partial = try get_partial(ctx, partialid);
    return try partial.createBox();
}
pub fn box_pr_set_vertical_align(ctx: u16, partialid: u16, al: u16) !void {
    const partial = try get_partial(ctx, partialid);
    try partial.setVerticalAlign(try std.meta.intToEnum(RenderAlign, al));
}
pub fn box_pr_get_align(ctx: u16, partialid: u16) !u16 {
    const partial = try get_partial(ctx, partialid);
    const al = try partial.getSideAlign(try get_context(ctx));
    return @intFromEnum(al);
}
pub fn box_pr_set_align(ctx: u16, partialid: u16, al: u16) !void {
    const partial = try get_partial(ctx, partialid);
    try partial.setAlign(try std.meta.intToEnum(RenderAlign, al));
}
pub fn box_pr_render(ctx: u16, partialid: u16, lineHeight: ?u16) !u16 {
    const partial = try get_partial(ctx, partialid);
    return try partial.render(lineHeight);
}

pub fn box_pr_deinit(ctx: u16, partialid: u16) !void {
    const partial = try get_partial(ctx, partialid);
    partial.deinit();
}

pub fn box_pr_get_render_type(ctx: u16, partialid: u16) !u16 {
    const partial = try get_partial(ctx, partialid);
    return @intFromEnum(partial.tag.tag);
}
pub fn box_pr_set_render_type(ctx: u16, partialid: u16, renderType: u8) !void {
    const partial = try get_partial(ctx, partialid);
    partial.setRenderType(try std.meta.intToEnum(RenderType, renderType));
}

// }

pub fn box_image_clone(ctx: u16, otherCtx: u16, imageId: u16) !u16 {
    const context = try get_context(ctx);
    const other = try get_context(otherCtx);
    return try context.cloneImage(other, imageId);
}
pub fn box_image_snap(ctx: u16, x: u16, y: u16, w: u16, h: u16, newHl: Highlight) !u16 {
    const context = try get_context(ctx);
    log.write("YO IMAGE: {} {} {} {} {}\n", .{ x, y, w, h, newHl }) catch {};
    return try context.newImage(x, y, w, h, newHl);
}

pub fn box_image_render_over(ctx: u16, image: u16, x: u16, y: u16) !void {
    const context = try get_context(ctx);
    return try context.renderImageOver(image, x, y);
}

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

pub fn box_unsafe_set_width(ctx: u16, boxid: u16, width: u16) !void {
    const box = try get_box(ctx, boxid);
    box.unsafeSetWidth(width);
}
pub fn box_unsafe_increase_offset(ctx: u16, boxid: u16, left: i16, top: i16) !void {
    const box = try get_box(ctx, boxid);
    box.increaseOffsetBy(left, top);
}
pub fn box_unsafe_increase_cursor(ctx: u16, boxid: u16, left: i16, top: i16) !void {
    const box = try get_box(ctx, boxid);
    box.increaseCursorBy(left, top);
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
pub fn ExpectStruct(comptime str: []const u8, T: type) type {
    _ = str;
    return T;
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
pub fn box_get_offset_y(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    return self.offsetY;
}
pub fn box_get_offset_x(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    return self.offsetX;
}
pub fn box_get_cursor_y(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    return self.cursorY;
}
pub fn box_get_cursor_x(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    return self.cursorX;
}

pub fn box_get_hl(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    return self.hlgroup;
}
pub fn box_get_max_width(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    return self.maxWidth;
}
pub fn box_get_max_height(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    return self.maxHeight;
}

pub fn box_set_max_width(ctx: u16, box: u16, width: i16) !void {
    const self = try get_box(ctx, box);
    self.maxWidth = @max(width, 0);
}
pub fn box_set_max_height(ctx: u16, box: u16, height: i16) !void {
    const self = try get_box(ctx, box);
    self.maxHeight = @max(height, 0);
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
    try context.stripRightSpace(expected_bg.L, lua.get_top(expected_bg.L));
}
// TODO: Unused

// pub fn trimWidthLastLine(width, trimStrat){}

// NOTE: Rendering over should *only* happen from prepared box contexts

pub fn box_render_over(ctx: u16, box: u16, otherCtx: u16, left: u16, top: u16) !void {
    const self = try get_box(ctx, box);
    const context = try get_context(otherCtx);
    try self.renderOver(context, left, top);
}
