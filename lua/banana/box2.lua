---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
---@module 'banana.utils.string'
local _str = require("banana.lazyRequire")("banana.utils.string")
---@module 'banana.libbananabox'
local lb = require("banana.lazyRequire")("banana.libbanana")
-- ---@module 'banana.utils.string'
-- local _str = require("banana.lazyRequire")("banana.utils.string")

local M = {}

local hls = {}

---@return number
function M.createContext()
    local ctx = lb.box_context_create()
    hls[ctx + 1] = {}
    return ctx
end

---@param ctx number
function M.deleteContext(ctx)
    lb.box_context_delete(ctx)
end

---@param ctx number
---@param hl Banana.Highlight
---@return number
function M.addHighlight(ctx, hl)
    hls[ctx + 1] = hl
    return #hls
end

---@class (exact) Banana.Box2
---@field ctx integer
---@field boxid integer
---@field hlgroup integer
local Box = {
    ctx = 0,
    boxid = 0,
    hlgroup = 0,
}

---@param ctx number
---@return Banana.Box2
function M.boxFromCtx(ctx)
    local boxid = lb.box_new_from_context(ctx, 0)
    ---@type Banana.Box2
    ---@diagnostic disable-next-line: missing-fields
    local ret = {
        ctx = ctx,
        boxid = boxid,
        hlgroup = 0,
    }
    setmetatable(ret, { __index = Box })
    return ret
end

---@param ctx number
---@param id number
---@return Banana.Box2
function M.boxFromId(ctx, id)
    ---@type Banana.Box2
    local box = {
        ctx = ctx,
        boxid = id,
        hlgroup = lb.box_get_hl(ctx, id)
    }
    setmetatable(box, Box)
    return box
end

---@return Banana.Box2
function Box:newAtOffset(x, y)
    local boxid = lb.box_new_from_offset(self.ctx, self.boxid, x, y)
    ---@type Banana.Box2
    ---@diagnostic disable-next-line: missing-fields
    local ret = {
        ctx = self.ctx,
        boxid = boxid,
        hlgroupid = self.hlgroupid,
    }
    setmetatable(ret, { __index = Box })
    return ret
end

function Box:newCursored()
    local boxid = lb.box_new_cursored(self.ctx, self.boxid)
    ---@type Banana.Box2
    ---@diagnostic disable-next-line: missing-fields
    local ret = {
        ctx = self.ctx,
        boxid = boxid,
        hlgroupid = self.hlgroupid,
    }
    setmetatable(ret, { __index = Box })
    return ret
end

---@return Banana.Box2
function Box:newToRight()
    local boxid = lb.box_new_right_from(self.ctx, self.boxid)
    ---@type Banana.Box2
    ---@diagnostic disable-next-line: missing-fields
    local ret = {
        ctx = self.ctx,
        boxid = boxid,
        hlgroupid = self.hlgroupid,
    }
    setmetatable(ret, { __index = Box })
    return ret
end

-- Box.__index = flame.wrapClass(Box, "Box", false)
-- Box.__mode = "kv"

-- function Box:getLines()
--     return self.lines
-- end

---@param other Banana.Box2
function Box:updateCursorFrom(other)
    lb.box_update_cursor_from(self.ctx, self.boxid, other.boxid)
end

---@param width number
function Box:setMaxWidth(width)
    lb.box_set_max_width(self.ctx, self.boxid, width)
end

function Box:insertGradientMarker()
    -- TODO: Need this later

    -- if self.hlgroup == nil then
    --     return
    -- end
    --
    -- if type(self.hlgroup.fg) == "table" or type(self.hlgroup.bg) == "table" then
    --     for _, v in ipairs(self.lines) do
    --         table.insert(v, 1, word("", self.hlgroup))
    --     end
    -- end
end

function Box:setGradientSize()
    -- TODO: need later

    -- if self.hlgroup == nil then
    --     return
    -- end
    -- if type(self.hlgroup.fg) == "table" then
    --     ---@diagnostic disable-next-line: param-type-mismatch
    --     self.hlgroup.fg:setSize(self._width, self:height())
    -- end
    -- if type(self.hlgroup.bg) == "table" then
    --     ---@diagnostic disable-next-line: param-type-mismatch
    --     self.hlgroup.bg:setSize(self._width, self:height())
    -- end
end

---@param width number
function Box:shrinkWidthTo(width)
    lb.box_shrink_width_to(self.ctx, self.boxid, width)
end

---@param width number
function Box:setWidth(width)
    lb.box_set_width(self.ctx, self.boxid, width)
end

---@param width number
function Box:shiftRightBy(width)
    lb.box_shift_right_by(self.ctx, self.boxid, width)
end

---@param width number
function Box:expandWidthTo(width)
    lb.box_expand_width_to(self.ctx, self.boxid, width)
end

-- ---@return Banana.Box2
-- function Box:clone()
--     local b = Box:new(self.hlgroup)
--     for _, v in ipairs(self.lines) do
--         table.insert(b.lines, cloneLine(v))
--     end
--     b._width = self._width
--     return b
-- end

---@return number
function Box:height()
    return lb.box_get_height(self.ctx, self.boxid)
end

---@return integer
function Box:width()
    return lb.box_get_width(self.ctx, self.boxid)
end

---@param height number
function Box:expandHeightTo(height)
    lb.box_expand_height_to(self.ctx, self.boxid, height)
end

---@param height number
function Box:shrinkHeightTo(height)
    lb.box_shrink_height_to(self.ctx, self.boxid, height)
end

---@param height number
function Box:setHeight(height)
    lb.box_set_height(self.ctx, self.boxid, height)
end

---@param hl Banana.Highlight
function Box:setHl(hl)
    lb.box_set_hl(self.ctx, self.boxid, M.addHighlight(self.ctx, hl))
end

function Box:clean()
    lb.box_clean(self.ctx, self.boxid)
end

---Appends string to the right
---@param str string
function Box:appendStr(str)
    lb.box_append_str(self.ctx, self.boxid, str)
end

---@param str string
---@param style number
function Box:appendWord(str, style)
    lb.box_append_word(self.ctx, self.boxid, str, style)
end

---@param expectedBg string?
function Box:stripRightSpace(expectedBg)
    lb.box_strip_right_space(self.ctx, 0)
end

---Renders a box over another box (essentially position:absolute)
---@param other number
---@param left number
---@param top number
function Box:renderOver(other, left, top)
    lb.box_render_over(self.ctx, self.boxid, other, left, top)
end

return M
