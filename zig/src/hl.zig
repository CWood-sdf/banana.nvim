const std = @import("std");
const tp = @import("nvim_api/types.zig");
const zero = std.mem.zeroes;

pub const RgbValue = i32;
pub const HlAttrFlags = enum(u16) {
    INVERSE = 0x01,
    BOLD = 0x02,
    ITALIC = 0x04,
    // The next three bits are all underline styles
    UNDERLINE_MASK = 0x38,
    UNDERLINE = 0x08,
    UNDERCURL = 0x10,
    UNDERDOUBLE = 0x18,
    UNDERDOTTED = 0x20,
    UNDERDASHED = 0x28,
    // 0x30 and 0x38 spare for underline styles
    STANDOUT = 0x0040,
    STRIKETHROUGH = 0x0080,
    ALTFONT = 0x0100,
    // 0x0200 spare
    NOCOMBINE = 0x0400,
    BG_INDEXED = 0x0800,
    FG_INDEXED = 0x1000,
    DEFAULT = 0x2000,
    GLOBAL = 0x4000,
};
pub const OptionalKeys = u64;
pub const HLGroupID = enum(tp.Integer) { _ };
pub const Masks = struct {
    const bg = 1;
    const fg = 2;
    const sp = 3;
    const url = 4;
    const bold = 5;
    const link = 6;
    const blend = 7;
    const cterm = 8;
    const force = 9;
    const italic = 10;
    const special = 11;
    const ctermbg = 12;
    const ctermfg = 13;
    const default = 14;
    const altfont = 15;
    const reverse = 16;
    const fallback = 17;
    const standout = 18;
    const nocombine = 19;
    const undercurl = 20;
    const underline = 21;
    const background = 22;
    const bg_indexed = 23;
    const foreground = 24;
    const fg_indexed = 25;
    const global_link = 26;
    const underdashed = 27;
    const underdotted = 28;
    const underdouble = 29;
    const strikethrough = 30;
};
pub const HlAttrs = extern struct {
    is_set__highlight_: OptionalKeys = 0,
    bold: tp.Boolean = false,
    standout: tp.Boolean = false,
    strikethrough: tp.Boolean = false,
    underline: tp.Boolean = false,
    undercurl: tp.Boolean = false,
    underdouble: tp.Boolean = false,
    underdotted: tp.Boolean = false,
    underdashed: tp.Boolean = false,
    italic: tp.Boolean = false,
    reverse: tp.Boolean = false,
    altfont: tp.Boolean = false,
    nocombine: tp.Boolean = false,
    default: tp.Boolean = false,
    cterm: tp.Union(.{ tp.Integer, tp.String }) = tp.nilObject(),
    foreground: tp.Union(.{ tp.Integer, tp.String }) = tp.nilObject(),
    fg: tp.Union(.{ tp.Integer, tp.String }) = tp.nilObject(),
    background: tp.Union(.{ tp.Integer, tp.String }) = tp.nilObject(),
    bg: tp.Union(.{ tp.Integer, tp.String }) = tp.nilObject(),
    ctermfg: tp.Union(.{ tp.Integer, tp.String }) = tp.nilObject(),
    ctermbg: tp.Union(.{ tp.Integer, tp.String }) = tp.nilObject(),
    special: tp.Union(.{ tp.Integer, tp.String }) = tp.nilObject(),
    sp: tp.Union(.{ tp.Integer, tp.String }) = tp.nilObject(),
    link: HLGroupID = @enumFromInt(0),
    global_link: HLGroupID = @enumFromInt(0),
    fallback: tp.Boolean = false,
    blend: tp.Integer = 0,
    fg_indexed: tp.Boolean = false,
    bg_indexed: tp.Boolean = false,
    force: tp.Boolean = false,
    url: tp.String = tp.String.fromSlice(@as([]const u8, "")),

    pub const gradTop: u32 = 0x80000000;
};

fn lowercase(comptime str: []const u8) []u8 {
    var ret: [str.len]u8 = [_]u8{' '} ** str.len;
    for (str, 0..) |c, i| {
        ret[i] = c;
        if (c >= 'A' and c <= 'Z') {
            ret[i] = c - 'A' + 'a';
        }
    }
    return ret[0..];
}

pub fn setHlValue(hl: *HlAttrs, comptime name: []const u8, value: @FieldType(HlAttrs, name)) void {
    @field(hl, name) = value;
    hl.is_set__highlight_ |= 1 << @field(Masks, name);
}

pub fn clearHlValue(hl: *HlAttrs, comptime name: []const u8) void {
    hl.is_set__highlight_ &= ~(1 << @field(Masks, name));
}
