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

---@type Banana.Highlight[][]
local hls = {}

---@type { [Banana.Highlight]: number }[]
local hlsMap = {}

---@return number
function M.createContext()
    local ctx = lb.box_context_create()
    hls[ctx + 1] = {}
    hlsMap[ctx + 1] = {}
    return ctx
end

---@param ctx number
function M.deleteContext(ctx)
    hls[ctx + 1] = {}
    hlsMap[ctx + 1] = {}
end

function M.wipeContext(ctx)
    hls[ctx + 1] = {}
    hlsMap[ctx + 1] = {}
end

---@param ctx number
---@param hl Banana.Highlight?
---@return number
function M.addHighlight(ctx, hl)
    if hl == nil then
        return 0
    end
    if hlsMap[ctx + 1][hl] ~= nil then
        return hlsMap[ctx + 1][hl]
    end
    -- if #hls == 0 and hl.bg == "red" then
    table.insert(hls[ctx + 1], hl)
    hlsMap[ctx + 1][hl] = #hls[ctx + 1]
    -- end
    return #hls[ctx + 1]
end

---@return Banana.Highlight?
function M.getHl(ctx, hl)
    return hls[ctx + 1][hl]
end

---@class (exact) Banana.Box
---@field ctx integer
---@field boxid integer
---@field private hlgroup integer
---@field trace number?
local Box = {
    ctx = 0,
    boxid = 0,
    hlgroup = 0,
}
local Box__index = flame.wrapClass(Box, "Box", false)
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
    lb.box_dump_box_data(self.ctx, self.boxid, self)
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

-- Box.__index = flame.wrapClass(Box, "Box", false)
-- Box.__mode = "kv"

-- function Box:getLines()
--     return self.lines
-- end

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
    log.throw("yoo do this")
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
    log.throw("yoo do this")
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

-- ---@return Banana.Box
-- function Box:clone()
--     local b = Box:new(self.hlgroup)
--     for _, v in ipairs(self.lines) do
--         table.insert(b.lines, cloneLine(v))
--     end
--     b._width = self._width
--     return b
-- end

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
    if self.trace ~= nil then
        lb.box_context_dump_to(self.ctx, self.trace, "appendStr pre")
    end
    lb.box_append_str(self.ctx, self.boxid, str)
    if self.trace ~= nil then
        lb.box_context_dump_to(self.ctx, self.trace, "appendStr post")
    end
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
