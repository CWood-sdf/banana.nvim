local M = {}
local counterInst = nil
local todoInst = nil
local instance = nil
local inst = nil
---@module 'banana.instance'
local render = require("banana.lazyRequire")("banana.instance")

local tsInit = false
local tsInstall = false

M.test = {
    grid = function ()
        if inst == nil then
            inst = render.newInstance("grid", "")
            inst.DEBUG_showPerf = true
            inst.DEBUG_stressTest = true
            -- inst.DEBUG = true
        end
        inst:open()
    end
}

M.runCounter = function ()
    if counterInst == nil then
        counterInst = render.newInstance("examples/counter", "asdf")
        -- instance.DEBUG = true
    end
    counterInst:open()
end
M.runTodo = function ()
    if todoInst == nil then
        todoInst = render.newInstance("examples/todo", "asdf")
        -- instance.DEBUG = true
    end
    todoInst:open()
end

M.runLazy = function ()
    if instance == nil then
        instance = render.newInstance("examples/lazy", "")
        -- instance.DEBUG = true
        -- instance.DEBUG_showPerf = true
        -- instance.DEBUG_stressTest = true
    end
    instance:open()
    instance:_requestRender()
end

function M.spam()
    local testFile = [[
			.asdf {
				hl-bg: #0000ff;
			}
		]]
    local startTime = vim.uv.hrtime()
    for _ = 1, 1000 do
        local _ = require("banana.ncss.parser").parseTextSlow(testFile)
    end
    vim.notify((vim.uv.hrtime() - startTime) / 1e6 .. "ms\n")
    startTime = vim.uv.hrtime()
    for _ = 1, 1000 do
        local _ = require("banana.ncss.parser").parseText(testFile)
    end
    vim.notify((vim.uv.hrtime() - startTime) / 1e6 .. "ms\n")
end

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
    vim.treesitter.language.register("ncss", "ncss")
end

return M
