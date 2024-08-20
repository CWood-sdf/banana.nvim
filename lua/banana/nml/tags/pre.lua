---@module 'banana.utils.debug_flame'
---flame.new("tag:pre")
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
-- local t = require('banana.nml.tags')
--
-- ---@type Banana.Renderer
-- local function renderer(self, ast, parentHl, parentWidth, parentHeight, startX, startY, inherit, extra)
--     local _str = require('banana.utils.string')
--     local b = require('banana.box')
--     ---@type Banana.Box
--     local ret = b.Box:new()
--     ret.hlgroup = ast:mixHl(parentHl)
--     for _, box, _ in self:blockIter(ast, ret.hlgroup, parentWidth, parentHeight, startX, startY, inherit, extra) do
--         for _, v in ipairs(box.lines) do
--             local currentLine = b.Box:new(ret.hlgroup)
--             currentLine:appendStr('', nil)
--             for _, word in ipairs(v) do
--                 local split = vim.split(word.word, '\n')
--                 if #split ~= 1 then
--                     table.insert(currentLine.lines[1], {
--                         word = split[1],
--                         style = word.style
--                     })
--                     currentLine._width = currentLine._width + _str.charWidth(split[1])
--                     local i = 2
--                     while i <= #split do
--                         ret:appendBoxBelow(currentLine)
--                         currentLine = b.Box:new(ret.hlgroup)
--                         currentLine._width = _str.charWidth(split[i])
--                         currentLine.lines = { { {
--                             word = split[i],
--                             style = word.style,
--                         } } }
--                         i = i + 1
--                     end
--                 else
--                     table.insert(currentLine.lines[1], word)
--                     currentLine._width = currentLine._width + _str.charWidth(word.word)
--                 end
--             end
--             ret:appendBoxBelow(currentLine)
--         end
--     end
--     flame.pop()
--     return ret
-- end
-- ---@type Banana.TagInfo
-- local M = t.newTag(
--     'pre',
--     t.FormatType.Block,
--     false,
--     renderer,
--     require('banana.nml.tags').defaultInitials()
-- )
--
-- return M
