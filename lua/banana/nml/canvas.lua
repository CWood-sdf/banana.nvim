local M = {}
---@module "banana.box"
local box = require "banana.lazyRequire" ("banana.box")
---@class Banana.Nml.CanvasContext
---@field fillChar string
---@field fillBg string
---@field fillFg string
---@field box Banana.Box
---@field ast Banana.Ast
local Context = {
}

function Context:background()
    local newBox = box.Box:new({
        bg = self.fillBg,
        fg = self.fillFg,
    }, self.fillChar)
    local w, h = self:width(), self:height()
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
end

---Draws a rect at the specified top left (x, y) with size {w}x{h}
---@param x number
---@param y number
---@param w number
---@param h number
function Context:rect(x, y, w, h)
    local overlay = box.Box:new({
        bg = self.fillBg,
        fg = self.fillFg,
    }, self.fillChar)
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
    overlay:expandHeightTo(math.min(h, self:height() - y))
    overlay:expandWidthTo(math.min(w, self:width() - x))
    self.box:renderOver(overlay, x, y)
    self.ast:_requestRender()
end

---@return Banana.Box
function Context:getBox()
    return self.box:clone()
end

---@return number
function Context:height()
    return self.box:height()
end

---@return number
function Context:width()
    return self.box:width()
end

---Draws a single character at the
---@param x any
---@param y any
function Context:point(x, y)
    local overlay = box.Box:new({
        bg = self.fillBg,
        fg = self.fillFg,
    }, self.fillChar)
    x = math.floor(x)
    y = math.floor(y)
    if y >= self:height() or y < 0 then
        return
    end
    if x >= self:width() or x < 0 then
        return
    end
    overlay:expandHeightTo(1)
    overlay:expandWidthTo(1)
    self.box:renderOver(overlay, x, y)
    self.ast:_requestRender()
end

---Draws the {str} at ({x}, {y}) with optional {maxWidth}
---@param str string
---@param x number
---@param y number
---@param maxWidth number?
function Context:text(str, x, y, maxWidth)

end

---@param ast Banana.Ast
---@return Banana.Nml.CanvasContext
function M.newContext(ast)
    ---@type Banana.Nml.CanvasContext
    ---@diagnostic disable-next-line: missing-fields
    local ctx = {
        fillChar = " ",
        fillBg = "#ffffff",
        fillFg = "#000000",
        box = box.Box:new({ bg = "#ffffff" }),
        ast = ast,
    }
    setmetatable(ctx, { __index = Context })
    return ctx
end

return M
