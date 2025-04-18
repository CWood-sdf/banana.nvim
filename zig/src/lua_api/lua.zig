pub const State = extern struct {};

pub const CFunction = *allowzero const fn (L: *State) callconv(.C) c_int;

pub const Number = f64;

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

extern fn lua_gettop(L: *State) callconv(.C) c_int;
pub const get_top = lua_gettop;

extern fn lua_tonumber(L: *State, index: c_int) callconv(.C) Number;
pub const to_number = lua_tonumber;
pub fn to_int(L: *State, index: c_int) i64 {
    return @intFromFloat(to_number(L, index));
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
