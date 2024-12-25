--- from folke/noice.nvim
local M = {}

-- literally just so that I can have treesitter highlighting for tests
---@diagnostic disable-next-line: lowercase-global
function nml(str)
    return str
end

function M.root(root)
    local f = debug.getinfo(1, "S").source:sub(2)
    return vim.fn.fnamemodify(f, ":p:h:h") .. "/" .. (root or "")
end

---@param plugin string
function M.load(plugin)
    local name = plugin:match(".*/(.*)")
    local package_root = M.root(".tests/site/pack/deps/start/")
    if not vim.loop.fs_stat(package_root .. name) then
        print("Installing " .. plugin)
        vim.fn.mkdir(package_root, "p")
        -- local isDone = false
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

function M.setup()
    vim.cmd([[set runtimepath=$VIMRUNTIME]])
    vim.opt.runtimepath:append(M.root())
    vim.opt.packpath = { M.root(".tests/site") }

    M.load("nvim-lua/plenary.nvim")
    M.load("nvim-treesitter/nvim-treesitter")

    vim.env.XDG_CONFIG_HOME = M.root(".tests/config")
    vim.env.XDG_DATA_HOME = M.root(".tests/data")
    vim.env.XDG_STATE_HOME = M.root(".tests/state")
    vim.env.XDG_CACHE_HOME = M.root(".tests/cache")
    require("nvim-treesitter").setup()
    require("nvim-treesitter.install").compilers = { "zig", "clang" }

    require("nvim-treesitter.configs").setup({
        modules = {},

        ignore_install = {},

        -- A list of parser names, or "all" (the five listed parsers should always be installed)
        ensure_installed = {
        },

        -- Install parsers synchronously (only applied to `ensure_installed`)
        sync_install = false,

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
    print("Root is: " .. M.root())
    local libbananaPath = M.root("zig/zig-out/lib/libbanana.so")
    print("libbanana path: " .. libbananaPath)
    vim.cmd("so " .. M.root() .. "/build.lua")
    print("libbanana exists: " .. vim.fn.filereadable(libbananaPath))
    require("banana").installLibbanana()
    -- require("banana")._statInstallDir()
end

M.setup()
