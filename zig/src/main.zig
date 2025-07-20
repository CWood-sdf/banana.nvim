// const std = @import("std");
// const box = @import("box.zig");
// const gen = @import("genlua.zig");
// const hl = @import("hl.zig");
// const Char = box.Char;

pub fn main() !void {
    // const chars = "asdfasdf";
    // // const charsVec: @Vector(Char.simdLen, u8) = chars[0..8].*;
    // const char = Char.fromAscii(chars[0]);
    //
    // std.debug.print("{}\n", .{@bitOffsetOf(Char, "char")});
    // std.debug.print("{b:0>32}\n", .{@as(u32, chars[0]) << @bitOffsetOf(Char, "char")});
    // std.debug.print("{b:0>32}\n", .{@as(u32, @bitCast(char))});
}
test "simple test" {
    // var list = std.ArrayList(i32).init(std.testing.allocator);
    // defer list.deinit(); // try commenting this out and see if zig detects the memory leak!
    // try list.append(42);
    // try std.testing.expectEqual(@as(i32, 42), list.pop());
}
