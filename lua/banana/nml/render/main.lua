---@module 'banana.nml.render.partialRendered'
local p = require('banana.lazyRequire')('banana.nml.render.partialRendered')
---@module 'banana.box'
local b = require('banana.lazyRequire')('banana.box')
---@module 'banana.utils.case'
local case = require('banana.lazyRequire')('banana.utils.case')
---@module 'banana.utils.debug_flame'
local flame = require('banana.lazyRequire')('banana.utils.debug_flame')

---@module 'banana.utils.debug'
local dbg = require('banana.lazyRequire')('banana.utils.debug')

---@module 'banana.nml.render'
local _render = require('banana.lazyRequire')('banana.nml.render')

---@param ast Banana.Ast
---@param extraWidth number
---@return boolean
local function isExpandable(ast, extraWidth)
    local isFlexChild = ast._parent ~= nil and ast._parent:firstStyleValue('display') == "flex"
    if isFlexChild then
        return extraWidth > 0 and
            (ast.actualTag.formatType == _render.FormatType.Block or ast.actualTag.formatType == _render.FormatType.BlockInline) and
            (ast:hasStyle('width') or ast:hasStyle("flex-basis"))
    end

    return (ast.actualTag.formatType == _render.FormatType.Block or ast.actualTag.formatType == _render.FormatType.BlockInline
        ) and extraWidth > 0
        or ast:hasStyle('width')
end
---@param self Banana.TagInfo
---@param ast Banana.Ast
---@param parentHl Banana.Highlight?
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return Banana.Renderer.PartialRendered
return function(self, ast, parentHl, parentWidth, parentHeight, startX, startY, inherit, extra)
    flame.new("getRendered_start")
    ast.relativeBoxId = nil
    local inheritOld = {}
    for k, _ in pairs(inherit) do
        local style = case.snakeToKebab(k)
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
        flame.pop()
        return p.emptyPartialRendered()
    end
    local disp = ast:firstStyleValue("display")
    if disp == "none" then
        for k, _ in pairs(inheritOld) do
            inherit[k] = inheritOld[k]
        end
        flame.pop()
        return p.emptyPartialRendered()
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
    ---@cast parentWidth number
    ---@cast parentHeight number
    flame.pop()
    flame.new("element render")
    local centerBox = self:render(ast, parentHl, contentWidth, parentHeight, startX, startY, inherit, extra)
    -- flame.expect("element render")
    flame.pop()
    flame.new("getRendered_expansion")
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
        extra.trace:appendBoxBelow(dbg.traceBreak("Raw render"), false)
        extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
        extra.trace:appendBoxBelow(centerBox:clone(), false)
    end
    ---@type Banana.Renderer.PartialRendered
    local ret = p.emptyPartialRendered()
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
            extra.trace:appendBoxBelow(dbg.traceBreak("Expansion w"), false)
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
            extra.trace:appendBoxBelow(dbg.traceBreak("Expansion h"), false)
            extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
            extra.trace:appendBoxBelow(ret:render(true), false)
        end
    end
    flame.pop()
    flame.new("getRendered_pad")
    local changed = false
    changed = ret:applyPad('padding', ast)
    if changed then
        if extra.debug then
            extra.trace:appendBoxBelow(dbg.traceBreak("pad"), false)
            extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
            extra.trace:appendBoxBelow(ret:render(true), false)
        end
    end
    boundBox.rightX = boundBox.leftX + ret:getWidth()
    boundBox.bottomY = boundBox.topY + ret:getHeight()
    ast.boundBox = boundBox
    if position ~= "static" then
        flame.pop()
        flame.new("getRendered_relative")
        local newRet = b.Box:new(parentHl)
        local render = ret:render()
        while newRet:height() < render:height() do
            local newBox = b.Box:new(newRet.hlgroup)
            newBox:appendStr(string.rep(' ', render:width()))
            newRet:appendBoxBelow(newBox)
        end
        if extra.debug then
            extra.trace:appendBoxBelow(dbg.traceBreak("float render"), false)
            extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
            extra.trace:appendBoxBelow(render:clone(), false)
            extra.trace:appendBoxBelow(dbg.traceBreak("extraRender render"), false)
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
            extra.trace:appendBoxBelow(dbg.traceBreak("new render"), false)
            extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
            extra.trace:appendBoxBelow(ret:render(true), false)
        end
    end
    flame.pop()
    flame.new("getRendered_margin")
    changed = ret:applyPad('margin', ast)
    if changed then
        if extra.debug then
            extra.trace:appendBoxBelow(dbg.traceBreak("margin"), false)
            extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
            extra.trace:appendBoxBelow(ret:render(true), false)
        end
    end
    if ast.absoluteAsts ~= nil then
        flame.pop()
        flame.new("getRendered_abs")
        for _, v in ipairs(ast.absoluteAsts) do
            v:_resolveUnits(parentWidth, parentHeight)
            v.style.position[1].value = "relative"
            v.actualTag:getRendered(
                v, ret.mainColor, parentWidth, parentHeight, startX, startY, inherit,
                extra)
            v.style.position[1].value = "absolute"
        end
    end
    if ast.relativeBoxes ~= nil then
        flame.pop()
        flame.new("getRendered_rel")
        table.sort(ast.relativeBoxes, function(l, r)
            return l.z < r.z
        end)
        flame.new("element render")
        local rendered = ret:render()
        -- flame.expect("element render")
        flame.pop()
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
    flame.pop()
    return ret
end
