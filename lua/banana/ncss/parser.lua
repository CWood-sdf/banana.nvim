local M = {}

local q = require('banana.ncss.query')

---@enum Banana.Ncss.TSTypes
M.ts_types = {
    function_name = "function_name",
    class_name = "class_name",
    property_name = "property_name",
    tag_name = "tag_name",
    charset_statement = "charset_statement",
    supports_statement = "supports_statement",
    stylesheet = "stylesheet",
    _top_level_item = "_top_level_item",
    import_statement = "import_statement",
    media_statement = "media_statement",
    namespace_statement = "namespace_statement",
    keyframes_statement = "keyframes_statement",
    keyframe_block_list = "keyframe_block_list",
    keyframe_block = "keyframe_block",
    from = "from",
    to = "to",
    postcss_statement = "postcss_statement",
    at_rule = "at_rule",
    rule_set = "rule_set",
    selectors = "selectors",
    block = "block",
    _block_item = "_block_item",
    _selector = "_selector",
    nesting_selector = "nesting_selector",
    universal_selector = "universal_selector",
    class_selector = "class_selector",
    pseudo_class_selector = "pseudo_class_selector",
    pseudo_element_selector = "pseudo_element_selector",
    id_selector = "id_selector",
    attribute_selector = "attribute_selector",
    child_selector = "child_selector",
    descendant_selector = "descendant_selector",
    sibling_selector = "sibling_selector",
    adjacent_sibling_selector = "adjacent_sibling_selector",
    namespace_selector = "namespace_selector",
    pseudo_class_arguments = "pseudo_class_arguments",
    pseudo_element_arguments = "pseudo_element_arguments",
    declaration = "declaration",
    last_declaration = "last_declaration",
    important = "important",
    _query = "_query",
    feature_query = "feature_query",
    parenthesized_query = "parenthesized_query",
    binary_query = "binary_query",
    unary_query = "unary_query",
    selector_query = "selector_query",
    -- _value = "_value",
    parenthesized_value = "parenthesized_value",
    color_value = "color_value",
    string_value = "string_value",
    integer_value = "integer_value",
    float_value = "float_value",
    boolean_value = "boolean_value",
    unit = "unit",
    grid_value = "grid_value",
    call_expression = "call_expression",
    binary_expression = "binary_expression",
    arguments = "arguments",
    identifier = "identifier",
    at_keyword = "at_keyword",
    js_comment = "js_comment",
    comment = "comment",
    plain_value = "plain_value",
}

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
        if col > #self.lines[row] then
            row = row + 1
            col = 1
        end
    end
    return ret
end

---@type { [Banana.Ncss.TSTypes]: fun(node: TSNode, parser: Banana.Ncss.ParseData): Banana.Ncss.Where|Banana.Ncss.Selector }
M.queryParsers = {
    [M.ts_types.pseudo_class_selector] = function(node, parser)
        local nameTag = node:child(2)
        if nameTag == nil then
            error("Expected class_name to not be nil")
        end
        if nameTag:type() ~= M.ts_types.class_name then
            error("Expected nameTag to have type class_name, got '" .. nameTag:type() .. "'")
        end

        local name = parser:getStringFromRange({ nameTag:start() }, { nameTag:end_() })


        return q.newWhere(function(ast)
            --TODO: Impl
            error("Please implement pseudo_class_selector")
            return true
        end)
    end,
    [M.ts_types.descendant_selector] = function(node, parser)
        local el = node:child(1)

        if el == nil then
            error("Expected el to not be nil in child_selector parser")
        end
        if el:type() ~= M.ts_types.tag_name then
            error("Expected el to have type 'tag_name', instead got '" .. el:type() .. "'")
        end
        local elName = parser:getStringFromRange({ el:start() }, { el:end_() })
        ---@type fun(ast: Banana.Ast, arr: Banana.Ast[]): Banana.Ast[]
        local sel = nil
        sel = function(ast, arr)
            if arr == nil then
                arr = {}
            end
            for _, v in ipairs(ast.nodes) do
                if type(v) == "string" then
                    goto continue
                end
                if v.tag == elName then
                    table.insert(arr, v)
                end
                sel(v, arr)
                ::continue::
            end
            return arr
        end

        return q.newManualSelector(sel)
    end,
    [M.ts_types.child_selector] = function(node, parser)
        local el = node:child(2)

        if el == nil then
            error("Expected el to not be nil in child_selector parser")
        end
        if el:type() ~= M.ts_types.tag_name then
            error("Expected el to have type 'tag_name', instead got '" .. el:type() .. "'")
        end
        local elName = parser:getStringFromRange({ el:start() }, { el:end_() })

        return q.newManualSelector(function(ast)
            local ret = {}
            for _, v in ipairs(ast.nodes) do
                if type(v) == "string" then
                    goto continue
                end
                ---@cast v Banana.Ast
                if v.tag == elName then
                    table.insert(ret, v)
                end
                ::continue::
            end
            return ret
        end)
    end,
    [M.ts_types.class_selector] = function(node, parser)
        local nameTag = node:child(2)
        if nameTag == nil then
            error("Expected class_name to not be nil")
        end
        if nameTag:type() ~= M.ts_types.class_name then
            error("Expected nameTag to have type class_name, got '" .. nameTag:type() .. "'")
        end

        local name = parser:getStringFromRange({ nameTag:start() }, { nameTag:end_() })


        return q.newWhere(function(ast)
            return ast:hasClass(name)
        end)
    end,

}

