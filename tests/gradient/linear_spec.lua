local g = require("banana.gradient")
---@param grad Banana.Gradient
---@param tlColor Banana.GradientColorStop
---@param brColor Banana.GradientColorStop
local function basicAsserts(grad, tlColor, brColor)
    grad:setSize(5, 5)
    grad:startLineRender()
    local tl = grad:nextCharColor()
    local expTl = grad:_lerpColors(tlColor, tlColor, 1)
    assert(tl == expTl,
        "Could not match top left colors (NOTE: expected '" ..
        expTl .. "' but got '" .. tl .. "')")
    grad:nextLine()
    grad:nextLine()
    grad:nextLine()
    grad:nextLine()
    grad:nextCharColor()
    grad:nextCharColor()
    grad:nextCharColor()
    grad:nextCharColor()
    local br = grad:nextCharColor()
    local expBr = grad:_lerpColors(brColor, brColor, 1)
    assert(br == expBr,
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
        grad.angleOffset = 90
        -- basicAsserts(grad, stops[1], stops[2])
    end)
end)
