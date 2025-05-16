---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")

---@type Banana.Renderer
local function renderer(self, ast, box, parentHl, parentWidth, parentHeight,
                        startX,
                        startY, inherit, extra)
    -- flame.new("tag:div")
    local hl = ast:_mixHl(parentHl)
    box:setHl(hl)
    for _, _, _ in self:blockIter(ast, box, hl, parentWidth, parentHeight, startX, startY, inherit, extra) do
        -- ret:appendBoxBelow(box)
    end
    -- flame.expect("tag:div")
    -- flame.pop()
    return box
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
