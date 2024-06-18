local M = {}
local _str = require('banana.utils.string')
local _ast = require('banana.nml.ast')

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
---@return Banana.Box
local function padLeftRight(ast, name, i, hl)
    local b = require('banana.box')
    local box = b.Box:new(hl);
    box:appendStr(' ', nil)
    box:expandWidthTo(ast[name][i].value)
    return box
end

---@param ast Banana.Ast
---@param name string
---@param i number
---@param hl Banana.Highlight?
---@param width number
---@return Banana.Box
local function padTopBtm(ast, name, i, hl, width)
    local b = require('banana.box')
    local box = b.Box:new(hl);
    box:appendStr(' ', nil)
    box:expandWidthTo(width)
    while #box.lines < ast[name][i].value do
        table.insert(box.lines, box.lines[1])
    end
    return box
end

---@param name string
---@param ast Banana.Ast
---@param ret Banana.Box
---@param hl Banana.Highlight?
---@return Banana.Box
local function applyPad(name, ast, ret, hl)
    local b = require('banana.box')
    if ast[name][_ast.left].value ~= 0 then
        local box = padLeftRight(ast, name, _ast.left, hl)
        box:append(ret, nil)
        ret = box
    end
    if ast[name][_ast.right].value ~= 0 then
        local box = padLeftRight(ast, name, _ast.right, hl)
        ret:append(box, nil)
    end
    if ast[name][_ast.top].value ~= 0 then
        local box = padTopBtm(ast, name, _ast.top, hl, b.lineWidth(ret.lines[1]))
        box:appendBoxBelow(ret)
        ret = box
    end
    if ast[name][_ast.bottom].value ~= 0 then
        local box = padTopBtm(ast, name, _ast.top, hl, b.lineWidth(ret.lines[1]))
        ret:appendBoxBelow(box)
    end
    return ret
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
---@return Banana.RenderRet
function TagInfo:getRendered(ast, parentHl, parentWidth, parentHeight, startX, startY, inherit, extra)
    local b = require('banana.box')
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
        return b.Box:new()
    end
    local d = "display"
    local disp = ast.style[d]
    if disp ~= nil and disp[1] ~= nil and disp[1].value == "hidden" then
        for k, _ in pairs(inheritOld) do
            inherit[k] = inheritOld[k]
        end

        return b.Box:new(nil)
    end
    if ast.style['width'] ~= nil then
        ---@diagnostic disable-next-line: cast-local-type
        parentWidth = math.min(ast.style['width'][1].value.computed, parentWidth)
    end
    if ast.style['height'] ~= nil then
        ---@diagnostic disable-next-line: cast-local-type
        parentHeight = math.min(ast.style['height'][1].value.computed, parentHeight)
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
    ---@type Banana.Ast.BoundingBox
    local boundBox = {
        leftX   = startX,
        topY    = startY,
        rightX  = 0,
        bottomY = 0,
    }
    startX = startX + ast.padding[_ast.left].value + ast.margin[_ast.left].value
    startY = startY + ast.padding[_ast.top].value + ast.margin[_ast.top].value
    ---@cast parentWidth number
    ---@cast parentHeight number
    local ret = self:render(ast, parentHl, parentWidth, parentHeight, startX, startY, inherit, extra)
    local extraWidth =
        parentWidth - ret.width -
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
    end
    if ast.style['height'] ~= nil and not ast:parent():isNil() then
        local height = ast.style['height'][1].value.computed
        ---@cast height number
        local above = require('banana.box').Box:new(ret.hlgroup)
        above:appendStr(' ')
        above:expandWidthTo(ret.width)
        if #ret.lines >= height then
            goto skip
        end
        while #ret.lines + #above.lines < height do
            table.insert(above.lines, above.lines[1])
        end
        above:appendBoxBelow(ret)
        ret = above

        ::skip::
    end
    ret = applyPad('padding', ast, ret, ret.hlgroup)
    boundBox.rightX = boundBox.leftX + ret.width
    boundBox.bottomY = boundBox.topY + #ret.lines
    ast.boundBox = boundBox
    if position == "static" then
    else
        local newRet = b.Box:new(parentHl)
        while #newRet.lines < #ret.lines do
            local newBox = b.Box:new(newRet.hlgroup)
            newBox:appendStr(string.rep(' ', ret.width))
            newRet:appendBoxBelow(newBox)
        end
        newRet:clean()
        local root = ast
        while root.relativeBoxes == nil do
            root = root._parent
        end
        table.insert(root.relativeBoxes, {
            box = ret,
            left = startX - 1,
            top = startY - 1,
            z = (ast.style['z-index'] or { {} })[1].value or 0
        })
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
    ret = applyPad('margin', ast, ret, parentHl)
    if ast.absoluteAsts ~= nil then
        for _, v in ipairs(ast.absoluteAsts) do
            v:resolveUnits(parentWidth, parentHeight)
            v.style.position[1].value = "relative"
            v.actualTag:getRendered(
                v, ret.hlgroup, parentWidth, parentHeight, startX, startY, inherit,
                {})
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
        startY = startY + #render.lines
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
    --FIX: spans dont know how many chars will overflow, so they just render as if they wont
    --then when overflow happens its like shoot the span overflowed, i'll just appendBelow() badd
    -- NEEDS FLOAT
    local b = require('banana.box')
    local currentLine = b.Box:new(parentHl)
    local hasText = false
    local width = parentWidth
        - ast.padding[_ast.left].value - ast.padding[_ast.right].value
        - ast.margin[_ast.left].value - ast.margin[_ast.right].value
    local height = parentHeight
        - ast.padding[_ast.top].value - ast.padding[_ast.bottom].value
        - ast.margin[_ast.top].value - ast.margin[_ast.bottom].value
    ---@type Banana.Box?
    local extra = nil
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
            if count + currentLine.width > width then
                local remove = 1
                local j = count - remove
                local repLim = 1000
                while count + currentLine.width - remove > width do
                    remove = remove + 1
                    j = count - remove
                    while v:sub(j, j) ~= ' ' and j > 0 do
                        remove = remove + 1
                        j = count - remove
                    end
                    if repLim < 0 then
                        vim.notify("Reached repeat limit on string '" .. v .. "'")
                        break
                    end
                    repLim = repLim - 1
                end
                if j <= 0 then
                    remove = count + currentLine.width - width
                    j = count - remove
                end
                local str = v:sub(1, j)
                currentLine:appendStr(str, b.MergeStrategy.Bottom)
                if extra == nil then
                    extra = currentLine
                else
                    extra:appendBoxBelow(currentLine)
                end
                currentLine = b.Box:new(currentLine.hlgroup)
                v = v:sub(j + 1, count)
                startX = 0
            end
            currentLine:appendStr(v, b.MergeStrategy.Bottom)
            startX = startX + count
            hasText = true
        else
            local tag = M.makeTag(v.tag)
            if (tag.formatType == M.FormatType.Block or tag.formatType == M.FormatType.BlockInline) and hasText then
                break
            end
            v:resolveUnits(width, height)
            local rendered = tag:getRendered(v, currentLine.hlgroup, width, height, startX, startY, inherit, extra_)
            startX = startX + rendered.width
            if currentLine.width + rendered.width > width then
                if extra == nil then
                    extra = currentLine
                else
                    extra:appendBoxBelow(currentLine)
                end
                currentLine = b.Box:new(currentLine.hlgroup)
            end
            currentLine:append(rendered, b.MergeStrategy.Bottom)
            if tag.formatType == M.FormatType.Block or tag.formatType == M.FormatType.BlockInline then
                i = i + 1
                break
            end

            hasText = true
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
