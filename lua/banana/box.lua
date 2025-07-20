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

---A global list of all the highlights
---@type (Banana.Highlight?)[]
local hls = {}

---The highlights owned by a context
---@type number[][]
local contextHls = {}

---@type { [Banana.Highlight]: number }[]
local hlsMap = {}

---@return number
function M.createContext()
    local ctx = lb.box_context_create()
    hlsMap[ctx + 1] = {}
    contextHls[ctx + 1] = {}
    return ctx
end

---@param ctx number
function M.deleteContext(ctx)
    for _, hl in ipairs(contextHls[ctx + 1]) do
        hls[hl] = nil
    end
    contextHls[ctx + 1] = {}
    hlsMap[ctx + 1] = {}
end

function M.wipeContext(ctx)
    M.deleteContext(ctx)
end

---@param ctx number
---@param hl Banana.Highlight?
---@return number
function M.addHighlight(ctx, hl)
    if hl == nil then
        return 0
    end
    flame.new("addHighlight")
    local fg = hl.fg
    local bg = hl.bg
    if type(fg) == "table" then
        hl.fg = tostring(fg)
    end
    if type(bg) == "table" then
        hl.bg = tostring(bg)
    end
    local str = vim.inspect(hl)
    hl.fg = fg
    hl.bg = bg
    if hlsMap[ctx + 1][str] ~= nil then
        flame.pop()
        return hlsMap[ctx + 1][str]
    end
    local id = #hls + 1
    hls[#hls+1] = hl
    hlsMap[ctx + 1][str] = id
    table.insert(contextHls[ctx + 1], id)
    flame.pop()
    return id
end

---@param hl number
---@return Banana.Highlight?
function M.getHl(hl)
    return hls[hl]
end

---@class (exact) Banana.Box
---@field ctx integer
---@field boxid integer
---@field hlgroup integer
---@field trace number?
local Box = {
    ctx = 0,
    boxid = 0,
    hlgroup = 0,
}
local Box__index = Box -- flame.wrapClass(Box, "Box", true)
---@param ctx number
---@param trace number?
---@return Banana.Box
function M.boxFromCtx(ctx, trace)
    local boxid = lb.box_new_from_context(ctx, 0)
    ---@type Banana.Box
    local ret = {
        ctx = ctx,
        boxid = boxid,
        hlgroup = 0,
        trace = trace,
    }
    setmetatable(ret, { __index = Box__index })
    ret:_dumpToSelf()
    return ret
end

---@param ctx number
---@param id number
---@param trace number?
---@return Banana.Box
function M.boxFromId(ctx, id, trace)
    ---@type Banana.Box
    local box = {
        ctx = ctx,
        boxid = id,
        hlgroup = lb.box_get_hl(ctx, id),
        trace = trace,
    }
    setmetatable(box, { __index = Box__index })
    box:_dumpToSelf()
    return box
end

function Box:_dumpToSelf()
    -- lb.box_dump_box_data(self.ctx, self.boxid, self)
end

---@return Banana.Box
function Box:newAtOffset(x, y)
    local boxid = lb.box_new_from_offset(self.ctx, self.boxid, x, y)
    ---@type Banana.Box
    local ret = {
        ctx = self.ctx,
        boxid = boxid,
        hlgroup = self.hlgroup,
        trace = self.trace,
    }
    setmetatable(ret, { __index = Box__index })
    ret:_dumpToSelf()
    return ret
end

function Box:destroy()
    lb.box_destroy(self.ctx, self.boxid)
end

function Box:newCursored()
    local boxid = lb.box_new_cursored(self.ctx, self.boxid)
    ---@type Banana.Box
    local ret = {
        ctx = self.ctx,
        boxid = boxid,
        hlgroup = self.hlgroup,
        trace = self.trace,
    }
    setmetatable(ret, { __index = Box__index })
    ret:_dumpToSelf()
    return ret
end

---@return Banana.Box
function Box:newBelow()
    local boxid = lb.box_new_below_from(self.ctx, self.boxid)
    ---@type Banana.Box
    local ret = {
        ctx = self.ctx,
        boxid = boxid,
        hlgroup = self.hlgroup,
        trace = self.trace,
    }
    setmetatable(ret, { __index = Box__index })
    ret:_dumpToSelf()
    return ret
end

---@return Banana.Box
function Box:newToRight()
    local boxid = lb.box_new_right_from(self.ctx, self.boxid)
    ---@type Banana.Box
    local ret = {
        ctx = self.ctx,
        boxid = boxid,
        hlgroup = self.hlgroup,
        trace = self.trace,
    }
    setmetatable(ret, { __index = Box__index })
    ret:_dumpToSelf()
    return ret
end

---@param other Banana.Box
function Box:updateCursorFrom(other)
    lb.box_update_cursor_from(self.ctx, self.boxid, other.boxid)
    self:_dumpToSelf()
end

---@param left number
---@param top number
function Box:unsafeIncreaseOffsetBy(left, top)
    lb.box_unsafe_increase_offset(self.ctx, self.boxid, left, top)
    self:_dumpToSelf()
end

---@return number
function Box:getOffsetY()
    return lb.box_get_offset_y(self.ctx, self.boxid)
end

---@return number
function Box:getOffsetX()
    return lb.box_get_offset_x(self.ctx, self.boxid)
end

---@return number
function Box:getCursorY()
    return lb.box_get_cursor_y(self.ctx, self.boxid)
end

---@return number
function Box:getCursorX()
    return lb.box_get_cursor_x(self.ctx, self.boxid)
end

---@param width number
function Box:unsafeSetWidth(width)
    lb.box_unsafe_set_width(self.ctx, self.boxid, width)
    self:_dumpToSelf()
end

---@param left number
---@param top number
function Box:unsafeSetCursor(left, top)
    lb.box_unsafe_set_cursor(self.ctx, self.boxid, left, top)
    self:_dumpToSelf()
end

---@param left number
---@param top number
function Box:unsafeIncreaseCursorBy(left, top)
    lb.box_unsafe_increase_cursor(self.ctx, self.boxid, left, top)
    self:_dumpToSelf()
end

---@param other Banana.Box
function Box:putCursorBelow(other)
    lb.box_put_cursor_below(self.ctx, self.boxid, other.boxid)
    other:_dumpToSelf()
    self:_dumpToSelf()
end

---@param width number
function Box:setMaxWidth(width)
    lb.box_set_max_width(self.ctx, self.boxid, width)
    self:_dumpToSelf()
end

function Box:setMaxHeight(height)
    lb.box_set_max_height(self.ctx, self.boxid, height)
    self:_dumpToSelf()
end

function Box:getMaxWidth()
    return lb.box_get_max_width(self.ctx, self.boxid)
end

function Box:getMaxHeight()
    return lb.box_get_max_height(self.ctx, self.boxid)
end

---@param width number
function Box:shrinkWidthTo(width)
    lb.box_shrink_width_to(self.ctx, self.boxid, width)
    self:_dumpToSelf()
end

---@param width number
function Box:setWidth(width)
    lb.box_set_width(self.ctx, self.boxid, width)
    self:_dumpToSelf()
end

---@param width number
function Box:shiftRightBy(width)
    lb.box_shift_right_by(self.ctx, self.boxid, width)
    self:_dumpToSelf()
end

---@param width number
function Box:expandWidthTo(width)
    lb.box_expand_width_to(self.ctx, self.boxid, width)
    self:_dumpToSelf()
end

---@param x number
---@param y number
---@param w number
---@param h number
---@param char string
---@param style number
function Box:overlay(x, y, w, h, char, style)
    lb.box_overlay(self.ctx, self.boxid, x, y, w, h, char, style)
    self:_dumpToSelf()
end

---@return number
function Box:getHeight()
    local ret = lb.box_get_height(self.ctx, self.boxid)
    return ret
end

---@return integer
function Box:getWidth()
    local ret = lb.box_get_width(self.ctx, self.boxid)
    return ret
end

---@param height number
function Box:expandHeightTo(height)
    lb.box_expand_height_to(self.ctx, self.boxid, height)
    self:_dumpToSelf()
end

---@param height number
function Box:shrinkHeightTo(height)
    lb.box_shrink_height_to(self.ctx, self.boxid, height)
    self:_dumpToSelf()
end

---@param height number
function Box:setHeight(height)
    lb.box_set_height(self.ctx, self.boxid, height)
    self:_dumpToSelf()
end

---@param hl number
function Box:setHlId(hl)
    lb.box_set_hl(self.ctx, self.boxid, hl)
    self:_dumpToSelf()
end

---@param hl Banana.Highlight
function Box:setHl(hl)
    local hlg = M.addHighlight(self.ctx, hl)
    lb.box_set_hl(self.ctx, self.boxid, hlg)
    self.hlgroup = hlg
    self:_dumpToSelf()
end

---@return number
function Box:getHl()
    return self.hlgroup
end

function Box:clean()
    lb.box_clean(self.ctx, self.boxid)
    self:_dumpToSelf()
end

---Appends string to the right
---@param str string
function Box:appendStr(str)
    lb.box_append_str(self.ctx, self.boxid, str)
    self:_dumpToSelf()
end

---@param str string
---@param style number
function Box:appendWord(str, style)
    lb.box_append_word(self.ctx, self.boxid, str, style)
    self:_dumpToSelf()
end

---Renders a context over this box
---@param other number
---@param left number
---@param top number
function Box:renderOver(other, left, top)
    lb.box_render_over(self.ctx, self.boxid, other, left, top)
    self:_dumpToSelf()
end

return M
