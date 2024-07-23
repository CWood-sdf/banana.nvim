---@module 'banana.utils.debug_flame'
local flame = require('banana.lazyRequire')('banana.utils.debug_flame')
---@module 'banana.utils.log'
local log = require('banana.lazyRequire')('banana.utils.log')
local M = {}
---@module 'banana.utils.string'
local _str = require('banana.lazyRequire')('banana.utils.string')
-- ---@module 'banana.utils.case'
-- local case = require('banana.lazyRequire')('banana.utils.case')
---@module 'banana.utils.dbg'
local dbg = require('banana.lazyRequire')('banana.utils.dbg')
---@module 'banana.nml.ast'
local _ast = require('banana.lazyRequire')('banana.nml.ast')
---@module 'banana.box'
local b = require('banana.lazyRequire')('banana.box')
-- ---@module 'banana.nml.render.partialRendered'
-- local p = require('banana.lazyRequire')('banana.nml.render.partialRendered')

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

---@alias Banana.Renderer fun(self: Banana.TagInfo, ast: Banana.Ast, parentHl: Banana.Highlight?, parentWidth: number, parentHeight: number, startX: number, startY: number, inherit: Banana.Renderer.InheritedProperties, extra: Banana.Renderer.ExtraInfo): Banana.RenderRet


---@class (exact) Banana.TagInfo
---@field name string
---@field formatType Banana.Nml.FormatType
---@field selfClosing boolean
---@field initialProps Banana.Renderer.InitialProperties
---@field render Banana.Renderer
local TagInfo = {
    name = '',
    formatType = M.FormatType.Inline,
    selfClosing = false,
    render = function(_) return {} end,
}



---@param ast Banana.Ast
---@param startHl Banana.Highlight?
---@param winWidth number
---@param winHeight number
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return Banana.Box
function TagInfo:renderRoot(ast, startHl, winWidth, winHeight, inherit, extra)
    flame.new("element render")
    local ret = self:render(ast, startHl, winWidth, winHeight, 1, 1, inherit, extra)
    flame.pop()
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
    log.trace("TagInfo:getRendered " .. ast.tag .. "#" .. (ast:getAttribute('id') or ""))
    flame.new("getRendered start")
    local ret = require('banana.nml.render.main')(
        self, ast, parentHl, parentWidth, parentHeight, startX, startY, inherit,
        extra)
    flame.pop()
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
    local ret, _ = self:renderBlock(ast, ast:_mixHl(parentHl), 1, parentWidth, parentHeight, startX, startY, inherit,
        extra)
    return ret
end

---@param targetWidth number
---@param box Banana.Box
---@param hl Banana.Highlight?
---@return Banana.Box, Banana.Box
local function splitLineBoxOnce(targetWidth, box, hl)
    flame.new("splitLineBoxOnce")
    if targetWidth < 1 then
        targetWidth = 1
    end
    if box:width() < targetWidth then
        flame.pop()
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
    flame.pop()
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
    flame.new("handleOverflow")
    -- if currentLine:height() == 0 then
    --     currentLine:appendStr("", nil)
    -- end
    if currentLine:width() + append:width() <= maxWidth then
        currentLine:append(append, nil)
        flame.pop()
        return currentLine, nil
    end
    if append:height() ~= 1 or not breakable(ast.nodes[i]) then
        flame.pop()
        return currentLine, append
    end
    if currentLine:height() > 1 then
        local ap, extra = splitLineBoxOnce(maxWidth - currentLine:width(), append, hl)
        currentLine:append(ap, nil)
        flame.pop()
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
    flame.pop()
    return preStuff, extra
end


---@param ast Banana.Ast
---@return boolean
local function hasNoFrUnits(ast)
    for _, nodes in pairs(ast.style) do
        for _, v in ipairs(nodes) do
            if v.type == "unit" and v.value.unit == "fr" then
                if not ast:hasStyle("width") then
                    log.assert(false, "an ast with fractional units must have a width/height")
                    error("")
                end
                if ast:firstStyleValue("width").unit ~= "fr" then
                    log.assert(false,
                        "an ast with fractional units must have a width/height with unit fr")
                    error("")
                end
                return false
            end
        end
    end
    return true
end

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

-- Grid todo:
-- repeat()
-- grid-template-columns
-- grid-template-rows
-- grid-template-areas
-- grid-template (shorthand prop)
-- grid-auto-columns
-- grid-auto-rows
-- grid-auto-flow
-- grid
-- grid-row-start
-- grid-column-start
-- grid-row-end
-- grid-column-end
-- grid-row
-- grid-column
-- grid-area
-- row-gap
-- column-gap
-- gap

---@param ast Banana.Ast
---@param parentHl Banana.Highlight?
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return Banana.Box, integer
function TagInfo:renderGridBlock(ast, parentHl, parentWidth, parentHeight, startX, startY, inherit, extra)
    -- TODO: Everything

    -- so the plan sorta is basically make a grid of boxes that can be dynamically updated
    -- (ie for auto els), then once initial box has been made, just determine where each box is
    -- then fill it in
    return b.Box:new(), #ast.nodes + 1
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
    log.trace("TagInfo:renderFlexBlock " .. ast.tag)
    flame.new("renderFlexBlock")
    -- possible todos:
    --   abstract out base rendering into a function
    --   inline the current height / line calculation
    --   maybe some other stuff
    local oldMinSize = inherit.min_size
    inherit.min_size = true
    local takenWidth = 0
    local hl = ast:_mixHl(parentHl)
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

        v:_resolveUnits(parentWidth, parentHeight)
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
        extra.trace:appendBoxBelow(dbg.traceBreak("flex w/o fr"), false)
        extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
        for i, v in ipairs(renders) do
            if v ~= nil then
                extra.trace:appendBoxBelow(dbg.traceBreak(i .. ""), false)
                extra.trace:appendBoxBelow(v[1]:render(true), false)
            else
                extra.trace:appendBoxBelow(dbg.traceBreak(i .. ""), false)
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
        v:_resolveUnits(parentWidth, parentHeight, {
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
        v:_resolveUnits(parentWidth, parentHeight, {
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
        extra.trace:appendBoxBelow(dbg.traceBreak("flex w/ fr"), false)
        extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
        for i, v in ipairs(renders) do
            extra.trace:appendBoxBelow(dbg.traceBreak(i .. ""), false)
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
        extra.trace:appendBoxBelow(dbg.traceBreak("flex-grow"), false)
        extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
        for i, v in ipairs(renders) do
            if v ~= nil then
                extra.trace:appendBoxBelow(dbg.traceBreak(i .. ""), false)
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
        extra.trace:appendBoxBelow(dbg.traceBreak("Wrapping into " .. #lines .. " lines"), false)
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

    flame.pop()
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
    log.trace("TagInfo:renderBlock " .. ast.tag)
    flame.new("renderBlock")
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
            flame.new("renderBlock_primaryRender")
            local tag = v.actualTag
            if (tag.formatType == M.FormatType.Block or tag.formatType == M.FormatType.BlockInline) and hasElements then
                flame.pop()
                break
            end
            v:_resolveUnits(width, height)
            flame.pop()
            flame.new("renderBlock_primaryRender3")
            local rendered = tag:getRendered(v, parentHl, width, height, startX, startY, inherit, extra_):render()
            flame.pop()
            flame.new("renderBlock_primaryRender2")
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
            flame.pop()

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
    flame.pop()
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
    if not ok then
        log.assert(false,
            "Error while trying to load tag '" .. name .. "'")
        error("")
    end
    return mgr
end

return M
