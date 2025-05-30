const std = @import("std");
const debug = @import("debug.zig").debug;
pub fn init() !void {
    const file = try std.fs.cwd().createFile("log.txt", .{});
    defer file.close();
}

pub inline fn write(comptime fmt: []const u8, extra: anytype) !void {
    // _ = fmt;
    // _ = extra;
    if (comptime debug) {
        const file = try std.fs.cwd().createFile("log.txt", .{
            .truncate = false,
        });
        defer file.close();

        try file.seekFromEnd(0);
        _ = try std.fmt.format(file.writer(), fmt, extra);
    }
}
