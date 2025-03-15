// https://github.com/neovim/neovim/blob/v0.9.0/src/nvim/api/private/defs.h#L43
pub const INTERNAL_CALL_MASK: u64 = 1 << (@sizeOf(u64) * 8 - 1);

// https://github.com/neovim/neovim/blob/v0.9.0/src/nvim/api/private/defs.h#L46
pub const VIML_INTERNAL_CALL: u64 = INTERNAL_CALL_MASK;

// https://github.com/neovim/neovim/blob/v0.9.0/src/nvim/api/private/defs.h#L49
pub const LUA_INTERNAL_CALL: u64 = VIML_INTERNAL_CALL + 1;
