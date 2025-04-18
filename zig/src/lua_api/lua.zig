const std = @import("std");
pub const State = extern struct {};

pub const CFunction = *allowzero const fn (L: *State) callconv(.C) c_int;

pub const Number = f64;

extern fn lua_gettop(L: *State) callconv(.C) c_int;
pub const get_top = lua_gettop;

// stack get functions {
extern fn lua_tonumber(L: *State, index: c_int) callconv(.C) Number;
pub const to_number = lua_tonumber;
pub fn to_int(L: *State, index: c_int) i64 {
    return @intFromFloat(to_number(L, index));
}
pub fn to_cast_int(L: *State, index: c_int, tp: type) tp {
    return @as(tp, @intFromFloat(to_number(L, index)));
}

extern fn lua_tostring(L: *State, index: c_int) callconv(.C) [*:0]const u8;
extern fn lua_tolstring(L: *State, index: c_int, len: *usize) callconv(.C) [*:0]const u8;
pub const to_string = lua_tostring;
pub const to_lstring = lua_tolstring;
pub fn to_slice(L: *State, index: c_int) []const u8 {
    var len: usize = 0;
    const chars = to_lstring(L, index, &len);
    return chars[0..len];
}
extern fn lua_topointer(L: *State, index: c_int) callconv(.C) *const anyopaque;
pub const to_pointer = lua_topointer;
extern fn lua_touserdata(L: *State, index: c_int) callconv(.C) *anyopaque;
pub const to_userdata = lua_touserdata;
// }

// stack checking functions {
extern fn lua_isboolean(L: *State, index: c_int) callconv(.C) c_int;
pub fn is_bool(L: *State, index: c_int) bool {
    return lua_isboolean(L, index) != 0;
}
extern fn lua_isnil(L: *State, index: c_int) callconv(.C) c_int;
pub fn is_nil(L: *State, index: c_int) bool {
    return lua_isnil(L, index) != 0;
}
extern fn lua_isnone(L: *State, index: c_int) callconv(.C) c_int;
pub fn is_none(L: *State, index: c_int) bool {
    return lua_isnone(L, index) != 0;
}
extern fn lua_isnumber(L: *State, index: c_int) callconv(.C) c_int;
pub fn is_number(L: *State, index: c_int) bool {
    return lua_isnumber(L, index) != 0;
}
extern fn lua_isstring(L: *State, index: c_int) callconv(.C) c_int;
pub fn is_string(L: *State, index: c_int) bool {
    return lua_isstring(L, index) != 0;
}
extern fn lua_iscfunction(L: *State, index: c_int) callconv(.C) c_int;
pub fn is_cfunction(L: *State, index: c_int) bool {
    return lua_iscfunction(L, index) != 0;
}
// extern fn lua_isfunction(L: *State, index: c_int) callconv(.C) c_int;
// pub fn is_function(L: *State, index: c_int) bool {
//     return lua_isfunction(L, index) != 0;
// }
extern fn lua_isuserdata(L: *State, index: c_int) callconv(.C) c_int;
pub fn is_userdata(L: *State, index: c_int) bool {
    return lua_isuserdata(L, index) != 0;
}
extern fn lua_isnoneornil(L: *State, index: c_int) callconv(.C) c_int;
pub fn is_noneornil(L: *State, index: c_int) bool {
    return lua_isnoneornil(L, index) != 0;
}
extern fn lua_istable(L: *State, index: c_int) callconv(.C) c_int;
pub fn is_table(L: *State, index: c_int) bool {
    return lua_istable(L, index) != 0;
}
extern fn lua_isthread(L: *State, index: c_int) callconv(.C) c_int;
pub fn is_thread(L: *State, index: c_int) bool {
    return lua_isthread(L, index) != 0;
}
// }

// stach pushing functions {
extern fn lua_pushvalue(L: *State, index: c_int) callconv(.C) void;
pub const push_value = lua_pushvalue;
extern fn lua_pushlightuserdata(L: *State, ptr: *anyopaque) callconv(.C) void;
pub const push_lightuserdata = lua_pushlightuserdata;

extern fn lua_pushnumber(L: *State, n: Number) callconv(.C) void;
pub const push_number = lua_pushnumber;
pub fn push_int(L: *State, n: c_int) void {
    push_number(L, @floatFromInt(n));
}

extern fn lua_pushboolean(L: *State, n: c_int) callconv(.C) void;
pub const push_boolean = lua_pushboolean;
pub fn push_bool(L: *State, n: bool) void {
    push_boolean(L, @intFromBool(n));
}
// }

extern fn lua_call(L: *State, nargs: c_int, nresults: c_int) callconv(.C) void;
pub const call = lua_call;
