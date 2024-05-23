local t = require('banana.nml.tags')

---@type Banana.Renderer
local function renderer(self, ast, parentHl, parentWidth, parentHeight, startX, startY)
    return self:renderInlineEl(ast, parentHl, parentWidth, parentHeight, startX, startY)
end
---@type Banana.TagInfo
local M = t.newTag(
    'span',
    t.FormatType.Inline,
    false,
    renderer
)

return M
