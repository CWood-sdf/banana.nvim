---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.render'
local t = require("banana.lazyRequire")("banana.nml.render")

---@type Banana.Renderer
local function renderer(self, ast, _, parentWidth, parentHeight, startX, startY,
                        inherit, extra)
    --flame.new("tag:title")
    local inst = require("banana.instance").getInstance(ast.instance)
    inst:setBufName(ast:getTextContent())
    local b = require("banana.box")
    ---@type Banana.Box
    local ret = b.Box:new()
    --flame.pop()
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    "title",
    t.FormatType.BlockInline,
    false,
    renderer,
    require("banana.nml.render").defaultInitials()
)

return M
