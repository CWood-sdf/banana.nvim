-- local _str = require('banana.utils.string')
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")
---@module 'banana.utils.string'
local _str = require("banana.lazyRequire")("banana.utils.string")

---@type Banana.Renderer
local function renderer(self, ast, box, parentHl, inherit, extra)
    local widthAlloted = nil
    local listTick = ast:parent():_getNextListItem(inherit["list-style-type"])
    local tickWidth = _str.charWidth(listTick)
    if ast:parent().listCounter ~= nil then
        widthAlloted = ast:parent():_getMaxListWidth(inherit["list-style-type"])
    else
        widthAlloted = tickWidth
    end
    local extraSpace = string.rep(" ",
        widthAlloted - _str.charWidth(listTick))
    box:appendStr(extraSpace)
    box:appendStr(listTick)
    self:renderInlineEl(ast, box, parentHl, inherit, extra)
end
---@type Banana.TagInfo
local M = t.newTag(
    "li",
    t.FormatType.BlockInline,
    false,
    renderer,
    require("banana.nml.tag").defaultInitials()
)

return M
