---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")

-- this file is here for inline components. it is supposed to injected manually
-- via ast/runtime stuff and not from a user tag

---@type Banana.Renderer
local function renderer(self, ast, box, parentHl,

                        inherit, extra)
    -- flame.new("tag:slot")
    local lastEl = extra.componentStack[#extra.componentStack]
    local renderable = lastEl:_getSlot(ast.attributes["name"])
    local b = require("banana.box")
    if renderable:isNil() then
        local ret = b.Box:new()
        ret.hlgroup = ast:_mixHl(parentHl)
        for _, box, _ in self:blockIter(ast, box, ret.hlgroup, inherit, extra) do
            ret:appendBoxBelow(box)
        end
        -- flame.pop()
        return ret
    end
    local ret = renderable.actualTag:getRendered(renderable, box, parentHl,
        inherit, extra)
    -- flame.pop()
    return ret:render()
end
---@type Banana.TagInfo
local M = t.newTag(
    "slot",
    t.FormatType.Inline,
    false,
    renderer,
    require("banana.nml.tag").defaultInitials()
)

return M
