const std = @import("std");
const lua = @import("lua_api/lua.zig");
const luaL = @import("lua_api/luaL.zig");

pub fn luaReturn(L: *lua.State, v: anytype) c_int {
    switch (@typeInfo(@TypeOf(v))) {
        .int => {
            lua.push_int(L, v);
        },
        .bool => {
            lua.push_bool(L, v);
        },
        else => {
            @compileError(std.fmt.comptimePrint("Cant return type {}\n", .{v}));
        },
    }
    return 1;
}

pub fn pushValue(L: *lua.State, v: anytype) void {
    const info = @typeInfo(@TypeOf(v));
    switch (info) {
        .int => {
            lua.push_int(L, @intCast(v));
        },
        .bool => {
            lua.push_bool(L, v);
        },
        .float => {
            lua.push_number(L, v);
        },
        .pointer => |p| {
            if (p.size == .slice) {
                lua.push_stringslice(L, v);
            } else if (p.size == .one) {
                lua.push_lightuserdata(L, v);
            }
        },
        .optional => |o| {
            std.debug.assert(isPointer(o.child));

            lua.push_lightuserdata(L, @ptrCast(v));
        },
        else => {
            @compileError(std.fmt.comptimePrint("Cant push type {}\n", .{@TypeOf(v)}));
        },
    }
}

pub fn toLuaType(tp: type) lua.Type {
    const info = @typeInfo(tp);
    switch (info) {
        .int, .float => {
            return .number;
        },
        .bool => {
            return .bool;
        },
        else => {
            return .table;
        },
    }
}
pub fn parseParam(L: *lua.State, index: c_int, tp: type, failReturn: anytype) !tp {
    const info = @typeInfo(tp);
    errdefer {
        const failInfo = @typeInfo(@TypeOf(failReturn));
        switch (failInfo) {
            .null => {
                _ = lua.push_fmtstring(
                    L,
                    "Expected type {} but got type {} in parameter {}",
                    .{ toLuaType(tp), lua.gettype(L, index), index },
                );
                _ = lua.senderror(L);
            },
            else => {
                pushValue(L, failReturn);
            },
        }
    }
    switch (info) {
        .int => {
            if (!lua.is_number(L, index)) {
                return error.IncorrectType;
            }

            return lua.to_cast_int(L, index, tp);
        },
        .bool => {
            if (!lua.is_bool(L, index)) {
                return error.IncorrectType;
            }
            return lua.to_bool(L, index, tp);
        },
        .float => {
            if (!lua.is_number(L, index)) {
                return error.IncorrectType;
            }
            return lua.to_number(L, index, tp);
        },
        .pointer => |p| {
            if (p.size == .slice) {
                if (!lua.is_string(L, index)) {
                    return error.IncorrectType;
                }
                return lua.to_slice(L, index);
            } else {
                if (!lua.is_userdata(L, index)) {
                    return error.IncorrectType;
                }
                return @ptrCast(@alignCast(lua.to_userdata(L, index)));
            }
        },
        else => {
            @compileError(std.fmt.comptimePrint("Cant parse parameter type {}\n", .{tp}));
        },
    }
}

pub fn isStruct(tp: type) bool {
    const info = @typeInfo(tp);
    switch (info) {
        .@"struct" => return true,
        else => return false,
    }
}
pub fn isPointer(tp: type) bool {
    const info = @typeInfo(tp);
    switch (info) {
        .pointer => return true,
        else => return false,
    }
}
pub fn isInt(tp: type) bool {
    const info = @typeInfo(tp);
    switch (info) {
        .int => return true,
        else => return false,
    }
}
pub fn isZeroPointer(tp: type) bool {
    const info = @typeInfo(tp);
    switch (info) {
        .optional => |o| return isPointer(o.child),
        .pointer => return true,
        else => return false,
    }
}

