---@module "banana.gradient"
local g = require("banana.gradient")

---@param c string
---@return Banana.GradientColorStop
local function parseColorString(c)
    ---@type Banana.GradientColorStop
    return {
        r = tonumber(c:sub(2, 3), 16),
        g = tonumber(c:sub(4, 5), 16),
        b = tonumber(c:sub(6, 7), 16),
    }
end

---@param l string
---@param r string
---@param msg string
local function colMatch(l, r, msg)
    local vl = parseColorString(l)
    local vr = parseColorString(r)
    assert(math.abs(vl.r - vr.r) < 2, msg)
    assert(math.abs(vl.g - vr.g) < 2, msg)
    assert(math.abs(vl.b - vr.b) < 2, msg)
end

---@param grad Banana.Gradient
---@param tlColor Banana.GradientColorStop
---@param brColor Banana.GradientColorStop
local function basicAsserts(grad, tlColor, brColor)
    local ast = {}
    grad:setBounds(0, 1, 5, 5, ast)
    -- grad:startLineRender()
    grad:setPos(0, 0)
    local tl = grad:nextCharColor()
    local expTl = grad:_lerpColors(tlColor, tlColor, 1)
    colMatch(tl, expTl,
        "Could not match top left colors (NOTE: expected '" ..
        expTl .. "' but got '" .. tl .. "')")
    grad:setPos(4, 4)
    local br = grad:nextCharColor()
    local expBr = grad:_lerpColors(brColor, brColor, 1)
    colMatch(br, expBr,
        "Could not match bottom right colors (NOTE: expected '" ..
        expBr .. "' but got '" .. br .. "')")
end

describe("Linear gradient tests", function ()
    it("gradients", function ()
        local grad = g.linearGradient()
        grad.angleOffset = 180
        ---@type Banana.GradientColorStop[]
        local stops = {
            {
                r = 0,
                g = 0,
                b = 255,
            },
            {
                r = 255,
                g = 255,
                b = 0,
            },
        }
        grad.colors = stops

        basicAsserts(grad, stops[1], stops[2])
    end)
    it("gradients at 90", function ()
        local grad = g.linearGradient()
        grad.angleOffset = 180
        ---@type Banana.GradientColorStop[]
        local stops = {
            {
                r = 0,
                g = 0,
                b = 255,
            },
            {
                r = 255,
                g = 255,
                b = 0,
            },
        }
        grad.colors = stops

        grad.angleOffset = 90
        print("Start grad")
        basicAsserts(grad, stops[1], stops[2])
    end)
    it("gradients at 45", function ()
        local grad = g.linearGradient()
        grad.angleOffset = 45
        ---@type Banana.GradientColorStop[]
        local stops = {
            {
                r = 0,
                g = 0,
                b = 255,
            },
            {
                r = 255,
                g = 255,
                b = 0,
            },
        }
        grad.colors = stops

        grad.angleOffset = 90
        print("Start grad")
        basicAsserts(grad, stops[1], stops[2])
    end)
end)
