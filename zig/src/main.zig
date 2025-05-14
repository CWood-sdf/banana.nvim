const std = @import("std");
const box = @import("box.zig");
const gen = @import("genlua.zig");
const hl = @import("hl.zig");
const Char = box.Char;

pub fn main() !void {
    const chars = "asdfasdf";
    const charsVec: @Vector(Char.simdLen, u8) = chars[0..8].*;
    const simd = Char.simdToChars(charsVec);
    const charArr: [8]Char = @bitCast(simd);

    const bitsBacking: u16 = 0b1111_0000_0101_1010;
    const bits: @Vector(2, u8) = @bitCast(bitsBacking);

    const newBits: u16 = @bitCast(@bitReverse(bits));
    std.debug.print("bits: {b:0>16}\n", .{newBits});

    const char0: Char = @bitCast(charArr[0]);

    const realChar = Char.fromAscii('a');

    var charSlice = [_]u8{0} ** 16;
    var i: usize = 0;
    for (charArr) |c| {
        const width = c.toBytes(charSlice[i..]) catch {
            std.debug.print("big sad :( {}\n", .{i});
            break;
        };
        i += width;
    }
    std.debug.print("New str: {s}\n", .{charSlice[0..i]});
    std.debug.print("ordering: {s}\n", .{@tagName(Char.ordering)});

    std.debug.print("width: {}\n", .{char0.width});
    std.debug.print("bytes: {}\n", .{char0.bytes});
    std.debug.print("char 0: {b:0>8}\n", .{'a'});
    std.debug.print("real  : {b:0>32}\n", .{@as(u32, @bitCast(realChar))});
    std.debug.print("actual: {b:0>32}\n", .{@as(u32, @bitCast(char0))});
    // std.debug.print("char 0: {b:0>21}\n", .{char0.char});
    // std.debug.print("char 0: {b:0>8}\n", .{@bitReverse(@as(u8, @intCast(@bitReverse(char0.char))))});
}
test "simple test" {
    var list = std.ArrayList(i32).init(std.testing.allocator);
    defer list.deinit(); // try commenting this out and see if zig detects the memory leak!
    try list.append(42);
    try std.testing.expectEqual(@as(i32, 42), list.pop());
}
