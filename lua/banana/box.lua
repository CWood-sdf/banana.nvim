local _str = require('banana.utils.string')
local M = {}
---@class (exact) Banana.Box
---@field lines Banana.Line[]
---@field width integer
---@field dirty boolean true when box is a rect of width self.width
---@field fillChar string
---@field hlgroup Banana.Highlight?
M.Box = {
    lines = {},
    width = 0,
    dirty = false,
    fillChar = ' ',
    hlgroup = nil,
}

---@enum Banana.Box.MergeStrategy
M.MergeStrategy = {
    Bottom = 1,
    Top = 2,
}
---@enum Banana.Box.TrimStrategy
M.TrimStrategy = {
    Delete = 1,
    NewLine = 2
}

---@return number
---@param line Banana.Line
function M.lineWidth(line)
    local ret = 0
    for _, v in ipairs(line) do
        ret = ret + _str.charCount(v.word)
    end
    return ret
end

---@param width number
---@return Banana.Word
function M.Box:fillString(width)
    local newStr = string.rep(self.fillChar, width)
    ---@type Banana.Word
    local word = {
        word = newStr,
        style = self.hlgroup,
    }
    return word
end

---@param width number
function M.Box:expandWidthTo(width)
    if width < self.width then
        error("width is smaller than possible")
    end
    self.width = width
    self.dirty = true
    self:clean()
end

---@param hlgroup Banana.Highlight?
---@return Banana.Box
function M.Box:new(hlgroup)
    ---@type Banana.Box
    local box = {
        lines = {},
        width = 0,
        dirty = false,
        fillChar = ' ',
        hlgroup = hlgroup,

    }
    setmetatable(box, { __index = M.Box })
    return box
end

function M.Box:clean()
    if not self.dirty then
        return
    end
    for i, _ in ipairs(self.lines) do
        local w = M.lineWidth(self.lines[i])
        if w > self.width then
            error("Unreachable (line width is greater than max width)")
        elseif w < self.width then
            table.insert(self.lines[i], self:fillString(self.width - w))
        end
    end
    self.dirty = false
end

---@param box Banana.Box
---@param strat Banana.Box.MergeStrategy?
function M.Box:append(box, strat)
    strat = strat or M.MergeStrategy.Bottom
    self:clean()
    while #self.lines < #box.lines do
        if self.width == 0 then
            table.insert(self.lines, {})
        elseif strat == M.MergeStrategy.Bottom then
            table.insert(self.lines, 1, {
                self:fillString(self.width)
            })
        else
            table.insert(self.lines, {
                self:fillString(self.width)
            })
        end
    end
    local i = 0
    while #box.lines + i < #self.lines do
        if strat == M.MergeStrategy.Bottom then
            table.insert(self.lines[i + 1], self:fillString(box.width))
        else
            table.insert(self.lines[#self.lines - i], self:fillString(box.width))
        end
        i = i + 1
    end
    local boxI = 1
    if strat == M.MergeStrategy.Top then
        i = 0
    end
    while i < #self.lines and boxI <= #box.lines do
        for _, v in ipairs(box.lines[boxI]) do
            table.insert(self.lines[i + 1], v)
        end
        boxI = boxI + 1
        i = i + 1
    end
    self.width = self.width + box.width
    self.dirty = box.dirty
end

---@param str string
---@param strat Banana.Box.MergeStrategy?
function M.Box:appendStr(str, strat)
    self:clean()
    ---@type Banana.Word
    local word = {
        word = str,
        style = self.hlgroup,
    }
    if #self.lines == 0 then
        self.lines = { { word } }
        self.width = _str.charCount(str)
        self.dirty = false
    elseif #self.lines == 1 then
        table.insert(self.lines[1], word)
        self.width = self.width + _str.charCount(str)
        self.dirty = false
    else
        if strat == M.MergeStrategy.Top then
            table.insert(self.lines[1], word)
            self.width = math.max(M.lineWidth(self.lines[1]), self.width)
        else
            table.insert(self.lines[#self.lines], word)
            self.width = math.max(M.lineWidth(self.lines[#self.lines]), self.width)
        end
        self.dirty = true
    end
end

---@param box Banana.Box
function M.Box:appendBoxBelow(box)
    box:clean()
    local newWidth = math.max(self.width, box.width)
    if newWidth > self.width then
        self.width = newWidth
        self.dirty = true
        self:clean()
    end
    for _, v in ipairs(box.lines) do
        table.insert(self.lines, v)
    end
    self.dirty = self.width ~= box.width
    self.width = newWidth
end

---@param width number the maximum width of the box
---@param trimStrat Banana.Box.TrimStrategy? the trim method
function M.Box:trimWidthLastLine(width, trimStrat)
    trimStrat = trimStrat or M.TrimStrategy.NewLine
    local maxWidth = 0
    for i = 1, #self.lines - 1 do
        maxWidth = math.max(maxWidth, M.lineWidth(self.lines[i]))
        if maxWidth > width then
            error("Can not trim non last line in Box:trimWidthLastLine")
        end
    end
end

return M
