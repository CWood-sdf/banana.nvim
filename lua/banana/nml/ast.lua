---@module 'banana.nml.tag'
local _tag = require("banana.lazyRequire")("banana.nml.tag")
---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
local M = {}
---@module 'banana.utils.string'
local _str = require("banana.lazyRequire")("banana.utils.string")

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

---@class Banana.Ast
---@field nodes (string|Banana.Ast)[]
---@field tag string
---@field attributes Banana.Attributes
---@field actualTag Banana.TagInfo
---@field style { [string]: Banana.Ncss.StyleValue[] }
---@field hl Banana.Highlight
---@field private padding Banana.Ncss.UnitValue[]
---@field private margin Banana.Ncss.UnitValue[]
---@field classes? { [string]: boolean }
---@field boundBox? Banana.Ast.BoundingBox
---@field precedences { [string]: number }
---@field instance number?
---@field _parent Banana.Ast
---@field inlineStyle Banana.Ncss.StyleDeclaration[]
---@field absoluteAsts? Banana.Ast[]
---@field relativeBoxId? number
---@field hidden boolean
---@field relativeBoxes? { box: Banana.Box, left: number, top: number, z: number}[]
---@field componentPath string[]
---@field listCounter? number
---@field fromFile string
---@field componentCache? { [string]: Banana.Component }
---@field componentTree? Banana.Ast
---@field componentParent? Banana.Ast
M.Ast = {
    nodes = {},
    tag = "",
    attributes = {},
    inlineStyle = {},
    padding = {
    },
    margin = {
    },
    classes = nil,
    precedences = {},
}

