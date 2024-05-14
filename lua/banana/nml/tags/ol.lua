local t = require('banana.nml.tags')

---@param self Banana.Ast
---@param ast Banana.Ast
---@param parentHl Banana.Highlight?
---@return Banana.RenderRet
local function renderer(self, ast, parentHl)
    local b = require('banana.box')
    ---@type Banana.Box
    local ret = b.Box:new()
    ret.hlgroup = ast:mixHl(parentHl)
    -- keep track of what the last tag type was, then insert newlines as necessary rather than doing whatever we are doing rn
    ---@type "inline"|"block"|"text"
    local lastTag = "inline"

    local count = 1

    -- Add the newline
    ---@type Banana.Box
    local currentLine = b.Box:new(ret.hlgroup)
    for _, v in ipairs(ast.nodes) do
        if type(v) == 'string' then
            if lastTag == "block" then
                ret:appendBoxBelow(currentLine)
                currentLine = b.Box:new(ret.hlgroup)
            end
            currentLine:appendStr(v, b.MergeStrategy.Bottom)
            lastTag = "text"
        else
            local tag = t.makeTag(v.tag)
            local rendered = tag:render(v, ret.hlgroup)
            local isBlock = tag.formatType == t.FormatType.BlockInline or tag.formatType == t.FormatType.Block
            if isBlock then
                ret:appendBoxBelow(currentLine)
                currentLine = b.Box:new(ret.hlgroup)
            end
            if tag.name == 'li' then
                local str = count .. ". "
                currentLine:appendStr("", nil)
                currentLine:expandWidthTo(5 - #str)
                currentLine:appendStr(count .. ". ", nil)
                count = count + 1
            end
            currentLine:expandWidthTo(5)
            currentLine:append(rendered, b.MergeStrategy.Bottom)
            if isBlock then
                lastTag = "block"
            else
                lastTag = "inline"
            end
        end
    end
    ret:appendBoxBelow(currentLine)
    return ret
end
---@type Banana.TagInfo
local M = {
    name = 'ol',
    formatType = t.FormatType.Block,
    selfClosing = false,
    render = renderer
}

return M
