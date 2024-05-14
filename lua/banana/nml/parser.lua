local lexer = require("banana.nml.lexer")
local M = {}

---@enum Banana.Nml.TSTypes
M.ts_types = {
    style_end_tag = "style_end_tag",
    style_element = "style_element",
    script_element = "script_element",
    raw_text = "raw_text",
    source_file = "source_file",
    doctype = "doctype",
    element = "element",
    entity = "entity",
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

---@class (exact) Banana.Highlight: vim.api.keyset.highlight
---@field _name string?

---@class (exact) Banana.Attributes
---@field [string] string?

---@class (exact) Banana.Ast
---@field nodes (string|Banana.Ast)[]
---@field tag string
---@field attributes Banana.Attributes
---@field actualTag Banana.TagInfo
---@field style Banana.Ncss.StyleDeclaration[]
---@field hl Banana.Highlight?
---@field padding number[]
---@field margin number[]
---@field classes? { [string]: boolean }
M.Ast = {
    nodes = {},
    tag = "",
    attributes = {},
    padding = {},
    margin = {},
    classes = nil,
}

---@param tag string
---@return Banana.Ast
function M.Ast:new(tag)
    ---@type Banana.Ast
    local ast = {
        nodes = {},
        tag = tag,
        actualTag = require("banana.nml.tags").makeTag(tag),
        attributes = {},
        padding = {},
        margin = {},
        style = {},
    }
    setmetatable(ast, { __index = M.Ast })
    return ast
end

---@param c string
---@return boolean
function M.Ast:hasClass(c)
    if self.classes == nil and self.attributes["class"] ~= nil then
        local arr = vim.split(self.attributes["class"], ' ')
        self.classes = {}
        for _, v in ipairs(arr) do
            self.classes[v] = true
        end
    elseif self.classes == nil then
        self.classes = {}
    end
    return self.classes[c] or false
end

---@param parentHl Banana.Highlight?
---@return Banana.Highlight
function M.Ast:mixHl(parentHl)
    local ret = {}

    for k, v in pairs(self.hl or {}) do
        ret[k] = v
    end
    for k, v in pairs(parentHl or {}) do
        if ret[k] == nil then
            ret[k] = v
        end
    end
    return ret
end

---@param declarations Banana.Ncss.StyleDeclaration[]
function M.Ast:applyStyleDeclarations(declarations)
    for _, v in ipairs(declarations) do
        if v.name:sub(1, 3) == "hl-" then
            self.hl = self.hl or {}
            local name = v.name:sub(4, #v.name)

            local value = v.values[1]
            if #v.values ~= 1 then
                error("Multiple values given to specific declaration '" .. name .. "'")
            end
            self.hl[name] = value.value
        end
    end
end

---@param name string
---@return string?
function M.Ast:getAttribute(name)
    return self.attributes[name]
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
---@field styleSets Banana.Ncss.RuleSet[]
---@field scripts string[]
---@field ncssParsers TSTree[]
---@field ncssIndex number
local Parser = {
    lexer = nil,
    tree = nil,
    styleSets = {},
    scripts = {},
    ncssIndex = 1,
}

---@param lex Banana.Lexer
---@param tree TSTree
---@param ncssParsers TSTree[]
function Parser:new(lex, tree, ncssParsers)
    ---@type Banana.Parser
    local parser = {
        lexer = lex,
        tree = tree,
        styleSets = {},
        scripts = {},
        ncssParsers = ncssParsers,
        ncssIndex = 1,
    }
    setmetatable(parser, { __index = Parser })
    return parser
end

---@param tree TSNode
---@return string
function Parser:getStrFromNode(tree)
    return self.lexer:getStrFromRange({ tree:start() }, { tree:end_() })
end

---@param tree TSNode
---@return string[]
function Parser:parseAttribute(tree)
    local name = tree:child(0)
    if name == nil then
        error("Unreachable")
    end
    if name:type() ~= M.ts_types.attribute_name then
        error("Unreachable")
    end
    local nameStr = self:getStrFromNode(name)
    local value = nil
    if tree:child_count() >= 3 then
        local val = tree:child(2)
        ::top::
        if val == nil then
            error("Unreachable")
        end
        if val:type() == M.ts_types.attribute_value then
            value = self:getStrFromNode(val)
        elseif val:type() == M.ts_types.quoted_attribute_value then
            val = val:child(1)
            goto top
        end
    end

    return { nameStr, value }
end

---@param tree TSNode
---@return Banana.Attributes
function Parser:parseAttributes(tree)
    if tree:type() ~= M.ts_types.start_tag and tree:type() ~= M.ts_types.self_closing_tag then
        error("Must pass in a start_tag or self_closing_tag tree to parseAttributes")
    end
    ---@type Banana.Attributes
    local ret = {}
    local i = 2
    while i < tree:child_count() - 1 do
        local attr = tree:child(i)
        if attr == nil then
            error("Unreachable")
        end
        if attr:type() ~= M.ts_types.attribute then
            error("An attribute was not given")
        end
        local a = self:parseAttribute(attr)
        ret[a[1]] = a[2]
        i = i + 1
    end

    return ret
end

---@param tree TSNode
---@return Banana.Ast?
function Parser:parseSelfClosingTag(tree)
    local child = tree:child(0)
    if child == nil then
        error("Unreachable")
    end
    local nameEl = child:child(1)
    if nameEl == nil then
        error("Unreachable")
    end
    if nameEl:type() ~= M.ts_types.tag_name then
        error("Unreachable")
    end
    local name = self.lexer:getStrFromRange({ nameEl:start() }, { nameEl:end_() })
    local ret = M.Ast:new(name)

    local attrs = self:parseAttributes(child)
    ret.attributes = attrs

    return ret
end

---@return TSNode
function Parser:getNextNcssParser()
    local node = self.ncssParsers[self.ncssIndex]:root()
    self.ncssIndex = self.ncssIndex + 1
    return node
end

---@param str string
---@return string
function Parser:resolveEntity(str)
    local stripped = str:sub(2, #str)
    ---TODO: process entity string
    return stripped
end

---@param tree TSNode
---@param isSpecial? boolean
---@return Banana.Ast?
function Parser:parseTag(tree, isSpecial)
    isSpecial = isSpecial or false
    local firstChild = tree:child(0)
    local lastChild = tree:child(tree:child_count() - 1)
    if firstChild == nil or lastChild == nil then
        error("Unreachable")
    end
    if firstChild:type() ~= M.ts_types.start_tag then
        error("Unreachable")
    end
    if lastChild:type() ~= M.ts_types.end_tag and not isSpecial then
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
    local isScript = false
    if tagNameStr == "script" then
        isScript = true
    end
    local isStyle = false
    if tagNameStr == "style" then
        isStyle = true
    end
    local ret = nil
    if not isScript and not isStyle then
        ret = M.Ast:new(tagNameStr)
    end

    local attrs = self:parseAttributes(firstChild)
    if ret ~= nil then
        ret.attributes = attrs
    end

    local i = 1
    while i < tree:child_count() - 1 do
        local child = tree:child(i)
        if child == nil then
            error("Unreachable")
        end
        if child:type() == M.ts_types.text then
            if ret == nil then
                error("Unreachable")
            end
            ret:appendTextNode(self:getStrFromNode(child))
        elseif child:type() == M.ts_types.element then
            local element = self:parseElement(child)
            if element ~= nil then
                if ret == nil then
                    error("Unreachable")
                end
                ret:appendNode(element)
            end
        elseif child:type() == M.ts_types.entity then
            if ret == nil then
                error("Unreachable")
            end
            ret:appendTextNode(self:resolveEntity(self:getStrFromNode(child)))
        elseif child:type() == M.ts_types.raw_text and isScript then
            local scriptStr = self.lexer:getStrFromRange({ child:start() }, { child:end_() })
            table.insert(self.scripts, scriptStr)
        elseif child:type() == M.ts_types.raw_text and isStyle then
            local ncssTree = self:getNextNcssParser()
            local ncssParser = require('banana.ncss.parser').newParseData(self.lexer.program)
            local rules = require('banana.ncss.parser').parse(ncssTree, ncssParser)
            for _, rule in ipairs(rules) do
                table.insert(self.styleSets, rule)
            end
        elseif child:type() == M.ts_types.style_element then
            self:parseTag(child, true)
        elseif child:type() == M.ts_types.script_element then
            self:parseTag(child, true)
        else
            error("Node type " .. child:type() .. " not allowed when parsing tag body")
        end
        i = i + 1
    end
    if isScript or isStyle then
        return nil
    end

    return ret
end

---@param tree TSNode
---@return Banana.Ast?
function Parser:parseElement(tree)
    if tree:type() ~= M.ts_types.element then
        error("Did not pass an element into parseElement()")
    end
    if tree:child_count() == 0 then
        error("Somehow an element does not have a child")
    end
    if tree:child_count() == 1 then
        return self:parseSelfClosingTag(tree)
    end
    return self:parseTag(tree)
end

---@return Banana.Ast?
function Parser:parse()
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
    local child = nil
    if fullDocMode then
        child = parsed:child(1)
        if child == nil then
            error("Unreachable: parsed child is 0 in fullDocMode")
        end
    else
        child = parsed:child(0)
        if child == nil then
            error("Unreachable: parsed child is 0 in not fullDocMode")
        end
    end
    return self:parseElement(child)
end

function Parser:reset()
    self.lexer.currentLine = 1
    self.lexer.currentCol = 1
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
    local langTree = vim.treesitter.get_parser(buf, "nml")
    local arr = langTree:parse(true)
    local ncssParsers = langTree:children().ncss:parse(true)
    tree = arr[1]
    local parsed = tree:root()
    local children = parsed:child(0)
    if children == nil then
        error("y r u gay")
    end

    -- delete the buffer
    vim.api.nvim_buf_delete(buf, { force = true })

    local lex = lexer.fromString(content)

    local parser = Parser:new(lex, tree, ncssParsers)
    return parser
end

return M
