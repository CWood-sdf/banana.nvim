// TODO: Box.destroy()
const std = @import("std");
const lua = @import("lua_api/lua.zig");

const Hl = @import("hl.zig");
const consts = @import("nvim_api/constants.zig");
const fns = @import("nvim_api/functions.zig");
const tps = @import("nvim_api/types.zig");

const Highlight = u32;

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

const Char = packed struct {
    // the actual number
    bytes: u3,
    // the width
    width: u2,
    char: u21,

    // should be placed after double width characters so that they can act like their width
    pub const dummy: Char = .{
        .bytes = 0,
        .width = 0,
        .char = 0,
    };

    pub const space: Char = .{
        .bytes = 1,
        .width = 1,
        .char = ' ',
    };

    /// writes the utf8 representation to the byte array
    /// then returns the number of bytes written
    pub fn toBytes(self: *const Char, byteArr: []u8) !u8 {
        if (self.bytes == 0) {
            return 0;
        }
        if (byteArr.len < self.bytes) {
            return error.ArrayTooSmall;
        }

        const bytes = try std.unicode.utf8Encode(self.char, byteArr);
        return bytes;
    }
    pub fn fromAscii(byte: u8) Char {
        return .{
            .bytes = 1,
            .char = byte,
            .width = 1,
        };
    }

    pub fn fromUtf8(bytes: []const u8) !Char {
        if (bytes.len == 0) {
            return error.ArrayTooSmall;
        }
        const byteSize = try std.unicode.utf8ByteSequenceLength(bytes[0]);
        if (bytes.len < byteSize) {
            return error.ArrayTooSmall;
        }
        const codepoint: u21 = try std.unicode.utf8Decode(bytes[0..byteSize]);
        const width = try fns.z_nvim_strwidth(bytes[0..byteSize]);
        if (width > 2) {
            return error.NvimStrWidthTooBig;
        }
        return .{
            .bytes = byteSize,
            .char = codepoint,
            .width = @intCast(width),
        };
    }

    pub fn isDummy(char: Char) bool {
        return char.width == 0;
    }

    pub fn sliceWidth(slice: []const Char) u32 {
        var ret: u32 = 0;
        for (slice) |char| {
            ret += char.width;
        }
        return ret;
    }
};

const Line = struct {
    chars: std.ArrayListUnmanaged(Char),
    hls: std.ArrayListUnmanaged(Highlight),
    width: u32,

    pub fn init() Line {
        return .{
            .chars = .empty,
            .hls = .empty,
            .width = 0,
        };
    }

    pub fn popLastChar(self: *Line) void {
        _ = self.chars.pop();
        _ = self.hls.pop();
        self.width -= 1;
    }
    pub fn deinit(self: *Line, alloc: std.mem.Allocator) void {
        self.chars.deinit(alloc);
        self.hls.deinit(alloc);
    }
    pub fn appendWordToLen(
        self: *Line,
        ctx: *BoxContext,
        str: []const u8,
        hl: Highlight,
        len: u32,
        addNoMatterWhat: bool,
    ) !u32 {
        var i: u32 = 0;
        if (self.width == len and !addNoMatterWhat) {
            return 0;
        }
        while (i < str.len) {
            const char = try Char.fromUtf8(str[i..]);
            if (char.width + self.width > len and !addNoMatterWhat) {
                return i;
            }
            i += char.bytes;
            try self.chars.append(ctx.alloc, char);
            self.hls.append(ctx.alloc, hl) catch |e| {
                self.chars.shrinkRetainingCapacity(self.chars.items.len - 1);
                return e;
            };
            if (char.width == 2) {
                try self.chars.append(ctx.alloc, .dummy);
                self.hls.append(ctx.alloc, hl) catch |e| {
                    self.chars.shrinkRetainingCapacity(self.chars.items.len - 1);
                    return e;
                };
            } else if (char.width > 2) {
                return error.TripleWidthCharacter;
            }
            self.width += char.width;
            if (self.width >= len) {
                return i;
            }
        }
        return i;
    }
    pub fn appendWord(self: *Line, ctx: *BoxContext, str: []const u8, hl: Highlight) !void {
        _ = try self.appendWordToLen(ctx, str, hl, str.len + self.width, true);
    }

    pub fn ensureAppendableAt(self: *Line, ctx: *BoxContext, spot: u32) !void {
        if (self.width < spot) {
            try self.chars.appendNTimes(ctx.alloc, .space, spot - self.width);
            self.hls.appendNTimes(ctx.alloc, 0, spot - self.width) catch |e| {
                self.chars.shrinkRetainingCapacity(self.width);
                return e;
            };
            self.width = spot;
        }
    }

    /// Appends an ascii char n times
    pub fn appendCharNTimes(
        self: *Line,
        ctx: *BoxContext,
        char: u8,
        hl: Highlight,
        n: u32,
    ) !void {
        try self.chars.appendNTimes(ctx.alloc, Char.fromAscii(char), n);
        self.hls.appendNTimes(ctx.alloc, hl, n) catch |e| {
            self.chars.shrinkRetainingCapacity(self.chars.items.len - n);
            return e;
        };
        self.width += n;
    }
    pub fn widthFrom(self: *Line, base: u32) u32 {
        return self.width - base;
    }
};

