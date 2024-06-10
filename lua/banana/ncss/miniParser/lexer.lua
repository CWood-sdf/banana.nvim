local M = {}
---@enum Banana.Ncss.MiniParser.TokenType
M.TokenType = {
    EOF = '\n',
    LeftParen = '(',
    RightParen = ')',
    LeftSquare = '[',
    RightSquare = ']',
    Dot = '.',       -- ==
    Hash = '#',      -- ==
    Exclam = '!',    -- ==
    Parent = '>',    -- ==
    Child = ' ',     -- ==
    Colon = ':',     -- ==
    Semicolon = ';', -- ==
    LeftBrace = '{',
    RightBrace = '}',
    Comma = ',',
    RightAngle = '<',
    Space = ' ',
    Word = '[%w%-][%w%-%d]*', -- :find
    Number = '%d*',           -- :find
    Unknown = "ERROR",
}

---@class (exact) Banana.Ncss.MiniParser.Token
---@field tp Banana.Ncss.MiniParser.TokenType
---@field str string
local Token = {
    tp = M.TokenType.EOF,
    str = "",
}

---comment @param tp Banana.Ncss.MiniParser.TokenType
---@param str string
---@return Banana.Ncss.MiniParser.Token
function Token:new(tp, str)
    ---@type Banana.Ncss.MiniParser.Token
    local tok = {
        tp = tp,
        str = str,
    }
    setmetatable(tok, {
        __index = Token,
    })
    return tok
end

---@class (exact) Banana.Ncss.MiniParser.Lexer
---@field program string[]
---@field str string
---@field currentToken Banana.Ncss.MiniParser.Token
---@field row number
---@field col number
---@field context "property"|"selector"
local Lexer = {
    program = {},
    str = "",
    currentToken = Token:new(M.TokenType.EOF, ""),
    row = 1,
    col = 1,
}

---@param str string
---@return Banana.Ncss.MiniParser.Lexer
function Lexer:new(str)
    ---@type Banana.Ncss.MiniParser.Lexer
    local lex = {
        program = vim.split(str, '\n'),
        str = "",
        currentToken = Token:new(M.TokenType.EOF, ""),
        row = 1,
        col = 1,
        context = "selector",
    }
    setmetatable(lex, {
        __index = Lexer,
    })
    return lex
end

---@return string
function Lexer:nextChar()
    if self.row > #self.program then
        return ''
    end
    local char = self:currentChar()
    self.col = self.col + 1
    while self.col > #self.program[self.row] + 1 do
        self.col = 1
        self.row = self.row + 1
        if self.row > #self.program then
            return ''
        end
    end
    return char
end

---@return string
function Lexer:currentChar()
    if self.row > #self.program then
        return ''
    end
    local char = ''
    if self.col == #self.program[self.row] + 1 then
        char = '\n'
    else
        char = self.program[self.row][self.col]
    end

    return char
end

---@return string
function Lexer:peekNextChar()
    local row, col = self.row, self.col
    local ret = self:nextChar()
    self.row, self.col = row, col
    return ret
end

---@param pattern string
---@return string
function Lexer:read(pattern)
    local str = self:currentChar()
    while (str .. self:peekNextChar()):find(pattern) ~= nil do
        str = str .. self:nextChar()
    end
    return str
end

---@return [ number, number ]
function Lexer:position()
    return { self.row, self.col }
end

---@return Banana.Ncss.MiniParser.Token
function Lexer:peekNextToken()
    local row, col = self.row, self.col
    local tok = self:nextToken()
    self.row, self.col = row, col
    return tok
end

