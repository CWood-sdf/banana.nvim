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
    return ret
end

---@param left number
---@param right number
---@param top number
---@param bottom number
function PartialRendered:setMargin(left, right, top, bottom)
    lb.box_pr_set_margin(self.ctx, self.pr, left, right, top, bottom)
end

---@param left number
---@param right number
---@param top number
---@param bottom number
function PartialRendered:setPad(left, right, top, bottom)
    lb.box_pr_set_pad(self.ctx, self.pr, left, right, top, bottom)
end

---@param hl number
function PartialRendered:setMainHl(hl)
    lb.box_pr_set_main_hl(self.ctx, self.pr, hl)
end

---@param w number
function PartialRendered:setMaxWidth(w)
    lb.box_pr_set_max_width(self.ctx, self.pr, w)
end

---@param w number
function PartialRendered:setMaxHeight(w)
    lb.box_pr_set_max_height(self.ctx, self.pr, w)
end

---@return Banana.Box2
function PartialRendered:getCursoredBox()
    local id = lb.box_pr_cursored_box(self.ctx, self.pr)
    return box.boxFromId(self.ctx, id)
end

---@return Banana.Box2
function PartialRendered:getBox()
    local id = lb.box_pr_box(self.ctx, self.pr)
    return box.boxFromId(self.ctx, id)
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
end

function PartialRendered:render()
    if self.center == nil then return end
    lb.box_pr_render(self.ctx, self.pr)
end

---@param lineHeight number
---@return boolean
function PartialRendered:renderCursored(lineHeight)
    if self.center == nil then return false end
    return lb.box_pr_render_cursored(self.ctx, self.pr, lineHeight)
end

return M
