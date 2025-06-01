const std = @import("std");
const dst = @import("dst.zig");
const log = @import("log.zig");
const lua = @import("lua_api/lua.zig");
const luaL = @import("lua_api/luaL.zig");
const Box = @import("box/api.zig");
const grid = @import("grid.zig");
const gen = @import("genlua.zig");
const testing = std.testing;

// pub const panic: type = std.debug.FullPanic(
//     struct {
//         pub fn panic(
//             msg: []const u8,
//             first_trace_addr: ?usize,
//         ) noreturn {
//             defer std.process.exit(1);
//             const logfile = try std.fs.cwd().createFile("panic.txt", .{});
//             defer logfile.close();
//             _ = try logfile.write(msg);
//             _ = try logfile.write("\r\n");
//             _ = first_trace_addr;
//         }
//     }.panic,
// );

pub fn panic(msg: []const u8, trace: ?*std.builtin.StackTrace, third: anytype) noreturn {
    defer std.process.exit(1);
    const logfile = try std.fs.cwd().createFile("panic.txt", .{});
    defer logfile.close();
    _ = try logfile.write("AUGGGGHHGG");
    _ = try logfile.write("\r\n");
    _ = try logfile.write(msg);
    _ = try logfile.write("\r\n");

    try log.write("AUGGHHGHGH PANIC!!!\n", .{});
    try log.write("PANIC REASON: {s}\n", .{msg});

    if (trace) |stack_trace| {
        _ = try logfile.write("EVERYONE STOP WE HAVE A TRACE!!!");
        _ = try logfile.write("\r\n");
        std.debug.dumpStackTrace(stack_trace.*);
    }
    _ = third;
    // if(trace) |t| {
    //
    // }
}

// pub export const decls = gen.genLuaDecls(Box, "box_");

export fn add(a: i32, b: i32) i32 {
    return a + b;
}

// NOTE: array MUST end with null
pub const regs = [_]luaL.Reg{
    luaL.Reg.init("box_context_create", Box.lua_new_context),
    luaL.Reg.init("box_context_delete", Box.lua_delete_context),
    luaL.Reg.init("box_context_exists", Box.lua_context_exists),
    luaL.Reg.init("box_context_render", Box.lua_context_render),
    // luaL.Reg.init("box_context_highlight", Box.lua_context_highlight),
    luaL.Reg.init("box_new_from_context", Box.lua_new_from_ctx),
    luaL.Reg.init("box_new_from_offset", Box.lua_new_from_offset),
    luaL.Reg.init("box_new_right_from", Box.lua_new_right),
    luaL.Reg.init("box_append_str", Box.lua_append_str),
    luaL.Reg.init("box_set_hl", Box.lua_set_hl),
    luaL.Reg.init("grid_getNew", grid.lua_getNew),
    luaL.Reg.init("grid_turnOnRange", grid.lua_turnOnRange),
    luaL.Reg.init("grid_isEnabled", grid.lua_isEnabled),
    luaL.Reg.init("grid_freeSection", grid.lua_freeSection),
    .Null,
};

var list: std.ArrayListUnmanaged(luaL.Reg) = .empty;

// pub const regs = gen.genLuaDecls(Box, "box_");

export fn luaopen_banana_libbanana(state: *lua.State) c_int {
    const alloc = std.heap.smp_allocator;
    // const file = std.fs.cwd().openFile("thing.txt", .{ .mode = .write_only }) catch return 0;
    // _ = file.write("opening :)\n") catch 0;
    const fns = gen.genLuaDecls(Box, "box_");
    inline for (fns) |f| {
        // std.debug.print("{s}\n", .{f.name});
        // _ = file.write(std.fmt.allocPrint(alloc, "name {s}\n", .{f.name}) catch "asdf") catch 0;
        const newName = alloc.dupeZ(u8, f.name) catch return 0;
        const function = luaL.Reg.init(newName, f.f);
        list.append(
            alloc,
            function,
        ) catch return 0;
    }
    const gridFns = gen.genLuaDecls(grid, "grid_");
    inline for (gridFns) |f| {
        // std.debug.print("{s}\n", .{f.name});
        // _ = file.write(std.fmt.allocPrint(alloc, "name {s}\n", .{f.name}) catch "asdf") catch 0;
        const newName = alloc.dupeZ(u8, f.name) catch return 0;
        const function = luaL.Reg.init(newName, f.f);
        list.append(
            alloc,
            function,
        ) catch return 0;
    }
    const dstFns = gen.genLuaDecls(dst, "dst_");
    inline for (dstFns) |f| {
        // std.debug.print("{s}\n", .{f.name});
        // _ = file.write(std.fmt.allocPrint(alloc, "name {s}\n", .{f.name}) catch "asdf") catch 0;
        const newName = alloc.dupeZ(u8, f.name) catch return 0;
        const function = luaL.Reg.init(newName, f.f);
        list.append(
            alloc,
            function,
        ) catch return 0;
    }
    list.append(alloc, luaL.Reg.Null) catch return 0;
    // const alloc = alloc;
    // var arr: std.ArrayListUnmanaged(lua.CFunction) = .empty;
    // gen.genLuaDecls(Box, "box_", &arr, alloc) catch return 0;
    luaL.register(state, "libbanana", list.items.ptr);

    // Box.init_boxes();

    log.init() catch return 1;

    // luaL.register(state, "libbanana", &regs);
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

test "basic add functionality" {
    try testing.expect(add(3, 7) == 10);
}
