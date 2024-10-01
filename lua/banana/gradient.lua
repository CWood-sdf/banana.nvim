local M = {}
local log = require("banana.utils.log")
---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")

---@class (exact) Banana.Color
---@field r number
---@field g number
---@field b number

---@class (exact) Banana.GradientColorStop: Banana.Color
---@field r number
---@field g number
---@field b number
---@field start? Banana.Ncss.UnitValue
---@field midpoint? Banana.Ncss.UnitValue

---@class (exact) Banana.Gradient
---@field width number?
---@field height number?
---@field type "radial"|"linear"
---@field colors Banana.GradientColorStop[]
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
---@field lenNeeded boolean
---@field private cache number[]
---@field private cacheDirty boolean
local Gradient = {}

---@class (exact) Banana.Highlight: vim.api.keyset.highlight
---@field fg? string|Banana.Gradient
---@field bg? string|Banana.Gradient
---@field __name? string

function Gradient:startLineRender()
    self.col = 0
    self.lenNeeded = self.line == 0
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

---@param v Banana.Ncss.UnitValue?
---@param len number
function Gradient:_resolveUnitStop(v, len)
    if v == nil then return end
    if v.unit == "ch" then
        v.computed = math.max(0, math.min(1, v.value / len))
    elseif v.unit == "%" then
        v.computed = math.max(0, math.min(1, v.value / 100))
    end
    -- return v
end

---@param len number
function Gradient:_setLineLen(len)
    local i = 1
    while i <= #self.colors do
        local v = self.colors[i]

        self:_resolveUnitStop(v.start, len)
        self:_resolveUnitStop(v.midpoint, len)

        local runCount = 0
        while v.start == nil or v.start.unit == "" do
            runCount = runCount + 1
            v        = self.colors[i + runCount]
            if v == nil then
                break
            end
        end

        if runCount > 0 then
            local e = self.colors[i + runCount]
            local endNum = 1
            local startNum = 0
            local atStart = 0
            local atEnd = 0
            if self.colors[i - 1] ~= nil and self.colors[i - 1].start.unit ~= "" then
                atStart = 1
                startNum = self.colors[i - 1].start.computed
            end
            if e ~= nil and e.start.unit ~= "" then
                atEnd = 1
                self:_resolveUnitStop(e.start, len)
                self:_resolveUnitStop(e.midpoint, len)
                endNum = e.start.computed
            end

            local distPer = (endNum - startNum) /
                (runCount - 1 + atStart + atEnd)

            local d = startNum

            if atStart == 0 then
                d = d - distPer
            end

            for j = i, i + runCount - 1 do
                d = d + distPer
                self.colors[j].start = {
                    unit = "",
                    computed = d,
                    value = 0
                }
                self:_resolveUnitStop(self.colors[j].midpoint, len)
            end
        end

        i = i + 1 + runCount
    end
end

---@return number
function Gradient:_getRadialColor()
    flame.new("Gradient:_getRadialColor")
    local col = self.col + 0.5
    local line = self.line * 2 + 0.5
    if self.cacheDirty then
        local centerX = self.width / 2
        local centerY = self.height
        local radius = math.sqrt(centerY * centerY + centerX * centerX)
        if self.lenNeeded then
            self:_setLineLen(radius * 2)
        end


        self.cacheDirty = false
        self.cache[1] = centerX
        self.cache[2] = centerY
        self.cache[3] = radius
    end
    local centerX = self.cache[1]
    local centerY = self.cache[2]
    local radius = self.cache[3]
    local offX = centerX - col
    local offY = centerY - line

    local dist = math.sqrt(offY * offY + offX * offX)
    local mult = 1 - dist / radius

    flame.pop()
    return mult
end

