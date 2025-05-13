const std = @import("std");
const box = @import("box.zig");
const gen = @import("genlua.zig");
const hl = @import("hl.zig");

pub fn main() !void {
    const vec: @Vector(4, u8) = std.simd.iota(u8, 4) + @as(@Vector(4, u8), @splat(0b1000_0000));
    const v2 = @reduce(.And, vec);
    std.debug.print("{}\n", .{v2});
}
test "simple test" {
    var list = std.ArrayList(i32).init(std.testing.allocator);
    defer list.deinit(); // try commenting this out and see if zig detects the memory leak!
    try list.append(42);
    try std.testing.expectEqual(@as(i32, 42), list.pop());
}
