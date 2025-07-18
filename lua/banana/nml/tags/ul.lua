---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
-- local _str = require('banana.utils.string')
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")

---@type Banana.Renderer
local function renderer(self, ast, box, parentHl, inherit, extra)
    for _, newBox, _ in self:blockIter(ast, box, parentHl, inherit, extra) do
    end
    -- flame.pop()
end
---@type Banana.TagInfo
local M = t.newTag(
    "ul",
    t.FormatType.Block,
    false,
    renderer,
    require("banana.nml.tag").defaultInitials()
)

return M
