local t = require('banana.nml.tags')

---@param self Banana.Ast
---@param ast Banana.Ast
---@return Banana.RenderRet
local function brRenderer(self, ast)
    local ret = {}
    table.insert(ret, {})
    -- table.insert(ret, {})
    return ret
end
---@type Banana.TagInfo
local M = {
    name = 'br',
    formatType = t.FormatType.Block,
    selfClosing = true,
    render = brRenderer
}

return M
