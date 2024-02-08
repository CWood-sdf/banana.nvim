local i = 0
local M = {}
local function getNextI()
    i = i + 1
    return i
end
---@enum BananaTokenType
M.TokenType = {
    --- The "<div" part of an opening tag
    StartTagOpen = "StartTagOpen",
    --- The ">" of an opening tag
    StartTagClose = "StartTagClose",
    --- The "/>" of a tag that doesn't have an end tag
    StartTagSelfClose = "StartTagSelfClose",
    --- The "</div>" of an end tag
    EndTag = "EndTag",
    --- The "href=" part of an attribute
    AttributeLeft = "AttributeLeft",
    --- The '"sdf"' part of an attribute
    AttributeRight = "AttributeRight",
    --- An attribute that doesn't have a value
    AttributeNoValue = "AttributeNoValue",
    --- The &lt; characters
    SpecialChar = "SpecialChar",
    --- Just a block of text inside a <div>
    Text = "Text",
    --- The end of the file
    EndOfFile = "EndOfFile",
}
---@enum BananaLexerContext
M.LexerContext = {
    --- The lexer is currently parsing a opening tag
    OpenTag = getNextI(),
    --- The lexer is currently parsing a block of text
    Text = getNextI(),
    --- Script or style tag
    Script = getNextI(),
    --- Opening a script or style tag
    ScriptOpen = getNextI(),
}

---@class (exact) BananaToken
---@field type BananaTokenType
---@field text string
---@field lineStart integer
---@field lineEnd integer
---@field colStart integer
---@field colEnd integer
---@field file string
local Token = {
    type = M.TokenType.Text,
    text = "",
    lineStart = 1,
    lineEnd = 1,
    colStart = 1,
    colEnd = 1,
    file = "",
}
function Token:new(tp, text, lineStart, lineEnd, colStart, colEnd, file)
    local token = {
        type = tp,
        text = text,
        lineStart = lineStart,
        lineEnd = lineEnd,
        colStart = colStart,
        colEnd = colEnd,
        file = file,
    }
    setmetatable(token, { __index = Token })
    return token
end

---@class (exact) BananaLexer
---@field currentToken BananaToken
---@field currentLine integer
---@field currentCol integer
---@field program string[]
---@field context BananaLexerContext
---@field file string
local Lexer = {
    currentToken = Token:new(M.TokenType.EndOfFile, "", 1, 1, 1, 1, ""),
    currentLine = 1,
    currentCol = 1,
    context = M.LexerContext.Text,
    program = {},
    file = "",
}
local function isAlpha(c)
    return c:match("[a-zA-Z]")
end
local function isWhitespace(c)
    return c:match("[ \t\n]")
end
local function isAlnum(c)
    return c:match("[a-zA-Z0-9]")
end
local function isTagNameChar(c)
    return c:match("[a-zA-Z0-9-]")
end

function Lexer:nextPosition()
    self.currentCol = self.currentCol + 1
    if self.program[self.currentLine] == nil then
        self.currentLine = self.currentLine + 1
        self.currentCol = 1
        return self.currentLine, self.currentCol
    end
    if self.currentCol > #self.program[self.currentLine] then
        self.currentCol = 1
        self.currentLine = self.currentLine + 1
    end
    return self.currentLine, self.currentCol
end

---@return BananaToken
function Lexer:readStartTagOpen()
    local lineStart = self.currentLine
    local colStart = self.currentCol
    local line, col = self:nextPosition()
    local tagName = ""
    local char = self.program[line]:sub(col, col)
    while isAlnum(char) or char == "-" do
        tagName = tagName .. char
        line, col = self:nextPosition()
        char = self.program[line]:sub(col, col)
    end
    self.context = M.LexerContext.OpenTag
    if tagName == "script" or tagName == "style" then
        self.context = M.LexerContext.ScriptOpen
    end
    return Token:new(M.TokenType.StartTagOpen, tagName, lineStart, line, colStart, col, self.file)
end

function Lexer:peekNextChar()
    local line = self.currentLine
    local col = self.currentCol
    local newLine, newCol = self:nextPosition()
    if newLine > #self.program or newCol > #self.program[newLine] then
        return ""
    end
    local char = self.program[newLine]:sub(newCol, newCol)
    self.currentLine = line
    self.currentCol = col
    return char
end

function Lexer:parseEndTag()
    local lineStart = self.currentLine
    local colStart = self.currentCol
    -- Eat the "</"
    self:nextPosition()
    local line, col = self:nextPosition()
    local tagName = ""
    local char = self.program[line]:sub(col, col)
    while isAlnum(char) do
        tagName = tagName .. char
        line, col = self:nextPosition()
        char = self.program[line]:sub(col, col)
    end
    -- Eat the ">"
    self:nextPosition()
    return Token:new(M.TokenType.EndTag, tagName, lineStart, line, colStart, col, self.file)
end

