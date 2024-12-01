const std = @import("std");

const Alloc = std.heap.ArenaAllocator;

// const BoxContext = extern struct {
//     allocator: *Alloc,
//     fn init() !BoxContext {
//         const a = try std.heap.c_allocator.create(Alloc);
//         return .{ .allocator = a };
//     }
//     fn deinit(self: *BoxContext) void {
//         self.allocator.deinit();
//         std.heap.c_allocator.destroy(self.allocator);
//     }
// };
//
// var contexts = [_]?BoxContext{null} ** 1000;
// const Style = packed struct {
//     bold: u1,
//     standout: u1,
//     strikethrough: u1,
//     underline: u1,
//     undercurl: u1,
//     underdouble: u1,
//     underdotted: u1,
//     underdashed: u1,
//     italic: u1,
//     reverse: u1,
//     altfont: u1,
//     nocombine: u1,
//     default: u1,
//     fg_indexed: u1,
//     bg_indexed: u1,
//     force: u1,
//     fallback: u1,
//     fg: [*]u8,
//     bg: [*]u8,
//     ctermfg: u32,
//     ctermbg: u32,
//     special: u32,
//     sp: [*]u8,
//     link: [*]u8,
//     global_link: u32,
//     blend: u32,
//     url: [*]u8,
// };
//
// var styleArray: [1000]Style = .{};
//
// const Word = struct {
//     word: [16]u8,
//     style: u32,
// };
//
// const Box = struct {
//     lines: std.ArrayList(std.ArrayList(Word)),
//     context: u32,
// };
//
// pub export fn initRenderCycle() i32 {
//     for (contexts, 0..) |c, i| {
//         if (c) |_| {} else {
//             contexts[i] = BoxContext.init() catch return -1;
//             return @intCast(i);
//         }
//     }
//     return -1;
// }
//
// export fn clearRender(index: u32) void {
//     if (contexts[index]) |*c| {
//         c.deinit();
//     }
//     contexts[index] = null;
// }
