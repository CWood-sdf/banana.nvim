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
    local renderable = lastEl:_getSlot(ast.attributes["name"])
    local b = require("banana.box")
    if renderable:isNil() then
        local ret = b.Box:new()
        for _, _, _ in self:blockIter(ast, box, parentHl, inherit, extra) do
        end
        -- flame.pop()
        return ret
    end
    local ret = renderable.actualTag:getRendered(renderable, box, parentHl,
        inherit, extra)
    -- flame.pop()
    ret:render()
    return ret.center
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
