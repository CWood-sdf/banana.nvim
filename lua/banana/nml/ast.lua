---@module 'banana.utils.debug_flame'
local flame = require('banana.lazyRequire')('banana.utils.debug_flame')
---@module 'banana.utils.log'
local log = require('banana.lazyRequire')('banana.utils.log')
local M = {}
---@module 'banana.utils.string'
local _str = require('banana.lazyRequire')('banana.utils.string')

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
---@field private padding Banana.Ncss.UnitValue[]
---@field private margin Banana.Ncss.UnitValue[]
---@field classes? { [string]: boolean }
---@field boundBox? Banana.Ast.BoundingBox
---@field precedences { [string]: number }
---@field instance number?
---@field _parent Banana.Ast
---@field inlineStyle? Banana.Ncss.StyleDeclaration[]
---@field absoluteAsts? Banana.Ast[]
---@field relativeBoxId? number
---@field relativeBoxes? { box: Banana.Box, left: number, top: number, z: number}[]
---@field listCounter? number
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
        actualTag = require("banana.nml.render").makeTag(tag),
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
    if tag == "ol" then
        ast.listCounter = 1
    end
    setmetatable(ast, { __index = M.Ast })
    return ast
end

---@return Banana.Ncss.StyleValue?
---@param style string
function M.Ast:firstStyle(style)
    if self.style[style] == nil then
        return nil
    end
    return self.style[style][1]
end

---@param style string
---@param default Banana.Ncss.StyleValueType
---@return Banana.Ncss.StyleValueType
---@overload fun(self: Banana.Ast, style: string): Banana.Ncss.StyleValueType?
function M.Ast:firstStyleValue(style, default)
    local val = self:firstStyle(style)
    if val == nil and default ~= nil then
        return default
    end
    if val == nil then
        return nil
    end
    return val.value
end

---@param style string
---@return boolean
function M.Ast:hasStyle(style)
    return self.style[style] ~= nil
end

function M.Ast:assertHasStyle(style)
    if self:firstStyle(style) == nil then
        log.assert(false, "needs style")
        error("")
    end
end

---@return number
function M.Ast:_boundBottom()
    return self.padding[M.bottom].computed
end

---@return number
function M.Ast:_extraBottom()
    return self:_boundBottom() + self.margin[M.bottom].computed
end

---@return number
function M.Ast:_boundTop()
    return self.padding[M.top].computed
end

---@return number
function M.Ast:_extraTop()
    return self:_boundTop() + self.margin[M.top].computed
end

function M.Ast:_boundTb()
    return self:_boundTop() + self:_boundBottom()
end

function M.Ast:_extraTb()
    return self:_extraTop() + self:_extraBottom()
end

function M.Ast:_boundLr()
    return self:_boundLeft() + self:_boundRight()
end

function M.Ast:_extraLr()
    return self:_extraLeft() + self:_extraRight()
end

---@return number
function M.Ast:_boundRight()
    return self.padding[M.right].computed
end

---@return number
function M.Ast:_extraRight()
    return self:_boundRight() + self.margin[M.right].computed
end

---@return number
function M.Ast:_boundLeft()
    return self.padding[M.left].computed
end

---@return number
function M.Ast:_extraLeft()
    return self:_boundLeft() + self.margin[M.left].computed
end

function M.Ast:_getInitialStyles()
    local tag = self.actualTag
    return tag.initialProps
end

function M.Ast:paddingLeft()
    return self.padding[M.left].computed
end

function M.Ast:paddingRight()
    return self.padding[M.right].computed
end

function M.Ast:paddingTop()
    return self.padding[M.top].computed
end

function M.Ast:paddingBottom()
    return self.padding[M.bottom].computed
end

function M.Ast:marginLeft()
    return self.margin[M.left].computed
end

function M.Ast:marginRight()
    return self.margin[M.right].computed
end

function M.Ast:marginTop()
    return self.margin[M.top].computed
end

function M.Ast:marginBottom()
    return self.margin[M.bottom].computed
end

---@param i number
---@return Banana.Ncss.UnitValue
function M.Ast:_marginUnit(i)
    return self.margin[i]
end

---@param styleTp string
---@return string
local function getListItemUl(styleTp)
    if _str.charWidth(styleTp) < 3 then
        return styleTp
    end
    if styleTp == "star" then
        return "*"
    elseif styleTp == "dash" then
        return "-"
    end
    return "*"
end

---@param num number
---@return string
function M.numToRoman(num)
    local roman = {
        { 1000, "M" },
        { 900,  "CM" },
        { 500,  "D" },
        { 400,  "CD" },
        { 100,  "C" },
        { 90,   "XC" },
        { 50,   "L" },
        { 40,   "XL" },
        { 10,   "X" },
        { 9,    "IX" },
        { 5,    "V" },
        { 4,    "IV" },
        { 1,    "I" },
    }
    local ret = ""
    for _, v in ipairs(roman) do
        while num >= v[1] do
            ret = ret .. v[2]
            num = num - v[1]
        end
    end
    return ret
