---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")

---@type Banana.Renderer
local function renderer(self, ast, box, parentHl, inherit, extra)
    -- flame.new("tag:div")
    for _, _, _ in self:blockIter(ast, box, parentHl, inherit, extra) do
        -- ret:appendBoxBelow(box)
    end
    -- flame.expect("tag:div")
    -- flame.pop()
    -- return box
end
---@type Banana.TagInfo
local M = t.newTag(
    "div",
    t.FormatType.Block,
    false,
    renderer,
    require("banana.nml.tag").defaultInitials()
)

return M