---@return number
function Gradient:_getLinearColor()
    local col = self.col
    local line = self.line
    flame.new("Gradient:_getLinearColor")
    if self.cacheDirty then
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

        -- if self.col == 2 and self.line == 0 and self.dbgthing == true then
        --     print(widthToCorner .. ", " .. heightToCorner)
        -- end

        local angleToCorner = math.atan2(widthToCorner, heightToCorner) * 180 /
            math.pi

        local internalAngle = angleToCorner - ang

        local distToCorner = math.sqrt(widthToCorner * widthToCorner +
            heightToCorner * heightToCorner)

        -- we can form a right triangle to corner (the hypotenuse is distToCorner)
        -- long side is that gradient line len we want

        -- cos = adj / hyp (want adj)

        local halfGradLine = math.cos(internalAngle * math.pi / 180) *
            distToCorner


        -- |proj u onto v| = u dot v / |v|

        local gradLineX = math.sin(ang * math.pi / 180) * halfGradLine
        local gradLineY = math.cos(ang * math.pi / 180) * halfGradLine

        self.cache[1] = -math.abs(widthToCorner)
        self.cache[2] = math.abs(heightToCorner)
        self.cache[3] = gradLineX
        self.cache[4] = gradLineY
        self.cache[5] = halfGradLine
        self.cacheDirty = false

        if self.lenNeeded then
            self:_setLineLen(halfGradLine * 2)
        end
    end
    local widthToCorner = self.cache[1]
    local heightToCorner = self.cache[2]
    local gradLineX = self.cache[3]
    local gradLineY = self.cache[4]
    local halfGradLine = self.cache[5]
    local gradX = widthToCorner + col
    local gradY = heightToCorner - line
    local len = (gradX * gradLineX + gradY * gradLineY) / halfGradLine

    local mult = (-len + halfGradLine) / (2 * halfGradLine)

    flame.pop()
    return mult
end

---@param l Banana.Color
---@param r Banana.Color
---@param m number
---@return string
function Gradient:_lerpColors(l, r, m)
    local red   = (r.r - l.r) * m + l.r
    local green = (r.g - l.g) * m + l.g
    local blue  = (r.b - l.b) * m + l.b

    red         = math.min(math.max(red, 0), 255)
    green       = math.min(math.max(green, 0), 255)
    blue        = math.min(math.max(blue, 0), 255)

    return string.format("#%02x%02x%02x", red, green, blue)
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


    flame.new("Gradient:nextCharColor")
    local mult
    if self.type == "linear" then
        mult = self:_getLinearColor()
    elseif self.type == "radial" then
        mult = self:_getRadialColor()
    end
    mult = 1 - mult
    self.col = self.col + 1

    local i = 1
    local stop = self.colors[1]
    while stop.start.computed < mult do
        i = i + 1
        stop = self.colors[i]
        if stop == nil then break end
    end
    i = i - 1
    stop = self.colors[i]

    if stop == nil then
        return self:_lerpColors(self.colors[i + 1], self.colors[i + 1], 1)
    end

    local next = self.colors[i + 1]

    if next == nil then
        return self:_lerpColors(stop, stop, 1)
    end

    local mp = (stop.start.computed + next.start.computed) / 2
    if stop.midpoint ~= nil then
        ---@diagnostic disable-next-line: param-type-mismatch, cast-local-type
        mp = math.max(math.min(stop.midpoint.computed, next.start.computed),
            stop.start.computed)
    end

    if mult > mp then
        local ret = self:_lerpColors(stop, next,
            (mult - mp) / (2 * (next.start.computed - mp)) + 0.5)
        flame.pop()
        return ret
    end

    local ret = self:_lerpColors(stop, next,
        0.5 - (mp - mult) / (2 * (mp - stop.start.computed)))
    flame.pop()
    return ret
end

---@param w number
---@param h number
function Gradient:setSize(w, h)
    self.cacheDirty = true
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
        local heightToCorner = sign((corner - 1) % 4 - 1.5) * centerY
        self.angleOffset = math.atan2(heightToCorner, widthToCorner) * 180 /
            math.pi
    elseif side ~= nil then
        self.angleOffset = 90 * side
    end
end

---@return Banana.Gradient
function M.linearGradient()
    ---@type Banana.Gradient
    local gradient = {
        cacheDirty = true,
        cache = {},
        lenNeeded = true,
        owned = false,
        repeating = false,
        colors = {},
        type = "linear",
        angleOffset = 30,
    }
    setmetatable(gradient, { __index = Gradient })
    return gradient
end

---@return Banana.Gradient
function M.radialGradient()
    ---@type Banana.Gradient
    local gradient = {
        cacheDirty = true,
        cache = {},
        lenNeeded = true,
        owned = false,
        repeating = false,
        type = "radial",
        colors = {},
        angleOffset = 0,
    }
    setmetatable(gradient, { __index = Gradient })
    return gradient
end

return M
