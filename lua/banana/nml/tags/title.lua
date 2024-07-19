---@module 'banana.nml.render'
local t = require('banana.lazyRequire')('banana.nml.render')

---@type Banana.Renderer
local function renderer(self, ast, _, parentWidth, parentHeight, startX, startY, inherit, extra)
    local inst = require('banana.instance').getInstance(ast.instance)
    inst:setBufName(ast:getTextContent())
    local b = require('banana.box')
    ---@type Banana.Box
    local ret = b.Box:new()
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    'title',
    t.FormatType.BlockInline,
    false,
    renderer,
    require('banana.nml.render').defaultInitials()
)

return M
