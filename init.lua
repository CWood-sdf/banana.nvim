-- an init.lua file for debugging zig .so's

local M = {}
function M.root(root)
    local f = debug.getinfo(1, "S").source:sub(2)
    return vim.fn.getcwd() .. "/" .. (root or "")
end

vim.g.mapleader = " "
vim.keymap.set("n", "<leader>dy", function ()
    require("banana").test.grid()
end, {})

function M.load(plugin)
    local name = plugin:match(".*/(.*)")
    local package_root = M.root(".zigd/site/pack/deps/start/")
    if not vim.loop.fs_stat(package_root .. name) then
        print("Installing " .. plugin)
        vim.fn.mkdir(package_root, "p")
        local isDone = false
        vim.cmd(
            "!git clone --depth=1 https://github.com/" ..
            plugin ..
            ".git " ..
            package_root ..
            name --, {
        --     on_exit = function()
        --         print("DOne")
        --         isDone = true
        --     end,
        -- }
        )
        -- while not isDone do
        --     vim.uv.sleep(1000)
        -- end
    end
end

vim.cmd([[set runtimepath=$VIMRUNTIME]])
vim.opt.runtimepath:append(M.root())
vim.opt.packpath = { M.root(".zigd/site") }

M.load("nvim-lua/plenary.nvim")
M.load("nvim-treesitter/nvim-treesitter")

vim.env.XDG_CONFIG_HOME = M.root(".zigd/config")
vim.env.XDG_DATA_HOME = M.root(".zigd/data")
vim.env.XDG_STATE_HOME = M.root(".zigd/state")
vim.env.XDG_CACHE_HOME = M.root(".zigd/cache")
require("nvim-treesitter").setup()
require("nvim-treesitter.install").compilers = { "zig", "clang" }

require("nvim-treesitter.configs").setup({
    sync_install = true,
    modules = {},

    ignore_install = {},

    -- A list of parser names, or "all" (the five listed parsers should always be installed)
    ensure_installed = {
    },
    -- Install parsers synchronously (only applied to `ensure_installed`) sync_install = false,

    -- Automatically install missing parsers when entering buffer
    -- Recommendation: set to false if you don't have `tree-sitter` CLI installed locally
    auto_install = true,

    highlight = {
        enable = true,

        -- Setting this to true will run `:h syntax` and tree-sitter at the same time.
        -- Set this to `true` if you depend on 'syntax' being enabled (like for indentation).
        -- Using this option may slow down your editor, and you may see some duplicate highlights.
        -- Instead of true it can also be a list of languages
        additional_vim_regex_highlighting = false,
    },
})

local parser_config = require("nvim-treesitter.parsers").get_parser_configs()
vim.treesitter.language.register("nml", "nml")
---@diagnostic disable-next-line: inject-field
parser_config.nml = {
    install_info = {
        url = M.root("./tree-sitter-nml"),
        files = { "src/parser.c" },
        branch = "main",
        generate_requires_npm = false,
        requires_generate_from_grammar = false,
    },
    filetype = "nml",
}
---@diagnostic disable-next-line: inject-field
parser_config.ncss = {
    install_info = {
        url = M.root("./tree-sitter-ncss"),
        files = { "src/parser.c", "src/scanner.c" },
        branch = "main",
        generate_requires_npm = false,
        requires_generate_from_grammar = false,
    },
    filetype = "ncss",
}
vim.treesitter.language.register("ncss", "ncss")
vim.cmd("TSInstallSync! nml")
vim.cmd("TSInstallSync! ncss")

vim.cmd("so build.lua")

require("banana.nml.render.grid").getGridSo()