var contexts: std.ArrayListUnmanaged(?BoxContext) = .empty;

/// This is just supposed to be a structureless buffer for boxes to render to
pub const BoxContext = struct {
    lines: std.ArrayListUnmanaged(Line) = .empty,
    arena: std.heap.ArenaAllocator,
    alloc: std.mem.Allocator,
    boxes: std.ArrayListUnmanaged(Box) = .empty,
    partials: std.ArrayListUnmanaged(PartialRendered) = .empty,

    // ctor/dtor
    pub fn init(allocator: std.mem.Allocator) BoxContext {
        var arena = std.heap.ArenaAllocator.init(allocator);
        return .{
            .lines = .empty,
            .boxes = .empty,
            .arena = arena,
            .alloc = arena.allocator(),
            .partials = .empty,
        };
    }
    pub fn deinit(self: *BoxContext) void {
        self.arena.deinit();
        // for (self.lines.items) |*line| {
        //     line.deinit(self.alloc);
        // }
        // self.lines.deinit(self.alloc);
        // self.boxes.deinit(self.alloc);
        // self.partials.deinit(self.alloc);
    }
    pub fn newBox(self: *BoxContext, box: Box) !u32 {
        try self.boxes.append(self.alloc, box);
        return @intCast(self.boxes.items.len - 1);
    }
    pub fn getBox(self: *const BoxContext, box: u32) ?*Box {
        if (box >= self.boxes.items.len) {
            return null;
        }
        return &self.boxes.items[box];
    }
    pub fn newPartial(self: *BoxContext, partial: PartialRendered) !u32 {
        try self.partials.append(self.alloc, partial);
        return @intCast(self.partials.items.len - 1);
    }
    pub fn getPartial(self: *const BoxContext, ptl: u32) ?*PartialRendered {
        if (ptl >= self.partials.items.len) {
            return null;
        }
        return &self.partials.items[ptl];
    }
    pub fn stripRightSpace(self: *BoxContext, expectedBg: Highlight) !void {
        _ = self; // autofix
        _ = expectedBg; // autofix
    }

    pub fn getLine(self: *BoxContext, line: u32) !*Line {
        while (self.lines.items.len <= line) {
            try self.lines.append(self.alloc, Line.init());
        }
        return &self.lines.items[line];
    }
    pub fn render(self: *BoxContext, buf: tps.Integer) !void {
        var err = tps.Error{ .type = .None, .msg = @ptrFromInt(0) };
        var arena: tps.Arena = .{
            .current_block = "",
            .size = 0,
            .pos = 0,
        };
        const arr = try self.alloc.alloc(tps.Object, self.lines.items.len);
        defer self.alloc.free(arr);

        var lines: std.ArrayListUnmanaged(std.ArrayListUnmanaged(u8)) = .empty;
        defer {
            for (lines.items) |*line| {
                line.deinit(self.alloc);
            }
            lines.deinit(self.alloc);
        }
        for (self.lines.items) |*line| {
            try lines.append(self.alloc, .empty);
            for (line.chars.items) |char| {
                var chars = [_]u8{0} ** 4;
                const bytes = try char.toBytes(&chars);
                if (bytes != 0) {
                    try lines.items[lines.items.len - 1].appendSlice(
                        self.alloc,
                        chars[0..bytes],
                    );
                }
            }
        }

        for (lines.items, 0..) |line, i| {
            arr[i] = tps.stringObject(line.items);
        }
        const replacement: tps.Array = .{
            .size = self.lines.items.len,
            .items = arr.ptr,
            .capacity = self.lines.items.len,
        };
        fns.nvim_buf_set_lines(
            consts.LUA_INTERNAL_CALL,
            @enumFromInt(buf),
            0,
            -1,
            false,
            replacement,
            &arena,
            &err,
        );

        if (err.type != .None) {
            switch (err.type) {
                .Exception => return tps.NvimError.Exception,
                .Validation => return tps.NvimError.Validation,
                else => {},
            }
        }
    }
    pub fn highlight(self: *BoxContext, L: *lua.State, pos: c_int) void {
        // if (!lua.is_function(L, 1)) {
        //     return error.NotAFunction;
        // }
        for (self.lines.items, 0..) |line, row| {
            if (line.hls.items.len == 0) {
                continue;
            }
            var startCol: u32 = 0;
            var currentHl: Highlight = line.hls.items[0];
            var byte: u32 = 0;
            for (line.hls.items, 0..) |hl, col| {
                if (currentHl != hl) {
                    if (currentHl != 0) {
                        lua.push_value(L, pos);
                        lua.push_int(L, @intCast(row));
                        lua.push_int(L, @intCast(startCol));
                        lua.push_int(L, @intCast(byte));
                        lua.push_int(L, @intCast(currentHl));
                        lua.call(L, 4, 0);
                    }
                    currentHl = hl;
                    startCol = byte;
                }
                byte += line.chars.items[col].bytes;
            }
            if (startCol != byte) {
                lua.push_value(L, pos);
                lua.push_int(L, @intCast(row));
                lua.push_int(L, @intCast(startCol));
                lua.push_int(L, @intCast(byte));
                lua.push_int(L, @intCast(currentHl));
                lua.call(L, 4, 0);
            }
        }
    }
};

