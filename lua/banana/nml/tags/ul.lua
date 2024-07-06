-- local _str = require('banana.utils.string')
local t = require('banana.nml.tags')

---@type Banana.Renderer
local function renderer(self, ast, parentHl, parentWidth, parentHeight, startX, startY, inherit, extra)
    local b = require('banana.box')
    ---@type Banana.Box
    local ret = b.Box:new()
    ret.hlgroup = ast:mixHl(parentHl)

    ---@type string
    -- local listType = "* "
    -- if ast.style["list-style-type"] ~= nil then
    --     ---@diagnostic disable-next-line: cast-local-type
    --     listType = ast.style["list-style-type"][1].value
    -- end
    -- ---@cast listType string
    -- local numSize = 5
    -- if ast.style["list-base-width"] ~= nil then
    --     numSize = ast.style["list-base-width"][1].value.computed
    --     ---@cast numSize number
    -- end
    for _, box, _ in self:blockIter(ast, ret.hlgroup, parentWidth, parentHeight, startX, startY, inherit, extra) do
        -- local v = ast.nodes[i]
        -- local currentLine = b.Box:new(ret.hlgroup)
        -- if type(v) ~= "string" and v.actualTag.name == 'li' then
        --     currentLine:appendStr("", nil)
        --     currentLine:expandWidthTo(numSize - _str.charWidth(listType))
        --     currentLine:appendStr(listType, nil)
        -- end
        -- currentLine:expandWidthTo(numSize)
        -- currentLine:append(box, b.MergeStrategy.Bottom)
        ret:appendBoxBelow(box)
    end
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    'ul',
    t.FormatType.Block,
    false,
    renderer,
    require('banana.nml.tags').defaultInitials()
)

return M
