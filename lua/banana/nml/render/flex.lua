---@module 'banana.nml.render.partialRendered'
local p = require("banana.lazyRequire")("banana.nml.render.partialRendered")
---@module 'banana.box'
local b = require("banana.lazyRequire")("banana.box")
---@module 'banana.libbananabox'
local lb = require("banana.lazyRequire")("banana.libbanana")

---Renders everything in a flex block
---@param ast Banana.Ast
---@param box Banana.Box
---@param parentHl Banana.Highlight?
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@param maxWidths number[]?
local function flexRenderNoWrap(ast, box, parentHl, inherit, extra, maxWidths)
    maxWidths = maxWidths or {}
    ---@type Banana.Renderer.PartialRendered[]
    local renders = {}
    ---@type Banana.Box[]
    local containers = {}

    local minWidth = 0
    local width = 0
    local oldMinSize = inherit["min-size"]
    inherit["min-size"] = true
    local parentWidth = box:getMaxWidth()
    local totalGrows = 0
    local totalShrinks = 0
    local maxHeight = 0
    local i = 0
    for child in ast:childIter() do
        child:_resolveUnits(parentWidth, box:getMaxHeight())
        i = i + 1
        local maxWidth = maxWidths[i] or box:getMaxWidth()
        if child:_firstStyleValue("flex-shrink") == 0 then
            inherit["min-size"] = false
        end
        if child:hasStyle("flex-basis") then
            maxWidth = child:_firstStyleComputedValue("flex-basis", 0) +
                child:paddingLeft() + child:paddingRight() + child:marginLeft() +
                child:marginRight()
        end
        local context = lb.box_context_create()
        local newBox = b.boxFromCtx(context, extra.trace)
        newBox:setMaxWidth(maxWidth)
        newBox:setMaxHeight(box:getMaxHeight())
        table.insert(containers, newBox)
        local render = child.actualTag:getRendered(child, newBox, parentHl,
            inherit, extra)

        inherit["min-size"] = true

        table.insert(renders, render)

        minWidth = minWidth + render:getMinWidth()

        if child:hasStyle("flex-basis") and render:getWidth() < maxWidth then
            local basis = child:_firstStyleComputedValue("flex-basis", 0)
            local extraPad = render:getWidth() - render.center:getWidth()
            ---@cast basis number
            render:setMaxWidth(math.min(basis, maxWidth - extraPad))
            if render:getAlign() == p.Align.noexpand then
                render:setAlign(p.Align.left)
            end
        end
        width = width + render:getWidth()

        totalGrows = totalGrows + child:_firstStyleValue("flex-grow", 1)
        totalShrinks = totalShrinks +
            child:_firstStyleValue("flex-shrink", 1)
        maxHeight = math.max(maxHeight, render:getHeight())
    end

    if width > parentWidth and totalShrinks > 0 then
        local distribution = width - parentWidth
        ---@type number[]
        local newWidths = {}

        -- shrink value is proportional to element width, so:
        -- shrink_i = floor(width%_i * flex-shrink_i * (shrink factor)) + q
        --      where q is some small integer to add to fill up extra space
        -- sum_{i=1}^n shrink_i = distribution
        -- shrink factor = distribution / (sum_{i=1}^n (width%_i * flex-shrink_i))

        local sum = 0
        for _, v in ipairs(renders) do
            sum = sum +
                v:getWidth() / width * v.ast:_firstStyleValue("flex-shrink", 1)
        end
        local shrinkFactor = distribution / sum

        local extraToAdd = 0
        for _, render in ipairs(renders) do
            local decrease    = render:getWidth() / width *
                render.ast:_firstStyleValue("flex-shrink", 1) *
                shrinkFactor
            local extraAmount = math.ceil(decrease) - decrease
            extraToAdd        = extraToAdd + extraAmount
            local w           = render:getWidth() - math.ceil(decrease)
            if extraToAdd >= 1 then
                w = w + 1
                extraToAdd = extraToAdd - 1
            end
            if minWidth > parentWidth then
                table.insert(newWidths, w)
            else
                render:setMaxWidth(w)
                render.center:setWidth(w)
            end
        end

        -- if minWidth > parentWidth and #maxWidths == 0 then
        --     for _, render in ipairs(renders) do
        --         lb.box_context_delete(render.ctx)
        --     end
        --     flexRenderNoWrap(ast, box, parentHl, inherit, extra, newWidths)
        -- end
    elseif width < parentWidth and totalGrows > 0 then
        local extraWidth = parentWidth - width
        local growPer = math.floor(extraWidth / totalGrows)
        local extraGrow = extraWidth - growPer * totalGrows
        for _, render in ipairs(renders) do
            local grow = render.ast:_firstStyleValue("flex-grow", 1)
            ---@cast grow number
            if grow == 0 then
                goto continue
            end
            local boxWidth = render.center:getWidth()

            local growAmount = growPer * grow
            if extraGrow > 0 then
                local extraAdded = math.min(math.ceil(grow), extraGrow)
                growAmount = growAmount + extraAdded
                extraGrow = extraGrow - extraAdded
            end

            local newBoxWidth = boxWidth + growAmount

            render:setMaxWidth(render:getWidth() + growAmount)
            render.center:setWidth(newBoxWidth)
            ::continue::
        end
    end

    for _, pr in ipairs(renders) do
        pr:setMaxHeight(maxHeight)
        pr:setVerticalAlign(p.Align.left)
        pr:render()
        box:renderOver(pr.ctx, 0, 0)
        lb.box_context_delete(pr.ctx)
        -- TODO: Fixup ast bound boxes
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
    return box, #ast.nodes
    -- log.trace("TagInfo:renderFlexBlock " .. ast.tag)
    -- flame.new("renderFlexBlock")
    --
    -- -- TODO: Flex rendering stuff:
    -- --  - flex-shrink distributes available negative space
    -- --  however, i have no idea how i could do that without way
    -- --  too much werk
    -- --  - flex-grow distributes available positive space (ez enough)
    -- --  - flex-wrap is just inlineblock yuhh
    -- --  - flex-basis is just a min-width (chilling)
    --
    -- -- possible todos:
    -- --   abstract out base rendering into a function
    -- --   inline the current height / line calculation
    -- --   maybe some other stuff
    -- local oldMinSize = inherit["min-size"]
    -- inherit["min-size"] = true
    -- local takenWidth = 0
    -- ---@type ([Banana.Renderer.PartialRendered, Banana.Ast]?)[]
    -- local renders = {}
    -- local rendersLen = 0
    -- -- TODO: Flex rendering will require unholy things to be done to the boxes
    -- --  - nowrap + nogrow: just render as inline block (like wrap ig)
    -- --  - nowrap + grow: we will prolly have to make container boxes for each pr (inlineBlock),
    -- --  then after rendering (left to right) each pr, increase following
    -- --  container boxes cursorX, and render
    -- --  - wrap + nogrow: prolly can just force boxes to be inlineBlock and everything
    -- --  should automatically wrap
    -- --  - wrap + grow: just nowrap+grow with
    --
    -- for _, v in ipairs(ast.nodes) do
    --     if type(v) == "string" then
    --         goto continue
    --     end
    --
    --     v:_resolveUnits(box:getMaxWidth(), box:getMaxWidth())
    --     local basis = v:_firstStyleValue("flex-basis", {
    --         computed = box:getMaxWidth(),
    --         unit = "ch",
    --         value = box:getMaxWidth(),
    --     })
    --     ---@cast basis Banana.Ncss.UnitValue
    --     local basisVal = math.min(basis.computed or parentWidth, parentWidth)
    --     if v:_firstStyleValue("flex-shrink") == 0 or v:hasStyle("flex-basis") then
    --         inherit["min-size"] = false
    --     end
    --     local rendered = v.actualTag:getRendered(v, parentHl, basisVal,
    --         parentHeight,
    --         startX, startY, inherit, extra)
    --
    --     inherit["min-size"] = true
    --
    --     renders[rendersLen + 1] = { rendered, v }
    --     rendersLen = rendersLen + 1
    --     -- if rendered:getHeight() > currentHeight then
    --     --     currentHeight = rendered:getHeight()
    --     -- end
    --
    --     takenWidth = takenWidth + rendered:getWidth()
    --
    --     ::continue::
    -- end
    --
    -- -- if extra.debug then
    -- --     extra.trace:appendBoxBelow(dbg.traceBreak("flex w/o fr"), false)
    -- --     extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
    -- --     for i, v in ipairs(renders) do
    -- --         if v ~= nil then
    -- --             extra.trace:appendBoxBelow(dbg.traceBreak(i .. ""), false)
    -- --             extra.trace:appendBoxBelow(v[1]:render(true), false)
    -- --             extra.trace:appendBoxBelow(dbg.traceBreak(v[1].renderAlign),
    -- --                 false)
    -- --         else
    -- --             extra.trace:appendBoxBelow(dbg.traceBreak(i .. ""), false)
    -- --             local box = b.Box:new()
    -- --             box:appendStr("empty")
    -- --             extra.trace:appendBoxBelow(box, false)
    -- --         end
    -- --     end
    -- -- end
    --
    --
    -- -- flex-grow and half of flex-wrap
    -- if takenWidth < parentWidth then
    --     flexGrowSection(parentWidth, takenWidth, renders, 1, #renders)
    -- elseif ast:_firstStyleValue("flex-wrap", "nowrap") == "wrap" then
    --     local taken = 0
    --     local startI = 1
    --     -- local yInc = 0
    --     for i, v in ipairs(renders) do
    --         if v == nil then
    --             error("Unreachable")
    --         end
    --         -- if yInc > 0 then
    --         --     v[2]:_increaseTopBound(yInc)
    --         -- end
    --         local render = v[1]
    --         if taken + render:getWidth() > parentWidth then
    --             flexGrowSection(parentWidth, taken, renders, startI, i - 1)
    --             taken = 0
    --             startI = i
    --             -- yInc = yInc + renders[startI][1]:getHeight()
    --         end
    --         taken = taken + render:getWidth()
    --     end
    --     flexGrowSection(parentWidth, taken, renders, startI, #renders)
    -- end
    -- if extra.debug then
    --     extra.trace:appendBoxBelow(dbg.traceBreak("flex-grow"), false)
    --     extra.trace:appendBoxBelow(ast:_testDumpBox(), false)
    --     for i, v in ipairs(renders) do
    --         if v ~= nil then
    --             extra.trace:appendBoxBelow(dbg.traceBreak(i .. ""), false)
    --             extra.trace:appendBoxBelow(v[1]:render(true), false)
    --         end
    --     end
    -- end
    --
    --
    --
    -- --- post processing cleanup to readjust bound boxes
    -- local inc = 0
    -- local yInc = 0
    -- local isWrap = ast:_firstStyleValue("flex-wrap", "nowrap") == "wrap"
    -- ---@type [Banana.Renderer.PartialRendered, Banana.Ast][][]
    -- local lines = {}
    -- ---@type [Banana.Renderer.PartialRendered, Banana.Ast][]
    -- local line = {}
    --
    -- for i = 1, #renders do
    --     local v = renders[i]
    --     if v == nil then
    --         log.throw("rendered " .. i .. " was nil!")
    --         error("")
    --     end
    --
    --     if inc + renders[i][1]:getWidth() > parentWidth and #line > 0 and isWrap then
    --         table.insert(lines, line)
    --         local maxH = 0
    --
    --         for _, el in ipairs(line) do
    --             maxH = math.max(el[1]:getHeight(), maxH)
    --         end
    --
    --         for _, el in ipairs(line) do
    --             if el[1]:getHeight() < maxH then
    --                 el[1]:expandHeightTo(maxH)
    --                 el[2]:_increaseHeightBoundBy(maxH - el[1]:getHeight())
    --             end
    --         end
    --
    --         yInc = yInc + line[1][1]:getHeight()
    --         line = {}
    --         inc = 0
    --     end
    --
    --     if yInc > 0 then
    --         renders[i][2]:_increaseTopBound(yInc)
    --     end
    --
    --
    --     table.insert(line, renders[i])
    --     v[2]:_increaseLeftBound(inc)
    --     inc = inc + v[1]:getWidth()
    -- end
    -- table.insert(lines, line)
    -- local maxH = 0
    -- for _, v in ipairs(line) do
    --     maxH = math.max(v[1]:getHeight(), maxH)
    -- end
    -- for _, v in ipairs(line) do
    --     if v[1]:getHeight() < maxH then
    --         v[1]:expandHeightTo(maxH)
    --         v[2]:_increaseHeightBoundBy(maxH - v[1]:getHeight())
    --     end
    -- end
    -- if extra.debug then
    --     extra.trace:appendBoxBelow(
    --         dbg.traceBreak("Wrapping into " .. #lines .. " lines"), false)
    -- end
    --
    -- local ret = b.Box:new(parentHl)
    -- for _, l in ipairs(lines) do
    --     local box = b.Box:new(parentHl)
    --     for _, val in ipairs(l) do
    --         box:append(val[1]:render(), nil)
    --     end
    --     ret:appendBoxBelow(box)
    -- end
    -- -- for _, v in ipairs(renders) do
    -- --     if v ~= nil then
    -- --         ret:append(v[1]:render(), nil)
    -- --     end
    -- -- end
    -- inherit["min-size"] = oldMinSize
    --
    -- flame.pop()
    -- return ret, #ast.nodes + 1
end
