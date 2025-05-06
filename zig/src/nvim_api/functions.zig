const tp = @import("./types.zig");

// nvim_strwidth doesnt work on slices
pub extern fn nvim_strwidth(str: tp.String, err: *tp.Error) callconv(.C) tp.Integer;
// vim_strwidth does tho ig
pub extern fn vim_strwidth(str: tp.String, err: *tp.Error) callconv(.C) tp.Integer;

pub fn z_nvim_strwidth(str: []const u8) tp.NvimError!tp.Integer {
    var err = tp.Error{ .type = .None, .msg = @ptrFromInt(0) };

    const ret = vim_strwidth(tp.String.fromSlice(str), &err);

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

pub fn codepointLen(byte: u8) u8 {
    if (byte < 128) {
        return 1;
    } else if (byte < 224) {
        return 2;
    } else if (byte < 240) {
        return 3;
    } else {
        return 4;
    }
}

pub fn sliceToWidth(str: []const u8, maxWidth: u32) tp.NvimError![]const u8 {
    var width: u32 = 0;
    var i: u32 = 0;
    while (width <= maxWidth) {
        if (i >= str.len) {
            i = @intCast(str.len);
        }
        const byteWidth = codepointLen(str[i]);
        const slice = str[i .. i + byteWidth];
        const charWidth = try z_nvim_strwidth(slice);
        if (charWidth + width > maxWidth) {
            break;
        }
        width += @intCast(charWidth);
        i += 1;
    }
    return str[0..i];
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
