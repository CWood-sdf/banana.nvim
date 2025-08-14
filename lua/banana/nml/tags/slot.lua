---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")
---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")

---@type Banana.Renderer
local function renderer(self, ast, box, parentHl, inherit, extra)
    -- flame.new("tag:slot")
    local lastEl = extra.componentStack[#extra.componentStack]
    local renderable = lastEl:_getSlot(ast:getAttribute("name"))
    if renderable:isNil() then
        for _, _, _ in self:blockIter(ast, box, parentHl, inherit, extra) do
        end
        return
        -- flame.pop()
    end
    local ret = renderable.actualTag:getRendered(renderable, box, parentHl,
        inherit, extra)
    -- flame.pop()
    ret:render()
end
---@type Banana.TagInfo
local M = t.newTag(
    "slot",
    t.FormatType.Block,
    false,
    renderer,
    require("banana.nml.tag").defaultInitials()
)

return M
