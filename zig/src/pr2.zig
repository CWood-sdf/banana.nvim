const _b = @import("box.zig");
const debug = @import("debug.zig").debug;
const std = @import("std");
const log = @import("log.zig");
const get_context = _b.get_context;
const get_box = _b.get_box;
const sub = _b.sub;
const subMult = _b.subMult;
const subMultOr = _b.subMultOr;
const subOr = _b.subOr;
const Id = _b.Id;
const NullableId = _b.NullableId;
const Highlight = _b.Highlight;
const BoxContext = _b.BoxContext;
const Box = _b.Box;

pub const BoundBox = struct {
    leftX: u16,
    topY: u16,
    bottomY: u16,
    rightX: u16,
};

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
pub const PartialRendered = struct {
    tag: PartialRenderedTag,
    ctx: Id,
    containerBox: Id,
    box: NullableId,
    // TODO: remove this if not in debug
    dbgCtx: NullableId,
    mainColor: Highlight,
    // TODO: Can just have a bunch of stacks and the tag determines which stack has data
    //
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
            return left.left == right.left and left.right == right.right and left.top == right.top and left.bottom == right.bottom;
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
                .tag = .block,
            },
            .dbgCtx = .nil,
            .ctx = containerBox.context,
            .containerBox = containerId,
            .box = .nil,
            .mainColor = 0,
        };
    }

    pub fn deinit(self: *PartialRendered) void {
        const context: *BoxContext = get_context(self.ctx) catch return;
        context.partialData.cleanup(self);
        _ = context.partials.pop();
    }

    // bound box {
    pub fn getBoundBoxCount(self: *const PartialRendered) !u16 {
        return switch (self.tag.tag) {
            .@"inline" => blk: {
                const box = try self.getBox();
                const container = try self.getContainer();
                break :blk box.cursorY - container.cursorY + 1;
            },
            else => 1,
        };
    }

    pub fn getBoundBox(self: *const PartialRendered, n: u16) !BoundBox {
        if (n > 1 and self.tag.tag != .@"inline") {
            return error.InlineBoundBoxOnNonInline;
        }
        const box = try self.getBox();
        const ctx = try self.getContext();
        const padding = try self.getPadding(ctx);
        const margin = try self.getMargin(ctx);
        const width = try self.getWidth();
        const height = try self.getHeight();
        return .{
            .leftX = try sub(box.offsetX, padding.left) + 1,
            .rightX = box.offsetX + width - margin.side() + 1,
            .topY = try sub(box.offsetY, padding.top) + 1,
            .bottomY = box.offsetY + height - margin.vert() + 1,
        };
    }
    // }

    // value setters {

    fn setAsBlockType(self: *PartialRendered) void {
        if (self.tag.tag == .@"inline") {
            log.write("Promoting element to inlineBlock\n", .{}) catch {};
            self.tag.tag = .inlineBlock;
        }
    }
    pub fn setRenderType(self: *PartialRendered, renderType: RenderType) void {
        self.tag.tag = renderType;
    }

    pub fn setAlign(self: *PartialRendered, al: RenderAlign) !void {
        const context = try self.getContext();
        self.setAsBlockType();
        try self.getPartialData(context).setSideAlign(self, al);
    }

    pub fn setVerticalAlign(self: *PartialRendered, al: RenderAlign) !void {
        const context = try self.getContext();
        self.setAsBlockType();
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
        self.setAsBlockType();
        const context = try get_context(self.ctx);
        try context.partialData.setMargin(self, margin);
    }

    pub fn setPadding(self: *PartialRendered, padding: Pad) !void {
        if (padding.equals(.zero)) {
            return;
        }
        self.setAsBlockType();
        const context = try get_context(self.ctx);
        try context.partialData.setPadding(self, padding);
    }

    pub fn setMainColor(self: *PartialRendered, main: Highlight) !void {
        self.mainColor = main;
    }

    pub fn setMaxWidth(self: *PartialRendered, width: u16, force: bool) !void {
        const context = try get_context(self.ctx);
        const currentWidth = try context.partialData.getWidth(self) orelse std.math.maxInt(@TypeOf(width));
        const w = if (force) width else @min(currentWidth, width);
        try context.partialData.setWidth(self, w);
    }

    pub fn setMaxHeight(self: *PartialRendered, height: u16) !void {
        const context = try get_context(self.ctx);
        const currentHeight = try context.partialData.getHeight(self) orelse std.math.maxInt(@TypeOf(height));
        log.write("Setting max height to {}\n", .{@min(currentHeight, height)}) catch {};
        try context.partialData.setHeight(self, @min(currentHeight, height));
    }
    // }

    // internal box getters {
    fn getContainer(self: *const PartialRendered) !*Box {
        return try get_box(self.ctx, self.containerBox);
    }
    fn getContext(self: *const PartialRendered) !*BoxContext {
        return try get_context(self.ctx);
    }
    fn getPartialData(self: *const PartialRendered, context: *BoxContext) *PrDataStack {
        _ = self;
        // const ctx = try self.getContext();
        return &context.partialData;
    }
    fn getBox(self: *const PartialRendered) !*Box {
        if (self.box.asOptional()) |id| {
            return try get_box(self.ctx, id);
        }
        return error.BoxNotExist;
    }
    // }

    // value getters {
    pub fn getMaxWidth(
        self: *const PartialRendered,
        context: *BoxContext,
        container: *Box,
    ) !u16 {
        return try self.getPartialData(context).getWidth(self) orelse container.maxWidth;
    }

    pub fn getMargin(self: *const PartialRendered, context: *BoxContext) !Pad {
        return try self.getPartialData(context).getMargin(self) orelse .zero;
    }

    pub fn getSideAlign(self: *const PartialRendered, context: *BoxContext) !RenderAlign {
        if (self.tag.tag == .@"inline") {
            return .noexpand;
        }
        const defaultAlign: RenderAlign = switch (self.tag.tag) {
            .@"inline" => unreachable,
            .inlineBlock => .noexpand,
            .block => .left,
        };
        return try self.getPartialData(context).getSideAlign(self) orelse defaultAlign;
    }

    pub fn getVerticalAlign(self: *const PartialRendered, context: *BoxContext) !RenderAlign {
        return try self.getPartialData(context).getVerticalAlign(self) orelse .noexpand;
    }

    pub fn getPadding(self: *const PartialRendered, context: *BoxContext) !Pad {
        return try self.getPartialData(context).getPadding(self) orelse .zero;
    }

    pub fn getMaxHeight(
        self: *const PartialRendered,
        context: *BoxContext,
        container: *Box,
    ) !u16 {
        return try self.getPartialData(context).getHeight(self) orelse container.maxHeight;
    }

    pub fn getMinWidth(self: *PartialRendered) !u16 {
        const context = try self.getContext();

        const padding = try self.getPadding(context);
        const margin = try self.getMargin(context);

        const box = try self.getBox();

        return padding.side() + margin.side() + box.width;
    }
    pub fn getWidth(self: *const PartialRendered) !u16 {
        const context = try self.getContext();
        const container = try self.getContainer();
        return try self._getWidth(context, container);
    }

    pub fn _getWidth(self: *const PartialRendered, context: *BoxContext, container: *Box) !u16 {
        const box = try self.getBox();
        if (self.tag.tag == .@"inline") {
            return box.width;
        }
        const padding = try self.getPadding(context);
        const margin = try self.getMargin(context);
        const noexpandWidth = padding.side() + margin.side() + box.width;
        const width = switch (try self.getSideAlign(context)) {
            .left, .center, .right => @max(noexpandWidth, try self.getMaxWidth(context, container)),
            .noexpand => noexpandWidth,
        };
        return width;
    }

    pub fn getHeight(self: *const PartialRendered) !u16 {
        const context = try self.getContext();
        const container = try self.getContainer();
        return try self._getHeight(context, container);
    }
    pub fn _getHeight(self: *const PartialRendered, context: *BoxContext, container: *Box) !u16 {
        const box = try self.getBox();
        const padding = try self.getPadding(context);
        const margin = try self.getMargin(context);
        const maxHeight = try self.getMaxHeight(context, container);
        const noexpandHeight = padding.vert() + margin.vert() + box.height;
        const height = switch (try self.getVerticalAlign(context)) {
            .left, .center, .right => @max(noexpandHeight, maxHeight),
            .noexpand => noexpandHeight,
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
        const margin = try self.getMargin(context);
        const padding = try self.getPadding(context);
        // if we have an inline el, then we need to make it cursored
        var box = containerBox.newBoxFromOffset(
            margin.left + padding.left,
            margin.top + padding.top + containerBox.cursorY,
        );
        box.maxWidth = subMultOr(u16, &[_]u16{
            try self.getMaxWidth(context, containerBox),
            margin.side(),
            padding.side(),
        }, 0);
        const dbg: ?*BoxContext =
            if (comptime debug)
                if (self.dbgCtx.asOptional()) |id|
                    try get_context(id)
                else
                    null
            else
                null;
        if (dbg) |d| {
            var buffer = [_]u8{0} ** 300;
            d.dumpComment(try std.fmt.bufPrint(&buffer, "setting max width to {}", .{box.maxWidth})) catch {};
        }
        log.write("setting max width to {}\n", .{box.maxWidth}) catch {};

        return box;
    }
    fn createBoxBlockInline(self: *PartialRendered, context: *BoxContext, containerBox: *Box) !Box {
        log.write("Creating block inline \n", .{}) catch {};
        var box = try self.createBoxBlock(context, containerBox);
        box.cursorX = 0;
        box.offsetX += containerBox.cursorX;
        return box;
    }

    // }

    // render functions {

    pub fn render(self: *PartialRendered, lineHeight: ?u16) !u16 {
        const startTime = std.time.microTimestamp();

        defer {
            const time = std.time.microTimestamp() - startTime;
            log.write("Time taken: {}us\n", .{time}) catch {};
        }
        const containerBox = try self.getContainer();
        const box = try self.getBox();
        const context = try self.getContext();
        log.write("Rendering for type: {}\n", .{self.tag.tag}) catch {};
        const newLineHeight = switch (self.tag.tag) {
            .@"inline" => blk: {
                const multiline = containerBox.cursorY != box.cursorY;
                try self.renderInline(box, containerBox);
                break :blk if (multiline)
                    1
                else
                    @max(lineHeight orelse return error.NoGivenLineHeight, 1);
            },
            .block => blk: {
                try self.renderBlock(context, box, containerBox, true);
                break :blk 0;
            },
            .inlineBlock => try self.renderInlineBlock(
                context,
                box,
                containerBox,
                lineHeight orelse return error.NoGivenLineHeight,
            ),
        };

        return newLineHeight;
    }

    fn renderInline(self: *PartialRendered, box: *Box, containerBox: *Box) !void {
        // inline elements have no margin, padding, width, height, ...
        // so therefore any "rendering" has already been done by the boxAppendStr
        _ = self;
        containerBox.updateCursorFrom(box);
    }

    fn renderInlineBlock(self: *PartialRendered, context: *BoxContext, box: *Box, containerBox: *Box, lineHeight: u16) !u16 {
        const maxWidth = subOr(containerBox.maxWidth, containerBox.cursorX, 0);

        var buffer = [_]u8{0} ** 300;
        const dbg: ?*BoxContext =
            if (debug)
                if (self.dbgCtx.asOptional()) |id|
                    try get_context(id)
                else
                    null
            else
                null;

        log.write("calling render block\n", .{}) catch {};
        // const containerWidth = containerBox.width;
        try self.renderBlock(context, box, containerBox, false);
        log.write("getWidth\n", .{}) catch {};
        const width = try self._getWidth(context, containerBox);
        const height = try self._getHeight(context, containerBox);

        log.write("checking gucciness\n", .{}) catch {};
        if (width < maxWidth or containerBox.cursorX == 0) {
            log.write("is gucci\n", .{}) catch {};
            containerBox.cursorX += width;
            containerBox.dirty = containerBox.width != containerBox.cursorX;
            containerBox.width = @max(containerBox.width, containerBox.cursorX);
            const newLineHeight = @max(lineHeight, height);
            if (containerBox.cursorX >= containerBox.maxWidth) {
                containerBox.cursorX = 0;
                containerBox.cursorY += newLineHeight;
            }
            return newLineHeight;
        }
        log.write("no gucci\n", .{}) catch {};

        var image: std.ArrayListUnmanaged(_b.Line) = .empty;

        for (0..height) |i| {
            const lineI = containerBox.cursorY + containerBox.offsetY + i;
            log.write("Getting line {}\n", .{i}) catch {};
            if (dbg) |d| {
                d.dumpComment(try std.fmt.bufPrint(&buffer, "Capturing line {}", .{lineI})) catch {};
            }
            const line = try context.getLine(@intCast(lineI));
            var actualLine: _b.Line = .init();

            const start = containerBox.cursorX;
            try actualLine._chars.appendSlice(context.alloc(), line._chars.items[start..]);
            try actualLine._hls.appendSlice(context.alloc(), line._hls.items[start..]);

            try image.append(context.alloc(), actualLine);

            if (i >= lineHeight) {
                line._chars.shrinkRetainingCapacity(containerBox.offsetX);
                line._hls.shrinkRetainingCapacity(containerBox.offsetX);
            } else {
                line._chars.shrinkRetainingCapacity(containerBox.cursorX + containerBox.offsetX);
                line._hls.shrinkRetainingCapacity(containerBox.cursorX + containerBox.offsetX);
            }
            if (dbg) |d| {
                context.dumpTo(d, "image capture") catch {};
            }
        }
        log.write("image grabbed\n", .{}) catch {};

        if (dbg) |d| {
            d.dumpComment("captured Image") catch {};
            d.dumpImage(image.items) catch {};
        }
        const newStartLine = containerBox.cursorY + lineHeight;
        log.write("new start {}\n", .{newStartLine}) catch {};

        if (height != image.items.len) {
            return error.ImageSizeMismatch;
        }

        for (0..height) |i| {
            const lineI = containerBox.cursorY + i + newStartLine + containerBox.offsetY;
            log.write("lineI {}\n", .{lineI}) catch {};
            if (dbg) |d| {
                d.dumpComment(try std.fmt.bufPrint(&buffer, "pasting to line {}", .{lineI})) catch {};
                context.dumpTo(d, "image paste") catch {};
            }
            const line = try context.getLine(@intCast(lineI));
            log.write("appendable to {}\n", .{containerBox.offsetX}) catch {};
            try line.ensureAppendableAt(context, containerBox.offsetX);
            log.write("getting image line\n", .{}) catch {};
            const imageLine = image.items[i];

            try line._chars.appendSlice(context.alloc(), imageLine._chars.items[0..]);
            try line._hls.appendSlice(context.alloc(), imageLine._hls.items[0..]);
        }
        log.write("done building\n", .{}) catch {};

        containerBox.dirty = true;
        containerBox.width = @max(containerBox.width, width);
        containerBox.cursorX = width;
        containerBox.cursorY = newStartLine;
        containerBox.height = newStartLine + height;
        if (containerBox.cursorX >= containerBox.maxWidth) {
            containerBox.cursorX = 0;
            containerBox.cursorY += height;
            return 0;
        }

        return height;
    }

    fn renderWidthExpansion(
        self: *PartialRendered,
        context: *BoxContext,
        box: *Box,
        widthExpansion: u16,
        containerBox: *Box,
    ) !void {
        var buffer = [_]u8{0} ** 300;
        const dbg: ?*BoxContext =
            if (comptime debug)
                if (self.dbgCtx.asOptional()) |id|
                    try get_context(id)
                else
                    null
            else
                null;

        const padding = try self.getPadding(context);
        const margin = try self.getMargin(context);

        // const widthExpansion = try self.getMaxWidth(context, containerBox) - padding.side() - margin.side() - box.width;
        const insertPos = containerBox.realCursorX() + padding.left + margin.left + box.width;

        switch (try self.getSideAlign(context)) {
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
                    const actualInsertPos = insertPos + leftSide;
                    for (0..rightSide) |_| {
                        try line.insertAscii(context, actualInsertPos, ' ', self.mainColor);
                    }
                }
            },
            .right => {
                try box.shiftRightwardsBy(widthExpansion);
            },
            .left => {
                for (box.offsetY..box.offsetY + box.height) |i| {
                    const line = try context.getLine(@intCast(i));
                    log.write("Width expansion yay: {}\n", .{widthExpansion}) catch {};
                    // try line.appendAsciiNTimes(context, ' ', self.mainColor, widthExpansion);
                    for (0..widthExpansion) |_| {
                        try line.insertAscii(context, insertPos, ' ', self.mainColor);
                    }
                }
            },
            // prolly inlineBlock with no width:
            .noexpand => {},
        }
    }

    fn renderHeightExpansion(
        self: *PartialRendered,
        context: *BoxContext,
        box: *Box,
        // containerBox: *Box,
        heightExpansion: u16,
    ) !void {
        log.write("Expanding height by: {}\n", .{heightExpansion}) catch {};

        switch (try self.getVerticalAlign(context)) {
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

    fn renderMarginAndPadding(
        self: *PartialRendered,
        context: *BoxContext,
        box: *Box,
        containerBox: *Box,
    ) !void {
        var buffer = [_]u8{0} ** 300;
        const dbg: ?*BoxContext =
            if (comptime debug)
                if (self.dbgCtx.asOptional()) |id|
                    try get_context(id)
                else
                    null
            else
                null;

        const height = try self.getHeight();
        _ = box;
        const offX = containerBox.realCursorX();
        const offY = containerBox.realCursorY();
        const alloc = context.alloc();
        const width = try self._getWidth(context, containerBox);
        const padding = try self.getPadding(context);
        const margin = try self.getMargin(context);
        const mainWidth = try subMult(u16, &[_]u16{
            width,
            padding.side(),
            margin.side(),
        });
        if (dbg) |d| {
            const str = try std.fmt.bufPrint(&buffer, "Rendering to width {}", .{width});
            d.dumpComment(str) catch {};
        }
        // const mainHeight = height - padding.vert() - margin.vert();
        // set margin and padding
        for (0..height) |i| {
            log.write("looping {}\n", .{i}) catch {};
            if (dbg) |d| {
                const reason = try std.fmt.bufPrint(&buffer, "rendering line index {} ({})", .{ i, offY + i });
                context.dumpTo(d, reason) catch {};
            }
            const line = try context.getLine(offY + @as(u16, @intCast(i)));
            if (i < margin.top or i >= height - margin.bottom) {
                // TODO: Test if this is faster or not
                try line.ensureTotalCapacity(alloc, offX + width);
                const currentStrLen = line.width();
                // ensure that we have enough spaces in the line
                if (currentStrLen < offX + width) {
                    try line.appendAsciiNTimes(
                        context,
                        ' ',
                        containerBox.hlgroup,
                        subOr(offX + width, currentStrLen, 0),
                    );
                }
                if (currentStrLen > offX) {
                    // only need to set the stuff before currentStrLen
                    // (because everything after was already set to space)
                    @memset(line._chars.items[offX..currentStrLen], .space);
                    @memset(line._hls.items[offX .. offX + width], containerBox.hlgroup);
                }
            } else if (i < margin.top + padding.top or i >= height - margin.bottom - padding.bottom) {
                // margin l r, middle padding
                const currentStrLen = line.width();
                if (currentStrLen < offX + width) {
                    try line.appendAsciiNTimes(
                        context,
                        ' ',
                        containerBox.hlgroup,
                        subOr(offX + width, currentStrLen, 0),
                    );
                }
                if (dbg) |d| {
                    context.dumpTo(d, "Starting middle pad") catch {};
                }

                if (currentStrLen > offX) {
                    @memset(line._chars.items[offX..currentStrLen], .space);
                }
                if (dbg) |d| {
                    context.dumpTo(d, "Middle pad 1") catch {};
                }
                @memset(line._hls.items[offX .. offX + margin.left], containerBox.hlgroup);
                if (dbg) |d| {
                    context.dumpTo(d, "Middle pad 2") catch {};
                }
                @memset(
                    line._hls.items[offX + margin.left .. offX + width - margin.right],
                    self.mainColor,
                );
                if (dbg) |d| {
                    context.dumpTo(d, "Middle pad 3") catch {};
                }
                @memset(
                    line._hls.items[offX + width - margin.right .. offX + width],
                    containerBox.hlgroup,
                );
                if (dbg) |d| {
                    context.dumpTo(d, "Middle pad 4 (done)") catch {};
                }
            } else {
                // margin + pad l r, middle content{
                const currentStrLen = line.width();
                log.write("Widths: {}, {}\n", .{ line._chars.items.len, line._hls.items.len }) catch {};
                if (currentStrLen < offX + width) {
                    try line.appendAsciiNTimes(
                        context,
                        ' ',
                        containerBox.hlgroup,
                        subOr(offX + width, currentStrLen, 0),
                    );
                }

                const spaceArea = margin.left + padding.left;
                @memset(line._chars.items[offX .. offX + spaceArea], .space);
                const spaceCont = spaceArea + mainWidth;
                @memset(line._chars.items[offX + spaceCont .. offX + width], .space);
                @memset(line._hls.items[offX .. offX + margin.left], containerBox.hlgroup);
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
                    containerBox.hlgroup,
                );
            }
        }
    }

    fn renderBlock(
        self: *PartialRendered,
        context: *BoxContext,
        box: *Box,
        containerBox: *Box,
        moveCursor: bool,
    ) !void {
        log.write("render blocking yuhh\n", .{}) catch {};
        var buffer = [_]u8{0} ** 300;
        const dbg: ?*BoxContext =
            if (debug)
                if (self.dbgCtx.asOptional()) |id|
                    try get_context(id)
                else
                    null
            else
                null;

        const sideAlign = try self.getSideAlign(context);
        const verticalAlign = try self.getVerticalAlign(context);
        log.write("vertical align: {}\n", .{verticalAlign}) catch {};
        const margin = try self.getMargin(context);
        const padding = try self.getPadding(context);
        const maxWidth = try self.getMaxWidth(context, containerBox);
        const maxHeight = try self.getMaxHeight(context, containerBox);
        log.write("Yuhh did stuff max height {}\n", .{maxHeight}) catch {};
        const widthExpansion =
            if (box.width + margin.side() + padding.side() > maxWidth)
                0
            else switch (sideAlign) {
                .left, .center, .right => subMultOr(u16, &[_]u16{
                    maxWidth,
                    padding.side(),
                    margin.side(),
                    box.width,
                }, 0),
                .noexpand => 0,
            };
        log.write("Yuhh did stuff\n", .{}) catch {};
        const heightExpansion =
            if (box.height + margin.vert() + padding.vert() > maxHeight)
                0
            else switch (verticalAlign) {
                .left, .center, .right => subMultOr(u16, &[_]u16{
                    maxHeight,
                    padding.vert(),
                    margin.vert(),
                    box.height,
                }, 0),
                .noexpand => 0,
            };
        log.write("Yuhh did stuff done he: {}\n", .{heightExpansion}) catch {};
        const mainWidth = box.width + widthExpansion;
        const mainHeight = box.height + heightExpansion;
        const height = mainHeight + padding.vert() + margin.vert();
        const width = mainWidth + padding.side() + margin.side();

        if (dbg) |d| {
            context.dumpTo(d, "Pre height expand") catch {};
            d.dumpComment(
                try std.fmt.bufPrint(&buffer, "target height: {}", .{height}),
            ) catch {};
            d.dumpComment(
                try std.fmt.bufPrint(&buffer, "box height: {}", .{box.height}),
            ) catch {};
        }

        if (self.tag.height == 1) {
            log.write("Rendering height expansion to {}\n", .{height}) catch {};
            try self.renderHeightExpansion(context, box, heightExpansion);
        }

        try box.cleanDbg(dbg);

        if (dbg) |d| {
            context.dumpTo(d, "Pre side align") catch {};
            const comment = try std.fmt.bufPrint(&buffer, "side align: {s}", .{@tagName(sideAlign)});
            d.dumpComment(comment) catch {};
        }

        try self.renderWidthExpansion(context, box, widthExpansion, containerBox);
        if (dbg) |d| {
            const comment = try std.fmt.bufPrint(&buffer, "rendered width expansion: {}", .{widthExpansion});
            d.dumpComment(comment) catch {};
        }

        if (dbg) |d| {
            context.dumpTo(d, "about to render stuff yay") catch {};
        }

        if (self.tag.margin == 1 or self.tag.padding == 1) {
            try self.renderMarginAndPadding(context, box, containerBox);
        }
        if (dbg) |d| {
            context.dumpTo(d, "done rendering") catch {};
        }
        if (width != containerBox.width) {
            containerBox.width = @max(containerBox.width, width);
            containerBox.dirty = true;
        }

        // NOTE: If changing, change the offset line in renderWithMove
        if (moveCursor) {
            containerBox.cursorY += height;
            containerBox.height += height;
        }
        if (dbg) |d| {
            context.dumpTo(d, try std.fmt.bufPrint(&buffer, "new height: {}", .{containerBox.height})) catch {};
        }
    }

    // }

};

