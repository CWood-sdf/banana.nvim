--- TODO: The grid rendering system needs to be reworked (again) to allow for
--- auto-size columns. the rework would be somewhat minimal (compared to what's
--- already happened with these functions). it would just be like render the
--- auto size ones first, then compute widths for everything else, then render
--- everything else, then combine into one rendering area. Doing things this way
--- would also allow more complicated values for grid-template-columns (like
--- minmax functions or something)

--- TODO: Basically we just need to first lay out all the elements (grid
--- placement) then determine column widths in order of priority (eg static
--- sized, then auto sized, then ..., then finally distribute to the fr)

---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.ncss.unit'
local unit = require("banana.lazyRequire")("banana.ncss.unit")
---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
local M = {}
---@module 'banana.box'
local b = require("banana.lazyRequire")("banana.box")
---@module 'banana.nml.render.partialRendered'
local p = require("banana.lazyRequire")("banana.nml.render.partialRendered")
---@module 'banana.libbananagrid'
local so = require("banana.lazyRequire")("banana.libbanana")
---@module 'banana.libbananabox'
local lb = require("banana.lazyRequire")("banana.libbanana")
-- ---@module 'banana.ncss.unit'
-- local unit = require("banana.lazyRequire")("banana.ncss.unit")

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
---@param gap number
---@return number
local function getGridStart(templ, fix, gap)
    if templ.prevLink == nil then
        return templ.start
    else
        local prevSize = templ.prevLink.size
        if prevSize == -1 then
            prevSize = templ.prevLink.maxSize
        end
        local ret = getGridStart(templ.prevLink, fix, gap) + prevSize + gap
        if fix then
            templ.start = ret
            templ.prevLink = nil
        end
        return ret
    end
end

---Essentially this is so that we can arrange the children such that we can
---do the least amount of resizing
---@class (exact) Banana.Renderer.GridPreRender
---@field ast Banana.Ast
---@field startColumn number
---@field startRow number
---@field colSize number
---@field rowSize number

---@class (exact) Banana.Renderer.GridRenderItem
---@field ctx number
---@field priority number z > rows > columns (aka 1,1 z=0 first, 10,10 z=80 last)
---@field render Banana.Renderer.PartialRendered
---@field ast Banana.Ast
---@field rowStart number
---@field colStart number
---@field colEnd number
---@field rowEnd number
---@field ogHeight number

