local _str = require('banana.utils.string')
local t = require('banana.nml.tags')

---@type Banana.Renderer
local function renderer(self, ast, parentHl, parentWidth, parentHeight, startX, startY, inherit)
    local b = require('banana.box')
    ---@type Banana.Box
    local ret = b.Box:new()
    ret.hlgroup = ast:mixHl(parentHl)

    local count = 1
    local numSize = 5
    if ast.style["list-base-width"] ~= nil then
        numSize = ast.style["list-base-width"][1].value.computed
        ---@cast numSize number
    end
    for i, box, _ in self:blockIter(ast, ret.hlgroup, parentWidth - numSize, parentHeight, startX, startY, inherit) do
        local v = ast.nodes[i]
        local currentLine = b.Box:new(ret.hlgroup)
        if type(v) ~= "string" and t.makeTag(v.tag).name == 'li' then
            local str = count .. ". "
            currentLine:appendStr("", nil)
            currentLine:expandWidthTo(numSize - _str.charCount(str))
            currentLine:appendStr(count .. ". ", nil)
            count = count + 1
        end
        currentLine:expandWidthTo(numSize)
        currentLine:append(box, b.MergeStrategy.Bottom)
        ret:appendBoxBelow(currentLine)
    end
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    'ol',
    t.FormatType.Block,
    false,
    renderer,
    require('banana.nml.tags').defaultInitials()
)

return M