function Lexer:parseAttribute()
    local lineStart = self.currentLine
    local colStart = self.currentCol
    local line, col = lineStart, colStart
    local attrName = ""
    local char = self.program[line]:sub(col, col)
    while isAlnum(char) or char == "-" do
        attrName = attrName .. char
        line, col = self:nextPosition()
        char = self.program[line]:sub(col, col)
    end
    if char == "=" then
        self:nextPosition()
        return Token:new(M.TokenType.AttributeLeft, attrName, lineStart, line, colStart, col, self.file)
    end
    return Token:new(M.TokenType.AttributeNoValue, attrName, lineStart, line, colStart, col, self.file)
end

function Lexer:parseAttributeRight()
    local lineStart = self.currentLine
    local colStart = self.currentCol
    local line, col = self:nextPosition()
    local attrValue = ""
    local char = self.program[line]:sub(col, col)
    local done = false
    local slash = false
    while not done do
        attrValue = attrValue .. char
        line, col = self:nextPosition()
        char = self.program[line]:sub(col, col)
        if char == "\"" and not slash then
            done = true
        end
        slash = false
        if char == "\\" then
            slash = true
        end
    end
    self:nextPosition()
    self.context = M.LexerContext.OpenTag
    return Token:new(M.TokenType.AttributeRight, attrValue, lineStart, line, colStart, col, self.file)
end

function Lexer:isDone()
    return self.currentLine > #self.program or
        (self.currentLine == #self.program and self.currentCol > #self.program[self.currentLine])
end

---@return BananaToken
function Lexer:_getNextToken()
    if self:isDone() then
        return Token:new(M.TokenType.EndOfFile, "", self.currentLine, self.currentLine, self.currentCol,
            self.currentCol, self.file)
    end
    local currentChar = self.program[self.currentLine]:sub(self.currentCol, self.currentCol)
    local peek = self:peekNextChar()
    local isOpenTag = self.context == M.LexerContext.OpenTag or self.context == M.LexerContext.ScriptOpen
    if isWhitespace(currentChar) and isOpenTag then
        self:nextPosition()
        return self:getNextToken()
    end
    if currentChar == "/" and peek == ">" and isOpenTag then
        self:nextPosition()
        self:nextPosition()
        return Token:new(M.TokenType.StartTagSelfClose, "", self.currentLine, self.currentLine, self.currentCol - 1,
            self.currentCol, self.file)
    end
    if currentChar == "<" then
        if peek == "/" then
            return self:parseEndTag()
        elseif isTagNameChar(peek) and self.context ~= M.LexerContext.Script then
            return self:readStartTagOpen()
        end
    end
    if isAlpha(currentChar) and isOpenTag then
        return self:parseAttribute()
    end
    if currentChar == "\"" and isOpenTag and self.currentToken.type == M.TokenType.AttributeLeft then
        return self:parseAttributeRight()
    end
    if currentChar == ">" and isOpenTag then
        if self.context == M.LexerContext.ScriptOpen then
            self.context = M.LexerContext.Script
        else
            self.context = M.LexerContext.Text
        end
        self:nextPosition()
        return Token:new(M.TokenType.StartTagClose, ">", self.currentLine, self.currentLine, self.currentCol,
            self.currentCol, self.file)
    end
    local str = ""
    local startLine, startCol = self.currentLine, self.currentCol

    local done = false
    while not done do
        if self:isDone() then
            done = true
            break
        end
        local char = self.program[self.currentLine]:sub(self.currentCol, self.currentCol)
        peek = self:peekNextChar()
        if char == "<" and peek == "/" then
            done = true
            break
        end
        if char == "<" and isTagNameChar(peek) and self.context ~= M.LexerContext.Script then
            done = true
            break
        end
        str = str .. char
        -- Don't eat until the checks have gone through
        self:nextPosition()
    end

    if str == "" then
        return Token:new(M.TokenType.EndOfFile, "", self.currentLine, self.currentLine, self.currentCol, self.currentCol,
            self.file)
    end
    return Token:new(M.TokenType.Text, str, startLine, self.currentLine, startCol, self.currentCol, self.file)
end

---@return BananaToken
function Lexer:getNextToken()
    local token = self:_getNextToken()
    self.currentToken = token
    return token
end

---@param file string
---@return BananaLexer?
function M.fromPath(file)
    ---@type file*?
    local f = io.open(file, "r")
    if not f then
        return nil
    end
    local program = {}
    for line in f:lines() do
        table.insert(program, line .. "\n")
    end
    local lexer = {
        currentToken = Token,
        currentLine = 1,
        currentCol = 1,
        program = program,
        file = file,
    }
    setmetatable(lexer, { __index = Lexer })
    return lexer
end

---@param str string
function M.fromString(str)
    local program = {}
    for line in str:gmatch("[^\n]+") do
        table.insert(program, line .. "\n")
    end
    local lexer = {
        currentToken = Token,
        currentLine = 1,
        currentCol = 1,
        program = program,
        file = "string",
    }
    setmetatable(lexer, { __index = Lexer })
    return lexer
end

return M
