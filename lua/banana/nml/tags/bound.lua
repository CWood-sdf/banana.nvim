--NOTE: THIS TAG IS TEMPORARY FOR TESTING PURPOSES
local t = require('banana.nml.tags')

---@type Banana.Renderer
local function renderer(self, ast, parentHl, parentWidth, parentHeight, startX, startY)
    local b = require('banana.box')
    local ret = b.Box:new(ast:mixHl(parentHl))
    ret:appendStr(startX .. ", " .. startY)
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    'span',
    t.FormatType.Inline,
    true,
    renderer
)

return M
