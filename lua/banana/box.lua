local M = {}
---@class (exact) Banana.Box
---@field lines Banana.Line[]
---@field width integer
---@field dirty boolean true when box is a rect of width self.width
M.Box = {
    lines = {},
    width = 0,
    dirty = false,
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
local function lineWidth(line)
    local ret = 0
    for _, v in ipairs(line) do
        ret = ret + #v
    end
    return ret
end

---@param hlgroup table?
---@param fillChar string?
function M.Box:clean(hlgroup, fillChar)
    fillChar = fillChar or ' '
    for i, _ in ipairs(self.lines) do
        local w = lineWidth(self.lines[i])
        if w > self.width then
            error("Unreachable (line width is greater than max width)")
        elseif w < self.width then
            local newStr = string.rep(fillChar, self.width - w);
            ---@type Banana.Word
            local word = {
                word = newStr,
                style = hlgroup
            }
            table.insert(self.lines[i], word)
        end
    end
    self.dirty = false
end

---@param box Banana.Box
---@param strat Banana.Box.MergeStrategy?
function M.Box:append(box, strat)
    strat = strat or M.MergeStrategy.Bottom
end

---@param width number the maximum width of the box
---@param trimStrat Banana.Box.TrimStrategy? the trim method
function M.Box:trimWidthLastLine(width, trimStrat)
    trimStrat = trimStrat or M.TrimStrategy.NewLine
    local maxWidth = 0
    for i = 1, #self.lines - 1 do
        maxWidth = math.max(maxWidth, lineWidth(self.lines[i]))
        if maxWidth > width then
            error("Can not trim non last line in Box:trimWidthLastLine")
        end
    end
end

return M
