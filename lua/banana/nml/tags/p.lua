local t = require('banana.nml.tags')

---@type Banana.Renderer
local function renderer(self, ast, parentHl, parentWidth, parentHeight, startX, startY)
    return self:renderInlineEl(ast, parentHl, parentWidth, parentHeight, startX, startY)
end
---@type Banana.TagInfo
local M = t.newTag(
    'p',
    t.FormatType.BlockInline,
    false,
    renderer
)

return M
