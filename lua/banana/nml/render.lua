---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
local M = {}
---@module 'banana.nml.tag'
local _tag = require("banana.lazyRequire")("banana.nml.tag")

---@class (exact) Banana.Renderer.InheritedProperties
---@field text_align string
---@field position "static"|"absolute"|"sticky"|"relative"
---@field min_size boolean
---@field list_style_type string

---@class (exact) Banana.Renderer.InitialProperties: Banana.Renderer.InheritedProperties
---@field flex_shrink number
---@field flex_wrap "nowrap"|"wrap"

---@alias Banana.RenderRet Banana.Box

---@class (exact) Banana.Renderer.ExtraInfo
---@field box Banana.Box?
---@field trace Banana.Box
---@field debug boolean
---@field useAllHeight boolean
---@field isRealRender boolean
---@field componentStack Banana.Ast[]

---@alias Banana.Renderer fun(self: Banana.TagInfo, ast: Banana.Ast, parentHl: Banana.Highlight?, parentWidth: number, parentHeight: number, startX: number, startY: number, inherit: Banana.Renderer.InheritedProperties, extra: Banana.Renderer.ExtraInfo): Banana.RenderRet


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
    local gr = require("banana.nml.render.grid")
    return gr.render(ast, parentHl, parentWidth, parentHeight, startX,
        startY, inherit, extra)
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
    local fr = require("banana.nml.render.flex")
    return fr(ast, parentHl, parentWidth, parentHeight, startX,
        startY, inherit, extra)
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
    local br = require("banana.nml.render.block")
    return br(ast, parentHl, i, parentWidth, parentHeight, startX, startY,
        inherit, extra_)
end

---@param ast Banana.Ast
---@param parentHl Banana.Highlight?
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return Banana.Box
function TagInfo:renderComponent(ast, parentHl, parentWidth, parentHeight,
                                 startX, startY, inherit, extra)
    flame.new("TagInfo:renderComponent")
    ast:_tryMountComponent()
    table.insert(extra.componentStack, ast)

    ast.componentTree:_resolveUnits(parentWidth, parentHeight, {})
    local ret = ast.componentTree.actualTag:getRendered(ast.componentTree,
        parentHl,
        parentWidth,
        parentHeight, startX, startY, inherit, extra)
    table.remove(extra.componentStack, #extra.componentStack)
    flame.pop()
    return ret:render()
end

M.TagInfo = TagInfo

return M
