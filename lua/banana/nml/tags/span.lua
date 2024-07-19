---@module 'banana.nml.render'
local t = require('banana.lazyRequire')('banana.nml.render')

---@type Banana.Renderer
local function renderer(self, ast, parentHl, parentWidth, parentHeight, startX, startY, inherit, extra)
    return self:renderInlineEl(ast, parentHl, parentWidth, parentHeight, startX, startY, inherit, extra)
end
---@type Banana.TagInfo
local M = t.newTag(
    'span',
    t.FormatType.Inline,
    false,
    renderer,
    require('banana.nml.render').defaultInitials()
)

return M
