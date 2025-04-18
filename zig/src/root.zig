const std = @import("std");
const lua = @import("lua_api/lua.zig");
const luaL = @import("lua_api/luaL.zig");
const b4 = @import("box4.zig");
const grid = @import("grid.zig");
const testing = std.testing;

export fn add(a: i32, b: i32) i32 {
    return a + b;
}

// NOTE: array MUST end with null
pub const regs = [_]luaL.Reg{
    luaL.Reg.init("box_context_create", b4.lua_new_context),
    luaL.Reg.init("box_context_delete", b4.lua_delete_context),
    luaL.Reg.init("box_context_exists", b4.lua_context_exists),
    luaL.Reg.init("box_context_render", b4.lua_context_render),
    luaL.Reg.init("box_context_highlight", b4.lua_context_highlight),
    luaL.Reg.init("box_new_from_context", b4.lua_new_from_ctx),
    luaL.Reg.init("box_new_from_offset", b4.lua_new_from_offset),
    luaL.Reg.init("box_new_right_from", b4.lua_new_right),
    luaL.Reg.init("box_append_str", b4.lua_append_str),
    luaL.Reg.init("box_set_hl", b4.lua_set_hl),
    luaL.Reg.init("grid_getNew", grid.lua_getNew),
    luaL.Reg.init("grid_turnOnRange", grid.lua_turnOnRange),
    luaL.Reg.init("grid_isEnabled", grid.lua_isEnabled),
    luaL.Reg.init("grid_freeSection", grid.lua_freeSection),
    .Null,
};

export fn luaopen_banana_libbanana(state: *lua.State) c_int {
    luaL.register(state, "libbanana", &regs);
    return 1;
}

export fn addToString(str: [*:0]u8) void {
    var i: u8 = 0;
    while (str[i] != 0) {
        if (str[i] >= '0' and str[i] <= '9') {
            str[i] += 1;
        }
        i += 1;
    }
}

export fn contextThing() void {
    var ctx = b4.BoxContext.init(std.heap.page_allocator);
    defer ctx.deinit();

    var box = b4.Box.newBoxFromContext(&ctx, 0);
    box.appendStr(@as([]const u8, "asdf")) catch return;
}

test "basic add functionality" {
    try testing.expect(add(3, 7) == 10);
}
