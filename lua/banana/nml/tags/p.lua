---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.render'
local t = require("banana.lazyRequire")("banana.nml.render")

---@type Banana.Renderer
local function renderer(self, ast, parentHl, parentWidth, parentHeight, startX,
                        startY, inherit, extra)
    --flame.new("tag:p")
    local ret = self:renderInlineEl(ast, parentHl, parentWidth, parentHeight,
        startX,
        startY, inherit, extra)
    --flame.pop()
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    "p",
    t.FormatType.BlockInline,
    false,
    renderer,
    require("banana.nml.render").defaultInitials()
)

return M
