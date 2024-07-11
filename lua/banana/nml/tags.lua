local M = {}
local _str = require('banana.utils.string')
local _ast = require('banana.nml.ast')
local b = require('banana.box')

---@class (exact) Banana.Renderer.Surround
---@field left number
---@field right number
---@field top number
---@field bottom number
---@field fillChar? string For borders if they ever happen

---@class (exact) Banana.Renderer.PartialRendered
---@field margin Banana.Renderer.Surround
---@field padding Banana.Renderer.Surround
---@field widthExpansion number
---@field heightExpansion number
---@field center Banana.Box
---@field marginColor? Banana.Highlight
---@field mainColor? Banana.Highlight
---@field renderAlign "left"|"center"|"right"
---@field maxWidth number
local PartialRendered = {}

---@return Banana.Renderer.PartialRendered
local function emptyPartialRendered()
    ---@type Banana.Renderer.PartialRendered
    local ret = {
        maxWidth = 0,
        renderAlign = "left",
        mainColor = {},
        marginColor = {},
        center = b.Box:new(),
        heightExpansion = 0,
        widthExpansion = 0,
        margin = {
            top    = 0,
            left   = 0,
            right  = 0,
            bottom = 0,
        },
        padding = {
            top    = 0,
            left   = 0,
            right  = 0,
            bottom = 0,
        },

    }
    setmetatable(ret, {
        __index = PartialRendered,
    })
    return ret
end

---@return number
function PartialRendered:getWidth()
    return self.margin.left + self.margin.right
        + self.padding.left + self.padding.right
        + self.widthExpansion + self.center:width()
end

---@return number
function PartialRendered:getHeight()
    return self.margin.top + self.margin.bottom
        + self.padding.top + self.padding.bottom
        + self.heightExpansion + self.center:height()
end

---@param num number
function PartialRendered:expandWidthTo(num)
    self.widthExpansion = num - (self:getWidth() - self.widthExpansion)
end

---@param num number
function PartialRendered:expandHeightTo(num)
    self.heightExpansion = num - (self:getHeight() - self.heightExpansion)
end

---comment
---@param box Banana.Box
---@param pad Banana.Renderer.Surround
---@param color Banana.Highlight
---@return Banana.Box
function PartialRendered:padWith(box, pad, color)
    if pad.top ~= 0 then
        local topBox = b.Box:new(color)
        topBox:appendStr('', nil)
        topBox:expandWidthTo(box:width())
        topBox:cloneHeightTo(pad.top)
        topBox:appendBoxBelow(box)
        box = topBox
    end
    if pad.bottom ~= 0 then
        local btmBox = b.Box:new(color)
        btmBox:appendStr('', nil)
        btmBox:expandWidthTo(box:width())
        btmBox:cloneHeightTo(pad.bottom)
        box:appendBoxBelow(btmBox)
    end
    if pad.left ~= 0 then
        local leftBox = b.Box:new(color)
        leftBox:appendStr('', nil)
        leftBox:expandWidthTo(pad.left)
        leftBox:cloneHeightTo(box:height())
        leftBox:append(box)
        box = leftBox
    end
    if pad.right ~= 0 then
        local rightBox = b.Box:new(color)
        rightBox:appendStr('', nil)
        rightBox:expandWidthTo(pad.right)
        rightBox:cloneHeightTo(box:height())
        box:append(rightBox)
    end
    return box
end

---@param clone boolean?
---@return Banana.Box
function PartialRendered:render(clone)
    if clone then
        local new = vim.fn.deepcopy(self)
        setmetatable(new, {
            __index = PartialRendered,
        })
        new.center = self.center:clone()
        return new:render()
    end
    clone = clone or false
    local box = self.center
    if clone then
        box = box:clone()
    end
    if self.heightExpansion > 0 then
        local btmBox = b.Box:new(self.mainColor)
        btmBox:appendStr('', nil)
        btmBox:expandWidthTo(box:width())
        btmBox:cloneHeightTo(self.heightExpansion)
        box:appendBoxBelow(btmBox)
    end
    if self.widthExpansion > 0 then
        local left = b.Box:new(self.mainColor)
        left:appendStr('', nil)
        left:expandWidthTo(self.widthExpansion)
        left:cloneHeightTo(box:height())
        if self.renderAlign == "right" then
            left:append(box)
            box = left
        elseif self.renderAlign == "left" then
            box:append(left)
        else
            local l = b.Box:new(self.mainColor)
            l:appendStr('', nil)
            l:expandWidthTo(math.ceil(self.widthExpansion / 2))
            l:cloneHeightTo(box:height())
            local r = b.Box:new(self.mainColor)
            r:appendStr('', nil)
            r:expandWidthTo(math.floor(self.widthExpansion / 2))
            r:cloneHeightTo(box:height())
            l:append(box)
            l:append(r)
            box = l
        end
    end
    box = self:padWith(box, self.padding, self.mainColor)
    box = self:padWith(box, self.margin, self.marginColor)
    return box