pub const Box = struct {
    context: *BoxContext,
    offsetX: u32,
    offsetY: u32,
    width: u32,
    maxWidth: u32,
    height: u32,
    dirty: bool,
    hlgroup: Highlight,
    cursorX: u32,
    cursorY: u32,
    // TODO: Need to work on this
    // pub fn insertGradientMarker(){}
    // pub fn setGradientSize(){}

    // TODO: Internal behavior
    // pub fn fillString(width){}

    pub fn newBoxFromContext(ctx: *BoxContext, hlgroup: Highlight) Box {
        // @compileLog(std.fmt.comptimePrint("{}\n", .{@sizeOf(Highlight)}));
        return .{
            .height = 0,
            .context = ctx,
            .offsetX = 0,
            .offsetY = 0,
            .width = 0,
            .maxWidth = std.math.maxInt(@FieldType(Box, "width")),
            .dirty = false,
            .hlgroup = hlgroup,
            .cursorX = 0,
            .cursorY = 0,
        };
    }
    pub fn newBoxFromOffset(self: *Box, x: u32, y: u32) Box {
        return .{
            .height = 0,
            .context = self.context,
            .offsetX = self.offsetX + x,
            .offsetY = self.offsetY + y,
            .width = 0,
            .maxWidth = std.math.maxInt(@FieldType(Box, "width")),
            .dirty = false,
            .hlgroup = self.hlgroup,
            .cursorX = 0,
            .cursorY = 0,
        };
    }

    pub fn newBoxCursored(self: *Box) Box {
        return .{
            .height = 0,
            .context = self.context,
            .offsetX = self.offsetX,
            .offsetY = self.offsetY,
            .cursorX = self.cursorX,
            .cursorY = self.cursorY,
            .width = 0,
            .maxWidth = std.math.maxInt(@FieldType(Box, "width")),
            .dirty = false,
            .hlgroup = self.hlgroup,
        };
    }

    pub fn newBoxRightOf(self: *Box) Box {
        return .{
            .height = 0,
            .context = self.context,
            .offsetX = self.offsetX + self.width,
            .offsetY = self.offsetY,
            .width = 0,
            .maxWidth = std.math.maxInt(@FieldType(Box, "width")),
            .dirty = false,
            .hlgroup = self.hlgroup,
            .cursorX = 0,
            .cursorY = 0,
        };
    }

    // prettry sure this is only used for canvas
    pub fn shrinkWidthTo(self: *Box, width: u32) !void {
        for (self.offsetY..self.offsetY + self.height) |i| {
            const line: *Line = &self.context.lines.items[i];
            while (line.width > width) {
                line.popLastChar();
            }
        }
    }
    pub fn setWidth(self: *Box, width: u32) !void {
        if (self.width == width) {
            return;
        }
        if (self.width < width) {
            try self.expandWidthTo(width);
        } else {
            try self.shrinkWidthTo(width);
        }
    }
    pub fn expandWidthTo(self: *Box, width: u32) !void {
        if (width < self.width) {
            return error.HeightTooSmall;
        }
        if (width == self.width) return;
        self.width = width;
        self.dirty = true;
        try self.clean();
    }
    // TODO: Used for debugging ONLY
    pub fn clone(self: *Box) BoxContext {
        _ = self; // autofix
    }

    pub fn setHl(self: *Box, hl: Highlight) void {
        self.hlgroup = hl;
    }

    pub fn shiftRightwardsBy(self: *Box, extra: u32) !void {
        for (self.context.lines.items[self.offsetY .. self.offsetY + self.height]) |*line| {
            try line.chars.ensureTotalCapacity(
                self.context.alloc,
                extra + line.chars.items.len,
            );
            try line.hls.ensureTotalCapacity(
                self.context.alloc,
                extra + line.hls.items.len,
            );
            for (0..extra) |_| {
                line.chars.insertAssumeCapacity(self.offsetX, .space);
                line.hls.insertAssumeCapacity(self.offsetX, self.hlgroup);
            }
        }
    }
    pub fn expandHeightTo(self: *Box, height: u32) !void {
        if (height < self.height) {
            return error.HeightTooSmall;
        }
        for (0..self.height - height) |_| {
            try self.context.lines.append(self.context.alloc, Line.init());
            try self.context.lines.items[self.context.lines.items.len - 1].appendCharNTimes(
                self.context,
                ' ',
                self.hlgroup,
                self.width,
            );
        }
    }
    pub fn shrinkHeightTo(self: *Box, height: u32) !void {
        if (height > self.height) {
            return error.HeightTooBig;
        }
        for (0..(self.height - height)) |_| {
            self.context.lines.items[self.context.lines.items.len - 1].deinit(self.context.alloc);
            _ = self.context.lines.pop();
        }
    }
    pub fn setHeight(self: *Box, height: u32) !void {
        if (self.height == height) {
            return;
        }
        if (self.height < height) {
            try self.expandHeightTo(height);
        } else {
            try self.shrinkHeightTo(height);
        }
    }

    pub fn clean(self: *Box) !void {
        if (!self.dirty) {
            return;
        }
        for (self.context.lines.items[self.offsetY .. self.offsetY + self.height]) |*line| {
            if (line.widthFrom(self.offsetX) > self.width) {
                return error.LineTooBig;
            }
            if (line.widthFrom(self.offsetX) < self.width) {
                try line.appendCharNTimes(self.context, ' ', self.hlgroup, self.width - line.widthFrom(self.offsetX));
            }
        }
        self.dirty = false;
    }

    // TODO: Should be removable with offsets. BoxContext should have appendLeft for flex display (could prolly even get away with just renderOver)
    // pub fn append(box, strat){}

    // *kinda* one of the most needed low level apis
    pub fn appendStr(self: *Box, str: []const u8) !void {
        var isFirst: bool = true;
        var newStr = str;
        if (self.height == 0) {
            self.height = 1;
        }
        while (newStr.len != 0) {
            const maxWidth = self.maxWidth - self.cursorX;
            const line = try self.context.getLine(self.cursorY + self.offsetY);

            if (self.cursorX == 0) {
                try line.ensureAppendableAt(self.context, self.offsetX);
            }
            const startWidth = line.width;

            const index = try line.appendWordToLen(
                self.context,
                str,
                self.hlgroup,
                maxWidth,
                self.cursorX == 0,
            );
            self.cursorX += line.width - startWidth;
            if (self.cursorX >= self.maxWidth) {
                self.cursorX = 0;
                self.height += 1;
                self.cursorY += 1;
            }
            self.width = @max(self.width, self.cursorX);
            if (index >= newStr.len) {
                break;
            }
            newStr = newStr[index..];
            isFirst = false;
        }
    }

    pub fn updateCursorFrom(self: *Box, other: *Box) void {
        self.cursorX = other.cursorX;
        self.cursorY = other.cursorY;
    }
    // pub fn appendStr(self: *Box, str: [*]const u8, len: u32) bool {
    //     self.appendStr_internal(str[0..len]) catch return false;
    //     return true;
    // }
    pub fn appendWord(self: *Box, str: []const u8, style: Highlight) !void {
        const currentHl = self.hlgroup;
        self.hlgroup = style;
        defer self.hlgroup = currentHl;
        try self.appendStr(str);
    }
    // TODO: Remove in favor of managed splitting
    // pub fn getLine(i){}

    // TODO: Remove in favor of offsets
    // pub fn appendBoxBelow(box, expand){}

    // TODO: Unused
    // pub fn trimWidthLastLine(width, trimStrat){}

    // NOTE: Rendering over should *only* happen from prepared box contexts
    pub fn renderOver(self: *Box, other: *BoxContext, left: u32, top: u32) !void {
        if (self.context == other) {
            return error.SameContext;
        }
        _ = left; // autofix
        _ = top; // autofix
    }
};

