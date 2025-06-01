const log = @import("../log.zig");
const Line = @import("Line.zig");
const Box = @import("Box.zig");
const BoxContext = @import("BoxContext.zig");
const PartialRendered = @import("PartialRendered.zig");
const common = @import("common.zig");
const get_box = common.get_box;
const get_context = common.get_context;
const get_partial = common.get_partial;
const BoxExpect = ExpectStr("Banana.Box");
const lua = @import("../lua_api/lua.zig");
const std = @import("std");
const NullableId = common.NullableId;
const Highlight = common.Highlight;

fn dumpObjectToLua(T: type, obj: *const T, L: *lua.State) !void {
    const info = @typeInfo(T).@"struct";
    inline for (info.fields) |field| {
        const name = field.name;
        const luaName = std.fmt.comptimePrint("_{s}", .{name});
        // log.write("Pushing debug field {s} for type {}\n", .{ name, T }) catch {};
        const top = lua.get_top(L);
        switch (@typeInfo(field.type)) {
            .int => {
                lua.push_int(L, std.math.lossyCast(c_int, @field(obj.*, name)));
            },
            .bool => {
                lua.push_bool(L, @field(obj.*, name));
            },
            .float => {
                lua.push_number(L, @field(obj.*, name));
            },
            .@"struct" => {
                switch (field.type) {
                    NullableId => {
                        const val: NullableId = @field(obj.*, name);
                        if (val.isNull()) {
                            lua.push_nil(L);
                        } else {
                            lua.push_int(L, @intCast(val.value));
                        }
                    },
                    else => {
                        const ptr = &@field(obj.*, name);
                        lua.create_table(L, 0, 4);
                        try dumpObjectToLua(@TypeOf(ptr.*), ptr, L);
                    },
                }
            },
            .@"enum" => {
                const value = @field(obj.*, name);
                const str = @tagName(value);
                lua.push_stringslice(L, str);
            },
            .void => {},
            else => @compileError(std.fmt.comptimePrint("omg errr {}", .{field.type})),
        }
        lua.set_field(L, top, luaName);
    }
}

// pub fn box_context_render_to_string(ctx: u16) ![]const u8 {}
pub fn box_context_get_memory_usage(ctx: u16) !usize {
    const context = try get_context(ctx);
    // _ = context;
    // return 0;
    return context.arena.queryCapacity();
}
pub fn box_context_data_memory_usage(ctx: u16) !usize {
    const context = try get_context(ctx);
    // _ = context;
    // return 0;
    return context.partialData.getMemoryUsage();
}
pub fn box_context_line_memory_usage(ctx: u16) !usize {
    const context = try get_context(ctx);
    // _ = context;
    // return 0;
    var usage: usize = context.lines.capacity * @sizeOf(Line);
    for (context.lines.items) |line| {
        usage += line.getMemoryUsage();
    }
    return usage;
}
pub fn box_context_pr_memory_usage(ctx: u16) !usize {
    const context = try get_context(ctx);
    // _ = context;
    // return 0;
    return context.partials.capacity * @sizeOf(Box);
}
pub fn box_context_box_memory_usage(ctx: u16) !usize {
    const context = try get_context(ctx);
    // _ = context;
    // return 0;
    return context.boxes.capacity * @sizeOf(Box);
}

pub fn box_dump_box_data(ctx: u16, box: u16, value: BoxExpect) !void {
    const b = try get_box(ctx, box);
    try dumpObjectToLua(Box, b, value.L);
}

const PartialExpect = ExpectStr("Banana.Renderer.PartialRendered");

pub fn box_dump_pr_data(ctx: u16, pr: u16, value: PartialExpect) !void {
    const p = try get_partial(ctx, pr);
    try dumpObjectToLua(PartialRendered, p, value.L);
}

// new context {
pub fn box_context_delete_all() void {
    for (0.., common.contexts.items) |i, _| {
        _ = box_context_delete(@intCast(i));
    }
}
/// @return i16 the id of a new box context
pub fn box_context_create() !u16 {
    for (common.contexts.items, 0..) |item, i| {
        if (item) |_| continue;
        common.contexts.items[i] = BoxContext.init(std.heap.smp_allocator);
        return @intCast(i);
    }
    try common.contexts.append(std.heap.smp_allocator, null);
    const i = common.contexts.items.len - 1;
    common.contexts.items[i] = BoxContext.init(std.heap.smp_allocator);
    return @intCast(i);
}

pub fn box_context_dump_to(ctx: u16, other: u16, reason: []const u8) !void {
    const self = try get_context(ctx);
    const o = try get_context(other);
    try self.dumpTo(o, reason);
}

