---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")
---@module 'banana.nml.canvas'
local canvas = require("banana.lazyRequire")("banana.nml.canvas")

---@type Banana.Renderer
local function renderer(_, ast, box, _, _)
    ---@type Banana.Nml.CanvasContext
    local ctx
    ast.data = ast.data or {}
    if ast.data.__ctx == nil then
        ast.data.__ctx = canvas.newContext(ast)
        ast.data.__ctx:resize(box:getMaxWidth(), box:getMaxHeight())
    end
    ctx = ast.data.__ctx
    box:renderOver(ctx.ctx, 0, 0)
end
---@type Banana.TagInfo
local M = t.newTag(
    "canvas",
    t.FormatType.Block,
    true,
    renderer,
    require("banana.nml.tag").defaultInitials()
)

return M
