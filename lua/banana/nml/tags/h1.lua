---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")

---@type Banana.Renderer
local function renderer(self, ast, box, parentHl, inherit, extra)
    -- flame.new("tag:h1")
    local ret = self:renderInlineEl(ast, box, parentHl, inherit, extra)
    -- flame.pop()
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    "h1",
    t.FormatType.BlockInline,
    false,
    renderer,
    require("banana.nml.tag").defaultInitials()
)

return M
