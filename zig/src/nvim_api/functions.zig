const tp = @import("./types.zig");

pub extern fn nvim_strwidth(str: tp.String, err: *tp.Error) callconv(.C) tp.Integer;

pub fn z_nvim_strwidth(str: []const u8) tp.NvimError!tp.Integer {
    var err = tp.Error{ .type = .None, .msg = @ptrFromInt(0) };

    const ret = nvim_strwidth(tp.String.fromSlice(str), &err);

    // if (err.type != .None) {
    //     errmsg.* = err.msg;
    // }
    if (err.type != .None) {
        switch (err.type) {
            .Exception => return tp.NvimError.Exception,
            .Validation => return tp.NvimError.Validation,
            else => {},
        }
    }
    return ret;
}

pub extern fn nvim_buf_set_lines(
    channel_id: u64,
    buf: tp.Buffer,
    start: i64,
    end: i64,
    strict_indexing: bool,
    replacement: tp.Array,
    arena: *tp.Arena,
    err: *tp.Error,
) void;

pub extern fn nvim_buf_add_highlight(
    buf: tp.Buffer,
    ns_id: tp.Integer,
    hl_group: tp.String,
    line: tp.Integer,
    col_start: tp.Integer,
    col_end: tp.Integer,
    err: *tp.Error,
) tp.Integer;

pub extern fn nvim_buf_clear_namespace(
    buf: tp.Buffer,
    ns_id: tp.Integer,
    line_start: tp.Integer,
    line_end: tp.Integer,
    err: *tp.Error,
) void;
