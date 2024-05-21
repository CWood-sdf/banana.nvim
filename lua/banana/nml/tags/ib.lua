local t = require('banana.nml.tags')

---@param self Banana.TagInfo
---@param ast Banana.Ast
---@param parentHl Banana.Highlight?
---@return Banana.RenderRet
local function renderer(self, ast, parentHl, parentWidth, parentHeight)
    local b = require('banana.box')
    ---@type Banana.Box
    local ret = b.Box:new()
    ret.hlgroup = ast:mixHl(parentHl)
    for _, box, _ in self:blockIter(ast, ret.hlgroup, parentWidth, parentHeight) do
        ret:appendBoxBelow(box)
    end
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    'ib',
    t.FormatType.InlineBlock,
    false,
    renderer
)

return M