pub fn box_context_dump_comment(ctx: u16, comment: []const u8) !void {
    const self = try get_context(ctx);
    try self.dumpComment(comment);
}

// }

// delete context {
/// In all cases, if ctx is valid it will be deleted
/// @param ctx u16 A box context id
/// @return bool whether the context existed or not
pub fn box_context_delete(ctx: u16) bool {
    if (ctx >= common.contexts.items.len) {
        return false;
    }
    if (common.contexts.items[ctx]) |*context| {
        context.deinit();
    }
    common.contexts.items[ctx] = null;
    return true;
}

pub fn box_context_wipe(ctx: u16) bool {
    const context = get_context(ctx) catch return false;
    return context.wipe();
}

// }

// context exists {
/// @retrun ctx u16 a box context id
/// @return bool whether the context exists or not
pub fn box_context_exists(ctx: u16) bool {
    if (ctx >= common.contexts.items.len) {
        return false;
    }
    return common.contexts.items[ctx] != null;
}

pub fn box_destroy(ctx: u16, boxid: u16) !void {
    const context = try get_context(ctx);

    while (context.boxes.items.len > boxid) {
        _ = context.boxes.pop();
    }
}
// }

// partial rendereds {
pub fn box_pr_new(ctx: u16, boxid: u16) !u16 {
    const context = try get_context(ctx);
    const box = try get_box(ctx, boxid);
    const partial = PartialRendered.init(box, boxid);
    return try context.newPartial(partial);
}
pub fn box_pr_get_bound_box_count(ctx: u16, pr: u16) !u16 {
    const partial = try get_partial(ctx, pr);
    return try partial.getBoundBoxCount();
}

const BoundBoxExpect = ExpectStruct("Banana.Ast.BoundingBox", PartialRendered.BoundBox);
pub fn box_pr_get_bound_box(ctx: u16, pr: u16, n: u16) !BoundBoxExpect {
    const partial = try get_partial(ctx, pr);
    return try partial.getBoundBox(n);
}
pub fn box_pr_set_dbg_ctx(ctx: u16, pr: u16, dbg: ?u16) !void {
    const partial = try get_partial(ctx, pr);
    partial.setDebugContext(dbg);
}
pub fn box_pr_set_margin(ctx: u16, partialid: u16, left: u16, right: u16, top: u16, bottom: u16) !void {
    const partial = try get_partial(ctx, partialid);
    try partial.setMargin(.init(left, right, top, bottom));
}
pub fn box_pr_set_pad(ctx: u16, partialid: u16, left: u16, right: u16, top: u16, bottom: u16) !void {
    const partial = try get_partial(ctx, partialid);
    try partial.setPadding(.init(left, right, top, bottom));
}
pub fn box_pr_set_main_hl(ctx: u16, partialid: u16, hl: Highlight) !void {
    const partial = try get_partial(ctx, partialid);
    try partial.setMainColor(hl);
}

pub fn box_pr_get_min_width(ctx: u16, partialid: u16) !u16 {
    const partial = try get_partial(ctx, partialid);
    return try partial.getMinWidth();
}

pub fn box_pr_get_width(ctx: u16, partialid: u16) !u16 {
    const partial = try get_partial(ctx, partialid);
    return try partial.getWidth();
}
pub fn box_pr_get_height(ctx: u16, partialid: u16) !u16 {
    const partial = try get_partial(ctx, partialid);
    return try partial.getHeight();
}
pub fn box_pr_set_max_height(ctx: u16, partialid: u16, height: u16) !void {
    const partial = try get_partial(ctx, partialid);
    try partial.setMaxHeight(height);
}
pub fn box_pr_set_max_width(ctx: u16, partialid: u16, width: u16, force: ?bool) !void {
    const partial = try get_partial(ctx, partialid);
    try partial.setMaxWidth(width, force orelse false);
}
pub fn box_pr_increase_max_width(ctx: u16, partialid: u16, width: u16) !void {
    const partial = try get_partial(ctx, partialid);
    try partial.setMaxWidth(width, true);
}
pub fn box_pr_box(ctx: u16, partialid: u16) !u16 {
    const partial = try get_partial(ctx, partialid);
    return try partial.createBox();
}
pub fn box_pr_set_vertical_align(ctx: u16, partialid: u16, al: u16) !void {
    const partial = try get_partial(ctx, partialid);
    try partial.setVerticalAlign(try std.meta.intToEnum(PartialRendered.RenderAlign, al));
}
pub fn box_pr_get_align(ctx: u16, partialid: u16) !u16 {
    const partial = try get_partial(ctx, partialid);
    const al = try partial.getSideAlign(try get_context(ctx));
    return @intFromEnum(al);
}
pub fn box_pr_set_align(ctx: u16, partialid: u16, al: u16) !void {
    const partial = try get_partial(ctx, partialid);
    try partial.setAlign(try std.meta.intToEnum(PartialRendered.RenderAlign, al));
}
pub fn box_pr_render(ctx: u16, partialid: u16, lineHeight: ?u16) !u16 {
    const partial = try get_partial(ctx, partialid);
    return try partial.render(lineHeight);
}