---@param values Banana.Ncss.StyleValue[]
---@param sizeInDirection number
---@param start number
---@param min number
---@param isCol boolean
---@param ast Banana.Ast
---@param gap number
---@return Banana.Renderer.GridTemplate[]
local function getTemplates(values, sizeInDirection, start, min, isCol, ast, gap)
    ---@type Banana.Renderer.GridTemplate[]
    local ret = {}
    local takenSize = gap * (math.max(min, #values) - 1)
    local totalFrs = 0
    ---@type number[]
    local frs = {}
    local i = 1
    local definedHeight = ast:hasStyle("height")
    while i <= math.max(min, #values) do
        local v = values[i]
        if v ~= nil then
            local value = v.value
            if value.unit ~= "fr" and value.unit ~= "nfr" then
                ---@cast value Banana.Ncss.UnitValue
                local resolve = value:computeClone(sizeInDirection)
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
        elseif definedHeight then
            totalFrs = totalFrs + 1
            table.insert(frs, i)
            table.insert(ret, {})
        else
            table.insert(ret, {
                start = 0,
                size = -1,
                maxSize = 0,
                name = i .. "",
                claimants = {},
                prevLink = ret[#ret]
            })
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
        if v ~= nil and v.value.unit == "nfr" then
            extraAdded = 0
        end
        ret[j] = {
            start = 0,
            size = resolve + extraAdded,
            maxSize = resolve + extraAdded,
            name = j .. "",
            claimants = {},
        }
        if ret[j + 1] ~= nil and ret[j + 1].prevLink ~= nil then
            ret[j + 1].prevLink = ret[j]
        end
        extraWidthNeeded = extraWidthNeeded - extraAdded
        takenSize = takenSize + resolve
    end
    for _, v in ipairs(ret) do
        if v.size ~= -1 then
            v.start = v.start + start
            start = start + v.size + gap
        end
    end
    return ret
end
---@param ast Banana.Ast
---@param box Banana.Box
---@param parentHl Banana.Highlight?
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return Banana.Box, integer
local function actualRender(thing, ast, box, parentHl, inherit, extra)
    local insert = table.insert
    local hl = ast:_mixHl(parentHl)
    -- the plan is basically to arrange the grid elements in the places that
    -- they absolutely have to be (eg grid-row or grid-column specified)
    -- ("necessary elements") and determine number of needed implicit columns then render all the elements
    --
    -- and since we already have already determined implicit column, we can just
    -- grab any free spots for elements without grid-row or grid-column

    ---Essentially we want to render things such that resize is minimized
    ---obv anything inside a definite row/col is fine
    ---the index of the table is the i in childIterWithI
    ---@type Banana.Renderer.GridPreRender[]
    local renderOrder = {}

    local maxRow = 0
    local maxCol = 0

    -- using one array instead of many i believe reduces reallocs
    ---@type (Banana.Ast|number|Banana.Ncss.StyleValue[])[]
    local rowEls = {}

    ---@type (Banana.Ast|number|Banana.Ncss.StyleValue[])[]
    local colAndNonSpecEls = {}

    local parentHeight = box:getMaxHeight()
    local parentWidth = box:getMaxWidth()

    local rowGap = ast:_computeUnitFor("row-gap", parentHeight) or 0
    local columnGap = ast:_computeUnitFor("column-gap", parentWidth) or 0

    local colTemplatesDef = ast:_allStylesFor("grid-template-columns")

    local startY = box:getCursorY() + box:getOffsetY()
    local startX = box:getCursorX() + box:getOffsetX()

    maxCol = #colTemplatesDef

    for i, node in ast:childIterWithI() do
        local rows = node:_allStylesFor("grid-row")
        local cols = node:_allStylesFor("grid-column")
        if #cols ~= 0 then
            -- need to preload max columns bc of this case:
            -- first two elements non-defined
            -- next two have grid-column: 1/3 (or span 2 or 1 / span 2...)
            -- the first two elements must be same row, but cant know that ahead
            -- of time, so need this
            if #cols == 2 then
                ---@diagnostic disable-next-line: param-type-mismatch
                maxCol = math.max(maxCol, cols[2].value)
            elseif #cols == 1 then
                ---@diagnostic disable-next-line: param-type-mismatch
                maxCol = math.max(maxCol, cols[1].value)
            elseif #cols == 3 then
                ---@diagnostic disable-next-line: param-type-mismatch
                maxCol = math.max(maxCol, cols[3].value - 1)
            elseif #cols == 4 then
                maxCol = math.max(maxCol, cols[1].value + cols[4].value - 1)
            end
        end
        -- According to validations.lua (as of now), [2] only supports span,
        -- which is NOT considered a definite element
        if #rows == 0 or #rows == 2 then
            insert(colAndNonSpecEls, node)
            insert(colAndNonSpecEls, i)
            if #rows == 0 then
                insert(colAndNonSpecEls, {})
            else
                insert(colAndNonSpecEls, rows)
            end
            if #cols == 0 then
                insert(colAndNonSpecEls, {})
            else
                insert(colAndNonSpecEls, cols)
            end
            goto continue
        end
        if #cols == 0 or #cols == 2 then
            insert(rowEls, node)
            insert(rowEls, i)
            if #rows == 0 then
                insert(rowEls, {})
            else
                insert(rowEls, rows)
            end
            if #cols == 0 then
                insert(rowEls, {})
            else
                insert(rowEls, cols)
            end
            goto continue
        end
        local row = rows[1].value
        local col = cols[1].value
        ---@cast row number
        ---@cast col number
        row = math.max(row, 1)
        col = math.max(col, 1)

        local endRow = row + 1
        local endCol = col + 1
        -- TODO: Handle negative values and span areas
        if #rows == 3 then
            ---@diagnostic disable-next-line: cast-local-type
            endRow = rows[3].value
        elseif #rows == 4 then
            endRow = row + rows[4].value
        end
        ---@cast endRow number
        if #cols == 3 then
            ---@diagnostic disable-next-line: cast-local-type
            endCol = cols[3].value
        elseif #cols == 4 then
            endCol = col + cols[4].value
        end
        ---@type Banana.Renderer.GridPreRender
        local preRender = {
            startRow = row,
            startColumn = col,
            ast = node,
            rowSize = endRow - row,
            colSize = endCol - col,
        }
        renderOrder[i] = preRender
        maxRow = math.max(maxRow, endRow - 1)
        maxCol = math.max(maxCol, endCol - 1)
        ---@diagnostic disable-next-line: param-type-mismatch
        so.grid_turnOnRange(thing, row, col, endRow, endCol)
        ::continue::
    end
    local j = 1
    while j <= #rowEls do
        local node = rowEls[j]
        ---@cast node Banana.Ast
        local i = rowEls[j + 1]
        local rows = rowEls[j + 2]
        local cols = rowEls[j + 3]
        ---@cast rows Banana.Ncss.StyleValue[]
        ---@cast cols Banana.Ncss.StyleValue[]
        -- NOTE: we can only be here if rows *IS* definite
        -- However, cols could also be a span value
        -- (see https://www.w3.org/TR/css-grid-1/#placement)

        local colSpan = 1
        if #cols == 2 then
            ---@diagnostic disable-next-line: cast-local-type
            colSpan = cols[2].value
        end
        ---@cast colSpan number
        ---@cast i number
        local startRow = rows[1].value
        local endRow = startRow + 1
        if #rows == 3 then
            ---@diagnostic disable-next-line: cast-local-type
            endRow = rows[3].value
        elseif #rows == 4 then
            endRow = startRow + rows[4].value
        end
        local column = 1

        ---@cast startRow number
        ---@cast endRow number

        -- small optimization here, we can start reading from end and move
        -- cursor a lot if reach taken element
        local done = false
        local shouldBreak = false
        while not done do
            for c = column + colSpan - 1, column, -1 do
                for r = startRow, endRow - 1 do
                    -- lazy load in rows
                    local enabled = so.grid_isEnabled(thing, r, c)
                    if enabled ~= 0 then
                        column = c + 1
                        shouldBreak = true
                        break
                    end
                end
                if shouldBreak then break end
            end
            if not shouldBreak then
                done = true
            end
            shouldBreak = false
        end
        ---@type Banana.Renderer.GridPreRender
        local preRender = {
            startRow = startRow,
            startColumn = column,
            ast = node,
            rowSize = endRow - startRow,
            colSize = colSpan,
        }
        renderOrder[i] = preRender
        maxRow = math.max(endRow - 1, maxRow)
        maxCol = math.max(column + colSpan - 1, maxCol)

        so.grid_turnOnRange(thing, startRow, column, endRow,
            column + colSpan)
        j = j + 4
    end
    local rowCursor = 1
    local columnCursor = 1
    j = 1
    while j <= #colAndNonSpecEls do
        local node = colAndNonSpecEls[j]
        ---@cast node Banana.Ast
        local i = colAndNonSpecEls[j + 1]
        ---@cast i number
        local rows = colAndNonSpecEls[j + 2]
        local cols = colAndNonSpecEls[j + 3]
        local rowSpan = 1
        local colSpan = 1
        if #rows == 2 then
            ---@diagnostic disable-next-line: cast-local-type
            rowSpan = rows[2].value
        end
        local column = columnCursor
        local colDefined = false
        if #cols == 2 then
            ---@diagnostic disable-next-line: cast-local-type
            colSpan = cols[2].value
        elseif #cols == 1 then
            colDefined = true
            colSpan = 1
            ---@diagnostic disable-next-line: cast-local-type
            column = cols[1].value
        elseif #cols == 3 then
            colDefined = true
            colSpan = cols[3].value - cols[1].value
            ---@diagnostic disable-next-line: cast-local-type
            column = cols[1].value
        elseif #cols == 4 then
            colDefined = true
            ---@diagnostic disable-next-line: cast-local-type
            colSpan = cols[4].value
            ---@diagnostic disable-next-line: cast-local-type
            column = cols[1].value
        end
        ---@cast column number
        ---@cast rowSpan number
        ---@cast colSpan number

        local row = rowCursor
        local done = false
        local shouldBreak = false
        while not done do
            for r = row, row + rowSpan - 1 do
                for c = column, column + colSpan - 1 do
                    if so.grid_isEnabled(thing, r, c) ~= 0 then
                        if colDefined then
                            row = r + 1
                        else
                            column = c + 1
                            if column > maxCol then
                                row = row + 1
                                column = 1
                            end
                        end
                        shouldBreak = true
                        break
                    end
                end
                if shouldBreak then break end
            end
            if not shouldBreak then
                done = true
            end
            shouldBreak = false
        end
        maxRow = math.max(row + rowSpan - 1, maxRow)
        maxCol = math.max(column + colSpan - 1, maxCol)
        columnCursor = column
        rowCursor = row
        ---@cast row number
        ---@type Banana.Renderer.GridPreRender
        local preRender = {
            colSize = colSpan,
            rowSize = rowSpan,
            startRow = row,
            startColumn = column,
            ast = node,
        }
        renderOrder[i] = preRender
        so.grid_turnOnRange(thing, row, column, row + rowSpan,
            column + colSpan)
        j = j + 4
    end


    ---@type Banana.Renderer.GridTemplate[]
    local columnTemplates = {}
    ---@type Banana.Renderer.GridTemplate[]
    local rowTemplates = {}

    columnTemplates = getTemplates(colTemplatesDef, parentWidth, startX, maxCol,
        true, ast,
        columnGap)
    local rows = ast:_allStylesFor("grid-template-rows")
    rowTemplates = getTemplates(rows, parentHeight, 0, maxRow, false, ast,
        rowGap)
    local columnLimit = 300
    local rowLimit = 300
    if #columnTemplates > columnLimit then
        -- if they have more than 300 columns, HOW!?!?!
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
        insert(columnTemplates, templ)
    end


    local rowI = 1
    local columnI = 1
    if #rowTemplates == 0 then
        ---@type Banana.Renderer.GridTemplate
        local templ = {
            start = startY,
            size = -1,
            maxSize = 0,
            name = "1",
            claimants = {}
        }
        insert(rowTemplates, templ)
    end

    ---@type Banana.Renderer.GridRenderItem[]
    local renderList = {}
    for i, node in ast:childIterWithI() do
        local row = nil
        local col = nil
        local rowSpan = 1
        local colSpan = 1
        if renderOrder[i] ~= nil then
            row = renderOrder[i].startRow
            col = renderOrder[i].startColumn
            rowSpan = renderOrder[i].rowSize
            colSpan = renderOrder[i].colSize
        else
            log.throw("unreachable")
            error("")
        end
        local actualHeight = 0
        local actualWidth = 0
        for c = col, col + colSpan - 1 do
            local t     = columnTemplates[c]
            actualWidth = actualWidth + t.size
        end
        -- local x = columnTemplates[col].start
        -- extra.useAllHeight = true
        local ogHeight = 0
        for r = row, row + rowSpan - 1 do
            local t = rowTemplates[r]
            if t.size ~= -1 then
                actualHeight = actualHeight + t.size
                ogHeight = ogHeight + t.size
            else
                ogHeight = ogHeight + t.maxSize
                actualHeight = actualHeight + parentHeight
                extra.useAllHeight = false
            end
        end
        actualHeight = actualHeight + rowGap * (rowSpan - 1)
        actualWidth = actualWidth + columnGap * (colSpan - 1)
        node:_resolveUnits(actualWidth, actualHeight)
        local ctx = lb.box_context_create()
        table.insert(extra.extraCtx, ctx)
        local renderBox = b.boxFromCtx(ctx, extra.trace)
        renderBox:setMaxWidth(actualWidth)
        renderBox:setMaxHeight(actualHeight)
        local rendered = node.actualTag:getRendered(node, renderBox, hl, inherit,
            extra)

        ---@type Banana.Renderer.GridRenderItem
        local renderItem = {
            ctx = ctx,
            ogHeight = ogHeight,
            priority = (columnI - 1) + (rowI - 1) * columnLimit +
                node:_firstStyleValue("z-index", 0) * columnLimit * rowLimit,
            rowStart = row,
            colStart = col,
            rowEnd = row + rowSpan - 1,
            colEnd = col + colSpan - 1,
            ast = node,
            render = rendered
        }
        local heightToDistribute = rendered:getHeight()
        local implicitRows = 0
        for r = row, row + rowSpan - 1 do
            if rowTemplates[r].size == -1 then
                implicitRows = row + rowSpan - r
                break
            end
            local size = rowTemplates[r].size
            heightToDistribute = heightToDistribute - size
        end
        if heightToDistribute > 0 and implicitRows > 0 then
            -- while it's not in spec (afaik) that implicit spanned rows have a min
            -- height of 1, i dont like the idea of 0 height
            if heightToDistribute < implicitRows then
                heightToDistribute = implicitRows
            end
            local perRow = math.floor(heightToDistribute / implicitRows)
            local extraHeight = heightToDistribute - perRow * implicitRows
            for r = row + rowSpan - 1, row, -1 do
                if rowTemplates[r].size ~= -1 then
                    break
                end
                if rowTemplates[r].maxSize >= perRow then
                    heightToDistribute = heightToDistribute - perRow
                    if extraHeight > 0 then
                        heightToDistribute = heightToDistribute - 1
                        extraHeight = extraHeight - 1
                    end
                end
            end
            perRow = math.floor(heightToDistribute / implicitRows)
            extraHeight = heightToDistribute - perRow * implicitRows
            for r = row + rowSpan - 1, row, -1 do
                if rowTemplates[r].size ~= -1 then
                    break
                end
                local newMax = rowTemplates[r].maxSize + perRow
                if rowTemplates[r].maxSize >= perRow then
                    goto continue
                end
                if extraHeight > 0 then
                    newMax      = newMax + 1
                    extraHeight = extraHeight - 1
                end
                rowTemplates[r].maxSize = newMax
                rowTemplates[r].maxSize = math.max(newMax, 1)

                ::continue::
            end
        end
        insert(renderList, renderItem)
    end
    local ret = box:newBelow()

    --- a ctx where we can just render everything to, then render to ret
    local stagingCtx = lb.box_context_create()
    table.insert(extra.extraCtx, stagingCtx)


    table.sort(renderList, function (l, r) return l.priority < r.priority end)

    for _, v in ipairs(renderList) do
        local render = v.render
        local rowTempl = rowTemplates[v.rowStart]
        local colTempl = columnTemplates[v.colStart]
        local rowStart = getGridStart(rowTempl, true, rowGap)
        local colStart = getGridStart(colTempl, true, columnGap)
        -- print(rowStart, colStart)
        local newHeight = 0
        for r = v.rowStart, v.rowEnd do
            local t = rowTemplates[r]
            if t.size == -1 then
                newHeight = newHeight + rowTemplates[r].maxSize
            else
                newHeight = newHeight + rowTemplates[r].size
            end
        end
        -- ikik this doesnt include pcts,
        -- but there are so many cases to worry about because different combos
        -- of margin and height and pct and ch
        -- ALSO browsers are really weird about this because if you set height
        -- to be pct on an implicit row, it's computed with respect to content
        -- height, but if you add margin pct, it's computed with respect to page
        -- height. In a word, that's all too much complexity when people SHOULD
        -- NOT be setting height/width on grid elements
        if
            newHeight > render:getHeight()
            and v.ast:_firstStyleValue("height", unit.newUnit("", 0)).unit ~= "ch"
        then
            render:setMaxHeight(newHeight)
            render:setVerticalAlign(p.Align.left)
        end
        render:render()
        v.ast:_increaseTopBound(rowStart + startY)
        v.ast:_increaseLeftBound(colStart + startX)
        -- v.ast:_increaseHeightBoundBy(heightInc)
        local tempBox = b.boxFromCtx(stagingCtx, extra.ctx)
        tempBox:setHlId(box:getHl())
        tempBox:renderOver(v.ctx,
            columnTemplates[v.colStart].start - startX,
            rowStart)
        tempBox:destroy()
        lb.box_context_delete(v.ctx)
    end
    ret:renderOver(stagingCtx, 0, 0)
    lb.box_context_delete(stagingCtx)
    box:putCursorBelow(ret)
    return box, #ast.nodes + 1
end

--- renders an element with display:grid
---@param ast Banana.Ast
---@param box Banana.Box
---@param parentHl Banana.Highlight?
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return Banana.Box, integer
function M.render(ast, box, parentHl, inherit, extra)
    -- flame.new("TagInfo:renderGridBlock")
    local thing = so.grid_getNew()
    -- have to be able to free the zig memory, hence the pcall
    local errOrRet, i = actualRender(thing, ast, box, parentHl,
        inherit, extra)
    so.grid_freeSection(thing)
    -- flame.pop()
    -- if not ok then error(errOrRet) end
    return errOrRet, i
end

return M
