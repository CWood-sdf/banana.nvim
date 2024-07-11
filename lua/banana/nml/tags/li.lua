-- local _str = require('banana.utils.string')
local t = require('banana.nml.tags')

---@type Banana.Renderer
local function renderer(self, ast, parentHl, parentWidth, parentHeight, startX, startY, inherit, extra)
    -- local listTick = nil
    -- local widthAlloted = nil
    -- if self.name == "li" then
    --     listTick = ast:parent():_getNextListItem(inherit.list_style_type)
    --     widthAlloted = _str.charWidth(listTick)
    --     if ast:parent().listCounter ~= nil then
    --         widthAlloted = ast:parent():_getMaxListWidth(inherit.list_style_type)
    --     end
    --     parentWidth = parentWidth - widthAlloted
    -- end
    return self:renderInlineEl(ast, parentHl, parentWidth, parentHeight, startX, startY, inherit, extra)
end
---@type Banana.TagInfo
local M = t.newTag(
    'li',
    t.FormatType.BlockInline,
    false,
    renderer,
    require('banana.nml.tags').defaultInitials()
)

return M
