local M = {}
local _str = require('banana.utils.string')

M.left = 1
M.top = 2
M.right = 3
M.bottom = 4
M.padNames = { "left", "top", "right", "bottom" }

---@class (exact) Banana.Ast.BoundingBox
---@field leftX number
---@field topY number
---@field rightX number
---@field bottomY number

---@class (exact) Banana.Ast
---@field nodes (string|Banana.Ast)[]
---@field tag string
---@field attributes Banana.Attributes
---@field actualTag Banana.TagInfo
---@field style { [string]: Banana.Ncss.StyleValue[] }
---@field hl Banana.Highlight?
---@field padding Banana.Ncss.UnitValue[]
---@field margin Banana.Ncss.UnitValue[]
---@field classes? { [string]: boolean }
---@field boundBox? Banana.Ast.BoundingBox
---@field precedences { [string]: number }
---@field instance number?
---@field _parent Banana.Ast
---@field inlineStyle? Banana.Ncss.StyleDeclaration[]
M.Ast = {
    nodes = {},
    tag = "",
    attributes = {},
    inlineStyle = nil,
    padding = {
    },
    margin = {
    },
    classes = nil,
    precedences = {},
}

---@param tag string
---@param parent Banana.Ast
---@return Banana.Ast
function M.Ast:new(tag, parent)
    ---@type Banana.Ast
    local ast = {
        boundBox = nil,
        precedences = {},
        nodes = {},
        tag = tag,
        _parent = parent,
        actualTag = require("banana.nml.tags").makeTag(tag),
        attributes = {},
        instance = nil,
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

function M.Ast:_getInitialStyles()
    local tag = self.actualTag
    return tag.initialProps
end

function M.Ast:defaultStyles()
    self.padding = {
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
    }
    self.margin = {
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
    }
    self.style = {}
    self.hl = nil
    self.precedences = {}
end

---@param ast Banana.Ast
local function applyAstMeta(ast)
    setmetatable(ast, { __index = M.Ast })
    for _, v in ipairs(ast.nodes) do
        if type(v) ~= "string" then
            applyAstMeta(v)
            v._parent = ast
        end
    end
end

---@return Banana.Ast
function M.Ast:clone()
    local newAst = vim.fn.deepcopy(self)
    applyAstMeta(newAst)
    return newAst
end

---@param name string
---@param value string
function M.Ast:setAttribute(name, value)
    if name == "style" then
        vim.notify(
            "Setting the style property using setAttribute does nothing, please use setStyleSlow. Banana will call setStyleSlow for you right now, but it should be explicit",
            vim.log.levels.WARN)
        self:setStyleSlow(value)
        return
    end
    self.attributes[name] = value
end

---THIS FUNCTION TAKES ~1ms TO RUN: DO NOT CALL INSIDE A LOOP
---@param value string
function M.Ast:setStyleSlow(value)
    local parsed = require('banana.ncss.parser').parseText(value)
    self.inlineStyle = parsed[1].declarations
end

---@param name string
---@param value string
function M.Ast:setStyleValue(name, value)
    local p = require('banana.ncss.valueParser')
    ---@type Banana.Ncss.StyleValue
    local cssVal = nil
    if value:sub(1, 1) == '#' then
        cssVal = p.newColorValue(value)
    elseif value:sub(1, 1) == '"' or value:sub(1, 1) == "'" then
        value = value:sub(2, #value)
        value = value:sub(1, #value - 1)
        cssVal = p.newStringValue(value)
    else
        vim.notify("Currently only sting values and color values are supported for ast:setStyleValue",
            vim.log.levels.WARN)
        cssVal = p.newPlainValue(value)
    end
    ---@type Banana.Ncss.StyleDeclaration
    local decl = {
        name = name,
        values = { cssVal },
        important = false,
    }
    if self.inlineStyle == nil then
        self.inlineStyle = {}
    end
    table.insert(self.inlineStyle, decl)
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
    if self.classes[c] == nil then
        return false
    end
    return self.classes[c]
end

---@param c string
function M.Ast:removeClass(c)
    if self.classes == nil then
        self.classes = {}
    end
    if self.classes[c] == true then
        self.classes[c] = false
    end
end

---@param c string
function M.Ast:addClass(c)
    if self.classes == nil then
        self.classes = {}
    end
    self.classes[c] = true
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

---@param unit Banana.Ncss.UnitValue
---@param parentWidth number
---@return Banana.Ncss.UnitValue
function M.calcUnit(unit, parentWidth)
    if unit.unit == "ch" then
        return unit
    elseif unit.unit == "%" then
        local mult = unit.value / 100
        return {
            value = math.floor(mult * parentWidth),
            unit = "ch",
        }
    end
    return unit
    -- error("Undefined unit '" .. unit.unit .. "'")
end

---@param unit Banana.Ncss.UnitValue
---@param parentWidth number
---@return Banana.Ncss.UnitValue
function M.calcUnitNoMod(unit, parentWidth)
    if unit.unit == "ch" then
        return {
            value = unit.value,
            unit = unit.unit,
            computed = unit.value,
        }
    elseif unit.unit == "%" then
        local mult = unit.value / 100
        return {
            value = unit.value,
            computed = math.floor(mult * parentWidth),
            unit = unit.unit,
        }
    end
    return unit
    -- error("Undefined unit '" .. unit.unit .. "'")
end

function M.Ast:getWidth()
    return self.boundBox.rightX - self.boundBox.leftX
end

function M.Ast:getHeight()
    return self.boundBox.bottomY - self.boundBox.topY
end

function M.Ast:_computeUnitFor(prop, basedOn)
    local style = self.style[prop]
    if style ~= nil then
        ---@diagnostic disable-next-line: param-type-mismatch
        style[1].value = M.calcUnitNoMod(style[1].value, basedOn)
    end
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
    self:_computeUnitFor("list-base-width", parentWidth)
    self:_computeUnitFor("width", parentWidth)
    self:_computeUnitFor("height", parentHeight)
end

function M.Ast:applyInlineStyleDeclarations()
    if self.inlineStyle == nil then
        return
    end
    self:applyStyleDeclarations(
        self.inlineStyle,
        require('banana.ncss.query').Specificity.Inline
    )
end

---@return boolean
function M.Ast:isNil()
    return false
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
            if value.type == "plain" and value.value == "inherit" then
                goto continue
            end
            self.hl[name] = value.value
        elseif v.name:sub(1, 8) == "padding-" then
            local side = v.name:sub(9, #v.name)

            local value = v.values[1]
            local index = M[side]
            if index == nil then
                error("Undefined side '" .. side .. "'")
            end
            local val = value.value
            ---@cast val Banana.Ncss.UnitValue
            self.padding[index] = val
        elseif v.name:sub(1, 7) == "margin-" then
            local side = v.name:sub(8, #v.name)

            local value = v.values[1]
            local index = M[side]
            if index == nil then
                error("Undefined side '" .. side .. "'")
            end
            local val = value.value
            ---@cast val Banana.Ncss.UnitValue
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
                ---@cast val Banana.Ncss.UnitValue
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
                ---@cast val Banana.Ncss.UnitValue
                self.padding[i] = val
            end
        else
            self.style[v.name] = v.values
        end
        ::continue::
    end
end

function M.Ast:remove()
    if self._parent == require('banana.render').getNilAst() then
        error("Attempting to remove the root node")
    end
    for i, v in ipairs(self._parent.nodes) do
        if v == self then
            table.remove(self._parent.nodes, i)
            break
        end
    end
    require('banana.render').getInstance(self.instance):removeMapsFor(self)
    self._parent = nil
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
    node._parent = self
    table.insert(self.nodes, node)
    if self.instance ~= nil then
        require('banana.render').getInstance(self.instance):applyId(node)
    end
end

---@return boolean
function M.Ast:isLineHovering()
    local line = vim.fn.line('.')
    local ret =
        line >= self.boundBox.topY
        and line < self.boundBox.bottomY
    return ret
end

---@return boolean
function M.Ast:isHovering()
    local line = vim.fn.line('.')
    local col = vim.fn.col('.')
    local ret =
        line >= self.boundBox.topY
        and line < self.boundBox.bottomY
        and col >= self.boundBox.leftX
        and col < self.boundBox.rightX
    return ret
end

function M.Ast:removeChildren()
    for _, v in ipairs(self.nodes) do
        if type(v) ~= "string" then
            v:remove()
        end
    end
    self.nodes = {}
end

---@return Banana.Ast[]
function M.Ast:children()
    ---@type Banana.Ast[]
    local ret = {}
    for i, v in ipairs(self.nodes) do
        if type(v) ~= "string" then
            table.insert(ret, self.nodes[i])
        end
    end
    return ret
end

---@return Banana.Ast
function M.Ast:child(i)
    for _, v in ipairs(self.nodes) do
        if type(v) ~= "string" then
            if i == 1 then
                return v
            else
                i = i - 1
            end
        end
    end
    return require('banana.render').getNilAst()
end

---@return string
function M.Ast:getTextContent()
    local ret = ""
    for _, v in ipairs(self.nodes) do
        if type(v) == "string" then
            ret = ret .. v
        else
            ret = ret .. v:getTextContent()
        end
    end
    return ret
end

---@param str string
function M.Ast:setTextContent(str)
    self:removeChildren()
    self.nodes = { str }
end

---@param mod Banana.Remap.Constraint
---@return fun(): boolean
function M.Ast:parseRemapMod(mod)
    if mod == "hover" then
        return function()
            return self:isHovering()
        end
    elseif mod == "line-hover" then
        return function()
            return self:isLineHovering()
        end
    elseif type(mod) == "number" then
        return function()
            local count = vim.v.count
            return count == mod
        end
    end
    error("Attempting to use ast remap mod '"
        .. mod .. "' even though it has not been defined")
end

---@return Banana.Ast
function M.Ast:parent()
    return self._parent
end

---@param mode string
---@param lhs string
---@param rhs string|fun()
---@param mods Banana.Remap.Constraint[]
---@param opts vim.keymap.set.Opts
function M.Ast:attachRemap(mode, lhs, mods, rhs, opts)
    if type(mods) ~= "table" then
        error("Banana attachRemap requires the 4th parameter (before rhs) to be a table of modifiers")
    end
    local modFns = vim.iter(mods)
        :map(function(mod) return self:parseRemapMod(mod) end):totable()
    if type(rhs) == "string" then
        local oldRhs = rhs
        rhs = function()
            vim.api.nvim_feedkeys(vim.api.nvim_replace_termcodes(oldRhs, true, true, true), mode, true)
        end
    end
    local actualRhs = function()
        local works = #modFns == 0
        for _, v in ipairs(modFns) do
            if v() then
                works = true
                break
            end
        end
        if not works then return false end
        if type(rhs) == "string" then
            vim.api.nvim_feedkeys(vim.api.nvim_replace_termcodes(rhs, true, true, true), mode, true)
        else
            rhs()
        end
        return true
    end
    local inst = require('banana.render').getInstance(self.instance)
    inst:_setRemap(mode, lhs, actualRhs, opts, self)
end

return M
