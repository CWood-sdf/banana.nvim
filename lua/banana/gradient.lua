local M = {}
local log = require("banana.utils.log")
---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")

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
---@field angleOffset? number
---@field sideTarget? "left"|"right"|"top"|"bottom"
---@field cornerTarget? "left"|"right"|"top"|"bottom"
---@field distanceOffset number? for polar coord offsets in radial-gradient
---@field repeating boolean
---@field line? number
---@field col? number
---@field owned boolean
---@field parent? Banana.Gradient
---@field children? Banana.Gradient
---@field childI? number
local Gradient = {}

---@class (exact) Banana.Highlight: vim.api.keyset.highlight
---@field fg? string|Banana.Gradient
---@field bg? string|Banana.Gradient
---@field __name? string

function Gradient:startLineRender()
    self.col = 0
end

---Skips the next n chars (for words not gradientized)
---@param count number
function Gradient:skipNext(count)
    self.col = self.col + count
end

function Gradient:nextLine()
    self.line = self.line + 1
    self.col = 0
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
function Gradient:_getRadialColor()
    flame.new("Gradient:_getRadialColor")
    local centerX = (self.width) / 2
    local centerY = (self.height)
    local radius = math.sqrt(centerY * centerY + centerX * centerX)

    local col = self.col + 0.5
    local line = self.line * 2 + 0.5

    local offX = centerX - col
    local offY = centerY - line

    local dist = math.sqrt(offY * offY + offX * offX)

    local mult = 1 - dist / radius


    local colorLeft = self.colors[1]
    local colorRight = self.colors[2]
    local r = math.max(
        math.floor(colorLeft.r + (colorRight.r - colorLeft.r) * mult), 0)
    local g = math.max(
        math.floor(colorLeft.g + (colorRight.g - colorLeft.g) * mult), 0)
    local b = math.max(
        math.floor(colorLeft.b + (colorRight.b - colorLeft.b) * mult), 0)
    local ret = string.format("#%06x", r * 256 * 256 + g * 256 + b)
    flame.pop()
    -- log.fatal(mult .. " #0000" .. b)
    return ret
end

---@return string
function Gradient:_getLinearColor()
    local col = self.col
    local line = self.line
    flame.new("Gradient:_getLinearColor")
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
    -- widthToCorner = widthToCorner - sign(widthToCorner) * 0.5
    local heightToCorner = sign((corner - 1) % 4 - 1.5) * centerY
    -- heightToCorner = heightToCorner - sign(heightToCorner) * 0.5

    if self.col == 2 and self.line == 0 and self.dbgthing == true then
        print(widthToCorner .. ", " .. heightToCorner)
    end

    local angleToCorner = math.atan2(widthToCorner, heightToCorner) * 180 /
        math.pi

    local internalAngle = angleToCorner - ang

    local distToCorner = math.sqrt(widthToCorner * widthToCorner +
        heightToCorner * heightToCorner)

    -- we can form a right triangle to corner (the hypotenuse is distToCorner)
    -- long side is that gradient line len we want

    -- cos = adj / hyp (want adj)

    local halfGradLine = math.cos(internalAngle * math.pi / 180) * distToCorner

    local gradX = -math.abs(widthToCorner) + col
    local gradY = math.abs(heightToCorner) - line

    -- |proj u onto v| = u dot v / |v|

    local gradLineX = math.sin(ang * math.pi / 180) * halfGradLine
    local gradLineY = math.cos(ang * math.pi / 180) * halfGradLine

    local len = (gradX * gradLineX + gradY * gradLineY) / halfGradLine

    local mult = (-len + halfGradLine) / (2 * halfGradLine)
    -- if self.col == 2 and self.dbgthing == true then
    --     print(mult)
    -- end

    -- if mult > 1 or mult < 0 then
    --     print(mult)
    -- end

    local colorLeft = self.colors[1]
    local colorRight = self.colors[2]

    local r = math.max(
        math.floor(colorLeft.r + (colorRight.r - colorLeft.r) * mult), 0)
    local g = math.max(
        math.floor(colorLeft.g + (colorRight.g - colorLeft.g) * mult), 0)
    local b = math.max(
        math.floor(colorLeft.b + (colorRight.b - colorLeft.b) * mult), 0)

    -- if math.abs(mult - 0.5) < 0.01 then
    --     r = 0
    --     g = 0
    --     b = 0
    -- end
    -- if math.abs(mult) < 0.01 then
    --     r = 0
    --     g = 255
    --     b = 0
    -- end
    -- if math.abs(mult - 1) < 0.01 then
    --     r = 0
    --     g = 255
    --     b = 0
    -- end

    -- so color spaces?? might just interpolate in RGB for now

    local ret = string.format("#%06x", r * 256 * 256 + g * 256 + b)
    -- log.fatal(mult .. " #0000" .. b)
    flame.pop()
    return ret
