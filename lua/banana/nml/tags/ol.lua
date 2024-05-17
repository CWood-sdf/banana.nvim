local t = require('banana.nml.tags')

---@param self Banana.TagInfo
---@param ast Banana.Ast
---@param parentHl Banana.Highlight?
---@return Banana.RenderRet
local function renderer(self, ast, parentHl)
    local b = require('banana.box')
    ---@type Banana.Box
    local ret = b.Box:new()
    ret.hlgroup = ast:mixHl(parentHl)

    local count = 1
    for i, box, _ in self:blockIter(ast, ret.hlgroup) do
        local v = ast.nodes[i]
        local currentLine = b.Box:new(ret.hlgroup)
        if type(v) ~= "string" and t.makeTag(v.tag).name == 'li' then
            local str = count .. ". "
            currentLine:appendStr("", nil)
            currentLine:expandWidthTo(5 - #str)
            currentLine:appendStr(count .. ". ", nil)
            count = count + 1
        end
        currentLine:expandWidthTo(5)
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
    renderer
)

return M
