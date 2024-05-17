local t = require('banana.nml.tags')

---@param self Banana.TagInfo
---@param ast Banana.Ast
---@param parentHl Banana.Highlight?
---@return Banana.RenderRet
local function renderer(self, ast, parentHl)
    return self:renderInlineEl(ast, parentHl)
end
---@type Banana.TagInfo
local M = t.newTag(
    'li',
    t.FormatType.BlockInline,
    false,
    renderer
)

return M