const PrDataItem = struct {
    padding: PartialRendered.Pad,
    margin: PartialRendered.Pad,
    sideAlign: RenderAlign,
    verticalAlign: RenderAlign,
    width: u16,
    height: u16,
};

fn GenPrLists() type {
    const info = @typeInfo(PrDataItem).@"struct";

    var fieldArrays: [info.fields.len]std.builtin.Type.StructField = undefined;

    inline for (info.fields, 0..) |field, i| {
        const ArrType = std.ArrayListUnmanaged(field.type);
        const newField: std.builtin.Type.StructField = .{
            .type = ArrType,
            .name = field.name,
            .is_comptime = false,
            .alignment = @alignOf(ArrType),
            .default_value_ptr = &ArrType.empty,
        };
        fieldArrays[i] = newField;
    }

    const decls: [0]std.builtin.Type.Declaration = .{};

    const Struct: std.builtin.Type.Struct = .{
        .fields = &fieldArrays,
        .backing_integer = null,
        .decls = &decls,
        .is_tuple = false,
        .layout = .auto,
    };

    return @Type(.{
        .@"struct" = Struct,
    });
}

fn prListsGetMemoryUsage(lists: *const GenPrLists()) usize {
    const fields = @typeInfo(GenPrLists()).@"struct".fields;
    var ret: usize = 0;

    inline for (fields) |field| {
        const arr = @field(lists, field.name);
        ret += arr.capacity * @sizeOf(@TypeOf(arr.items[0]));
    }
    return ret;
}

