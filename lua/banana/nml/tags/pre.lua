---@module 'banana.utils.debug_flame'
---flame.new("tag:pre")tags
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")

---@type Banana.Renderer
local function renderer(self, ast, box, parentHl,

                        inherit, extra)
    local b = require("banana.box")
    ---@type Banana.Box
    local ret = b.Box:new()
    ret.hlgroup = ast:_mixHl(parentHl)
    for _, box, _ in self:blockIter(ast, box, ret.hlgroup, inherit, extra) do
        ret:appendBoxBelow(box)
    end
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    "pre",
    t.FormatType.Block,
    false,
    renderer,
    require("banana.nml.tag").defaultInitials()
)

return M
