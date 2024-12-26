const std = @import("std");
const hl = @import("hl.zig");

/// API should be like:
///
/// Instance acquires a box context
/// That box context should be passed down thru render chain
/// Ideally we could just call box.renderOutput(buf, ns, win...) and it renders using ffi of the nvim_ functions (this would be easy to do for rendering lines)
const Alloc = std.heap.ArenaAllocator;

const BoxContext = extern struct {
    parent: ?usize,
    allocator: *Alloc,
    fn init() !BoxContext {
        const a = try std.heap.c_allocator.create(Alloc);
        return .{ .allocator = a };
    }
    fn deinit(self: *BoxContext) void {
        self.allocator.deinit();
        std.heap.c_allocator.destroy(self.allocator);
    }
};

var contexts = [_]?BoxContext{null} ** 1000;
//
const Word = struct { word: std.ArrayList(u8), style: hl.HlAttrs };

const Box = struct {
    lines: std.ArrayList(std.ArrayList(Word)),
    context: usize,
    fn renderToBuf(self: *const Box, buf: i32, ns: i32, win: i32) void {
        _ = self; // autofix
        _ = win; // autofix
        _ = ns; // autofix
        _ = buf; // autofix
        // nvim_buf_set_lines
        // nvim_buf_ns_clear (or whatever it is)
        // need to empty previous context because it is safe to now (AKA neovim wont have any references to any freed strings)
    }
};
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
