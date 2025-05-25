const b = @import("box.zig");
const Line = b.Line;
const BoxContext = b.BoxContext;
const Highlight = b.Highlight;
const Self = @This();

/// Inclusive to BoxContext.imageLines
startIndex: u16,
/// Exclusive to BoxContext.imageLines
endIndex: u16,

pub fn snap(context: *BoxContext, x: u16, y: u16, w: u16, h: u16, overwriteHl: Highlight) !Self {
    const alloc = context.alloc();
    const startIndex = context.imageLines.items.len;
    for (0..h) |i| {
        const actualY = y + @as(u16, @intCast(i));
        const line = try context.getLine(actualY);
        const newLine: Line = try line.clone(context.alloc());
        // alloc jagged images just in case an inline el is relative
        const lineEnd = @min(x + w, line.width());

        @memset(line._chars.items[x..lineEnd], .space);
        @memset(line._hls.items[x..lineEnd], overwriteHl);

        try context.imageLines.append(alloc, newLine);
    }
    const endIndex = context.imageLines.items.len;
    return .{
        .startIndex = @intCast(startIndex),
        .endIndex = @intCast(endIndex),
    };
}
