---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
---@module "banana.nml.lexer"
local lexer = require("banana.lazyRequire")("banana.nml.lexer")
---@module 'banana.nml.tag'
local _tag = require("banana.lazyRequire")("banana.nml.tag")
local M = {}

local parsingStack = {}

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

local ast = require("banana.nml.ast")

---@class (exact) Banana.Attributes
---@field [string] string?

---@class (exact) Banana.Component
---@field ast Banana.Ast
---@field styles Banana.Ncss.RuleSet[]
---@field scripts string[]
---@field name string

---@class (exact) Banana.Nml.Parser
---@field lexer Banana.Lexer?
---@field tree TSTree?
---@field styleSets Banana.Ncss.RuleSet[]
---@field scripts string[]
---@field ncssParsers TSTree[]
---@field ncssInlineIndex number
---@field ncssBlockIndex number
---@field currentComponent Banana.Component?
---@field source string
local Parser = {
    lexer = nil,
    tree = nil,
    styleSets = {},
    scripts = {},
    ncssInlineIndex = 1,
    ncssBlockIndex = 1,
}

---@param str string
---@return boolean, string
function M.isValidComponentName(str)
    if #str == 0 then
        return false, "component name must have at least one character"
    end
    local firstChar = str:sub(1, 1)
    if string.upper(firstChar) ~= firstChar and firstChar ~= "_" then
        return false, "component name must start with uppercase or underscore"
    end
    return str:match("^[%w_-]*$"),
        "component must only contain words, underscore, and -"
end

