const std = @import("std");
const lua = @import("lua.zig");
pub const Reg = extern struct {
    name: [*:0]allowzero const u8,
    func: lua.CFunction,
    pub const Null: Reg = .{ .name = @ptrFromInt(0), .func = @ptrFromInt(0) };

    pub fn init(name: [*:0]allowzero const u8, func: lua.CFunction) Reg {
        return .{
            .name = name,
            .func = func,
        };
    }
};

extern fn luaL_register(L: *lua.State, libname: [*:0]const u8, l: [*]const Reg) callconv(.C) void;

pub const register = luaL_register;

extern fn luaL_error(L: *lua.State, fmt: [*:0]const u8, ...) c_int;
