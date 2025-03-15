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

// API should be like:
//
// Instance acquires a box context
// That box context should be passed down thru render chain
// Ideally we could just call box.renderOutput(buf, ns, win...) and it renders using ffi of the nvim_ functions (this would be easy to do for rendering lines)
// Current ideas:
// Box context contains all strings and highlights and boxes just request data be put into that
// This would require a box to know it's position pre-render (AKA margin and pad need to be calc'd and applied before then)
//

// Happy path is NOT overwriting (eg only position:absolute/relative/... over unicode should be sad path)
// Thus we should not worry about resizing performance

// TODO:
// - setCharAt() needs to account for multibyte chars when *overwriting*
// - need to add a clean() method (same as Box:clean())
// - add a fillArea() method (padding)
// - possible perf optimizations in indexForPos()
// - finalize the c api
const BoxContext = struct {
    // NOTE: one thing while reading the docs in here is the wording choice is somewhat selective
    // - position means the 'index' that a user sees
    //     - in x direction, the sum of the real widths (nvim_strwidth) of all the previous characters in a line
    //     - in y direction, position and index are the same
    //     - ie if a character is in x position 3, it will be presented three characters from the left, could be any index because individual characters can be multiple bytes/widths
    // - indices means the actual index of self.lines
    arena: std.heap.ArenaAllocator,
    lines: std.ArrayList(std.ArrayList(u8)),
    hls: std.ArrayList(hl.HlAttrs),
    offsetX: i32,
    offsetY: i32,
    width: u32,
    hl: hl.HlAttrs,

    // ctor/dtor
    pub fn init(alloc: std.mem.Allocator) BoxContext {
        var a = std.heap.ArenaAllocator.init(alloc);
        // zig fmt: off
        return .{ 
            .arena = a, 
            // .boxList = std.ArrayList(?Box)
            //     .init(a.allocator()), 
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

    // low level api, intended for use by the public api functions

    /// just adds a new line to the end
    fn addLine(self: *BoxContext) void {
        var newLine = std.ArrayList(u8).init(self.arena.allocator());
        newLine.appendNTimes(' ', self.width);
        self.lines.append(newLine);
        var hlLine = std.ArrayList(hl.HlAttrs).init(self.arena.allocator());
        hlLine.appendNTimes(self.hl, self.width);
        self.hls.append(hlLine);
    }

    /// To be called after a line has finished being changed, to readjust the width
    fn adjustWidthFrom(self: *BoxContext, line: *std.ArrayList(u8)) void {
        self.width = std.math.maxInt(lineWidth(&line), self.width);
    }

    /// returns the index needed for an x position on the line. note that index can be out of bounds, so you will have to readjust the array yourself or call `setCharAt`
    fn indexForPos(line: *std.ArrayList(u8), pos: usize) usize {
        // TODO: can prolly have a short-circuit of pos>width -> line.items.len + pos - width
        // NOTE: above path is prolly the most likely just because we always appending

        var cpos = 0;
        var i = 0;
        while (cpos < pos) {
            if (i >= line.items.len) {
                break;
            }
            const byteWidth = codepointLen(line.items[i]);
            var err: [*]allowzero const u8 = 0;
            const width = fns.z_nvim_strwidth(line.items[i .. i + byteWidth], &err);
            cpos += width;
            i += byteWidth;
        }
        // TODO: off by one error here? who knows
        if (cpos >= pos) {
            return i;
        }
        return i + cpos - pos;
    }

    /// Sets the char at the x and y indices, readjusts the array if necessary
    fn setCharAt(self: *BoxContext, x: usize, y: usize, char: u8, color: hl.HlAttrs) void {
        self.ensureLineExists(y);
        const sizeDiff = x + 1 - self.lines.items[y].items.len;
        // TODO: handle mutlibyte chars overwriting single byte chars or vice-versa
        self.lines.items[y].appendNTimes(' ', sizeDiff);
        self.hls.items[y].appendNTimes(self.hl, sizeDiff);
        self.lines.items[y].items[x] = char;
        self.hls.items[y].items[x] = color;
    }

    /// ensures that index y is accessible
    fn ensureLineExists(self: *BoxContext, y: usize) void {
        while (y >= self.lines.items.len) {
            self.addLine();
        }
    }

    // External api

    /// sets the default hl of the context
    pub fn setHl(self: *BoxContext, color: hl.HlAttrs) void {
        self.hl = color;
    }

    /// Renders the line over the rest of the box starting at the given x position
    pub fn renderLineOver(self: *BoxContext, startX: usize, y: usize, line: []u8, color: hl.HlAttrs) void {
        self.ensureLineExists(y);
        const startIndex = indexForPos(&self.lines.items[y], startX);
        for (line, 0..) |char, i| {
            self.setCharAt(startIndex + i, y, char, color);
        }
        self.adjustWidthFrom(&self.lines.items[y]);
    }

    /// Renders the context over the rest of the box
    pub fn renderCtxOver(self: *BoxContext, other: usize) ContextError!void {
        const otherCtx = contexts[other] orelse return ContextError.ContextNotFound;
        var j = 0;
        while (self.lines.len < otherCtx.offsetY + otherCtx.lines.len) {
            self.addLine();
        }
        while (j < otherCtx.height) {
            const startI = indexForPos(&self.lines.items[j + otherCtx.offsetY], otherCtx.offsetX);
            for (otherCtx.lines.items[j].items, otherCtx.hls.items[j].items, 0..) |char, color, i| {
                self.setCharAt(i + startI, j + otherCtx.offsetY, char, color);
            }
            self.adjustWidthFrom(&self.lines.items[j + otherCtx.offsetY]);
            j += 1;
        }
    }
};

var contexts: [1000]?BoxContext = [1]?BoxContext{null} ** 1000;

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
    const ret = &(contexts[i] orelse return ContextError.ContextNotFound);
    return ret;
}

pub fn removeContextIfExists(i: usize) void {
    const ctx = contexts[i] orelse return;
    ctx.deinit();
    contexts[i] = null;
}

export fn setCtxBool(i: usize, name: [*:0]u8, value: bool) u32 {
    var ctx = getContext(i) catch |v| return @intFromError(v);
    hl.setHlBool(&ctx.hl, std.mem.span(name), value);
    return 0;
}