end

---Returns the highlight color, and also whether end of line has been reached
---@return string
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


    local ret
    if self.type == "linear" then
        ret = self:_getLinearColor()
    elseif self.type == "radial" then
        ret = self:_getRadialColor()
    end
    self.col = self.col + 1
    -- local drop = self.col > self.width
    -- if drop then
    --     self.col  = 0
    --     self.line = self.line + 1
    -- end
    return ret
end

---@param w number
---@param h number
function Gradient:setSize(w, h)
    self.col = 0
    self.line = 0
    self.width = w
    self.height = h
    local side = nil
    if self.sideTarget == "top" then
        side = 0
    elseif self.sideTarget == "right" then
        side = 1
    elseif self.sideTarget == "bottom" then
        side = 2
    elseif self.sideTarget == "left" then
        side = 3
    end
    local corner = nil
    if self.cornerTarget == "top" then
        corner = 0
    elseif self.cornerTarget == "right" then
        corner = 1
    elseif self.cornerTarget == "bottom" then
        corner = 2
    elseif self.cornerTarget == "left" then
        corner = 3
    end

    if side ~= nil and corner ~= nil then
        if side % 2 == corner % 2 then
            log.throw(
                "Corner target must target an actual corner (eg top left, and not top bottom)")
        end

        local centerX = (self.width - 1) / 2
        local centerY = (self.height - 1) / 2

        -- angle 0 = ▲
        -- angle 90 = ►

        --   3─────0────0
        -- 3-│          │ - 1
        --   2─────2────1
        --
        if math.abs(corner - side) == 1 then
            corner = math.floor((corner + side) / 2)
        else
            -- i think this is the only remaining case
            corner = 3
        end

        local widthToCorner = -sign(corner - 1) * centerX
        -- widthToCorner = widthToCorner - sign(widthToCorner) * 0.5
        local heightToCorner = sign((corner - 1) % 4 - 1.5) * centerY
        self.angleOffset = math.atan2(heightToCorner, widthToCorner) * 180 /
            math.pi
    elseif side ~= nil then
        self.dbgthing = true
        self.angleOffset = 90 * side
    end
end

---@param col1 Banana.Color
---@param col2 Banana.Color
---@return Banana.Gradient
function M.linearGradient(col1, col2)
    ---@type Banana.Gradient
    local gradient = {
        owned = false,
        repeating = false,
        type = "linear",
        colors = { col1, col2 },
        angleOffset = 30,
    }
    setmetatable(gradient, { __index = Gradient })
    return gradient
end

---@param col1 Banana.Color
---@param col2 Banana.Color
---@return Banana.Gradient
function M.radialGradient(col1, col2)
    ---@type Banana.Gradient
    local gradient = {
        owned = false,
        repeating = false,
        type = "radial",
        colors = { col1, col2 },
        angleOffset = 0,
    }
    setmetatable(gradient, { __index = Gradient })
    return gradient
end

return M
