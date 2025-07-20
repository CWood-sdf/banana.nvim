---@module 'banana.nml.tag'
local _tag = require("banana.lazyRequire")("banana.nml.tag")
---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
local M = {}
---@module 'banana.utils.string'
local _str = require("banana.lazyRequire")("banana.utils.string")
---@module 'banana.instance'
local _inst = require("banana.lazyRequire")("banana.instance")
---@module 'banana.ncss.unit'
local unit = require("banana.lazyRequire")("banana.ncss.unit")


---@type Banana.Ncss.UnitValue?
local zeroUnit = nil

M.left = 1
M.top = 2
M.right = 3
M.bottom = 4
M.padNames = { "left", "top", "right", "bottom" }

---A **1** indexed bounding box
---@class (exact) Banana.Ast.BoundingBox
---@field leftX number The left edge, inclusive
---@field topY number The top edge, inclusive
---@field rightX number The right edge, exclusive
---@field bottomY number The bottom edge, exclusive

---@alias Banana.RelativeBox { image: number, left: number, top: number, z: number}

local astId = 0

---@class Banana.Ast
---@field _astId number just an id to keep track of things in debug
---@field data table? For eventual data sharing between components
---and (maybe) templating
---@field nodes (string|Banana.Ast)[] List of text and ast nodes
---@field tag string The name of the tag
---@field attributes Banana.Attributes Attributes table
---@field actualTag Banana.TagInfo The actual tag object
---@field private style { [string]: Banana.Ncss.StyleValue[] } List of style values
---@field hl Banana.Highlight The highlight value (derived at style time)
---@field private padding Banana.Ncss.UnitValue[]
---@field private margin Banana.Ncss.UnitValue[]
---@field classes? { [string]: boolean } A list of the classes
---@field boundBox? Banana.Ast.BoundingBox The bounds of the render
---@field precedences { [string]: number } The precedences of each applied style field
---@field instance number? The id of the attached instance
---@field _parent Banana.Ast The parent ast
---@field inlineStyle Banana.Ncss.StyleDeclaration[] The inline styles
---@field absoluteAsts? Banana.Ast[] Any absolute asts that will be rendered over this ast
---@field relativeBoxId? number If position:relative, this will be an index into the renderOver target Ast relativeBoxes
---@field hidden boolean True if wont be rendered (eg display:none...)
---@field relativeBoxes? Banana.RelativeBox[] A list of relative boxes to render
---@field componentPath string[] The search path for components
---@field listCounter? number For <ol>, starts at 1 and increases every time a descendant <li> is rendered
---@field fromFile string The file this ast is from
---@field componentCache? { [string]: Banana.Component } Cache of components
---@field componentTree? Banana.Ast If is component, will contain <template> to render
---@field componentParent? Banana.Ast If is <template>, will contain component
---@field _isComponentCache boolean
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

local Ast__index = M.Ast -- flame.wrapClass(M.Ast, "Ast", true)

---@param tag string
---@param parent Banana.Ast
---@param source string
---@return Banana.Ast
function M.Ast:new(tag, parent, source)
    local actualTag = nil
    if zeroUnit == nil then
        zeroUnit = unit.newUnit("ch", 0, 0)
    end
    local isComponent = false
    if require("banana.nml.parser").isValidComponentName(tag) then
        actualTag = _tag.newComponentTag(tag)
        isComponent = true
    end
    actualTag = actualTag or require("banana.nml.tag").makeTag(tag)
    local path
    if source:sub(1, 1) ~= "@" then
        path = { source }
    else
        path = {}
    end
    ---@type Banana.Ast
    local ast = {
        hl = {},
        _astId = astId,
        inlineStyle = {},
        componentPath = path,
        fromFile = source,
        hidden = false,
        boundBox = nil,
        precedences = {},
        _isComponentCache = isComponent,
        nodes = {},
        tag = tag,
        _parent = parent,
        actualTag = actualTag,
        attributes = {},
        instance = nil,
        padding = {
            zeroUnit,
            zeroUnit,
            zeroUnit,
            zeroUnit,
        },
        margin = {
            zeroUnit,
            zeroUnit,
            zeroUnit,
            zeroUnit,
        },
        style = {},
    }
    astId = astId + 1
    if tag == "ol" then
        ast.listCounter = 1
    end
    setmetatable(ast, { __index = Ast__index })

    if tag == "progress" and #ast.nodes == 0 then
        local left = M.Ast:new("span", ast, "__internal")
        -- left:_applyInstance(ast:ownerDocument())
        left:_addClass("progress-filled")
        local right = M.Ast:new("span", ast, "__internal")
        -- right:_applyInstance(ast:ownerDocument())
        right:_addClass("progress-empty")
        ast:_appendChild(left)
        ast:_appendChild(right)
    end


    return ast
