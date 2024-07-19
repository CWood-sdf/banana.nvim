local M = {}
---@param str string
---@return string
function M.snakeToKebab(str)
    local ret, _ = str:gsub('_', '-')
    return ret
end

---@param str string
---@return string
function M.kebabToSnake(str)
    local ret, _ = str:gsub('\\-', '_')
    return ret
end

return M
