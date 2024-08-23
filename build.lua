local cwd = vim.fn.getcwd()

if cwd:match("banana.nvim$") == nil then
    error("Expected build.lua to be run with banana install dir as the cwd")
end
vim.opt.runtimepath:append(cwd)
require("banana").installLibbanana()
