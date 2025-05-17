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

---@alias Banana.Renderer fun(self: Banana.TagInfo, ast: Banana.Ast, box: Banana.Box, parentHl: Banana.Highlight?, inherit: Banana.Renderer.InheritedProperties, extra: Banana.Renderer.ExtraInfo)


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
    render = function (_) end,
}



---@param ast Banana.Ast
---@param box Banana.Box
---@param startHl Banana.Highlight?
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return Banana.Box
function TagInfo:renderRoot(ast, box, startHl, inherit,
                            extra)
    -- flame.new("renderRoot")
    log.trace("TagInfo:renderRoot")
    local ret = self:render(ast, box, startHl, inherit, extra)
    -- flame.expect("renderRoot")
    -- flame.pop()
    return ret
end

---@param ast Banana.Ast
---@param box Banana.Box
---@param parentHl Banana.Highlight?
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return Banana.Renderer.PartialRendered
function TagInfo:getRendered(ast, box, parentHl, inherit, extra)
    log.trace("TagInfo:getRendered " ..
        ast.tag .. "#" .. (ast:getAttribute("id") or ""))
    local main = require("banana.nml.render.main")

    local ret = main(
        self, ast, box, parentHl,
        inherit,
        extra)
    -- flame.expect("getRendered start")
    return ret
end

---Returns an iterator that renders blocks
---@param ast  Banana.Ast
---@param box Banana.Box
---@param parentHl Banana.Highlight?
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return fun(): integer?, integer?
function TagInfo:blockIter(ast, box, parentHl, inherit, extra)
    local i = 1
    return function ()
        if i > #ast.nodes then
            return nil
        end
        flame.new("TagInfo:blockIter")
        local oldI = i
        local renderBox = box:newBelow()
        if ast:_firstStyleValue("display") == "flex" then
            -- error("impl flex")
            self:renderFlexBlock(ast, renderBox, parentHl, inherit, extra)
            i = #ast.nodes + 1
        elseif ast:_firstStyleValue("display") == "grid" then
            self:renderGridBlock(ast, renderBox, parentHl, inherit,
                extra)
            i = #ast.nodes + 1
        else
            i = self:renderBlock(
                ast, renderBox, parentHl, i,
                inherit, extra)
        end
        box:putCursorBelow(renderBox)
        renderBox:destroy()
        flame.pop()
        return i, i - oldI
    end
end

---@param ast Banana.Ast
---@param box Banana.Box
---@param parentHl Banana.Highlight?
---@param inherit Banana.Renderer.InheritedProperties
function TagInfo:renderInlineEl(ast, box, parentHl, inherit, extra)
    ---@type Banana.Box
    self:renderBlock(ast, box, ast:_mixHl(parentHl), 1, inherit, extra)
end

--- renders an element with display:grid
---@param ast Banana.Ast
---@param box Banana.Box
---@param parentHl Banana.Highlight?
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return integer
function TagInfo:renderGridBlock(ast, box, parentHl, inherit, extra)
    local gr = require("banana.nml.render.grid")
    gr.render(ast, box, parentHl, inherit, extra)
    return #ast.nodes
end

---Renders everything in a flex block
---@param ast Banana.Ast
---@param box Banana.Box
---@param parentHl Banana.Highlight?
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
---@return integer
function TagInfo:renderFlexBlock(ast, box, parentHl, inherit, extra)
    local fr = require("banana.nml.render.flex")
    fr(ast, box, parentHl, inherit, extra)
    return #ast.nodes
end

---Renders everything in a block
---@param ast Banana.Ast
---@param box Banana.Box
---@param parentHl Banana.Highlight?
---@param i integer
---@param inherit Banana.Renderer.InheritedProperties
---@param extra_ Banana.Renderer.ExtraInfo
---@return integer
function TagInfo:renderBlock(ast, box, parentHl, i,
                             inherit, extra_)
    local br = require("banana.nml.render.block")
    local ret = br(ast, box, parentHl, i,
        inherit, extra_)
    return ret
end

---@param ast Banana.Ast
---@param box Banana.Box
---@param parentHl Banana.Highlight?
---@param inherit Banana.Renderer.InheritedProperties
---@param extra Banana.Renderer.ExtraInfo
function TagInfo:renderComponent(ast, box, parentHl,
                                 inherit, extra)
    -- flame.new("TagInfo:renderComponent")
    ast:_tryMountComponent()
    extra.componentStack = extra.componentStack or {}
    table.insert(extra.componentStack, ast)

    ast.componentTree:_resolveUnits(box:getMaxWidth(), box:getMaxHeight())
    ast.componentTree.actualTag:getRendered(ast.componentTree, box,
        parentHl, inherit, extra):render()
    table.remove(extra.componentStack, #extra.componentStack)
    -- flame.pop()
end

M.TagInfo = TagInfo

return M
