---@module 'banana.utils.debug_flame'
local flame = require("banana.utils.debug_flame")
---@module 'banana.nml.tag'
local t = require("banana.nml.tag")

---@type Banana.Renderer
local function renderer(_, ast, box, hl, inherit, extra)
    if extra.isRealRender then
        -- flame.pop()
        return
    end
    -- not actually rendering anything bc its all metadata tags
    for v in ast:childIter() do
        v.actualTag:renderRoot(v, box, hl, inherit, extra)
    end
    -- flame.expect("tag:head")
    -- flame.pop()
end
---@type Banana.TagInfo
local M = t.newTag(
    "head",
    t.FormatType.Block,
    false,
    renderer,
    require("banana.nml.tag").defaultInitials()
)

return M
