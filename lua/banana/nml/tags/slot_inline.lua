---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")

-- this file is here for inline components. it is supposed to injected manually
-- via ast/runtime stuff and not from a user tag

---@type Banana.Renderer
local function renderer(self, ast, parentHl, parentWidth, parentHeight, startX,
                        startY, inherit, extra)
    flame.new("tag:slot")
    local ret = self:renderInlineEl(ast, parentHl, parentWidth, parentHeight,
        startX,
        startY, inherit, extra)
    flame.pop()
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    "slot",
    t.FormatType.Inline,
    false,
    renderer,
    require("banana.nml.tag").defaultInitials()
)

return M
