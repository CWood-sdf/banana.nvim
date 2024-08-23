local counterInst = nil
local todoInst = nil
local instance = nil
local inst = nil
---@module 'banana.instance'
local render = require("banana.lazyRequire")("banana.instance")
local ffi = require("ffi")

---@class Banana
---@field newInstance function
---@field emptyInstance function
---@field getInstance function
---@field getNilAst function
---@field listInstanceIds function
---@field examples table
local M = {
    newInstance = render.newInstance,
    emptyInstance = render.emptyInstance,
    getInstance = render.getInstance,
    getNilAst = render.getNilAst,
    listInstanceIds = render.listInstanceIds,
}


local tsInit = false
local tsInstall = false

---@class Banana.Examples
---@field runCounter function
---@field runTodo function
---@field runLazy function
M.examples = {
    runCounter = function ()
        if counterInst == nil then
            counterInst = M.newInstance("examples/counter", "asdf")
            -- instance.DEBUG = true
        end
        counterInst:open()
    end,

    runTodo = function ()
        if todoInst == nil then
            todoInst = M.newInstance("examples/todo", "asdf")
            -- instance.DEBUG = true
        end
        todoInst:open()
    end,

    runLazy = function ()
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

M.test = {
    grid = function ()
        -- print(jit.status())
        -- jit.on()
        -- ffi.cdef([[
        -- int add(int l, int r);
        -- void addToString(char* str);
        -- ]])
        -- local so = ffi.load(
        --     "/home/christopher-wood/projects/banana.nvim/zig/zig-out/lib/libbanana.so")
        -- print(so.add(1, 2))
        -- local txt = "asdf123"
        -- local cstr = ffi.new("char[?]", #txt + 1)
        -- ffi.copy(cstr, txt)
        -- so.addToString(cstr)
        -- print(ffi.string(cstr))
        if inst == nil then
            inst = render.newInstance("grid", "")
            -- inst.DEBUG_showPerf = true
            -- inst.DEBUG_stressTest = true
            -- inst.DEBUG = true
        end
        inst:open()
    end
}

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
    local job = vim.fn.jobstart("zig build -Doptimize=ReleaseFast",
        {
            cwd = M.getInstallDir() .. "/zig",
            detach = true,
            on_exit = function (p1, p2, p3)
                print("Exit parameters: " .. p1 .. ", " .. p2 .. ", " .. p3)
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
                print("stdout params: " ..
                    vim.inspect(p1) ..
                    ", " .. vim.inspect(p2) .. ", " .. vim.inspect(p3))
            end
        })

    vim.fn.jobwait({ job })
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
