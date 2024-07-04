local M = {}

local q = require('banana.ncss.query')
local ts_types = require('banana.ncss.tsTypes')
local valueParser = require('banana.ncss.valueParser')
local queryParser = require('banana.ncss.queryParser')


---@class (exact) Banana.Ncss.ParseData
---@field lines string[]
local ParseData = {
    lines = {}
}

---@param lines string[]
---@return Banana.Ncss.ParseData
function ParseData:new(lines)
    ---@type Banana.Ncss.ParseData
    local ret = {
        lines = lines,
    }
    setmetatable(ret, { __index = ParseData })
    return ret
end

function M.newParseData(lines)
    return ParseData:new(lines)
end

---@param left integer[]
---@param right integer[]
---@return string
function ParseData:getStringFromRange(left, right)
    local row = left[1] + 1
    local col = left[2] + 1
    local ret = ""
    while row < right[1] + 1 or col < right[2] + 1 do
        ret = ret .. self.lines[row]:sub(col, col)
        col = col + 1
        --- so treesitter returns bytes, not chars, so use # here
        if col > #self.lines[row] then
            row = row + 1
            col = 1
        end
    end
    return ret
end

---@class (exact) Banana.Ncss.StyleDeclaration
---@field name string
---@field values Banana.Ncss.StyleValue[]
---@field important boolean
local StyleDeclaration = {
    name = "",
    values = {}
}

---@class (exact) Banana.Ncss.RuleSet
---@field query Banana.Ncss.Query?
---@field declarations Banana.Ncss.StyleDeclaration[]
local RuleSet = {
    query = nil,
    declarations = {},
}

---@param query Banana.Ncss.Query?
---@param declarations Banana.Ncss.StyleDeclaration[]?
---@return Banana.Ncss.RuleSet
function RuleSet:new(query, declarations)
    ---@type Banana.Ncss.RuleSet
    local ret = {
        query = query,
        declarations = declarations or {},
    }
    setmetatable(ret, {
        __index = RuleSet,
    })
    return ret
end

---@param name string
---@param value Banana.Ncss.StyleValue[]
function M.validateCssProperty(name, value)
    local validations = require('banana.ncss.validations')
    assert(validations.validate(name, value),
        "Validation for property '" .. name .. "' failed")
end

---@param tree TSNode
---@param name string
---@param parser Banana.Ncss.ParseData
---@return Banana.Ncss.StyleValue[], boolean
function M.parsePropValue(tree, name, parser)
    -- tree has type "block"
    local i = 1
    local child = tree:child(i)
    assert(child ~= nil,
        "expected a value when parsing css property")

    local important = false

    ---@type Banana.Ncss.StyleValue[]
    local ret = {}

    while child ~= nil do
        local text = nil
        local value = nil
        if child:type() == ";" then
            goto continue
        end
        if child:type() == ts_types.important then
            important = true
            goto continue
        end
        text = parser:getStringFromRange({ child:start() }, { child:end_() })
        if text == ":" or text == "," or text == ";" then
            goto continue
        end

        value = valueParser.parseCssValue(child, parser)
        for _, v in ipairs(value) do
            table.insert(ret, v)
        end

        ::continue::
        i = i + 1
        child = tree:child(i)
    end
    M.validateCssProperty(name, ret)

    return ret, important
end

---@param tree TSNode
---@param parser Banana.Ncss.ParseData
---@return Banana.Ncss.StyleDeclaration[]
function M.parseBlock(tree, parser)
    -- can ignore the parent type because inline styles (stylsheet parent vs block parent)
    local i = 0
    local child = tree:child(i)
    ---@type Banana.Ncss.StyleDeclaration[]
    local ret = {}
    while child ~= nil do
        local propName = nil
        local name = nil
        local values = nil
        local styleVal = nil
        local important = nil
        local tp = child:type()
        if tp == '{' or tp == '}' or tp == ts_types.comment then
            goto continue
        end
        assert(tp == ts_types.declaration,
            "Found a child that does not have type 'declaration' in a parseBlock tree (given type of '" ..
            tp .. "' from parent of type '" .. tree:type() .. "')")
        propName = child:child(0)
        assert(propName ~= nil,
            "propName is nil")
        assert(propName:type() == ts_types.property_name,
            "Expected propName to be type 'property', got '" .. propName:type() .. "'")
        name = parser:getStringFromRange({ propName:start() }, { propName:end_() })
        values, important = M.parsePropValue(child, name, parser)
        ---@type Banana.Ncss.StyleDeclaration
        styleVal = {
            name = name,
            values = values,
            important = important,
        }
        table.insert(ret, styleVal)
        ::continue::
        i = i + 1
        child = tree:child(i)
    end
    return ret
