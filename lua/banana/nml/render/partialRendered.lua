---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.box'
local b = require("banana.lazyRequire")("banana.box")
---@module 'banana.nml.ast'
local _ast = require("banana.lazyRequire")("banana.nml.ast")
local M = {}
---@class (exact) Banana.Renderer.Surround
---@field left number
---@field right number
---@field top number
---@field bottom number
---@field fillChar? string For borders if they ever happen

---@class (exact) Banana.Renderer.PartialRendered
---@field margin Banana.Renderer.Surround
---@field padding Banana.Renderer.Surround
---@field widthExpansion number
---@field heightExpansion number
---@field center Banana.Box
---@field marginColor? Banana.Highlight
---@field mainColor? Banana.Highlight
---@field renderAlign "left"|"center"|"right"
---@field maxWidth number
local PartialRendered = {}

---@return Banana.Renderer.PartialRendered
function M.emptyPartialRendered()
    ---@type Banana.Renderer.PartialRendered
    local ret = {
        maxWidth = 0,
        renderAlign = "left",
        mainColor = {},
        marginColor = {},
        center = b.Box:new(),
        heightExpansion = 0,
        widthExpansion = 0,
        margin = {
            top    = 0,
            left   = 0,
            right  = 0,
            bottom = 0,
        },
        padding = {
            top    = 0,
            left   = 0,
            right  = 0,
            bottom = 0,
        },

    }
    setmetatable(ret, {
        __index = PartialRendered,
    })
    return ret
end

---@return number
function PartialRendered:getWidth()
    return self.margin.left + self.margin.right
        + self.padding.left + self.padding.right
        + self.widthExpansion + self.center:width()
end

---@return number
function PartialRendered:getHeight()
    return self.margin.top + self.margin.bottom
        + self.padding.top + self.padding.bottom
        + self.heightExpansion + self.center:height()
end

---@param num number
function PartialRendered:expandWidthTo(num)
    self.widthExpansion = num - (self:getWidth() - self.widthExpansion)
end

---@param num number
function PartialRendered:expandHeightTo(num)
    self.heightExpansion = num - (self:getHeight() - self.heightExpansion)
end

---comment
---@param box Banana.Box
---@param pad Banana.Renderer.Surround
---@param color Banana.Highlight
---@return Banana.Box
function PartialRendered:padWith(box, pad, color)
    if pad.top ~= 0 then
        local topBox = b.Box:new(color)
        topBox:expandWidthTo(box:width())
        topBox:expandHeightTo(pad.top)
        topBox:appendBoxBelow(box)
        box = topBox
    end
    if pad.bottom ~= 0 then
        local btmBox = b.Box:new(color)
        btmBox:expandWidthTo(box:width())
        btmBox:expandHeightTo(pad.bottom)
        box:appendBoxBelow(btmBox)
    end
    if pad.left ~= 0 then
        local leftBox = b.Box:new(color)
        leftBox:expandWidthTo(pad.left)
        leftBox:expandHeightTo(box:height())
        leftBox:append(box)
        box = leftBox
    end
    if pad.right ~= 0 then
        local rightBox = b.Box:new(color)
        -- rightBox:appendStr('', nil)
        rightBox:expandWidthTo(pad.right)
        rightBox:expandHeightTo(box:height())
        box:append(rightBox)
    end
    return box
end

---@param clone boolean?
---@return Banana.Box
function PartialRendered:render(clone)
    -- if clone == true then
    --     print("has clone, ignoring")
    --     return b.Box:new(nil)
    -- end
    flame.new("PartialRendered:render")
    clone = clone or false
    if clone then
        if not require("banana.utils.debug").isdev() then
            print("Calling clone in prod?!")
        end
        local new = vim.fn.deepcopy(self)
        setmetatable(new, {
            __index = PartialRendered,
        })
        new.center = self.center:clone()
        flame.pop()
        return new:render()
    end
    local box = self.center
    if clone then
        box = box:clone()
    end
    if self.heightExpansion > 0 then
        local btmBox = b.Box:new(self.mainColor)
        -- btmBox:appendStr('', nil)
        btmBox:expandWidthTo(box:width())
        btmBox:expandHeightTo(self.heightExpansion)
        box:appendBoxBelow(btmBox)
    end
    if self.widthExpansion > 0 then
        local left = b.Box:new(self.mainColor)
        if box:height() == 0 then
            left:expandWidthTo(self.widthExpansion)
        else
            -- left:appendStr('', nil)
            left:expandWidthTo(self.widthExpansion)
            left:expandHeightTo(box:height())
        end
        if self.renderAlign == "right" then
            left:append(box)
            box = left
        elseif self.renderAlign == "left" then
            box:append(left)
        else
            local l = b.Box:new(self.mainColor)
            -- l:appendStr('', nil)
            l:expandWidthTo(math.ceil(self.widthExpansion / 2))
            l:expandHeightTo(box:height())
            local r = b.Box:new(self.mainColor)
            -- r:appendStr('', nil)
            r:expandWidthTo(math.floor(self.widthExpansion / 2))
            r:expandHeightTo(box:height())
            l:append(box)
            l:append(r)
            box = l
        end
    end
    box = self:padWith(box, self.padding, self.mainColor)
    box = self:padWith(box, self.margin, self.marginColor)
    flame.pop()
    return box
end

---@param name string
---@param ast Banana.Ast
---@return boolean
function PartialRendered:applyPad(name, ast)
    flame.new("applyPad")
    local changed = false
    if ast[name][_ast.left].computed ~= 0 then
        self[name].left = ast[name][_ast.left].computed
        changed = true
    end
    if ast[name][_ast.right].computed ~= 0 then
        self[name].right = ast[name][_ast.right].computed
        changed = true
    end
    if ast[name][_ast.top].computed ~= 0 then
        self[name].top = ast[name][_ast.top].computed
        changed = true
    end
    if ast[name][_ast.bottom].computed ~= 0 then
        self[name].bottom = ast[name][_ast.bottom].computed
        changed = true
    end
    flame.pop()
    return changed
end

return M
