---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")

---@type Banana.Renderer
local function renderer(self, ast, box, parentHl,

                        inherit, extra)
    -- print("RENDER INLINE!")
    self:renderInlineEl(ast, box, parentHl, inherit, extra)
end
---@type Banana.TagInfo
local M = t.newTag(
    "template",
    t.FormatType.Inline,
    false,
    renderer,
    require("banana.nml.tag").defaultInitials()
)

return M