end

---@param tree TSNode
---@param parser Banana.Ncss.ParseData
---@return Banana.Ncss.Query
function M.parseQuery(tree, parser)
    assert(tree:type() == ts_types.selectors,
        "tree parsed into parseQuery does not have type selectors, instead got '" .. tree:type() .. "'")
    local ret = q.newQuery()
    local child = tree:child(0)
    assert(child ~= nil,
        "Could not find first child of tree type '" .. tree:type() .. "' in parseQuery()")
    queryParser.parseQueryComponent(child, ret, parser)

    return ret
end

---@param tree TSNode
---@param parser Banana.Ncss.ParseData
---@return Banana.Ncss.RuleSet
function M.parseRuleSet(tree, parser)
    local selectors = tree:child(0)
    assert(selectors ~= nil,
        "Selectors in parseRuleSet is nil")
    assert(selectors:type() == ts_types.selectors,
        "Selectors in parseRuleSet does not have type selectors, instead got '" .. selectors:type() .. "'")
    local block = tree:child(1)
    assert(block ~= nil,
        "Block in parseRuleSet is nil")
    assert(block:type() == ts_types.block,
        "Block in parseRuleSet does not have type block, instead got '" .. block:type() .. "'")

    local query = M.parseQuery(selectors, parser)
    local b = M.parseBlock(block, parser)
    local ret = RuleSet:new(query, b)
    return ret
end

---@param tree TSNode
---@param parser Banana.Ncss.ParseData
---@return Banana.Ncss.RuleSet[]
function M.parse(tree, parser)
    assert(tree:type() == ts_types.stylesheet,
        "Parsed treesitter tree must be a stylesheet type for ncss parser")
    local firstChild = tree:child(0)
    if firstChild == nil then
        -- empty tag
        return {}
    end
    if firstChild:type() == ts_types.block then
        local block = M.parseBlock(firstChild, parser)
        return { RuleSet:new(nil, block) }
    end
    if firstChild:type() == ts_types.declaration then
        local block = M.parseBlock(tree, parser)
        return { RuleSet:new(nil, block) }
    end
    if firstChild:type() == ts_types.rule_set then
        local ret = {}
        local i = 1
        repeat
            local ruleSet = M.parseRuleSet(firstChild, parser)
            table.insert(ret, ruleSet)
            firstChild = tree:child(i)
            i = i + 1
        until firstChild == nil

        return ret
    end
    error("Could not parse given stylesheet bc expected block, declaration, or rule_set nodes but got '" ..
        firstChild:type() .. "'")
end

---@param tree TSNode
---@return boolean
function M.treeIsInline(tree)
    -- if tree:has_error() then
    --     error("omg there is an ncss parser error")
    -- end
    assert(tree:type() == ts_types.stylesheet,
        "Parsed treesitter tree must be a stylesheet type for ncss parser")
    local firstChild = tree:child(0)
    if firstChild == nil then
        vim.notify(
            "Empty inline styles/style tags could lead to undefined behavior in banana, please remove any style tags or inline styles that are empty or contain only whitespace\n",
            vim.log.levels.WARN)
        local startLine, _, _ = tree:start()
        local endLine = tree:end_()
        return startLine == endLine
    end
    if firstChild:type() == ts_types.declaration then
        return true
    end
    return false
end

---@param content string
---@return Banana.Ncss.RuleSet[]
function M.parseText(content)
    local parse = vim.treesitter.get_string_parser(content, "ncss", {

    })
    local tree = parse:parse(true)
    local parser = ParseData:new(vim.split(content, '\n'))
    return M.parse(tree[1]:root(), parser)
end

---@param name string
---@return Banana.Ncss.RuleSet[]
function M.parseFile(name)
    local f = io.open(name, "r")
    assert(f ~= nil,
        "File '" .. name .. "' does not exist")
    return M.parseText(f:read("*a"))
end

---@param lines string[]
---@return Banana.Ncss.RuleSet[]
function M.parseLines(lines)
    return M.parseText(vim.iter(lines):join("\n"))
end

return M
