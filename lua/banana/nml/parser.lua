local lexer = require("banana.nml.lexer")
local M = {}

---@enum Banana.Nml.TSTypes
M.ts_types = {
    source_file = "source_file",
    doctype = "doctype",
    element = "element",
    start_tag = "start_tag",
    end_tag = "end_tag",
    tag_name = "tag_name",
    text = "text",
    attribute = "attribute",
    attribute_name = "attribute_name",
    comment = "comment",
    quoted_attribute_value = "quoted_attribute_value",
    attribute_value = "attribute_value",
    self_closing_tag = "self_closing_tag"
}

---@class (exact) Banana.Attribute
---@field name string
---@field value string?
M.Attribute = {
    name = "",
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

---@class (exact) Banana.Ast
---@field nodes (string|Banana.Ast)[]
---@field tag string
---@field attributes Banana.Attribute[]
M.Ast = {
    nodes = {},
    tag = "",
    attributes = {},
}

---@param tag string
function M.Ast:new(tag)
    local ast = {
        nodes = {},
        tag = tag,
        actualTag = require("banana.nml.tags").makeTag(tag),
    }
    setmetatable(ast, { __index = M.Ast })
    return ast
end

---@param text string
function M.Ast:appendTextNode(text)
    table.insert(self.nodes, text)
end

---@param node Banana.Ast
function M.Ast:appendNode(node)
    table.insert(self.nodes, node)
end

---@class (exact) Banana.Parser
---@field lexer Banana.Lexer?
---@field tree TSTree?
local Parser = {
    lexer = nil,
    tree = nil,
}

---@param lex Banana.Lexer
---@param tree TSTree
function Parser:new(lex, tree)
    local parser = {
        lexer = lex,
        tree = tree,
    }
    setmetatable(parser, { __index = Parser })
    return parser
end

---@return Banana.Ast
function Parser:parseBlock()
    local token = self.lexer.currentToken
    if not token:isType(lexer.TokenType.StartTagOpen) then
        error("Expected start tag")
    end
    local tagName = token.text
    ---@type Banana.Ast
    local ret = M.Ast:new(tagName)
    token = self.lexer:getNextToken()
    while not token:isType(lexer.TokenType.StartTagClose) and not token:isType(lexer.TokenType.StartTagSelfClose) do
        if token:isType(lexer.TokenType.AttributeNoValue) then
            local attr = M.Attribute:new(token.text)
            table.insert(ret.attributes, attr)
            token = self.lexer:getNextToken()
        elseif token:isType(lexer.TokenType.AttributeLeft) then
            local attr = M.Attribute:new(token.text)
            token = self.lexer:getNextToken()
            if token:isType(lexer.TokenType.AttributeRight) then
                attr.value = token.text
            else
                attr.value = ""
                error("Expected attribute value")
            end
            table.insert(ret.attributes, attr)
            token = self.lexer:getNextToken()
        else
            error("Expected attribute")
        end
    end
    if token:isType(lexer.TokenType.StartTagSelfClose) then
        return ret
    end
    token = self.lexer:getNextToken()
    while not token:isType(lexer.TokenType.EndTag) do
        if token:isType(lexer.TokenType.Text) then
            ret:appendTextNode(token.text)
        elseif token:isType(lexer.TokenType.StartTagOpen) then
            local node = self:parseBlock()
            if node ~= nil then
                ret:appendNode(node)
            end
        end
        if token:isType(lexer.TokenType.EndOfFile) then
            error("Unexpected end of file")
        end
        token = self.lexer:getNextToken()
    end
    if token:isType(lexer.TokenType.EndTag) then
        if token.text ~= tagName then
            error("Expected end tag for " .. tagName .. " but got " .. token.text)
        end
    end
    return ret
end

---@param tree TSNode
---@return Banana.Ast?
function Parser:parseElement(tree)
    if tree:type() ~= M.ts_types.element then
        error("Did not pass an element into parseElement()")
    end
    --TODO: Account for self closing tags
    if tree:child_count() < 2 then
        error("Somehow an element does not have 2 children")
    end
    local firstChild = tree:child(0)
    local lastChild = tree:child(tree:child_count() - 1)
    if firstChild == nil or lastChild == nil then
        error("Unreachable")
    end
    if firstChild:type() ~= M.ts_types.start_tag then
        error("Unreachable")
    end
    if lastChild:type() ~= M.ts_types.end_tag then
        error("Unreachable")
    end
    local tagName = firstChild:child(1)
    if tagName == nil then
        error("Unreachable")
    end
    if tagName:type() ~= M.ts_types.tag_name then
        error("tagName does not have type tag_name, but instead has type " .. tagName:type())
    end
    local tagNameStr = self.lexer:getStrFromRange({ tagName:start() }, { tagName:end_() })
    local lastTagName = lastChild:child(1)
    if lastTagName == nil then
        error('Unreachable')
    end
    if lastTagName:type() ~= M.ts_types.tag_name then
        error("Unreachable")
    end
    local endTagNameStr = self.lexer:getStrFromRange({ lastTagName:start() }, { lastTagName:end_() })
    if tagNameStr ~= endTagNameStr then
        error("A start tag is not closed by the same tag (started with " ..
            tagNameStr .. " but ended with " .. endTagNameStr .. ")")
    end
    local ret = M.Ast:new(tagNameStr)

    return ret
end

---@return Banana.Ast?
function Parser:parse2()
    if self.tree == nil then
        return nil
    end
    ---@type TSNode
    local parsed = self.tree:root()
    if parsed:has_error() then
        return nil
    end
    if parsed:type() ~= "source_file" then
        return nil
    end
    if parsed:child_count() == 0 then
        return nil
    end
    -- Nml should support partial documents (like for insertion of subtrees)
    local fullDocMode = parsed:child(0):type() == M.ts_types.doctype
    if fullDocMode and parsed:child_count() > 2 then
        error("A full nml document should have only one tag (an <nml> tag)")
    end
    if fullDocMode and parsed:child_count() < 2 then
        error("A full nml document must have an <nml> tag")
    end
    if not fullDocMode and parsed:child_count() ~= 1 then
        error("A partial nml document should have only one element")
    end
    if not fullDocMode and parsed:child(0):type() ~= M.ts_types.element then
        error("A partial nml document should contain an element as the root node")
    end
    if fullDocMode then
        local child = parsed:child(1)
        if child == nil then
            error("Unreachable: parsed child is 0 in fullDocMode")
        end
        return self:parseElement(child)
    else
        local child = parsed:child(0)
        if child == nil then
            error("Unreachable: parsed child is 0 in not fullDocMode")
        end
        return self:parseElement(child)
    end
end

---@return Banana.Ast?
function Parser:parse()
    self:parse2()
    local token = self.lexer:getNextToken()
    if token:isType(lexer.TokenType.EndOfFile) then
        return nil
    end
    while token:isType(lexer.TokenType.Text) do
        token = self.lexer:getNextToken()
    end
    --- basically, the whole file is supposed to be in a block
    if token:isType(lexer.TokenType.StartTagOpen) then
        return self:parseBlock()
    end
    if not token:isType(lexer.TokenType.EndOfFile) then
        error("Unexpected token " .. token.text)
    end
    return nil
end

function Parser:reset()
    self.lexer.currentLine = 1
    self.lexer.currentCol = 1
    self.lexer.currentToken = nil
end

---@type TSTree?
local tree = nil

function M.getTree()
    return tree
end

---@return Banana.Parser?
M.fromFile = function(path)
    local file = io.open(path, "r")
    if file == nil then
        print("Failed to open code file")
        return nil
    end
    local content = file:read("*a")
    file:close()
    local buf = vim.api.nvim_create_buf(false, true)
    vim.api.nvim_set_option_value("modifiable", true, { buf = buf })
    vim.api.nvim_buf_set_lines(buf, 0, -1, false, vim.split(content, "\n"))
    vim.api.nvim_set_option_value("modifiable", false, { buf = buf })
    vim.api.nvim_set_option_value("modified", false, { buf = buf })
    vim.api.nvim_set_option_value("filetype", "nml", { buf = buf })
    vim.api.nvim_set_option_value("buflisted", false, { buf = buf })
    vim.api.nvim_set_option_value("swapfile", false, { buf = buf })
    vim.treesitter.start(buf, "nml")
    tree = vim.treesitter.get_parser(buf, "nml"):parse(true)[1]
    local parsed = tree:root()
    local children = parsed:child(0)
    if children == nil then
        error("y r u gay")
    end

    -- delete the buffer
    vim.api.nvim_buf_delete(buf, { force = true })

    local lex = lexer.fromPath(path)
    if lex == nil then
        print("Failed to open code file")
        return nil
    end

    local parser = Parser:new(lex, tree)
    return parser
end

return M
