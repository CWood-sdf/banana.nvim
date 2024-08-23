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
---@module 'ffi'
local ffi = require("banana.lazyRequire")("ffi")
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
    -- flame.new("renderRoot")
    log.trace("TagInfo:renderRoot")
    local ret = self:render(ast, startHl, winWidth, winHeight, 1, 1, inherit,
        extra)
    -- flame.expect("renderRoot")
    -- flame.pop()
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
        -- flame.new("TagInfo:blockIter")
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
        -- flame.pop()
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
    -- flame.new("splitLineBoxOnce")
    if targetWidth < 1 then
        targetWidth = 1
    end
    if box:width() < targetWidth then
        -- flame.pop()
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
        local w = box:getLine(1)[i]
        left:appendWord(w.word, w.style)
        i = i + 1
    end
    local word = box:getLine(1)[i]
    local leftIns = _str.sub(word.word, 1, targetWidth - left:width())
    --Allow unsafe #word.word, bc #word.word is always >= str.charWidth(word.word)
    --so since we are just reading to end of string
    local rightIns = _str.sub(word.word, targetWidth - left:width() + 1,
        #word.word)
    left:appendWord(
        leftIns,
        word.style,
        nil)
    right:appendWord(
        rightIns,
        word.style,
        nil)
    i = i + 1
    while i <= #box:getLine(1) do
        local w = box:getLine(1)[i]
        right:appendWord(w.word, w.style)
        i = i + 1
    end
    -- flame.pop()
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
    -- flame.new("handleOverflow")
    -- if currentLine:height() == 0 then
    --     currentLine:appendStr("", nil)
    -- end
    if currentLine:width() + append:width() <= maxWidth then
        currentLine:append(append, nil)
        -- flame.pop()
        return currentLine, nil
    end
    if append:height() ~= 1 or not breakable(ast.nodes[i]) then
        -- flame.pop()
        return currentLine, append
    end
    if currentLine:height() > 1 then
        local ap, extra = splitLineBoxOnce(maxWidth - currentLine:width(), append,
            hl)
        currentLine:append(ap, nil)
        -- flame.pop()
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
    -- flame.pop()
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
                    local extraAdded = math.min(math.ceil(flexGrow), extraGrow)
                    grow = grow + extraAdded
                    extraGrow = extraGrow - extraAdded
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

local gridSo = nil

function M.getGridSo()
    if gridSo == nil then
        local path = require("banana").getInstallDir() ..
            "/zig/zig-out/lib/libbanana.so"
        if not vim.fn.filereadable(path) then
            vim.notify("libbanana does not exist, installing now...")
            require("banana").installLibbanana()
        end
        ffi.cdef([[

typedef struct {
} BitSetSection;

 bool toggle(struct BitSetSection* s, uint32_t row, uint32_t column);

 bool turnOn(struct BitSetSection*, uint32_t row, uint32_t column);

 bool turnOnRange(struct BitSetSection*, uint32_t rowStart, uint32_t colStart, uint32_t rowEnd, uint32_t colEnd);

 uint32_t isEnabled(struct BitSetSection*, uint32_t row, uint32_t column);

 struct BitSetSection* getNew();

 void freeSection(struct BitSetSection*);

 void initExisting(struct BitSetSection*);


        ]])
        local loadSo = function ()
            gridSo = ffi.load(require("banana").getInstallDir() ..
                "/zig/zig-out/lib/libbanana.so")
        end
        local ok, _ = pcall(loadSo)
        if not ok or gridSo == nil then
            vim.notify("libbanana does not exist, attempting reinstall...")
            require("banana").installLibbanana()
            ok, _ = pcall(loadSo)
            if not ok or gridSo == nil then
                log.throw(
                    "Could not find libbanana, do you have zig installed on your system?")
                error("")
            end
        end
    end
    return gridSo
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
---@field priority number z > rows > columns (aka 1,1 z=0 first, 10,10 z=80 last)
---@field render Banana.Renderer.PartialRendered
---@field ast Banana.Ast
---@field rowStart number
---@field colStart number
---@field colEnd number
---@field rowEnd number
---@field ogHeight number

---@class (exact) Banana.Renderer.CellClaimant
---@field render Banana.Renderer.PartialRendered?
---@field ast Banana.Ast
---@field box Banana.Box?
---@field startRow number
---@field startCol number

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
    local insert = table.insert
    local hl = ast:_mixHl(parentHl)
    local so = M.getGridSo()
    local thing = so.getNew()

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

    local rowGap = ast:_computeUnitFor("row-gap", parentHeight, {}) or 0
    local columnGap = ast:_computeUnitFor("column-gap", parentWidth, {}) or 0

    local colTemplatesDef = ast:allStylesFor("grid-template-columns")
    if colTemplatesDef == nil then
        colTemplatesDef = {}
    end

    maxCol = #colTemplatesDef

    for i, node in ast:childIterWithI() do
        local rows = node:allStylesFor("grid-row")
        local cols = node:allStylesFor("grid-column")
        if cols ~= nil then
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
        if rows == nil or #rows == 2 then
            insert(colAndNonSpecEls, node)
            insert(colAndNonSpecEls, i)
            if rows == nil then
                insert(colAndNonSpecEls, {})
            else
                insert(colAndNonSpecEls, rows)
            end
            if cols == nil then
                insert(colAndNonSpecEls, {})
            else
                insert(colAndNonSpecEls, cols)
            end
            goto continue
        end
        if cols == nil or #cols == 2 then
            insert(rowEls, node)
            insert(rowEls, i)
            if rows == nil then
                insert(rowEls, {})
            else
                insert(rowEls, rows)
            end
            if cols == nil then
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
        so.turnOnRange(thing, row, col, endRow, endCol)
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
                    local enabled = so.isEnabled(thing, r, c)
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

        so.turnOnRange(thing, startRow, column, endRow,
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
                    if so.isEnabled(thing, r, c) ~= 0 then
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
        so.turnOnRange(thing, row, column, row + rowSpan,
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
    local rows = ast:allStylesFor("grid-template-rows")
    if rows == nil then
        rows = {}
    end
    rowTemplates = getTemplates(rows, parentHeight, 0, maxRow, false, ast,
        rowGap)
    so.freeSection(thing)
    local columnLimit = 300
    local rowLimit = 300
    if #columnTemplates > columnLimit then
        -- if they have more than 5000 columns, HOW!?!?!
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
        local x = columnTemplates[col].start
        extra.useAllHeight = true
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
        node:_resolveUnits(actualWidth, actualHeight, {})
        flame.new("getRendered")
        local rendered = node.actualTag:getRendered(node, hl, actualWidth,
            actualHeight, x, startY,
            inherit, extra)
        flame.pop()

        ---@type Banana.Renderer.GridRenderItem
        local renderItem = {
            ogHeight = ogHeight,
            priority = (columnI - 1) + (rowI - 1) * columnLimit +
                node:firstStyleValue("z-index", 0) * columnLimit * rowLimit,
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
            -- while it's not in spec that implicit spanned rows get extra
            -- height, im not sure what else to do
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
    local ret = b.Box:new(parentHl)


    table.sort(renderList, function (l, r) return l.priority < r.priority end)

    for _, v in ipairs(renderList) do
        local render = v.render
        local rowTempl = rowTemplates[v.rowStart]
        local start = getGridStart(rowTempl, true, rowGap)
        local newHeight = 0
        for r = v.rowStart, v.rowEnd do
            local t = rowTemplates[r]
            if t.size == -1 then
                newHeight = newHeight + rowTemplates[r].maxSize
            else
                newHeight = newHeight + rowTemplates[r].size
            end
        end
        v.ast:_increaseTopBound(start)
        if newHeight > render:getHeight() and v.ast:firstStyleValue("height", { unit = "", value = 0 }).unit ~= "ch" then
            v.ast:_increaseHeightBoundBy(newHeight - v.render:getHeight())
            v.render:expandHeightTo(newHeight)
        end
        ret:renderOver(render:render(),
            columnTemplates[v.colStart].start - startX,
            start)
    end

    flame.pop()
    --
    return ret, #ast.nodes + 1
    -- return b.Box:new(), 40
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
                extra.trace:appendBoxBelow(dbg.traceBreak(v[1].renderAlign),
                    false)
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
