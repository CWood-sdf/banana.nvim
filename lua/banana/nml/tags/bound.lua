--NOTE: THIS TAG IS TEMPORARY FOR TESTING PURPOSES
local t = require('banana.nml.tags')

---@type Banana.Renderer
local function renderer(_, ast, parentHl, _, _, startX, startY, _)
    local b = require('banana.box')
    local ret = b.Box:new(ast:mixHl(parentHl))
    ret:appendStr(startX .. ", " .. startY)
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    'bound',
    t.FormatType.Inline,
    true,
    renderer,
    require('banana.nml.tags').defaultInitials()
)

return M
