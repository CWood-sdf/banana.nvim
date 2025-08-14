const log = @import("log.zig");
pub fn banana_init_log(path: []const u8) !void {
    try log.init(path);
}
