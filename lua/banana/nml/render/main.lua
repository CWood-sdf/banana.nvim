---@module 'banana.nml.render.partialRendered'
local p     = require("banana.lazyRequire")("banana.nml.render.partialRendered")
---@module 'banana.libbananabox'
local lb    = require("banana.lazyRequire")("banana.libbanana")
---@module 'banana.box'
local b     = require("banana.lazyRequire")("banana.box")
---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")

---@module 'banana.utils.log'
local log   = require("banana.lazyRequire")("banana.utils.log")
---@module 'banana.nml.tag'
local _tag  = require("banana.lazyRequire")("banana.nml.tag")
---@param ast Banana.Ast
---@return boolean
local function isExpandable(ast)
    local isFlexChild = not ast._parent:isNil() and
        ast._parent:_firstStyleValue("display") == "flex"
    if isFlexChild then
        return
            (ast.actualTag.formatType == _tag.FormatType.Block or ast.actualTag.formatType == _tag.FormatType.BlockInline) and
            (ast:hasStyle("width") or ast:hasStyle("flex-basis"))
    end

    return
        (
            ast.actualTag.formatType == _tag.FormatType.Block
            or ast.actualTag.formatType == _tag.FormatType.BlockInline
        )
        or ast:hasStyle("width")
end
---@param self Banana.TagInfo
---@param ast Banana.Ast
---@param box Banana.Box
---@param parentHl Banana.Highlight?
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return Banana.Renderer.PartialRendered
return function (self, ast, box, parentHl,
                 inherit, extra)
    flame.new("getRendered_start")
    ast.relativeBoxId = nil
    local inheritOld = {}
    -- setmetatable(inherit, { __mode = "kv" })
    for k, _ in pairs(inherit) do
        -- local style = case.snakeToKebab(k)
        if ast:hasStyle(k) then
            inheritOld[k] = inherit[k]
            inherit[k] = ast:_firstStyleValue(k)
            if inherit[k] == "initial" then
                inherit[k] = ast:_getInitialStyles()[k]
            end
        end
    end
    local position = ast:_firstStyleValue("position")
    if position == nil or position == "initial" then
        position = ast:_getInitialStyles().position
    end
    -- flame.pop()
    -- flame.new("getRendered_misc")
    if position == "absolute" and extra.renderAbsolute ~= true then
        local root = ast
        while root.absoluteAsts == nil do
            root = root._parent
        end
        table.insert(root.absoluteAsts, ast)
        for k, _ in pairs(inheritOld) do
            inherit[k] = inheritOld[k]
        end
        flame.pop()
        -- return pr
        return p.noopPartialRendered()
    end
    local disp = ast:_firstStyleValue("display")
    if disp == "none" then
        for k, _ in pairs(inheritOld) do
            inherit[k] = inheritOld[k]
        end
        ast.hidden = true
        flame.pop()
        return p.noopPartialRendered()
    end
    ast.hidden = false
    local pr = p.emptyPartialRendered(box, ast)

    if ast.actualTag.formatType == _tag.FormatType.Inline then
        pr:setRenderType(p.RenderType.inline)
    end
    pr.trace = extra.trace
    local useMaxHeight = extra.useAllHeight
    if ast:_firstStyleValue("width") == "fit-content" then
        -- TODO: Should this also include padding?
        inherit["min-size"] = true
        pr:setAlign(p.Align.noexpand)
    elseif inherit["min-size"] then
        pr:setAlign(p.Align.noexpand)
    elseif ast:hasStyle("flex-basis") then
        -- add margins bc width only sets content-width + padding
        ---@diagnostic disable-next-line: cast-local-type
        local width = ast:_firstStyleValue("width").computed + ast:marginLeft() +
            ast:marginRight()
        pr:setMaxWidth(width)
        if inherit["text-align"] == "left" then
            pr:setAlign(p.Align.left)
        elseif inherit["text-align"] == "right" then
            pr:setAlign(p.Align.right)
        elseif inherit["text-align"] == "center" then
            pr:setAlign(p.Align.center)
        else
            log.throw("Undefined text align type " .. inherit["text-align"])
        end
        if inherit["min-size"] then
            inherit["min-size"] = false
        end
    elseif ast:hasStyle("width") then
        -- add margins bc width only sets content-width + padding
        ---@diagnostic disable-next-line: cast-local-type
        local width = ast:_firstStyleValue("width").computed + ast:marginLeft() +
            ast:marginRight()
        pr:setMaxWidth(width)
        -- yes ik i could just do pr:setAlign(p.Align[inherit["text-align"]})
        -- with a nil check, however that is gross and makes me feel pain
        if inherit["text-align"] == "left" then
            pr:setAlign(p.Align.left)
        elseif inherit["text-align"] == "right" then
            pr:setAlign(p.Align.right)
        elseif inherit["text-align"] == "center" then
            pr:setAlign(p.Align.center)
        else
            log.throw("Undefined text align type " .. inherit["text-align"])
        end
        if inherit["min-size"] then
            inherit["min-size"] = false
        end
    elseif isExpandable(ast) then
        -- pr:setMaxWidth(parentWidth)
        if inherit["text-align"] == "left" then
            pr:setAlign(p.Align.left)
        elseif inherit["text-align"] == "right" then
            pr:setAlign(p.Align.right)
        elseif inherit["text-align"] == "center" then
            pr:setAlign(p.Align.center)
        else
            log.throw("Undefined text align type " .. inherit["text-align"])
        end
    end
    if ast:hasStyle("height") then
        ---@diagnostic disable-next-line: cast-local-type
        local height =
            ast:_firstStyleValue("height").computed + ast:marginTop() +
            ast:marginBottom()

        -- print("Setting height to " .. height)

        if (not ast:parent():isNil() or ast.tag == "template") then
            pr:setMaxHeight(height + ast:marginTop() + ast:marginBottom())
            pr:setVerticalAlign(p.Align.left)
        end
    elseif useMaxHeight then
        pr:setVerticalAlign(p.Align.left)
        -- pr:setMaxHeight(parentHeight + ast:marginTop() + ast:marginBottom())
    end

    flame.pop()
    flame.new("element render")
    extra.useAllHeight = false
    local hl = ast:_mixHl(parentHl)
    pr:setDbgCtx(extra.trace)
    pr:setPad(ast:paddingLeft(), ast:paddingRight(), ast:paddingTop(),
        ast:paddingBottom())
    pr:setMargin(ast:marginLeft(), ast:marginRight(), ast:marginTop(),
        ast:marginBottom())
    pr:setMainHl(b.addHighlight(extra.ctx, hl))
    flame.pop()
    flame.new("other render")
    local contentBox = pr:getBox()

    if extra.trace ~= nil then
        lb.box_context_dump_comment(extra.trace, "Rendering " .. ast.tag)
    end
    self:render(ast, contentBox, hl, inherit, extra)

    if position == "relative" then
        if pr:getRenderType() == p.RenderType.inline then
            log.throw("Absolute position not implemented for inline els yet")
        end
        table.insert(pr.postRender, function ()
            local bound = ast.boundBox
            if bound == nil then
                log.throw(
                    "Unreachable: Ast bound box not set after PartialRendered:render()")
                error("")
            end
            local image = lb.box_image_snap(pr.ctx, bound.leftX - 1,
                bound.topY - 1,
                bound.rightX - bound.leftX, bound.bottomY - bound.topY,
                b.addHighlight(extra.ctx, parentHl))

            local deltaX = 0
            local deltaY = 0
            if ast:hasStyle("left") then
                deltaX = deltaX + ast:_firstStyleValue("left").computed
            elseif ast:hasStyle("right") then
                deltaX = deltaX - ast:_firstStyleValue("right").computed
            end
            if ast:hasStyle("top") then
                deltaY = deltaY + ast:_firstStyleValue("top").computed
            elseif ast:hasStyle("bottom") then
                deltaY = deltaY + ast:_firstStyleValue("bottom").computed
            end
            ast:_increaseLeftBound(deltaX)
            ast:_increaseTopBound(deltaY)
            ---@type Banana.Ast
            local root = ast
            while root.relativeBoxes == nil do
                root = root._parent
            end
            table.insert(root.relativeBoxes, {
                image = image,
                -- width = ast:getWidth() + ast:marginLeft() + ast:marginRight(),
                -- height = ast:getHeight() + ast:marginBottom() + ast:marginTop(),
                left = ast.boundBox.leftX - ast:marginLeft() - 1,
                top = ast.boundBox.topY - ast:marginTop() - 1,
                z = ast:_firstStyleValue("z-index", 0)
            })
        end)
    end

    if ast.absoluteAsts ~= nil and #ast.absoluteAsts > 0 then
        -- log.throw("Reimplement absoluteAsts")
        local oldRenderAbsolute = extra.renderAbsolute
        ---@type Banana.Ast
        local root = ast
        while root.relativeBoxes == nil do
            root = root._parent
        end
        extra.renderAbsolute = true
        for _, v in ipairs(ast.absoluteAsts) do
            v:_resolveUnits(box:getMaxWidth(), box:getMaxHeight())
            local ctx = lb.box_context_create()
            table.insert(extra.extraCtx, ctx)
            local renderBox = b.boxFromCtx(ctx, extra.trace)
            renderBox:setMaxWidth(box:getMaxWidth())
            renderBox:setMaxHeight(box:getMaxHeight())
            local render = v.actualTag:getRendered(v, renderBox, parentHl,
                inherit,
                extra)
            local width = render:getWidth()
            local height = render:getHeight()
            render:render()
            local img = lb.box_image_snap(ctx, 0, 0, width, height, 0)
            local posX = 0
            local posY = 0
            if v:hasStyle("left") then
                posX = posX + v:_firstStyleValue("left").computed
            elseif v:hasStyle("right") then
                posX = pr:getWidth() - width -
                    v:_firstStyleValue("right").computed
            end
            if v:hasStyle("top") then
                posY = posY + v:_firstStyleValue("top").computed
            elseif v:hasStyle("bottom") then
                posY = posY + v:_firstStyleValue("bottom").computed
            end
            local actualImage = lb.box_image_clone(pr.ctx, ctx, img)
            table.insert(root.relativeBoxes, {
                image = actualImage,
                -- width = width,
                -- height = height,
                left = posX,
                top = posY,
                z = v:_firstStyleValue("z-index", 0)
            })
            v:_increaseTopBound(posY)
            v:_increaseLeftBound(posX)
            lb.box_context_delete(ctx)
        end
        extra.renderAbsolute = oldRenderAbsolute
    end
    if ast.relativeBoxes ~= nil and #ast.relativeBoxes > 0 then
        table.sort(ast.relativeBoxes, function (l, r)
            return l.z < r.z
        end)
        pr:render()
        for _, data in ipairs(ast.relativeBoxes) do
            lb.box_image_render_over(pr.ctx, data.image, data.left, data.top)
            --     local newWidth = data.left + data.width - box:getOffsetX() + 1
            --     local newHeight = data.top + data.height - box:getOffsetY() + 1
            --     if newWidth > box:getWidth() then
            --         box:setWidth(newWidth)
            --     end
            --     if newHeight > box:getHeight() then
            --         box:setWidth(newHeight)
            --     end
        end
        pr = p.noopPartialRendered()
    end
    for k, _ in pairs(inheritOld) do
        inherit[k] = inheritOld[k]
    end
    flame.pop()
    return pr
end
