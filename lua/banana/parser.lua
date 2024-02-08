local lexer = require "banana.lexer"
local M = {}

---@class (exact) BananaAttribute
---@field name string
---@field value string?
M.Attribute = {
    name = '',
    value = nil,
}

---@param name string
function M.Attribute:new(name)
    local attr = {
        name = name,
        value = nil,
    }
    setmetatable(attr, { __index = M.Attribute })
    return attr
end

---@class (exact) BananaAst
---@field nodes (string|BananaAst)[]
---@field tag string
---@field attributes BananaAttribute[]
M.Ast = {
    nodes = {},
    tag = '',
    attributes = {},
}

---@param tag string
function M.Ast:new(tag)
    local ast = {
        nodes = {},
        tag = tag,
    }
    setmetatable(ast, { __index = M.Ast })
    return ast
end

---@param text string
function M.Ast:appendTextNode(text)
    table.insert(self.nodes, text)
end

---@param node BananaAst
function M.Ast:appendNode(node)
    table.insert(self.nodes, node)
end

---@class (exact) BananaParser
---@field lexer BananaLexer?
local Parser = {
    lexer = nil,
}

function Parser:new(lex)
    local parser = {
        lexer = lex,
    }
    setmetatable(parser, { __index = Parser })
    return parser
end

---@return BananaAst?
function Parser:parseBlock()
    local token = self.lexer.currentToken
    if token.type ~= lexer.TokenType.StartTagOpen then
        return nil
    end
    local tagName = token.text
    local ret = M.Ast:new(tagName)
    token = self.lexer:getNextToken()
    while token.type ~= lexer.TokenType.StartTagClose and token.type ~= lexer.TokenType.StartTagSelfClose do
        if token.type == lexer.TokenType.AttributeNoValue then
            local attr = M.Attribute:new(token.text)
            table.insert(ret.attributes, attr)
            token = self.lexer:getNextToken()
        elseif token.type == lexer.TokenType.AttributeLeft then
            local attr = M.Attribute:new(token.text)
            token = self.lexer:getNextToken()
            if token.type == lexer.TokenType.AttributeRight then
                attr.value = token.text
            else
                attr.value = ''
                error('Expected attribute value')
            end
            table.insert(ret.attributes, attr)
            token = self.lexer:getNextToken()
        else
            error('Expected attribute')
        end
    end
    if token.type == lexer.TokenType.StartTagSelfClose then
        return ret
    end
    token = self.lexer:getNextToken()
    while token.type ~= lexer.TokenType.EndTag do
        if token.type == lexer.TokenType.Text then
            ret:appendTextNode(token.text)
        elseif token.type == lexer.TokenType.StartTagOpen then
            local node = self:parseBlock()
            if node ~= nil then
                ret:appendNode(node)
            end
        end
        token = self.lexer:getNextToken()
    end
    return ret
end

---@return BananaAst?
function Parser:parse()
    local token = self.lexer:getNextToken()
    if token.type == lexer.TokenType.EndOfFile then
        return nil
    end
    while token.type == lexer.TokenType.Text do
        token = self.lexer:getNextToken()
    end
    if token.type == lexer.TokenType.StartTagOpen then
        return self:parseBlock()
    end
    return nil
end

---@return BananaParser?
M.fromFile = function(path)
    local lex = lexer.fromPath(path)
    if lex == nil then
        print('Failed to open file')
        return nil
    end

    local parser = Parser:new(lex)
    return parser
end

return M