end

---@param str string
---@return string
local function snakeToKebab(str)
    local ret, _ = str:gsub('_', '-')
    return ret
end

---@param str string
---@return string
---@diagnostic disable-next-line: unused-local, unused-function
local function kebabToSnake(str)
    local ret, _ = str:gsub('\\-', '_')
    return ret
end

---@param msg string
---@return Banana.Box
local function traceBreak(msg)
    local ret = b.Box:new()
    ret:appendStr("---- line: " .. msg)
    return ret
end

---@class (exact) Banana.Renderer.InheritedProperties
---@field text_align string
---@field position "static"|"absolute"|"sticky"|"relative"
---@field min_size boolean
---@field list_style_type string

---@class (exact) Banana.Renderer.InitialProperties: Banana.Renderer.InheritedProperties
---@field flex_shrink number
---@field flex_wrap "nowrap"|"wrap"

---@enum Banana.Nml.FormatType
M.FormatType = {
    Inline = 1,
    Block = 2,
    -- InlineBlock = 3,
    BlockInline = 4,
    Script = 5,
}

---@alias Banana.RenderRet Banana.Box

---@class (exact) Banana.Renderer.ExtraInfo
---@field box Banana.Box?
---@field trace Banana.Box
---@field debug boolean

---Gosh so many parameters i might die
---@alias Banana.Renderer fun(self: Banana.TagInfo, ast: Banana.Ast, parentHl: Banana.Highlight?, parentWidth: number, parentHeight: number, startX: number, startY: number, inherit: Banana.Renderer.InheritedProperties, extra: Banana.Renderer.ExtraInfo): Banana.RenderRet


---@class (exact) Banana.TagInfo
---@field name string
---@field formatType Banana.Nml.FormatType
---@field selfClosing boolean
---@field initialProps Banana.Renderer.InitialProperties
---@field private render Banana.Renderer
local TagInfo = {
    name = '',
    formatType = M.FormatType.Inline,
    selfClosing = false,
    render = function(_) return {} end,
}

---@param name string
---@param ast Banana.Ast
---@param ret Banana.Renderer.PartialRendered
---@return Banana.Renderer.PartialRendered, boolean
local function applyPad(name, ast, ret)
    local changed = false
    if ast[name][_ast.left].computed ~= 0 then
        ret[name].left = ast[name][_ast.left].computed
        changed = true
    end
    if ast[name][_ast.right].computed ~= 0 then
        ret[name].right = ast[name][_ast.right].computed
        changed = true
    end
    if ast[name][_ast.top].computed ~= 0 then
        ret[name].top = ast[name][_ast.top].computed
        changed = true
    end
    if ast[name][_ast.bottom].computed ~= 0 then
        ret[name].bottom = ast[name][_ast.bottom].computed
        changed = true
    end
    return ret, changed
end

---@param ast Banana.Ast
---@param extraWidth number
---@return boolean
local function isExpandable(ast, extraWidth)
    local isFlexChild = ast._parent ~= nil and ast._parent:firstStyleValue('display') == "flex"
    if isFlexChild then
        return extraWidth > 0 and
            (ast.actualTag.formatType == M.FormatType.Block or ast.actualTag.formatType == M.FormatType.BlockInline) and
            (ast:hasStyle('width') or ast:hasStyle("flex-basis"))
    end

    return (ast.actualTag.formatType == M.FormatType.Block or ast.actualTag.formatType == M.FormatType.BlockInline
        ) and extraWidth > 0
        or ast:hasStyle('width')
end

---@param ast Banana.Ast
---@param startHl Banana.Highlight?
---@param winWidth number
---@param winHeight number
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return Banana.Box
function TagInfo:renderRoot(ast, startHl, winWidth, winHeight, inherit, extra)
    local ret = self:render(ast, startHl, winWidth, winHeight, 1, 1, inherit, extra)
    return ret
end

