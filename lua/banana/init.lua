local M = {}

---@class Banana.Opts
---@field setupTs boolean

local counterInst = nil
local todoInst = nil
local treeInst = nil
local instance = nil
local inst = nil
---@module 'banana.instance'
local render = require("banana.lazyRequire")("banana.instance")
local ffi = require("ffi")

local tsInit = false
local tsInstall = false

M.test = {
    grid = function ()
        if inst == nil then
            inst = render.newInstance("devtools", "")
            -- inst.DEBUG = true
            -- inst.DEBUG_showBuild = true
            -- inst.DEBUG_showPerf = true
            -- inst.DEBUG_dumpTree = true
            -- inst.DEBUG_stressTest = true
        end
        inst:open()
    end
}

M.runTree = function ()
    if treeInst == nil then
        treeInst = render.newInstance("examples/tree", "tree demo")
    end
    treeInst:open()
end

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
    if ret == "" then
        ret = vim.fn.getcwd()
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

function M.installLibbanana()
    vim.print("Installing libbanana")
    local job = vim.fn.jobstart("zig build",
        {
            cwd = M.getInstallDir() .. "/zig",
            detach = true,
            on_exit = function (p1, p2, p3)
            end,
            on_stderr = function (p1, p2, p3)
                p1 = p1 or ""
                p2 = p2 or ""
                p3 = p3 or ""
            end,
            on_stdout = function (p1, p2, p3)
                p1 = p1 or ""
                p2 = p2 or ""
                p3 = p3 or ""
            end
        })

    vim.fn.jobwait({ job })
end

---@param opts Banana.Opts
function M.setup(opts)
    if opts.setupTs then
        M.initTsParsers()
    end
end

function M.initTsParsers()
    if tsInit then
        return
    end
    tsInit = true
    local parser_config = require("nvim-treesitter.parsers").get_parser_configs()
    vim.filetype.add({
        extension = { nml = "nml", ncss = "ncss" },
    })

    ---@diagnostic disable-next-line: inject-field
    parser_config.nml = {
        install_info = {
            url = "https://github.com/CWood-sdf/tree-sitter-nml",
            -- path = M.getInstallDir() .. "/tree-sitter-nml",
            files = { "src/parser.c", "src/scanner.c" },
            branch = "main",
            generate_requires_npm = false,
            requires_generate_from_grammar = false,
        },
        filetype = "nml",
    }
    vim.treesitter.language.register("nml", "nml")
    ---@diagnostic disable-next-line: inject-field
    parser_config.ncss = {
        install_info = {
            url = "https://github.com/CWood-sdf/tree-sitter-ncss",
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
