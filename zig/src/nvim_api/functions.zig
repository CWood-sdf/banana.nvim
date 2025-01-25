const tp = @import("./types.zig");

pub extern fn nvim_strwidth(str: tp.String, err: *tp.Error) callconv(.C) tp.Integer;

pub fn z_nvim_strwidth(str: []u8, errmsg: *[*]allowzero const u8) tp.ZError!tp.Integer {
    const err = tp.Error{ .type = .None, .msg = 0 };

    const ret = nvim_strwidth(tp.String.fromSlice(str), &err);

    if (err.type != .None) {
        errmsg.* = err.msg;
        return err.type;
    }
    return ret;
}