---@param lex Banana.Lexer
---@param tree TSTree
---@param ncssParsers TSTree[]
---@param source string
function Parser:new(lex, tree, ncssParsers, source)
    ---@type Banana.Nml.Parser
    local parser = {
        lexer = lex,
        tree = tree,
        styleSets = {},
        scripts = {},
        ncssParsers = ncssParsers,
        ncssInlineIndex = 1,
        ncssBlockIndex = 1,
        source = source
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
    if name == nil then
        log.throw(
            "Unreachable")
        error("")
    end
    if name:type() ~= M.ts_types.attribute_name then
        log.throw(
            "Unreachable")
        error("")
    end
    local nameStr = self:getStrFromNode(name)
    local value = nil
    if tree:child_count() >= 3 and nameStr == "style" then
        local ncssTree = self:getNextInlineNcssParser()
        local ncssParser = require("banana.ncss.parser").newParseData(self.lexer
                                                                          .program)
        local rules = require("banana.ncss.parser").parse(ncssTree, ncssParser)
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
        if val == nil then
            log.throw(
                "Unreachable")
            error("")
        end
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
    if tree:type() ~= M.ts_types.start_tag and tree:type() ~= M.ts_types.self_closing_tag then
        log.throw(
            "Must pass in a start_tag or self_closing_tag tree to parseAttributes")
        error("")
    end
    ---@type Banana.Attributes
    local ret = {}
    local i = 2
    ---@type Banana.Ncss.StyleDeclaration[]
    local decls = {}
    while i < tree:child_count() - 1 do
        local attr = tree:child(i)
        if attr == nil then
            log.throw(
                "Unreachable")
            error("")
        end
        if attr:type() ~= M.ts_types.attribute then
            log.throw(
                "An attribute was not given")
            error("")
        end
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
    if child == nil then
        log.throw(
            "Unreachable")
        error("")
    end
    local nameEl = child:child(1)
    if nameEl == nil then
        log.throw(
            "Unreachable")
        error("")
    end
    if nameEl:type() ~= M.ts_types.tag_name then
        log.throw(
            "Unreachable")
        error("")
    end
    local name = self.lexer:getStrFromRange({ nameEl:start() }, { nameEl:end_() })
    local ret = ast.Ast:new(name, parent, self.source)

    local attrs, decls = self:parseAttributes(child)
    ret.inlineStyle = decls
    ret.attributes = attrs

    return ret
end

---@return TSNode
function Parser:getNextBlockNcssParser()
    while require("banana.ncss.parser").treeIsInline(self.ncssParsers[self.ncssBlockIndex]:root()) do
        self.ncssBlockIndex = self.ncssBlockIndex + 1
    end
    local node = self.ncssParsers[self.ncssBlockIndex]:root()
    self.ncssBlockIndex = self.ncssBlockIndex + 1
    return node
end

---@return TSNode
function Parser:getNextInlineNcssParser()
    while not require("banana.ncss.parser").treeIsInline(self.ncssParsers[self.ncssInlineIndex]:root()) do
        self.ncssInlineIndex = self.ncssInlineIndex + 1
    end
    local node = self.ncssParsers[self.ncssInlineIndex]:root()
    self.ncssInlineIndex = self.ncssInlineIndex + 1
    return node
end

---@param tree TSNode
---@param parent Banana.Ast?
---@param isSpecial? boolean
---@return Banana.Ast?, Banana.Component[]?
function Parser:parseTag(tree, parent, isSpecial)
    -- we need to say when tag == <template>, create a component, set the
    -- current tracked component to that then continue parsing as normal
    isSpecial = isSpecial or false
    local firstChild = tree:child(0)
    local lastChild = tree:child(tree:child_count() - 1)
    ---@type Banana.Component[]?
    local components = nil
    if firstChild == nil or lastChild == nil then
        log.throw(
            "Unreachable")
        error("")
    end
    if firstChild:type() ~= M.ts_types.start_tag then
        log.throw(
            "Unreachable")
        error("")
    end
    if lastChild:type() ~= M.ts_types.end_tag and not isSpecial then
        log.throw(
            "Unreachable")
        error("")
    end
    local tagName = firstChild:child(1)
    if tagName == nil then
        log.throw(
            "Unreachable")
        error("")
    end
    if tagName:type() ~= M.ts_types.tag_name then
        log.throw(
            "tagName does not have type tag_name, but instead has type " ..
            tagName:type())
        error("")
    end
    local tagNameStr = self.lexer:getStrFromRange({ tagName:start() },
        { tagName:end_() })


    local lastTagName = lastChild:child(1)
    if lastTagName == nil then
        log.throw(
            "Unreachable")
        error("")
    end
    if lastTagName:type() ~= M.ts_types.tag_name then
        log.throw(
            "Unreachable")
        error("")
    end
    local endTagNameStr = self.lexer:getStrFromRange({ lastTagName:start() },
        { lastTagName:end_() })
    if tagNameStr ~= endTagNameStr then
        log.throw(
            "A start tag is not closed by the same tag (started with " ..
            tagNameStr .. " but ended with " .. endTagNameStr .. ")")
        error("")
    end
    local isScript = false
    if tagNameStr == "script" then
        isScript = true
    end
    local isStyle = false
    if tagNameStr == "style" then
        isStyle = true
    end
    local isTemplate = tagNameStr == "template"
    local ret = nil
    if not isScript and not isStyle then
        if parent == nil then
            log.throw(
                "Parent is nil")
            error("")
        end
        ret = ast.Ast:new(tagNameStr, parent, self.source)
    end

    local attrs, decls = self:parseAttributes(firstChild)
    if ret ~= nil then
        ret.attributes = attrs
        ret.inlineStyle = decls
    end
    local scriptStr = ""
    if attrs["src"] ~= nil and isScript then
        local req = attrs["src"]
        scriptStr = "@" .. req
        local tbl = self.scripts
        if self.currentComponent ~= nil then
            tbl = self.currentComponent.scripts
        end
        table.insert(tbl, scriptStr)
    end

    if attrs["import"] ~= nil and isTemplate then
        -- im assuming parent is nil in template only files
        if parent == nil then
            log.throw(
                "an import tag statement is not allowed to be the only tag in a file")
            error()
        end
        local root = nil
        if attrs["onparent"] ~= nil then
            root = parent
        else
            root = parent:root()
        end
        root.componentPath = root.componentPath or nil
        table.insert(root.componentPath,
            require("banana.require").getPathForRequire(attrs["import"], "nml"))
        return nil, components
    elseif attrs["use-imports-from"] ~= nil and isTemplate then
        if parent == nil then
            log.throw(
                "an import tag statement is not allowed to be the only tag in a file")
            error()
        end
        local root = nil
        if attrs["onparent"] ~= nil then
            root = parent
        else
            root = parent:root()
        end

        root.componentPath = root.componentPath or nil
        local componentAst = require("banana.require").nmlRequire(attrs
            ["use-imports-from"])
        for _, v in ipairs(componentAst.componentPath or {}) do
            table.insert(root.componentPath, v)
        end
        return nil, components
    elseif isTemplate then
        if attrs["name"] == nil then
            log.throw("Component must have a filled out name property")
            error()
        end
        if self.currentComponent ~= nil then
            log.throw("template tags cannot be nested")
        end
        ret._parent = require("banana.instance").getNilAst()
        local g, err = M.isValidComponentName(attrs["name"])
        if not g then
            log.throw(err)
            error()
        end
        self.currentComponent = {
            ---@diagnostic disable-next-line: assign-type-mismatch
            ast = ret,
            styles = {},
            scripts = {},
            name = attrs["name"]
        }
    end

    local i = 1
    while i < tree:child_count() - 1 do
        local child = tree:child(i)
        if child == nil then
            log.throw(
                "Unreachable")
            error("")
        end
        if child:type() == M.ts_types.text then
            if ret == nil then
                log.throw(
                    "Unreachable")
                error("")
            end
            ret:appendTextNode(self:getStrFromNode(child))
        elseif child:type() == M.ts_types.element then
            ---@cast ret Banana.Ast
            local element, comps = self:parseElement(child, ret)
            if comps ~= nil then
                if components ~= nil then
                    for _, v in ipairs(comps) do
                        table.insert(components, v)
                    end
                else
                    components = comps
                end
            end
            if element ~= nil then
                if ret == nil then
                    log.throw(
                        "Unreachable")
                    error("")
                end
                ret:appendNode(element)
            end
        elseif child:type() == M.ts_types.entity then
            if ret == nil then
                log.throw(
                    "Unreachable")
                error("")
            end
            ret:appendTextNode(self:getStrFromNode(child))
        elseif child:type() == M.ts_types.substitution then
            if ret == nil then
                log.throw(
                    "Unreachable")
                error("")
            end
            ret:appendTextNode(self:getStrFromNode(child))
        elseif child:type() == M.ts_types.raw_text and isScript then
            scriptStr = self.lexer:getStrFromRange({ child:start() },
                { child:end_() })
            local set = self.scripts

            if self.currentComponent ~= nil then
                set = self.currentComponent.scripts
            end
            if scriptStr ~= "" then
                table.insert(set, scriptStr)
            end
        elseif child:type() == M.ts_types.raw_text and isStyle then
            local ncssTree = self:getNextBlockNcssParser()
            local ncssParser = require("banana.ncss.parser").newParseData(self
                .lexer.program)
            local rules = require("banana.ncss.parser").parse(ncssTree,
                ncssParser)

            local set = self.styleSets
            if self.currentComponent ~= nil then
                set = self.currentComponent.styles
            end
            for _, rule in ipairs(rules) do
                table.insert(set, rule)
            end
        elseif child:type() == M.ts_types.style_element then
            self:parseTag(child, ret, true)
        elseif child:type() == M.ts_types.script_element then
            self:parseTag(child, ret, true)
        elseif child:type() == M.ts_types.comment then
        else
            error("Node type " ..
                child:type() .. " not allowed when parsing tag body")
        end
        i = i + 1
    end
    if isScript or isStyle then
        return nil
    end
    if isTemplate then
        components = components or {}
        local allInline = true
        local selfClosing = true
        for v in self.currentComponent.ast:childIter() do
            if v.actualTag.formatType ~= _tag.FormatType.Inline then
                allInline = false
            end
            if v.tag == "slot" then
                selfClosing = false
            end
        end
        self.currentComponent.ast.actualTag.selfClosing = selfClosing
        if allInline then
            self.currentComponent.ast.actualTag.formatType = require(
                "banan.nml.render").FormatType.Inline
        end
        table.insert(components, 1, self.currentComponent)
        self.currentComponent = nil
        return nil, components
    end

    return ret, components
end

---@param tree TSNode
---@param parent Banana.Ast
---@return Banana.Ast?, Banana.Component[]?
function Parser:parseElement(tree, parent)
    if tree:type() ~= M.ts_types.element then
        log.throw(
            "Did not pass an element into parseElement()")
        error("")
    end
    if tree:child_count() == 0 then
        log.throw(
            "Somehow an element does not have a child")
        error("")
    end
    if tree:child_count() == 1 then
        return self:parseSelfClosingTag(tree, parent)
    end
    return self:parseTag(tree, parent)
end

---@return Banana.Ast?, Banana.Component[]?
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
        log.throw(
            "A partial nml document should have only one element")
        error("")
    end
    if not fullDocMode and parsed:child(0):type() ~= M.ts_types.element then
        log.throw(
            "A partial nml document should contain an element as the root node")
        error("")
    end
    local child = nil
    if fullDocMode then
        child = parsed:child(1)
        if child == nil then
            log.throw(
                "Unreachable: parsed child is 0 in fullDocMode")
            error("")
        end
    else
        child = parsed:child(0)
        if child == nil then
            log.throw(
                "Unreachable: parsed child is 0 in not fullDocMode")
            error("")
        end
    end
    local nilAst = require("banana.instance").getNilAst()
    if nilAst == nil then
        log.throw(
            "Nil ast is not defined")
        error("")
    end
    if vim.tbl_contains(parsingStack, self.source) then
        log.throw(
            "Cyclic parsing (probably from recursive use-imports-from) in file '" ..
            self.source .. "'")
    end
    table.insert(parsingStack, self.source)
    ---@diagnostic disable-next-line: cast-type-mismatch
    ---@cast nilAst Banana.Ast
    local ok, v, v2 = pcall(self.parseElement, self, child, nilAst)
    table.remove(parsingStack, #parsingStack)
    if not ok then
        error(v)
    end
    return v, v2
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
---@param source? string
---@return Banana.Nml.Parser
function M.fromString(content, source)
    source = source or "@@string"
    require("banana").initTsParsers()
    local arr = nil
    local langTree = nil
    local ok, _ = pcall(function ()
        langTree = vim.treesitter.get_string_parser(content, "nml", {})
        arr = langTree:parse(true)
    end)
    if not ok then
        require("banana").installTsParsers()
        langTree = vim.treesitter.get_string_parser(content, "nml", {})
        arr = langTree:parse(true)
    end
    if langTree == nil or arr == nil then
        log.throw("Could not parse nml tree")
        error("")
    end
    local ncssChild = langTree:children()["ncss"]
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
    if children == nil then
        log.throw(
            "found no children")
        error("")
    end

    -- delete the buffer

    local lex = lexer.fromString(content)

    local parser = Parser:new(lex, tree, ncssParsers, source)
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
    return M.fromString(content, path)
end

return M
