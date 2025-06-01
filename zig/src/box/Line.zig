const std = @import("std");
const log = @import("../log.zig");
const Char = @import("Char.zig").Char;
const common = @import("common.zig");
const sub = common.sub;
const Highlight = common.Highlight;
const BoxContext = @import("BoxContext.zig");

const Self = @This();

_chars: std.ArrayListUnmanaged(Char),
_hls: std.ArrayListUnmanaged(Highlight),

pub const empty: Self = .{
    ._hls = .empty,
    ._chars = .empty,
};

pub fn init() Self {
    return .{
        ._chars = .empty,
        ._hls = .empty,
    };
}

pub fn clone(self: *const Self, alloc: std.mem.Allocator) !Self {
    var ret: Self = .empty;
    try ret._chars.appendSlice(alloc, self._chars.items);
    try ret._hls.appendSlice(alloc, self._hls.items);
    return ret;
}

pub fn getMemoryUsage(self: *const Self) usize {
    return self._chars.capacity * @sizeOf(Char) + self._hls.capacity * @sizeOf(Highlight);
}

pub fn width(self: *const Self) u16 {
    return @intCast(self._chars.items.len);
}

pub fn popLastChar(self: *Self) void {
    _ = self._chars.pop();
    _ = self._hls.pop();
}
pub fn deinit(self: *Self, alloc: std.mem.Allocator) void {
    self._chars.deinit(alloc);
    self._hls.deinit(alloc);
}
pub fn appendWordToLen(
    self: *Self,
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
pub fn appendWord(self: *Self, ctx: *BoxContext, str: []const u8, hl: Highlight) !void {
    _ = try self.appendWordToLen(ctx, str, hl, @as(u16, @intCast(str.len)) + self.width(), true);
}

pub fn ensureAppendableAt(self: *Self, ctx: *BoxContext, spot: u16, hl: Highlight) !void {
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
    self: *Self,
    ctx: *BoxContext,
    char: u8,
    hl: Highlight,
) !void {
    try self.appendAsciiNTimes(ctx, char, hl, 1);
}

pub fn ensureTotalCapacity(self: *Self, alloc: std.mem.Allocator, cap: usize) !void {
    try self._chars.ensureTotalCapacity(alloc, cap);
    try self._hls.ensureTotalCapacity(alloc, cap);
}

/// Appends an ascii char n times
pub fn insertAscii(
    self: *Self,
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
    self: *Self,
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
    self: *Self,
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

pub fn widthFrom(self: *const Self, base: u16) u16 {
    if (base > self.width()) {
        return 0;
    }
    return self.width() - base;
}
