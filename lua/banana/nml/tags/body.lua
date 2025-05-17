---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")

---@type Banana.Renderer
local function renderer(self, ast, box, parentHl, inherit, extra)
    flame.new("tag:body")
    if not extra.isRealRender then
        flame.pop()
        return
    end
    -- local ret = box:newAtOffset(0, 0)
    -- ret:setHl(hl)
    for _, _, _ in self:blockIter(ast, box, parentHl, inherit, extra) do
    end
    -- if box:height() < parentHeight then
    --     box:expandHeightTo(parentHeight)
    -- end
    -- if box:width() < parentWidth then
    --     box:expandWidthTo(parentWidth)
    -- end
    flame.pop()
end
---@type Banana.TagInfo
local M = t.newTag(
    "body",
    t.FormatType.Block,
    false,
    renderer,
    require("banana.nml.tag").defaultInitials()
)

return M
