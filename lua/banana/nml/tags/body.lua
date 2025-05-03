---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")

---@type Banana.Renderer
local function renderer(self, ast, box, parentHl, parentWidth, parentHeight,
                        startX,
                        startY, inherit, extra)
    -- flame.new("tag:body")
    if not extra.isRealRender then
        return box:newToRight()
    end
    local hl = ast:_mixHl(parentHl)
    local ret = box:newAtOffset(0, 0)
    ret:setHl(hl)
    for _, _, _ in self:blockIter(ast, ret, hl, parentWidth, parentHeight, startX, startY, inherit, extra) do
    end
    if ret:height() < parentHeight then
        ret:expandHeightTo(parentHeight)
    end
    if ret:width() < parentWidth then
        ret:expandWidthTo(parentWidth)
    end
    -- flame.pop()
    return ret
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
