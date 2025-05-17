-- ---@module 'banana.utils.debug_flame'
-- local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")

---@type Banana.Renderer
local function renderer(self, ast, box, parentHl, inherit, extra)
    -- flame.new("tag:span")
    self:renderInlineEl(ast, box, parentHl, inherit, extra)
    if extra.isRealRender and ast:hasAttribute("href") then
        table.insert(ast:ownerDocument().urlAsts, ast)
    end
end
---@type Banana.TagInfo
local M = t.newTag(
    "a",
    t.FormatType.Inline,
    false,
    renderer,
    require("banana.nml.tag").defaultInitials()
)

return M