---@param tag string
---@param parent Banana.Ast
---@param source string
---@return Banana.Ast
function M.Ast:new(tag, parent, source)
    local actualTag = nil
    if require("banana.nml.parser").isValidComponentName(tag) then
        actualTag = _tag.newComponentTag(tag)
    end
    actualTag = actualTag or require("banana.nml.tag").makeTag(tag)
    local path = nil
    if source:sub(1, 1) ~= "@" then
        path = { source }
    else
        path = {}
    end
    ---@type Banana.Ast
    ---@diagnostic disable-next-line: missing-fields
    local ast = {
        hl = {},
        inlineStyle = {},
        componentPath = path,
        fromFile = source,
        hidden = false,
        boundBox = nil,
        precedences = {},
        nodes = {},
        tag = tag,
        _parent = parent,
        actualTag = actualTag,
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

---@param name string
---@return Banana.Component?
function M.Ast:_findComponent(name)
    if self.componentCache ~= nil then
        local v = self.componentCache[name]
        if v ~= nil then
            return v
        end
    end
    for _, v in ipairs(self.componentPath) do
        local req = require("banana.require").getComponentFrom(v, name)
        if req ~= nil then
            self.componentCache = self.componentCache or {}
            self.componentCache[name] = req
            return req
        end
    end
    if self._parent:isNil() then return nil end
    return self._parent:_findComponent(name)
end

function M.Ast:_tryMountComponent()
    if self.componentTree ~= nil then return end
    self:_mountComponent()
end

function M.Ast:_mountComponent()
    if not self:_isComponent() then
        log.throw("Cannot mount tag '" ..
            self.tag .. "' as a component because it is not a component")
    end
    if self.componentTree ~= nil then
        log.throw("Component is already mounted")
    end
    local component = self:_findComponent(self.tag)
    if component == nil then
        log.throw("Could not find component '" .. self.tag .. "'")
        error()
    end
    local ast = component.ast:clone()
    ast.componentParent = self
    local inst = require("banana.instance").getInstance(self.instance)
    if inst == nil then
        log.throw("Could not find instance")
        error()
    end
    inst:_applyId(ast)
    inst:_loadStyleFor(component.styles, ast)
    for _, v in ipairs(component.scripts) do
        inst:_loadScriptFor(v, ast, {})
    end
    self.componentTree = ast
end

---@param name string?
---@return Banana.Ast
function M.Ast:_getSlot(name)
    if name == nil then
        return self:child(1)
    end
    for _, v in self:childIter() do
        if v.attributes["slot"] == name then
            return v
        end
    end
    return require("banana.instance").getNilAst()
end

---Returns the root node of this section of the dom tree
---@return Banana.Ast
function M.Ast:root()
    if self._parent:isNil() then
        return self
    end
    return self:parent():root()
end

---Returns the first style value for the given {style} or nil if not found
---@param style string the style to lookup
---@return Banana.Ncss.StyleValue?
function M.Ast:_firstStyle(style)
    local s = self.style[style]
    if s == nil then
        return nil
    end
    return s[1]
end

---@return boolean
function M.Ast:_isComponent()
    local ret, _ = require("banana.nml.parser").isValidComponentName(self.tag)
    return ret
end

---Returns all style values for the style string
---@param style string the style to lookup
---@return Banana.Ncss.StyleValue[]?
function M.Ast:_allStylesFor(style)
    return self.style[style]
end

---@param pad number?
---@return string[]
function M.Ast:_dumpTree(pad)
    pad = pad or 0
    local ret = {
        string.rep(" ", pad) .. self.tag .. ": "
    }
    local id = self:getAttribute("id")
    if id ~= nil then
        ret[1] = ret[1] .. "#" .. id .. " "
    end
    for v, s in pairs(self.classes or {}) do
        if s then
            ret[1] = ret[1] .. "." .. v .. " "
        end
    end
    pad = pad + 2
    for _, v in ipairs(self.nodes) do
        if type(v) == "string" then
            table.insert(ret, string.rep(" ", pad) .. v)
        else
            local dump = v:_dumpTree(pad)
            for _, d in ipairs(dump) do
                table.insert(ret, d)
            end
        end
    end
    return ret
end

---Returns the first style value or a given default
---@param style string the style to lookup
---@param default Banana.Ncss.StyleValueType
---@return Banana.Ncss.StyleValueType
---@overload fun(self: Banana.Ast, style: string): Banana.Ncss.StyleValueType?
function M.Ast:_firstStyleValue(style, default)
    local val = self:_firstStyle(style)
    if val == nil then
        return default
    end
    return val.value
end

---@param style string
---@param default number
---@return number
---@overload fun(self: Banana.Ast, style: string): number?
function M.Ast:_firstStyleComputedValue(style, default)
    local val = self:_firstStyle(style)
    if val == nil or val.type ~= "unit" then
        return default
    end
    return val.value.computed
end

---Returns true if the style {style} is in the node's style list
---@param style string the style to lookup
---@return boolean
function M.Ast:hasStyle(style)
    return self.style[style] ~= nil
end

---Throws an error if the style {style} has not been set in the node's style list
---@param style string the style to lookup
function M.Ast:assertHasStyle(style)
    if self:_firstStyle(style) == nil then
        log.throw("needs style")
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

---@return number
function M.Ast:_boundTb()
    return self:_boundTop() + self:_boundBottom()
end

---@return number
function M.Ast:_extraTb()
    return self:_extraTop() + self:_extraBottom()
end

---@return number
function M.Ast:_boundLr()
    return self:_boundLeft() + self:_boundRight()
end

---@return number
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

---Returns the actual left side margin of the element (in characters)
---@return number
function M.Ast:marginLeft()
    return self.margin[M.left].computed
end

---Returns the actual right side margin of the element (in characters)
---@return number
function M.Ast:marginRight()
    return self.margin[M.right].computed
end

---Returns the actual top side margin of the element (in characters)
---@return number
function M.Ast:marginTop()
    return self.margin[M.top].computed
end

---Returns the actual bottom side margin of the element (in characters)
---@return number
function M.Ast:marginBottom()
    return self.margin[M.bottom].computed
end

---Returns the actual left side padding of the element (in characters)
---@return number
function M.Ast:paddingLeft()
    return self.padding[M.left].computed
end

---Returns the actual right side padding of the element (in characters)
---@return number
function M.Ast:paddingRight()
    return self.padding[M.right].computed
end

---Returns the actual top side padding of the element (in characters)
---@return number
function M.Ast:paddingTop()
    return self.padding[M.top].computed
end

---Returns the actual bottom side padding of the element (in characters)
---@return number
function M.Ast:paddingBottom()
    return self.padding[M.bottom].computed
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
        local code = string.byte("A") + counter
        return string.char(code) .. "."
    end
    if styleTp == "alpha" then
        local code = string.byte("a") + counter
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
function M.Ast:_getNextListItem(styleTp)
    if self.tag == "ol" and self.listCounter == nil then
        self.listCounter = 1
    end
    if self.listCounter == nil then
        return getListItemUl(styleTp) .. " "
    end
    local ret        = getListItemOl(styleTp, self.listCounter) .. " "
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
    self:_unlockGradients()
    self.hl = {}
    self.precedences = {}
end

function M.Ast:_clearStyles()
    if self:_isComponent() and self.componentTree == nil then
        self:_tryMountComponent()
    end
    if self.componentTree ~= nil then
        self.componentTree:_defaultStyles()
    end
    self:_defaultStyles()
    for node in self:childIter() do
        node:_clearStyles()
    end
end

---Applies the ast metatable to an ast tree (after cloning)
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

---Duplicates this node and all its children (note: does NOT copy attached events)
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
    local fg = self.hl.fg
    local bg = self.hl.bg
    self.hl.bg = nil
    self.hl.fg = nil
    newAst.hl = vim.fn.deepcopy(self.hl)
    if type(bg) == "table" then
        newAst.hl.bg = bg:getInstance(newAst)
    else
        newAst.hl.bg = bg
    end
    self.hl.bg = bg
    if type(fg) == "table" then
        newAst.hl.fg = fg:getInstance(newAst)
    else
        newAst.hl.fg = fg
    end
    self.hl.fg = fg
    newAst.padding = vim.fn.deepcopy(self.padding)
    newAst.margin = vim.fn.deepcopy(self.margin)
    if self.classes ~= nil then
        newAst.classes = vim.fn.deepcopy(self.classes)
    end
    newAst.instance = self.instance
    newAst._parent = require("banana.instance").getNilAst()
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

function M.Ast:_unlockGradients()
    if type(self.hl.fg) == "table" then
        ---@diagnostic disable-next-line: param-type-mismatch
        self.hl.fg:unlock()
    end
    if type(self.hl.bg) == "table" then
        ---@diagnostic disable-next-line: param-type-mismatch
        self.hl.bg:unlock()
    end
end

function M.Ast:_lockGradients()
    if type(self.hl.fg) == "table" then
        ---@diagnostic disable-next-line: param-type-mismatch
        self.hl.fg = self.hl.fg:getInstance(self)
    end
    if type(self.hl.bg) == "table" then
        ---@diagnostic disable-next-line: param-type-mismatch
        self.hl.bg = self.hl.bg:getInstance(self)
    end
end

---Sets the attribute {name} to {value}
---@param name string the name of the attribute
---@param value string the new value of the attribute
function M.Ast:setAttribute(name, value)
    if name == "style" then
        self:setStyle(value)
        return
    end
    self.attributes[name] = value
    self:_requestRender()
end

---Sets the elements custom style rules to {value}
---(note: overrides any styles set with style="")
---@param value string the ncss style string to set this element's style rules to
function M.Ast:setStyle(value)
    local parsed = require("banana.ncss.parser").parseText(value)
    self.inlineStyle = parsed[1].declarations
    self:_requestRender()
end

---Sets the style declaration for {name} (eg hl-bg) to be {value}
---@param name string the name of the style to set
---@param value string the string of the value
function M.Ast:setStyleValue(name, value)
    local text = name .. ": " .. value .. ";"
    local parsed = require("banana.ncss.parser").parseText(text)
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

---Returns true if the node has class {c}
---@param c string the class to find
---@return boolean
function M.Ast:hasClass(c)
    if self.classes == nil and self.attributes["class"] ~= nil then
        local arr = vim.split(self.attributes["class"], " ")
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

---Removes the class {c} from the node's class list
---@param c string the class to unset
function M.Ast:removeClass(c)
    if self.classes == nil then
        self.classes = {}
    end
    if self.classes[c] == true then
        self.classes[c] = false
        self:_requestRender()
    end
end

---Adds the class {c} to the node's class list
---@param c string the class to set
function M.Ast:addClass(c)
    if self.classes == nil then
        self.classes = {}
    end
    if not self.classes[c] then
        self.classes[c] = true
        self:_requestRender()
    end
end

---Toggles the class {c} to the node's class list
---@param c string the class to toggle
function M.Ast:toggleClass(c)
    self.classes = self.classes or {}
    self.classes[c] = self.classes[c] or false
    self.classes[c] = not self.classes[c]
    self:_requestRender()
end

---@param parentHl Banana.Highlight?
---@return Banana.Highlight
function M.Ast:_mixHl(parentHl)
    -- flame.new("Ast:_mixHl")
    local ret = {}
    -- setmetatable(ret, { __mode = "kv" })
    if self.tag == "h1" then
        ret.bold = true
    end


    for k, v in pairs(self.hl) do
        ret[k] = v
    end
    for k, v in pairs(parentHl or {}) do
        if ret[k] == nil then
            ret[k] = v
        end
    end
    -- flame.pop()
    return ret
end

---@param unit Banana.Ncss.UnitValue
---@param parentWidth number
---@param extras number[]
---@return number
---@diagnostic disable-next-line: unused-local
function M.getComputedValue(unit, parentWidth, extras)
    if unit.unit == "ch" then
        return unit.value
    elseif unit.unit == "%" then
        local mult = unit.value / 100
        return math.floor(mult * parentWidth)
    end
    error("Undefined unit '" .. unit.unit .. "'")
    return unit.value
end

---@param unit Banana.Ncss.UnitValue
---@param parentWidth number
---@param extras number[]
---@return Banana.Ncss.UnitValue
function M.calcUnitNoMod(unit, parentWidth, extras)
    return {
        unit = unit.unit,
        value = unit.value,
        computed = M.getComputedValue(unit, parentWidth, extras)
    }
end

---@param unit Banana.Ncss.UnitValue
---@param parentWidth number
---@param extras number[]
---@return number
function M.calcUnitInPlace(unit, parentWidth, extras)
    unit.computed = M.getComputedValue(unit, parentWidth, extras)
    return unit.computed
end

---Returns the width of the node's bounding box (content+padding)
---@return number
function M.Ast:getWidth()
    return self.boundBox.rightX - self.boundBox.leftX
end

---Returns the height of the node's bounding box (content+padding)
function M.Ast:getHeight()
    return self.boundBox.bottomY - self.boundBox.topY
end

---@param prop string
---@param basedOn number
---@param extras number[]
---@return number?
function M.Ast:_computeUnitFor(prop, basedOn, extras)
    local style = self.style[prop]
    local ret = nil
    if style ~= nil then
        for _, s in ipairs(style) do
            if s.type ~= "unit" then
                goto continue
            end
            ---@diagnostic disable-next-line: param-type-mismatch
            local v = M.calcUnitInPlace(s.value, basedOn, extras)
            if ret == nil then
                ret = v
            end
            ::continue::
        end
    end
    return ret
end

---@param parentWidth number
---@param parentHeight number
---@param extras? number[]
function M.Ast:_resolveUnits(parentWidth, parentHeight, extras)
    --flame.new("Ast:resolveUnits")
    extras = extras or {}
    --flame.new("Ast:resolveUnits_marg")
    for i, v in ipairs(self.margin) do
        if i % 2 == 1 then
            M.calcUnitInPlace(v, parentWidth, extras)
        else
            M.calcUnitInPlace(v, parentHeight, extras)
        end
    end
    for i, v in ipairs(self.padding) do
        if i % 2 == 1 then
            M.calcUnitInPlace(v, parentWidth, extras)
        else
            M.calcUnitInPlace(v, parentHeight, extras)
        end
    end
    --flame.pop()
    self:_computeUnitFor("list-base-width", parentWidth, extras)
    self:_computeUnitFor("width", parentWidth, extras)
    self:_computeUnitFor("height", parentHeight, extras)
    if self.style.width == nil and self.style.height ~= nil and self.style["aspect-ratio"] ~= nil then
        ---@type Banana.Ncss.StyleValue
        local width = {
            type = "unit",
            value = {
                unit = "ch",
                computed = self.style["height"][1].value.computed *
                    self.style["aspect-ratio"][1].value * 2,
                value = self.style.height[1].value.computed *
                    self.style["aspect-ratio"][1].value,
            }
        }
        self.style.width = { width }
    end
    if self.style.height == nil and self.style.width ~= nil and self.style["aspect-ratio"] ~= nil then
        ---@type Banana.Ncss.StyleValue
        local height = {
            type = "unit",
            value = {
                unit = "ch",
                computed = math.floor(self.style["width"][1].value.computed /
                    self.style["aspect-ratio"][1].value / 2),
                value = math.floor(self.style.width[1].value.computed /
                    self.style["aspect-ratio"][1].value / 2),
            }
        }
        self.style.height = { height }
    end
    self:_computeUnitFor("top", parentHeight, extras)
    self:_computeUnitFor("bottom", parentHeight, extras)
    self:_computeUnitFor("left", parentWidth, extras)
    self:_computeUnitFor("right", parentWidth, extras)
    self:_computeUnitFor("flex-basis", parentWidth, extras)
    -- self:_computeUnitFor("row-gap", parentWidth, extras)
    -- self:_computeUnitFor("column-gap", parentWidth, extras)
    --flame.pop()
end

function M.Ast:_applyInlineStyleDeclarations()
    if self.inlineStyle == nil then
        return
    end
    self:_applyStyleDeclarations(
        self.inlineStyle,
        require("banana.ncss.query").Specificity.Inline
    )
end

---Returns true if the node is a nil node
---@return boolean
function M.Ast:isNil()
    -- the return true is in instance.lua when the nil ast is created
    return false
end

---@param declarations Banana.Ncss.StyleDeclaration[]
---@param basePrec number
function M.Ast:_applyStyleDeclarations(declarations, basePrec)
    for _, v in ipairs(declarations) do
        local prec = basePrec
        if v.important then
            prec = prec + require("banana.ncss.query").Specificity.Important
        end
        if self.precedences[v.name] ~= nil and prec < self.precedences[v.name] then
            goto continue
        end
        self.precedences[v.name] = prec
        if v.name:sub(1, 3) == "hl-" then
            local name = v.name:sub(4, _str.charWidth(v.name))

            local value = v.values[1]
            if value.type == "plain" and value.value == "inherit" then
                goto continue
            end
            if (name == "fg" or name == "bg") and type(self.hl[name]) == "table" then
                ---@type Banana.Gradient
                local t = self.hl[name]
                t:unlock()
            end
            self.hl[name] = value.value
            self:_lockGradients()
        elseif v.name:sub(1, 8) == "padding-" then
            local side = v.name:sub(9, #v.name)

            local value = v.values[1]
            local index = M[side]
            if index == nil then
                log.throw(
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
                log.throw(
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

---removes the ast node from the dom
function M.Ast:remove()
    if self._parent == require("banana.instance").getNilAst() then
        log.throw(
            "Attempting to remove the root node")
        error("")
    end
    for i, v in ipairs(self._parent.nodes) do
        if v == self then
            table.remove(self._parent.nodes, i)
            break
        end
    end
    if self.componentTree ~= nil then
        -- just add it to prevent the root node removal error
        self.componentTree._parent = self
        self.componentTree:remove()
    end
    require("banana.instance").getInstance(self.instance):_removeMapsFor(self)
    self._parent = nil
    self:_requestRender()
end

---Returns the attribute value for {name} or nil if not found
---@param name string the name of the attribute to get
---@return string?
function M.Ast:getAttribute(name)
    return self.attributes[name]
end

---Adds {text} to the child list of the node
---@param text string the text to add to the node
function M.Ast:appendTextNode(text)
    table.insert(self.nodes, text)
    self:_requestRender()
end

---Adds {node} as a child to this node
---@param node Banana.Ast the node to append as a child
function M.Ast:appendNode(node)
    node._parent = self
    table.insert(self.nodes, node)
    if self.instance ~= nil then
        require("banana.instance").getInstance(self.instance):_applyId(node)
    end
    self:_requestRender()
end

---Returns true if the cursor is on the same line as this node
---@return boolean
function M.Ast:isLineHovering()
    local line = vim.fn.line(".")
    local ret =
        line >= self.boundBox.topY
        and line < self.boundBox.bottomY
    return ret
end

---Returns true if the cursor is hovering over this ast
---@return boolean
function M.Ast:isHovering()
    local line = vim.fn.line(".")
    local col = vim.fn.col(".")
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
    local ret = require("banana.box").Box:new()
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

---Removes all children from this node (including text)
function M.Ast:removeChildren()
    local i = 1
    while i < #self.nodes do
        if type(self.nodes[i]) == "string" then
            i = i + 1
        else
            ---@diagnostic disable-next-line: param-type-mismatch
            self.nodes[i]:remove()
        end
    end
    self.nodes = {}
    self:_requestRender()
end

---Returns all ast node children of this element (not text nodes)
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

---Returns an iterator that allows iteration over all children with indexing
---@return fun(): number?, Banana.Ast?
function M.Ast:childIterWithI()
    local i = 0
    local retI = 0
    return function ()
        i = i + 1
        retI = retI + 1
        while type(self.nodes[i]) ~= "table" do
            i = i + 1
            if i > #self.nodes then
                return nil
            end
        end
        ---@diagnostic disable-next-line: return-type-mismatch
        return retI, self.nodes[i]
    end
end

---Returns an iterator over all the children of this node
---@return fun(): Banana.Ast?
function M.Ast:childIter()
    local i = 0
    return function ()
        --flame.new("Ast:childIter")
        i = i + 1
        while type(self.nodes[i]) ~= "table" do
            i = i + 1
            if i > #self.nodes then
                --flame.pop()
                return nil
            end
        end
        --flame.pop()
        ---@diagnostic disable-next-line: return-type-mismatch
        return self.nodes[i]
    end
end

---Returns the nth non-string child of this node
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
    return require("banana.instance").getNilAst()
end

---returns what the attribute substitution (eg %attr in nml) would be for {name}
---@param name string the attribute to lookup
---@return string?
function M.Ast:getAttributeSubstitution(name)
    local el = self
    local v = nil
    while el.attributes[name] == nil do
        if el:isNil() then
            break
        end
        if el.componentParent ~= nil then
            el = el.componentParent
            -- dont want to keep looping bc that would give our
            -- component access to the outside source tree which
            -- doesnt make sense
            break
        end
        el = el._parent
    end
    if el:isNil() then
        v = ""
        log.warn("Could not find attribute '" ..
            name .. "' for template substitution")
        vim.notify("Could not find attribute '" ..
            name .. "' for template substitution")
    else
        v = el:getAttribute(name) or ""
    end
    return v
end

---Returns the printed text value of this element (does not include newlines)
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

---Sets the text content of this element
---@param str string the text to set this element's content to
function M.Ast:setTextContent(str)
    if type(str) ~= "string" then
        str = tostring(str)
    end
    self:removeChildren()
    self.nodes = { str }
    self:_requestRender()
end

---@param mod Banana.Remap.Constraint
---@return fun(): boolean
function M.Ast:_parseRemapMod(mod)
    if mod == "hover" then
        return function ()
            return self:isHovering()
        end
    elseif mod == "line-hover" then
        return function ()
            return self:isLineHovering()
        end
    elseif type(mod) == "number" then
        return function ()
            local count = vim.v.count
            return count == mod
        end
    end
    error("Attempting to use ast remap mod '"
        .. mod .. "' even though it has not been defined")
end

---Returns the parent node of this node
---@return Banana.Ast
function M.Ast:parent()
    return self._parent
end

---Returns true when this node is not rendered
---@return boolean
function M.Ast:isHidden()
    if self.hidden then return true end
    if self._parent:isNil() then return false end
    return self._parent:isHidden()
end

---Attaches the given remap to the ast
---@param mode string the mode of the keymap
---@param lhs string the lhs of the keymap
---@param rhs string|fun() rhs
---@param mods Banana.Remap.Constraint[] a list of remap constraints
---@param opts vim.keymap.set.Opts? keymap options
function M.Ast:attachRemap(mode, lhs, mods, rhs, opts)
    opts = opts or {}
    if type(mods) ~= "table" then
        log.throw(
            "Banana attachRemap requires the 4th parameter (before rhs) to be a table of modifiers")
        error("")
    end
    local modFns = {}
    for _, v in ipairs(mods) do
        table.insert(modFns, self:_parseRemapMod(v))
    end
    -- local modFns = vim.iter(mods)
    --                   :map(function (mod) return self:_parseRemapMod(mod) end)
    --                   :totable()
    if type(rhs) == "string" then
        local oldRhs = rhs
        rhs = function ()
            vim.api.nvim_feedkeys(
                vim.api.nvim_replace_termcodes(oldRhs, true, true, true), mode,
                true)
        end
    end
    local actualRhs = function ()
        if self:isHidden() then return false end
        local works = #modFns == 0
        for _, v in ipairs(modFns) do
            if v() then
                works = true
                break
            end
        end
        if not works then return false end
        if type(rhs) == "string" then
            vim.api.nvim_feedkeys(
                vim.api.nvim_replace_termcodes(rhs, true, true, true), mode, true)
        else
            rhs()
        end
        return true
    end
    local inst = require("banana.instance").getInstance(self.instance)
    if inst == nil then
        log.throw("ast does not have an associated document")
        error("")
    end
    inst:_setRemap(mode, lhs, actualRhs, opts, self)
end

function M.Ast:_requestRender()
    if self.instance == nil then
        return
    end
    local inst = require("banana.instance").getInstance(self.instance)
    if inst == nil then
        log.throw("ast does not have an associated document")
        error("")
    end
    inst:_requestRender()
end

return M
