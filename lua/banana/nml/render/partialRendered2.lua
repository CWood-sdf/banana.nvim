---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.box2'
local box = require("banana.lazyRequire")("banana.box2")
---@module 'banana.libbananabox'
local lb = require("banana.lazyRequire")("banana.libbanana")
local M = {}

---@enum Banana.Renderer.Align
M.Align = {
    left = 0,
    center = 1,
    right = 2,
}

---@class (exact) Banana.Renderer.PartialRendered2
---@field ctx number
---@field pr number
---@field trace number?
---@field center Banana.Box2?
local PartialRendered = {}

local PrIndex = flame.wrapClass(PartialRendered, "Partial", true)

---@param container Banana.Box2
---@return Banana.Renderer.PartialRendered2
function M.emptyPartialRendered(container)
    local ctx = container.ctx
    local pr = lb.box_pr_new(ctx, container.boxid)
    ---@type Banana.Renderer.PartialRendered2
    local ret = {
        ctx = ctx,
        pr = pr,
        center = nil,
    }

    setmetatable(ret, { __index = PrIndex })
    ret:_dump()
    return ret
end

function PartialRendered:_dump()
    lb.box_dump_pr_data(self.ctx, self.pr, self)
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
    lb.box_pr_set_main_hl(self.ctx, self.pr, hl)
    self:_dump()
end

---@param w number
function PartialRendered:setMaxWidth(w)
    lb.box_pr_set_max_width(self.ctx, self.pr, w)
    self:_dump()
end

---@param w number
function PartialRendered:setMaxHeight(w)
    lb.box_pr_set_max_height(self.ctx, self.pr, w)
    self:_dump()
end

---@return Banana.Box2
function PartialRendered:getCursoredBox()
    local id = lb.box_pr_cursored_box(self.ctx, self.pr)
    self.center = box.boxFromId(self.ctx, id, self.trace)
    self:_dump()
    return self.center
end

---@return Banana.Box2
function PartialRendered:getBox()
    local id = lb.box_pr_box(self.ctx, self.pr)
    self.center = box.boxFromId(self.ctx, id, self.trace)
    self:_dump()
    return self.center
end

---@return number
function PartialRendered:getWidth()
    return lb.box_pr_get_width(self.ctx, self.pr)
end

---@return number
function PartialRendered:getHeight()
    return lb.box_pr_get_height(self.ctx, self.pr)
end

---@param align Banana.Renderer.Align
function PartialRendered:setAlign(align)
    lb.box_pr_set_align(self.ctx, self.pr, align)
    self:_dump()
end

function PartialRendered:render()
    if self.center == nil then return end
    if self.trace ~= nil then
        lb.box_context_dump_to(self.ctx, self.trace, "render pre")
    end
    lb.box_pr_render(self.ctx, self.pr)
    if self.trace ~= nil then
        lb.box_context_dump_to(self.ctx, self.trace, "render post")
    end
    self:_dump()
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
