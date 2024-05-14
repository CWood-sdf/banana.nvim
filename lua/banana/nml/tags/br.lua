local t = require('banana.nml.tags')

---@param self Banana.Ast
---@param ast Banana.Ast
---@param parentHl Banana.Highlight?
---@return Banana.RenderRet
local function renderer(self, ast, parentHl)
    local b = require('banana.box')
    ---@type Banana.Box
    local ret = b.Box:new()
    ret.hlgroup = ast:mixHl(parentHl)
    ret:appendStr("")
    return ret
end
---@type Banana.TagInfo
local M = {
    name = 'br',
    formatType = t.FormatType.Block,
    selfClosing = true,
    render = renderer
}

return M
