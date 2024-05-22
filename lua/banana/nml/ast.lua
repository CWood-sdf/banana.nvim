local _str = require('banana.utils.string')
local M = {}

M.left = 1
M.top = 2
M.right = 3
M.bottom = 4
M.padNames = { "left", "top", "right", "bottom" }

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
    padding = {
    },
    margin = {
    },
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
        padding = {
            {
                value = 0,
                unit = "ch",
            },
            {
                value = 0,
                unit = "ch",
            },
            {
                value = 0,
                unit = "ch",
            },
            {
                value = 0,
                unit = "ch",
            },
        },
        margin = {
            {
                value = 0,
                unit = "ch",
            },
            {
                value = 0,
                unit = "ch",
            },
            {
                value = 0,
                unit = "ch",
            },
            {
                value = 0,
                unit = "ch",
            },
        },
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

---@param unit Banana.Ncss.Value
---@param parentWidth number
---@return Banana.Ncss.Value
function M.calcUnit(unit, parentWidth)
    if unit.unit == "ch" then
        return unit
    elseif unit.unit == "%" then
        local mult = unit.value / 100
        return {
            value = mult * parentWidth,
            unit = "ch",
        }
    end
    error("Undefined unit '" .. unit.unit .. "'")
end

---@param parentWidth number
---@param parentHeight number
function M.Ast:resolveUnits(parentWidth, parentHeight)
    for i, v in ipairs(self.margin) do
        if i % 2 == 1 then
            self.margin[i] = M.calcUnit(v, parentWidth)
        else
            self.margin[i] = M.calcUnit(v, parentHeight)
        end
    end
    for i, v in ipairs(self.padding) do
        if i % 2 == 1 then
            self.padding[i] = M.calcUnit(v, parentWidth)
        else
            self.padding[i] = M.calcUnit(v, parentHeight)
        end
    end
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
            local name = v.name:sub(4, _str.charCount(v.name))

            local value = v.values[1]
            self.hl[name] = value.value
        elseif v.name:sub(1, 8) == "padding-" then
            local side = v.name:sub(9, #v.name)

            local value = v.values[1]
            local index = M[side]
            if index == nil then
                error("Undefined side '" .. side .. "'")
            end
            local val = value.value
            ---@cast val Banana.Ncss.Value
            self.padding[index] = val
        elseif v.name:sub(1, 7) == "margin-" then
            local side = v.name:sub(8, #v.name)

            local value = v.values[1]
            local index = M[side]
            if index == nil then
                error("Undefined side '" .. side .. "'")
            end
            local val = value.value
            ---@cast val Banana.Ncss.Value
            self.margin[index] = val
        elseif v.name == "margin" then
            for i, _ in ipairs(self.margin) do
                local name = "margin-" .. M.padNames[i]
                local offset = i - 1
                local values = v.values
                local fromArr = values[offset % #values + 1]
                local val = fromArr.value
                if self.precedences[name] ~= nil and prec < self.precedences[name] then
                    goto continue
                end
                self.precedences[name] = prec
                ---@cast val Banana.Ncss.Value
                self.margin[i] = val
            end
        elseif v.name == "padding" then
            for i, _ in ipairs(self.padding) do
                local name = "padding-" .. M.padNames[i]
                local offset = i - 1
                local values = v.values
                local fromArr = values[offset % #values + 1]
                local val = fromArr.value
                if self.precedences[name] ~= nil and prec < self.precedences[name] then
                    goto continue
                end
                self.precedences[name] = prec
                ---@cast val Banana.Ncss.Value
                self.padding[i] = val
            end
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
