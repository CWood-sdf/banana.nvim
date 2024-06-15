local t = require('banana.nml.tags')

---@type Banana.Renderer
local function renderer(self, ast, _, parentWidth, parentHeight, startX, startY, inherit, extra)
    local b = require('banana.box')
    ---@type Banana.Box
    local ret = b.Box:new()
    -- not actually rendering anything bc its all metadata tags
    for _, _, _ in self:blockIter(ast, ret.hlgroup, parentWidth, parentHeight, startX, startY, inherit, extra) do
        local _ = 0
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
