const hl = @import("hl.zig");
const consts = @import("nvim_api/constants.zig");
const std = @import("std");
const fns = @import("nvim_api/functions.zig");
const tps = @import("nvim_api/types.zig");
pub const BoxContext = struct {
    lines: std.ArrayList(std.ArrayList(u8)),
    hls: std.ArrayList(std.ArrayList(hl.HlAttrs)),
    alloc: std.mem.Allocator,
    // ctor/dtor
    pub fn init(alloc: std.mem.Allocator) BoxContext {
        // zig fmt: off
        return .{ 
            .lines = std.ArrayList(std.ArrayList(u8))
                .init(alloc), 
            .hls = std.ArrayList(std.ArrayList(hl.HlAttrs)).init(alloc),
            .alloc = alloc,
        };
        // zig fmt: on
    }
    pub fn deinit(self: *BoxContext) void {
        for (self.lines.items) |line| {
            line.deinit();
        }
        self.lines.deinit();
        for (self.hls.items) |line| {
            line.deinit();
        }
        self.hls.deinit();
    }

    pub fn addNewLine(self: *BoxContext) !void {
        try self.lines.append(std.ArrayList(u8).init(self.alloc));
    }
    pub fn last(self: *BoxContext) !*std.ArrayList(u8) {
        return &self.lines.items[self.lines.items.len - 1];
    }
    pub fn doThingWithErr(self: *const BoxContext, err: tps.Error) void {
        _ = self;
        std.debug.print("asdf, {}", .{err.type});
    }
    pub fn renderToBuf(self: *const BoxContext, alloc: std.mem.Allocator, buf: c_int) void {
        const start = 0;
        const end = -1;
        const strict = false;

        var replacementLines = std.ArrayList(tps.Object).init(alloc);
        defer replacementLines.deinit();

        for (self.lines.items) |line| {
            replacementLines.append(tps.stringObject(line.items)) catch return;
        }

        const replacement = tps.Array{
            .capacity = replacementLines.items.len,
            .size = replacementLines.items.len,
            .items = replacementLines.items.ptr,
        };
        var arena = tps.Arena{ .current_block = "", .pos = 0, .size = 0 };

        var err = tps.Error{
            .msg = "",
            .type = tps.ErrorType.None,
        };

        fns.nvim_buf_set_lines(consts.LUA_INTERNAL_CALL, buf, start, end, strict, replacement, &arena, &err);

        self.doThingWithErr(err);
        std.debug.print("asdf, {}", .{err.type});

        _ = 1;
    }
};
