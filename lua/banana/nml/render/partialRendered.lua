---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.box'
local box = require("banana.lazyRequire")("banana.box")
---@module 'banana.libbananabox'
local lb = require("banana.lazyRequire")("banana.libbanana")
local M = {}

---@enum Banana.Renderer.Align
M.Align = {
    left = 0,
    center = 1,
    right = 2,
    noexpand = 3,
}

---@enum Banana.Renderer.RenderType
M.RenderType = {
    inline = 0,
    inlineBlock = 1,
    block = 2,

}

---@class (exact) Banana.Renderer.PartialRendered
---@field ctx number
---@field pr number
---@field trace number?
---@field center Banana.Box?
---@field ast Banana.Ast
---@field mainHl number
---@field postRender fun()[]
local PartialRendered = {}

local PrIndex = flame.wrapClass(PartialRendered, "Partial", false)

---@return Banana.Renderer.PartialRendered
function M.noopPartialRendered()
    local ret = {
    }
    setmetatable(ret, {
        __index = function ()
            return function () end
        end,
    })
    return ret
end

---@param container Banana.Box
---@param ast Banana.Ast
---@return Banana.Renderer.PartialRendered
function M.emptyPartialRendered(container, ast)
    local ctx = container.ctx
    local pr = lb.box_pr_new(ctx, container.boxid)
    ---@type Banana.Renderer.PartialRendered
    local ret = {
        mainHl = 0,
        postRender = {},
        ast = ast,
        ctx = ctx,
        pr = pr,
        center = nil,
    }

    setmetatable(ret, { __index = PrIndex })
    ret:_dump()
    return ret
end

function PartialRendered:_dump()
    -- lb.box_dump_pr_data(self.ctx, self.pr, self)
end

---@param ctx number?
function PartialRendered:setDbgCtx(ctx)
    lb.box_pr_set_dbg_ctx(self.ctx, self.pr, ctx)
end

---@param left number
---@param right number
---@param top number
---@param bottom number
function PartialRendered:setMargin(left, right, top, bottom)
    lb.box_pr_set_margin(self.ctx, self.pr, left, right, top, bottom)
    self:_dump()
end

---@param left number
---@param right number
---@param top number
---@param bottom number
function PartialRendered:setPad(left, right, top, bottom)
    lb.box_pr_set_pad(self.ctx, self.pr, left, right, top, bottom)
    self:_dump()
end

---@param hl number
function PartialRendered:setMainHl(hl)
    self.mainHl = hl
    lb.box_pr_set_main_hl(self.ctx, self.pr, hl)
    self:_dump()
end

---@param w number
---@param force? boolean
function PartialRendered:setMaxWidth(w, force)
    lb.box_pr_set_max_width(self.ctx, self.pr, w, force)
    self:_dump()
end

---@param a Banana.Renderer.Align
function PartialRendered:setVerticalAlign(a)
    lb.box_pr_set_vertical_align(self.ctx, self.pr, a)
    self:_dump()
end

---@param w number
function PartialRendered:setMaxHeight(w)
    lb.box_pr_set_max_height(self.ctx, self.pr, w)
    self:_dump()
end

---@return number
function PartialRendered:getBoundBoxCount()
    return lb.box_pr_get_bound_box_count(self.ctx, self.pr)
end

---@param n number
---@return Banana.Ast.BoundingBox
function PartialRendered:getBoundBox(n)
    return lb.box_pr_get_bound_box(self.ctx, self.pr, n)
end

---@return Banana.Box
function PartialRendered:getBox()
    local id = lb.box_pr_box(self.ctx, self.pr)
    self.center = box.boxFromId(self.ctx, id, self.trace)
    self:_dump()
    return self.center
end

---@return number
function PartialRendered:getMinWidth()
    return lb.box_pr_get_min_width(self.ctx, self.pr)
end

---@return number
function PartialRendered:getWidth()
    return lb.box_pr_get_width(self.ctx, self.pr)
end

---@return number
function PartialRendered:getHeight()
    return lb.box_pr_get_height(self.ctx, self.pr)
end

---@return Banana.Renderer.Align
function PartialRendered:getAlign()
    return lb.box_pr_get_align(self.ctx, self.pr)
end

---@param align Banana.Renderer.Align
function PartialRendered:setAlign(align)
    lb.box_pr_set_align(self.ctx, self.pr, align)
    self:_dump()
end

---@return Banana.Renderer.RenderType
function PartialRendered:getRenderType()
    return lb.box_pr_get_render_type(self.ctx, self.pr)
end

---@param renderType Banana.Renderer.RenderType
function PartialRendered:setRenderType(renderType)
    lb.box_pr_set_render_type(self.ctx, self.pr, renderType)
    self:_dump()
end

---@param lineHeight ?number
---@return number
function PartialRendered:render(lineHeight)
    if self.center == nil then error("Calling render when no box created") end
    if self.trace ~= nil then
        lb.box_context_dump_to(self.ctx, self.trace, "render pre")
    end
    flame.new("box_pr_render")
    local ret = lb.box_pr_render(self.ctx, self.pr, lineHeight)
    if self.trace ~= nil then
        lb.box_context_dump_to(self.ctx, self.trace, "render post")
        lb.box_context_dump_to(self.ctx, self.trace, "render post")
    end
    flame.pop()

    local boundBox = self:getBoundBox(1)
    self.ast.boundBox = boundBox

    for _, fn in ipairs(self.postRender) do
        fn()
    end

    self:_dump()
    self:destroy()
    return ret
end

function PartialRendered:destroy()
    lb.box_pr_deinit(self.ctx, self.pr)
    self.center:destroy()
end

---@param lineHeight number
---@return boolean
function PartialRendered:renderCursored(lineHeight)
    if self.center == nil then return false end
    if self.trace ~= nil then
        lb.box_context_dump_to(self.ctx, self.trace, "renderCursored pre")
    end
    local ret = lb.box_pr_render_cursored(self.ctx, self.pr, lineHeight)
    if self.trace ~= nil then
        lb.box_context_dump_to(self.ctx, self.trace, "renderCursored post")
    end
    self:_dump()
    return ret
end

return M
