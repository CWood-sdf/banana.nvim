local t = require('banana.nml.tags')

---@type Banana.Renderer
local function renderer(_, ast, parentHl, _, _)
    local b = require('banana.box')
    ---@type Banana.Box
    local ret = b.Box:new()
    ret.hlgroup = ast:mixHl(parentHl)
    ret:appendStr("")
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    'br',
    t.FormatType.Block,
    true,
    renderer,
    require('banana.nml.tags').defaultInitials()
)

return M
