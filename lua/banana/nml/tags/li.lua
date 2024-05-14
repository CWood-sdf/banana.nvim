local t = require('banana.nml.tags')

---@param self Banana.Ast
---@param ast Banana.Ast
---@param parentHl Banana.Highlight?
---@return Banana.RenderRet
local function renderer(self, ast, parentHl)
    local b = require('banana.box')
    ---@type Banana.RenderRet
    local ret = b.Box:new()
    ret.hlgroup = ast:mixHl(parentHl)

    -- Add the newline
    -- table.insert(ret, {})
    for _, v in ipairs(ast.nodes) do
        if type(v) == 'string' then
            ret:appendStr(v, b.MergeStrategy.Bottom)
        else
            ---@cast v Banana.Ast
            local tag = require('banana.nml.tags').makeTag(v.tag)
            local rendered = tag:render(v, ret.hlgroup)
            ret:append(rendered, b.MergeStrategy.Bottom)
        end
    end
    return ret
end
---@type Banana.TagInfo
local M = {
    name = 'li',
    formatType = t.FormatType.BlockInline,
    selfClosing = false,
    render = renderer
}

return M
