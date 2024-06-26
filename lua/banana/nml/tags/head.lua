local t = require('banana.nml.tags')

---@type Banana.Renderer
local function renderer(_, ast, hl, parentWidth, parentHeight, _, _, inherit, extra)
    local b = require('banana.box')
    ---@type Banana.Box
    local ret = b.Box:new()
    -- not actually rendering anything bc its all metadata tags
    for v in ast:childIter() do
        v.actualTag:renderRoot(ast, hl, parentWidth, parentHeight, inherit, extra)
    end
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    'head',
    t.FormatType.Block,
    false,
    renderer,
    require('banana.nml.tags').defaultInitials()
)

return M
