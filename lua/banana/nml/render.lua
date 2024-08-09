---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
local M = {}
---@module 'banana.utils.string'
local _str = require("banana.lazyRequire")("banana.utils.string")
-- ---@module 'banana.utils.case'
-- local case = require('banana.lazyRequire')('banana.utils.case')
---@module 'banana.utils.debug'
local dbg = require("banana.lazyRequire")("banana.utils.debug")
---@module 'banana.nml.ast'
local _ast = require("banana.lazyRequire")("banana.nml.ast")
---@module 'banana.box'
local b = require("banana.lazyRequire")("banana.box")
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
---@field useAllHeight boolean
---@field isRealRender boolean

---@alias Banana.Renderer fun(self: Banana.TagInfo, ast: Banana.Ast, parentHl: Banana.Highlight?, parentWidth: number, parentHeight: number, startX: number, startY: number, inherit: Banana.Renderer.InheritedProperties, extra: Banana.Renderer.ExtraInfo): Banana.RenderRet


---@class (exact) Banana.TagInfo
---@field name string
---@field formatType Banana.Nml.FormatType
---@field selfClosing boolean
---@field initialProps Banana.Renderer.InitialProperties
---@field render Banana.Renderer
local TagInfo = {
    name = "",
    formatType = M.FormatType.Inline,
    selfClosing = false,
    render = function (_) return {} end,
}



