---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
local M = {}
---@module 'banana.nml.tag'
local _tag = require("banana.lazyRequire")("banana.nml.tag")

---@class (exact) Banana.Renderer.InheritedProperties
---@field ["text-align"] string
---@field position "static"|"absolute"|"sticky"|"relative"
---@field ["min-size"] boolean
---@field ["list-style-type"] string

---@class (exact) Banana.Renderer.InitialProperties: Banana.Renderer.InheritedProperties
---@field flex_shrink number
---@field flex_wrap "nowrap"|"wrap"

---@alias Banana.RenderRet Banana.Box

---@class (exact) Banana.Renderer.ExtraInfo
---@field box Banana.Box?
---@field ctx number
---@field trace number?
---@field debug boolean
---@field useAllHeight boolean
---@field isRealRender boolean
---@field componentStack Banana.Ast[]

---@alias Banana.Renderer fun(self: Banana.TagInfo, ast: Banana.Ast, box: Banana.Box2, parentHl: Banana.Highlight?, parentWidth: number, parentHeight: number, startX: number, startY: number, inherit: Banana.Renderer.InheritedProperties, extra: Banana.Renderer.ExtraInfo): Banana.RenderRet


---@class (exact) Banana.TagInfo
---@field name string
---@field formatType Banana.Nml.FormatType
---@field selfClosing boolean
---@field initialProps Banana.Renderer.InitialProperties
---@field render Banana.Renderer
local TagInfo = {
    name = "",
    formatType = _tag.FormatType.Inline,
    selfClosing = false,
    render = function (_) return {} end,
}



---@param ast Banana.Ast
---@param box Banana.Box2
---@param startHl Banana.Highlight?
---@param winWidth number
---@param winHeight number
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return Banana.Box2
function TagInfo:renderRoot(ast, box, startHl, winWidth, winHeight, inherit,
                            extra)
    -- flame.new("renderRoot")
    log.trace("TagInfo:renderRoot")
    local ret = self:render(ast, box, startHl, winWidth, winHeight, 1, 1, inherit,
        extra)
    -- flame.expect("renderRoot")
    -- flame.pop()
    return ret
end

---@param ast Banana.Ast
---@param box Banana.Box2
---@param parentHl Banana.Highlight?
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return Banana.Renderer.PartialRendered2
function TagInfo:getRendered(ast, box, parentHl, parentWidth, parentHeight,
                             startX,
                             startY, inherit, extra)
    log.trace("TagInfo:getRendered " ..
        ast.tag .. "#" .. (ast:getAttribute("id") or ""))
    local main = require("banana.nml.render.main")

    local ret = main(
        self, ast, box, parentHl, parentWidth, parentHeight, startX, startY,
        inherit,
        extra)
    -- flame.expect("getRendered start")
    return ret
end

---Returns an iterator that renders blocks
---@param ast  Banana.Ast
---@param box Banana.Box2
---@param parentHl Banana.Highlight?
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return fun(): integer?, Banana.Box2?, integer?
function TagInfo:blockIter(ast, box, parentHl, parentWidth, parentHeight, startX,
                           startY, inherit, extra)
    local i = 1
    return function ()
        if i > #ast.nodes then
            return nil
        end
        flame.new("TagInfo:blockIter")
        local oldI = i
        local render = nil
        local renderBox = box:newBelow()
        if ast:_firstStyleValue("display") == "flex" then
            -- error("impl flex")
            render = self:renderFlexBlock(
                ast, renderBox, parentHl, parentWidth, parentHeight,
                startX, startY, inherit, extra)
            i = #ast.nodes + 1
        elseif ast:_firstStyleValue("display") == "grid" then
            render = self:renderGridBlock(
                ast, renderBox, parentHl, parentWidth, parentHeight,
                startX, startY, inherit, extra)
            i = #ast.nodes + 1
        else
            render, i = self:renderBlock(
                ast, renderBox, parentHl, i, parentWidth, parentHeight,
                startX, startY, inherit, extra)
        end
        box:putCursorBelow(renderBox)
        startY = startY + render:height()
        renderBox:destroy()
        flame.pop()
        return oldI, render, i - oldI
    end
end

---@param ast Banana.Ast
---@param box Banana.Box2
---@param parentHl Banana.Highlight?
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@param inherit Banana.Renderer.InheritedProperties
---@return Banana.Box2
function TagInfo:renderInlineEl(ast, box, parentHl, parentWidth, parentHeight,
                                startX,
                                startY, inherit, extra)
    ---@type Banana.Box2
    local ret, _ = self:renderBlock(ast, box, ast:_mixHl(parentHl), 1,
        parentWidth,
        parentHeight, startX, startY, inherit,
        extra)
    return ret
end

--- renders an element with display:grid
---@param ast Banana.Ast
---@param box Banana.Box2
---@param parentHl Banana.Highlight?
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return Banana.Box2, integer
function TagInfo:renderGridBlock(ast, box, parentHl, parentWidth, parentHeight,
                                 startX,
                                 startY, inherit, extra)
    local gr = require("banana.nml.render.grid")
    return gr.render(ast, box, parentHl, parentWidth, parentHeight, startX,
        startY, inherit, extra)
end

---Renders everything in a flex block
---@param ast Banana.Ast
---@param box Banana.Box2
---@param parentHl Banana.Highlight?
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return Banana.Box2, integer
function TagInfo:renderFlexBlock(ast, box, parentHl, parentWidth, parentHeight,
                                 startX,
                                 startY, inherit, extra)
    local fr = require("banana.nml.render.flex")
    return fr(ast, box, parentHl, parentWidth, parentHeight, startX,
        startY, inherit, extra)
end

---Renders everything in a block
---@param ast Banana.Ast
---@param box Banana.Box2
---@param parentHl Banana.Highlight?
---@param i integer
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@param inherit Banana.Renderer.InheritedProperties
---@param extra_ Banana.Renderer.ExtraInfo
---@return Banana.Box2, integer
function TagInfo:renderBlock(ast, box, parentHl, i, parentWidth, parentHeight,
                             startX,
                             startY, inherit, extra_)
    local br = require("banana.nml.render.block")
    return br(ast, box, parentHl, i, parentWidth, parentHeight, startX, startY,
        inherit, extra_)
end

---@param ast Banana.Ast
---@param box Banana.Box2
---@param parentHl Banana.Highlight?
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return Banana.Box2
function TagInfo:renderComponent(ast, box, parentHl, parentWidth, parentHeight,
                                 startX, startY, inherit, extra)
    -- flame.new("TagInfo:renderComponent")
    ast:_tryMountComponent()
    extra.componentStack = extra.componentStack or {}
    table.insert(extra.componentStack, ast)

    ast.componentTree:_resolveUnits(parentWidth, parentHeight)
    local ret = ast.componentTree.actualTag:getRendered(ast.componentTree, box,
        parentHl,
        parentWidth,
        parentHeight, startX, startY, inherit, extra)
    table.remove(extra.componentStack, #extra.componentStack)
    -- flame.pop()
    return ret:render()
end

M.TagInfo = TagInfo

return M
