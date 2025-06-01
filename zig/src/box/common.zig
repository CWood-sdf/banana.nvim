const fns = @import("../nvim_api/functions.zig");
const lua = @import("../lua_api/lua.zig");
const std = @import("std");
const BoxContext = @import("BoxContext.zig");
const Box = @import("Box.zig");
const PartialRendered = @import("PartialRendered.zig");
const log = @import("../log.zig");

pub var contexts: std.ArrayListUnmanaged(?BoxContext) = .empty;
pub fn get_context(ctx: u16) !*BoxContext {
    // dumpContexts();
    if (ctx >= contexts.items.len) {
        return error.ContextNotFound;
    }
    if (contexts.items[ctx]) |*c| return c;
    return error.ContextNotFound;
}

pub fn get_box(ctx: u16, box: u16) !*Box {
    const context = try get_context(ctx);
    const b = context.getBox(box) orelse return error.BoxNotFound;
    // const indent = "  ";
    log.write("  Getting box {}:{}\n", .{ ctx, box }) catch {};
    // dumpStruct(b.*, indent[0..]);
    return b;
}
pub fn get_partial(ctx: u16, partial: u16) !*PartialRendered {
    const context = try get_context(ctx);
    const ret = context.getPartial(partial) orelse return error.PartialNotFound;
    // const indent = "  ";
    log.write("  Getting partial {}:{}\n", .{ ctx, partial }) catch {};
    // dumpStruct(ret.*, indent[0..]);
    return ret;
}
pub fn subOr(l: anytype, r: anytype, default: anytype) @TypeOf(l) {
    comptime if (@TypeOf(l) != @TypeOf(r) and @TypeOf(r) != comptime_int) {
        @compileError(std.fmt.comptimePrint(
            "Got two different types to safeSubtract: l={} r={}\n",
            .{ @TypeOf(l), @TypeOf(r) },
        ));
    };
    comptime if (@TypeOf(l) != @TypeOf(default) and @TypeOf(default) != comptime_int) {
        @compileError(std.fmt.comptimePrint(
            "Got two different types to safeSubtract: l={} default={}\n",
            .{ @TypeOf(l), @TypeOf(default) },
        ));
    };

    const T = @TypeOf(l);

    if (comptime @typeInfo(T).int.signedness == .unsigned) {
        if (r > l) {
            return default;
        }
    }
    return l - r;
}
pub fn subMultOr(comptime T: type, l: []const T, comptime default: T) T {
    return subMult(T, l) catch default;
}
pub fn subMult(comptime T: type, l: []const T) !T {
    if (l.len == 0) {
        return error.EmptyArray;
    }
    var ret: T = l[0];
    for (1..l.len) |i| {
        if (comptime @typeInfo(T).int.signedness == .unsigned) {
            if (l[i] > ret) {
                return error.UnsignedSubtractToNegative;
            }
        }
        ret -= l[i];
    }
    return ret;
}
pub fn sub(l: anytype, r: anytype) !@TypeOf(l) {
    // comptime if (@TypeOf(l) != @TypeOf(r)) {
    //     @compileError(std.fmt.comptimePrint(
    //         "Got two different types to safeSubtract: {} {}\n",
    //         .{ @TypeOf(l), @TypeOf(r) },
    //     ));
    // };

    const T = @TypeOf(l);

    if (comptime @typeInfo(T).int.signedness == .unsigned) {
        if (r > l) {
            return error.UnsignedSubtractToNegative;
        }
    }
    return l - r;
}

pub const Highlight = u16;

pub const Id = u16;

pub const NullableId = struct {
    const Self = @This();
    value: i16,

    pub const nil: Self = .{ .value = -1 };

    pub fn isNull(self: *const Self) bool {
        return self.value < 0;
    }

    pub fn asOptional(self: *const Self) ?u15 {
        if (self.value > 0) {
            return @intCast(self.value);
        }
        return null;
    }

    pub fn set(self: *Self, value: ?u16) void {
        if (value) |val| {
            self.value = @intCast(val);
        } else {
            self.value = -1;
        }
    }

    pub fn init(value: ?u16) Self {
        if (value) |v| {
            return .{
                .value = @intCast(v),
            };
        } else {
            return .{
                .value = -1,
            };
        }
    }
};

const RealNum = i16;

pub fn charwidth(chars: []const u8) !u8 {
    if (chars.len > 4) {
        return error.StrTooBig;
    }
    var byteArr = [_]u8{0} ** 5;
    for (chars, 0..) |c, i| {
        byteArr[i] = c;
    }
    return @intCast(try fns.z_nvim_strwidth(byteArr[0..chars.len]));
}

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

pub fn dumpStruct(obj: anytype, indent: []const u8) void {
    const st = @typeInfo(@TypeOf(obj)).@"struct";
    inline for (st.fields) |field| {
        switch (@typeInfo(@FieldType(@TypeOf(obj), field.name))) {
            .@"struct" => {},
            else => {
                log.write("{s}.{s} = {any}\n", .{ indent, field.name, @field(obj, field.name) }) catch {};
            },
        }
    }
}

pub fn dumpContexts() void {
    log.write("  ctx ptr: {*}\n", .{contexts.items.ptr}) catch {};
    for (contexts.items, 0..) |ctxn, i| {
        if (ctxn) |ctx| {
            log.write("    ctx {} is not null\n", .{i}) catch {};
            log.write("      .memusage = {}\n", .{ctx.arena.queryCapacity()}) catch {};
            log.write("      .boxes = {*}\n", .{ctx.boxes.items.ptr}) catch {};
            const indent = "          ";
            for (ctx.boxes.items, 0..) |box, j| {
                log.write("      .boxes[{}] = \n", .{j}) catch {};
                dumpStruct(box, indent[0..]);
            }
            log.write("      .partials = {*}\n", .{ctx.partials.items.ptr}) catch {};
            for (ctx.partials.items, 0..) |partial, j| {
                log.write("        .partials[{}] = \n", .{j}) catch {};
                dumpStruct(partial, indent[0..]);
            }
            // log.write("    .lines = {*}\n", .{ctx.lines.items.ptr}) catch {};
            // for (ctx.lines.items, 0..) |line, j| {
            //     log.write("      .lines[{}] = (widths {}, {})\n", .{
            //         j,
            //         line._chars.items.len,
            //         line._hls.items.len,
            //     }) catch {};
            //     // dumpStruct(line, indent[0..]);
            // }
            log.write("    .partialData = {*}\n", .{&ctx.partialData}) catch {};
            inline for (@typeInfo(@FieldType(@TypeOf(ctx.partialData), "fields")).@"struct".fields) |field| {
                const arr = @field(ctx.partialData.fields, field.name);
                log.write("      .{s} = [{}] {any}\n", .{
                    field.name,
                    arr.items.len,
                    arr.items,
                }) catch {};
                // dumpStruct(line, indent[0..]);
            }
        } else {
            log.write("    ctx {} is null\n", .{i}) catch {};
        }
        break;
    }
}