---@param ast Banana.Ast
---@param startHl Banana.Highlight?
---@param winWidth number
---@param winHeight number
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return Banana.Box
function TagInfo:renderRoot(ast, startHl, winWidth, winHeight, inherit, extra)
    flame.new("renderRoot")
    log.trace("TagInfo:renderRoot")
    local ret = self:render(ast, startHl, winWidth, winHeight, 1, 1, inherit,
        extra)
    -- flame.expect("renderRoot")
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
function TagInfo:getRendered(ast, parentHl, parentWidth, parentHeight, startX,
                             startY, inherit, extra)
    log.trace("TagInfo:getRendered " ..
        ast.tag .. "#" .. (ast:getAttribute("id") or ""))
    local ret = require("banana.nml.render.main")(
        self, ast, parentHl, parentWidth, parentHeight, startX, startY, inherit,
        extra)
    -- flame.expect("getRendered start")
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
function TagInfo:blockIter(ast, parentHl, parentWidth, parentHeight, startX,
                           startY, inherit, extra)
    local i = 1
    return function ()
        if i > #ast.nodes then
            return nil
        end
        flame.new("TagInfo:blockIter")
        local oldI = i
        local render = nil
        if ast:firstStyleValue("display") == "flex" then
            -- error("impl flex")
            render = self:renderFlexBlock(
                ast, parentHl, parentWidth, parentHeight,
                startX, startY, inherit, extra)
            i = #ast.nodes + 1
        elseif ast:firstStyleValue("display") == "grid" then
            render = self:renderGridBlock(
                ast, parentHl, parentWidth, parentHeight,
                startX, startY, inherit, extra)
            i = #ast.nodes + 1
        else
            render, i = self:renderBlock(
                ast, parentHl, i, parentWidth, parentHeight,
                startX, startY, inherit, extra)
        end
        startY = startY + render:height()
        flame.pop()
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
function TagInfo:renderInlineEl(ast, parentHl, parentWidth, parentHeight, startX,
                                startY, inherit, extra)
    ---@type Banana.Box
    local ret, _ = self:renderBlock(ast, ast:_mixHl(parentHl), 1, parentWidth,
        parentHeight, startX, startY, inherit,
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
    local rightIns = _str.sub(word.word, targetWidth - left:width() + 1,
        #word.word)
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
    return ast:paddingRight() == 0 and ast:paddingLeft() == 0 and
        not ast:hasStyle("width")
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
        local ap, extra = splitLineBoxOnce(maxWidth - currentLine:width(), append,
            hl)
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
                renders[i][1].widthExpansion = renders[i][1].widthExpansion +
                    grow
                renders[i][2]:_increaseWidthBoundBy(grow)
            end
            ::continue::
        end
    end
end

-- Grid todo:
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


---@class (exact) Banana.Renderer.GridTemplate
---@field start number
---@field size number
---@field maxSize number
---@field name string
---@field claimants number[]
---@field prevLink Banana.Renderer.GridTemplate?


---@param templ Banana.Renderer.GridTemplate
---@param fix boolean
---@return number
local function getGridStart(templ, fix)
    if templ.prevLink == nil then
        return templ.start
    else
        local prevSize = templ.prevLink.size
        if prevSize == -1 then
            prevSize = templ.prevLink.maxSize
        end
        local ret = getGridStart(templ.prevLink, fix) + prevSize
        if fix then
            templ.start = ret
            templ.prevLink = nil
        end
        return ret
    end
end

---@param values Banana.Ncss.StyleValue[]
---@param sizeInDirection number
---@param start number
---@param min number
---@param isCol boolean
---@return Banana.Renderer.GridTemplate[]
local function getTemplates(values, sizeInDirection, start, min, isCol)
    ---@type Banana.Renderer.GridTemplate[]
    local ret = {}
    local takenSize = 0
    local totalFrs = 0
    ---@type number[]
    local frs = {}
    local i = 1
    while i <= math.max(min, #values) do
        local v = values[i]
        if v ~= nil then
            local value = v.value
            if value.unit ~= "fr" then
                ---@cast value Banana.Ncss.UnitValue
                local resolve = _ast.calcUnitNoMod(value, sizeInDirection, {})
                ---@type Banana.Renderer.GridTemplate
                local ins = {
                    start = 0,
                    size = resolve.computed,
                    maxSize = resolve.computed,
                    name = i .. "",
                    claimants = {}
                }
                table.insert(ret, ins)
                -- columnOrder[i] = i
                takenSize = takenSize + resolve.computed
            else
                totalFrs = totalFrs + value.value
                table.insert(frs, i)
                table.insert(ret, {})
            end
        elseif isCol then
            totalFrs = totalFrs + 1
            table.insert(frs, i)
            table.insert(ret, {})
        else
        end
        i = i + 1
    end

    local widthPer = math.floor((sizeInDirection - takenSize) / totalFrs)
    if widthPer < 0 then
        widthPer = 0
    end

    local extraWidthNeeded = sizeInDirection - takenSize - totalFrs * widthPer

    for _, j in ipairs(frs) do
        local fr = 0
        local v = values[j]
        if v ~= nil then
            fr = v.value.value
        else
            fr = 1
        end
        local resolve = math.floor(fr * widthPer)
        local extraAdded = math.min(math.ceil(fr), extraWidthNeeded)
        ret[j] = {
            start = 0,
            size = resolve + extraAdded,
            maxSize = resolve + extraAdded,
            name = j .. "",
            claimants = {},
        }
        extraWidthNeeded = extraWidthNeeded - extraAdded
        takenSize = takenSize + resolve
    end
    for _, v in ipairs(ret) do
        v.start = v.start + start
        start = start + v.size
    end
    return ret
end

---@param i number
---@param templates Banana.Renderer.GridTemplate[]
---@param limit number
---@return Banana.Renderer.GridTemplate
local function getSection(i, templates, limit)
    -- flame.new("renderGridBlock_getSection")
    while #templates < i do
        local prev = templates[#templates]
        ---@type Banana.Renderer.GridTemplate
        local templ = {
            start = math.max(prev.size, prev.maxSize) + prev.start,
            size = -1,
            maxSize = 0,
            name = (#templates + 1) .. "",
            claimants = {},
            prevLink = prev
        }
        table.insert(templates, templ)
        if #templates > limit then
            log.fmt_throw("%d grid rows specified, maximum of %d", limit,
                limit)
        end
        -- for _, col in ipairs(takenMatrix) do
        --     table.insert(col, {})
        -- end
    end
    -- flame.pop()
    return templates[i]
end

--- renders an element with display:grid
---@param ast Banana.Ast
---@param parentHl Banana.Highlight?
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return Banana.Box, integer
function TagInfo:renderGridBlock(ast, parentHl, parentWidth, parentHeight, startX,
                                 startY, inherit, extra)
    flame.new("TagInfo:renderGridBlock")
    local hl = ast:_mixHl(parentHl)

    ---@class (exact) Banana.Renderer.CellClaimant
    ---@field render Banana.Renderer.PartialRendered?
    ---@field ast Banana.Ast
    ---@field box Banana.Box?
    ---@field startRow number
    ---@field startCol number

    -- the plan is basically to arrange the grid elements in the places that
    -- they absolutely have to be (eg grid-row or grid-column specified)
    -- ("necessary elements") and determine number of needed implicit columns then render all the elements
    --
    -- and since we already have already determined implicit column, we can just
    -- grab any free spots for elements without grid-row or grid-column

    ---Essentially this is so that we can arrange the children such that we can
    ---do the least amount of resizing
    ---@class Banana.Renderer.GridPreRender
    ---@field ast Banana.Ast
    ---@field priority number based on resizing needed
    ---@field startColumn number
    ---@field startRow number
    ---@field columnSpecified boolean so that things can get demoted to implicit row
    ---@field rowSpecified boolean so that things can get demoted to implicit column

    ---Essentially we want to render things such that resize is minimized
    ---obv anything inside a definite row/col is fine
    ---the index of the table is the i in childIterWithI
    ---@type Banana.Renderer.GridPreRender[]
    local renderOrder = {}

    ---this is the big matrix ("sparse matrix") that we fill with necessary elements
    ---need multiple bc grid elements can overlapped (only if forced to tho)
    ---the asts are used as keys for renderOrder
    ---the numbers are keys to renderOrder
    ---@type number[][][]
    local preRenderTakenMatrix = {}

    local maxRow = 0

    -- NOTE: New notes after some more research
    -- 1. grid-column has equal precedence to nothing
    -- 2. grid-row has more precedence
    -- 3. explicit has most
    -- 4. i think these rules on row vs column invert via grid-auto-flow
    -- 5. frs dont distribute available space, but they are responsive to incorrect sizes (pcts arent)
    -- 6. when grid has height defined, implicit rows have 1fr height unless otherwise said
    -- 7. the placement cursor follows the previous element (aka when grid-column
    -- is defined, then moved to a different place, the cursor doesnt reset)
    -- (this can leave empty spaces in grid)

    -- TODO: So essentially i need two distribution loops
    -- one for explicit/grid-row defs
    -- final for grid-column/none (this is so that defined height can give rows
    -- proper frs)
    -- then a render loop for all

    flame.new("renderGridBlock_placement")
    for i, node in ast:childIterWithI() do
        local row = node:firstStyleValue("grid-row")
        local column = node:firstStyleValue("grid-column")
        ---@cast row number?
        ---@cast column number?
        if row == nil and column == nil then
            goto continue
        end
        -- should we increase stuff in the column direction?
        local incColumn = column == nil
        local incRow = row == nil
        row = row or 1
        column = column or 1
        ---@cast row number
        ---@cast column number
        ---@type Banana.Renderer.GridPreRender
        local preRender = {
            startRow = row,
            startColumn = column,
            columnSpecified = not incColumn,
            rowSpecified = not incRow,
            ast = node,
            priority = 0,
        }
        if node:getTextContent() == "16" then
            print("a")
        end
        renderOrder[i] = preRender
        -- table.insert(renderOrder, preRender)
        -- local id = #renderOrder
        while preRenderTakenMatrix[column] == nil do
            table.insert(preRenderTakenMatrix, {})
        end
        while preRenderTakenMatrix[column][row] == nil do
            table.insert(preRenderTakenMatrix[column], {})
        end
        if incColumn or incRow then
            while #preRenderTakenMatrix[column][row] ~= 0 do
                if incColumn then
                    column = column + 1
                else
                    row = row + 1
                end
                while preRenderTakenMatrix[column] == nil do
                    table.insert(preRenderTakenMatrix, {})
                end
                while preRenderTakenMatrix[column][row] == nil do
                    table.insert(preRenderTakenMatrix[column], {})
                end
            end
        end
        preRender.startRow = row
        preRender.startColumn = column
        maxRow = math.max(maxRow, row)
        if #preRenderTakenMatrix[column][row] ~= 0 then
            -- if there are elements that dont HAVE to be here, then there will only be one
            local key = preRenderTakenMatrix[column][row][1]
            local el = renderOrder[key]
            local freeIndex = nil
            if el.rowSpecified and not el.columnSpecified then
                freeIndex = column
                while #preRenderTakenMatrix[freeIndex][row] ~= 0 do
                    freeIndex = freeIndex + 1
                    if preRenderTakenMatrix[freeIndex] == nil then
                        table.insert(preRenderTakenMatrix, {})
                    end
                    while preRenderTakenMatrix[freeIndex][row] == nil do
                        table.insert(preRenderTakenMatrix[freeIndex], {})
                    end
                end
                local swapIndex = freeIndex
                repeat
                    swapIndex = swapIndex - 1
                    local e = preRenderTakenMatrix[swapIndex][row][1]
                    if not renderOrder[e].columnSpecified and el.rowSpecified then
                        preRenderTakenMatrix[freeIndex][row] = { e }
                        renderOrder[e].startColumn = freeIndex
                        preRenderTakenMatrix[swapIndex][row] = {}
                        freeIndex = swapIndex
                    end
                until swapIndex == column
            elseif el.columnSpecified and not el.rowSpecified then
                freeIndex = row
                while #preRenderTakenMatrix[column][freeIndex] ~= 0 do
                    freeIndex = freeIndex + 1
                    while preRenderTakenMatrix[column][freeIndex] == nil do
                        table.insert(preRenderTakenMatrix[column], {})
                    end
                end
                local swapIndex = freeIndex
                repeat
                    swapIndex = swapIndex - 1
                    local e = preRenderTakenMatrix[column][swapIndex][1]
                    if not renderOrder[e].rowSpecified and el.columnSpecified then
                        preRenderTakenMatrix[column][freeIndex] = { e }
                        renderOrder[e].startRow = freeIndex
                        preRenderTakenMatrix[column][swapIndex] = {}
                        freeIndex = swapIndex
                    end
                until swapIndex == row
            end
        end
        table.insert(preRenderTakenMatrix[column][row], i)
        ::continue::
    end
    flame.pop()

    flame.new("renderGridBlock_makeTemplates")
    ---@type Banana.Renderer.GridTemplate[]
    local columnTemplates = {}
    ---@type Banana.Renderer.GridTemplate[]
    local rowTemplates = {}

    local cols = ast:allStylesFor("grid-template-columns") or {}
    columnTemplates = getTemplates(cols, parentWidth, startX,
        #preRenderTakenMatrix, true)
    local rows = ast:allStylesFor("grid-template-rows") or {}
    rowTemplates = getTemplates(rows, parentHeight, startY, maxRow, false)
    local columnLimit = 5000
    local rowLimit = 10000
    if #columnTemplates > columnLimit then
        log.fmt_throw("%d grid columns specified, maximum of %d", columnLimit,
            rowLimit)
    end
    if #rowTemplates > rowLimit then
        log.fmt_throw("%d grid rows specified, maximum of %d", rowLimit,
            rowLimit)
    end

    if #columnTemplates == 0 then
        ---@type Banana.Renderer.GridTemplate
        local templ = {
            start = startX,
            size = -1,
            maxSize = 0,
            name = "1",
            claimants = {}
        }
        table.insert(columnTemplates, templ)
    end

    if extra.debug then
        local sm = b.Box:new()
        for c, row in ipairs(preRenderTakenMatrix) do
            local box = b.Box:new()
            for r, v in ipairs(row) do
                local below = b.Box:new()
                if #v ~= 0 then
                    below:appendStr("#" .. c .. ", " .. r .. ", " .. " ")
                else
                    below:appendStr(" ")
                end
                box:appendBoxBelow(below)
            end
            sm:append(box)
        end
        extra.trace:appendBoxBelow(dbg.traceBreak("sparse matrix"), false)
        extra.trace:appendBoxBelow(dbg.traceBreak("making grid with " ..
            maxRow .. " rows and " .. #preRenderTakenMatrix .. " cols"), false)
        extra.trace:appendBoxBelow(sm, false)
    end

    local rowI = 1
    local columnI = 1
    local x = startX
    if #rowTemplates == 0 then
        ---@type Banana.Renderer.GridTemplate
        local templ = {
            start = startY,
            size = -1,
            maxSize = 0,
            name = "1",
            claimants = {}
        }
        table.insert(rowTemplates, templ)
        -- for _, col in ipairs(takenMatrix) do
        --     table.insert(col, false)
        -- end
    end
    flame.pop()

    ---@class Banana.Renderer.GridRenderItem
    ---@field priority number z > rows > columns (aka 1,1 z=0 first, 10,10 z=80 last)
    ---@field render Banana.Renderer.PartialRendered
    ---@field ast Banana.Ast
    ---@field rowStart number
    ---@field colStart number

    -- TODO: Need a loop to determine implicit column count/implicit row count

    flame.new("renderGridBlock_renderLoop")
    ---@type Banana.Renderer.GridRenderItem[]
    local renderList = {}
    for i, node in ast:childIterWithI() do
        local row = nil
        local col = nil
        if renderOrder[i] ~= nil then
            row = renderOrder[i].startRow
            col = renderOrder[i].startColumn
        else
            repeat
                columnI = columnI + 1
                if columnI > #columnTemplates then
                    columnI = 1
                    rowI = rowI + 1
                end
                if rowI > #rowTemplates then
                    break
                end
                if preRenderTakenMatrix[columnI] == nil then
                    table.insert(preRenderTakenMatrix, {})
                end
                while preRenderTakenMatrix[columnI][rowI] == nil do
                    table.insert(preRenderTakenMatrix[columnI], {})
                end
            until #preRenderTakenMatrix[columnI][rowI]
            row = rowI
            col = columnI
        end
        local colTempl = columnTemplates[col]
        local rowTempl = getSection(row, rowTemplates, rowLimit)
        local height = rowTempl.size
        if height == -1 then
            height = parentHeight
        end

        if rowTempl.size ~= -1 then
            extra.useAllHeight = true
        end
        node:_resolveUnits(colTempl.size, rowTempl.size, {})
        -- TODO: multi cell size
        local rendered = node.actualTag:getRendered(node, hl, colTempl.size,
            height, x, startY,
            inherit, extra)

        ---@type Banana.Renderer.GridRenderItem
        local renderItem = {
            priority = (columnI - 1) + (rowI - 1) * columnLimit +
                node:firstStyleValue("z-index", 0) * columnLimit * rowLimit,
            rowStart = row,
            colStart = col,
            ast = node,
            render = rendered
        }
        -- TODO: on implicit rows, resize all prev elements if bigger (could
        -- also make secondary startsize matrix but that prolly slower)
        if rowTempl.size == -1 then
            -- local old = rowTempl.maxSize
            rowTempl.maxSize = math.max(rowTempl.maxSize, rendered:getHeight())
            -- local inc = rowTempl.maxSize - old
            -- if inc ~= 0 then
            --     for i = row + 1, #rowTemplates do
            --         rowTemplates[i].start = rowTemplates[i].start + inc
            --     end
            -- end
        end
        table.insert(renderList, renderItem)
        -- TODO: For multi cell blocks, loop through and claim all

        -- dont have to worry abt double insertion
        table.insert(preRenderTakenMatrix[col][row], node)
        -- columnI = columnI + 1
    end
    local ret = b.Box:new(parentHl)

    flame.pop()
    flame.new("renderGridBlock_final")

    -- faster without sort
    -- table.sort(renderList, function (l, r) return l.priority < r.priority end)

    for _, v in ipairs(renderList) do
        local render = v.render
        local rowTempl = rowTemplates[v.rowStart]
        local start = getGridStart(rowTempl, true)
        v.ast:_increaseTopBound(start - v.ast.boundBox.topY)
        if rowTempl.size == -1 and render:getHeight() < rowTempl.maxSize and v.ast:firstStyleValue("height", { unit = "", value = 0 }).unit ~= "ch" then
            v.ast:_increaseHeightBoundBy(rowTempl.maxSize - v.render:getHeight())
            v.render:expandHeightTo(rowTempl.maxSize)
        end
        ret:renderOver(render:render(),
            columnTemplates[v.colStart].start - startX,
            start - startY)
    end

    flame.pop()
    flame.pop()

    return ret, #ast.nodes + 1
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
function TagInfo:renderFlexBlock(ast, parentHl, parentWidth, parentHeight, startX,
                                 startY, inherit, extra)
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
    local rendersLen = 0

    -- base render for non fr els
    for _, v in ipairs(ast.nodes) do
        if type(v) == "string" then
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
        if v:firstStyleValue("flex-shrink") == 0 or v:hasStyle("flex-basis") then
            inherit.min_size = false
        end
        local rendered = v.actualTag:getRendered(v, hl, basisVal, parentHeight,
            startX, startY, inherit, extra)
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


    -- flex-grow and half of flex-wrap
    if takenWidth < parentWidth then
        flexGrowSection(parentWidth, takenWidth, renders, 1, #renders)
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
            log.throw("rendered " .. i .. " was nil!")
            error("")
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
        extra.trace:appendBoxBelow(
            dbg.traceBreak("Wrapping into " .. #lines .. " lines"), false)
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
function TagInfo:renderBlock(ast, parentHl, i, parentWidth, parentHeight, startX,
                             startY, inherit, extra_)
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
        if v == "" then
        elseif type(v) == "string" then
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
                    if el:isNil() then
                        v = ""
                        log.warn("Could not find attribute '" ..
                            attr .. "' for template substitution")
                        vim.notify("Could not find attribute '" ..
                            attr .. "' for template substitution")
                    else
                        v = el:getAttribute(attr) or ""
                    end
                end
            end
            local count = _str.charWidth(v)
            local box = b.Box:new(parentHl)
            box:appendStr(v, nil)
            local overflow = nil
            currentLine, overflow = handleOverflow(ast, i, currentLine, box,
                width, parentHl)
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
            local tag = v.actualTag
            if (tag.formatType == M.FormatType.Block or tag.formatType == M.FormatType.BlockInline) and hasElements then
                break
            end
            v:_resolveUnits(width, height)
            local rendered = tag:getRendered(v, parentHl, width, height, startX,
                startY, inherit, extra_):render()
            startX = startX + rendered:width()
            local overflow = nil
            local orgLines = currentLine:height()
            currentLine, overflow = handleOverflow(ast, i, currentLine, rendered,
                width, parentHl)
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
    return pcall(require, "banana.nml.tags." .. name)
end

---@param ast Banana.Ast|string
---@return string
function M.firstChar(ast)
    if type(ast) == "string" then
        if string.len(ast) > 0 then
            return string.sub(ast, 1, 1)
        end
        return ""
    end
    if ast.nodes[1] == nil then
        return ""
    end
    ---@cast ast Banana.Ast
    local i = 1
    while M.firstChar(ast.nodes[i]) == "" do
        i = i + 1
        if i > #ast.nodes then
            return ""
        end
    end
    return M.firstChar(ast.nodes[i])
end

---@return Banana.TagInfo
---@param name string
function M.makeTag(name)
    local ok, mgr = pcall(require, "banana.nml.tags." .. name)
    if not ok then
        log.throw(
            "Error while trying to load tag '" .. name .. "'")
        error("")
    end
    return mgr
end

return M
