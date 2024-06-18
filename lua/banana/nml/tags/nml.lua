local t = require('banana.nml.tags')

---@type Banana.Renderer
local function renderer(self, ast, parentHl, parentWidth, parentHeight, startX, startY, inherit, extra)
    local b = require('banana.box')
    ---@type Banana.Box
    local ret = b.Box:new()
    for _, node in ipairs(ast.nodes) do
        if type(node) == "string" then
            goto continue
        end
        ---@cast node Banana.Ast
        if node.tag == "head" then
            node.actualTag:renderRoot(node, parentHl, parentWidth, parentHeight, startX, startY)
        elseif node.tag == "body" then
            ret = node.actualTag:getRendered(node, parentHl, parentWidth, parentHeight, startX, startY, inherit, extra)
        elseif node.tag ~= "script" and node.tag ~= "style" then
            error("Only <head> and <body> tags allowed in <nml>, instead got <" .. node.tag .. ">")
        end
        ::continue::
    end
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    'nml',
    t.FormatType.Block,
    false,
    renderer,
    require('banana.nml.tags').defaultInitials()
)

return M
