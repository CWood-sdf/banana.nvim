local M = {}

---@param name string
---@return number
M.nameToIndex = function(name)
    if name == "left" then
        return 1
    elseif name == "top" then
        return 2
    elseif name == "right" then
        return 3
    elseif name == "bottom" then
        return 4
    end
    return 0
end

---@class (exact) Banana.Ast
---@field nodes (string|Banana.Ast)[]
---@field tag string
---@field attributes Banana.Attributes
---@field actualTag Banana.TagInfo
---@field style Banana.Ncss.StyleDeclaration[]
---@field hl Banana.Highlight?
---@field padding number[]
---@field margin number[]
---@field classes? { [string]: boolean }
M.Ast = {
    nodes = {},
    tag = "",
    attributes = {},
    padding = {},
    margin = {},
    classes = nil,
}

---@param tag string
---@return Banana.Ast
function M.Ast:new(tag)
    ---@type Banana.Ast
    local ast = {
        nodes = {},
        tag = tag,
        actualTag = require("banana.nml.tags").makeTag(tag),
        attributes = {},
        padding = {},
        margin = {},
        style = {},
    }
    setmetatable(ast, { __index = M.Ast })
    return ast
end

---@param c string
---@return boolean
function M.Ast:hasClass(c)
    if self.classes == nil and self.attributes["class"] ~= nil then
        local arr = vim.split(self.attributes["class"], ' ')
        self.classes = {}
        for _, v in ipairs(arr) do
            self.classes[v] = true
        end
    elseif self.classes == nil then
        self.classes = {}
    end
    return self.classes[c] or false
end

---@param parentHl Banana.Highlight?
---@return Banana.Highlight
function M.Ast:mixHl(parentHl)
    local ret = {}

    for k, v in pairs(self.hl or {}) do
        ret[k] = v
    end
    for k, v in pairs(parentHl or {}) do
        if ret[k] == nil then
            ret[k] = v
        end
    end
    return ret
end

---@param declarations Banana.Ncss.StyleDeclaration[]
function M.Ast:applyStyleDeclarations(declarations)
    for _, v in ipairs(declarations) do
        if v.name:sub(1, 3) == "hl-" then
            self.hl = self.hl or {}
            local name = v.name:sub(4, #v.name)

            local value = v.values[1]
            self.hl[name] = value.value
        elseif v.name:sub(1, 8) == "padding-" then
            local side = v.name:sub(8, #v.name)

            local value = v.values[1]
            local num = value.value
            ---@cast num number
            self.padding[M.nameToIndex(side)] = num
        elseif v.name:sub(1, 7) == "margin-" then
            local side = v.name:sub(7, #v.name)

            local value = v.values[1]
            local num = value.value
            ---@cast num number
            self.margin[M.nameToIndex(side)] = num
        end
    end
end

---@param name string
---@return string?
function M.Ast:getAttribute(name)
    return self.attributes[name]
end

---@param text string
function M.Ast:appendTextNode(text)
    table.insert(self.nodes, text)
end

---@param node Banana.Ast
function M.Ast:appendNode(node)
    table.insert(self.nodes, node)
end

return M
