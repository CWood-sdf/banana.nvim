const PrLists = GenPrLists();
const PartialRendered = @import("PartialRendered.zig");
const RenderAlign = PartialRendered.RenderAlign;
const RenderType = PartialRendered.RenderType;
const std = @import("std");
const PrDataStack = @This();
const BoxContext = @import("BoxContext.zig");

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
