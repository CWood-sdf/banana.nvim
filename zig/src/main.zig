const std = @import("std");
const hl = @import("hl.zig");
// const asdf = @cImport({
//     // @cDefine("DEFINE_FUNC_ATTRIBUTES", "");
//     // @cDefine("DEFINE_EMPTY_ATTRIBUTES", "");
//     @cInclude("nvim/api/autocmd.h");
// });

pub fn main() !void {
    var h = hl.HlAttrs{};
    std.debug.print("{d}\n", .{h.rgb_ae_attr});
    const str = "underdashed";
    const str2 = "bold";
    hl.setHlBool(&h, str[0..], true);
    std.debug.print("{d}\n", .{h.rgb_ae_attr});
    hl.setHlBool(&h, str[0..], false);
    std.debug.print("{d}\n", .{h.rgb_ae_attr});
    hl.setHlBool(&h, str2[0..], true);
    std.debug.print("{d}\n", .{h.rgb_ae_attr});
    hl.setHlBool(&h, str[0..], true);
    std.debug.print("{d}\n", .{h.rgb_ae_attr});
}

test "simple test" {
    var list = std.ArrayList(i32).init(std.testing.allocator);
    defer list.deinit(); // try commenting this out and see if zig detects the memory leak!
    try list.append(42);
    try std.testing.expectEqual(@as(i32, 42), list.pop());
}