---@class (exact) Banana.Ncss.Value
---@field value number
---@field unit string
local Value = {
    value = 0,
    unit = "%",

}

--TODO: Need some sort of deferred value for calc

---@alias Banana.Ncss.StyleValue.Types "color"|"integer"|"plain"|"float"|"string"|"unit"|"boolean"

---@class (exact) Banana.Ncss.StyleValue
---@field value number|string|Banana.Ncss.Value|boolean
---@field type Banana.Ncss.StyleValue.Types
local StyleValue = {

}

--{
---@param value number
---@param unit string
---@return Banana.Ncss.StyleValue
local function newUnitValue(value, unit)
    ---@type Banana.Ncss.StyleValue
    local ret = {
        value = {
            value = value,
            unit = unit
        },
        type = "unit",
    }
    setmetatable(ret, { __index = StyleValue })
    return ret
end

---@param value string
---@return Banana.Ncss.StyleValue
local function newColorValue(value)
    ---@type Banana.Ncss.StyleValue
    local ret = {
        value = value,
        type = "color"
    }
    setmetatable(ret, { __index = StyleValue })
    return ret
end
---@param value boolean
---@return Banana.Ncss.StyleValue
local function newBoolValue(value)
    ---@type Banana.Ncss.StyleValue
    local ret = {
        value = value,
        type = "boolean"
    }
    setmetatable(ret, { __index = StyleValue })
    return ret
end

---@param value string
---@return Banana.Ncss.StyleValue
local function newStringValue(value)
    ---@type Banana.Ncss.StyleValue
    local ret = {
        value = value,
        type = "string"
    }
    setmetatable(ret, { __index = StyleValue })
    return ret
end

---@param value string
---@return Banana.Ncss.StyleValue
local function newPlainValue(value)
    ---@type Banana.Ncss.StyleValue
    local ret = {
        value = value,
        type = "plain"
    }
    setmetatable(ret, { __index = StyleValue })
    return ret
end

---@param value number
---@return Banana.Ncss.StyleValue
local function newIntegerValue(value)
    ---@type Banana.Ncss.StyleValue
    local ret = {
        value = value,
        type = "integer"
    }
    setmetatable(ret, { __index = StyleValue })
    return ret
end

---@param value number
---@return Banana.Ncss.StyleValue
local function newFloatValue(value)
    ---@type Banana.Ncss.StyleValue
    local ret = {
        value = value,
        type = "float",
    }
    setmetatable(ret, { __index = StyleValue })
    return ret
end

--}

---@class (exact) Banana.Ncss.StyleDeclaration
---@field name string
---@field values Banana.Ncss.StyleValue[]
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
    local ret = {
        query = query,
        declarations = declarations,
    }
    setmetatable(ret, {
        __index = RuleSet,
    })
    return ret
end

