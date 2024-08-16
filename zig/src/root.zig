const std = @import("std");
const testing = std.testing;

export fn add(a: i32, b: i32) i32 {
    return a + b;
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

const GridInputElement = extern struct {
    // index: u32,
    row: u32,
    column: u32,
    rowSize: u32,
    columnSize: u32,
};

const GridOutput = extern struct { maxRows: u32, maxColumns: u32, isValid: bool, time: u32, len: u32 };

fn getPos(row: u32, column: u32, len: u32) u32 {
    if (row < 1) {
        return getPos(1, column, len);
    }
    if (column < 1) {
        return getPos(row, 1, len);
    }
    return (row - 1) * len + (column - 1);
}

export fn gridPlace(arr: [*]GridInputElement, len: u32) callconv(.C) GridOutput {
    // prep
    var counter = std.time.Timer.start() catch return GridOutput{ .maxRows = 0, .maxColumns = 0, .isValid = true, .time = 10, .len = len };
    const alloc = std.heap.c_allocator;
    // const alloc = gpa.allocator();
    // defer _ = gpa.deinit();
    const gridT = std.bit_set.DynamicBitSet;
    // this len^2 stuff is to avoid realloc
    // but it'll take 64 elements to alloc half a kb (which should never happen)
    var list = gridT.initFull(alloc, len * len) catch return GridOutput{ .maxRows = 0, .maxColumns = 0, .isValid = true, .time = 100, .len = len };
    list.toggleAll();
    defer list.deinit();

    var maxRow: u32 = 0;
    var maxColumn: u32 = 0;
    var i: u32 = 0;
    while (i < len) {
        const el = arr[i];
        if (el.row == 0 or el.column == 0) {
            i += 1;
            continue;
        }
        list.set(getPos(el.row, el.column, len));
        maxRow = @max(el.row, maxRow);
        maxColumn = @max(el.column, maxColumn);
        i += 1;
    }

    i = 0;
    // var count: u32 = 0;
    while (i < len) {
        const el = &arr[i];
        // count += 1;
        // if (count < 0) {
        //     i += 1;
        //     continue;
        // }
        // if (el.row == 0 or el.column == 0) {
        //     i += 1;
        //     continue;
        // }
        // _ = getPos(el.row, el.column, len);
        if (el.row == 0 and el.column != 0) {
            i += 1;
            continue;
        }
        var col: u32 = 1;
        var idx = getPos(el.row, col, len);
        // if (idx >= list.count()) {
        //     return GridOutput{ .maxRows = el.row, .maxColumns = col, .isValid = true, .time = @intCast(counter.read() / 1000), .len = @intCast(list.count()) };
        // }
        while (list.isSet(idx)) {
            col += 1;
            idx = getPos(el.row, col, len);
            // if (idx >= list.count()) {
            //     return GridOutput{ .maxRows = el.row, .maxColumns = col, .isValid = true, .time = @intCast(counter.read() / 1000), .len = @intCast(list.count()) };
            // }
        }
        // list.set(getPos(el.row, col, len));
        el.column = col;
        maxRow = @max(el.row, maxRow);
        maxColumn = @max(col, maxColumn);
        i += 1;
    }
    // return GridOutput{ .maxRows = 0, .maxColumns = 0, .isValid = true, .time = @intCast(counter.read() / 1000), .len = @intCast(list.count()) };

    i = 0;
    while (i < len) {
        const el = arr[i];
        var col = el.column;
        const moveCol = col == 0;
        var row: u32 = 1;
        if (el.row != 0) {
            i += 1;
            continue;
        }
        if (col == 0) {
            col = 1;
        }
        while (list.isSet(getPos(row, col, len))) {
            if (moveCol) {
                col += 1;
                if (col > maxColumn) {
                    col = 1;
                    row += 1;
                }
            } else {
                row += 1;
            }
        }
        list.set(getPos(row, col, len));
        arr[i].column = col;
        arr[i].row = row;
        maxRow = @max(row, maxRow);
        maxColumn = @max(col, maxColumn);
        i += 1;
    }

    return GridOutput{ .maxRows = 0, .maxColumns = 0, .isValid = true, .time = @intCast(counter.read() / 1000), .len = len };
}

test "basic add functionality" {
    try testing.expect(add(3, 7) == 10);
}
