local M = {}

local lex = require('banana.ncss.miniParser.lexer')
local tsTypes = require('banana.ncss.tsTypes')

---@class (exact) Banana.Ncss.MiniParser.Ast
---@field children Banana.Ncss.MiniParser.Ast[]
---@field str string
---@field tp string
local Ast = {
}

---comment
---@param str string
---@param tp Banana.Ncss.TSTypes
---@return Banana.Ncss.MiniParser.Ast
function Ast:new(str, tp)
    ---@type Banana.Ncss.MiniParser.Ast
    local ret = {
        children = {},
        tp = tp,
        str = str,
    }
    setmetatable(ret, {
        __index = Ast
    })
    return ret
end

---@param i integer
---@return Banana.Ncss.MiniParser.Ast
function Ast:child(i)
    return self.children[i + 1]
end

---@return string
function Ast:type()
    return self.tp
end

---@param child Banana.Ncss.MiniParser.Ast
function Ast:append(child)
    table.insert(self.children, child)
end

---@param child Banana.Ncss.MiniParser.Ast
function Ast:prepend(child)
    table.insert(self.children, child, 1)
end

---@class (exact) Banana.Ncss.MiniParser.Parser
---@field lexer Banana.Ncss.MiniParser.Lexer
local Parser = {
}

---@param lexer Banana.Ncss.MiniParser.Lexer
---@return Banana.Ncss.MiniParser.Parser
function Parser:new(lexer)
    ---@type Banana.Ncss.MiniParser.Parser
    local parser = {
        lexer = lexer,
    }
    setmetatable(parser, {
        __index = Parser
    })
    return parser
end

---@param str string
---@return Banana.Ncss.MiniParser.Ast
local function anonAst(str)
    return Ast:new(str, tsTypes._anon)
end

---@return Banana.Ncss.MiniParser.Ast
function Parser:parsePseudoClass()
    local name = self.lexer:nextToken()
    if name.tp ~= lex.TokenType.Word then
        error("Expected a name for a pseudo class")
    end
    local peek = self.lexer:peekNextToken()
    local ret = Ast:new("", tsTypes.pseudo_class_selector)
    local nameAst = Ast:new(name.str, tsTypes.class_name)
    ret:append(Ast:new(":", tsTypes._anon))
    ret:append(nameAst)
    if peek.tp == lex.TokenType.LeftParen then
        self.lexer:nextToken()

        local args = Ast:new("", tsTypes.arguments)
        args:append(anonAst("("))
        while self.lexer.currentToken.tp ~= lex.TokenType.RightParen do
            local sel = self:parseSelector()
            args:append(sel)
            if self.lexer.currentToken.tp == lex.TokenType.Space then
                self.lexer:nextToken()
            end
            if self.lexer.currentToken.tp == lex.TokenType.Comma then
                args:append(anonAst(","))
                self.lexer:nextToken()
            end
            if self.lexer.currentToken.tp == lex.TokenType.Space then
                self.lexer:nextToken()
            end
        end
        args:append(anonAst("("))
    end
    return ret
end

---@return Banana.Ncss.MiniParser.Ast?
function Parser:parseBasicSel()
    ---@type Banana.Ncss.MiniParser.Ast?
    local ast = nil
    while true do
        if self.lexer.currentToken.tp == lex.TokenType.Dot then
            local name = self.lexer:nextToken()
            if name.tp ~= lex.TokenType.Word then
                error("Expected a name for class selector, instead got '" .. name.tp .. "'")
            end
            local nameAst = Ast:new(name.str, tsTypes.class_name)
            local newAst = Ast:new("", tsTypes.class_selector)
            if ast ~= nil then
                newAst:prepend(ast)
            end
            newAst:append(anonAst("."))
            newAst:append(nameAst)
            ast = newAst
        elseif self.lexer.currentToken.tp == lex.TokenType.Word then
            local name = self.lexer:nextToken()
            if name.tp ~= lex.TokenType.Word then
                error("Expected a name for tag selector, instead got '" .. name.tp .. "'")
            end
            -- can only happen once, so we skip the other checks
            ast = Ast:new(name.str, tsTypes.tag_name)
        elseif self.lexer.currentToken.tp == lex.TokenType.Hash then
            local name = self.lexer:nextToken()
            if name.tp ~= lex.TokenType.Word then
                error("Expected a name for id selector, instead got '" .. name.tp .. "'")
            end
            local nameAst = Ast:new(name.str, tsTypes.id_name)
            local newAst = Ast:new("", tsTypes.id_selector)
            if ast ~= nil then
                newAst:prepend(ast)
            end
            newAst:append(anonAst("#"))
            newAst:append(nameAst)
            ast = newAst
        elseif self.lexer.currentToken.tp == lex.TokenType.Colon then
            local newAst = self:parsePseudoClass()
            if ast ~= nil then
                newAst:prepend(ast)
            end
            ast = newAst
        else
            break
        end
    end

    return ast
end

---@param tp Banana.Ncss.MiniParser.TokenType
---@return boolean
function Parser:parseSelIsTp(tp)
    if self.lexer.currentToken.tp == lex.TokenType.Space
        and self.lexer:peekNextToken().tp == tp
    then
        self.lexer:nextToken()
        return true
    end
    return self.lexer.currentToken.tp == tp
end

---@return Banana.Ncss.MiniParser.Ast
function Parser:parseSelector()
    local ast = self:parseBasicSel()
    if ast == nil then
        error("Could not parse")
    end
    while true do
        if self:parseSelIsTp(lex.TokenType.RightAngle) then
            local next = self:parseBasicSel()
            if next == nil then
                error("Expected a valid selector on the right side of a child_selector")
            end
            local newAst = Ast:new("", tsTypes.child_selector)
            newAst:append(ast)
            newAst:append(next)
            ast = newAst
        elseif self.lexer.currentToken.tp == lex.TokenType.Space then
            local next = self:parseBasicSel()
            if next == nil then
                break
            end
            local newAst = Ast:new("", tsTypes.descendant_selector)
            newAst:append(ast)
            newAst:append(next)
            ast = newAst
        else
            break
        end
    end

    return ast
end

---@return Banana.Ncss.MiniParser.Ast
function Parser:parseRuleSet()
    local sel = self:parseSelector()
    self.lexer.context = "property"
    assert(self.lexer:nextToken().tp == lex.TokenType.LeftBrace, "Expected a left brace to start block of rule set")
    local block = self:parseBlock()
    local ast = Ast:new("", tsTypes.rule_set)
    ast:append(sel)
    ast:append(block)
    return ast
end

---@return Banana.Ncss.MiniParser.Ast
function Parser:parseBlock()

end

---@param inline boolean
---@return Banana.Ncss.MiniParser.Ast
function Parser:parse(inline)
    local ret = Ast:new("", tsTypes.stylesheet)
    local token = self.lexer:nextToken()
    while token.tp ~= lex.TokenType.EOF do
        if inline then
            local ast = self:parseBlock()
            ret:append(ast)
            break
        else
            local ast = self:parseRuleSet()
            ret:append(ast)
            break
        end
    end

    return ret
end

function M.parserFromString(str)
    local lexer = lex.newLexer(str)
    return Parser:new(lexer)
end

return M
