const std = @import("std");

pub const DiagnosticStackItem = union(enum) {
    Box: u16,
    PartialRendered: u16,
    Image: u16,
    BoxContext: u16,
};

pub const Diagnostic = union(enum) {
    OutOfMemory: void,
    ContextNotFound: Indexing,
    BoxNotFound: Indexing,
    PartialNotFound: Indexing,
    ArrayTooSmall: LenMismatch,
    StrLenTooSmall: LenMismatch,
    BoxNotExist: struct {
        partialId: u16,
    },
    HeightTooBig: LenMismatch,
    HeightTooSmall: LenMismatch,
    Exception: FromFunction,
    Validation: FromFunction,
    UnsignedSubtractToNegative: OperatorError,
    InlineBoundBoxOnNonInline: struct {
        tag: @import("PartialRendered.zig").RenderType,
    },
    BadStackSize: struct {
        field: []const u8,
    },
    EmptyStack: struct {
        field: []const u8,
    },
    Overflow: void,
    Utf8InvalidStartByte: void,
    RandomUninitialized: void,
    InvalidImageHandle: Indexing,
    NoSpaceLeft: void,
    InvalidEnumTag: void,
    Utf8ExpectedContinuation: void,
    Utf8OverlongEncoding: void,
    Utf8CannotEncodeSurrogateHalf: void,
    Utf8EncodesSurrogateHalf: void,
    CodepointTooLarge: void,
    Utf8CodepointTooLarge: void,
    NoFunction: void,
    IndexTooBig: void,
    SystemResources: void,
    SameContext: struct {
        ctxId: u16,
    },
    IntCantFit: struct {
        value: i64,
        tp: std.builtin.Type.Int,
    },
    OverindexingShiftRight: void,
    LineTooBig: LenMismatch,
    StrTooBig: LenMismatch,
    NvimStrWidthTooBig: LenMismatch,
    BadReturn: void,
    TripleWidthCharacter: void,
    OverindexingShrinkWidth: Indexing,
    CenterVerticalAlignUnimplemented: void,
    RightVerticalAlignUnimplemented: void,
    IsDir: void,
    OverindexingInsertAscii: Indexing,
    UnexpectedInlineEl: void,
    WouldBlock: void,
    AccessDenied: void,
    ProcessNotFound: void,
    EmptyArray: void,
    Unexpected: void,
    NoGivenLineHeight: void,
    ImageSizeMismatch: void,
    LogPathTooBig: LenMismatch,
    FileProblem: void,

    pub const OperatorError = struct {
        left: i64,
        right: i64,
    };
    pub const FromFunction = struct {
        name: [:0]const u8,
    };
    pub const LenMismatch = struct {
        wantedLen: u16,
        gotLen: u16,
    };
    pub const Indexing = struct {
        i: u16,
        len: u16,
    };
};
