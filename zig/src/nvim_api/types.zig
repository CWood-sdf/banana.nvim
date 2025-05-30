pub const Buffer = enum(c_int) { _ };
pub const Window = enum(c_int) { _ };
pub const ObjectKind = enum(c_int) {
    Nil = 0,
    Boolean = 1,
    Integer = 2,
    Float = 3,
    String = 4,
    Array = 5,
    Dictionary = 6,
    LuaRef = 7,
    Buffer = 8,
    Window = 9,
    TabPage = 10,
};
pub const OptionalKeys = u64;
pub const Boolean = bool;
pub const Integer = i64;
pub const Float = f64;
pub const LuaRef = c_int;
pub const String = extern struct {
    data: [*]allowzero const u8,
    size: u64,
    pub fn fromSlice(slice: []const u8) String {
        return .{
            .data = slice.ptr,
            .size = slice.len,
        };
    }
};

pub fn KVec(T: type) type {
    return extern struct {
        size: u64,
        capacity: u64,
        items: [*]allowzero T,

        const Self = @This();

        pub fn fromSlice(slice: []T) Self {
            return .{
                .size = slice.len,
                .capacity = slice.len,
                .items = slice.ptr,
            };
        }
    };
}
pub const KeyValuePair = extern struct {
    key: String,
    value: Object,
};

pub const Array = KVec(Object);
pub const Dictionary = KVec(KeyValuePair);
pub const ObjectData = extern union {
    boolean: Boolean,
    integer: Integer,
    float: Float,
    string: String,
    array: Array,
    dictionary: Dictionary,
    luaref: LuaRef,
};
pub const Object = extern struct {
    type: ObjectKind,
    data: ObjectData,
};

pub fn intObject(val: Integer) Object {
    return Object{ .type = .Integer, .data = .{ .integer = val } };
}
pub fn floatObject(val: Float) Object {
    return Object{ .type = .Float, .data = .{ .float = val } };
}

pub fn boolObject(val: Boolean) Object {
    return Object{ .type = .Boolean, .data = .{ .boolean = val } };
}
pub fn makeString(val: []const u8) String {
    return String.fromSlice(val);
}

pub fn stringObject(val: []const u8) Object {
    const str = makeString(val);
    return Object{
        .data = .{ .string = str },
        .type = .String,
    };
}

pub fn nilObject() Object {
    return Object{ .type = ObjectKind.Nil, .data = .{
        .integer = 0,
    } };
}
pub const ErrorType = enum(c_int) {
    None = -1,
    Exception,
    Validation,
};
pub const Error = extern struct {
    type: ErrorType,
    msg: [*]allowzero const u8,
    pub const empty: Error = .{
        .type = .None,
        .msg = @ptrFromInt(0),
    };
};

pub const NvimError = error{ Exception, Validation };

pub const Arena = extern struct {
    current_block: [*]allowzero const u8,
    pos: usize,
    size: usize,
    pub const empty: Arena = .{
        .current_block = @ptrFromInt(0),
        .pos = 0,
        .size = 0,
    };
};
pub fn Union(_: anytype) type {
    return Object;
}
