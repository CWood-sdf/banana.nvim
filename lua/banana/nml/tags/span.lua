local t = require('banana.nml.tags')

---@param self Banana.Ast
---@param ast Banana.Ast
---@return Banana.RenderRet
local function renderer(self, ast)
    local ret = {}

    local currentLine = {}
    for _, v in ipairs(ast.nodes) do
        if type(v) == 'string' then
            table.insert(currentLine, { word = v })
        else
            ---@cast v Banana.Ast
            local tag = require('banana.nml.tags').makeTag(v.tag)
            local rendered = tag:render(v)
            for _, line in ipairs(rendered[1]) do
                table.insert(currentLine, { word = line.word })
            end
            if #rendered > 1 then
                table.insert(ret, currentLine)
                currentLine = {}
                for i = 2, #rendered do
                    table.insert(ret, rendered[i])
                end
            end
        end
    end
    if #currentLine > 0 then
        table.insert(ret, currentLine)
        currentLine = {}
    end
    return ret
end
---@type Banana.TagInfo
local M = {
    name = 'span',
    inline = t.Type.Inline,
    selfClosing = false,
    render = renderer
}

return M