pub const PartialRendered = struct {
    margin: Pad,
    padding: Pad,
    widthExpansion: u32,
    heightExpansion: u32,
    containerBox: *Box,
    box: ?*Box,
    marginColor: Highlight,
    mainColor: Highlight,
    renderAlign: RenderAlign,
    maxWidth: u32,
    pub const RenderAlign = enum(u8) {
        left = 0,
        center = 1,
        right = 2,
    };
    pub const Pad = struct {
        left: u32,
        right: u32,
        top: u32,
        bottom: u32,
        pub const zero: Pad = .init(0, 0, 0, 0);
        pub fn init(l: u32, r: u32, t: u32, b: u32) Pad {
            return .{
                .left = l,
                .right = r,
                .top = t,
                .bottom = b,
            };
        }
        pub fn equals(left: Pad, right: Pad) bool {
            return left.left == right.right and left.right == right.right and left.top == right.top and left.bottom == right.bottom;
        }
    };

    pub fn init(containerBox: *Box) PartialRendered {
        return .{
            .margin = .zero,
            .padding = .zero,
            .widthExpansion = 0,
            .heightExpansion = 0,
            .containerBox = containerBox,
            .box = null,
            .marginColor = containerBox.hlgroup,
            .mainColor = 0,
            .renderAlign = .left,
            .maxWidth = containerBox.maxWidth,
        };
    }

    pub fn setMargin(self: *PartialRendered, margin: Pad) void {
        self.margin = margin;
    }
    pub fn setPadding(self: *PartialRendered, padding: Pad) void {
        self.padding = padding;
    }
    pub fn setMainColor(self: *PartialRendered, main: Highlight) void {
        self.mainColor = main;
    }
    pub fn setMaxWidth(self: *PartialRendered, width: u32) void {
        self.maxWidth = width;
    }
    pub fn createBoxTryCursored(self: *PartialRendered) !u32 {
        if (!self.padding.equals(.zero) or !self.margin.equals(.zero)) {
            return try self.createBox(self.containerBox.cursorX, 0);
        }
        const box = self.containerBox.newBoxCursored();
        const id = try self.containerBox.context.newBox(box);

        self.box = self.containerBox.context.getBox(id);
        if (self.box == null) {
            return error.CantCreateBox;
        }
        // dont need to set maxWidth bc its inherited from containerBox
        // self.box.?.maxWidth = self.maxWidth - self.margin.left - self.padding.left - self.margin.right - self.padding.right;
        self.box.?.hlgroup = self.mainColor;
        return id;
    }
    pub fn createBox(self: *PartialRendered, offX: u32, offY: u32) !u32 {
        const box = self.containerBox.newBoxFromOffset(
            self.margin.left + self.padding.left + offX,
            self.margin.top + self.padding.top + self.containerBox.cursorY + offY,
        );
        const id = try self.containerBox.context.newBox(box);

        self.box = self.containerBox.context.getBox(id);
        if (self.box == null) {
            return error.CantCreateBox;
        }
        self.box.?.maxWidth = self.maxWidth - self.margin.left - self.padding.left - self.margin.right - self.padding.right;
        self.box.?.hlgroup = self.mainColor;
        return id;
    }
    pub fn setAlign(self: *PartialRendered, al: RenderAlign) void {
        self.renderAlign = al;
    }
    pub fn render(self: *PartialRendered) !void {
        const box = self.box orelse return error.BoxNotExist;
        const alloc = box.context.alloc;
        const mainWidth = box.width + self.widthExpansion;
        const mainHeight = box.height + self.heightExpansion;
        const offX = self.containerBox.offsetX;
        const offY = self.containerBox.offsetY;
        const height = mainHeight + self.padding.top + self.padding.bottom + self.margin.top + self.margin.bottom;
        const width = mainWidth + self.padding.left + self.padding.right + self.margin.left + self.margin.right;

        self.containerBox.width = @max(self.containerBox.width, width);
        // NOTE: If changing, change the offset line in renderWithMove
        self.containerBox.cursorY += height;
        switch (self.renderAlign) {
            .center => {
                const leftSide = @divFloor(self.widthExpansion, 2);
                try box.shiftRightwardsBy(leftSide);
                const rightSide = self.widthExpansion - leftSide;
                for (box.offsetY..box.offsetY + box.height) |i| {
                    const line = try box.context.getLine(@intCast(i));
                    try line.chars.appendNTimes(alloc, .space, rightSide);
                    try line.hls.appendNTimes(alloc, self.mainColor, rightSide);
                }
            },
            .right => {
                try box.shiftRightwardsBy(self.widthExpansion);
            },
            .left => {
                for (box.offsetY..box.offsetY + box.height) |i| {
                    const line = try box.context.getLine(@intCast(i));
                    try line.chars.appendNTimes(alloc, .space, self.widthExpansion);
                    try line.hls.appendNTimes(
                        alloc,
                        self.mainColor,
                        self.widthExpansion,
                    );
                }
            },
        }
        for (0..self.heightExpansion) |i| {
            const lineNr = offY + self.padding.top + self.margin.top + box.height + i;
            const line = try box.context.getLine(@intCast(lineNr));
            const startX = offX + self.margin.left + self.padding.left;
            try line.chars.ensureTotalCapacity(
                alloc,
                startX + mainWidth,
            );
            try line.hls.ensureTotalCapacity(
                alloc,
                startX + mainWidth,
            );
            @memset(line.chars.items[startX .. startX + mainWidth], .space);
            @memset(line.hls.items[startX .. startX + mainWidth], self.mainColor);
        }

        // set margin and padding
        for (0..height) |i| {
            const line = try box.context.getLine(offY + @as(u32, @intCast(i)));
            if (i < self.margin.top or i >= height - self.margin.bottom) {
                // all margin
                try line.chars.ensureTotalCapacity(alloc, offX + width);
                const currentStrLen = line.chars.items.len;
                if (currentStrLen < offX + width) {
                    line.chars.appendNTimesAssumeCapacity(.space, offX + width - currentStrLen);
                }
                if (currentStrLen > offX) {
                    @memset(line.chars.items[offX..currentStrLen], .space);
                }
                try line.hls.ensureTotalCapacity(alloc, offX + width);
                if (currentStrLen < offX + width) {
                    line.hls.appendNTimesAssumeCapacity(self.marginColor, offX + width - currentStrLen);
                }
                if (currentStrLen > offX) {
                    @memset(line.hls.items[offX .. offX + width], self.marginColor);
                }
            } else if (i < self.margin.top + self.padding.top or i >= height - self.margin.bottom - self.padding.bottom) {
                // margin l r, middle padding
                try line.chars.ensureTotalCapacity(alloc, offX + width);
                const currentStrLen = line.chars.items.len;
                if (currentStrLen < offX + width) {
                    line.chars.appendNTimesAssumeCapacity(.space, offX + width - currentStrLen);
                }
                if (currentStrLen > offX) {
                    @memset(line.chars.items[offX..currentStrLen], .space);
                }
                try line.hls.ensureTotalCapacity(alloc, offX + width);
                // just set any unused area to margin color, it will be changed later
                // do this bc i REALLY dont want to do complicated logic
                if (currentStrLen < offX + width) {
                    line.hls.appendNTimesAssumeCapacity(self.marginColor, offX + width - currentStrLen);
                }

                @memset(line.hls.items[offX .. offX + self.margin.left], self.marginColor);
                @memset(
                    line.hls.items[offX + self.margin.left .. offX + width - self.margin.right],
                    self.mainColor,
                );
                @memset(
                    line.hls.items[offX + width - self.margin.right .. offX + width],
                    self.marginColor,
                );
            } else {
                // margin + pad l r, middle content{
                const currentStrLen = line.chars.items.len;
                try line.chars.ensureTotalCapacity(alloc, offX + width);
                if (currentStrLen < offX + width) {
                    line.chars.appendNTimesAssumeCapacity(.space, offX + width - currentStrLen);
                }

                const spaceArea = self.margin.left + self.padding.left;
                @memset(line.chars.items[offX .. offX + spaceArea], .space);
                const spaceCont = spaceArea + mainWidth;
                @memset(line.chars.items[offX + spaceCont .. offX + width], .space);
                try line.hls.ensureTotalCapacity(alloc, offX + width);
                if (currentStrLen < offX + width) {
                    line.hls.appendNTimesAssumeCapacity(self.marginColor, offX + width - currentStrLen);
                }
                @memset(line.hls.items[offX .. offX + self.margin.left], self.marginColor);
                @memset(
                    line.hls.items[offX + self.margin.left .. offX + self.margin.left + self.padding.left],
                    self.mainColor,
                );
                @memset(
                    line.hls.items[offX + self.margin.left + self.padding.left + mainWidth .. offX + width - self.margin.right],
                    self.mainColor,
                );
                @memset(
                    line.hls.items[offX + width - self.margin.right .. offX + width],
                    self.marginColor,
                );
            }
        }
    }
    pub fn renderWithMove(self: *PartialRendered, maxWidth: u32, toX: u32, toY: u32) !bool {
        try self.render();
        const box = self.box orelse return error.BoxNotExist;
        const alloc = box.context.alloc;
        const mainWidth = box.width + self.widthExpansion;
        const width = mainWidth + self.padding.left + self.padding.right + self.margin.left + self.margin.right;
        const height = box.height + self.heightExpansion + self.padding.top + self.padding.bottom + self.margin.top + self.margin.bottom;
        // yo we gucci
        if (width <= maxWidth) {
            // dont need to save the width before render() bc if
            // - A: the width doesnt increase, that means width is currently bigger
            // than box size, so we just need to recompute if its bigger than boxSize AND cursor
            // - B: The width already increased from width, now it will increase
            // even more with cursor + width
            self.containerBox.width = @max(
                self.containerBox.width,
                self.containerBox.cursorX + width,
            );
            self.containerBox.cursorX += width;
            // NOTE: to offset the increase at the end of render()
            self.containerBox.cursorY -= height;
            return false;
        }
        self.containerBox.cursorX = 0;
        const offX = self.containerBox.offsetX;
        const offY = self.containerBox.offsetY;
        for (0..height) |i| {
            const line = try box.context.getLine(offY + @as(u32, @intCast(i)));
            const count = @min(line.chars.items.len - offX, width);
            const slice = line.chars.items[offX .. offX + count];
            const otherLine = try box.context.getLine(toY + @as(u32, @intCast(i)));

            if (otherLine.chars.items.len < toX + count) {
                try otherLine.chars.appendNTimes(box.context.alloc, .space, toX + count - otherLine.chars.items.len);
                try otherLine.hls.appendNTimes(box.context.alloc, self.marginColor, toX + count - otherLine.hls.items.len);
            }
            try otherLine.chars.replaceRange(alloc, toX, count, slice);
            try otherLine.hls.replaceRange(
                alloc,
                toX,
                count,
                line.hls.items[offX .. offX + count],
            );
            @memset(line.chars.items[offX .. offX + count], .space);
            @memset(line.hls.items[offX .. offX + count], self.marginColor);
        }
        return true;
    }
};

