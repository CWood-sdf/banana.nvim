---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
-- local _str = require('banana.utils.string')
---@module 'banana.nml.render'
local t = require("banana.lazyRequire")("banana.nml.render")
---@module 'banana.utils.string'
local _str = require("banana.lazyRequire")("banana.utils.string")
---@module 'banana.utils.debug'
local dbg = require("banana.lazyRequire")("banana.utils.debug")
---@module 'banana.box'
local b = require("banana.lazyRequire")("banana.box")

---@type Banana.Renderer
local function renderer(self, ast, parentHl, parentWidth, parentHeight, startX,
                        startY, inherit, extra)
    flame.new("tag:li")
    local widthAlloted = nil
    local listTick = ast:parent():_getNextListItem(inherit.list_style_type)
    widthAlloted = _str.charWidth(listTick)
    if ast:parent().listCounter ~= nil then
        widthAlloted = ast:parent():_getMaxListWidth(inherit.list_style_type)
    end
    parentWidth = parentWidth - widthAlloted

    local render = self:renderInlineEl(ast, parentHl, parentWidth, parentHeight,
        startX, startY, inherit, extra)

    -- because expandHeightTo will fail later down
    if render:height() == 0 then return render end

    if extra.debug then
        extra.trace:appendBoxBelow(
            dbg.traceBreak("Adding list item '" .. listTick .. "'"), false)
    end
    listTick = string.rep(" ", widthAlloted - _str.charWidth(listTick)) ..
        listTick
    local box = b.Box:new(parentHl)
    box:appendStr(listTick)
    box:expandHeightTo(render:height())
    if extra.debug then
        extra.trace:appendBoxBelow(dbg.traceBreak("List item box"), false)
        extra.trace:appendBoxBelow(box, false)
    end
    box:append(render)
    local oldHl = render.hlgroup
    render = box
    render.hlgroup = oldHl
    -- flame.expect("tag:li")
    flame.pop()
    return render
end
---@type Banana.TagInfo
local M = t.newTag(
    "li",
    t.FormatType.BlockInline,
    false,
    renderer,
    require("banana.nml.render").defaultInitials()
)

return M