---@param tree TSNode
---@param parser Banana.Ncss.ParseData
---@param new fun(num: number): Banana.Ncss.StyleValue
---@return Banana.Ncss.StyleValue
local function parseNumValue(tree, parser, new)
    local unit = tree:child(0)
    local valueString = parser:getStringFromRange({ tree:start() }, { tree:end_() })
    if unit ~= nil then
        local unitStr = parser:getStringFromRange({ unit:start() }, { unit:end_() })

        local valStr = valueString:sub(1, #valueString - #unitStr)

        local val = tonumber(valStr)
        if val == nil then
            error("Value is nil (from value string of '" .. valStr .. "')")
        end
        return newUnitValue(val, unitStr)
    end
    local num = tonumber(valueString)
    if num == nil then
        error("Got a nil value when num parsing '" .. valueString .. "'")
    end
    return new(num)
end

---@class Banana.Ncss.Function
---@field argsCount number
---@field fn fun(params: Banana.Ncss.StyleValue[], parser: Banana.Ncss.ParseData): Banana.Ncss.StyleValue[]|Banana.Ncss.StyleValue
---@field argsType (Banana.Ncss.StyleValue.Types|Banana.Ncss.StyleValue.Types[])[]
local Function = {

}
---@param args number
---@param fn fun(params: Banana.Ncss.StyleValue[], parser: Banana.Ncss.ParseData): Banana.Ncss.StyleValue[]|Banana.Ncss.StyleValue
---@param argsType (Banana.Ncss.StyleValue.Types|Banana.Ncss.StyleValue.Types[])[]
function Function:new(fn, args, argsType)
    if #argsType ~= args then
        error("Could not match argument size to type size")
    end
    ---@type Banana.Ncss.Function
    local ret = {
        argsCount = args,
        fn = fn,
        argsType = argsType,
    }
    setmetatable(ret, { __index = Function })
    return ret
end

---@type { [string]: Banana.Ncss.Function}
local cssFunctions = {
    rgb = Function:new(function(params, _)
        local red = params[1].value
        local green = params[2].value
        local blue = params[3].value
        ---@cast red number
        ---@cast green number
        ---@cast blue number

        local num = red * 256 * 256 + green * 256 + blue
        return newColorValue(string.format("#%06x", num))
    end, 3, { "integer", "integer", "integer" }),

}
---@type { [string]: fun(tree: TSNode, parser: Banana.Ncss.ParseData, text: string): Banana.Ncss.StyleValue[]|Banana.Ncss.StyleValue }
local cssParsers = {
    integer_value = function(tree, parser, _)
        return parseNumValue(tree, parser, newIntegerValue)
    end,
    boolean_value = function(_, _, str)
        return newBoolValue(str == "true")
    end,
    float_value = function(tree, parser, _)
        return parseNumValue(tree, parser, newFloatValue)
    end,
    string_value = function(_, _, str)
        return newStringValue(str)
    end,
    plain_value = function(_, _, str)
        return newPlainValue(str)
    end,
    color_value = function(_, _, str)
        --TODO: Might need to process the string a lil bit
        return newColorValue(str)
    end,
    call_expression = function(tree, parser, _)
        local fNameNode = tree:child(0)
        if fNameNode == nil then
            error("function_name node is nil in call_expression")
        end
        if fNameNode:type() ~= M.ts_types.function_name then
            error("Expected fNameNode to be 'function_name' type, but got '" .. fNameNode:type() .. "'")
        end
        local fName = parser:getStringFromRange({ fNameNode:start() }, { fNameNode:end_() })
        local fn = cssFunctions[fName]
        if fn == nil then
            error("Could not find function definition for function '" .. fName .. "'")
        end
        local paramsNode = tree:child(1)
        if paramsNode == nil then
            error("Expected arguments node to not be nil")
        end
        if paramsNode:type() ~= M.ts_types.arguments then
            error("Expected paramsNode to have type 'arguments', instead got '" .. paramsNode:type() .. "'")
        end
        ---@type Banana.Ncss.StyleValue[]
        local params = {}
        local i = 0
        local param = paramsNode:child(i)
        while param ~= nil do
            local t = param:type()
            local value = nil
            if t == "(" or t == ")" or t == "," then
                goto continue
            end
            value = M.parseCssValue(param, parser)
            for _, v in ipairs(value) do
                table.insert(params, v)
            end
            ::continue::
            i = i + 1
            param = paramsNode:child(i)
        end
        if #params ~= fn.argsCount then
            error("Got incorrect number of arguments for function '" ..
                fName .. "', expected " .. fn.argsCount .. ", but got " .. #params)
        end
        for j, v in ipairs(params) do
            local pType = v.type
            local expected = fn.argsType[j]
            if type(expected) == "string" then
                assert(pType == expected,
                    "Expected type '" ..
                    expected ..
                    "' for parameter " .. j .. " of ncss function '" .. fName .. "', but got type '" .. pType .. "'")
            else
                local match = false
                for _, e in ipairs(expected) do
                    if e == pType then
                        match = true
                        break
                    end
                end
                if not match then
                    local arr2 = vim.tbl_map(function(s) return "'" .. s .. "', " end, expected)
                    local types = ""
                    for _, s in ipairs(arr2) do
                        types = types .. s
                    end
                    error("Can not match type '" ..
                        pType ..
                        "' to one of expected types " ..
                        types .. " in parameter " .. j .. " of ncss function '" .. fName .. "'")
                end
            end
        end
        return fn.fn(params, parser)
    end,
    parenthesized_value = function(tree, parser, _)
        local child = tree:child(1)
        if child == nil then
            error("Unreachable")
        end
        return M.parseCssValue(child, parser)
    end,
}

---@param tree TSNode
---@param parser Banana.Ncss.ParseData
---@return Banana.Ncss.StyleValue[]
function M.parseCssValue(tree, parser)
    local p = cssParsers[tree:type()]
    if p == nil then
        error("Could not find value parser for node of type '" .. tree:type() .. "'")
    end
    local str = parser:getStringFromRange({ tree:start() }, { tree:end_() })
    local ret = p(tree, parser, str)
    if ret == nil then
        error("Unreachable")
    end
    if ret[1] ~= nil then
        return ret
    end
    return { ret }
end

---@param name string
---@param value Banana.Ncss.StyleValue[]
function M.validateCssProperty(name, value)

end

---@param tree TSNode
---@param name string
---@param parser Banana.Ncss.ParseData
---@return Banana.Ncss.StyleValue[]
function M.parsePropValue(tree, name, parser)
    -- tree has type "block"
    local i = 1
    local child = tree:child(i)
    if child == nil then
        error("expected a value when parsing css property")
    end

    ---@type Banana.Ncss.StyleValue[]
    local ret = {}

    while child ~= nil do
        local text = nil
        local value = nil
        if child:type() == ";" then
            goto continue
        end
        text = parser:getStringFromRange({ child:start() }, { child:end_() })
        if text == ":" or text == "," or text == ";" then
            goto continue
        end

        value = M.parseCssValue(child, parser)
        for _, v in ipairs(value) do
            table.insert(ret, v)
        end

        ::continue::
        i = i + 1
        child = tree:child(i)
    end
    M.validateCssProperty(name, ret)

    return ret
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
        if child:type() == '{' or child:type() == '}' then
            goto continue
        end
        if child:type() ~= M.ts_types.declaration then
            error("Found a child that does not have type 'declaration' in a parseBlock tree (given type of '" ..
                child:type() .. "' from parent of type '" .. tree:type() .. "')")
        end
        propName = child:child(0)
        if propName == nil then
            error("propName is nil")
        end
        if propName:type() ~= M.ts_types.property_name then
            error("Expected propName to be type 'property', got '" .. propName:type() .. "'")
        end
        name = parser:getStringFromRange({ propName:start() }, { propName:end_() })
        values = M.parsePropValue(child, name, parser)
        ---@type Banana.Ncss.StyleDeclaration
        styleVal = {
            name = name,
            values = values,
        }
        table.insert(ret, styleVal)
        ::continue::
        i = i + 1
        child = tree:child(i)
    end
    return ret
end

---@param tree TSNode
---@param query Banana.Ncss.Query
---@param parser Banana.Ncss.ParseData
function M.parseQueryComponent(tree, query, parser)
    if tree:type() == M.ts_types.tag_name then
        local text = parser:getStringFromRange({ tree:start() }, { tree:end_() })
        query:setRootSelector(q.selectors.tag(text), true)
    else
        local child = tree:child(0)
        if child == nil then
            error("First child of '" .. tree:type() .. "' is nil")
        end
        M.parseQueryComponent(child, query, parser)
        local p = M.queryParsers[tree:type()]
        if p == nil then
            error("Could not find parser for '" .. tree:type() .. "'")
        end
        local comp = p(tree, parser)
        query:appendFilter(comp)
    end
end

---@param tree TSNode
---@param parser Banana.Ncss.ParseData
---@return Banana.Ncss.Query
function M.parseQuery(tree, parser)
    if tree:type() ~= M.ts_types.selectors then
        error("tree parsed into parseQuery does not have type selectors, instead got '" .. tree:type() .. "'")
    end
    local ret = q.newQuery()
    local child = tree:child(0)
    if child == nil then
        error("Could not find first child of tree type '" .. tree:type() .. "' in parseQuery()")
    end
    M.parseQueryComponent(child, ret, parser)

    return ret
end

---@param tree TSNode
---@param parser Banana.Ncss.ParseData
---@return Banana.Ncss.RuleSet
function M.parseRuleSet(tree, parser)
    local selectors = tree:child(0)
    if selectors == nil then
        error("Selectors in parseRuleSet is nil")
    end
    if selectors:type() ~= M.ts_types.selectors then
        error("Selectors in parseRuleSet does not have type selectors, instead got '" .. selectors:type() .. "'")
    end
    local block = tree:child(1)
    if block == nil then
        error("Block in parseRuleSet is nil")
    end
    if block:type() ~= M.ts_types.block then
        error("Block in parseRuleSet does not have type block, instead got '" .. block:type() .. "'")
    end

    local query = M.parseQuery(selectors, parser)
    local b = M.parseBlock(block, parser)
    return RuleSet:new(query, b)
end

---@param tree TSNode
---@param parser Banana.Ncss.ParseData
---@return Banana.Ncss.RuleSet[]
function M.parse(tree, parser)
    if tree:has_error() then
        error("omg there is an ncss parser error")
    end
    if tree:type() ~= M.ts_types.stylesheet then
        error("Parsed treesitter tree must be a stylesheet type for ncss parser")
    end
    local firstChild = tree:child(0)
    if firstChild == nil then
        error("stylesheet first child is nil")
    end
    if firstChild:type() == M.ts_types.block then
        local block = M.parseBlock(firstChild, parser)
        return { RuleSet:new(nil, block) }
    end
    if firstChild:type() == M.ts_types.declaration then
        local block = M.parseBlock(tree, parser)
        return { RuleSet:new(nil, block) }
    end
    if firstChild:type() == M.ts_types.rule_set then
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

---@param content string
function M.parseText(content)
    return M.parseLines(vim.split(content, '\n'))
end

function M.parseLines(lines)
    local buf = vim.api.nvim_create_buf(false, true)
    vim.api.nvim_set_option_value("modifiable", true, { buf = buf })
    vim.api.nvim_buf_set_lines(buf, 0, -1, false, lines)
    vim.api.nvim_set_option_value("modifiable", false, { buf = buf })
    vim.api.nvim_set_option_value("modified", false, { buf = buf })
    vim.api.nvim_set_option_value("filetype", "ncss", { buf = buf })
    vim.api.nvim_set_option_value("buflisted", false, { buf = buf })
    vim.api.nvim_set_option_value("swapfile", false, { buf = buf })
    vim.treesitter.start(buf, "ncss")
    local tree = vim.treesitter.get_parser(buf, "ncss"):parse(true)[1]
    local parsed = tree:root()
    local children = parsed:child(0)
    if children == nil then
        error("y r u gay")
    end

    -- delete the buffer
    vim.api.nvim_buf_delete(buf, { force = true })

    local parser = ParseData:new(lines)

    return M.parse(tree:root(), parser)
end

return M
