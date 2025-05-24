const std = @import("std");
const log = @import("log.zig");

const alloc = std.heap.smp_allocator;

const Dst = struct {
    fns: std.ArrayListUnmanaged(Function) = .empty,
    currentFunction: ?Function = null,
    random: ?std.Random = null,
    randomGen: std.Random.DefaultPrng = .init(0),
    stringBuf: [1000]u8 = [_]u8{0} ** 1000,

    pub const Function = struct {
        name: [200]u8 = [_]u8{0} ** 200,
        nameLen: u16 = 0,
        params: [40]ParamType = [_]ParamType{.none} ** 40,
        paramsLen: u16 = 0,

        pub const ParamType = enum(u8) {
            none = 0,
            string = 1,
            i16 = 2,
            u16 = 3,
            u8 = 4,
        };
    };

    pub fn pushFunction(self: *Dst) !void {
        if (self.currentFunction) |function| {
            try self.fns.append(alloc, function);
            self.currentFunction = null;
        } else {
            return error.NoFunction;
        }
    }
    pub fn newFunction(self: *Dst, name: []const u8) bool {
        if (name.len > 200) {
            return false;
        }
        self.currentFunction = .{
            .nameLen = @intCast(name.len),
        };
        @memcpy(self.currentFunction.?.name[0..name.len], name);
        return true;
    }

    pub fn addParam(self: *Dst, tp: []const u8) bool {
        const typeId = std.meta.stringToEnum(Function.ParamType, tp) orelse return false;

        if (self.currentFunction) |*f| {
            if (f.paramsLen == f.params.len) {
                return false;
            }
            f.params[f.paramsLen] = typeId;
            f.paramsLen += 1;
            return true;
        } else {
            return false;
        }
    }

    pub fn initRandom(self: *Dst) void {
        self.randomGen = @TypeOf(self.randomGen).init(@intCast(std.time.milliTimestamp()));
        self.random = self.randomGen.random();
    }

    pub fn getFunctionName(self: *Dst, i: usize) ![]const u8 {
        const f = self.fns.items[i];
        // log.write("getting function with name: {s}\n", .{f.name[0..f.nameLen]}) catch {};
        return f.name[0..f.nameLen];
    }

    pub fn getNextFunction(self: *Dst) !usize {
        if (self.random) |*rand| {
            const index = rand.intRangeLessThan(usize, 0, self.fns.items.len);
            self.currentFunction = self.fns.items[index];
            return index;
        } else return error.RandomUninitialized;
    }

    pub fn getFunctionCount(self: *Dst) !u32 {
        if (self.random) |*rand| {
            return rand.intRangeLessThan(u32, 0, 100000);
        } else return error.RandomUninitialized;
    }

    pub fn getParamCount(self: *Dst) !usize {
        if (self.currentFunction) |f| {
            return f.paramsLen;
        } else {
            return error.NoFunction;
        }
    }

    pub fn getParamType(self: *Dst, i: u16) !usize {
        if (self.currentFunction) |f| {
            if (i >= f.paramsLen) {
                return error.IndexTooBig;
            }
            return @intFromEnum(f.params[i]);
        } else {
            return error.NoFunction;
        }
    }
    pub fn getU16Param(self: *Dst) !u16 {
        if (self.random) |*rand| {
            return rand.intRangeAtMost(u16, 0, 20);
        } else return error.RandomUninitialized;
    }
    pub fn getU8Param(self: *Dst) !u8 {
        if (self.random) |*rand| {
            return rand.intRangeAtMost(u8, 0, 20);
        } else return error.RandomUninitialized;
    }

    pub fn getI16Param(self: *Dst) !i16 {
        if (self.random) |*rand| {
            return rand.intRangeAtMostBiased(i16, -20, 20);
        } else return error.RandomUninitialized;
    }

    pub fn getStringParam(self: *Dst) ![]const u8 {
        if (self.random) |*rand| {
            const len = rand.intRangeLessThan(usize, 0, self.stringBuf.len);
            for (self.stringBuf[0..len]) |*c| {
                c.* = rand.intRangeAtMost(u8, ' ', 100);
            }
            return self.stringBuf[0..len];
        } else return error.RandomUninitialized;
    }
};

var dst: Dst = .{};

pub fn dst_init() *Dst {
    dst = .{};
    return &dst;
}
pub fn dst_push_function(self: *Dst) !void {
    try self.pushFunction();
}
pub fn dst_new_function(self: *Dst, name: []const u8) bool {
    return self.newFunction(name);
}

pub fn dst_add_param(self: *Dst, tp: []const u8) bool {
    return self.addParam(tp);
}

pub fn dst_init_random(self: *Dst) void {
    self.initRandom();
}

pub fn dst_get_next_function(self: *Dst) !usize {
    return try self.getNextFunction();
}

pub fn dst_get_function_name(self: *Dst, i: usize) ![]const u8 {
    return try alloc.dupeZ(u8, try self.getFunctionName(i));
}

pub fn dst_get_function_count(self: *Dst) !u32 {
    return try self.getFunctionCount();
}
pub fn dst_get_param_count(self: *Dst) !usize {
    return try self.getParamCount();
}

pub fn dst_get_param_type(self: *Dst, i: u16) !usize {
    return try self.getParamType(i);
}
pub fn dst_get_u16_param(self: *Dst) !u16 {
    return try self.getU16Param();
}
pub fn dst_get_u8_param(self: *Dst) !u8 {
    return try self.getU8Param();
}

pub fn dst_get_i16_param(self: *Dst) !i16 {
    return try self.getI16Param();
}

pub fn dst_get_string_param(self: *Dst) ![]const u8 {
    return try self.getStringParam();
}
