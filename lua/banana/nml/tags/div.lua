local t = require('banana.nml.tags')

---@param self Banana.Ast
---@param ast Banana.Ast
---@return Banana.RenderRet
local function renderer(self, ast)
    local ret = {}
    -- keep track of what the last tag type was, then insert newlines as necessary rather than doing whatever we are doing rn
    ---@type "inline"|"block"|"text"
    local lastTag = "inline"

    -- Add the newline
    local currentLine = {}
    for _, v in ipairs(ast.nodes) do
        if type(v) == 'string' then
            if lastTag == "block" then
                table.insert(ret, currentLine)
                currentLine = {}
            end
            table.insert(currentLine, { word = v })
            lastTag = "text"
        else
            local tag = t.makeTag(v.tag)
            local rendered = tag:render(v)
            local isBlock = tag.formatType == t.FormatType.BlockInline or tag.formatType == t.FormatType.Block
            if isBlock then
                table.insert(ret, currentLine)
                currentLine = {}
            end
            ---@cast v Banana.Ast
            for _, line in ipairs(rendered[1]) do
                table.insert(currentLine, { word = line.word })
            end
            if #rendered > 1 then
                table.insert(ret, currentLine)
                currentLine = {}
                for i = 2, #rendered - 1 do
                    table.insert(ret, rendered[i])
                end
                for _, line in ipairs(rendered[#rendered]) do
                    table.insert(currentLine, { word = line.word })
                end
            end
            if isBlock then
                lastTag = "block"
            else
                lastTag = "inline"
            end
        end
    end
    table.insert(ret, currentLine)
    return ret
end
---@type Banana.TagInfo
local M = {
    name = 'div',
    formatType = t.FormatType.Block,
    selfClosing = false,
    render = renderer
}

return M
