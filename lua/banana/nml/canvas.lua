local M = {}
---@module "banana.box"
local box = require "banana.lazyRequire" ("banana.box")
---@module "banana.libbananabox"
local lb = require "banana.lazyRequire" ("banana.libbanana")

---@class Banana.Nml.CanvasContext
---@field ctx number
---@field fillChar string
---@field hlid number?
---@field fillBg string
---@field fillFg string
---@field box Banana.Box
---@field ast Banana.Ast
local Context = {
}

---@param c string
function Context:setFillChar(c)
    self.fillChar = c
end

---@param bg any
function Context:setFillBg(bg)
    if self.fillBg ~= bg then
        self.fillBg = bg
        self.hlid = nil
    end
end

---@param fg any
function Context:setFillFg(fg)
    if self.fillFg ~= fg then
        self.fillFg = fg
        self.hlid = nil
    end
end

---@return number
function Context:_getHlId()
    if self.hlid ~= nil then
        return self.hlid
    end
    local hlid = box.addHighlight(self.ctx, {
        bg = self.fillBg,
        fg = self.fillFg,
    })
    self.hlid = hlid
    return hlid
end

function Context:background()
    local w, h = self:width(), self:height()
    box.wipeContext(self.ctx)
    lb.box_context_wipe(self.ctx)
    self.hlid = nil
    ---@type Banana.Box
    local newBox = box.boxFromCtx(self.ctx, nil)
    newBox:setHlId(self:_getHlId())
    self.box = newBox
    self:resize(w, h)
    self.ast:_requestRender()
end

---Changes the size of the context
---@param w number
---@param h number
function Context:resize(w, h)
    if self:height() ~= h then
        self.box:setHeight(h)
    end
    if self:width() ~= w then
        self.box:setWidth(w)
    end
    self.box:clean()
end

---Draws a rect at the specified top left (x, y) with size {w}x{h}
---@param x number
---@param y number
---@param w number
---@param h number
function Context:rect(x, y, w, h)
    local hlid = self:_getHlId()
    x = math.floor(x)
    y = math.floor(y)
    w = math.floor(w)
    h = math.floor(h)
    if h < 0 then
        y = y + h
        h = -h
    end
    if w < 0 then
        x = x + w
        w = -w
    end
    if y >= self:height() then
        local extra = y - self:height() + 1
        y = self:height() - 1
        w = w - extra
    end
    if y < 0 then
        local extra = math.abs(y)
        y = 0
        h = h - extra
    end
    if x >= self:width() then
        local extra = x - self:width() + 1
        x = self:width() - 1
        w = w - extra
    end
    if x < 0 then
        local extra = math.abs(x)
        x = 0
        w = w - extra
    end
    self.box:overlay(x, y, w, h, self.fillChar, hlid)
    self.ast:_requestRender()
end

-- ---@return Banana.Box
-- function Context:getBox()
--     -- return self.box:clone()
-- end

---@return number
function Context:height()
    return self.box:getHeight()
end

---@return number
function Context:width()
    return self.box:getWidth()
end

---Draws a single character at the
---@param x any
---@param y any
function Context:point(x, y)
    local hlid = self:_getHlId()
    x = math.floor(x)
    y = math.floor(y)
    if y >= self:height() or y < 0 then
        return
    end
    if x >= self:width() or x < 0 then
        return
    end
    self.box:overlay(x, y, 1, 1, self.fillChar, hlid)
    self.ast:_requestRender()
end

---Draws the {str} at ({x}, {y}) with optional {maxWidth}
---@param str string
---@param x number
---@param y number
---@param maxWidth number?
function Context:text(str, x, y, maxWidth)
    local newCtx = lb.box_context_create()

    if y >= self:height() or y < 0 then
        return
    end
    if x >= self:width() or x < 0 then
        return
    end

    local ok, err = pcall(function ()
        local b = box.boxFromCtx(newCtx)
        if maxWidth ~= nil then
            b:setMaxWidth(maxWidth)
        end
        b:setHlId(self:_getHlId())
        b:appendStr(str)
        local w = self:width()
        if x + b:getWidth() > w then
            b:shrinkWidthTo(w - x)
        end
        local h = self:height()
        if y + b:getHeight() > h then
            b:shrinkHeightTo(h - y)
        end

        self.box:renderOver(newCtx, x, y)
        self.box:unsafeSetCursor(0, 0)
    end)

    lb.box_context_delete(newCtx)

    if not ok then
        error(err)
    end
    self.ast:_requestRender()
end

---@param ast Banana.Ast
---@return Banana.Nml.CanvasContext
function M.newContext(ast)
    local c = box.createContext()
    ---@type Banana.Nml.CanvasContext
    local ctx = {
        ctx = c,
        fillChar = " ",
        fillBg = "#ffffff",
        fillFg = "#000000",
        box = box.boxFromCtx(c),
        ast = ast,
    }
    setmetatable(ctx, { __index = Context })
    return ctx
end

return M