fn prListsCleanupFor(self: *GenPrLists(), pr: *PartialRendered) void {
    const fields = @typeInfo(GenPrLists()).@"struct".fields;

    inline for (fields) |field| {
        const arr = &@field(self, field.name);
        if (@field(pr.tag, field.name) == 1) {
            _ = arr.pop();
        }
    }
}

fn prListsGetValue(
    self: *PrDataStack,
    pr: *const PartialRendered,
    comptime ignore: []const RenderType,
    comptime field: []const u8,
) !?@FieldType(PrDataItem, field) {
    const fields = &self.fields;
    if (@field(pr.tag, field) == 0) {
        return null;
    }
    inline for (ignore) |i| {
        if (pr.tag.tag == i) {
            return null;
        }
    }

    return @field(fields, field).getLastOrNull() orelse return error.BadStackSize;
}

fn prListsSetValue(
    self: *PrDataStack,
    pr: *PartialRendered,
    comptime field: []const u8,
    value: @FieldType(PrDataItem, field),
) !void {
    defer @field(pr.tag, field) = 1;

    const fields: *GenPrLists() = &self.fields;
    const arr = &@field(fields, field);
    if (@field(pr.tag, field) == 1) {
        if (arr.items.len == 0) {
            return error.EmptyStack;
        }
        arr.items[arr.items.len - 1] = value;
    }
    const context: *BoxContext = @fieldParentPtr("partialData", self);
    try arr.append(context.alloc(), value);
}

