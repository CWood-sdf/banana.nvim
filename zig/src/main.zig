const std = @import("std");
// const asdf = @cImport({
//     // @cDefine("DEFINE_FUNC_ATTRIBUTES", "");
//     // @cDefine("DEFINE_EMPTY_ATTRIBUTES", "");
//     @cInclude("nvim/api/autocmd.h");
// });

pub fn main() !void {
    //
    // // https://github.com/neovim/neovim/blob/v0.9.0/src/nvim/api/private/defs.h#L43
    // const INTERNAL_CALL_MASK: u64 = 1 << (@sizeOf(u64) * 8 - 1);
    //
    // // https://github.com/neovim/neovim/blob/v0.9.0/src/nvim/api/private/defs.h#L46
    // const VIML_INTERNAL_CALL: u64 = INTERNAL_CALL_MASK;
    //
    // // https://github.com/neovim/neovim/blob/v0.9.0/src/nvim/api/private/defs.h#L49
    // const LUA_INTERNAL_CALL: u64 = VIML_INTERNAL_CALL + 1;
    //
    // var arr = std.ArrayList(asdf.Object);
    // var evs: arr = arr.init();
    // defer evs.deinit();
    // const event: [_:0]u8 = "TextYankPost";
    // const str: asdf.String = asdf.String{
    //     .size = event.len,
    //     .data = event,
    // };
    // evs.append(asdf.Object{
    //     .type =  asdf.kObjectTypeString,
    //     .data = str,
    //
    // });
    //
    // const events :asdf.Object = .{
    //     .type = asdf.kObjectTypeArray,
    //     .data = asdf.Array{
    //         .size = evs.items.len,
    //         .capacity = evs.items.len,
    //         .items = evs.items.ptr,
    //     }
    // };
    //
    // const opts: asdf.KeyDict_create_autocmd = .{
    //     .callback =
    // asdf.nvim_create_autocmd(LUA_INTERNAL_CALL, events, opts: [*c]KeyDict_create_autocmd, arena: [*c]Arena, err: [*c]Error)
    // Prints to stderr (it's a shortcut based on `std.io.getStdErr()`)
    std.debug.print("All your {s} are belong to us.\n", .{"codebase"});

    // stdout is for the actual output of your application, for example if you
    // are implementing gzip, then only the compressed bytes should be sent to
    // stdout, not any debugging messages.
    const stdout_file = std.io.getStdOut().writer();
    var bw = std.io.bufferedWriter(stdout_file);
    const stdout = bw.writer();

    const alloc = std.heap.c_allocator;
    const gridT = std.bit_set.DynamicBitSet;
    const len = 20;
    // this len^2 stuff is to avoid realloc
    // but it'll take 64 elements to alloc half a kb (which should never happen)
    var list = try gridT.initFull(alloc, len * len);
    list.toggleAll();

    try stdout.print("{}\n", .{list.isSet(1)});

    try stdout.print("Run `zig build test` to run the tests.\n", .{});
    try stdout.print("{} bits\n", .{@bitSizeOf(u64)});

    try bw.flush(); // don't forget to flush!
}

test "simple test" {
    var list = std.ArrayList(i32).init(std.testing.allocator);
    defer list.deinit(); // try commenting this out and see if zig detects the memory leak!
    try list.append(42);
    try std.testing.expectEqual(@as(i32, 42), list.pop());
}
