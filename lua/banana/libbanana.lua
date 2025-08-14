local libbanana = require("banana.libbanana_zig")

libbanana.banana_init_log(vim.fn.stdpath("log") .. "/banana-zig-log.txt")

return libbanana
