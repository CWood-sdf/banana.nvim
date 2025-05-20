---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
---@module 'banana.utils.debug'
local dbg = require("banana.lazyRequire")("banana.utils.debug")
---@module 'banana.box'
local b = require("banana.lazyRequire")("banana.box")
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
        totalGrows = totalGrows + node:_firstStyleValue("flex-grow", 0)
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
            if node:_firstStyleValue("flex-grow", 0) ~= 0 then
                local flexGrow = node:_firstStyleValue("flex-grow", 0)
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

---Renders everything in a flex block
---@param ast Banana.Ast
---@param box Banana.Box
---@param parentHl Banana.Highlight?
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
local function flexRenderNoWrap(ast, box, parentHl, inherit, extra)
    ---@type Banana.Renderer.PartialRendered[]
    local renders = {}
    ---@type Banana.Box[]
    local containers = {}

    local minWidth = 0
    local width = 0
    local oldMinSize = inherit["min-size"]
    inherit["min-size"] = true
    local parentWidth = box:getMaxWidth()
    for child in ast:childIter() do
        child:_resolveUnits(parentWidth, box:getMaxHeight())
        if child:_firstStyleValue("flex-shrink") == 0 or child:hasStyle("flex-basis") then
            inherit["min-size"] = false
        end
        local newBox = box:newCursored()
        table.insert(containers, newBox)
        local rendered = child.actualTag:getRendered(child, newBox, parentHl,
            inherit, extra)

        inherit["min-size"] = true

        table.insert(renders, rendered)
        -- if rendered:getHeight() > currentHeight then
        --     currentHeight = rendered:getHeight()
        -- end

        box:unsafeIncreaseCursorBy(0, rendered:getWidth())
        width = width + rendered:getWidth()
        minWidth = minWidth + rendered:getMinWidth()
    end

    if width > parentWidth then
        local distribution = width - parentWidth
    elseif width < parentWidth then
    end

    for _, v in ipairs(renders) do
        v:render()
    end
    inherit["min-size"] = oldMinSize
end
---Renders everything in a flex block
---@param ast Banana.Ast
---@param box Banana.Box
---@param parentHl Banana.Highlight?
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return Banana.Box, integer
return function (ast, box, parentHl,
                 inherit, extra)
    flexRenderNoWrap(ast, box, parentHl, inherit, extra)
    log.trace("TagInfo:renderFlexBlock " .. ast.tag)
    flame.new("renderFlexBlock")

    -- TODO: Flex rendering stuff:
    --  - flex-shrink distributes available negative space
    --  however, i have no idea how i could do that without way
    --  too much werk
    --  - flex-grow distributes available positive space (ez enough)
    --  - flex-wrap is just inlineblock yuhh
    --  - flex-basis is just a min-width (chilling)

    -- possible todos:
    --   abstract out base rendering into a function
    --   inline the current height / line calculation
    --   maybe some other stuff
    local oldMinSize = inherit["min-size"]
    inherit["min-size"] = true
    local takenWidth = 0
    ---@type ([Banana.Renderer.PartialRendered, Banana.Ast]?)[]
    local renders = {}
    local rendersLen = 0
    -- TODO: Flex rendering will require unholy things to be done to the boxes
    --  - nowrap + nogrow: just render as inline block (like wrap ig)
    --  - nowrap + grow: we will prolly have to make container boxes for each pr (inlineBlock),
    --  then after rendering (left to right) each pr, increase following
    --  container boxes cursorX, and render
    --  - wrap + nogrow: prolly can just force boxes to be inlineBlock and everything
    --  should automatically wrap
    --  - wrap + grow: just nowrap+grow with

    for _, v in ipairs(ast.nodes) do
        if type(v) == "string" then
            goto continue
        end

        v:_resolveUnits(box:getMaxWidth(), box:getMaxWidth())
        local basis = v:_firstStyleValue("flex-basis", {
            computed = box:getMaxWidth(),
            unit = "ch",
            value = box:getMaxWidth(),
        })
        ---@cast basis Banana.Ncss.UnitValue
        local basisVal = math.min(basis.computed or parentWidth, parentWidth)
        if v:_firstStyleValue("flex-shrink") == 0 or v:hasStyle("flex-basis") then
            inherit["min-size"] = false
        end
        local rendered = v.actualTag:getRendered(v, parentHl, basisVal,
            parentHeight,
            startX, startY, inherit, extra)

        inherit["min-size"] = true

        renders[rendersLen + 1] = { rendered, v }
        rendersLen = rendersLen + 1
        -- if rendered:getHeight() > currentHeight then
        --     currentHeight = rendered:getHeight()
        -- end

        takenWidth = takenWidth + rendered:getWidth()

        ::continue::
    end

    -- if extra.debug then
    --     extra.trace:appendBoxBelow(dbg.traceBreak("flex w/o fr"), false)
    --     extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
    --     for i, v in ipairs(renders) do
    --         if v ~= nil then
    --             extra.trace:appendBoxBelow(dbg.traceBreak(i .. ""), false)
    --             extra.trace:appendBoxBelow(v[1]:render(true), false)
    --             extra.trace:appendBoxBelow(dbg.traceBreak(v[1].renderAlign),
    --                 false)
    --         else
    --             extra.trace:appendBoxBelow(dbg.traceBreak(i .. ""), false)
    --             local box = b.Box:new()
    --             box:appendStr("empty")
    --             extra.trace:appendBoxBelow(box, false)
    --         end
    --     end
    -- end


    -- flex-grow and half of flex-wrap
    if takenWidth < parentWidth then
        flexGrowSection(parentWidth, takenWidth, renders, 1, #renders)
    elseif ast:_firstStyleValue("flex-wrap", "nowrap") == "wrap" then
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
    local isWrap = ast:_firstStyleValue("flex-wrap", "nowrap") == "wrap"
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

        if yInc > 0 then
            renders[i][2]:_increaseTopBound(yInc)
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

    local ret = b.Box:new(parentHl)
    for _, l in ipairs(lines) do
        local box = b.Box:new(parentHl)
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
    inherit["min-size"] = oldMinSize

    flame.pop()
    return ret, #ast.nodes + 1
end
