-- This file defines what kind of tags are allowed in the Banana language.

local M = {}

---@enum Banana.InlineType
M.Type = {
    Inline = 1,
    Block = 2,
    InlineBlock = 3,
}

---@alias Banana.RenderRet Banana.Word[][]

---@alias Banana.Renderer fun(self: Banana.TagInfo, ast: Banana.Ast):Banana.RenderRet


---@class (exact) Banana.TagInfo
---@field name string
---@field inline Banana.InlineType
---@field selfClosing boolean
---@field render Banana.Renderer
local TagInfo = {
    name = '',
    inline = M.Type.Inline,
    selfClosing = false,
    render = function(_) return {} end,
}



---@param name string
---@param inline Banana.InlineType
---@param selfClosing boolean
---@param renderer Banana.Renderer
function M.newTag(name, inline, selfClosing, renderer)
    ---@type Banana.TagInfo
    local tag = {
        name = name,
        inline = inline,
        selfClosing = selfClosing,
        render = renderer
    }
    setmetatable(tag, { __index = TagInfo })
    return tag
end

---@param name string
---@return boolean
function M.tagExists(name)
    return pcall(require, 'banana.nml.tags.' .. name)
end

---@param ast Banana.Ast|string
---@return string
function M.firstChar(ast)
    if type(ast) == 'string' then
        if string.len(ast) > 0 then
            return string.sub(ast, 1, 1)
        end
        return ''
    end
    if ast.nodes[1] == nil then
        return ''
    end
    ---@cast ast Banana.Ast
    local i = 1
    while M.firstChar(ast.nodes[i]) == '' do
        i = i + 1
        if i > #ast.nodes then
            return ''
        end
    end
    return M.firstChar(ast.nodes[i])
end

---@return Banana.TagInfo
---@param name string
function M.makeTag(name)
    local ok, mgr = pcall(require, 'banana.nml.tags.' .. name)
    if not ok then
        error('Unknown tag: ' .. name)
    end
    return mgr
end

---@param ast Banana.Ast
--- Removes all empty text nodes, and cleans up all whitespace.
function M.cleanAst(ast)
    for i = #ast.nodes, 1, -1 do
        local node = ast.nodes[i]
        if type(node) == 'string' then
            if node:match('^%s*$') then
                table.remove(ast.nodes, i)
            else
                ast.nodes[i] = node:gsub('%s+', ' ')
                node = ast.nodes[i]
                ---@cast node string
                --- If last char is whitespace, and first char of next node is whitespace, remove it.
                if i < #ast.nodes and node:match('%s$') and M.firstChar(ast.nodes[i + 1]):match('%s') then
                    ast.nodes[i] = node:gsub('%s$', '')
                end
            end
        else
            M.cleanAst(node)
        end
    end
end

return M
