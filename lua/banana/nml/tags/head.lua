---@module 'banana.utils.debug_flame'
local flame = require('banana.lazyRequire')('banana.utils.debug_flame')
---@module 'banana.nml.render'
local t = require('banana.lazyRequire')('banana.nml.render')

---@type Banana.Renderer
local function renderer(_, ast, hl, parentWidth, parentHeight, _, _, inherit, extra)
    flame.new("tag:head")
    local b = require('banana.box')
    ---@type Banana.Box
    local ret = b.Box:new()
    -- not actually rendering anything bc its all metadata tags
    for v in ast:childIter() do
        v.actualTag:renderRoot(ast, hl, parentWidth, parentHeight, inherit, extra)
    end
    flame.pop()
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    'head',
    t.FormatType.Block,
    false,
    renderer,
    require('banana.nml.render').defaultInitials()
)

return M