pub fn get_context(ctx: u32) !*BoxContext {
    if (ctx >= contexts.items.len) {
        return error.NotFound;
    }
    if (contexts.items[ctx]) |*c| return c;
    return error.NotFound;
}

pub fn get_box(ctx: u32, box: u32) !*Box {
    const context = try get_context(ctx);
    return context.getBox(box) orelse return error.NotFound;
}
pub fn get_partial(ctx: u32, partial: u32) !*PartialRendered {
    const context = try get_context(ctx);
    return context.getPartial(partial) orelse return error.NotFound;
}

// new context {
/// Returns -1 on failure
/// @return i32 the id of a new box context
pub fn box_context_create() !u32 {
    for (contexts.items, 0..) |item, i| {
        if (item) |_| continue;
        contexts.items[i] = BoxContext.init(std.heap.page_allocator);
        return @intCast(i);
    }
    try contexts.append(std.heap.page_allocator, null);
    const i = contexts.items.len - 1;
    contexts.items[i] = BoxContext.init(std.heap.page_allocator);
    return @intCast(i);
}

// }

// delete context {
/// In all cases, if ctx is valid it will be deleted
/// @param ctx u32 A box context id
/// @return bool whether the context existed or not
pub fn box_context_delete(ctx: u32) bool {
    if (ctx >= contexts.items.len) {
        return false;
    }
    if (contexts.items[ctx]) |*context| {
        context.deinit();
    }
    contexts.items[ctx] = null;
    return true;
}

