---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")

---@type Banana.Renderer
local function renderer(self, ast, parentHl, parentWidth, parentHeight, startX,
                        startY, inherit, extra)
    -- flame.new("tag:p")
    local ret = self:renderInlineEl(ast, parentHl, parentWidth, parentHeight,
        startX,
        startY, inherit, extra)
    -- flame.pop()
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    "p",
    t.FormatType.BlockInline,
    false,
    renderer,
    require("banana.nml.tag").defaultInitials()
)

return M
