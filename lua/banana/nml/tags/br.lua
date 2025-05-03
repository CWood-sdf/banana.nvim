---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")

---@type Banana.Renderer
local function renderer(_, ast, box, parentHl, _, _)
    -- flame.new("tag:br")
    local b = require("banana.box")
    ---@type Banana.Box
    local ret = b.Box:new()
    ret.hlgroup = ast:_mixHl(parentHl)
    ret:appendStr("")
    -- flame.pop()
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    "br",
    t.FormatType.Block,
    true,
    renderer,
    require("banana.nml.tag").defaultInitials()
)

return M