---@return Banana.Ncss.MiniParser.Token
function Lexer:nextToken()
    local char = self:nextChar()
    while (char == ' ' and self.context ~= "selector") or char == '\t' do
        char = self:nextChar()
    end
    if char == M.TokenType.EOF then
        local currentTok = Token:new(M.TokenType.EOF, M.TokenType.EOF)
        self.currentToken = currentTok
        return currentTok
    elseif char == M.TokenType.RightAngle then
        local currentTok = Token:new(M.TokenType.RightAngle, M.TokenType.RightAngle)
        self.currentToken = currentTok
        return currentTok
    elseif char == M.TokenType.Comma then
        local currentTok = Token:new(M.TokenType.Comma, M.TokenType.Comma)
        self.currentToken = currentTok
        return currentTok
    elseif char == M.TokenType.LeftParen then
        local currentTok = Token:new(M.TokenType.LeftParen, M.TokenType.LeftParen)
        self.currentToken = currentTok
        return currentTok
    elseif char == M.TokenType.RightParen then
        local currentTok = Token:new(M.TokenType.RightParen, M.TokenType.RightParen)
        self.currentToken = currentTok
        return currentTok
    elseif char == M.TokenType.LeftSquare then
        local currentTok = Token:new(M.TokenType.LeftSquare, M.TokenType.LeftSquare)
        self.currentToken = currentTok
        return currentTok
    elseif char == M.TokenType.RightSquare then
        local currentTok = Token:new(M.TokenType.RightSquare, M.TokenType.RightSquare)
        self.currentToken = currentTok
        return currentTok
    elseif char == M.TokenType.Dot then
        local currentTok = Token:new(M.TokenType.Dot, M.TokenType.Dot)
        self.currentToken = currentTok
        return currentTok
    elseif char == M.TokenType.Hash then
        local currentTok = Token:new(M.TokenType.Hash, M.TokenType.Hash)
        self.currentToken = currentTok
        return currentTok
    elseif char == M.TokenType.Exclam then
        local currentTok = Token:new(M.TokenType.Exclam, M.TokenType.Exclam)
        self.currentToken = currentTok
        return currentTok
    elseif char == M.TokenType.Parent then
        local currentTok = Token:new(M.TokenType.Parent, M.TokenType.Parent)
        self.currentToken = currentTok
        return currentTok
    elseif char == M.TokenType.Child then
        local currentTok = Token:new(M.TokenType.Child, M.TokenType.Child)
        self.currentToken = currentTok
        return currentTok
    elseif char == M.TokenType.Colon then
        local currentTok = Token:new(M.TokenType.Colon, M.TokenType.Colon)
        self.currentToken = currentTok
        return currentTok
    elseif char == M.TokenType.Semicolon then
        local currentTok = Token:new(M.TokenType.Semicolon, M.TokenType.Semicolon)
        self.currentToken = currentTok
        return currentTok
    elseif char == M.TokenType.LeftBrace then
        local currentTok = Token:new(M.TokenType.LeftBrace, M.TokenType.LeftBrace)
        self.currentToken = currentTok
        return currentTok
    elseif char == M.TokenType.RightBrace then
        local currentTok = Token:new(M.TokenType.RightBrace, M.TokenType.RightBrace)
        self.currentToken = currentTok
        return currentTok
    elseif char:find(M.TokenType.Word) ~= nil then
        local str = self:read(M.TokenType.Word)
        local currentTok = Token:new(M.TokenType.Word, str)
        self.currentToken = currentTok
        return currentTok
    elseif char:find(M.TokenType.Number) ~= nil then
        local str = self:read(M.TokenType.Number)
        local currentTok = Token:new(M.TokenType.Number, str)
        self.currentToken = currentTok
        return currentTok
    elseif char == M.TokenType.Space and self.context == "selector" then
        local currentTok = Token:new(M.TokenType.Space, M.TokenType.Space)
        self.currentToken = currentTok
        while self:peekNextChar() == M.TokenType.Space or self:peekNextChar() == '\t' do
            self:nextChar()
        end
        return currentTok
    end
    error("Cannot recognize character '" .. char .. "'")
end

---@param str string
---@return Banana.Ncss.MiniParser.Lexer
function M.newLexer(str)
    return Lexer:new(str)
end

return M
