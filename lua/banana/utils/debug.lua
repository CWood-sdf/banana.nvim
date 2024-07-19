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

return M
