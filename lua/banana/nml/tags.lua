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
---@field marginColor Banana.Highlight
---@field mainColor Banana.Highlight
---@field renderingLeft boolean
local PartialRendered = {}

---@return Banana.Renderer.PartialRendered
local function emptyPartialRendered()
    ---@type Banana.Renderer.PartialRendered
    local ret = {
        renderingLeft = false,
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
    local topBox = b.Box:new(color)
    topBox:appendStr('', nil)
    topBox:expandWidthTo(box:width())
    topBox:cloneHeightTo(pad.top)
    topBox:appendBoxBelow(box)
    box = topBox
    local btmBox = b.Box:new(color)
    btmBox:appendStr('', nil)
    btmBox:expandWidthTo(box:width())
    btmBox:cloneHeightTo(pad.bottom)
    btmBox:appendBoxBelow(box)
    box:appendBoxBelow(btmBox)
    local leftBox = b.Box:new(color)
    leftBox:appendStr('', nil)
    leftBox:expandWidthTo(pad.left)
    leftBox:cloneHeightTo(box:height())
    leftBox:append(box)
    box = leftBox
    local rightBox = b.Box:new(color)
    rightBox:appendStr('', nil)
    rightBox:expandWidthTo(pad.right)
    rightBox:cloneHeightTo(box:height())
    box:append(rightBox)
    return box
end

---@return Banana.Box
function PartialRendered:render()
    local box = self.center
    local btmBox = b.Box:new(self.mainColor)
    btmBox:appendStr('', nil)
    btmBox:expandWidthTo(box:width())
    btmBox:cloneHeightTo(self.heightExpansion)
    btmBox:appendBoxBelow(box)
    box:appendBoxBelow(btmBox)
    local left = b.Box:new(self.mainColor)
    left:appendStr('', nil)
    left:expandWidthTo(self.widthExpansion)
    left:cloneHeightTo(box:height())
    if self.renderingLeft then
        left:append(box)
        box = left
    else
        box:append(left)
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

---@class (exact) Banana.Renderer.InitialProperties: Banana.Renderer.InheritedProperties

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

---@param ast Banana.Ast
---@param name string
---@param i number
---@param hl Banana.Highlight?
---@param lines number
---@return Banana.Box
local function padLeftRight(ast, name, i, hl, lines)
    local ret = b.Box:new(hl);
    ret:appendStr(' ', nil)
    ret:expandWidthTo(ast[name][i].value)
    ret:cloneHeightTo(lines)
    return ret
end

---@param ast Banana.Ast
---@param name string
---@param i number
---@param hl Banana.Highlight?
---@param width number
---@return Banana.Box
local function padTopBtm(ast, name, i, hl, width)
    local box = b.Box:new(hl);
    box:appendStr(' ', nil)
    box:expandWidthTo(width)
    box:cloneHeightTo(ast[name][i].value)
    return box
end

---@param name string
---@param ast Banana.Ast
---@param ret Banana.Box
---@param hl Banana.Highlight?
---@return Banana.Box, boolean
local function applyPad(name, ast, ret, hl)
    local changed = false
    if ast[name][_ast.left].value ~= 0 then
        local box = padLeftRight(ast, name, _ast.left, hl, ret:height())
        box:append(ret, nil)
        ret = box
        changed = true
    end
    if ast[name][_ast.right].value ~= 0 then
        local box = padLeftRight(ast, name, _ast.right, hl, ret:height())
        ret:append(box, nil)
        changed = true
    end
    if ast[name][_ast.top].value ~= 0 then
        local box = padTopBtm(ast, name, _ast.top, hl, ret:width())
        box:appendBoxBelow(ret)
        ret = box
        changed = true
    end
    if ast[name][_ast.bottom].value ~= 0 then
        local box = padTopBtm(ast, name, _ast.top, hl, ret:width())
        ret:appendBoxBelow(box)
        changed = true
    end
    return ret, changed
end

---@param ast Banana.Ast
---@param extraWidth number
---@return boolean
local function isExpandable(ast, extraWidth)
    local isFlexChild = ast._parent ~= nil and ast._parent.style ~= nil and ast._parent.style['display'] == "flex"
    if isFlexChild then
        return extraWidth > 0 and
            (ast.actualTag.formatType == M.FormatType.Block or ast.actualTag.formatType == M.FormatType.BlockInline) and
            ast.style.width ~= nil
    end

    return (ast.actualTag.formatType == M.FormatType.Block or ast.actualTag.formatType == M.FormatType.BlockInline
        ) and extraWidth > 0
        or ast.style['width'] ~= nil
end

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
        if ast.style[style] ~= nil then
            inheritOld[k] = inherit[k]
            inherit[k] = ast.style[style][1].value
            if inherit[k] == "initial" then
                inherit[k] = ast:_getInitialStyles()[style]
            end
        end
    end
    local position = (ast.style.position or { {} })[1].value
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
    local d = "display"
    local disp = ast.style[d]
    if disp ~= nil and disp[1] ~= nil and disp[1].value == "hidden" then
        for k, _ in pairs(inheritOld) do
            inherit[k] = inheritOld[k]
        end

        return emptyPartialRendered()
    end
    if ast.style['width'] ~= nil then
        ---@diagnostic disable-next-line: cast-local-type
        parentWidth = math.min(
            ast.style['width'][1].value.computed + ast.margin[_ast.left].value + ast.margin[_ast.right].value,
            parentWidth)
    end
    if ast.style['height'] ~= nil then
        ---@diagnostic disable-next-line: cast-local-type
        parentHeight = math.min(
            ast.style['height'][1].value.computed + ast.margin[_ast.top].value + ast.margin[_ast.bottom].value,
            parentHeight)
    end
    if position ~= "static" then
        if ast.style.left ~= nil then
            startX = startX + ast.style.left[1].value.computed
        elseif ast.style.right ~= nil then
            startX = startX - ast.style.right[1].value.computed
        end
        if ast.style.top ~= nil then
            startY = startY + ast.style.top[1].value.computed
        elseif ast.style.bottom ~= nil then
            startY = startY - ast.style.bottom[1].value.computed
        end
    end
    startX = startX + ast.margin[_ast.left].value
    startY = startY + ast.margin[_ast.top].value
    ---@type Banana.Ast.BoundingBox
    local boundBox = {
        leftX   = startX,
        topY    = startY,
        rightX  = 0,
        bottomY = 0,
    }
    startX = startX + ast.padding[_ast.left].value
    startY = startY + ast.padding[_ast.top].value
    ---@cast parentWidth number
    ---@cast parentHeight number
    local centerBox = self:render(ast, parentHl, parentWidth, parentHeight, startX, startY, inherit, extra)
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
        extra.trace:appendBoxBelow(traceBreak("Raw render"))
        extra.trace:appendBoxBelow(ast:_testDumpBox())
        extra.trace:appendBoxBelow(centerBox)
    end
    local extraWidth =
        parentWidth - ret:width() -
        ast.padding[_ast.left].value - ast.padding[_ast.right].value -
        ast.margin[_ast.left].value - ast.margin[_ast.right].value
    if isExpandable(ast, extraWidth) then
        local width = parentWidth - ast.padding[_ast.left].value
            - ast.padding[_ast.right].value - ast.margin[_ast.left].value
            - ast.margin[_ast.right].value
        if inherit.text_align == "left" then
            ret:expandWidthTo(width)
        elseif inherit.text_align == "right" then
            local prepend = require('banana.box').Box:new(ret.hlgroup)
            prepend:appendStr('', nil)
            prepend:expandWidthTo(extraWidth)
            prepend:append(ret)
            ret = prepend
        elseif inherit.text_align == "center" then
            local leftWidth = math.floor(extraWidth / 2)
            local left = require('banana.box').Box:new(ret.hlgroup)
            left:appendStr('', nil)
            left:expandWidthTo(leftWidth)
            left:clean()
            left:append(ret)
            left:expandWidthTo(width)
            ret = left
        end
        ret:clean()
        if extra.debug then
            extra.trace:appendBoxBelow(traceBreak("Expansion w"))
            extra.trace:appendBoxBelow(ast:_testDumpBox())
            extra.trace:appendBoxBelow(ret)
        end
    end
    if ast.style['height'] ~= nil and not ast:parent():isNil() then
        local height = ast.style['height'][1].value.computed - ast.padding[_ast.top].value -
            ast.padding[_ast.bottom].value
        ---@cast height number
        local above = b.Box:new(ret.hlgroup)
        above:appendStr(' ')
        above:expandWidthTo(ret:width())
        if ret:height() >= height then
            goto skip
        end
        above:cloneHeightTo(height - ret:height())
        ret:appendBoxBelow(above)
        if extra.debug then
            extra.trace:appendBoxBelow(traceBreak("Expansion h"))
            extra.trace:appendBoxBelow(ast:_testDumpBox())
            extra.trace:appendBoxBelow(ret)
        end
        ::skip::
    end
    local changed = false
    ret, changed = applyPad('padding', ast, ret, ret.hlgroup)
    if changed then
        if extra.debug then
            extra.trace:appendBoxBelow(traceBreak("pad"))
            extra.trace:appendBoxBelow(ast:_testDumpBox())
            extra.trace:appendBoxBelow(ret)
        end
    end
    boundBox.rightX = boundBox.leftX + ret:width()
    boundBox.bottomY = boundBox.topY + ret:height()
    ast.boundBox = boundBox
    if position == "static" then
    else
        local newRet = b.Box:new(parentHl)
        while newRet:height() < ret:height() do
            local newBox = b.Box:new(newRet.hlgroup)
            newBox:appendStr(string.rep(' ', ret:width()))
            newRet:appendBoxBelow(newBox)
        end
        newRet:clean()
        local root = ast
        while root.relativeBoxes == nil do
            root = root._parent
        end
        table.insert(root.relativeBoxes, {
            box = ret,
            left = startX - 1 - ast.padding[_ast.left].value,
            top = startY - 1 - ast.padding[_ast.top].value,
            z = (ast.style['z-index'] or { {} })[1].value or 0
        })
        ast.relativeBoxId = #root.relativeBoxes
        ret = newRet
        if ast.style.left ~= nil then
            startX = startX - ast.style.left[1].value.computed
        elseif ast.style.right ~= nil then
            startX = startX + ast.style.right[1].value.computed
        end
        if ast.style.top ~= nil then
            startY = startY - ast.style.top[1].value.computed
        elseif ast.style.bottom ~= nil then
            startY = startY + ast.style.bottom[1].value.computed
        end
    end
    ret, changed = applyPad('margin', ast, ret, parentHl)
    if changed then
        if extra.debug then
            extra.trace:appendBoxBelow(traceBreak("margin"))
            extra.trace:appendBoxBelow(ast:_testDumpBox())
            extra.trace:appendBoxBelow(ret)
        end
    end
    if ast.absoluteAsts ~= nil then
        for _, v in ipairs(ast.absoluteAsts) do
            v:resolveUnits(parentWidth, parentHeight)
            v.style.position[1].value = "relative"
            v.actualTag:getRendered(
                v, ret.hlgroup, parentWidth, parentHeight, startX, startY, inherit,
                extra)
            v.style.position[1].value = "absolute"
        end
    end
    if ast.relativeBoxes ~= nil then
        table.sort(ast.relativeBoxes, function(l, r)
            return l.z < r.z
        end)
        for _, data in ipairs(ast.relativeBoxes) do
            ret:renderOver(data.box, data.left, data.top)
        end
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
        if ast.style.display ~= nil and ast.style["display"][1].value == "flex" then
            error("impl flex")
            -- render = self:renderFlexBlock(
            --     ast, parentHl, parentWidth, parentHeight,
            --     startX, startY, inherit, extra)
            -- i = #ast.nodes + 1
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
---@return Banana.Box, Banana.Box
local function splitLineBoxOnce(targetWidth, box)
    if box:width() < targetWidth then
        return box, b.Box:new(box.hlgroup)
    end
    local left = b.Box:new(box.hlgroup)
    left:appendStr("", nil)
    local right = b.Box:new(box.hlgroup)
    right:appendStr("", nil)
    local i = 1
    while left:width() + _str.charCount(box:getLine(1)[i].word) < targetWidth do
        left:appendWord(box:getLine(1)[i])
        i = i + 1
    end
    local word = box:getLine(1)[i]
    local leftIns = _str.sub(word.word, 1, targetWidth - left:width())
    --Allow unsafe #word.word, bc #word.word is always >= str.charCount(word.word)
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
    return ast.padding[_ast.right].value == 0 and ast.padding[_ast.left].value == 0 and ast.style.width == nil
end


---@param ast Banana.Ast
---@param i number
---@param currentLine Banana.Box
---@param append Banana.Box
---@param maxWidth number
---@return Banana.Box, Banana.Box?
local function handleOverflow(ast, i, currentLine, append, maxWidth)
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
        local ap, extra = splitLineBoxOnce(maxWidth - currentLine:width(), append)
        currentLine:append(ap, nil)
        return currentLine, extra
    end
    currentLine:append(append, nil)
    local preStuff = b.Box:new(currentLine.hlgroup)
    local extra = nil
    repeat
        currentLine, extra = splitLineBoxOnce(maxWidth, currentLine)
        preStuff:appendBoxBelow(currentLine)
        currentLine = extra
    until extra:width() <= maxWidth
    return preStuff, extra
end

-- also need to make default box renderSide loc top, not bottom
-- Flex todo:
-- Render the boxes
-- Finish partial renderer proto (inside the getRendered fn)
-- render boxes that dont have fr
-- calc remaining display width
-- render boxes with fr
-- redo box height
-- recalc remaining
-- impl flex basis
-- impl flex grow
-- impl flex shrink
-- impl emergency deflex
-- impl double emergency float rendering

---Renders everything in a flex block
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
function TagInfo:renderFlexBlock(ast, parentHl, i, parentWidth, parentHeight, startX, startY, inherit, extra_)
    local width = 0
    error("Not implemented")
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
    local width = parentWidth - ast:_extraLr()
    local height = parentHeight - ast:_extraTb()
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
            local count = _str.charCount(v)
            local box = b.Box:new(currentLine.hlgroup)
            box:appendStr(v, nil)
            local overflow = nil
            currentLine, overflow = handleOverflow(ast, i, currentLine, box, width)
            if overflow ~= nil then
                if extra == nil then
                    extra = currentLine
                else
                    extra:appendBoxBelow(currentLine)
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
            local rendered = tag:getRendered(v, parentHl, width, height, startX, startY, inherit, extra_)
            startX = startX + rendered:width()
            local overflow = nil
            local orgLines = currentLine:height()
            currentLine, overflow = handleOverflow(ast, i, currentLine, rendered, width)
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
                    extra:appendBoxBelow(currentLine)
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
        extra:appendBoxBelow(currentLine)
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
