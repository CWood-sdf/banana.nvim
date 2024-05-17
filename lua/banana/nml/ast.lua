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
---@field style { [string]: Banana.Ncss.Value[] }
---@field hl Banana.Highlight?
---@field padding Banana.Ncss.Value[]
---@field margin Banana.Ncss.Value[]
---@field classes? { [string]: boolean }
---@field precedences { [string]: number }
M.Ast = {
    nodes = {},
    tag = "",
    attributes = {},
    padding = {},
    margin = {},
    classes = nil,
    precedences = {},

}

---@param tag string
---@return Banana.Ast
function M.Ast:new(tag)
    ---@type Banana.Ast
    local ast = {
        precedences = {},
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
---@param basePrec number
function M.Ast:applyStyleDeclarations(declarations, basePrec)
    for _, v in ipairs(declarations) do
        local prec = basePrec
        if v.important then
            prec = prec + require('banana.ncss.query').Specificity.Important
        end
        if self.precedences[v.name] ~= nil and prec < self.precedences[v.name] then
            goto continue
        end
        self.precedences[v.name] = prec
        if v.name:sub(1, 3) == "hl-" then
            self.hl = self.hl or {}
            local name = v.name:sub(4, #v.name)

            local value = v.values[1]
            self.hl[name] = value.value
            -- elseif v.name:sub(1, 8) == "padding-" then
            --     error("Impl padding actually")
            --     local side = v.name:sub(9, #v.name)
            --
            --     local value = v.values[1]
            --     local num = value.value
            --     ---@cast num Banana.Ncss.Value
            --     self.padding[M.nameToIndex(side)] = num.value
            -- elseif v.name:sub(1, 7) == "margin-" then
            --     error("Impl margin actually")
            --     local side = v.name:sub(8, #v.name)
            --
            --     local value = v.values[1]
            --     local num = value.value
            --     ---@cast num number
            --     self.margin[M.nameToIndex(side)] = num
        else
            self.style[v.name] = v.values
        end
        ::continue::
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
