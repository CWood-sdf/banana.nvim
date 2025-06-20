local M = {}

---@module 'banana.box'
local b = require("banana.lazyRequire")("banana.box")

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

return M
