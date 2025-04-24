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

pub fn grid_turnOnRange(bs: *BitSetT, rowStart: u32, colStart: u32, rowEnd: u32, colEnd: u32) callconv(.C) bool {
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

pub fn grid_getNew() callconv(.C) ?*BitSetT {
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

// pub fn initExisting(bs: *BitSetT) callconv(.C) void {
//     bs.bitSet = BitSetT.initEmpty();
// }
pub fn grid_freeSection(bs: *BitSetT) callconv(.C) void {
    std.heap.page_allocator.destroy(bs);
    // free(bs);
    // _ = bs;
    // std.heap.raw_c_allocator.destroy(bitSet);
    // std.heap.raw_c_allocator.destroy(bs);
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
