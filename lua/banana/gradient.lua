local M = {}
local log = require("banana.utils.log")

---@class (exact) Banana.Color
---@field r number
---@field g number
---@field b number

---@class (exact) Banana.Gradient
---@field width number?
---@field height number?
---@field type "radial"|"linear"
---@field colors Banana.Color[]
---@field borders Banana.Ncss.UnitValue[]?
---@field angleOffset number?
---@field distanceOffset number? for polar coord offsets
---@field repeating boolean
---@field line? number
---@field col? number
local Gradient = {}

---@class (exact) Banana.Highlight: vim.api.keyset.highlight
---@field fg? string|Banana.Gradient
---@field bg? string|Banana.Gradient
---@field __name? string

function Gradient:startLineRender()
    self.col = 0
end

---Skips the next n chars (for words not gradient)
---@param count number
---@return boolean returns true when the gradient can be dropped
function Gradient:skipNext(count)
    self.col = self.col + count
    -- use >= because 0 based
    if self.col >= self.width then
        self.line = self.line + 1
        self.col  = 0
        return true
    end
    return false
end

---@param n number
---@return number
local function sign(n)
    if n < 0 then
        return -1
    else
        return 1
    end
end

---@return string
function Gradient:_getLinearColor()
    -- measure from center of char
    local centerX = (self.width - 1) / 2
    local centerY = (self.height - 1) / 2

    -- angle 0 = ▲
    -- angle 90 = ►

    local ang = self.angleOffset or 0

    while ang < 0 do
        ang = ang + 360
    end
    while ang >= 360 do
        ang = ang - 360
    end

    local corner = math.floor(ang / 90)
    -- 3──────────0
    -- │          │
    -- 2──────────1

    local widthToCorner = -sign(corner - 1.5) * centerX
    local heightToCorner = sign((corner - 2) % 4 - 1.5) * centerY

    local angleToCorner = math.atan2(widthToCorner, heightToCorner) * 180 /
        math.pi

    local internalAngle = angleToCorner - ang

    local distToCorner = math.sqrt(widthToCorner * widthToCorner +
        heightToCorner * heightToCorner)

    -- we can form a right triangle to corner (the hypotenuse is distToCorner)
    -- long side is that gradient line len we want

    -- cos = adj / hyp (want adj)

    local halfGradLine = math.cos(internalAngle * math.pi / 180) * distToCorner

    local gradX = -widthToCorner + self.col
    local gradY = heightToCorner - self.line

    -- |proj u onto v| = u dot v / |v|

    local gradLineX = math.sin(ang * math.pi / 180) * halfGradLine
    local gradLineY = math.cos(ang * math.pi / 180) * halfGradLine

    local len = (gradX * gradLineX + gradY * gradLineY) / halfGradLine

    local mult = (-len + halfGradLine) / (2 * halfGradLine)

    if mult > 1 or mult < 0 then
        print("asdf")
    end

    local colorLeft = self.colors[1]
    local colorRight = self.colors[2]

    local r = math.floor(colorLeft.r + (colorRight.r - colorLeft.r) * mult)
    local g = math.floor(colorLeft.g + (colorRight.g - colorLeft.g) * mult)
    local b = math.floor(colorLeft.b + (colorRight.b - colorLeft.b) * mult)

    -- so color spaces?? might just interpolate in RGB for now

    local ret = string.format("#%06x", r * 256 * 256 + g * 256 + b)
    -- log.fatal(mult .. " #0000" .. b)
    return ret
end

---Returns the highlight color, and also whether end of line has been reached
---@return string, boolean
function Gradient:nextCharColor()
    -- measure from the center of each character prolly (feels easier then
    -- trying to determine farthest corner then measure from that)

    -- for LINEAR gradients:
    --  Determine the gradient axis and gradient line
    --  Gradient line is rotated around the center point
    --  Find distance to that line (dot product?)

    -- for RADIAL gradients:
    --  Determine gradient center (easy bc polar coords)
    --  Determine dist to center point


    local ret = self:_getLinearColor()
    self.col = self.col + 1
    local drop = self.col >= self.width
    if drop then
        self.col  = 0
        self.line = self.line + 1
    end
    return ret, drop
end

---@param w number
---@param h number
function Gradient:setSize(w, h)
    self.col = 0
    self.line = 0
    self.width = w - 1
    self.height = h
end

---@param col1 Banana.Color
---@param col2 Banana.Color
---@return Banana.Gradient
function M.linearGradient(col1, col2)
    ---@type Banana.Gradient
    local gradient = {
        repeating = false,
        type = "linear",
        colors = { col1, col2 },
        angleOffset = 45,
    }
    setmetatable(gradient, { __index = Gradient })
    return gradient
end

return M
