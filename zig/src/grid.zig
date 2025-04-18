const std = @import("std");
const lua = @import("lua_api/lua.zig");
const luaL = @import("lua_api/luaL.zig");
const rowLimit = 300;
const columnLimit = 300;
const BitSetT = std.bit_set.ArrayBitSet(usize, rowLimit * columnLimit);
// var bitSet = BitSetT.initEmpty();

fn getPos(row: u32, column: u32) u32 {
    return (row - 1) * columnLimit + (column - 1);
}

// extern fn malloc(size: c_int) callconv(.C) *anyopaque;
// extern fn free(ptr: *anyopaque) callconv(.C) void;

export fn turnOnRange(bs: *BitSetT, rowStart: u32, colStart: u32, rowEnd: u32, colEnd: u32) callconv(.C) bool {
    // _ = box.initRenderCycle();
    // @compileLog(std.fmt.comptimePrint("{}", .{@sizeOf(BitSetT) * 400}));
    for (rowStart..rowEnd) |r| {
        const ogPos = getPos(@intCast(r), colStart);
        for (0..(colEnd - colStart)) |i| {
            bs.set(ogPos + i);
        }
    }
    return true;
}
pub fn lua_turnOnRange(L: *lua.State) callconv(.C) c_int {
    const args = lua.get_top(L);
    if (args != 5) {
        lua.push_bool(L, false);
        return 1;
    }
    if (!lua.is_userdata(L, 1)) {
        lua.push_bool(L, false);
        return 1;
    }
    if (!lua.is_number(L, 2)) {
        lua.push_bool(L, false);
        return 1;
    }
    if (!lua.is_number(L, 3)) {
        lua.push_bool(L, false);
        return 1;
    }
    if (!lua.is_number(L, 4)) {
        lua.push_bool(L, false);
        return 1;
    }
    if (!lua.is_number(L, 5)) {
        lua.push_bool(L, false);
        return 1;
    }
    const ptr = lua.to_userdata(L, 1);
    const rowStart = lua.to_cast_int(L, 2, u32);
    const colStart = lua.to_cast_int(L, 3, u32);
    const rowEnd = lua.to_cast_int(L, 4, u32);
    const colEnd = lua.to_cast_int(L, 5, u32);

    const ret = turnOnRange(@ptrCast(@alignCast(ptr)), rowStart, colStart, rowEnd, colEnd);
    lua.push_bool(L, ret);
    return 1;
}

export fn getNew() callconv(.C) ?*BitSetT {
    const bitSet = std.heap.page_allocator.create(BitSetT) catch return null;
    bitSet.* = BitSetT.initEmpty();
    bitSet.setRangeValue(.{ .start = 0, .end = rowLimit * columnLimit }, false);
    return bitSet;
    // bitSet.setRange(0, rowLimit * columnLimit, false);
    // const bs: *BitSetT = @ptrCast(@alignCast(malloc(@sizeOf(BitSetSection))));
    // const bs = c_alloc.create(BitSetT) catch @panic("out of memory or something");
    // bs.bitSet.setRangeValue(.{ .start = 0, .end = rowLimit * columnLimit }, false);
    // bs.bitSet = BitSetT.initEmpty(); //0x5ad5b5d642a0
    // return bs;
}

pub fn lua_getNew(L: *lua.State) callconv(.C) c_int {
    const ret = getNew().?;
    lua.push_lightuserdata(L, ret);
    return 1;
}

// export fn initExisting(bs: *BitSetT) callconv(.C) void {
//     bs.bitSet = BitSetT.initEmpty();
// }
export fn freeSection(bs: *BitSetT) callconv(.C) void {
    std.heap.page_allocator.destroy(bs);
    // free(bs);
    // _ = bs;
    // std.heap.raw_c_allocator.destroy(bitSet);
    // std.heap.raw_c_allocator.destroy(bs);
}
pub fn lua_freeSection(L: *lua.State) callconv(.C) c_int {
    const args = lua.get_top(L);
    if (args != 1) {
        lua.push_bool(L, false);
        return 1;
    }
    if (!lua.is_userdata(L, 1)) {
        lua.push_bool(L, false);
        return 1;
    }
    const ptr = lua.to_userdata(L, 1);
    freeSection(@ptrCast(@alignCast(ptr)));
    lua.push_bool(L, true);
    return 1;
}
export fn toggle(bs: *BitSetT, row: u32, column: u32) callconv(.C) bool {
    const spot = getPos(row, column);
    if (spot >= rowLimit * columnLimit) {
        return false;
    }
    bs.toggle(spot);
    return true;
}
pub fn lua_toggle(L: *lua.State) callconv(.C) c_int {
    const args = lua.get_top(L);
    if (args != 3) {
        lua.push_bool(L, false);
        return 1;
    }
    if (!lua.is_userdata(L, 1)) {
        lua.push_bool(L, false);
        return 1;
    }
    if (!lua.is_number(L, 2)) {
        lua.push_bool(L, false);
        return 1;
    }
    if (!lua.is_number(L, 3)) {
        lua.push_bool(L, false);
        return 1;
    }
    const ptr = lua.to_userdata(L, 1);
    const row = lua.to_cast_int(L, 2, u32);
    const col = lua.to_cast_int(L, 3, u32);

    const ret = toggle(@ptrCast(@alignCast(ptr)), row, col);
    lua.push_bool(L, ret);
    return 1;
}

export fn turnOn(bs: *BitSetT, row: u32, column: u32) callconv(.C) bool {
    const spot = getPos(row, column);
    if (spot >= rowLimit * columnLimit) {
        return false;
    }
    bs.set(spot);
    return true;
}
pub fn lua_turnOn(L: *lua.State) callconv(.C) c_int {
    const args = lua.get_top(L);
    if (args != 3) {
        lua.push_bool(L, false);
        return 1;
    }
    if (!lua.is_userdata(L, 1)) {
        lua.push_bool(L, false);
        return 1;
    }
    if (!lua.is_number(L, 2)) {
        lua.push_bool(L, false);
        return 1;
    }
    if (!lua.is_number(L, 3)) {
        lua.push_bool(L, false);
        return 1;
    }
    const ptr = lua.to_userdata(L, 1);
    const row = lua.to_cast_int(L, 2, u32);
    const col = lua.to_cast_int(L, 3, u32);

    const ret = turnOn(@ptrCast(@alignCast(ptr)), row, col);
    lua.push_bool(L, ret);
    return 1;
}

export fn isEnabled(bs: *BitSetT, row: u32, column: u32) callconv(.C) u32 {
    const spot = getPos(row, column);
    if (spot >= rowLimit * columnLimit) {
        return 2;
    }
    const ret: u32 = if (bs.isSet(spot)) 1 else 0;
    return ret;
}

pub fn lua_isEnabled(L: *lua.State) callconv(.C) c_int {
    const args = lua.get_top(L);
    if (args != 3) {
        lua.push_int(L, 2);
        return 1;
    }
    if (!lua.is_userdata(L, 1)) {
        lua.push_int(L, 2);
        return 1;
    }
    if (!lua.is_number(L, 2)) {
        lua.push_int(L, 2);
        return 1;
    }
    if (!lua.is_number(L, 3)) {
        lua.push_int(L, 2);
        return 1;
    }
    const ptr = lua.to_userdata(L, 1);
    const row = lua.to_cast_int(L, 2, u32);
    const col = lua.to_cast_int(L, 3, u32);

    const ret = isEnabled(@ptrCast(@alignCast(ptr)), row, col);
    lua.push_int(L, @intCast(ret));
    return 1;
}
