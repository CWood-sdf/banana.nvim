const std = @import("std");
const fns = @import("nvim_api/functions.zig");
const tps = @import("nvim-api/types.zig");
const Hl = @import("hl.zig");
fn codepointLen(char: u8) u8 {
    if (char < 128) {
        return 1;
    }
    if (char < 224) {
        return 2;
    }
    if (char < 240) {
        return 3;
    }
    return 4;
}

pub fn lineWidth(line: *std.ArrayList(u8)) tps.NvimError!tps.Integer {
    const ret = try fns.z_nvim_strwidth(line.items);
    return ret;
}

const Box = struct {
    lines: std.ArrayList(Line),
    hls: std.ArrayList(HlLine),
    alloc: std.mem.Allocator,
    hl: Hl.HlAttrs,
    dirty: bool,
    width: ActualPos,
    fillChar: u32,
    const Line = std.ArrayList(u8);
    const HlLine = std.ArrayList(Hl.HlAttrs);
    const VisualPos = struct {
        value: usize,
    };
    const ActualPos = struct {
        value: usize,
    };

    pub fn init(alloc: std.mem.Allocator) Box {
        return .{
            .lines = std.ArrayList(Line).init(alloc),
            .hls = std.ArrayList(HlLine).init(alloc),
            .alloc = alloc,
            .hl = std.mem.zeroes(Hl.HlAttrs),
        };
    }

    pub fn lineWidth(self: *Box, line: usize) !tps.Integer {
        if (line >= self.lines.items.len) {
            return error.OutOfBounds;
        }
        return try fns.z_nvim_strwidth(self.lines.items[line].items);
    }

    pub fn getActualX(self: *Box, x: VisualPos, y: usize) !ActualPos {
        const line = self.lines.items[y];
        // if too small, then error
        if (x > line.items.len) {
            return error.OverIndexing;
        }
        var actualPos = x;
        var baseWidth = try fns.z_nvim_str_width(line.items[0..actualPos]);
        while (baseWidth < x) {
            if (actualPos >= line.items.len) {
                return error.OverIndexing;
            }
            const og = actualPos;
            actualPos += codepointLen(line.items[actualPos]);
            baseWidth += try fns.z_nvim_str_width(line.items[og..actualPos]);
        }
        return .{ .value = actualPos };
    }

    // TODO: PUBLIC API
    pub fn render(self: *Box, buf: tps.Buffer) void {
        _ = buf; // autofix
        _ = self; // autofix

    }
    pub fn renderOver(self: *Box, otherBox: *const Box, x: VisualPos, y: usize) !void {
        _ = y; // autofix
        _ = x; // autofix
        _ = otherBox; // autofix
        _ = self; // autofix
    }

    pub fn addPadding(
        self: *Box,
        x: VisualPos,
        y: usize,
        padChar: u8,
        width: usize,
        height: usize,
    ) !void {
        while (self.lines.len < y + height) {
            try self.lines.append(Line.init(self.alloc));
            try self.hls.append(HlLine.init(self.alloc));
        }
        for (y..(y + height)) |i| {
            var line = &self.lines.items[i];
            var hlLine = &self.hls.items[i];
            const currentWidth = try fns.z_nvim_strwidth(line.items);
            const extra = x.value + width - currentWidth;
            if (extra > 0) {
                try line.appendNTimes(padChar, extra);
                try hlLine.appendNTimes(self.hl, extra);
            }
        }
    }

    pub fn addStr(self: *Box, str: []u8, line: usize) !void {
        while (self.lines.len < line) {
            try self.lines.append(Line.init(self.alloc));
            try self.hls.append(HlLine.init(self.alloc));
        }
    }

    pub fn setHl(hl: Hl.HlAttrs) !void {
        _ = hl; // autofix
    }
};
