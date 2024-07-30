---@module 'banana.instance'

local Instance = require('banana.lazyRequire')('banana.instance')

---@class Banana
---@field newInstance function
---@field emptyInstance function
---@field getInstance function
---@field getNilAst function
---@field listInstanceIds function
---@field examples table
local M = {
    newInstance = Instance.newInstance,
    emptyInstance = Instance.emptyInstance,
    getInstance = Instance.getInstance,
    getNilAst = Instance.getNilAst,
    listInstanceIds = Instance.listInstanceIds,
}

local counterInst = nil
local todoInst = nil
local instance = nil

local tsInit = false
local tsInstall = false

---@class Banana.Examples
---@field runCounter function
---@field runTodo function
---@field runLazy function
M.examples = {
    runCounter = function()
        if counterInst == nil then
            counterInst = M.newInstance("examples/counter", "asdf")
            -- instance.DEBUG = true
        end
        counterInst:open()
    end,

    runTodo = function()
        if todoInst == nil then
            todoInst = M.newInstance("examples/todo", "asdf")
            -- instance.DEBUG = true
        end
        todoInst:open()
    end,

    runLazy = function()
        if instance == nil then
            instance = M.newInstance("examples/lazy", "")
            -- instance.DEBUG = true
            -- instance.DEBUG_showPerf = true
            -- instance.DEBUG_stressTest = true
        end
        instance:open()
        instance:_requestRender()
    end,
}

function M.getInstallDir()
    local ret = ""

    for _, v in ipairs(vim.api.nvim_list_runtime_paths()) do
        if v:match("banana.nvim$") ~= nil then
            ret = v
        end
    end
    return ret
end

function M.installTsParsers()
    if tsInstall then
        return
    end
    M.initTsParsers()
    tsInstall = true
    vim.cmd("TSInstallSync nml")
    vim.cmd("TSInstallSync ncss")
end

function M.initTsParsers()
    if tsInit then
        return
    end
    tsInit = true
    local parser_config = require("nvim-treesitter.parsers").get_parser_configs()

    vim.filetype.add({ extension = { nml = "nml" } })
    vim.treesitter.language.register("nml", "nml")
    ---@diagnostic disable-next-line: inject-field
    parser_config.nml = {
        install_info = {
            url = M.getInstallDir() .. "/tree-sitter-nml",
            files = { "src/parser.c" },
            branch = "main",
            generate_requires_npm = false,
            requires_generate_from_grammar = false,
        },
        filetype = "nml",
    }

    vim.filetype.add({ extension = { ncss = "ncss" } })
    vim.treesitter.language.register("ncss", "ncss")
    ---@diagnostic disable-next-line: inject-field
    parser_config.ncss = {
        install_info = {
            url = M.getInstallDir() .. "/tree-sitter-ncss",
            files = { "src/parser.c", "src/scanner.c" },
            branch = "main",
            generate_requires_npm = false,
            requires_generate_from_grammar = false,
        },
        filetype = "ncss",
    }
end

return M
