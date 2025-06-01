const std = @import("std");
const common = @import("common.zig");
const charwidth = common.charwidth;
pub const Char = packed struct(u32) {

    // the actual number
    bytes: u3,
    // the width
    width: u2,
    pad1: u3 = 0,
    char: u21,
    pad2: u3 = 0,

    pub const ordering = getByteOrdering();
    pub const simdLen = std.simd.suggestVectorLength(u32) orelse 1;

    // should be placed after double width characters so that they can act like their width
    pub const dummy: Char = .{
        .bytes = 0,
        .width = 0,
        .char = 0,
    };

    pub const space: Char = .{
        .bytes = 1,
        .width = 1,
        .char = ' ',
    };

    pub const ByteOrdering = enum {
        left,
        right,
    };

    pub fn getByteOrdering() ByteOrdering {
        const bytes: u3 = 1;
        const width: u2 = 1;
        const char: u21 = 'a';
        const c: Char = Char.fromAscii(char);
        const cu32: u32 = @bitCast(c);
        // byte 1: bbbw_wppp
        const byte1: u8 = (@as(u8, bytes) << 5) | (@as(u8, width) << 3);
        // byte 2: pppc_cccc
        const byte2: u8 = (char & 0b1_1111_0000_0000_0000_0000) >> 16;
        // byte 3: cccc_cccc
        const byte3: u8 = (char & 0b0_0000_1111_1111_0000_0000) >> 8;
        // byte 4: cccc_cccc
        const byte4: u8 = (char & 0b0_0000_0000_0000_1111_1111);

        comptime std.debug.assert('a' == byte4);

        const ascii: @Vector(1, u8) = @splat('a');
        const b1vec: @Vector(1, u8) = @splat(byte1);
        const b2vec: @Vector(1, u8) = @splat(byte2);
        const b3vec: @Vector(1, u8) = @splat(byte3);

        const interlaced: @Vector(1, u32) = @bitCast(std.simd.interlace(
            .{ ascii, b1vec, b2vec, b3vec },
        ));
        if (@reduce(.Or, interlaced) == cu32) {
            return .left;
        }
        return .right;
    }

    pub fn equals(self: *const Char, other: Char) bool {
        return self.bytes == other.bytes and self.width == other.width and self.char == other.char;
    }

    /// writes the utf8 representation to the byte array
    /// then returns the number of bytes written
    pub fn toBytes(self: *const Char, byteArr: []u8) !u8 {
        if (self.bytes == 0) {
            return 0;
        }
        if (byteArr.len < self.bytes) {
            return error.ArrayTooSmall;
        }

        const bytes = try std.unicode.utf8Encode(self.char, byteArr);
        return bytes;
    }
    pub fn fromAscii(byte: u8) Char {
        return .{
            .bytes = 1,
            .char = byte,
            .width = 1,
        };
    }

    pub fn fromUtf8(bytes: []const u8) !Char {
        if (bytes.len == 0) {
            return error.ArrayTooSmall;
        }
        const byteSize = try std.unicode.utf8ByteSequenceLength(bytes[0]);
        if (bytes.len < byteSize) {
            return error.ArrayTooSmall;
        }
        const codepoint: u21 = try std.unicode.utf8Decode(bytes[0..byteSize]);
        const width = try charwidth(bytes[0..byteSize]);
        if (width > 2) {
            return error.NvimStrWidthTooBig;
        }
        return .{
            .bytes = byteSize,
            .char = codepoint,
            .width = @intCast(width),
        };
    }

    pub fn isDummy(char: Char) bool {
        return char.width == 0;
    }

    pub fn sliceWidth(slice: []const Char) u16 {
        var ret: u16 = 0;
        for (slice) |char| {
            ret += char.width;
        }
        return ret;
    }

    pub fn simdToChars(chars: @Vector(simdLen, u8)) @Vector(simdLen, u32) {
        const bytes: u3 = @bitReverse(@as(u3, 1));
        const width: u2 = @bitReverse(@as(u2, 1));
        // byte 1: bbbw_wppp
        const byte1: u8 = (@as(u8, bytes) << 5) | (@as(u8, width) << 3);
        // byte 2: aaaa_aaaa
        const byte2: u8 = 0;
        // byte 3: cccc_cccc
        const byte3: u8 = 0;
        // byte 4: cccc_cppp
        // where a = bits of ascii char

        const b1vec: @Vector(simdLen, u8) = @splat(byte1);
        const b2vec: @Vector(simdLen, u8) = @bitReverse(chars);
        const b3vec: @Vector(simdLen, u8) = @splat(byte3);
        // const actualChars = @bitReverse(chars);
        const actualChars: @Vector(simdLen, u8) = @splat(byte2);
        const ret = if (ordering == .left)
            std.simd.interlace(.{ b1vec, b2vec, b3vec, actualChars })
        else
            std.simd.interlace(.{ actualChars, b3vec, b2vec, b1vec });
        const actualRet: @Vector(simdLen, u32) = @bitCast(ret);
        return @bitReverse(actualRet);
    }
    pub fn canSimd(chars: []const u8) bool {
        if (chars.len < simdLen) {
            return false;
        }
        const charsVec: @Vector(simdLen, u8) = chars[0..simdLen].*;
        const reduction = @reduce(.Or, charsVec);
        return reduction & 0b1000_0000 == 0;
    }
};
