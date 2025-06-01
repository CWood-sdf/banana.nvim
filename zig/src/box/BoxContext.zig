const std = @import("std");
const common = @import("common.zig");
const Highlight = common.Highlight;
const log = @import("../log.zig");
const lua = @import("../lua_api/lua.zig");
const tps = @import("../nvim_api/types.zig");
const fns = @import("../nvim_api/functions.zig");
const consts = @import("../nvim_api/constants.zig");
const debug = @import("../debug.zig").debug;
const Line = @import("Line.zig");
const Box = @import("Box.zig");
const PartialRendered = @import("PartialRendered.zig");
const Image = @import("Image.zig");
const PrDataStack = @import("PrDataStack.zig");

const BoxContext = @This();

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

fn linesToStringArray(self: *BoxContext, out: *std.ArrayListUnmanaged(u8), join: u8) !void {
    log.write("Creating string table\n", .{}) catch {};
    for (self.lines.items) |*line| {
        for (line._chars.items) |char| {
            var chars = [_]u8{0} ** 4;
            const bytes = try char.toBytes(&chars);
            if (bytes != 0) {
                try out.appendSlice(
                    self.alloc(),
                    chars[0..bytes],
                );
            }
        }
        try out.append(self.alloc(), join);
    }
}

// pub fn renderToString(self: *BoxContext) ![]const u8 {
//     var lines: std.ArrayListUnmanaged(u8) = .empty;
//     // defer lines.deinit(self.alloc());
//
//     try self.linesToStringArray(&lines, '\n');
//
//     lua.push_stringslice(L, self.lines.items);
//     return lines.items;
// }
// pub fn renderToArray(self: *BoxContext, L: *lua.State) !void {
//     lua.create_table(L, self.lines.items.len, 0);
//     var lines: std.ArrayListUnmanaged(u8) = .empty;
//     defer lines.deinit(self.alloc());
//
//     try self.linesToStringArray(&lines, 0);
//
//     const simdLen = std.simd.suggestVectorLength(u8);
//     var startIndex = 0;
//     var n = 1;
//     while (startIndex < lines.items.len) {
//         var endIndex = startIndex;
//         while (endIndex < lines.items.len) {
//             const avail = lines.items.len - endIndex;
//             if (avail > simdLen) {
//                 const vec: @Vector(u8, simdLen) = lines.items[endIndex .. endIndex + simdLen];
//                 const i = std.simd.firstIndexOfValue(vec, 0);
//                 if (i) |j| {
//                     endIndex += j;
//                     break;
//                 } else {
//                     endIndex += simdLen;
//                 }
//             } else {
//                 endIndex += 1;
//                 if (endIndex >= lines.items.len or lines.items[endIndex] == 0) {
//                     break;
//                 }
//             }
//         }
//         if (endIndex != startIndex) {
//             lua.push_stringslice(L, lines.items[startIndex..endIndex]);
//             lua.raw_seti(L, -1, n);
//             n += 1;
//         }
//         startIndex = endIndex + 1;
//     }
// }
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
                isBanned = try lua.to_cast_int(L, top, u8) != 0;
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
    log.write("yuhh creating string table\n", .{}) catch {};
    var arr: std.ArrayListUnmanaged(tps.Object) = .empty;
    defer arr.deinit(self.alloc());

    try arr.ensureTotalCapacity(self.alloc(), self.lines.items.len);

    var lines: std.ArrayListUnmanaged(u8) = .empty;
    defer {
        lines.deinit(self.alloc());
    }

    try self.linesToStringArray(&lines, 0);

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
    // if (arr.items.len >= 256) {
    //     // TODO: Reset cursor
    //     const clear: tps.Array = tps.Array.fromSlice(arr.items[0..0]);
    //     fns.nvim_buf_set_lines(
    //         consts.LUA_INTERNAL_CALL,
    //         @enumFromInt(buf),
    //         lineStart,
    //         lineEnd,
    //         true,
    //         clear,
    //         &arena,
    //         &err,
    //     );
    //     var endIndex = arr.items.len;
    //     while (endIndex >= 256) : (endIndex -= 255) {
    //         const replacement: tps.Array = tps.Array.fromSlice(
    //             arr.items[endIndex - 255 .. endIndex],
    //         );
    //         fns.nvim_buf_set_lines(
    //             consts.LUA_INTERNAL_CALL,
    //             @enumFromInt(buf),
    //             lineStart,
    //             lineStart,
    //             true,
    //             replacement,
    //             &arena,
    //             &err,
    //         );
    //     }
    //     const replacement: tps.Array = tps.Array.fromSlice(arr.items[0..endIndex]);
    //
    //     fns.nvim_buf_set_lines(
    //         consts.LUA_INTERNAL_CALL,
    //         @enumFromInt(buf),
    //         lineStart,
    //         lineStart,
    //         false,
    //         replacement,
    //         &arena,
    //         &err,
    //     );
    // } else {
    const replacement: tps.Array = tps.Array.fromSlice(arr.items[0..arr.items.len]);

    const arenaBuf: []u8 = @ptrCast(try self.alloc().alloc(*u8, arr.items.len + 10));
    var arena: tps.Arena = .{
        .current_block = arenaBuf.ptr,
        .size = arenaBuf.len,
        .pos = 0,
    };

    fns.nvim_buf_set_lines(
        consts.LUA_INTERNAL_CALL,
        @enumFromInt(buf),
        lineStart,
        lineEnd,
        false,
        replacement,
        &arena,
        &err,
    );
    // }
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
