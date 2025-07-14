---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")
---@module 'banana.utils.string'
local str = require("banana.lazyRequire")("banana.utils.string")

---@type Banana.Renderer
local function renderer(_, ast, box, _, _, _)
    local fillChar = ast:getAttribute("char") or "-"
    for _ = 1, box:getMaxWidth() / str.charWidth(fillChar) do
        box:appendStr(fillChar)
    end
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
