---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")

---@type Banana.Renderer
local function renderer(_, _, box, _, _, _)
    -- flame.new("tag:br")
    ---@type Banana.Box
    -- local ret = b.Box:new()
    -- ret.hlgroup = ast:_mixHl(parentHl)
    box:appendStr(" ")
    -- flame.pop()
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