end

---Returns the data associated with the ast [UNSTABLE]
---@param item string?
---@return any?
function M.Ast:getData(item)
    if self.data == nil then
        if self.componentParent ~= nil then
            if self.componentParent.data == nil then
                return nil
            end
            return self.componentParent:getData(item)
        end
        return self._parent:getData(item)
    end
    if item == nil or self.data == nil then
        return self.data
    end
    return self.data[item]
end

---Sets the data associated with the array [UNSTABLE]
---@param key string
---@param value any
---@overload fun(self: Banana.Ast, value: table)
function M.Ast:setData(key, value)
    if type(key) == "table" then
        self.data = key
        return
    end
    self.data = self.data or {}
    self.data[key] = value
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

---@return Banana.Nml.CanvasContext
function M.Ast:getContext()
    return self.data.__ctx
end

---@param inst Banana.Instance
function M.Ast:_applyInstance(inst)
    if self.instance == nil then
        self.instance = inst.instanceId
        for v in self:childIter() do
            v:_applyInstance(inst)
        end
    end
    if self:_isComponent() and self.componentTree ~= nil then
        self:_mountComponent()
    end
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
    self.actualTag.formatType = component.ast.actualTag.formatType
    local ast = component.ast:clone(true)
    ast.componentParent = self
    local inst = self:ownerDocument()
    if inst == nil then
        log.throw("Could not find instance")
        error()
    end
    ast:_applyInstance(inst)
    inst:_loadStyleFor(component.styles, ast)
    for _, v in ipairs(component.preScripts) do
        inst:_loadPreScriptFor(v, ast, {})
    end
    for _, v in ipairs(component.postScripts) do
        inst:_loadPostScriptFor(v, ast, {})
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
    return _inst.getNilAst()
end

---Returns the root node of this section of the dom tree
---@return Banana.Ast
function M.Ast:getRootNode()
    if self._parent:isNil() then
        return self
    end
    return self:parent():getRootNode()
end

---@return string
function M.Ast:getTagName()
    return self.tag
end

---Returns the {n}th style value for the given {style} or nil if not found
---Removes expression tree from the possibility
---@param style string the style to lookup
---@param n number
---@return Banana.Ncss.StyleValue?
function M.Ast:_nthStyle(style, n)
    local s = self.style[style]
    if s == nil then
        return nil
    end
    local ret = s[n]
    if ret == nil then
        return nil
    end
    if type(ret.value) ~= "table" then
        return ret
    end
    if ret.value.isExprTree then
        local v = ret.value
        ---@cast v Banana.Ncss.ExpressionTree
        -- should be able to assume that units will already be computed
        if ret.type ~= "unit" then
            v:compute(0)
        end
        ret = v.computed
        if ret == nil then
            log.throw("Expression tree returned nil value")
        end
    end
    return ret
end

---Returns the first style value for the given {style} or nil if not found
---Removes expression tree from the possibility
---@param style string the style to lookup
---@return Banana.Ncss.StyleValue?
function M.Ast:_firstStyle(style)
    return self:_nthStyle(style, 1)
end