pub fn box_pr_deinit(ctx: u16, partialid: u16) !void {
    const partial = try get_partial(ctx, partialid);
    partial.deinit();
}

pub fn box_pr_get_render_type(ctx: u16, partialid: u16) !u16 {
    const partial = try get_partial(ctx, partialid);
    return @intFromEnum(partial.tag.tag);
}
pub fn box_pr_set_render_type(ctx: u16, partialid: u16, renderType: u8) !void {
    const partial = try get_partial(ctx, partialid);
    partial.setRenderType(try std.meta.intToEnum(PartialRendered.RenderType, renderType));
}

// }

pub fn box_image_clone(ctx: u16, otherCtx: u16, imageId: u16) !u16 {
    const context = try get_context(ctx);
    const other = try get_context(otherCtx);
    return try context.cloneImage(other, imageId);
}
pub fn box_image_snap(ctx: u16, x: u16, y: u16, w: u16, h: u16, newHl: Highlight) !u16 {
    const context = try get_context(ctx);
    log.write("YO IMAGE: {} {} {} {} {}\n", .{ x, y, w, h, newHl }) catch {};
    return try context.newImage(x, y, w, h, newHl);
}

pub fn box_image_render_over(ctx: u16, image: u16, x: u16, y: u16) !void {
    const context = try get_context(ctx);
    return try context.renderImageOver(image, x, y);
}

// context render {
///
pub fn box_context_render(ctx: u16, buf: u16) !bool {
    const context = try get_context(ctx);
    try context.render(buf, 0, -1);
    return true;
}

pub fn box_context_render_at(ctx: u16, buf: u16, start: i64, _end: i64) !bool {
    const context = try get_context(ctx);
    try context.render(buf, start, _end);
    return true;
}
pub fn box_context_highlight_at(ctx: u16, L: HlExpect, start: u64) !void {
    const context = try get_context(ctx);
    context.highlight(L.L, 2, start);
}

pub fn box_put_cursor_below(ctx: u16, boxOne: u16, boxOther: u16) !void {
    const box1 = try get_box(ctx, boxOne);
    const box2 = try get_box(ctx, boxOther);
    box1.putCursorBelow(box2);
}