---@param ast Banana.Ast
---@param parentHl Banana.Highlight?
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return Banana.Renderer.PartialRendered
function TagInfo:getRendered(ast, parentHl, parentWidth, parentHeight, startX, startY, inherit, extra)
    ast.relativeBoxId = nil
    local inheritOld = {}
    for k, _ in pairs(inherit) do
        local style = snakeToKebab(k)
        if ast:hasStyle(style) then
            inheritOld[k] = inherit[k]
            inherit[k] = ast:firstStyleValue(style)
            if inherit[k] == "initial" then
                inherit[k] = ast:_getInitialStyles()[k]
            end
        end
    end
    local position = ast:firstStyleValue("position")
    if position == nil or position == "initial" then
        position = ast:_getInitialStyles().position
    end
    if position == "absolute" then
        local root = ast
        while root.absoluteAsts == nil do
            root = root._parent
        end
        table.insert(root.absoluteAsts, ast)
        for k, _ in pairs(inheritOld) do
            inherit[k] = inheritOld[k]
        end
        return emptyPartialRendered()
    end
    local disp = ast:firstStyleValue("display")
    if disp == "hidden" then
        for k, _ in pairs(inheritOld) do
            inherit[k] = inheritOld[k]
        end

        return emptyPartialRendered()
    end
    if ast:hasStyle('width') then
        -- add margins bc width only sets content-width + padding
        ---@diagnostic disable-next-line: cast-local-type
        parentWidth = math.min(
            ast:firstStyleValue('width').computed + ast:marginLeft() + ast:marginRight(),
            parentWidth)
        if inherit.min_size then
            inherit.min_size = false
        end
    end
    if ast:hasStyle('height') then
        ---@diagnostic disable-next-line: cast-local-type
        parentHeight = math.min(
            ast:firstStyleValue('height').computed + ast:marginTop() + ast:marginBottom(),
            parentHeight)
    end
    if position ~= "static" then
        if ast:hasStyle("left") then
            startX = startX + ast:firstStyleValue("left").computed
        elseif ast:hasStyle("right") then
            startX = startX - ast:firstStyleValue("right").computed
        end
        if ast:hasStyle("top") then
            startY = startY + ast:firstStyleValue("top").computed
        elseif ast:hasStyle("bottom") then
            startY = startY + ast:firstStyleValue("bottom").computed
        end
    end
    startX = startX + ast:marginLeft()
    startY = startY + ast:marginTop()
    ---@type Banana.Ast.BoundingBox
    local boundBox = {
        leftX   = startX,
        topY    = startY,
        rightX  = 0,
        bottomY = 0,
    }
    startX = startX + ast:paddingLeft()
    startY = startY + ast:paddingTop()
    local contentWidth = parentWidth - ast:_extraLr()
    -- techincally this should be in li renderer BUT we would have to reresolve
    -- units (maybe?) but this would fall apart if something is an fr?
    -- cant really ignore frs bc someone could have a ul flex
    -- or we could have a thing that ensures only not frs are recalced
    local listTick = nil
    local widthAlloted = nil
    if ast.actualTag.name == "li" then
        listTick = ast:parent():_getNextListItem(inherit.list_style_type)
        widthAlloted = _str.charWidth(listTick)
        if ast:parent().listCounter ~= nil then
            widthAlloted = ast:parent():_getMaxListWidth(inherit.list_style_type)
        end
        contentWidth = contentWidth - widthAlloted
    end
    ---@cast parentWidth number
    ---@cast parentHeight number
    local centerBox = self:render(ast, parentHl, contentWidth, parentHeight, startX, startY, inherit, extra)
    if listTick ~= nil then
        if extra.debug then
            extra.trace:appendBoxBelow(traceBreak("Adding list item '" .. listTick .. "'"), false)
        end
        listTick = string.rep(' ', widthAlloted - _str.charWidth(listTick)) .. listTick
        local box = b.Box:new(parentHl)
        box:appendStr(listTick)
        box:expandHeightTo(centerBox:height())
        if extra.debug then
            extra.trace:appendBoxBelow(traceBreak("List item box"), false)
            extra.trace:appendBoxBelow(box, false)
        end
        box:append(centerBox)
        local oldHl = centerBox.hlgroup
        centerBox = box
        centerBox.hlgroup = oldHl
        -- centerBox:appendLeft(box)
    end
    ---@type Banana.Renderer.Surround
    local margin = {
        left = 0,
        right = 0,
        top = 0,
        bottom = 0,
    }
    ---@type Banana.Renderer.Surround
    local padding = {
        left = 0,
        right = 0,
        top = 0,
        bottom = 0,
    }
    if extra.debug then
        extra.trace:appendBoxBelow(traceBreak("Raw render"), false)
        extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
        extra.trace:appendBoxBelow(centerBox:clone(), false)
    end
    ---@type Banana.Renderer.PartialRendered
    local ret = emptyPartialRendered()
    ret.margin = margin
    ret.padding = padding
    ret.center = centerBox
    ret.marginColor = parentHl
    ret.mainColor = centerBox.hlgroup
    ret.renderAlign = "left"
    local extraWidth = parentWidth - ret:getWidth() - ast:_extraLr()
    if isExpandable(ast, extraWidth) and not inherit.min_size then
        ret.center:clean()
        ret.widthExpansion = extraWidth
        if inherit.text_align == "left" then
        elseif inherit.text_align == "right" then
            ret.renderAlign = "right"
        elseif inherit.text_align == "center" then
            ret.renderAlign = "center"
        end
        if extra.debug then
            extra.trace:appendBoxBelow(traceBreak("Expansion w"), false)
            extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
            extra.trace:appendBoxBelow(ret:render(true), false)
        end
    end
    if ast.style['height'] ~= nil and not ast:parent():isNil() then
        ret.center:clean()
        local height = ast.style['height'][1].value.computed
            - ast:paddingTop() - ast:paddingBottom()
        ret.heightExpansion = height - ret.center:height()
        ---@cast height number
        if extra.debug then
            extra.trace:appendBoxBelow(traceBreak("Expansion h"), false)
            extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
            extra.trace:appendBoxBelow(ret:render(true), false)
        end
    end
    local changed = false
    ret, changed = applyPad('padding', ast, ret)
    if changed then
        if extra.debug then
            extra.trace:appendBoxBelow(traceBreak("pad"), false)
            extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
            extra.trace:appendBoxBelow(ret:render(true), false)
        end
    end
    boundBox.rightX = boundBox.leftX + ret:getWidth()
    boundBox.bottomY = boundBox.topY + ret:getHeight()
    ast.boundBox = boundBox
    if position ~= "static" then
        local newRet = b.Box:new(parentHl)
        local render = ret:render(true)
        while newRet:height() < render:height() do
            local newBox = b.Box:new(newRet.hlgroup)
            newBox:appendStr(string.rep(' ', render:width()))
            newRet:appendBoxBelow(newBox)
        end
        newRet:clean()
        if extra.debug then
            extra.trace:appendBoxBelow(traceBreak("float render"), false)
            extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
            extra.trace:appendBoxBelow(render:clone(), false)
            extra.trace:appendBoxBelow(traceBreak("extraRender render"), false)
            extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
            extra.trace:appendBoxBelow(newRet:clone(), false)
        end
        local root = ast
        while root.relativeBoxes == nil do
            root = root._parent
        end
        table.insert(root.relativeBoxes, {
            box = render,
            left = startX - 1 - ast:paddingLeft(),
            top = startY - 1 - ast:paddingTop(),
            z = (ast.style['z-index'] or { {} })[1].value or 0
        })
        ast.relativeBoxId = #root.relativeBoxes
        ret.center = newRet
        ret.mainColor = parentHl
        ret.padding.left = 0
        ret.padding.right = 0
        ret.padding.top = 0
        ret.padding.bottom = 0
        ret.widthExpansion = 0
        ret.heightExpansion = 0
        if ast:hasStyle("left") then
            startX = startX - ast.style.left[1].value.computed
        elseif ast:hasStyle("right") then
            startX = startX + ast.style.right[1].value.computed
        end
        if ast:hasStyle("top") then
            startY = startY - ast.style.top[1].value.computed
        elseif ast:hasStyle("bottom") then
            startY = startY + ast.style.bottom[1].value.computed
        end
        if extra.debug then
            extra.trace:appendBoxBelow(traceBreak("new render"), false)
            extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
            extra.trace:appendBoxBelow(ret:render(true), false)
        end
    end
    ret, changed = applyPad('margin', ast, ret)
    if changed then
        if extra.debug then
            extra.trace:appendBoxBelow(traceBreak("margin"), false)
            extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
            extra.trace:appendBoxBelow(ret:render(true), false)
        end
    end
    if ast.absoluteAsts ~= nil then
        for _, v in ipairs(ast.absoluteAsts) do
            v:resolveUnits(parentWidth, parentHeight)
            v.style.position[1].value = "relative"
            v.actualTag:getRendered(
                v, ret.mainColor, parentWidth, parentHeight, startX, startY, inherit,
                extra)
            v.style.position[1].value = "absolute"
        end
    end
    if ast.relativeBoxes ~= nil then
        table.sort(ast.relativeBoxes, function(l, r)
            return l.z < r.z
        end)
        local rendered = ret:render()
        for _, data in ipairs(ast.relativeBoxes) do
            rendered:renderOver(data.box, data.left, data.top)
        end
        ret.center = rendered
        ret.margin.left = 0
        ret.margin.right = 0
        ret.margin.top = 0
        ret.margin.bottom = 0
        ret.padding.left = 0
        ret.padding.right = 0
        ret.padding.top = 0
        ret.padding.bottom = 0
    end
    for k, _ in pairs(inheritOld) do
        inherit[k] = inheritOld[k]
    end
    return ret