---@return boolean
function M.Ast:_isComponent()
    return self._isComponentCache
    -- local ret, _ = require("banana.nml.parser").isValidComponentName(self.tag)
    -- return ret
end

---@param nml string
function M.Ast:setInnerNml(nml)
    local ast, styleRules, preScripts, postScripts = require("banana.require")
        .nmlLoadString(nml)

    local doc = self:ownerDocument()
    for _, v in ipairs(postScripts) do
        table.insert(doc.postScripts, v)
    end
    for _, v in ipairs(preScripts) do
        table.insert(doc.preScripts, v)
    end
    for _, v in ipairs(styleRules) do
        table.insert(doc.styleRules, v)
    end
    ast:_applyInstance(doc)
    self:removeChildren()
    self:appendChild(ast)
end

---@param pad number?
---@return string[]
function M.Ast:_dumpTree(pad)
    pad = pad or 0
    local padStr = string.rep(" ", pad)
    local ret = {
        padStr .. "<" .. self.tag
    }
    local id = self:getAttribute("id")
    if id ~= nil then
        table.insert(ret, padStr .. "  id=\"" .. id .. "\"")
    end
    ret[#ret] = ret[#ret] .. ">"
    if self.classes ~= nil and #self.classes ~= 0 then
        table.insert(ret,
            padStr .. "  class=\"" .. self:getAttribute("class") .. "\"")
    end
    pad = pad + 2
    for _, v in ipairs(self.nodes) do
        if type(v) == "string" then
            if #self.nodes == 1 then
                ret[#ret] = ret[#ret] .. " " .. v
            else
                table.insert(ret, padStr .. v)
            end
        else
            local dump = v:_dumpTree(pad)
            for _, d in ipairs(dump) do
                table.insert(ret, d)
            end
        end
    end
    if #self.nodes == 0 or (type(self.nodes[1]) == "string" and #self.nodes == 1) then
        ret[#ret] = ret[#ret] .. " </" .. self.tag .. "> "
    else
        table.insert(ret, padStr .. "</" .. self.tag .. "> ")
    end
    return ret
end

---Returns all style values for the style string
---@param style string the style to lookup
---@return Banana.Ncss.StyleValue[]
function M.Ast:_allStylesFor(style)
    local ret = {}
    local arr = self.style[style] or {}
    for i, _ in ipairs(arr) do
        table.insert(ret, self:_nthStyle(style, i))
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

---Takes a unit style and returns the computed value
---@param style string
---@param default number
---@return number
---@overload fun(self: Banana.Ast, style: string): number?
function M.Ast:_firstStyleComputedValue(style, default)
    local val = self:_firstStyle(style)
    if val == nil or val.type ~= "unit" then
        return default
    end
    -- since we used _firstStyle, can safely ignore
    ---@diagnostic disable-next-line: return-type-mismatch
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
    if styleTp == "number" then
        return counter .. ""
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
        if len >= 388 then return 11 + 2 end
        if len >= 288 then return 10 + 2 end
        if len >= 188 then return 9 + 2 end
        if len >= 88 then return 8 + 2 end
        if len >= 38 then return 7 + 2 end
        if len >= 28 then return 6 + 2 end
        if len >= 18 then return 5 + 2 end
        if len >= 8 then return 4 + 2 end
        if len >= 3 then return 3 + 2 end
        if len >= 2 then return 2 + 2 end
        if len >= 1 then return 1 + 2 end
        return 0
    end
    return math.floor(math.log10(len) + 1) + 2

    -- return math.ceil(math.log10(len)) + 2
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
    if zeroUnit == nil then
        zeroUnit = unit.newUnit("ch", 0, 0)
    end
    self.padding = {
        zeroUnit,
        zeroUnit,
        zeroUnit,
        zeroUnit,
    }
    self.margin = {
        zeroUnit,
        zeroUnit,
        zeroUnit,
        zeroUnit,
    }
    self.hidden = true
    self.style = {}
    self:_unlockGradients()
    self.hl = {}
    self.precedences = {}
    -- setmetatable(self.hl, weak)
    -- setmetatable(self.style, weak)
    -- setmetatable(self.precedences, weak)
end

function M.Ast:_clearStyles()
    if self:_isComponent() and self.componentTree == nil then
        self:_tryMountComponent()
    end
    if self.componentTree ~= nil then
        self.componentTree:_clearStyles()
    end
    self:_defaultStyles()
    for node in self:childIter() do
        node:_clearStyles()
    end
end

---Applies the ast metatable to an ast tree (after cloning)
---@param self Banana.Ast
---@param ast Banana.Ast
local function applyAstMeta(self, ast)
    setmetatable(ast, getmetatable(self))
    for _, v in ipairs(ast.nodes) do
        if type(v) ~= "string" then
            applyAstMeta(self, v)
            v._parent = ast
        end
    end
end

function M.Ast:cloneNode(deep)
    return self:clone(deep)
end

function M.Ast:_postAppend()
    if self:_isComponent() then
        self:_tryMountComponent()
    end
end

---Adds {child} to this node's child list right before {referenceNode}
---@param child Banana.Ast|string
---@param referenceNode Banana.Ast|string
function M.Ast:insertBefore(child, referenceNode)
    if type(child) == "table" then
        child:_breakParentTies()
        child._parent = self
    end
    local found = false
    for i, v in ipairs(self.nodes) do
        if v == referenceNode then
            found = true
            table.insert(self.nodes, i, child)
            break
        end
    end
    if not found then
        table.insert(self.nodes, 1, child)
        if type(child) == "table" then
            child:_postAppend()
        end
    end
    self:_requestRender()
end

---Removes {child} from this node's child list
---@param child Banana.Ast|string
---@return Banana.Ast|string|nil
function M.Ast:removeChild(child)
    if type(child) == "table" then
        child:_breakParentTies()
        child._parent = self
        return child
    end
    for i, v in ipairs(self.nodes) do
        if v == child then
            table.remove(self.nodes, i)
            self:_requestRender()
            return child
        end
    end
    return nil
end

---Replaces {child} from this node's child list with {newChild}
---@param child Banana.Ast|string
---@param newChild Banana.Ast|string
---@return Banana.Ast|string|nil
function M.Ast:replaceChild(newChild, child)
    for i, v in ipairs(self.nodes) do
        if v == child then
            self.nodes[i] = newChild
            if type(child) == "table" then
                child:remove()
            else
                self:_requestRender()
            end
            if type(newChild) == "table" then
                newChild:_breakParentTies()
                newChild._parent = self
                newChild:_postAppend()
            end
            return child
        end
    end
    return nil
end

---@param allowString false? whether to include the string nodes
---@return Banana.Ast
---@overload fun(allowString: true): Banana.Ast|string
function M.Ast:firstChild(allowString)
    if allowString then
        return self.nodes[1] or _inst.getNilAst()
    end
    return self:child(1) or _inst.getNilAst()
end

---@param allowString false? whether to include the string nodes
---@return Banana.Ast
---@overload fun(allowString: true): Banana.Ast|string
function M.Ast:lastChild(allowString)
    if allowString then
        return self.nodes[#self.nodes] or _inst.getNilAst()
    end
    for i = #self.nodes, 1, -1 do
        if type(self.nodes[i]) == "table" then
            return self.nodes[i]
        end
    end
    return _inst.getNilAst()
end

---@param allowString false? whether to include the string nodes
---@return Banana.Ast
---@overload fun(allowString: true): Banana.Ast|string
function M.Ast:nextSibling(allowString)
    local j = 0
    local parNodes = self._parent.nodes
    for i, v in ipairs(parNodes) do
        if v == self then
            j = i
        end
    end
    if j == 0 then
        return _inst.getNilAst()
    end
    if allowString then
        return parNodes[j + 1] or _inst.getNilAst()
    end
    j = j + 1
    while j <= #parNodes and type(parNodes) ~= "table" do
        j = j + 1
    end
    return parNodes[j] or _inst.getNilAst()
end

---@param allowString false? whether to include the string nodes
---@return Banana.Ast
---@overload fun(allowString: true): Banana.Ast|string
function M.Ast:previousSibling(allowString)
    local j = 0
    local parNodes = self._parent.nodes
    for i, v in ipairs(parNodes) do
        if v == self then
            j = i
        end
    end
    if j == 0 then
        return _inst.getNilAst()
    end
    if allowString then
        return parNodes[j + 1] or _inst.getNilAst()
    end
    j = j + 1
    while j <= #parNodes and type(parNodes) ~= "table" do
        j = j + 1
    end
    return parNodes[j] or _inst.getNilAst()
end

---Returns the document owner
---@return Banana.Instance
function M.Ast:ownerDocument()
    if self.instance == nil then
        log.throw("ast does not have an associated document")
        error("")
    end
    local ret = _inst.getInstance(self.instance or 0)
    if ret == nil then
        log.throw("ast does not have an associated document")
        error("")
    end
    return ret
end

---Duplicates this node and all its children (note: does NOT copy attached events)
---@param deep boolean
---@return Banana.Ast
function M.Ast:clone(deep)
    deep = deep or false
    local newAst = {}
    newAst.nodes = {}
    for _, v in ipairs(self.nodes) do
        if type(v) ~= "string" then
            if deep then
                table.insert(newAst.nodes, v:clone(deep))
            else
                table.insert(newAst.nodes, v)
            end
        else
            table.insert(newAst.nodes, v)
        end
    end
    newAst.fromFile = self.fromFile
    newAst.componentPath = self.componentPath
    newAst.tag = self.tag
    newAst.attributes = vim.fn.deepcopy(self.attributes)
    newAst.actualTag = self.actualTag
    newAst.style = vim.fn.copy(self.style)
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
    newAst._parent = _inst.getNilAst()
    if self.inlineStyle ~= nil then
        newAst.inlineStyle = vim.fn.deepcopy(self.inlineStyle)
    end
    if self.listCounter ~= nil then
        newAst.listCounter = 1
    end
    applyAstMeta(self, newAst)
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
    end
    self.attributes[name] = value
    if name == "class" then
        self:hasClass("a")
    end
    self:_requestRender()
end

---@return string[]
function M.Ast:getAttributes()
    ---@type { [string]: string }
    local ret = {}
    for k, _ in pairs(self.attributes) do
        ret[k] = self:getAttribute(k) or ""
    end
    return ret
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

function M.Ast:_addClass(c)
    if self.classes == nil then
        self.classes = {}
    end
    if not self.classes[c] then
        self.classes[c] = true
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
    if self.tag == "h1" or self.tag == "strong" then
        ret.bold = true
    end
    if self.tag == "em" then
        ret.italic = true
    end

    if self.tag == "a" then
        ret.underline = true
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
---@return number?
function M.Ast:_computeUnitFor(prop, basedOn)
    local style = self.style[prop]
    local ret = nil
    if style ~= nil then
        for _, s in ipairs(style) do
            if s.type ~= "unit" then
                goto continue
            end
            ---@diagnostic disable-next-line: param-type-mismatch
            local v = s.value:compute(basedOn)
            if type(v) == "table" then
                v = v.value.computed
            end
            ---@cast v number
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
function M.Ast:_resolveUnits(parentWidth, parentHeight)
    --flame.new("Ast:resolveUnits")
    --flame.new("Ast:resolveUnits_marg")
    for i, v in ipairs(self.margin) do
        if i % 2 == 1 then
            v:compute(parentWidth)
        else
            v:compute(parentHeight)
        end
    end
    for i, v in ipairs(self.padding) do
        if i % 2 == 1 then
            v:compute(parentWidth)
        else
            v:compute(parentHeight)
        end
    end
    --flame.pop()
    self:_computeUnitFor("list-base-width", parentWidth)
    self:_computeUnitFor("width", parentWidth)
    self:_computeUnitFor("height", parentHeight)
    ---@diagnostic disable-next-line: param-type-mismatch
    local aspectRatio = math.max(self:_firstStyleValue("aspect-ratio", 0), 0)

    if self.style.width == nil and self.style.height ~= nil and aspectRatio ~= 0 then
        ---@type Banana.Ncss.StyleValue
        local width = {
            type = "unit",
            value = unit {
                unit = "ch",
                computed = self:_firstStyleComputedValue("height", 0) *
                    self:_firstStyleValue("aspect-ratio", 1) * 2,
                value = self:_firstStyleComputedValue("height", 0) *
                    self:_firstStyleValue("aspect-ratio", 1) * 2
            }
        }
        self.style.width = { width }
    elseif self.style.height == nil and self.style.width ~= nil and aspectRatio ~= 0 then
        ---@type Banana.Ncss.StyleValue
        local height = {
            type = "unit",
            value = unit.newUnit(
                "ch",
                math.floor(self:_firstStyleComputedValue("width", 0) /
                    self:_firstStyleValue("aspect-ratio", 1) / 2),
                math.floor(self:_firstStyleComputedValue("width", 0) /
                    self:_firstStyleValue("aspect-ratio", 1) / 2)
            )
        }
        self.style.height = { height }
    elseif self.style["aspect-ratio"] ~= nil then
        if aspectRatio == 0 then
            log.warn(self.tag ..
                " element has aspect-ratio set to <= 0. Ignoring this because negative or 0 aspect ratios can cause infinite loops")
        else
            log.warn(self.tag ..
                " element has aspect-ratio, width, and height set. aspect-ratio will do nothing because both width and height are set")
        end
    end
    self:_computeUnitFor("top", parentHeight)
    self:_computeUnitFor("bottom", parentHeight)
    self:_computeUnitFor("left", parentWidth)
    self:_computeUnitFor("right", parentWidth)
    self:_computeUnitFor("flex-basis", parentWidth)
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
        if v.namespace == "hl" then
            local name = v.actualName

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
        elseif v.namespace == "padding" then
            local side = v.actualName

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
        elseif v.namespace == "margin" then
            local side = v.actualName

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
    if self._parent == nil then return end
    if self._parent == _inst.getNilAst() then
        log.throw(
            "Attempting to remove the root node")
        error("")
    end
    self:_breakParentTies()
    -- if self.componentTree ~= nil then
    --     -- just add it to prevent the root node removal error
    --     self.componentTree._parent = self
    --     self.componentTree:remove()
    -- end
    self:_unlockGradients()
    self:ownerDocument():_removeMapsFor(self)
    self:_requestRender()
end

function M.Ast:_breakParentTies()
    for i, v in ipairs(self._parent.nodes) do
        if v == self then
            table.remove(self._parent.nodes, i)
            break
        end
    end
    self._parent = nil
end

---Returns the attribute value for {name} or nil if not found
---@param name string the name of the attribute to get
---@return string?
function M.Ast:getAttribute(name)
    if name == "class" then
        if self.classes == nil then
            return nil
        end
        return vim.iter(self.classes):map(function (k, _) return k end):join(" ")
    end
    return self.attributes[name]
end

---Returns true if this node has attribute {name} set
---@param name string
---@return boolean
function M.Ast:hasAttribute(name)
    return self.attributes[name] ~= nil
end

---Adds {text} to the child list of the node
---@param text string the text to add to the node
function M.Ast:appendTextNode(text)
    if text:sub(1, 1) == "%" then
        table.insert(self.nodes, "%%")
        text = text:sub(2, #text)
    elseif text:sub(1, 1) == "&" then
        table.insert(self.nodes, "&amp;")
        text = text:sub(2, #text)
    end
    table.insert(self.nodes, text)
    self:_requestRender()
end

---Adds {text} to the child list of the node
---@param text string the text to add to the node
function M.Ast:appendTextNodeNoEscape(text)
    table.insert(self.nodes, text)
    self:_requestRender()
end

---Adds {node} as a child to this node
---@param node Banana.Ast the node to append as a child
function M.Ast:_appendChild(node)
    -- TODO: Check if they are trying to put block inside of inline
    node._parent = self
    table.insert(self.nodes, node)
    if self.instance ~= nil then
        node:_applyInstance(self:ownerDocument())
    end
    node:_postAppend()
end

---Adds {node} as a child to this node
---@param node Banana.Ast the node to append as a child
function M.Ast:appendChild(node)
    self:_appendChild(node)
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
    if type(self.hl.fg) == "table" then
        ---@type Banana.Gradient
        ---@diagnostic disable-next-line: assign-type-mismatch
        local grad = self.hl.fg
        grad:moveLeftBy(number, self)
        if self._parent.tag == "progress" and self._parent:getAttribute("adjust-filled") ~= "no" then
            grad:moveLeftBy(number, self._parent)
        end
    end
    if type(self.hl.bg) == "table" then
        ---@type Banana.Gradient
        ---@diagnostic disable-next-line: assign-type-mismatch
        local grad = self.hl.bg
        grad:moveLeftBy(number, self)
        if self._parent.tag == "progress" and self._parent:getAttribute("adjust-filled") ~= "no" then
            grad:moveLeftBy(number, self._parent)
        end
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
    if type(self.hl.fg) == "table" then
        ---@type Banana.Gradient
        ---@diagnostic disable-next-line: assign-type-mismatch
        local grad = self.hl.fg
        grad:moveDownBy(number, self)
        if self._parent.tag == "progress" and self._parent:getAttribute("adjust-filled") ~= "no" then
            grad:moveDownBy(number, self._parent)
        end
    end
    if type(self.hl.bg) == "table" then
        ---@type Banana.Gradient
        ---@diagnostic disable-next-line: assign-type-mismatch
        local grad = self.hl.bg
        grad:moveDownBy(number, self)
        if self._parent.tag == "progress" and self._parent:getAttribute("adjust-filled") ~= "no" then
            grad:moveDownBy(number, self._parent)
        end
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
    while i <= #self.nodes do
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
function M.Ast:allChildIter()
    local i = 0
    return function ()
        --flame.new("Ast:childIter")
        i = i + 1
        --flame.pop()
        ---@diagnostic disable-next-line: return-type-mismatch
        return self.nodes[i]
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
    return _inst.getNilAst()
end

---returns what the attribute substitution (eg %attr in nml) would be for {name}
---@param name string the attribute to lookup
---@return string?
function M.Ast:getAttributeSubstitution(name)
    if name:sub(#name, #name) == ";" then
        name = name:sub(1, #name - 1)
    end
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
        -- log.warn("Could not find attribute '" ..
        --     name .. "' for template substitution")
        -- vim.notify("Could not find attribute '" ..
        --     name .. "' for template substitution")
    else
        v = el:getAttribute(name) or ""
    end
    return v
end

---Returns the printed text value of this element (does not include newlines)
---@return string
function M.Ast:getTextContent()
    -- TODO: Handle substitutions and stuff
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
    self.nodes = vim.split(str, "\n")
    for j = #self.nodes, 2, -1 do
        table.insert(self.nodes, j, M.Ast:new("br", self, "anon"))
    end
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
    return self.hidden
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
        if self:isHidden() then
            return false
        end
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
    local inst = self:ownerDocument()
    inst:_setRemap(mode, lhs, actualRhs, opts, self)
end

function M.Ast:_requestRender()
    if self.instance == nil then
        return
    end
    local inst = self:ownerDocument()
    if inst == nil then
        log.throw("ast does not have an associated document")
        error("")
    end
    inst:_requestRender()
end

return M