pub fn box_unsafe_set_width(ctx: u16, boxid: u16, width: u16) !void {
    const box = try get_box(ctx, boxid);
    box.unsafeSetWidth(width);
}
pub fn box_unsafe_increase_offset(ctx: u16, boxid: u16, left: i16, top: i16) !void {
    const box = try get_box(ctx, boxid);
    box.increaseOffsetBy(left, top);
}
pub fn box_unsafe_set_cursor(ctx: u16, boxid: u16, left: u16, top: u16) !void {
    const box = try get_box(ctx, boxid);
    box.cursorX = left;
    box.cursorY = top;
}
pub fn box_unsafe_increase_cursor(ctx: u16, boxid: u16, left: i16, top: i16) !void {
    const box = try get_box(ctx, boxid);
    box.increaseCursorBy(left, top);
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

/// Here so that functions can get lua functions/tables and document
/// what they want from the type
pub fn ExpectStruct(comptime str: []const u8, T: type) type {
    _ = str;
    return T;
}

/// Here so that functions can get lua functions/tables and document
/// what they want from the type
pub fn ExpectStr(comptime str: []const u8) type {
    return struct {
        L: *lua.State,
        pub const isLua = true;
        pub const T = str;
    };
}

const HlExpect = Expect(fn (line: i16, startCol: i16, endCol: i16, hl: i16) void);
pub fn box_context_highlight(ctx: u16, L: HlExpect) !void {
    const context = try get_context(ctx);
    context.highlight(L.L, 2, 0);
}

pub fn box_shift_right_by(ctx: u16, boxid: u16, extra: u16) !void {
    const box = try get_box(ctx, boxid);
    try box.shiftRightwardsBy(extra);
}

// new box from ctx {
pub fn box_new_from_context(ctx: u16, hlgroup: Highlight) !u16 {
    const context = try get_context(ctx);
    const ret = try context.newBox(Box.newBoxFromContext(ctx, hlgroup));
    return @intCast(ret);
}
// }

// new box from offset {
pub fn box_new_from_offset(ctx: u16, box: u16, x: u16, y: u16) !u16 {
    const self = try get_box(ctx, box);
    const context = try get_context(self.context);
    const ret = try context.newBox(self.newBoxFromOffset(x, y));
    return @intCast(ret);
}
// }

// new box right {
pub fn box_new_right_from(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    const context = try get_context(self.context);
    const ret = try context.newBox(self.newBoxRightOf());
    return @intCast(ret);
}

pub fn box_new_below_from(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    const context = try get_context(self.context);
    const ret = try context.newBox(self.newBoxBelow());
    return @intCast(ret);
}

pub fn box_new_cursored(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    const context = try get_context(self.context);
    const ret = try context.newBox(self.newBoxCursored());
    return @intCast(ret);
}
// }

// prettry sure this is only used for canvas
pub fn box_shrink_width_to(ctx: u16, box: u16, width: u16) !void {
    const self = try get_box(ctx, box);
    try self.shrinkWidthTo(width);
}

pub fn box_update_cursor_from(ctx: u16, box: u16, other: u16) !void {
    const self = try get_box(ctx, box);
    const otherBox = try get_box(ctx, other);
    self.updateCursorFrom(otherBox);
}
pub fn box_set_width(ctx: u16, box: u16, width: u16) !void {
    const self = try get_box(ctx, box);
    try self.setWidth(width);
}
pub fn box_get_offset_y(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    return self.offsetY;
}
pub fn box_get_offset_x(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    return self.offsetX;
}
pub fn box_get_cursor_y(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    return self.cursorY;
}
pub fn box_get_cursor_x(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    return self.cursorX;
}

pub fn box_get_hl(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    return self.hlgroup;
}
pub fn box_get_max_width(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    return self.maxWidth;
}
pub fn box_get_max_height(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    return self.maxHeight;
}

pub fn box_set_max_width(ctx: u16, box: u16, width: i16) !void {
    const self = try get_box(ctx, box);
    self.maxWidth = @max(width, 0);
}
pub fn box_set_max_height(ctx: u16, box: u16, height: i16) !void {
    const self = try get_box(ctx, box);
    self.maxHeight = @max(height, 0);
}
pub fn box_get_width(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    return @intCast(self.width);
}
pub fn box_expand_width_to(ctx: u16, box: u16, width: u16) !void {
    const self = try get_box(ctx, box);
    try self.expandWidthTo(width);
}

pub fn box_expand_height_to(ctx: u16, box: u16, height: u16) !void {
    const self = try get_box(ctx, box);
    try self.expandHeightTo(height);
}
pub fn box_shrink_height_to(ctx: u16, box: u16, height: u16) !void {
    const self = try get_box(ctx, box);
    try self.shrinkHeightTo(height);
}

pub fn box_set_height(ctx: u16, box: u16, height: u16) !void {
    const self = try get_box(ctx, box);
    try self.setHeight(height);
}

pub fn box_get_height(ctx: u16, box: u16) !u16 {
    const self = try get_box(ctx, box);
    return @intCast(self.height);
}

pub fn box_clean(ctx: u16, box: u16) !void {
    const self = try get_box(ctx, box);
    try self.clean();
}

// *kinda* one of the most needed low level apis
// append str {
pub fn box_append_str(ctx: u16, box: u16, str: []const u8) !void {
    const self = try get_box(ctx, box);
    try self.appendStr(str);
}
// }

// set hl {
pub fn box_set_hl(ctx: u16, box: u16, style: u16) !void {
    const self = try get_box(ctx, box);
    self.hlgroup = style;
}
// }

pub fn box_append_word(ctx: u16, box: u16, str: []const u8, style: Highlight) !void {
    const self = try get_box(ctx, box);
    try self.appendWord(str, style);
}

pub fn box_overlay(ctx: u16, box: u16, x: u16, y: u16, w: u16, h: u16, char: []const u8, style: Highlight) !void {
    const self = try get_box(ctx, box);
    try self.overlay(x, y, w, h, char, style);
}

const StripRightExpect = Expect(fn (hl: Highlight) u16);
pub fn box_context_strip_right_space(ctx: u16, expected_bg: StripRightExpect) !void {
    const context = try get_context(ctx);
    try context.stripRightSpace(expected_bg.L, lua.get_top(expected_bg.L));
}

pub fn box_render_over(ctx: u16, box: u16, otherCtx: u16, left: u16, top: u16) !void {
    const self = try get_box(ctx, box);
    const context = try get_context(otherCtx);
    try self.renderOver(context, left, top);
}
