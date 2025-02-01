const std = @import("std");
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
pub const HlAttrs = extern struct {
    rgb_ae_attr: u16 = zero(u16),
    cterm_ae_attr: u16 = zero(u16),
    // so we have 24 bits for rgb, that means we can use first 8 bits (sign bit + other) to store special info
    rgb_fg_color: RgbValue = zero(RgbValue),
    rgb_bg_color: RgbValue = zero(RgbValue),
    rgb_sp_color: RgbValue = zero(RgbValue),
    cterm_fg_color: i16 = zero(i16),
    cterm_bg_color: i16 = zero(i16),
    hl_blend: i32 = zero(i32),
    linkid: u16 = 0,
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

pub fn setHlBool(hl: *HlAttrs, name: []const u8, value: bool) void {
    const enumInfo = @typeInfo(HlAttrFlags);
    const info =
        comptime switch (enumInfo) {
        .Enum => |v| v,
        else => unreachable,
    };
    inline for (info.fields) |idk| {
        if (std.ascii.eqlIgnoreCase(name, idk.name)) {
            if (value) {
                hl.rgb_ae_attr |= idk.value;
            } else {
                hl.rgb_ae_attr &= 0xffff ^ idk.value;
            }
            break;
        }
    }
}

pub fn setHlGrad(hl: *HlAttrs, gradid: u16, fg: bool) void {
    if (fg) {
        hl.rgb_fg_color = HlAttrs.gradTop;
        hl.rgb_fg_color |= gradid;
    } else {
        hl.rgb_bg_color = HlAttrs.gradTop;
        hl.rgb_bg_color |= gradid;
    }
}
