const tp = @import("./types.zig");

pub extern fn nvim_strwidth(str: tp.String, err: *tp.Error) callconv(.C) tp.Integer;
