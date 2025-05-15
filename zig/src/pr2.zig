const _b = @import("box.zig");
const debug = @import("debug.zig").debug;
const std = @import("std");
const log = @import("log.zig");
const get_context = _b.get_context;
const get_box = _b.get_box;
const Id = _b.Id;
const NullableId = _b.NullableId;
const Highlight = _b.Highlight;
const BoxContext = _b.BoxContext;
const Box = _b.Box;
pub const PartialRendered = struct {
    tag: PartialRenderedTag,
    ctx: Id,
    containerBox: Id,
    box: NullableId,
    // TODO: remove this if not in debug
    dbgCtx: if (debug) NullableId else void,
    mainColor: Highlight,
    // TODO: Can just have a bunch of stacks and the tag determines which stack has data
    //
    pub fn deinit(self: *PartialRendered) void {
        const context: *BoxContext = get_context(self.ctx) orelse return;
        context.partialData.cleanup(self);
        _ = context.partials.pop();
    }

    pub const RenderType = enum(u2) {
        // Won't be moved; cursored; no margin, padding, or max width
        @"inline" = 0,
        // rendered as a block, can be moved if too big
        inlineBlock = 1,
        // rendered as a block, will not be moved
        block = 2,
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
        pub fn side(self: *const Pad) u16 {
            return self.left + self.right;
        }
        pub fn vert(self: *const Pad) u16 {
            return self.top + self.bottom;
        }
    };
    pub fn init(containerBox: *Box, containerId: Id) PartialRendered {
        return .{
            .tag = .{
                .tag = .@"inline",
            },
            .dbgCtx = .nil,
            .ctx = containerBox.context,
            .containerBox = containerId,
            .box = .nil,
            .mainColor = 0,
        };
    }

    // value setters {
    pub fn setRenderType(self: *PartialRendered, renderType: RenderType) void {
        self.tag.renderType = renderType;
    }

    pub fn setAlign(self: *PartialRendered, al: RenderAlign) !void {
        const context = try self.getContext();
        try self.getPartialData(context).setSideAlign(self, al);
    }

    pub fn setVerticalAlign(self: *PartialRendered, al: RenderAlign) !void {
        const context = try self.getContext();
        try self.getPartialData(context).setVerticalAlign(self, al);
    }

    pub fn setDebugContext(self: *PartialRendered, ctx: ?u16) void {
        if (debug) {
            self.dbgCtx.set(ctx);
        }
    }

    pub fn setMargin(self: *PartialRendered, margin: Pad) !void {
        if (margin.equals(.zero)) {
            return;
        }
        const context = try get_context(self.ctx);
        try context.partialData.setMargin(self, margin);
    }

    pub fn setPadding(self: *PartialRendered, padding: Pad) !void {
        if (padding.equals(.zero)) {
            return;
        }
        const context = try get_context(self.ctx);
        try context.partialData.setPadding(self, padding);
    }

    pub fn setMainColor(self: *PartialRendered, main: Highlight) !void {
        self.mainColor = main;
    }

    pub fn setMaxWidth(self: *PartialRendered, width: u16) !void {
        const context = try get_context(self.ctx);
        try context.partialData.setWidth(self, width);
    }

    pub fn setMaxHeight(self: *PartialRendered, height: u16) !void {
        const context = try get_context(self.ctx);
        try context.partialData.setHeight(self, height);
    }
    // }

    // internal box getters {
    fn getContainer(self: *PartialRendered) !*Box {
        return try get_box(self.ctx, self.containerBox);
    }
    fn getContext(self: *PartialRendered) !*BoxContext {
        return try get_context(self.ctx);
    }
    fn getPartialData(self: *PartialRendered, context: *BoxContext) *PrDataStack {
        _ = self;
        // const ctx = try self.getContext();
        return &context.partialData;
    }
    fn getBox(self: *PartialRendered) !*Box {
        if (self.box.asOptional()) |id| {
            return try get_box(self.ctx, id);
        }
        return error.BoxNotExist;
    }
    // }

    // value getters {
    pub fn getMaxWidth(
        self: *PartialRendered,
        context: *BoxContext,
        container: *Box,
    ) !u16 {
        return try self.getPartialData(context).getWidth(self) orelse container.maxWidth;
    }

    pub fn getMargin(self: *PartialRendered, context: *BoxContext) !Pad {
        return try self.getPartialData(context).getMargin(self) orelse .zero;
    }

    pub fn getSideAlign(self: *PartialRendered, context: *BoxContext) !PartialRendered.RenderAlign {
        if (self.tag.tag == .@"inline") {
            return .left;
        }
        return try self.getPartialData(context).getSideAlign(self) orelse .left;
    }

    pub fn getVerticalAlign(self: *PartialRendered, context: *BoxContext) !PartialRendered.RenderAlign {
        return try self.getPartialData(context).getVerticalAlign(self) orelse .noexpand;
    }

    pub fn getPadding(self: *PartialRendered, context: *BoxContext) !Pad {
        return try self.getPartialData(context).getPadding(self) orelse .zero;
    }

    pub fn getMaxHeight(
        self: *PartialRendered,
        context: *BoxContext,
        container: *Box,
    ) !u16 {
        return try self.getPartialData(context).getHeight(self) orelse container.maxHeight;
    }

    pub fn getWidth(self: *PartialRendered, context: *BoxContext, container: *Box) !u16 {
        const box = try self.getBox();
        if (self.tag.tag == .@"inline") {
            return box.width;
        }
        const padding = try self.getPadding(context);
        const margin = try self.getMargin(context);
        const width = switch (try self.getSideAlign(context)) {
            .left, .center, .right => try self.getMaxWidth(context, container),
            .noexpand => padding.side() + margin.side() + box.width,
        };
        return width;
    }

    pub fn getHeight(self: *PartialRendered, context: *BoxContext, container: *Box) !u16 {
        const box = try self.getBox();
        const padding = try self.getPadding(context);
        const margin = try self.getMargin(context);
        const maxHeight = try self.getMaxHeight(context, container);
        const height = switch (try self.getVerticalAlign(context)) {
            .left, .center, .right => maxHeight,
            .noexpand => padding.vert() + margin.vert() + box.height,
        };
        return height;
    }

    // }

    // create box {

    pub fn createBox(self: *PartialRendered) !u16 {
        const context = try self.getContext();
        const container = try self.getContainer();
        var box = switch (self.tag.tag) {
            .@"inline" => try self.createBoxInline(container),
            .block => try self.createBoxBlock(context, container),
            .inlineBlock => try self.createBoxBlockInline(context, container),
        };
        box.hlgroup = self.mainColor;
        const id = try context.newBox(box);

        self.box.set(id);

        return id;
    }

    fn createBoxInline(
        self: *PartialRendered,
        containerBox: *Box,
    ) !Box {
        _ = self;
        const box = containerBox.newBoxCursored();
        // dont need to set maxWidth bc its inherited from containerBox
        // self.box.?.maxWidth = self.maxWidth - self.margin.left - self.padding.left - self.margin.right - self.padding.right;
        return box;
    }
    fn createBoxBlock(self: *PartialRendered, context: *BoxContext, containerBox: *Box) !Box {
        // if we have an inline el, then we need to make it cursored
        var box = containerBox.newBoxFromOffset(
            self.margin.left + self.padding.left,
            self.margin.top + self.padding.top + containerBox.cursorY,
        );
        box.maxWidth = try self.getMaxWidth(context, containerBox);

        return box;
    }
    fn createBoxBlockInline(self: *PartialRendered, context: *BoxContext, containerBox: *Box) !Box {
        var box = try self.createBoxBlock(context, containerBox);
        box.offsetX += containerBox.cursorX;
        return box;
    }

    // }

    pub fn render(self: *PartialRendered) !void {
        _ = self;
    }

    fn renderInline(self: *PartialRendered, box: *Box, containerBox: *Box) !void {
        _ = self;
        containerBox.updateCursorFrom(box);
    }

    fn renderWidthExpansion(
        self: *PartialRendered,
        context: *BoxContext,
        box: *Box,
        containerBox: *Box,
    ) !void {
        var buffer = [_]u8{0} ** 300;
        const dbg: ?*BoxContext =
            comptime if (debug)
                if (self.dbgCtx.asOptional()) |id|
                    try get_context(id)
                else
                    null
            else
                null;

        const padding = try self.getPadding();
        const margin = try self.getMargin();

        const widthExpansion = try self.getMaxWidth(context, containerBox) - padding.side() - margin.side() - box.width;

        switch (self.getSideAlign()) {
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
            .noexpand => return error.UnexpectedInlineEl,
        }
    }

    fn renderHeightExpansion(
        self: *PartialRendered,
        context: *BoxContext,
        box: *Box,
        containerBox: *Box,
    ) !void {
        const padding = try self.getPadding();
        const margin = try self.getMargin();

        const heightExpansion = try self.getMaxHeight(context, containerBox) - padding.vert() - margin.vert() - box.height;

        switch (self.getVerticalAlign()) {
            .center => {
                return error.CenterVerticalAlignUnimplemented;
            },
            .right => {
                return error.RightVerticalAlignUnimplemented;
            },
            .left => {
                try box.expandHeightTo(box.height + heightExpansion);
            },
            .noexpand => return error.UnexpectedInlineEl,
        }
    }
    fn renderMargin(
        self: *PartialRendered,
        context: *BoxContext,
        box: *Box,
        containerBox: *Box,
    ) !void {
        _ = box;

        const height = try self.getHeight();
        const offX = containerBox.offsetX;
        const offY = containerBox.offsetY;
        const alloc = context.alloc();
        const width = try self.getWidth();
        const margin = try self.getMargin();
        const mainWidth = width - margin.side();
        // const mainHeight = height - padding.vert() - margin.vert();
        // set margin and padding
        for (0..height) |i| {
            const line = try context.getLine(offY + @as(u16, @intCast(i)));
            if (i < margin.top or i >= height - margin.bottom) {
                // all margin
                // TODO: Test if this is faster or not
                try line.ensureTotalCapacity(alloc, offX + width);
                const currentStrLen = line.width();
                // ensure that we have enough spaces in the line
                if (currentStrLen < offX + width) {
                    try line.appendAsciiNTimes(
                        context,
                        ' ',
                        self.marginColor,
                        offX + width - currentStrLen,
                    );
                }
                if (currentStrLen > offX) {
                    // only need to set the stuff before currentStrLen
                    // (because everything after was already set to space)
                    @memset(line._chars.items[offX..currentStrLen], .space);
                    @memset(line._hls.items[offX .. offX + width], self.marginColor);
                }
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

                const spaceArea = margin.left;
                @memset(line._chars.items[offX .. offX + spaceArea], .space);
                const spaceCont = spaceArea + mainWidth;
                @memset(line._chars.items[offX + spaceCont .. offX + width], .space);

                @memset(line._hls.items[offX .. offX + margin.left], self.marginColor);
                log.write("memsetting {} .. {}\n", .{ offX + width - margin.right, offX + width }) catch {};
                @memset(
                    line._hls.items[offX + width - margin.right .. offX + width],
                    self.marginColor,
                );
            }
        }
    }
    fn renderPadding(
        self: *PartialRendered,
        context: *BoxContext,
        box: *Box,
        containerBox: *Box,
    ) !void {
        _ = box;
        var buffer = [_]u8{0} ** 300;
        const dbg: ?*BoxContext =
            comptime if (debug)
                if (self.dbgCtx.asOptional()) |id|
                    try get_context(id)
                else
                    null
            else
                null;

        const height = try self.getHeight();
        const offX = containerBox.offsetX;
        const offY = containerBox.offsetY;
        const width = try self.getWidth();
        const padding = try self.getPadding();
        const margin = try self.getMargin();
        const mainWidth = width - padding.side() - margin.side();
        // const mainHeight = height - padding.vert() - margin.vert();
        // set margin and padding
        for (0..height) |i| {
            log.write("looping {}\n", .{i}) catch {};
            if (dbg) |d| {
                const reason = try std.fmt.bufPrint(&buffer, "rendering line index {}", .{i});
                context.dumpTo(d, reason) catch {};
            }
            const line = try context.getLine(offY + @as(u16, @intCast(i)));
            if (i < padding.top or i >= height - padding.bottom) {
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

                const spaceArea = padding.left;
                @memset(line._chars.items[offX .. offX + spaceArea], .space);
                const spaceCont = spaceArea + mainWidth;
                @memset(line._chars.items[offX + spaceCont .. offX + width], .space);

                @memset(
                    line._hls.items[offX .. offX + padding.left],
                    self.mainColor,
                );
                @memset(
                    line._hls.items[offX + padding.left + mainWidth .. offX + width - self.margin.right],
                    self.mainColor,
                );
            }
        }
    }

    fn renderMarginAndPadding(
        self: *PartialRendered,
        context: *BoxContext,
        box: *Box,
        // containerBox: *Box,
    ) !void {
        var buffer = [_]u8{0} ** 300;
        const dbg: ?*BoxContext =
            comptime if (debug)
                if (self.dbgCtx.asOptional()) |id|
                    try get_context(id)
                else
                    null
            else
                null;

        const height = try self.getHeight();
        const offX = box.offsetX;
        const offY = box.offsetY;
        const alloc = context.alloc();
        const width = try self.getWidth();
        const padding = try self.getPadding();
        const margin = try self.getMargin();
        const mainWidth = width - padding.side() - margin.side();
        // const mainHeight = height - padding.vert() - margin.vert();
        // set margin and padding
        for (0..height) |i| {
            log.write("looping {}\n", .{i}) catch {};
            if (dbg) |d| {
                const reason = try std.fmt.bufPrint(&buffer, "rendering line index {}", .{i});
                context.dumpTo(d, reason) catch {};
            }
            const line = try context.getLine(offY + @as(u16, @intCast(i)));
            if (i < margin.top or i >= height - margin.bottom) {
                // all margin
                // TODO: Test if this is faster or not
                try line.ensureTotalCapacity(alloc, offX + width);
                const currentStrLen = line.width();
                // ensure that we have enough spaces in the line
                if (currentStrLen < offX + width) {
                    try line.appendAsciiNTimes(
                        context,
                        ' ',
                        self.marginColor,
                        offX + width - currentStrLen,
                    );
                }
                if (currentStrLen > offX) {
                    // only need to set the stuff before currentStrLen
                    // (because everything after was already set to space)
                    @memset(line._chars.items[offX..currentStrLen], .space);
                    @memset(line._hls.items[offX .. offX + width], self.marginColor);
                }
            } else if (i < margin.top + padding.top or i >= height - margin.bottom - padding.bottom) {
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

                @memset(line._hls.items[offX .. offX + margin.left], self.marginColor);
                @memset(
                    line._hls.items[offX + margin.left .. offX + width - margin.right],
                    self.mainColor,
                );
                @memset(
                    line._hls.items[offX + width - margin.right .. offX + width],
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

                const spaceArea = margin.left + padding.left;
                @memset(line._chars.items[offX .. offX + spaceArea], .space);
                const spaceCont = spaceArea + mainWidth;
                @memset(line._chars.items[offX + spaceCont .. offX + width], .space);
                @memset(line._hls.items[offX .. offX + margin.left], self.marginColor);
                @memset(
                    line._hls.items[offX + margin.left .. offX + margin.left + padding.left],
                    self.mainColor,
                );
                @memset(
                    line._hls.items[offX + margin.left + padding.left + mainWidth .. offX + width - margin.right],
                    self.mainColor,
                );
                @memset(
                    line._hls.items[offX + width - margin.right .. offX + width],
                    self.marginColor,
                );
            }
        }
    }

    fn renderBlock(
        self: *PartialRendered,
        context: *BoxContext,
        box: *Box,
        containerBox: *Box,
    ) !void {
        var buffer = [_]u8{0} ** 300;
        const dbg: ?*BoxContext =
            if (debug)
                if (self.dbgCtx.asOptional()) |id|
                    try get_context(id)
                else
                    null
            else
                null;

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
        const height = mainHeight + self.padding.top + self.padding.bottom + self.margin.top + self.margin.bottom;
        const width = mainWidth + self.padding.left + self.padding.right + self.margin.left + self.margin.right;

        if (dbg) |d| {
            context.dumpTo(d, "Pre height expand") catch {};
            d.dumpComment(
                try std.fmt.bufPrint(&buffer, "target width: {}", .{box.width}),
            ) catch {};
        }

        if (self.tag.height == 1) {
            try self.renderHeightExpansion(context, box, containerBox);
        }

        try box.cleanDbg(dbg);

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

        try self.renderWidthExpansion(context, box, containerBox);

        if (dbg) |d| {
            context.dumpTo(d, "about to render stuff yay") catch {};
        }

        if (self.tag.margin == 1 and self.tag.padding == 1) {
            try self.renderMarginAndPadding();
        } else if (self.tag.margin == 1) {
            try self.renderMargin();
        } else if (self.tag.padding == 1) {
            try self.renderPadding();
        }
    }

    fn renderInlineBlock(
        self: *PartialRendered,
        context: *BoxContext,
        box: *Box,
        containerBox: *Box,
    ) !void {
        try self.renderBlock(context, box, containerBox);
    }
    fn renderCursoredOverflow(self: *PartialRendered, lineHeight: u16) !bool {
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

pub const PrDataStack = struct {
    padding: PadList = .empty,
    margin: PadList = .empty,
    sideAlign: AlignList = .empty,
    verticalAlign: AlignList = .empty,
    width: NumList = .empty,
    height: NumList = .empty,

    pub const empty: PrDataStack = .{};

    pub const NumList = std.ArrayListUnmanaged(u16);
    pub const PadList = std.ArrayListUnmanaged(PartialRendered.Pad);
    pub const AlignList = std.ArrayListUnmanaged(PartialRendered.RenderAlign);

    pub fn cleanup(self: *PrDataStack, pr: *PartialRendered) void {
        if (pr.tag.padding == 1) {
            _ = self.padding.pop();
        }
        if (pr.tag.margin == 1) {
            _ = self.margin.pop();
        }
        if (pr.tag.sideAlign == 1) {
            _ = self.sideAlign.pop();
        }
        if (pr.tag.verticalAlign == 1) {
            _ = self.verticalAlign.pop();
        }
        if (pr.tag.width == 1) {
            _ = self.width.pop();
        }
        if (pr.tag.height == 1) {
            _ = self.height.pop();
        }
    }

    // get set methods: {

    pub fn getWidth(
        self: *PrDataStack,
        pr: *PartialRendered,
    ) !?u16 {
        if (pr.tag.tag == .@"inline" or pr.tag.width == 0) {
            return null;
        }
        return self.width.getLastOrNull() orelse return error.BadStackSize;
    }
    pub fn setWidth(
        self: *PrDataStack,
        pr: *PartialRendered,
        width: u16,
    ) !void {
        if (pr.tag.width == 1) {
            if (self.width.items.len == 0) {
                return error.BadStackSize;
            }
            self.width.items[self.width.items.len - 1] = width;
            return;
        }
        const context: *BoxContext = @fieldParentPtr("partialData", self);
        try self.width.append(context.alloc(), width);
    }

    pub fn getHeight(
        self: *PrDataStack,
        pr: *PartialRendered,
    ) !?u16 {
        if (pr.tag.tag == .@"inline" or pr.tag.height == 0) {
            return null;
        }
        return self.height.getLastOrNull() orelse return error.BadStackSize;
    }
    pub fn setHeight(
        self: *PrDataStack,
        pr: *PartialRendered,
        height: u16,
    ) !void {
        if (pr.tag.height == 1) {
            if (self.height.items.len == 0) {
                return error.BadStackSize;
            }
            self.height.items[self.height.items.len - 1] = height;
            return;
        }
        const context: *BoxContext = @fieldParentPtr("partialData", self);
        try self.height.append(context.alloc(), height);
    }

    pub fn getPadding(self: *PrDataStack, pr: *PartialRendered) !?PartialRendered.Pad {
        if (pr.tag.tag == .@"inline" or pr.tag.padding == 0) {
            return null;
        }
        return self.padding.getLastOrNull() orelse return error.BadStackSize;
    }
    pub fn setPadding(
        self: *PrDataStack,
        pr: *PartialRendered,
        pad: PartialRendered.Pad,
    ) !void {
        if (pr.tag.padding == 1) {
            if (self.padding.items.len == 0) {
                return error.BadStackSize;
            }
            self.padding.items[self.padding.items.len - 1] = pad;
            return;
        }
        const context: *BoxContext = @fieldParentPtr("partialData", self);
        try self.padding.append(context.alloc(), pad);
    }

    pub fn getMargin(self: *PrDataStack, pr: *PartialRendered) !?PartialRendered.Pad {
        if (pr.tag.tag == .@"inline" or pr.tag.margin == 0) {
            return null;
        }
        return self.margin.getLastOrNull() orelse return error.BadStackSize;
    }
    pub fn setMargin(
        self: *PrDataStack,
        pr: *PartialRendered,
        margin: PartialRendered.Pad,
    ) !void {
        if (pr.tag.margin == 1) {
            if (self.margin.items.len == 0) {
                return error.BadStackSize;
            }
            self.margin.items[self.margin.items.len - 1] = margin;
            return;
        }
        const context: *BoxContext = @fieldParentPtr("partialData", self);
        try self.margin.append(context.alloc(), margin);
    }

    pub fn getVerticalAlign(
        self: *PrDataStack,
        pr: *PartialRendered,
    ) !?PartialRendered.RenderAlign {
        if (pr.tag.tag == .@"inline" or pr.tag.verticalAlign == 0) {
            return null;
        }
        return self.verticalAlign.getLastOrNull() orelse return error.BadStackSize;
    }
    pub fn setVerticalAlign(
        self: *PrDataStack,
        pr: *PartialRendered,
        verticalAlign: PartialRendered.RenderAlign,
    ) !void {
        if (pr.tag.verticalAlign == 1) {
            if (self.verticalAlign.items.len == 0) {
                return error.BadStackSize;
            }
            self.verticalAlign[self.verticalAlign.items.len - 1] = verticalAlign;
            return;
        }
        const context: *BoxContext = @fieldParentPtr("partialData", self);
        try self.verticalAlign.append(context.alloc(), verticalAlign);
    }

    pub fn getSideAlign(
        self: *PrDataStack,
        pr: *PartialRendered,
    ) !PartialRendered.RenderAlign {
        if (pr.tag.tag == .@"inline" or pr.tag.differentSideAlign == 0) {
            return null;
        }
        return self.sideAlign.getLastOrNull() orelse return error.BadStackSize;
    }
    pub fn setSideAlign(
        self: *PrDataStack,
        pr: *PartialRendered,
        sideAlign: PartialRendered.RenderAlign,
    ) !void {
        if (pr.tag.sideAlign == 1) {
            if (self.sideAlign.items.len == 0) {
                return error.BadStackSize;
            }
            self.sideAlign.items[self.sideAlign.items.len - 1] = sideAlign;
            return;
        }
        const context: *BoxContext = @fieldParentPtr("partialData", self);
        try self.sideAlign.append(context.alloc(), sideAlign);
    }

    // }
};

pub const PartialRenderedTag = packed struct {
    tag: PartialRendered.RenderType,
    /// From padding:!0
    padding: u1 = 0,
    /// From margin:!0
    margin: u1 = 0,

    /// Specified by text-align:!left
    sideAlign: u1 = 0,
    /// Pretty sure this isnt specified yet, but should have it jic
    verticalAlign: u1 = 0,
    /// Specified by width:_
    width: u1 = 0,
    /// Specified by height:_
    height: u1 = 0,
};