pub const PrDataStack = struct {
    const PrLists = GenPrLists();
    fields: PrLists = .{},
    // padding: PadList = .empty,
    // margin: PadList = .empty,
    // sideAlign: AlignList = .empty,
    // verticalAlign: AlignList = .empty,
    // width: NumList = .empty,
    // height: NumList = .empty,

    pub const empty: PrDataStack = .{};

    const ignoreInline = [_]RenderType{.@"inline"};

    pub const NumList = std.ArrayListUnmanaged(u16);
    pub const PadList = std.ArrayListUnmanaged(PartialRendered.Pad);
    pub const AlignList = std.ArrayListUnmanaged(RenderAlign);

    pub fn getMemoryUsage(self: *const PrDataStack) usize {
        return prListsGetMemoryUsage(&self.fields);
    }
    pub fn cleanup(self: *PrDataStack, pr: *PartialRendered) void {
        prListsCleanupFor(&self.fields, pr);
    }

    // get set methods: {

    pub fn getWidth(
        self: *PrDataStack,
        pr: *const PartialRendered,
    ) !?u16 {
        return try prListsGetValue(self, pr, &ignoreInline, "width");
    }
    pub fn setWidth(
        self: *PrDataStack,
        pr: *PartialRendered,
        width: u16,
    ) !void {
        try prListsSetValue(self, pr, "width", width);
    }

    pub fn getHeight(
        self: *PrDataStack,
        pr: *const PartialRendered,
    ) !?u16 {
        return try prListsGetValue(self, pr, &ignoreInline, "height");
    }
    pub fn setHeight(
        self: *PrDataStack,
        pr: *PartialRendered,
        height: u16,
    ) !void {
        try prListsSetValue(self, pr, "height", height);
    }

    pub fn getPadding(self: *PrDataStack, pr: *const PartialRendered) !?PartialRendered.Pad {
        return try prListsGetValue(self, pr, &ignoreInline, "padding");
    }
    pub fn setPadding(
        self: *PrDataStack,
        pr: *PartialRendered,
        pad: PartialRendered.Pad,
    ) !void {
        try prListsSetValue(self, pr, "padding", pad);
    }

    pub fn getMargin(self: *PrDataStack, pr: *const PartialRendered) !?PartialRendered.Pad {
        return try prListsGetValue(self, pr, &ignoreInline, "margin");
    }
    pub fn setMargin(
        self: *PrDataStack,
        pr: *PartialRendered,
        margin: PartialRendered.Pad,
    ) !void {
        try prListsSetValue(self, pr, "margin", margin);
    }

    pub fn getVerticalAlign(
        self: *PrDataStack,
        pr: *const PartialRendered,
    ) !?RenderAlign {
        return try prListsGetValue(self, pr, &ignoreInline, "verticalAlign");
    }
    pub fn setVerticalAlign(
        self: *PrDataStack,
        pr: *PartialRendered,
        verticalAlign: RenderAlign,
    ) !void {
        try prListsSetValue(self, pr, "verticalAlign", verticalAlign);
    }

    pub fn getSideAlign(
        self: *PrDataStack,
        pr: *const PartialRendered,
    ) !?RenderAlign {
        return try prListsGetValue(self, pr, &ignoreInline, "sideAlign");
    }
    pub fn setSideAlign(
        self: *PrDataStack,
        pr: *PartialRendered,
        sideAlign: RenderAlign,
    ) !void {
        try prListsSetValue(self, pr, "sideAlign", sideAlign);
    }

    // }
};

pub const PartialRenderedTag = packed struct {
    tag: RenderType,
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
