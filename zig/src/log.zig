const std = @import("std");
const debug = @import("debug.zig").debug;
var path: [1000]u8 = @splat(0);
var pathLen: u32 = 0;

var buffer: [4096]u8 = undefined;
pub fn init(p: []const u8) !void {
    if (p.len > path.len) {
        return error.LogPathTooBig;
    }
    @memcpy(path[0..p.len], p);
    pathLen = @intCast(p.len);
    const file = std.fs.cwd().createFile(path[0..pathLen], .{}) catch return error.FileProblem;
    defer file.close();
}

pub inline fn write(comptime fmt: []const u8, extra: anytype) !void {
    // _ = fmt;
    // _ = extra;
    if (comptime debug) {
        if (pathLen == 0) {
            return;
        }
        const file = std.fs.cwd().createFile(path[0..pathLen], .{
            .truncate = false,
        }) catch return error.FileProblem;
        defer file.close();

        try file.seekFromEnd(0);
        var writer = file.writer(&buffer);
        _ = try writer.interface.print(fmt, extra);
        _ = try writer.interface.flush();
        // _ = try std.fmt.format(writer.interface, fmt, extra);
    }
}
