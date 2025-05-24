---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
---@module 'banana.nml.render.partialRendered'
local p   = require("banana.lazyRequire")("banana.nml.render.partialRendered")
---@module 'banana.box'
local b   = require("banana.lazyRequire")("banana.box")
---@module 'banana.libbananabox'
local lb  = require("banana.lazyRequire")("banana.libbanana")

---@param arr Banana.Renderer.PartialRendered[]
---@param width number
---@param maxWidth number
---@param totalGrows number
---@param height number
---@param inherit Banana.Renderer.InheritedProperties
local function flexAdjustSection(arr, width, maxWidth, totalGrows, height,
                                 inherit)
    if width > maxWidth then
        return
    end

    local extraWidth = maxWidth - width
    local growPer = extraWidth / totalGrows
    local extraGrow = 0
    for _, render in ipairs(arr) do
        render:setMaxHeight(height)
        render:setVerticalAlign(p.Align.left)

        local grow = render.ast:_firstStyleValue("flex-grow", 1)

        ---@cast grow number
        if grow == 0 then
            goto continue
        end

        local growAmount = growPer * grow
        local actualGrow = math.floor(growAmount)

        extraGrow = extraGrow + growAmount - actualGrow
        if extraGrow >= 1 then
            actualGrow = actualGrow + 1
            extraGrow = extraGrow - 1
        end

        render:setMaxWidth(render:getWidth() + actualGrow, true)
        if render:getAlign() == p.Align.noexpand then
            -- have to set the align bc it was overwritten by setting min-width
            local align = render.ast:_firstStyleValue("text-align") or
                inherit["text-align"]

            if align == "left" then
                render:setAlign(p.Align.left)
            elseif align == "right" then
                render:setAlign(p.Align.right)
            elseif align == "center" then
                render:setAlign(p.Align.center)
            else
                log.throw("Undefined text align type " .. inherit["text-align"])
            end
        end
        ::continue::
    end
end

---Renders everything in a flex block
---@param ast Banana.Ast
---@param box Banana.Box
---@param parentHl Banana.Highlight?
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
local function flexRenderWrap(ast, box, parentHl, inherit, extra)
    ---@type Banana.Renderer.PartialRendered[]
    local renders = {}
    ---@type Banana.Box[]
    local containers = {}

    local width = 0
    local oldMinSize = inherit["min-size"]
    inherit["min-size"] = true
    local parentWidth = box:getMaxWidth()
    local totalGrows = 0
    local totalShrinks = 0
    local maxHeight = 0
    local i = 0
    ---@type { arr: Banana.Renderer.PartialRendered[], width: number, height: number, totalGrows: number }[]
    local lines = {}
    for child in ast:childIter() do
        child:_resolveUnits(parentWidth, box:getMaxHeight())
        i = i + 1
        local maxWidth = box:getMaxWidth()
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



        if child:hasStyle("flex-basis") and render:getWidth() < maxWidth then
            local basis = child:_firstStyleComputedValue("flex-basis", 0)
            local extraPad = render:getWidth() - render.center:getWidth()
            ---@cast basis number
            render:setMaxWidth(math.min(basis, maxWidth - extraPad))
            if render:getAlign() == p.Align.noexpand then
                render:setAlign(p.Align.left)
            end
        end

        if width + render:getWidth() > parentWidth then
            table.insert(lines, {
                arr = renders,
                width = width,
                height = maxHeight,
                totalGrows = totalGrows,
            })
            totalGrows = 0
            maxHeight = 0
            width = 0
            renders = {}
        end
        width = width + render:getWidth()

        table.insert(renders, render)
        totalGrows = totalGrows + child:_firstStyleValue("flex-grow", 1)
        totalShrinks = totalShrinks +
            child:_firstStyleValue("flex-shrink", 1)
        maxHeight = math.max(maxHeight, render:getHeight())
    end

    if #renders ~= 0 then
        table.insert(lines, {
            arr = renders,
            width = width,
            height = maxHeight,
            totalGrows = totalGrows,
        })
    end

    local xOffset = box:getOffsetX()
    local yOffset = box:getOffsetY()
    for _, v in ipairs(lines) do
        flexAdjustSection(v.arr, v.width, parentWidth, v.totalGrows, v.height,
            inherit)
        local lineBox = box:newBelow()
        local yCursor = box:getCursorY()
        for _, pr in ipairs(v.arr) do
            pr:render()
            local xCursor = box:getCursorX()
            lineBox:renderOver(pr.ctx, 0, 0)
            lb.box_context_delete(pr.ctx)
            pr.ast:_increaseLeftBound(xOffset + xCursor)
            pr.ast:_increaseTopBound(yOffset + yCursor)
        end
        box:putCursorBelow(lineBox)
        lineBox:destroy()
    end

    inherit["min-size"] = oldMinSize
end

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
        if child:hasStyle("flex-basis") and #maxWidths == 0 then
            maxWidth =
                child:_firstStyleComputedValue("flex-basis", 0) +
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

        if child:hasStyle("flex-basis") and render:getWidth() < maxWidth and #maxWidths == 0 then
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
        local totalWidth = 0
        for _, render in ipairs(renders) do
            local decrease    = render:getWidth() / width *
                render.ast:_firstStyleValue("flex-shrink", 1) *
                shrinkFactor
            local extraAmount = math.ceil(decrease) - decrease
            extraToAdd        = extraToAdd + extraAmount
            local w           = render:getWidth() - math.ceil(decrease)
            totalWidth        = totalWidth + w
            if extraToAdd >= 1 and totalWidth < parentWidth then
                w          = w + 1
                totalWidth = totalWidth + 1
                extraToAdd = extraToAdd - 1
            end
            if minWidth > parentWidth then
                table.insert(newWidths, w)
            else
                render:setMaxWidth(w)
                render.center:setWidth(w)
            end
        end

        if minWidth > parentWidth and #maxWidths == 0 then
            for _, render in ipairs(renders) do
                lb.box_context_delete(render.ctx)
            end
            flexRenderNoWrap(ast, box, parentHl, inherit, extra, newWidths)
            return
        end
    elseif width < parentWidth and totalGrows > 0 then
        flexAdjustSection(renders, width, parentWidth, totalGrows, maxHeight,
            inherit)
    end

    local xOffset = box:getOffsetX()
    local yOffset = box:getOffsetY()
    local yCursor = box:getCursorY()
    for _, pr in ipairs(renders) do
        pr:setMaxHeight(maxHeight)
        pr:setVerticalAlign(p.Align.left)
        pr:render()
        local xCursor = box:getCursorX()
        pr.ast:_increaseLeftBound(xOffset + xCursor)
        pr.ast:_increaseTopBound(yOffset + yCursor)
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
    if ast:_firstStyleValue("flex-wrap", "nowrap") == "wrap" then
        flexRenderWrap(ast, box, parentHl, inherit, extra)
    else
        flexRenderNoWrap(ast, box, parentHl, inherit, extra)
    end
    return box, #ast.nodes
end
