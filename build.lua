local cwd = vim.fn.getcwd()

if cwd:match("banana.nvim$") == nil then
    if vim.fn.isdirectory(cwd .. "/banana.nvim") then
        cwd = cwd .. "/banana.nvim"
    else
        vim.notify(cwd)
        error("Expected build.lua to be run with banana install dir as the cwd")
    end
end
vim.opt.runtimepath:append(cwd)
require("banana").installLibbanana()
