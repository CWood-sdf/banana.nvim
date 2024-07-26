---@module 'banana.utils.debug_flame'
local flame = require('banana.lazyRequire')('banana.utils.debug_flame')
---@module 'banana.nml.render'
local t = require('banana.lazyRequire')('banana.nml.render')

---@type Banana.Renderer
local function renderer(self, ast, parentHl, parentWidth, parentHeight, startX, startY, inherit, extra)
    flame.new("tag:div")
    local b = require('banana.box')
    ---@type Banana.Box
    local ret = b.Box:new()
    ret.hlgroup = ast:_mixHl(parentHl)
    for _, box, _ in self:blockIter(ast, ret.hlgroup, parentWidth, parentHeight, startX, startY, inherit, extra) do
        ret:appendBoxBelow(box)
    end
    flame.pop()
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    'div',
    t.FormatType.Block,
    false,
    renderer,
    require('banana.nml.render').defaultInitials()
)

return M
