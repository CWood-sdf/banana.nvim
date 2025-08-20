---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")

---@type Banana.Renderer
local function renderer(self, ast, box, _,

                        inherit, extra)
    -- flame.new("tag:title")
    local inst = require("banana.instance").getInstance(ast.instance)
    inst:_setBufName(ast:getTextContent())
end
---@type Banana.TagInfo
local M = t.newTag(
    "title",
    t.FormatType.BlockInline,
    false,
    renderer,
    require("banana.nml.tag").defaultInitials()
)

return M
