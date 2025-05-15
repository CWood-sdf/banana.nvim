const _b = @import("box.zig");
const std = @import("std");
const log = @import("log.zig");
const Box = _b.Box;
const BoxContext = _b.BoxContext;
const get_box = _b.get_box;
const get_context = _b.get_context;
const Id = _b.Id;
const NullableId = _b.NullableId;
const Highlight = _b.Highlight;
pub const PartialRendered = struct {
    // Shared data up here
    ctx: Id,
    containerBox: Id,
    box: NullableId,
    dbgCtx: NullableId,
    // TODO: Unnecessary lowkey, just grab container color
    marginColor: Highlight,
    mainColor: Highlight,

    // TODO: Merge these fields together
    // TODO: only used to detect inline behavior
    // Will be needed to determine inline bound box
    // Can just be determined by containerBox.cursorX
    startCursorX: u16,
    startCursorY: u16,
    // TODO: only used in inlineBlock, block
    margin: Pad,
    padding: Pad,
    // TODO: unnecessary for inline.
    // Also can be determined from container.maxWidth
    maxWidth: u16,
    maxHeight: u16,
    // TODO: currently used to detect inline. needed tho for width:fit-content and flex
    // Unnecessary for inline
    sideAlign: RenderAlign,
    verticalAlign: RenderAlign,

    /// Shared data struct for inline render mode
    pub const InlineData = struct {
        startCursorX: u16,
        startCursorY: u16,
    };

    /// Shared data struct for inlineBlock and block render modes
    pub const BlockData = struct {
        margin: Pad,
        padding: Pad,
        maxWidth: u16,
        maxHeight: u16,
        sideAlign: RenderAlign,
        verticalAlign: RenderAlign,
    };

    pub const RenderType = enum(u2) {
        // Won't be moved; cursored; no margin, padding, or max width
        @"inline",
        // rendered as a block, can be moved if too big
        inlineBlock,
        // rendered as a block, will not be moved
        block,
    };

    pub const RenderAlign = enum(u2) {
        left = 0,
        center = 1,
        right = 2,
        noexpand = 3,
    };
    pub const Pad = struct {
        left: u16,
        right: u16,
        top: u16,
        bottom: u16,
        pub const zero: Pad = .init(0, 0, 0, 0);
        pub fn init(l: u16, r: u16, t: u16, b: u16) Pad {
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
        pub fn side(self: *Pad) u16 {
            return self.left + self.right;
        }
        pub fn vert(self: *Pad) u16 {
            return self.top + self.bottom;
        }
    };

    pub fn init(containerBox: *Box, containerId: Id) PartialRendered {
        return .{
            .dbgCtx = .nil,
            .ctx = containerBox.context,
            .maxHeight = containerBox.maxHeight,
            .startCursorX = 0,
            .startCursorY = 0,
            .margin = .zero,
            .padding = .zero,
            .containerBox = containerId,
            .box = .nil,
            .marginColor = containerBox.hlgroup,
            .mainColor = 0,
            .sideAlign = .noexpand,
            .verticalAlign = .noexpand,
            .maxWidth = containerBox.maxWidth,
        };
    }

    pub fn setDebugContext(self: *PartialRendered, ctx: ?u16) void {
        self.dbgCtx.set(ctx);
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
    pub fn setMaxWidth(self: *PartialRendered, width: u16) void {
        self.maxWidth = width;
    }
    pub fn setMaxHeight(self: *PartialRendered, height: u16) void {
        self.maxHeight = height;
        self.verticalAlign = .left;
    }
    pub fn getContainer(self: *PartialRendered) !*Box {
        return try get_box(self.ctx, self.containerBox);
    }
    pub fn getContext(self: *PartialRendered) !*BoxContext {
        return try get_context(self.ctx);
    }
    pub fn getBox(self: *PartialRendered) !*Box {
        if (self.box.asOptional()) |id| {
            return try get_box(self.ctx, id);
        }
        return error.BoxNotExist;
    }
    pub fn createBoxTryCursored(self: *PartialRendered) !u16 {
        const containerBox = try self.getContainer();
        if (!self.padding.equals(.zero) or !self.margin.equals(.zero)) {
            return try self.createBox(containerBox.cursorX, 0);
        }
        const context = try self.getContext();
        var box = containerBox.newBoxCursored();
        // dont need to set maxWidth bc its inherited from containerBox
        // self.box.?.maxWidth = self.maxWidth - self.margin.left - self.padding.left - self.margin.right - self.padding.right;
        box.hlgroup = self.mainColor;
        const id = try context.newBox(box);

        self.box.set(id);

        return id;
    }
    pub fn createBox(self: *PartialRendered, offX: u16, offY: u16) !u16 {
        const containerBox = try self.getContainer();
        const noextra = self.padding.equals(.zero) and self.margin.equals(.zero);
        const noexpand =
            self.sideAlign == .noexpand and self.verticalAlign == .noexpand;
        const movable = containerBox.cursorX != 0;
        // if we have an inline el, then we need to make it cursored
        var box = if (noextra and noexpand and movable) blk: {
            self.startCursorX = containerBox.cursorX;
            self.startCursorY = containerBox.cursorY;
            const box = containerBox.newBoxCursored();
            break :blk box;
        } else containerBox.newBoxFromOffset(
            self.margin.left + self.padding.left + offX,
            self.margin.top + self.padding.top + containerBox.cursorY + offY,
        );
        var buffer = [_]u8{0} ** 300;
        const dbg: ?*BoxContext = if (self.dbgCtx.asOptional()) |id|
            try get_context(id)
        else
            null;
        if (dbg) |d| {
            d.dumpComment(
                try std.fmt.bufPrint(
                    &buffer,
                    "created box with offs: ({}, {})",
                    .{ box.offsetX, box.offsetY },
                ),
            ) catch {};
        }
        box.maxWidth = self.maxWidth;
        box.hlgroup = self.mainColor;

        const context = try self.getContext();

        const id = try context.newBox(box);

        self.box.set(id);

        return id;
    }

    pub fn setAlign(self: *PartialRendered, al: RenderAlign) void {
        self.sideAlign = al;
    }

    pub fn setVerticalAlign(self: *PartialRendered, al: RenderAlign) void {
        self.verticalAlign = al;
    }

    pub fn getWidth(self: *PartialRendered) !u16 {
        const box = try self.getBox();
        const width = switch (self.sideAlign) {
            .left, .center, .right => self.maxWidth,
            .noexpand => self.padding.side() + self.margin.side() + box.width,
        };
        return width;
    }
    pub fn getHeight(self: *PartialRendered) !u16 {
        const box = try self.getBox();
        const height = switch (self.verticalAlign) {
            .left, .center, .right => self.maxHeight,
            .noexpand => self.padding.vert() + self.margin.vert() + box.height,
        };
        return height;
    }

    pub fn render(self: *PartialRendered) !void {
        const box = try self.getBox();
        const containerBox = try self.getContainer();
        const context = try self.getContext();

        if (self.startCursorX != 0) {
            containerBox.updateCursorFrom(box);
            return;
        }

        var buffer = [_]u8{0} ** 300;
        const dbg: ?*BoxContext = if (self.dbgCtx.asOptional()) |id|
            try get_context(id)
        else
            null;

        const alloc = context.alloc();
        const widthExpansion = switch (self.sideAlign) {
            .left, .center, .right => self.maxWidth - self.padding.side() - self.margin.side() - box.width,
            .noexpand => 0,
        };
        const heightExpansion = switch (self.verticalAlign) {
            .left, .center, .right => self.maxHeight - self.padding.vert() - self.margin.vert() - box.height,
            .noexpand => 0,
        };
        const mainWidth = box.width + widthExpansion;
        const mainHeight = box.height + heightExpansion;
        const offX = containerBox.offsetX;
        const offY = containerBox.offsetY;
        const height = mainHeight + self.padding.top + self.padding.bottom + self.margin.top + self.margin.bottom;
        const width = mainWidth + self.padding.left + self.padding.right + self.margin.left + self.margin.right;

        if (dbg) |d| {
            context.dumpTo(d, "Pre height expand") catch {};
            d.dumpComment(
                try std.fmt.bufPrint(&buffer, "target width: {}", .{box.width}),
            ) catch {};
        }

        // inline elements SHOULD NOT be cleaned
        if (self.sideAlign != .noexpand) {
            try box.expandHeightTo(box.height + heightExpansion);
            try box.cleanDbg(dbg);
        }

        if (width != containerBox.width) {
            containerBox.width = @max(containerBox.width, width);
            containerBox.dirty = true;
        }

        // NOTE: If changing, change the offset line in renderWithMove
        containerBox.cursorY += height;
        containerBox.height += height;
        if (dbg) |d| {
            context.dumpTo(d, "Pre side align") catch {};
            const comment = try std.fmt.bufPrint(&buffer, "side align: {s}", .{@tagName(self.sideAlign)});
            d.dumpComment(comment) catch {};
        }
        switch (self.sideAlign) {
            .center => {
                const r = @divFloor(widthExpansion, 2);
                const l = widthExpansion - r;
                const leftSide = l;
                const rightSide = r;
                try box.shiftRightwardsBy(leftSide);
                if (dbg) |d| {
                    const comment = try std.fmt.bufPrint(
                        &buffer,
                        "after right shift by {} from offset {}",
                        .{ leftSide, box.offsetX },
                    );
                    context.dumpTo(d, comment) catch {};
                }
                for (box.offsetY..box.offsetY + box.height) |i| {
                    const line = try context.getLine(@intCast(i));
                    try line.appendAsciiNTimes(context, ' ', self.mainColor, rightSide);
                }
            },
            .right => {
                try box.shiftRightwardsBy(widthExpansion);
            },
            .left => {
                for (box.offsetY..box.offsetY + box.height) |i| {
                    const line = try context.getLine(@intCast(i));
                    log.write("Width expansion yay: {}\n", .{widthExpansion}) catch {};
                    try line.appendAsciiNTimes(context, ' ', self.mainColor, widthExpansion);
                }
            },
            .noexpand => {},
        }
        // for (0..heightExpansion) |i| {
        //     const lineNr = offY + self.padding.top + self.margin.top + box.height + i;
        //     const line = try context.getLine(@intCast(lineNr));
        //     const startX = offX + self.margin.left + self.padding.left;
        //     try line.chars.ensureTotalCapacity(
        //         alloc,
        //         startX + mainWidth,
        //     );
        //     try line.hls.ensureTotalCapacity(
        //         alloc,
        //         startX + mainWidth,
        //     );
        //     @memset(line.chars.items[startX .. startX + mainWidth], .space);
        //     @memset(line.hls.items[startX .. startX + mainWidth], self.mainColor);
        // }

        if (dbg) |d| {
            context.dumpTo(d, "about to render stuff yay") catch {};
        }
        // set margin and padding
        for (0..height) |i| {
            log.write("looping {}\n", .{i}) catch {};
            if (dbg) |d| {
                const reason = try std.fmt.bufPrint(&buffer, "rendering line index {}", .{i});
                context.dumpTo(d, reason) catch {};
            }
            const line = try context.getLine(offY + @as(u16, @intCast(i)));
            if (i < self.margin.top or i >= height - self.margin.bottom) {
                // all margin
                try line.ensureTotalCapacity(alloc, offX + width);
                const currentStrLen = line.width();
                if (currentStrLen < offX + width) {
                    try line.appendAsciiNTimes(
                        context,
                        ' ',
                        self.marginColor,
                        offX + width - currentStrLen,
                    );
                }
                if (currentStrLen > offX) {
                    @memset(line._chars.items[offX..currentStrLen], .space);
                }
                if (currentStrLen > offX) {
                    @memset(line._hls.items[offX .. offX + width], self.marginColor);
                }
            } else if (i < self.margin.top + self.padding.top or i >= height - self.margin.bottom - self.padding.bottom) {
                // margin l r, middle padding
                const currentStrLen = line.width();
                if (currentStrLen < offX + width) {
                    try line.appendAsciiNTimes(
                        context,
                        ' ',
                        self.marginColor,
                        offX + width - currentStrLen,
                    );
                }

                if (currentStrLen > offX) {
                    @memset(line._chars.items[offX..currentStrLen], .space);
                }

                @memset(line._hls.items[offX .. offX + self.margin.left], self.marginColor);
                @memset(
                    line._hls.items[offX + self.margin.left .. offX + width - self.margin.right],
                    self.mainColor,
                );
                @memset(
                    line._hls.items[offX + width - self.margin.right .. offX + width],
                    self.marginColor,
                );
            } else {
                // margin + pad l r, middle content{
                const currentStrLen = line.width();
                log.write("Widths: {}, {}\n", .{ line._chars.items.len, line._hls.items.len }) catch {};
                if (currentStrLen < offX + width) {
                    try line.appendAsciiNTimes(
                        context,
                        ' ',
                        self.marginColor,
                        offX + width - currentStrLen,
                    );
                }

                const spaceArea = self.margin.left + self.padding.left;
                @memset(line._chars.items[offX .. offX + spaceArea], .space);
                const spaceCont = spaceArea + mainWidth;
                @memset(line._chars.items[offX + spaceCont .. offX + width], .space);
                log.write("append to len {}\n", .{offX + width}) catch {};
                log.write("memsetting {} .. {}\n", .{ offX, offX + self.margin.left }) catch {};
                @memset(line._hls.items[offX .. offX + self.margin.left], self.marginColor);
                log.write("memsetting {} .. {}\n", .{ offX + self.margin.left, offX + self.margin.left + self.padding.left }) catch {};
                @memset(
                    line._hls.items[offX + self.margin.left .. offX + self.margin.left + self.padding.left],
                    self.mainColor,
                );
                log.write("memsetting {} .. {}\n", .{ offX + self.margin.left + self.padding.left + mainWidth, offX + width - self.margin.right }) catch {};
                @memset(
                    line._hls.items[offX + self.margin.left + self.padding.left + mainWidth .. offX + width - self.margin.right],
                    self.mainColor,
                );
                log.write("memsetting {} .. {}\n", .{ offX + width - self.margin.right, offX + width }) catch {};
                @memset(
                    line._hls.items[offX + width - self.margin.right .. offX + width],
                    self.marginColor,
                );
            }
        }
    }
    pub fn renderCursoredOverflow(self: *PartialRendered, lineHeight: u16) !bool {
        if (self.startCursorX != 0) {
            try self.render();
            return false;
        }
        const containerBox = try self.getContainer();
        const maxWidth = containerBox.maxWidth - containerBox.cursorX;
        return try self.renderWithMove(maxWidth, 0, containerBox.cursorY + lineHeight);
    }
    pub fn renderWithMove(self: *PartialRendered, maxWidth: u16, toX: u16, toY: u16) !bool {
        _ = maxWidth; // autofix
        _ = toX; // autofix
        _ = toY; // autofix
        try self.render();
        return false;
        // if (self.padding.equals(.zero) and self.margin.equals(.zero)) {
        //     return false;
        // }
        // const box = try self.getBox();
        // const context = try self.getContext();
        // const containerBox = try self.getContainer();
        // const alloc = context.alloc();
        // const widthExpansion = switch (self.sideAlign) {
        //     .left, .center, .right => self.maxWidth - self.padding.side() - self.margin.side() - box.width,
        //     .noexpand => 0,
        // };
        // const heightExpansion = switch (self.verticalAlign) {
        //     .left, .center, .right => self.maxHeight - self.padding.vert() - self.margin.vert() - box.height,
        //     .noexpand => 0,
        // };
        // const mainWidth = box.width + widthExpansion;
        // const width = mainWidth + self.padding.left + self.padding.right + self.margin.left + self.margin.right;
        // const height = box.height + heightExpansion + self.padding.top + self.padding.bottom + self.margin.top + self.margin.bottom;
        // // yo we gucci
        // if (width <= maxWidth) {
        //     // dont need to save the width before render() bc if
        //     // - A: the width doesnt increase, that means width is currently bigger
        //     // than box size, so we just need to recompute if its bigger than boxSize AND cursor
        //     // - B: The width already increased from width, now it will increase
        //     // even more with cursor + width
        //     containerBox.width = @max(
        //         containerBox.width,
        //         containerBox.cursorX + width,
        //     );
        //     containerBox.cursorX += width;
        //     // NOTE: to offset the increase at the end of render()
        //     containerBox.cursorY -= height;
        //     return false;
        // }
        // containerBox.cursorX = 0;
        // const offX = containerBox.offsetX;
        // const offY = containerBox.offsetY;
        // for (0..height) |i| {
        //     const line = try context.getLine(offY + @as(u16, @intCast(i)));
        //     const count = @min(line.width() - offX, width);
        //     const slice = line._chars.items[offX .. offX + count];
        //     const otherLine = try context.getLine(toY + @as(u16, @intCast(i)));
        //
        //     if (otherLine._chars.items.len < toX + count) {
        //         try otherLine.appendAsciiNTimes(
        //             context,
        //             ' ',
        //             self.marginColor,
        //             toX + count - @as(u16, @intCast(otherLine._chars.items.len)),
        //         );
        //     }
        //     try otherLine._chars.replaceRange(alloc, toX, count, slice);
        //     try otherLine._hls.replaceRange(
        //         alloc,
        //         toX,
        //         count,
        //         line._hls.items[offX .. offX + count],
        //     );
        //     @memset(line._chars.items[offX .. offX + count], .space);
        //     @memset(line._hls.items[offX .. offX + count], self.marginColor);
        // }
        // return true;
    }
};
