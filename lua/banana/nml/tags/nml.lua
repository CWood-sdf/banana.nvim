---@module 'banana.utils.debug_flame'
local flame = require('banana.lazyRequire')('banana.utils.debug_flame')
---@module 'banana.nml.render'
local t = require('banana.lazyRequire')('banana.nml.render')

---@type Banana.Renderer
local function renderer(self, ast, parentHl, parentWidth, parentHeight, startX, startY, inherit, extra)
    flame.new("tag:nml")
    local b = require('banana.box')
    ---@type Banana.Box
    local ret = b.Box:new()
    for _, node in ipairs(ast.nodes) do
        if type(node) == "string" then
            goto continue
        end
        ---@cast node Banana.Ast
        if node.tag == "head" then
            node.actualTag:renderRoot(node, parentHl, parentWidth, parentHeight, inherit, extra)
        elseif node.tag == "body" then
            node:_resolveUnits(parentWidth, parentHeight)
            ret = node.actualTag:getRendered(node, parentHl, parentWidth, parentHeight, startX, startY, inherit, extra)
                :render()
        elseif node.tag ~= "script" and node.tag ~= "style" then
            error("Only <head> and <body> tags allowed in <nml>, instead got <" .. node.tag .. ">")
        end
        ::continue::
    end
    flame.pop()
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    'nml',
    t.FormatType.Block,
    false,
    renderer,
    require('banana.nml.render').defaultInitials()
)

return M