// }

// context exists {
/// @retrun ctx u32 a box context id
/// @return bool whether the context exists or not
pub fn box_context_exists(ctx: u32) bool {
    if (ctx >= contexts.items.len) {
        return false;
    }
    return contexts.items[ctx] != null;
}
// }

// partial rendereds {
pub fn box_pr_new(ctx: u32, boxid: u32) !u32 {
    const context = try get_context(ctx);
    const box = try get_box(ctx, boxid);
    const partial = PartialRendered.init(box);
    return try context.newPartial(partial);
}
pub fn box_pr_set_margin(ctx: u32, partialid: u32, left: u32, right: u32, top: u32, bottom: u32) !void {
    const partial = try get_partial(ctx, partialid);
    partial.setMargin(.init(left, right, top, bottom));
}
pub fn box_pr_set_pad(ctx: u32, partialid: u32, left: u32, right: u32, top: u32, bottom: u32) !void {
    const partial = try get_partial(ctx, partialid);
    partial.setPadding(.init(left, right, top, bottom));
}
pub fn box_pr_set_main_hl(ctx: u32, partialid: u32, hl: Highlight) !void {
    const partial = try get_partial(ctx, partialid);
    partial.setMainColor(hl);
}
pub fn box_pr_set_max_width(ctx: u32, partialid: u32, width: u32) !void {
    const partial = try get_partial(ctx, partialid);
    partial.setMaxWidth(width);
}
pub fn box_pr_cursored_box(ctx: u32, partialid: u32) !u32 {
    const partial = try get_partial(ctx, partialid);
    return try partial.createBoxTryCursored();
}
pub fn box_pr_box(ctx: u32, partialid: u32) !u32 {
    const partial = try get_partial(ctx, partialid);
    return try partial.createBox(0, 0);
}
pub fn box_pr_set_align(ctx: u32, partialid: u32, al: u32) !void {
    const partial = try get_partial(ctx, partialid);
    partial.setAlign(@enumFromInt(al));
}
pub fn box_pr_render(ctx: u32, partialid: u32) !void {
    const partial = try get_partial(ctx, partialid);
    try partial.render();
}
pub fn box_pr_render_with_move(ctx: u32, partialid: u32, maxWidth: u32, toX: u32, toY: u32) !bool {
    const partial = try get_partial(ctx, partialid);
    return try partial.renderWithMove(maxWidth, toX, toY);
}
// }