end

---Returns an iterator that renders blocks
---@param ast  Banana.Ast
---@param parentHl Banana.Highlight?
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return fun(): integer?, Banana.Box?, integer?
function TagInfo:blockIter(ast, parentHl, parentWidth, parentHeight, startX, startY, inherit, extra)
    local i = 1
    return function()
        if i > #ast.nodes then
            return nil
        end
        local oldI = i
        local render = nil
        if ast:firstStyleValue("display") == "flex" then
            -- error("impl flex")
            render = self:renderFlexBlock(
                ast, parentHl, parentWidth, parentHeight,
                startX, startY, inherit, extra)
            i = #ast.nodes + 1
        else
            render, i = self:renderBlock(
                ast, parentHl, i, parentWidth, parentHeight,
                startX, startY, inherit, extra)
        end
        startY = startY + render:height()
        return oldI, render, i - oldI
    end
end

---@param ast Banana.Ast
---@param parentHl Banana.Highlight?
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@param inherit Banana.Renderer.InheritedProperties
---@return Banana.Box
function TagInfo:renderInlineEl(ast, parentHl, parentWidth, parentHeight, startX, startY, inherit, extra)
    ---@type Banana.Box
    local ret, _ = self:renderBlock(ast, ast:mixHl(parentHl), 1, parentWidth, parentHeight, startX, startY, inherit,
        extra)
    return ret
