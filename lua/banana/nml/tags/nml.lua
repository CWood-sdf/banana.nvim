---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")

---@type Banana.Renderer
local function renderer(_, ast, box, parentHl,
                        inherit, extra)
    parentHl = ast:_mixHl(parentHl)
    -- flame.new("tag:nml")
    -- -@type Banana.Box
    for node in ast:childIter() do
        ---@cast node Banana.Ast
        if node.tag == "head" then
            node.actualTag:renderRoot(node, box, parentHl,

                inherit, extra)
        elseif node.tag == "body" then
            node:_resolveUnits(box:getMaxWidth(), box:getMaxHeight())
            local pr = node.actualTag:getRendered(node, box, parentHl,
                inherit, extra)
            pr:render()
        elseif node.tag ~= "script" and node.tag ~= "style" then
            -- flame.pop()
            error("Only <head> and <body> tags allowed in <nml>, instead got <" ..
                node.tag .. ">")
        end
    end
    -- flame.expect("tag:nml")
    -- flame.pop()
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