// context render {
///
pub fn box_context_render(ctx: u32, buf: u32) !bool {
    const context = try get_context(ctx);
    try context.render(buf);
    return true;
}

/// Here so that functions can get lua functions/tables and document
/// what they want from the type
pub fn Expect(tp: type) type {
    return struct {
        L: *lua.State,
        pub const isLua = true;
        pub const T = tp;
    };
}

const HlExpect = Expect(fn (line: i32, startCol: i32, endCol: i32, hl: i32) void);
pub fn box_context_highlight(ctx: u32, L: HlExpect) !void {
    const context = try get_context(ctx);
    context.highlight(L.L, 2);
}

pub fn box_shift_right_by(ctx: u32, boxid: u32, extra: u32) !void {
    const box = try get_box(ctx, boxid);
    try box.shiftRightwardsBy(extra);
}

// new box from ctx {
pub fn box_new_from_context(ctx: u32, hlgroup: Highlight) !u32 {
    const context = try get_context(ctx);
    const ret = try context.newBox(Box.newBoxFromContext(context, hlgroup));
    return @intCast(ret);
}
// }

// new box from offset {
pub fn box_new_from_offset(ctx: u32, box: u32, x: u32, y: u32) !u32 {
    const self = try get_box(ctx, box);
    const ret = try self.context.newBox(self.newBoxFromOffset(x, y));
    return @intCast(ret);
}
// }

