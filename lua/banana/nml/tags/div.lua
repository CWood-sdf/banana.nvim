local t = require('banana.nml.tags')

---@type Banana.Renderer
local function renderer(self, ast, parentHl, parentWidth, parentHeight, startX, startY)
    local b = require('banana.box')
    ---@type Banana.Box
    local ret = b.Box:new()
    ret.hlgroup = ast:mixHl(parentHl)
    for _, box, _ in self:blockIter(ast, ret.hlgroup, parentWidth, parentHeight, startX, startY) do
        ret:appendBoxBelow(box)
    end
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    'div',
    t.FormatType.Block,
    false,
    renderer
)

return M