end

---@param targetWidth number
---@param box Banana.Box
---@param hl Banana.Highlight?
---@return Banana.Box, Banana.Box
local function splitLineBoxOnce(targetWidth, box, hl)
    if targetWidth < 1 then
        targetWidth = 1
    end
    if box:width() < targetWidth then
        return box, b.Box:new(hl)
    end
    -- if targetWidth == 0 then
    --     targetWidth = 1
    -- end
    local left = b.Box:new(hl)
    left:appendStr("", nil)
    local right = b.Box:new(hl)
    right:appendStr("", nil)
    local i = 1
    while left:width() + _str.charWidth(box:getLine(1)[i].word) < targetWidth do
        left:appendWord(box:getLine(1)[i])
        i = i + 1
    end
    local word = box:getLine(1)[i]
    local leftIns = _str.sub(word.word, 1, targetWidth - left:width())
    --Allow unsafe #word.word, bc #word.word is always >= str.charWidth(word.word)
    --so since we are just reading to end of string
    local rightIns = _str.sub(word.word, targetWidth - left:width() + 1, #word.word)
    left:appendWord({
        word = leftIns,
        style = word.style,
    })
    right:appendWord({
        word = rightIns,
        style = word.style,
    })
    i = i + 1
    while i <= #box:getLine(1) do
        right:appendWord(box:getLine(1)[i])
        i = i + 1
    end
    return left, right
end

---@param ast Banana.Ast|string
---@return boolean
local function breakable(ast)
    if type(ast) == "string" then
        return true
    end
    return ast:paddingRight() == 0 and ast:paddingLeft() == 0 and not ast:hasStyle("width")
end


---@param ast Banana.Ast
---@param i number
---@param currentLine Banana.Box
---@param append Banana.Box
---@param maxWidth number
---@param hl Banana.Highlight?
---@return Banana.Box, Banana.Box?
local function handleOverflow(ast, i, currentLine, append, maxWidth, hl)
    if currentLine:height() == 0 then
        currentLine:appendStr("", nil)
    end
    if currentLine:width() + append:width() <= maxWidth then
        currentLine:append(append, nil)
        return currentLine, nil
    end
    if append:height() ~= 1 or not breakable(ast.nodes[i]) then
        return currentLine, append
    end
    if currentLine:height() ~= 1 then
        local ap, extra = splitLineBoxOnce(maxWidth - currentLine:width(), append, hl)
        currentLine:append(ap, nil)
        return currentLine, extra
    end
    currentLine:append(append, nil)
    local preStuff = b.Box:new(hl)
    local extra = nil
    repeat
        currentLine, extra = splitLineBoxOnce(maxWidth, currentLine, hl)
        preStuff:appendBoxBelow(currentLine, false)
        currentLine = extra
    until extra:width() <= maxWidth
    return preStuff, extra
end


---@param ast Banana.Ast
---@return boolean
local function hasNoFrUnits(ast)
    for _, nodes in pairs(ast.style) do
        for _, v in ipairs(nodes) do
            if v.type == "unit" and v.value.unit == "fr" then
                assert(ast:hasStyle("width"), "an ast with fractional units must have a width/height")
                assert(ast:firstStyleValue("width").unit == "fr",
                    "an ast with fractional units must have a width/height with unit fr")
                return false
            end
        end
    end
    return true
end

-- Flex todo:
-- flex-direction
-- flex-wrap
-- impl emergency shrink
-- impl double emergency float rendering

---@param renders ([Banana.Renderer.PartialRendered, Banana.Ast]?)[]
---@param parentWidth number
---@param takenWidth number
---@param start number
---@param e number
local function flexGrowSection(parentWidth, takenWidth, renders, start, e)
    if takenWidth > parentWidth then
        return
    end
    local totalGrows = 0
    for i = start, e do
        local val = renders[i]
        if val == nil then
            goto continue
        end
        local node = val[2]
        totalGrows = totalGrows + node:firstStyleValue("flex-grow", 0)
        ::continue::
    end
    if totalGrows > 0 then
        local growPer = math.floor((parentWidth - takenWidth) / totalGrows)
        local extraGrow = parentWidth - takenWidth - growPer * totalGrows
        -- compute flex grow
        for i = start, e do
            local val = renders[i]
            if val == nil then
                goto continue
            end
            local node = val[2]
            if node:firstStyleValue("flex-grow", 0) ~= 0 then
                local flexGrow = node:firstStyleValue("flex-grow", 0)
                ---@cast flexGrow number
                local grow = growPer * flexGrow
                if extraGrow > 0 then
                    grow = grow + math.ceil(flexGrow)
                    extraGrow = extraGrow - math.ceil(flexGrow)
                end
                renders[i][1].widthExpansion = renders[i][1].widthExpansion + grow
                renders[i][2]:_increaseWidthBoundBy(grow)
            end
            ::continue::
        end
    end
end

---Renders everything in a flex block
---@param ast Banana.Ast
---@param parentHl Banana.Highlight?
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return Banana.Box, integer
function TagInfo:renderFlexBlock(ast, parentHl, parentWidth, parentHeight, startX, startY, inherit, extra)
    local oldMinSize = inherit.min_size
    inherit.min_size = true
    local takenWidth = 0
    local hl = ast:mixHl(parentHl)
    ---@type ([Banana.Renderer.PartialRendered, Banana.Ast]?)[]
    local renders = {}
    ---@type integer[]
    local needed = {}
    -- local currentHeight = 0
    local rendersLen = 0

    -- base render for non fr els
    for i, v in ipairs(ast.nodes) do
        if type(v) == "string" then
            goto continue
        end

        if not hasNoFrUnits(v) then
            renders[rendersLen + 1] = nil
            table.insert(needed, i)
            rendersLen = rendersLen + 1
            goto continue
        end

        v:resolveUnits(parentWidth, parentHeight)
        local basis = v:firstStyleValue("flex-basis", {
            computed = parentWidth,
            unit = "ch",
            value = parentWidth,
        })
        ---@cast basis Banana.Ncss.UnitValue
        local basisVal = math.min(basis.computed or parentWidth, parentWidth)
        if v:firstStyleValue("flex-shrink") == 0 or v:hasStyle('flex-basis') then
            inherit.min_size = false
        end
        local rendered = v.actualTag:getRendered(v, hl, basisVal, parentHeight, startX, startY, inherit, extra)
        -- if rendered:getHeight() < currentHeight then
        --     rendered:expandHeightTo(currentHeight)
        -- end

        inherit.min_size = true

        renders[rendersLen + 1] = { rendered, v }
        rendersLen = rendersLen + 1
        -- if rendered:getHeight() > currentHeight then
        --     currentHeight = rendered:getHeight()
        -- end

        takenWidth = takenWidth + rendered:getWidth()

        ::continue::
    end

    if extra.debug then
        extra.trace:appendBoxBelow(traceBreak("flex w/o fr"), false)
        extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
        for i, v in ipairs(renders) do
            if v ~= nil then
                extra.trace:appendBoxBelow(traceBreak(i .. ""), false)
                extra.trace:appendBoxBelow(v[1]:render(true), false)
            else
                extra.trace:appendBoxBelow(traceBreak(i .. ""), false)
                local box = b.Box:new()
                box:appendStr("empty")
                extra.trace:appendBoxBelow(box, false)
            end
        end
    end

    -- compute frs
    local widthLeft = parentWidth - takenWidth
    -- go through and add margins so that they are accounted for
    for _, i in ipairs(needed) do
        local v = ast.nodes[i]
        ---@cast v Banana.Ast
        v:resolveUnits(parentWidth, parentHeight, {
            0
        })
        widthLeft = widthLeft - v:marginLeft() - v:marginRight()
    end
    local totalFrs = 0
    for _, i in ipairs(needed) do
        local v = ast.nodes[i]
        ---@cast v Banana.Ast
        totalFrs = totalFrs + v:firstStyleValue("width").value
        if v:_marginUnit(_ast.left).unit == "fr" then
            totalFrs = totalFrs + v:_marginUnit(_ast.left).value
        end
        if v:_marginUnit(_ast.right).unit == "fr" then
            totalFrs = totalFrs + v:_marginUnit(_ast.right).value
        end
    end
    local frWidth = math.floor(widthLeft / totalFrs)
    local extraCharsNeeded = widthLeft - totalFrs * frWidth
    inherit.min_size = true
    for _, i in ipairs(needed) do
        local v = ast.nodes[i]
        local width = frWidth
        if extraCharsNeeded > 0 then
            width = width + 1
            extraCharsNeeded = extraCharsNeeded - 1
        end
        ---@cast v Banana.Ast
        v:resolveUnits(parentWidth, parentHeight, {
            width
        })
        local basis = v:firstStyleValue("flex-basis", {
            computed = parentWidth,
            unit = "ch",
            value = parentWidth,
        })
        ---@cast basis Banana.Ncss.UnitValue
        local basisVal = math.min(basis.computed or parentWidth, parentWidth)
        if v:firstStyleValue("flex-shrink") == 0 or v:hasStyle('flex-basis') then
            inherit.min_size = false
        end
        local rendered = v.actualTag:getRendered(v, hl, basisVal, parentHeight, startX, startY, inherit, extra)
        -- if rendered:getHeight() < currentHeight then
        --     rendered:expandHeightTo(currentHeight)
        -- end

        renders[i] = { rendered, v }
        -- rendersLen = rendersLen + 1
        -- if rendered:getHeight() > currentHeight then
        --     currentHeight = rendered:getHeight()
        -- end

        takenWidth = takenWidth + rendered:getWidth()
    end
    if extra.debug then
        extra.trace:appendBoxBelow(traceBreak("flex w/ fr"), false)
        extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
        for i, v in ipairs(renders) do
            extra.trace:appendBoxBelow(traceBreak(i .. ""), false)
            extra.trace:appendBoxBelow(v[1]:render(true), false)
        end
    end

    -- flex-grow and half of flex-wrap
    if takenWidth < parentWidth then
        flexGrowSection(parentWidth, takenWidth, renders, 1, #renders)
        -- local totalGrows = 0
        -- for node in ast:childIter() do
        --     totalGrows = totalGrows + node:firstStyleValue("flex-grow", 0)
        -- end
        -- if totalGrows > 0 then
        --     local growPer = math.floor((parentWidth - takenWidth) / totalGrows)
        --     local extraGrow = parentWidth - takenWidth - growPer * totalGrows
        --     -- compute flex grow
        --     local i = 1
        --     for node in ast:childIter() do
        --         if node:firstStyleValue("flex-grow", 0) ~= 0 then
        --             local grow = growPer * node:firstStyleValue("flex-grow", 0)
        --             if extraGrow > 0 then
        --                 grow = grow + 1
        --                 extraGrow = extraGrow - 1
        --             end
        --             renders[i][1].widthExpansion = renders[i][1].widthExpansion + grow
        --             renders[i][2]:_increaseWidthBoundBy(grow)
        --         end
        --         i = i + 1
        --     end
        -- end
    elseif ast:firstStyleValue("flex-wrap", "nowrap") == "wrap" then
        local taken = 0
        local startI = 1
        -- local yInc = 0
        for i, v in ipairs(renders) do
            if v == nil then
                error("Unreachable")
            end
            -- if yInc > 0 then
            --     v[2]:_increaseTopBound(yInc)
            -- end
            local render = v[1]
            if taken + render:getWidth() > parentWidth then
                flexGrowSection(parentWidth, taken, renders, startI, i - 1)
                taken = 0
                startI = i
                -- yInc = yInc + renders[startI][1]:getHeight()
            end
            taken = taken + render:getWidth()
        end
        flexGrowSection(parentWidth, taken, renders, startI, #renders)
    end
    if extra.debug then
        extra.trace:appendBoxBelow(traceBreak("flex-grow"), false)
        extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
        for i, v in ipairs(renders) do
            if v ~= nil then
                extra.trace:appendBoxBelow(traceBreak(i .. ""), false)
                extra.trace:appendBoxBelow(v[1]:render(true), false)
            end
        end
    end



    --- post processing cleanup to readjust bound boxes
    local inc = 0
    local yInc = 0
    local isWrap = ast:firstStyleValue("flex-wrap", "nowrap") == "wrap"
    ---@type [Banana.Renderer.PartialRendered, Banana.Ast][][]
    local lines = {}
    ---@type [Banana.Renderer.PartialRendered, Banana.Ast][]
    local line = {}
    for i = 1, #renders do
        local v = renders[i]
        if v == nil then
            error("rendered " .. i .. " was nil!")
        end
        if yInc > 0 then
            renders[i][2]:_increaseTopBound(yInc)
        end
        if inc + renders[i][1]:getWidth() > parentWidth and #line > 0 and isWrap then
            table.insert(lines, line)
            local maxH = 0
            for _, el in ipairs(line) do
                maxH = math.max(el[1]:getHeight(), maxH)
            end
            for _, el in ipairs(line) do
                if el[1]:getHeight() < maxH then
                    el[1]:expandHeightTo(maxH)
                    el[2]:_increaseHeightBoundBy(maxH - el[1]:getHeight())
                end
            end
            yInc = yInc + line[1][1]:getHeight()
            line = {}
            inc = 0
        end
        table.insert(line, renders[i])
        v[2]:_increaseLeftBound(inc)
        inc = inc + v[1]:getWidth()
    end
    table.insert(lines, line)
    local maxH = 0
    for _, v in ipairs(line) do
        maxH = math.max(v[1]:getHeight(), maxH)
    end
    for _, v in ipairs(line) do
        if v[1]:getHeight() < maxH then
            v[1]:expandHeightTo(maxH)
            v[2]:_increaseHeightBoundBy(maxH - v[1]:getHeight())
        end
    end
    if extra.debug then
        extra.trace:appendBoxBelow(traceBreak("Wrapping into " .. #lines .. " lines"), false)
    end

    local ret = b.Box:new(hl)
    for _, l in ipairs(lines) do
        local box = b.Box:new(hl)
        for _, val in ipairs(l) do
            box:append(val[1]:render(), nil)
        end
        ret:appendBoxBelow(box)
    end
    -- for _, v in ipairs(renders) do
    --     if v ~= nil then
    --         ret:append(v[1]:render(), nil)
    --     end
    -- end
    inherit.min_size = oldMinSize

    return ret, #ast.nodes + 1
end

---Renders everything in a block
---@param ast Banana.Ast
---@param parentHl Banana.Highlight?
---@param i integer
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@param inherit Banana.Renderer.InheritedProperties
---@param extra_ Banana.Renderer.ExtraInfo
---@return Banana.Box, integer
function TagInfo:renderBlock(ast, parentHl, i, parentWidth, parentHeight, startX, startY, inherit, extra_)
    local currentLine = b.Box:new(parentHl)
    local hasElements = false
    local width = parentWidth
    local height = parentHeight
    ---@type Banana.Box?
    local extra = nil
    local startI = i
    while i <= #ast.nodes do
        local v = ast.nodes[i]
        if v == nil then
            break
        end
        if type(v) == 'string' then
            if v:sub(1, 1) == "&" then
                error("Entity support is nonexistent")
            elseif v:sub(1, 1) == "%" then
                if v:sub(2, 2) == "%" then
                    v = "%"
                else
                    local attr = v:sub(2, #v)
                    local el = ast
                    while el.attributes[attr] == nil do
                        if el:isNil() then
                            break
                        end
                        el = el._parent
                    end
                    v = el:getAttribute(attr) or ""
                end
            end
            local count = _str.charWidth(v)
            local box = b.Box:new(parentHl)
            box:appendStr(v, nil)
            local overflow = nil
            currentLine, overflow = handleOverflow(ast, i, currentLine, box, width, parentHl)
            if overflow ~= nil then
                if extra == nil then
                    extra = currentLine
                else
                    if extra:width() < currentLine:width() then
                        extra:expandWidthTo(currentLine:width())
                    end
                    if currentLine:width() < extra:width() then
                        currentLine:expandWidthTo(extra:width())
                    end
                    extra:appendBoxBelow(currentLine, false)
                end
                currentLine = overflow
            end
            startX = startX + count
            hasElements = true
        else
            local tag = M.makeTag(v.tag)
            if (tag.formatType == M.FormatType.Block or tag.formatType == M.FormatType.BlockInline) and hasElements then
                break
            end
            v:resolveUnits(width, height)
            local rendered = tag:getRendered(v, parentHl, width, height, startX, startY, inherit, extra_):render()
            startX = startX + rendered:width()
            local overflow = nil
            local orgLines = currentLine:height()
            currentLine, overflow = handleOverflow(ast, i, currentLine, rendered, width, parentHl)
            if rendered:height() > orgLines and overflow == nil then
                local yInc = rendered:height() - orgLines
                local currentI = startI
                while currentI < i do
                    local node = ast.nodes[currentI]
                    if type(node) == "string" then
                        goto continue
                    end
                    node:_increaseTopBound(yInc)
                    ::continue::
                    currentI = currentI + 1
                end
            end
            if overflow ~= nil then
                if extra == nil then
                    extra = currentLine
                else
                    extra:appendBoxBelow(currentLine, false)
                end
                currentLine = overflow
            end

            if tag.formatType == M.FormatType.Block or tag.formatType == M.FormatType.BlockInline then
                i = i + 1
                break
            end

            hasElements = true
        end
        i = i + 1
    end
    if extra ~= nil then
        extra:appendBoxBelow(currentLine, false)
        currentLine = extra
    end
    return currentLine, i
end

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
    setmetatable(tag, { __index = TagInfo })
    return tag
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
    assert(ok,
        "Error while trying to load tag '" .. name .. "'")
    return mgr
end

return M