// new box right {
pub fn box_new_right_from(ctx: u32, box: u32) !u32 {
    const self = try get_box(ctx, box);
    const ret = try self.context.newBox(self.newBoxRightOf());
    return @intCast(ret);
}

pub fn box_new_cursored(ctx: u32, box: u32) !u32 {
    const self = try get_box(ctx, box);
    const ret = try self.context.newBox(self.newBoxCursored());
    return @intCast(ret);
}
// }

// prettry sure this is only used for canvas
pub fn box_shrink_width_to(ctx: u32, box: u32, width: u32) !void {
    const self = try get_box(ctx, box);
    try self.shrinkWidthTo(width);
}

pub fn box_update_cursor_from(ctx: u32, box: u32, other: u32) !void {
    const self = try get_box(ctx, box);
    const otherBox = try get_box(ctx, other);
    self.updateCursorFrom(otherBox);
}
pub fn box_set_width(ctx: u32, box: u32, width: u32) !void {
    const self = try get_box(ctx, box);
    try self.setWidth(width);
}

pub fn box_get_hl(ctx: u32, box: u32) !u32 {
    const self = try get_box(ctx, box);
    return self.hlgroup;
}

pub fn box_set_max_width(ctx: u32, box: u32, width: i32) !void {
    const self = try get_box(ctx, box);
    self.maxWidth = @max(width, 0);
}
pub fn box_get_width(ctx: u32, box: u32) !u32 {
    const self = try get_box(ctx, box);
    return @intCast(self.width);
}
pub fn box_expand_width_to(ctx: u32, box: u32, width: u32) !void {
    const self = try get_box(ctx, box);
    try self.expandWidthTo(width);
}

pub fn box_expand_height_to(ctx: u32, box: u32, height: u32) !void {
    const self = try get_box(ctx, box);
    try self.expandHeightTo(height);
}
pub fn box_shrink_height_to(ctx: u32, box: u32, height: u32) !void {
    const self = try get_box(ctx, box);
    try self.shrinkHeightTo(height);
}

pub fn box_set_height(ctx: u32, box: u32, height: u32) !void {
    const self = try get_box(ctx, box);
    try self.setHeight(height);
}

pub fn box_get_height(ctx: u32, box: u32) !u32 {
    const self = try get_box(ctx, box);
    return @intCast(self.height);
}

pub fn box_clean(ctx: u32, box: u32) !void {
    const self = try get_box(ctx, box);
    try self.clean();
}

// *kinda* one of the most needed low level apis
// append str {
pub fn box_append_str(ctx: u32, box: u32, str: []const u8) !void {
    const self = try get_box(ctx, box);
    try self.appendStr(str);
}
// }

// pub fn appendStr(elf: *Box, str: [*]const u8, len: u32) bool {
//     self.appendStr_internal(str[0..len]) catch return false;
//     return true;
// }

// set hl {
pub fn box_set_hl(ctx: u32, box: u32, style: u32) !void {
    const self = try get_box(ctx, box);
    self.hlgroup = style;
}
// }

pub fn box_append_word(ctx: u32, box: u32, str: []const u8, style: Highlight) !void {
    const self = try get_box(ctx, box);
    try self.appendWord(str, style);
}
// TODO: Remove in favor of managed splitting
// pb fn getLine(i){}

// TODO: Remove in fvor of offsets

// pub fn appendBoxBelow(box, expand){}

pub fn box_strip_right_space(ctx: u32, expected_bg: Highlight) !void {
    const context = try get_context(ctx);
    try context.stripRightSpace(expected_bg);
}
// TODO: Unused

// pub fn trimWidthLastLine(width, trimStrat){}

// NOTE: Rendering over should *only* happen from prepared box contexts

pub fn box_render_over(ctx: u32, box: u32, otherCtx: u32, left: u32, top: u32) !void {
    const self = try get_box(ctx, box);
    const context = try get_context(otherCtx);
    try self.renderOver(context, left, top);
}
