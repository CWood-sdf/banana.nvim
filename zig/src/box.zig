const std = @import("std");
const hl = @import("hl.zig");
const fns = @import("nvim_api/functions.zig");
const tps = @import("nvim_api/types.zig");

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

pub fn lineWidth(line: *std.ArrayList(u8)) u32 {
    const err = tps.Error{ .type = .None, .msg = 0 };

    return fns.nvim_strwidth(tps.String.fromSlice(line.items), &err);
}
pub const ContextError = error{
    OutOfContexts,
    ContextNotFound,
};

/// API should be like:
///
/// Instance acquires a box context
/// That box context should be passed down thru render chain
/// Ideally we could just call box.renderOutput(buf, ns, win...) and it renders using ffi of the nvim_ functions (this would be easy to do for rendering lines)
/// Current ideas:
/// Box context contains all strings and highlights and boxes just request data be put into that
/// This would require a box to know it's position pre-render (AKA margin and pad need to be calc'd and applied before then)
///

// TODO:
// - need to handle characters greater than one byte
// - render areas (for padding and stuff)
// - render lines properly
// - export all this functionality
// - need to invert order of rendering (mostly done already)
// - need to create boxcontexts for flex
// - enforce box being square
// - send hls from lua to zig
const BoxContext = struct {
    arena: std.heap.ArenaAllocator,
    boxList: std.ArrayList(?Box),
    lines: std.ArrayList(std.ArrayList(u8)),
    hls: std.ArrayList(hl.HlAttrs),
    offsetX: i32,
    offsetY: i32,
    width: u32,
    hl: hl.HlAttrs,
    pub fn init(alloc: std.mem.Allocator) BoxContext {
        var a = std.heap.ArenaAllocator.init(alloc);
        // zig fmt: off
        return .{ 
            .arena = a, 
            .boxList = std.ArrayList(?Box)
                .init(a.allocator()), 
            .lines = std.ArrayList(std.ArrayList(u8))
                .init(a.allocator()), 
            .hls = std.ArrayList(hl.HlAttrs).init(a.allocator()),
            .offsetX = 0, 
            .offsetY = 0, 
            .width = 0, 
            .hl = std.mem.zeroes(hl.HlAttrs) 
        };
        // zig fmt: on
    }
    pub fn deinit(self: *BoxContext) void {
        self.boxList.deinit();
        for (self.lines) |line| {
            line.deinit();
        }
        self.lines.deinit();
        self.arena.deinit();
    }

    pub fn renderLineOver(self: *BoxContext, startX: usize, startY: usize, line: []u8, color: hl.HlAttrs) void {
        _ = color; // autofix
        _ = line; // autofix
        _ = startY; // autofix
        _ = startX; // autofix
        _ = self; // autofix
    }

    pub fn addLine(self: *BoxContext) void {
        var newLine = std.ArrayList(u8).init(self.arena.allocator());
        newLine.appendNTimes(' ', self.width);
        self.lines.append(newLine);
        var hlLine = std.ArrayList(hl.HlAttrs).init(self.arena.allocator());
        hlLine.appendNTimes(self.hl, self.width);
        self.hls.append(hlLine);
    }

    fn adjustWidthFrom(self: *BoxContext, line: *std.ArrayList(u8)) void {
        self.width = std.math.maxInt(lineWidth(&line), self.width);
    }

    fn setCharAt(self: *BoxContext, x: usize, y: usize, char: u8, color: hl.HlAttrs) void {
        while (y < self.lines.items.len) {
            self.addLine();
        }
        const sizeDiff = x + 1 - self.lines.items[y].items.len;
        self.lines.items[y].appendNTimes(' ', sizeDiff);
        self.hls.items[y].appendNTimes(self.hl, sizeDiff);
        self.lines.items[y].items[x] = char;
        self.hls.items[y].items[x] = color;
        self.adjustWidthFrom(&self.lines.items[y]);
    }

    pub fn renderCtxOver(self: *BoxContext, other: usize) ContextError!void {
        const otherCtx = contexts[other] orelse return ContextError.ContextNotFound;
        var i = 0;
        var j = 0;
        while (j < otherCtx.height) {
            while (i < otherCtx.width) {
                self.lines.items[j + otherCtx.offsetY].items[i + otherCtx.offsetX] = other.lines.items[j].items[i];
                i += 1;
            }
            j += 1;
        }
    }
};

var contexts: [1000]?BoxContext = [1]?BoxContext{null} ** 1000;
// const Word = struct { word: std.ArrayList(u8), style: hl.HlAttrs };

const Box = struct {
    startX: usize,
    startY: usize,
    width: usize,
    height: usize,
    context: usize,
    fn renderToBuf(self: *const Box, buf: i32, ns: i32, win: i32) void {
        _ = self; // autofix
        _ = win; // autofix
        _ = ns; // autofix
        _ = buf; // autofix
        // nvim_buf_set_lines
        // nvim_buf_ns_clear (or whatever it is)
        // need to empty previous context because it is safe to now (AKA neovim wont have any references to any freed strings)
    }
};

const gpa = std.heap.GeneralPurposeAllocator(.{}){};

pub fn getNewContext() ContextError!usize {
    for (contexts, 0..) |ctx, i| {
        if (ctx == null) {
            contexts[i] = BoxContext.init(std.heap.page_allocator);
            return i;
        }
    }
    return ContextError.OutOfContexts;
}

pub fn getContext(i: usize) ContextError!*BoxContext {
    return &contexts[i] orelse ContextError.ContextNotFound;
}
//
// pub export fn initRenderCycle() i32 {
//     for (contexts, 0..) |c, i| {
//         if (c) |_| {} else {
//             contexts[i] = BoxContext.init() catch return -1;
//             return @intCast(i);
//         }
//     }
//     return -1;
// }
//
// export fn clearRender(index: u32) void {
//     if (contexts[index]) |*c| {
//         c.deinit();
//     }
//     contexts[index] = null;
// }
