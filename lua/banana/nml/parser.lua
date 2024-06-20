local _str = require('banana.utils.string')
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
    substitution = "substitution",
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

local ast = require('banana.nml.ast')

---@class (exact) Banana.Highlight: vim.api.keyset.highlight
---@field __name string?

---@class (exact) Banana.Attributes
---@field [string] string?

---@class (exact) Banana.Nml.Parser
---@field lexer Banana.Lexer?
---@field tree TSTree?
---@field styleSets Banana.Ncss.RuleSet[]
---@field scripts string[]
---@field ncssParsers TSTree[]
---@field ncssInlineIndex number
---@field ncssBlockIndex number
local Parser = {
    lexer = nil,
    tree = nil,
    styleSets = {},
    scripts = {},
    ncssInlineIndex = 1,
    ncssBlockIndex = 1,
}

---@param lex Banana.Lexer
---@param tree TSTree
---@param ncssParsers TSTree[]
function Parser:new(lex, tree, ncssParsers)
    ---@type Banana.Nml.Parser
    local parser = {
        lexer = lex,
        tree = tree,
        styleSets = {},
        scripts = {},
        ncssParsers = ncssParsers,
        ncssInlineIndex = 1,
        ncssBlockIndex = 1,
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
---@return string,string?,Banana.Ncss.StyleDeclaration[]?
function Parser:parseAttribute(tree)
    local name = tree:child(0)
    assert(name ~= nil,
        "Unreachable")
    assert(name:type() == M.ts_types.attribute_name,
        "Unreachable")
    local nameStr = self:getStrFromNode(name)
    local value = nil
    if tree:child_count() >= 3 and nameStr == "style" then
        local ncssTree = self:getNextInlineNcssParser()
        local ncssParser = require('banana.ncss.parser').newParseData(self.lexer.program)
        local rules = require('banana.ncss.parser').parse(ncssTree, ncssParser)
        ---@type Banana.Ncss.StyleDeclaration[]
        local ret = {}
        for _, rule in ipairs(rules) do
            for _, decl in ipairs(rule.declarations) do
                table.insert(ret, decl)
            end
        end
        return nameStr, nil, ret
    elseif tree:child_count() >= 3 then
        local val = tree:child(2)
        ::top::
        assert(val ~= nil,
            "Unreachable")
        if val:type() == M.ts_types.attribute_value then
            value = self:getStrFromNode(val)
        elseif val:type() == M.ts_types.quoted_attribute_value then
            val = val:child(1)
            goto top
        end
    end

    return nameStr, value, nil
end

---@param tree TSNode
---@return Banana.Attributes, Banana.Ncss.StyleDeclaration[]
function Parser:parseAttributes(tree)
    assert(tree:type() == M.ts_types.start_tag or tree:type() == M.ts_types.self_closing_tag,
        "Must pass in a start_tag or self_closing_tag tree to parseAttributes")
    ---@type Banana.Attributes
    local ret = {}
    local i = 2
    ---@type Banana.Ncss.StyleDeclaration[]
    local decls = {}
    while i < tree:child_count() - 1 do
        local attr = tree:child(i)
        assert(attr ~= nil,
            "Unreachable")
        assert(attr:type() == M.ts_types.attribute,
            "An attribute was not given")
        local name, val, d = self:parseAttribute(attr)
        if d ~= nil then
            for _, v in ipairs(d) do
                table.insert(decls, v)
            end
        else
            ret[name] = val
        end
        i = i + 1
    end

    return ret, decls
end

---@param tree TSNode
---@param parent Banana.Ast
---@return Banana.Ast?
function Parser:parseSelfClosingTag(tree, parent)
    local child = tree:child(0)
    assert(child ~= nil,
        "Unreachable")
    local nameEl = child:child(1)
    assert(nameEl ~= nil,
        "Unreachable")
    assert(nameEl:type() == M.ts_types.tag_name,
        "Unreachable")
    local name = self.lexer:getStrFromRange({ nameEl:start() }, { nameEl:end_() })
    local ret = ast.Ast:new(name, parent)

    local attrs, decls = self:parseAttributes(child)
    ret.inlineStyle = decls
    ret.attributes = attrs

    return ret
end

---@return TSNode
function Parser:getNextBlockNcssParser()
    while require('banana.ncss.parser').treeIsInline(self.ncssParsers[self.ncssBlockIndex]:root()) do
        self.ncssBlockIndex = self.ncssBlockIndex + 1
    end
    local node = self.ncssParsers[self.ncssBlockIndex]:root()
    self.ncssBlockIndex = self.ncssBlockIndex + 1
    return node
end

---@return TSNode
function Parser:getNextInlineNcssParser()
    while not require('banana.ncss.parser').treeIsInline(self.ncssParsers[self.ncssInlineIndex]:root()) do
        self.ncssInlineIndex = self.ncssInlineIndex + 1
    end
    local node = self.ncssParsers[self.ncssInlineIndex]:root()
    self.ncssInlineIndex = self.ncssInlineIndex + 1
    return node
end

---@param tree TSNode
---@param parent Banana.Ast?
---@param isSpecial? boolean
---@return Banana.Ast?
function Parser:parseTag(tree, parent, isSpecial)
    isSpecial = isSpecial or false
    local firstChild = tree:child(0)
    local lastChild = tree:child(tree:child_count() - 1)
    assert(firstChild ~= nil and lastChild ~= nil,
        "Unreachable")
    assert(firstChild:type() == M.ts_types.start_tag,
        "Unreachable")
    assert(lastChild:type() == M.ts_types.end_tag or isSpecial,
        "Unreachable")
    local tagName = firstChild:child(1)
    assert(tagName ~= nil,
        "Unreachable")
    assert(tagName:type() == M.ts_types.tag_name,
        "tagName does not have type tag_name, but instead has type " .. tagName:type())
    local tagNameStr = self.lexer:getStrFromRange({ tagName:start() }, { tagName:end_() })
    local lastTagName = lastChild:child(1)
    assert(lastTagName ~= nil,
        'Unreachable')
    assert(lastTagName:type() == M.ts_types.tag_name,
        "Unreachable")
    local endTagNameStr = self.lexer:getStrFromRange({ lastTagName:start() }, { lastTagName:end_() })
    assert(tagNameStr == endTagNameStr,
        "A start tag is not closed by the same tag (started with " ..
        tagNameStr .. " but ended with " .. endTagNameStr .. ")")
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
        assert(parent ~= nil,
            "Parent is nil")
        ret = ast.Ast:new(tagNameStr, parent)
    end

    local attrs, decls = self:parseAttributes(firstChild)
    if ret ~= nil then
        ret.attributes = attrs
        ret.inlineStyle = decls
    end

    local i = 1
    while i < tree:child_count() - 1 do
        local child = tree:child(i)
        assert(child ~= nil,
            "Unreachable")
        if child:type() == M.ts_types.text then
            assert(ret ~= nil,
                "Unreachable")
            ret:appendTextNode(self:getStrFromNode(child))
        elseif child:type() == M.ts_types.element then
            ---@cast ret Banana.Ast
            local element = self:parseElement(child, ret)
            if element ~= nil then
                assert(ret ~= nil,
                    "Unreachable")
                ret:appendNode(element)
            end
        elseif child:type() == M.ts_types.entity then
            assert(ret ~= nil,
                "Unreachable")
            ret:appendTextNode(self:getStrFromNode(child))
        elseif child:type() == M.ts_types.substitution then
            assert(ret ~= nil,
                "Unreachable")
            ret:appendTextNode(self:getStrFromNode(child))
        elseif child:type() == M.ts_types.raw_text and isScript then
            local scriptStr = ""
            if attrs["src"] ~= nil then
                local req = attrs["src"]
                scriptStr = "@" .. req
            else
                scriptStr = self.lexer:getStrFromRange({ child:start() }, { child:end_() })
            end
            table.insert(self.scripts, scriptStr)
        elseif child:type() == M.ts_types.raw_text and isStyle then
            local ncssTree = self:getNextBlockNcssParser()
            local ncssParser = require('banana.ncss.parser').newParseData(self.lexer.program)
            local rules = require('banana.ncss.parser').parse(ncssTree, ncssParser)
            for _, rule in ipairs(rules) do
                table.insert(self.styleSets, rule)
            end
        elseif child:type() == M.ts_types.style_element then
            self:parseTag(child, ret, true)
        elseif child:type() == M.ts_types.script_element then
            self:parseTag(child, ret, true)
        elseif child:type() == M.ts_types.comment then
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
---@param parent Banana.Ast
---@return Banana.Ast?
function Parser:parseElement(tree, parent)
    assert(tree:type() == M.ts_types.element,
        "Did not pass an element into parseElement()")
    assert(tree:child_count() ~= 0,
        "Somehow an element does not have a child")
    if tree:child_count() == 1 then
        return self:parseSelfClosingTag(tree, parent)
    end
    return self:parseTag(tree, parent)
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
    assert(fullDocMode or parsed:child_count() == 1,
        "A partial nml document should have only one element")
    assert(fullDocMode or parsed:child(0):type() == M.ts_types.element,
        "A partial nml document should contain an element as the root node")
    local child = nil
    if fullDocMode then
        child = parsed:child(1)
        assert(child ~= nil,
            "Unreachable: parsed child is 0 in fullDocMode")
    else
        child = parsed:child(0)
        assert(child ~= nil,
            "Unreachable: parsed child is 0 in not fullDocMode")
    end
    local nilAst = require('banana.render').getNilAst()
    assert(nilAst ~= nil,
        "Nil ast is not defined")
    ---@diagnostic disable-next-line: cast-type-mismatch
    ---@cast nilAst Banana.Ast
    return self:parseElement(child, nilAst)
end

function Parser:reset()
    self.scripts = {}
    self.styleSets = {}
    self.lexer.currentLine = 1
    self.lexer.currentCol = 1
    self.ncssBlockIndex = 1
    self.ncssInlineIndex = 1
end

---@type TSTree?
local tree = nil

function M.getTree()
    return tree
end

---@param content string
---@return Banana.Nml.Parser
function M.fromString(content)
    require('banana').initTsParsers()
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
    local ncssChild = langTree:children()['ncss']
    local ncssParsers = {}
    if ncssChild ~= nil then
        ncssParsers = ncssChild:trees()
    end
    -- for _, v in ipairs(ncssParsers) do
    --
    -- end
    tree = arr[1]
    local parsed = tree:root()
    local children = parsed:child(0)
    assert(children ~= nil,
        "y r u gay")

    -- delete the buffer
    vim.api.nvim_buf_delete(buf, { force = true })

    local lex = lexer.fromString(content)

    local parser = Parser:new(lex, tree, ncssParsers)
    return parser
end

---@return Banana.Nml.Parser?
function M.fromFile(path)
    local file = io.open(path)
    if file == nil then
        print("Failed to open code file")
        return nil
    end
    local content = file:read("*a")
    file:close()
    return M.fromString(content)
end

return M
