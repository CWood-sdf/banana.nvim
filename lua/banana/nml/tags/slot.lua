---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")
---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")

---@type Banana.Renderer
local function renderer(self, ast, parentHl, parentWidth, parentHeight, startX,
                        startY, inherit, extra)
    flame.new("tag:slot")
    local lastEl = extra.componentStack[#extra.componentStack]
    local renderable = lastEl:getSlot(ast.attributes["name"])
    if renderable == nil then
        log.throw("Could not find slot replacement")
        error()
    end
    local ret = renderable.actualTag:getRendered(ast, parentHl, parentWidth,
        parentHeight, startX, startY, inherit, extra)
    flame.pop()
    return ret:render()
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
