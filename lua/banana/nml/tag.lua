local M = {}
---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
---@module 'banana.nml.render'
local r = require("banana.lazyRequire")("banana.nml.render")
---@module 'banana.box'
local b = require("banana.lazyRequire")("banana.box")

---@enum Banana.Nml.FormatType
M.FormatType = {
    Inline = 1,
    Block = 2,
    -- InlineBlock = 3,
    BlockInline = 4,
    Script = 5,
}

---@param name string
---@param inline Banana.Nml.FormatType
---@param selfClosing boolean
---@param renderer Banana.Renderer
---@param initialProps Banana.Renderer.InitialProperties
function M.newTag(name, inline, selfClosing, renderer, initialProps)
    ---@type Banana.TagInfo
    local tag = {
        name = name,
        formatType = inline,
        selfClosing = selfClosing,
        render = renderer,
        initialProps = initialProps,
    }
    setmetatable(tag, { __index = r.TagInfo })
    return tag
end

---@param name string
function M.newComponentTag(name)
    return M.newTag(name,
        M.FormatType.Block, false,
        function () return b.Box:new() end,
        M.defaultInitials())
end

---@return Banana.Renderer.InitialProperties
function M.defaultInitials()
    ---@type Banana.Renderer.InitialProperties
    local initialProps = {
        flex_shrink = 1,
        flex_wrap = "nowrap",
        text_align = "left",
        position = "static",
    }
    return initialProps
end

---@param name string
---@return boolean
function M.tagExists(name)
    return pcall(require, "banana.nml.tags." .. name)
end

---@param ast Banana.Ast|string
---@return string
function M.firstChar(ast)
    if type(ast) == "string" then
        if string.len(ast) > 0 then
            return string.sub(ast, 1, 1)
        end
        return ""
    end
    if ast.nodes[1] == nil then
        return ""
    end
    ---@cast ast Banana.Ast
    local i = 1
    while M.firstChar(ast.nodes[i]) == "" do
        i = i + 1
        if i > #ast.nodes then
            return ""
        end
    end
    return M.firstChar(ast.nodes[i])
end

---@param name string
---@return Banana.TagInfo
function M.makeTag(name)
    local ok, mgr = pcall(require, "banana.nml.tags." .. name)
    if not ok then
        log.throw(
            "Error while trying to load tag '" .. name .. "': " .. mgr)
        error("")
    end
    return mgr
end

return M
