---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
---@module 'banana.utils.string'
local _str = require("banana.lazyRequire")("banana.utils.string")

local M = {}

---@return Banana.Word[]
local function emptyLine()
    local ret = {}
    setmetatable(ret, { __mode = "kv" })
    return ret
end

---@return Banana.Word[]
local function newLine(...)
    local ret = { ... }
    setmetatable(ret, { __mode = "kv" })
    return ret
end

---@return Banana.Word[][]
local function newLineArr(...)
    local ret = { ... }
    setmetatable(ret, { __mode = "kv" })
    return ret
end

---@return Banana.Word[][]
local function emptyLineArr()
    return emptyLine()
end

---comment
---@param str string
---@param style Banana.Highlight?
---@return Banana.Word
local function word(str, style)
    local ret = {
        word = str,
        style = style,
    }
    setmetatable(ret, { __mode = "kv" })
    return ret
end

---@param line Banana.Line
---@return Banana.Line
local function cloneLine(line)
    flame.new("cloneLine")
    ---@type Banana.Line
    local ret = emptyLine()
    for _, v in ipairs(line) do
        table.insert(ret, word(v.word, v.style))
    end
    flame.pop()
    return ret
end

---@class (exact) Banana.Box
---@field private lines Banana.Line[]
---@field private _width integer
---@field dirty boolean true when box is a rect of width self.width
---@field fillChar string
---@field hlgroup Banana.Highlight?
M.Box = {
    lines = emptyLineArr(),
    _width = 0,
    dirty = false,
    fillChar = " ",
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

function M.Box:getLines()
    return self.lines
end

---@return number
---@param line Banana.Line
function M.lineWidth(line)
    local ret = 0
    for _, v in ipairs(line) do
        ret = ret + _str.charWidth(v.word)
    end
    return ret
end

function M.Box:setGradientSize()
    if self.hlgroup == nil then
        return
    end
    if type(self.hlgroup.fg) == "table" then
        ---@diagnostic disable-next-line: param-type-mismatch
        self.hlgroup.fg:setSize(self._width, self:height())
    end
    if type(self.hlgroup.bg) == "table" then
        ---@diagnostic disable-next-line: param-type-mismatch
        self.hlgroup.bg:setSize(self._width, self:height())
    end
end

---@param width number
---@return Banana.Word
function M.Box:fillString(width)
    local newStr = string.rep(self.fillChar, width)
    ---@type Banana.Word
    local w = word(newStr, self.hlgroup)
    return w
end

---@param width number
function M.Box:expandWidthTo(width)
    if width < self._width then
        log.throw(
            "width is smaller than possible (given target width " ..
            width .. " when current width is " .. self._width .. ")")
        error("")
    end
    if width == self._width then
        return
    end
    self._width = width
    self.dirty = true
    self:clean()
end

---@return Banana.Box
function M.Box:clone()
    local b = M.Box:new(self.hlgroup)
    for _, v in ipairs(self.lines) do
        table.insert(b.lines, cloneLine(v))
    end
    b._width = self._width
    return b
end

---Expands the height by cloning the last line
---@param height number
function M.Box:cloneHeightTo(height)
    if height < #self.lines then
        return
    end
    if #self.lines == 0 then
        log.throw("No contents to clone")
        error("")
    end
    local i = #self.lines
    while #self.lines < height do
        table.insert(self.lines, cloneLine(self.lines[i]))
    end
end

---@return number
function M.Box:height()
    return #self.lines
end

---@return integer
function M.Box:width()
    return self._width
end

---@param height number
function M.Box:expandHeightTo(height)
    if height < #self.lines then
        log.throw("Height is smaller than possible")
        error("")
    end
    while #self.lines < height do
        table.insert(self.lines, newLine(
            word(
                string.rep(self.fillChar, self._width),
                self.hlgroup
            )
        ))
    end
end

---@param hlgroup Banana.Highlight?
---@return Banana.Box
function M.Box:new(hlgroup)
    ---@type Banana.Box
    local box = {
        lines = emptyLineArr(),
        _width = 0,
        dirty = false,
        fillChar = " ",
        hlgroup = hlgroup,

    }
    if box.hlgroup ~= nil then
        setmetatable(box.hlgroup, { __mode = "kv" })
    end
    setmetatable(box, { __index = M.Box, __mode = "kv" })
    return box
end

function M.Box:destroy()
    self.lines = emptyLineArr()
    self.hlgroup = nil
end

function M.Box:clean()
    if not self.dirty then
        return
    end
    flame.new("Box:clean")
    for i, _ in ipairs(self.lines) do
        local w = M.lineWidth(self.lines[i])
        if w > self._width then
            log.throw(
                "Unreachable (line width is greater than max width)")
            error("")
        end
        if w < self._width then
            table.insert(self.lines[i], self:fillString(self._width - w))
        end
    end
    -- if require("banana.utils.debug").isdev() then
    --     ---@type { [Banana.Word[]]: boolean }
    --     local foundLines = {}
    --     for _, v in ipairs(self.lines) do
    --         if foundLines[v] ~= nil then
    --             error("Duplicated lines!!")
    --         end
    --     end
    -- end
    self.dirty = false
    flame.pop()
end

---@param box Banana.Box
---@param strat Banana.Box.MergeStrategy?
function M.Box:appendLeft(box, strat)
    box:append(self, strat)
    self.lines = box.lines
    self.dirty = box.dirty
    self._width = box._width
    box:destroy()
end

---Appends box to the right, *CONSUMES BOX* (aka rust move)
---@param box Banana.Box
---@param strat Banana.Box.MergeStrategy?
function M.Box:append(box, strat)
    flame.new("Box:append")
    strat = strat or M.MergeStrategy.Top
    self:clean()
    -- essentially whats happening is this:
    --            ┌───────┐
    --            │       │
    --  ┌───────┐ │  box  │
    --  │ self  │ │       │
    --  └───────┘ └───────┘
    --  becomes this:
    --  ┌───────┐ ┌───────┐
    --  │       │ │       │
    --  │       │ │  box  │
    --  │ self  │ │       │
    --  └───────┘ └───────┘
    while #self.lines < #box.lines do
        if self._width == 0 then
            table.insert(self.lines, emptyLine())
        elseif strat == M.MergeStrategy.Bottom then
            table.insert(self.lines, 1, newLine(
                self:fillString(self._width)
            ))
        else
            table.insert(self.lines, newLine(
                self:fillString(self._width)
            ))
        end
    end
    local i = 0
    -- not quite the same thing, but
    -- ┌──────┐┌─────┐
    -- │      ││ box │
    -- │ self │└─────┘
    -- │      │
    -- │      │
    -- └──────┘
    -- becomes:
    -- ┌──────┐┌─────┐
    -- │      ││ box │
    -- │ self │└─────┘
    -- │      └──────┐
    -- │             │
    -- └─────────────┘
    while #box.lines + i < #self.lines do
        if strat == M.MergeStrategy.Bottom then
            table.insert(self.lines[i + 1], self:fillString(box._width))
        else
            table.insert(self.lines[#self.lines - i], self:fillString(box._width))
        end
        i = i + 1
    end
    local boxI = 1
    if strat == M.MergeStrategy.Top then
        i = 0
    end
    -- merge
    while i < #self.lines and boxI <= #box.lines do
        for _, v in ipairs(box.lines[boxI]) do
            table.insert(self.lines[i + 1], v)
        end
        boxI = boxI + 1
        i = i + 1
    end
    self._width = self._width + box._width
    self.dirty = box.dirty
    box:destroy()
    flame.pop()
end

---Appends string to the right
---@param str string
---@param strat Banana.Box.MergeStrategy?
function M.Box:appendStr(str, strat)
    strat = strat or M.MergeStrategy.Top
    self:clean()
    ---@type Banana.Word
    local w = word(
        str,
        self.hlgroup
    )
    if #self.lines == 0 then
        self.lines = newLineArr(newLine(w))
        self._width = _str.charWidth(str)
    elseif #self.lines == 1 then
        table.insert(self.lines[1], w)
        self._width = self._width + _str.charWidth(str)
    elseif strat == M.MergeStrategy.Top then
        table.insert(self.lines[1], w)
        self._width = math.max(M.lineWidth(self.lines[1]), self._width)
        self.dirty = true
    else
        table.insert(self.lines[#self.lines], w)
        self._width = math.max(M.lineWidth(self.lines[#self.lines]), self._width)
        self.dirty = true
    end
end

---Appends word to the right
---@param str string
---@param style Banana.Highlight?
---@param strat Banana.Box.MergeStrategy?
function M.Box:appendWord(str, style, strat)
    local w = word(str, style)
    self:clean()
    ---@type Banana.Word
    if #self.lines == 0 then
        self.lines = newLineArr(newLine(w))
        self._width = _str.charWidth(w.word)
        self.dirty = false
    elseif #self.lines == 1 then
        table.insert(self.lines[1], w)
        self._width = self._width + _str.charWidth(w.word)
        self.dirty = false
    else
        if strat == M.MergeStrategy.Top then
            table.insert(self.lines[1], w)
            self._width = math.max(M.lineWidth(self.lines[1]), self._width)
        else
            table.insert(self.lines[#self.lines], w)
            self._width = math.max(M.lineWidth(self.lines[#self.lines]),
                self._width)
        end
        self.dirty = true
    end
end

---@param i number
---@return Banana.Line?
function M.Box:getLine(i)
    return self.lines[i]
end

---Appends box below (USES MOVE SEMANTICS)
---@param box Banana.Box
---@param expand boolean?
function M.Box:appendBoxBelow(box, expand)
    flame.new("appendBoxBelow")
    if expand == nil then
        expand = true
    end
    box:clean()
    local newWidth = math.max(self._width, box._width)
    if newWidth > self._width and expand then
        self:expandWidthTo(newWidth)
        -- self._width = newWidth
        -- self.dirty = true
        -- self:clean()
    end
    if newWidth > box:width() and expand then
        box:expandWidthTo(newWidth)
        -- box._width = newWidth
        -- box.dirty = true
        -- box:clean()
    end
    for _, v in ipairs(box.lines) do
        table.insert(self.lines, newLine())
        for _, w in ipairs(v) do
            table.insert(self.lines[#self.lines], word(w.word, w.style))
        end
    end
    self.dirty = self._width ~= box._width
    self._width = newWidth
    box:destroy()
    -- flame.expect("appendBoxBelow")
    flame.pop()
end

-- function M.Box:floatAppend()
--
-- end

---@param expectedBg string?
function M.Box:stripRightSpace(expectedBg)
    for _, row in ipairs(self.lines) do
        while #row > 0 do
            local i = #row
            if row[i].style ~= nil then
                if row[i].style.link ~= nil then
                    break
                end
                if row[i].style.bg ~= expectedBg and row[i].style.bg ~= nil then
                    break
                end
            end
            row[i].word = row[i].word:gsub("%s+$", "")
            if #row[i].word == 0 then
                table.remove(row, i)
            else
                break
            end
        end
    end
end

---@param width number the maximum width of the box
---@param trimStrat Banana.Box.TrimStrategy? the trim method
function M.Box:trimWidthLastLine(width, trimStrat)
    trimStrat = trimStrat or M.TrimStrategy.NewLine
    local maxWidth = 0
    for i = 1, #self.lines - 1 do
        maxWidth = math.max(maxWidth, M.lineWidth(self.lines[i]))
        if maxWidth > width then
            log.throw(
                "Can not trim non last line in Box:trimWidthLastLine")
            error("")
        end
    end
end

---Renders a box over another box (essentially position:absolute)
---@param other Banana.Box
---@param left number
---@param top number
function M.Box:renderOver(other, left, top)
    log.trace("renderOver") --- This function is pretty expensive because all the string stuff
    flame.new("Box:renderOver")
    -- lol dont look at this function i barely understand it
    -- if you really need help with this function, post an issue
    self:clean()
    other:clean()
    left = math.max(left, 0)
    top = math.max(top, 0)
    -- make sure that current box reaches starting point
    while #self.lines < top do
        local box = M.Box:new(self.hlgroup)
        box:appendStr("", nil)
        self:appendBoxBelow(box)
    end
    local j = 1
    -- need + 1 so that top:0 sets it to be on the actual top
    for i = top + 1, #self.lines do
        if j > #other.lines then
            break
        end
        local line = self.lines[i]
        local count = left
        local wordIndex = 1
        local wordSize = _str.charWidth(line[wordIndex].word)
        while count >= wordSize do
            count = count - wordSize
            wordIndex = wordIndex + 1
            if line[wordIndex] == nil then
                break
            end
            wordSize = _str.charWidth(line[wordIndex].word)
        end
        -- 4 rendering cases:
        -- 1:
        -- |-- word --|
        --          |-- overlay --|
        -- 2:
        -- |-- word ----------------|
        --          |-- overlay --|
        -- 3:
        --        |-- word --|
        -- |-- overlay -----------|
        -- 4:
        --          |-- word --|
        -- |-- overlay --|

        -- Cut out overlayed word chars

        local charsToCut = other._width
        while charsToCut > 0 and line[wordIndex] ~= nil do
            local str = line[wordIndex].word
            -- case 2
            if wordSize - count > other._width and count ~= 0 then
                local leftStr = _str.sub(str, 1, count)
                local rightStr = _str.sub(str, count + other._width + 1, wordSize)
                line[wordIndex].word = leftStr
                local style = line[wordIndex].style
                wordIndex = wordIndex + 1
                table.insert(line, wordIndex, word(rightStr, style))
                break
            end
            local newStr = ""
            if count == 0 and charsToCut >= wordSize then
                -- case 3 (cut out entire word)
                newStr = ""
            elseif count == 0 then
                -- case 4
                newStr = _str.sub(str, math.min(charsToCut + 1, wordSize + 1),
                    wordSize)
            else
                -- case 1
                newStr = _str.sub(str, 1, count)
            end
            local newLen = _str.charWidth(newStr)
            if newStr == "" then
                table.remove(line, wordIndex)
            elseif count ~= 0 then
                line[wordIndex].word = newStr
                wordIndex = wordIndex + 1
            else
                line[wordIndex].word = newStr
            end
            charsToCut = charsToCut - (wordSize - newLen)
            if line[wordIndex] == nil then
                break
            end
            if #line == 0 then
                -- if we empty, then we need something to insert before
                table.insert(line, newLine(
                    word(
                        "",
                        self.hlgroup
                    )
                ))
                break
            end
            wordSize = _str.charWidth(line[wordIndex].word)
            count = 0
        end
        if M.lineWidth(line) < left then
            table.insert(line, word(
                string.rep(self.fillChar, left - M.lineWidth(line)),
                self.hlgroup
            ))
            -- need something to insert before
            table.insert(line, word(
                "",
                self.hlgroup
            ))
            wordIndex = wordIndex + 1
            self._width = math.max(M.lineWidth(line), self._width)
            self.dirty = true
        end
        -- Insert new words
        for l = #other.lines[j], 1, -1 do
            local v = other.lines[j][l]
            table.insert(line, wordIndex, v)
        end
        j = j + 1
    end

    -- for overflow
    while j <= #other.lines do
        ---@type Banana.Word[]
        local nl = newLine(
            word(
                string.rep(self.fillChar, left),
                self.hlgroup
            )
        )
        for _, v in ipairs(other.lines[j]) do
            table.insert(nl, v)
        end
        table.insert(nl, word(
            string.rep(self.fillChar, self._width - M.lineWidth(nl)),
            self.hlgroup
        ))
        table.insert(self.lines, nl)
        j = j + 1
    end
    self.dirty = self.dirty or (self._width < left + other._width)
    self._width = math.max(self._width, left + other._width)
    other:destroy()
    flame.pop()
end

return M
