---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")

---@type Banana.Renderer
local function renderer(self, ast, box, parentHl, inherit, extra)
    local fillChar = ast:getAttribute("filled-char") or "="
    local emptyChar = ast:getAttribute("empty-char") or " "
    local value = tonumber(ast:getAttribute("value") or "0") or 0
    local max = tonumber(ast:getAttribute("max") or "1") or 1
    if max == 0 then max = 1 end
    local portion = value / max
    local maxWidth = box:getMaxWidth()
    local fillPortion = vim.fn.round(maxWidth * portion)
    local emptyPortion = maxWidth - fillPortion
    local filledSpan = ast:child(1)
    local emptySpan = ast:child(2)
    local filledText = string.rep(fillChar, fillPortion)
    local emptyText = string.rep(emptyChar, emptyPortion)
    filledSpan.nodes = { filledText }
    emptySpan.nodes = { emptyText }
    self:renderInlineEl(ast, box, parentHl, inherit, extra)
end
---@type Banana.TagInfo
local M = t.newTag(
    "progress",
    t.FormatType.Inline,
    false,
    renderer,
    require("banana.nml.tag").defaultInitials()
)

return M
