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

pub fn grid_turnOnRange(bs: *BitSetT, rowStart: u32, colStart: u32, rowEnd: u32, colEnd: u32) callconv(.C) bool {
    for (rowStart..rowEnd) |r| {
        const ogPos = getPos(@intCast(r), colStart);
        for (0..(colEnd - colStart)) |i| {
            bs.set(ogPos + i);
        }
    }
    return true;
}

pub fn grid_getNew() callconv(.C) ?*BitSetT {
    const bitSet = std.heap.page_allocator.create(BitSetT) catch return null;
    bitSet.* = BitSetT.initEmpty();
    bitSet.setRangeValue(.{ .start = 0, .end = rowLimit * columnLimit }, false);
    return bitSet;
}

pub fn grid_freeSection(bs: *BitSetT) callconv(.C) void {
    std.heap.page_allocator.destroy(bs);
}
pub fn grid_toggle(bs: *BitSetT, row: u32, column: u32) callconv(.C) bool {
    const spot = getPos(row, column);
    if (spot >= rowLimit * columnLimit) {
        return false;
    }
    bs.toggle(spot);
    return true;
}

pub fn grid_turnOn(bs: *BitSetT, row: u32, column: u32) callconv(.C) bool {
    const spot = getPos(row, column);
    if (spot >= rowLimit * columnLimit) {
        return false;
    }
    bs.set(spot);
    return true;
}

pub fn grid_isEnabled(bs: *BitSetT, row: u32, column: u32) callconv(.C) u32 {
    const spot = getPos(row, column);
    if (spot >= rowLimit * columnLimit) {
        return 2;
    }
    const ret: u32 = if (bs.isSet(spot)) 1 else 0;
    return ret;
}
