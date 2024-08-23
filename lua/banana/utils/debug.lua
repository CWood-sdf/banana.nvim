local M = {}

---@module 'banana.box'
local b = require('banana.lazyRequire')('banana.box')

---@param msg string
---@return Banana.Box
function M.traceBreak(msg)
    local ret = b.Box:new()
    ret:appendStr("---- line: " .. msg)
    return ret
end

---@return boolean
function M.isdev()
    local ok, val = pcall(require, "banana.dev")
    return ok and val
end

function M.spam()
    local testFile = [[
			.asdf {
				hl-bg: #0000ff;
			}
		]]
    local startTime = vim.uv.hrtime()
    for _ = 1, 1000 do
        local _ = require('banana.ncss.parser').parseTextSlow(testFile)
    end
    vim.notify((vim.uv.hrtime() - startTime) / 1e6 .. "ms\n")
    startTime = vim.uv.hrtime()
    for _ = 1, 1000 do
        local _ = require('banana.ncss.parser').parseText(testFile)
    end
    vim.notify((vim.uv.hrtime() - startTime) / 1e6 .. "ms\n")
end

return M
