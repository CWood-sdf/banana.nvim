---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")

---@type Banana.Renderer
local function renderer(_, ast, parentHl, parentWidth, parentHeight, startX,
                        startY, inherit, extra)
    local b = require("banana.box")
    parentHl = ast:_mixHl(parentHl)
    -- flame.new("tag:nml")
    -- -@type Banana.Box
    local ret = b.Box:new(parentHl)
    for node in ast:childIter() do
        ---@cast node Banana.Ast
        if node.tag == "head" then
            node.actualTag:renderRoot(node, parentHl, parentWidth, parentHeight,
                inherit, extra)
        elseif node.tag == "body" then
            node:_resolveUnits(parentWidth, parentHeight)
            ret = node.actualTag:getRendered(node, parentHl, parentWidth,
                    parentHeight, startX, startY, inherit, extra)
                      :render()
        elseif node.tag ~= "script" and node.tag ~= "style" then
            -- flame.pop()
            error("Only <head> and <body> tags allowed in <nml>, instead got <" ..
                node.tag .. ">")
        end
    end
    -- flame.expect("tag:nml")
    -- flame.pop()
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    "nml",
    t.FormatType.Block,
    false,
    renderer,
    require("banana.nml.tag").defaultInitials()
)

return M
