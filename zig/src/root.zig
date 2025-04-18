const std = @import("std");
const lua = @import("lua_api/lua.zig");
const luaL = @import("lua_api/luaL.zig");
const b4 = @import("box4.zig");
const testing = std.testing;

export fn add(a: i32, b: i32) i32 {
    return a + b;
}

// NOTE: array MUST end with null
pub const regs = [_]luaL.Reg{
    luaL.Reg.init("box_context_create", b4.lua_new_context),
    luaL.Reg.init("box_context_delete", b4.lua_delete_context),
    luaL.Reg.init("box_context_exists", b4.lua_context_exists),
    luaL.Reg.init("box_context_render", b4.lua_context_render),
    luaL.Reg.init("box_context_highlight", b4.lua_context_highlight),
    luaL.Reg.init("box_new_from_context", b4.lua_new_from_ctx),
    luaL.Reg.init("box_new_from_offset", b4.lua_new_from_offset),
    luaL.Reg.init("box_new_right_from", b4.lua_new_right),
    luaL.Reg.init("box_append_str", b4.lua_append_str),
    luaL.Reg.init("box_set_hl", b4.lua_set_hl),
    .Null,
};

export fn luaopen_banana_libbanana(state: *lua.State) c_int {
    luaL.register(state, "libbanana", &regs);
    return 1;
}

export fn addToString(str: [*:0]u8) void {
    var i: u8 = 0;
    while (str[i] != 0) {
        if (str[i] >= '0' and str[i] <= '9') {
            str[i] += 1;
        }
        i += 1;
    }
}

export fn contextThing() void {
    var ctx = b4.BoxContext.init(std.heap.page_allocator);
    defer ctx.deinit();

    var box = b4.Box.newBoxFromContext(&ctx, 0);
    box.appendStr(@as([]const u8, "asdf")) catch return;
}

const rowLimit = 300;
const columnLimit = 300;
const BitSetT = std.bit_set.ArrayBitSet(usize, rowLimit * columnLimit);
var bitSet = BitSetT.initEmpty();

const BitSetSection = extern struct {
    bitSet: BitSetT,
};

fn getPos(row: u32, column: u32) u32 {
    return (row - 1) * columnLimit + (column - 1);
}

// extern fn malloc(size: c_int) callconv(.C) *anyopaque;
// extern fn free(ptr: *anyopaque) callconv(.C) void;

export fn turnOnRange(bs: *BitSetSection, rowStart: u32, colStart: u32, rowEnd: u32, colEnd: u32) callconv(.C) bool {
    // _ = box.initRenderCycle();
    // @compileLog(std.fmt.comptimePrint("{}", .{@sizeOf(BitSetSection) * 400}));
    _ = bs;
    for (rowStart..rowEnd) |r| {
        const ogPos = getPos(@intCast(r), colStart);
        for (0..(colEnd - colStart)) |i| {
            bitSet.set(ogPos + i);
        }
    }
    return true;
}

export fn getNew() callconv(.C) void {
    bitSet.setRangeValue(.{ .start = 0, .end = rowLimit * columnLimit }, false);
    // bitSet.setRange(0, rowLimit * columnLimit, false);
    // const bs: *BitSetSection = @ptrCast(@alignCast(malloc(@sizeOf(BitSetSection))));
    // const bs = c_alloc.create(BitSetSection) catch @panic("out of memory or something");
    // bs.bitSet.setRangeValue(.{ .start = 0, .end = rowLimit * columnLimit }, false);
    // bs.bitSet = BitSetT.initEmpty(); //0x5ad5b5d642a0
    // return bs;
}

export fn initExisting(bs: *BitSetSection) callconv(.C) void {
    bs.bitSet = BitSetT.initEmpty();
}
export fn freeSection(bs: *BitSetSection) callconv(.C) void {
    // free(bs);
    _ = bs;
    // std.heap.raw_c_allocator.destroy(bitSet);
    // std.heap.raw_c_allocator.destroy(bs);
}
export fn toggle(bs: *BitSetSection, row: u32, column: u32) callconv(.C) bool {
    _ = bs;
    const spot = getPos(row, column);
    if (spot >= rowLimit * columnLimit) {
        return false;
    }
    bitSet.toggle(spot);
    return true;
}

export fn turnOn(bs: *BitSetSection, row: u32, column: u32) callconv(.C) bool {
    _ = bs;
    const spot = getPos(row, column);
    if (spot >= rowLimit * columnLimit) {
        return false;
    }
    bitSet.set(spot);
    return true;
}

export fn isEnabled(bs: *BitSetSection, row: u32, column: u32) callconv(.C) u32 {
    _ = bs;
    const spot = getPos(row, column);
    if (spot >= rowLimit * columnLimit) {
        return 2;
    }
    const ret: u32 = if (bitSet.isSet(spot)) 1 else 0;
    return ret;
}

test "basic add functionality" {
    try testing.expect(add(3, 7) == 10);
}