end

---@param styleTp string
---@param counter number
---@return string
local function getListItemOl(styleTp, counter)
    if styleTp == "Roman" then
        return M.numToRoman(counter) .. "."
    end
    if styleTp == "roman" then
        return string.lower(M.numToRoman(counter) .. ".")
    end
    if styleTp == "Alpha" then
        local code = string.byte('A') + counter
        return string.char(code) .. "."
    end
    if styleTp == "alpha" then
        local code = string.byte('a') + counter
        return string.char(code) .. "."
    end
    if _str.codepointLen(styleTp:sub(1, 1)) == #styleTp then
        local code = string.byte(styleTp, 1, #styleTp) + counter
        return string.char(code)
    end
    return counter .. "."
end

---Returns a heuristic *guess* at the biggest list item for ol
---Accurate for ul
---@return number
function M.Ast:_getMaxListWidth(styleTp)
    if self.listCounter == nil then
        return _str.charWidth(getListItemUl(styleTp)) + 1
    end
    local len = #self.nodes
    if styleTp == "alpha" or styleTp == "Alpha" then
        return 3
    end
    if styleTp == "roman" or styleTp == "Roman" then
        -- if someone has roman numerals going to over 888 then im kinda scared
        if len >= 888 then
            local add = math.floor((len - 888) / 1000)
            return add + 12
        end
        if len >= 388 then return 11 end
        if len >= 288 then return 10 end
        if len >= 188 then return 9 end
        if len >= 88 then return 8 end
        if len >= 38 then return 7 end
        if len >= 28 then return 6 end
        if len >= 18 then return 5 end
        if len >= 8 then return 4 end
        if len >= 3 then return 3 end
        if len >= 2 then return 2 end
        if len >= 1 then return 1 end
        return 0
    end

    return math.ceil(math.log10(len)) + 2
end

---@param styleTp string
---@return string
function M.Ast:_getNextListItem(styleTp, extra)
    if self.tag == "ol" and self.listCounter == nil then
        self.listCounter = 1
    end
    if self.listCounter == nil then
        return getListItemUl(styleTp) .. " "
    end
    local ret        = getListItemOl(styleTp, self.listCounter) .. ' '
    self.listCounter = self.listCounter + 1
    return ret
end

function M.Ast:_defaultStyles()
    if self.listCounter ~= nil then
        self.listCounter = 1
    end
    self.padding = {
        {
            value = 0,
            computed = 0,
            unit = "ch",
        },
        {
            value = 0,
            computed = 0,
            unit = "ch",
        },
        {
            value = 0,
            computed = 0,
            unit = "ch",
        },
        {
            value = 0,
            computed = 0,
            unit = "ch",
        },
    }
    self.margin = {
        {
            value = 0,
            computed = 0,
            unit = "ch",
        },
        {
            value = 0,
            computed = 0,
            unit = "ch",
        },
        {
            value = 0,
            computed = 0,
            unit = "ch",
        },
        {
            value = 0,
            computed = 0,
            unit = "ch",
        },
    }
    self.style = {}
    self.hl = nil
    self.precedences = {}
end

function M.Ast:_clearStyles()
    self:_defaultStyles()
    for node in self:childIter() do
        node:_clearStyles()
    end
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
    local newAst = {}
    newAst.nodes = {}
    for _, v in ipairs(self.nodes) do
        if type(v) ~= "string" then
            table.insert(newAst.nodes, v:clone())
        else
            table.insert(newAst.nodes, v)
        end
    end
    newAst.tag = self.tag
    newAst.attributes = vim.fn.deepcopy(self.attributes)
    newAst.actualTag = self.actualTag
    newAst.style = vim.fn.deepcopy(self.style)
    newAst.hl = vim.fn.deepcopy(self.hl)
    newAst.padding = vim.fn.deepcopy(self.padding)
    newAst.margin = vim.fn.deepcopy(self.margin)
    if self.classes ~= nil then
        newAst.classes = vim.fn.deepcopy(self.classes)
    end
    newAst.instance = self.instance
    newAst._parent = require('banana.instance').getNilAst()
    if self.inlineStyle ~= nil then
        newAst.inlineStyle = vim.fn.deepcopy(self.inlineStyle)
    end
    if self.listCounter ~= nil then
        newAst.listCounter = 1
    end
    applyAstMeta(newAst)
    ---@cast newAst Banana.Ast
    newAst:_clearStyles()
    return newAst
end

---@param name string
---@param value string
function M.Ast:setAttribute(name, value)
    if name == "style" then
        vim.notify(
            "Setting the style property using setAttribute does nothing, please use setStyleSlow. Banana will call setStyleSlow for you right now, but it should be explicit",
            vim.log.levels.WARN)
        self:setStyle(value)
        return
    end
    self.attributes[name] = value
    self:_requestRender()
end

---@param value string
function M.Ast:setStyle(value)
    local parsed = require('banana.ncss.parser').parseText(value)
    self.inlineStyle = parsed[1].declarations
    self:_requestRender()
end

---@param name string
---@param value string
function M.Ast:setStyleValue(name, value)
    local text = name .. ": " .. value .. ';'
    local parsed = require('banana.ncss.parser').parseText(text)
    local decl = parsed[1].declarations[1]
    local found = false
    for i, v in ipairs(self.inlineStyle) do
        if v.name == decl.name then
            self.inlineStyle[i] = decl
            found = true
        end
    end
    if not found then
        table.insert(self.inlineStyle, decl)
    end
    self:_requestRender()
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
        self:_requestRender()
    end
end

---@param c string
function M.Ast:addClass(c)
    if self.classes == nil then
        self.classes = {}
    end
    if not self.classes[c] then
        self.classes[c] = true
        self:_requestRender()
    end
end

---@param parentHl Banana.Highlight?
---@return Banana.Highlight
function M.Ast:_mixHl(parentHl)
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

-- function M.calcUnit(unit, parentWidth, extras)
--     if unit.unit == "ch" then
--         return unit
--     elseif unit.unit == "%" then
--         local mult = unit.value / 100
--         return {
--             value = math.floor(mult * parentWidth),
--             unit = "ch",
--         }
--     end
--     return unit
--     -- error("Undefined unit '" .. unit.unit .. "'")
-- end

---@param unit Banana.Ncss.UnitValue
---@param parentWidth number
---@param extras number[]
---@return Banana.Ncss.UnitValue
function M.calcUnitNoMod(unit, parentWidth, extras)
    if unit.unit == "ch" then
        return {
            value = unit.value,
            unit = unit.unit,
            computed = unit.value,
        }
    elseif unit.unit == "fr" then
        if extras[1] == nil then
            log.assert(false, "fr unit requires an extra parameter")
            error("")
        end
        local mult = unit.value
        return {
            value = unit.value,
            computed = math.floor(mult * extras[1]),
            unit = unit.unit,
        }
    elseif unit.unit == "%" then
        local mult = unit.value / 100
        return {
            value = unit.value,
            computed = math.floor(mult * parentWidth),
            unit = unit.unit,
        }
    end
    error("Undefined unit '" .. unit.unit .. "'")
    return unit
end

function M.Ast:getWidth()
    return self.boundBox.rightX - self.boundBox.leftX
end

function M.Ast:getHeight()
    return self.boundBox.bottomY - self.boundBox.topY
end

---@param prop string
---@param basedOn number
---@param extras number[]
function M.Ast:_computeUnitFor(prop, basedOn, extras)
    local style = self.style[prop]
    if style ~= nil then
        for i, _ in ipairs(style) do
            ---@diagnostic disable-next-line: param-type-mismatch
            style[i].value = M.calcUnitNoMod(style[i].value, basedOn, extras)
        end
    end
end

---@param parentWidth number
---@param parentHeight number
---@param extras? number[]
function M.Ast:_resolveUnits(parentWidth, parentHeight, extras)
    flame.new("Ast:resolveUnits")
    extras = extras or {}
    for i, v in ipairs(self.margin) do
        if i % 2 == 1 then
            self.margin[i] = M.calcUnitNoMod(v, parentWidth, extras)
        else
            self.margin[i] = M.calcUnitNoMod(v, parentHeight, extras)
        end
    end
    for i, v in ipairs(self.padding) do
        if i % 2 == 1 then
            self.padding[i] = M.calcUnitNoMod(v, parentWidth, extras)
        else
            self.padding[i] = M.calcUnitNoMod(v, parentHeight, extras)
        end
    end
    self:_computeUnitFor("list-base-width", parentWidth, extras)
    self:_computeUnitFor("width", parentWidth, extras)
    self:_computeUnitFor("height", parentHeight, extras)
    self:_computeUnitFor("top", parentHeight, extras)
    self:_computeUnitFor("bottom", parentHeight, extras)
    self:_computeUnitFor("left", parentWidth, extras)
    self:_computeUnitFor("right", parentWidth, extras)
    self:_computeUnitFor("flex-basis", parentWidth, extras)
    flame.pop()
end

function M.Ast:_applyInlineStyleDeclarations()
    if self.inlineStyle == nil then
        return
    end
    self:_applyStyleDeclarations(
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
function M.Ast:_applyStyleDeclarations(declarations, basePrec)
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
            local name = v.name:sub(4, _str.charWidth(v.name))

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
                log.assert(false,
                    "Undefined side '" .. side .. "'")
                error("")
            end
            local val = value.value
            ---@cast val Banana.Ncss.UnitValue
            self.padding[index] = val
        elseif v.name:sub(1, 7) == "margin-" then
            local side = v.name:sub(8, #v.name)

            local value = v.values[1]
            local index = M[side]
            if index == nil then
                log.assert(false,
                    "Undefined side '" .. side .. "'")
                error("")
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
    if self._parent == require('banana.instance').getNilAst() then
        log.assert(false,
            "Attempting to remove the root node")
        error("")
    end
    for i, v in ipairs(self._parent.nodes) do
        if v == self then
            table.remove(self._parent.nodes, i)
            break
        end
    end
    require('banana.instance').getInstance(self.instance):_removeMapsFor(self)
    self._parent = nil
    self:_requestRender()
end

---@param name string
---@return string?
function M.Ast:getAttribute(name)
    return self.attributes[name]
end

---@param text string
function M.Ast:appendTextNode(text)
    table.insert(self.nodes, text)
    self:_requestRender()
end

---@param node Banana.Ast
function M.Ast:appendNode(node)
    node._parent = self
    table.insert(self.nodes, node)
    if self.instance ~= nil then
        require('banana.instance').getInstance(self.instance):_applyId(node)
    end
    self:_requestRender()
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

---@return string
function M.Ast:_testDumpAttr()
    local ret = "<" .. self.tag .. "> "
    for k, v in pairs(self.attributes) do
        ret = ret .. k .. ": '" .. v .. "',"
    end
    return ret
end

---@return Banana.Box
function M.Ast:_testDumpBox()
    local ret = require('banana.box').Box:new()
    ret:appendStr(self:_testDumpAttr())
    return ret
end

---@param number number
function M.Ast:_increaseLeftBound(number)
    if self.boundBox == nil then
        return
    end
    self.boundBox.leftX = self.boundBox.leftX + number
    self.boundBox.rightX = self.boundBox.rightX + number
    if self.relativeBoxId ~= nil then
        local root = self
        repeat
            root = root._parent
            if root == nil then
                return
            end
        until root.relativeBoxes ~= nil
        local box = root.relativeBoxes[self.relativeBoxId]
        box.left = box.left + number
    end
    for child in self:childIter() do
        child:_increaseLeftBound(number)
    end
end

---@param number number
function M.Ast:_increaseTopBound(number)
    if self.boundBox == nil then
        return
    end
    self.boundBox.bottomY = self.boundBox.bottomY + number
    self.boundBox.topY = self.boundBox.topY + number
    if self.relativeBoxId ~= nil then
        local root = self
        repeat
            root = root._parent
            if root == nil then
                return
            end
        until root.relativeBoxes ~= nil
        local box = root.relativeBoxes[self.relativeBoxId]
        box.top = box.top + number
    end
    for child in self:childIter() do
        child:_increaseTopBound(number)
    end
end

function M.Ast:_increaseHeightBoundBy(delta)
    self.boundBox.bottomY = self.boundBox.bottomY + delta
end

function M.Ast:_increaseWidthBoundBy(delta)
    self.boundBox.rightX = self.boundBox.rightX + delta
end

function M.Ast:removeChildren()
    for _, v in ipairs(self.nodes) do
        if type(v) ~= "string" then
            v:remove()
        end
    end
    self.nodes = {}
    self:_requestRender()
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

---@return fun(): Banana.Ast?
function M.Ast:childIter()
    local i = 0
    return function()
        i = i + 1
        while type(self.nodes[i]) ~= "table" do
            i = i + 1
            if i > #self.nodes then
                return nil
            end
        end
        ---@diagnostic disable-next-line: return-type-mismatch
        return self.nodes[i]
    end
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
    return require('banana.instance').getNilAst()
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
    self:_requestRender()
end

---@param mod Banana.Remap.Constraint
---@return fun(): boolean
function M.Ast:_parseRemapMod(mod)
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
        log.assert(false,
            "Banana attachRemap requires the 4th parameter (before rhs) to be a table of modifiers")
        error("")
    end
    local modFns = vim.iter(mods)
        :map(function(mod) return self:_parseRemapMod(mod) end):totable()
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
    local inst = require('banana.instance').getInstance(self.instance)
    inst:_setRemap(mode, lhs, actualRhs, opts, self)
end

function M.Ast:_requestRender()
    if self.instance == nil then
        return
    end
    local inst = require('banana.instance').getInstance(self.instance)
    inst:_requestRender()
end

return M