pub fn luaTemplate(
    L: *lua.State,
    fToCall: anytype,
    comptime name: []const u8,
    // failReturn: anytype,
) c_int {
    const f = @typeInfo(@TypeOf(fToCall)).@"fn";
    comptime var paramLen = 0;
    comptime var i = 0;
    comptime var tupleFields: [f.params.len]type = undefined;
    inline for (f.params) |param| {
        const tp = param.type.?;
        const info = @typeInfo(tp);

        switch (info) {
            .bool, .float, .int => {
                tupleFields[i] = tp;
                i += 1;
                paramLen += 1;
            },
            .@"struct" => |_| {
                if (!@hasField(tp, "L")) {
                    @compileError("struct parameters have to have isLua field");
                }
                tupleFields[i] = tp;
                i += 1;
                paramLen += 1;
            },
            .pointer => |p| {
                if (p.child == u8) {
                    if (p.size != .slice) {
                        @compileError(std.fmt.comptimePrint("Pointer type must be []const u8, instead got {}, from type {}\n", .{ p.size, tp }));
                    }
                    tupleFields[i] = []const u8;
                    i += 1;
                    paramLen += 1;
                } else {
                    if (p.size != .one) {
                        @compileError(std.fmt.comptimePrint(
                            "Pointers must be one sized, instead got {}\n",
                            .{p.size},
                        ));
                    }
                    tupleFields[i] = tp;
                    i += 1;
                    paramLen += 1;
                }
                // @compileLog(std.fmt.comptimePrint("{} yo", .{f.params.len}));
                // if (p.sentinel() != 0) {
                //     @compileError(std.fmt.comptimePrint("Pointer sentinel must be 0, instead got {?} from type {}\n", .{ p.sentinel(), tp }));
                // }
                // tupleFields[i] = u32;
                // i += 1;
                // paramLen += 1;
            },
            .optional => |o| {
                comptime std.debug.assert(isPointer(o.child));
            },
            else => {
                @compileError(std.fmt.comptimePrint("Something something {}, {s}\n", .{ tp, name }));
            },
        }
    }
    const args = lua.get_top(L);
    if (args != i) {
        _ = lua.push_fmtstring(L, "yo you put in the wrong number of parameters. expected {}, got {}", .{ i, args });
        _ = lua.senderror(L);
        // pushValue(L, failReturn);
        // lua.push_bool(L, false);
        return 1;
    }
    const tupleTp = std.meta.Tuple(tupleFields[0..i]);
    var tuple: tupleTp = undefined;
    const tupleInfo = @typeInfo(tupleTp).@"struct";
    inline for (tupleInfo.fields, 1..) |field, j| {
        if (field.type == []const u8) {
            const slice = parseParam(L, j, []const u8, null) catch return 1;
            @field(tuple, field.name) = slice;
        } else if (comptime isStruct(field.type) and @hasField(field.type, "L")) {
            @field(tuple, field.name) = .{ .L = L };
        } else {
            @field(tuple, field.name) = parseParam(L, j, field.type, null) catch return 1;
        }
    }
    // if (nextLen != null) {
    //     @compileError("Expected an int field after a [*]const u8 field");
    // }
    const ret = @call(.auto, fToCall, tuple);
    if (@TypeOf(ret) == void) {
        return 0;
    }
    pushValue(L, ret);
    // lua.push_bool(L, ret);
    return 1;
}
//
// pub const RegInfo = struct {
//
// };

pub const FnInfo = struct {
    name: []const u8,
    f: lua.CFunction,
    params: @FieldType(std.builtin.Type.Fn, "params"),
    ret: type,
};
pub fn genLuaDecls(
    scope: type,
    comptime prefix: []const u8,
    // arr: *std.ArrayListUnmanaged(lua.CFunction),
    // alloc: std.mem.Allocator,
) []const FnInfo {
    const infoPre = @typeInfo(scope);

    const info = switch (infoPre) {
        .@"struct" => |s| s,
        else => @compileError("Must pass a struct type to genLuaDecls"),
    };

    const methods = info.decls;

    var ret: [methods.len]FnInfo = undefined;
    comptime var i = 0;

    inline for (methods) |method| {
        if (method.name.len > prefix.len and comptime std.mem.eql(u8, method.name[0..prefix.len], prefix)) {
            const fnInfo = @typeInfo(@TypeOf(@field(scope, method.name))).@"fn";

            if (fnInfo.return_type == bool or comptime isInt(fnInfo.return_type.?) or isZeroPointer(fnInfo.return_type.?) or fnInfo.return_type == void) {
                const newThing = struct {
                    // pub const fInfo = fnInfo;

                    pub fn actualFn(L: *lua.State) callconv(.C) c_int {
                        // std.debug.print("{s}\n", .{method.name});
                        const r = luaTemplate(
                            L,
                            @field(scope, method.name),
                            method.name,
                        );
                        return r;
                    }
                };
                ret[i] = .{
                    .f = newThing.actualFn,
                    .name = method.name,
                    .ret = fnInfo.return_type.?,
                    .params = fnInfo.params,
                };
                i += 1;
            } else {
                @compileError(std.fmt.comptimePrint(
                    "Unusable return type {} while parsing function {s}\n",
                    .{ fnInfo.return_type.?, method.name },
                ));
            }
        }
        // functions[i] = newThing.actualFn;
    }
    // ret[i + 1] = .Null;
    return ret[0..i];
    // return functions[0..i];
}
