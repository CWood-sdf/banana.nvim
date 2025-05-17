---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
-- local _str = require('banana.utils.string')
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")

---@type Banana.Renderer
local function renderer(self, ast, box, parentHl,

                        inherit, extra)
    -- flame.new("tag:ul")
    local b = require("banana.box")
    ---@type Banana.Box
    local ret = b.Box:new()
    ret.hlgroup = ast:_mixHl(parentHl)

    local currentBox = box
    for _, newBox, _ in self:blockIter(ast, currentBox, ret.hlgroup, inherit, extra) do
        -- local v = ast.nodes[i]
        -- local currentLine = b.Box:new(ret.hlgroup)
        -- if type(v) ~= "string" and v.actualTag.name == 'li' then
        --     currentLine:appendStr("", nil)
        --     currentLine:expandWidthTo(numSize - _str.charWidth(listType))
        --     currentLine:appendStr(listType, nil)
        -- end
        -- currentLine:expandWidthTo(numSize)
        -- currentLine:append(box, b.MergeStrategy.Bottom)
        currentBox = newBox
    end
    -- flame.pop()
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    "ul",
    t.FormatType.Block,
    false,
    renderer,
    require("banana.nml.tag").defaultInitials()
)

return M
