local _str = require('banana.utils.string')
local M = {}
local ts_types = require('banana.ncss.tsTypes')
---@class (exact) Banana.Ncss.UnitValue
---@field value number
---@field unit string
---@field computed number|nil
local Value = {
    value = 0,
    unit = "%",

}


---@alias Banana.Ncss.StyleValue.Types "color"|"integer"|"plain"|"float"|"string"|"unit"|"boolean"

---@alias Banana.Ncss.StyleValueType number|string|Banana.Ncss.UnitValue|boolean

---@class (exact) Banana.Ncss.StyleValue
---@field value Banana.Ncss.StyleValueType
---@field type Banana.Ncss.StyleValue.Types
local StyleValue = {

}

--{
---@param value number
---@param unit string
---@return Banana.Ncss.StyleValue
function M.newUnitValue(value, unit)
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
function M.newColorValue(value)
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
function M.newBoolValue(value)
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
function M.newStringValue(value)
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
function M.newPlainValue(value)
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
function M.newIntegerValue(value)
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
function M.newFloatValue(value)
    ---@type Banana.Ncss.StyleValue
    local ret = {
        value = value,
        type = "float",
    }
    setmetatable(ret, { __index = StyleValue })
    return ret
end

--}

---@param tree TSNode
---@param parser Banana.Ncss.ParseData
---@param new fun(num: number): Banana.Ncss.StyleValue
---@return Banana.Ncss.StyleValue
local function parseNumValue(tree, parser, new)
    local unit = tree:child(0)
    local valueString = parser:getStringFromRange({ tree:start() }, { tree:end_() })
    if unit ~= nil then
        local unitStr = parser:getStringFromRange({ unit:start() }, { unit:end_() })

        local valStr = valueString:sub(1, _str.charCount(valueString) - _str.charCount(unitStr))

        local val = tonumber(valStr)
        assert(val ~= nil,
            "Value is nil (from value string of '" .. valStr .. "')")
        return M.newUnitValue(val, unitStr)
    end
    local num = tonumber(valueString)
    assert(num ~= nil,
        "Got a nil value when num parsing '" .. valueString .. "'")
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
    assert(#argsType == args,
        "Could not match argument size to type size")
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
        return M.newColorValue(string.format("#%06x", num))
    end, 3, { "integer", "integer", "integer" }),
    ["hl-extract"] = Function:new(function(params, _)
        local section = params[1].value
        local hl = params[2].value
        ---@cast hl string
        ---@cast section string
        if not vim.fn.hlexists(hl) then
            return {
                value = "inherit",
                type = "plain"
            }
        end
        local hlVal = vim.api.nvim_get_hl(0, {
            name = hl
        })
        local col = hlVal[section]
        if col == nil then
            return {
                value = "inherit",
                type = "plain"
            }
        end
        return M.newColorValue(string.format("#%06x", col))
    end, 2, { { "string", "plain" }, { "string", "plain" } })

}
---@type { [string]: fun(tree: TSNode, parser: Banana.Ncss.ParseData, text: string): Banana.Ncss.StyleValue[]|Banana.Ncss.StyleValue }
local cssParsers = {
    integer_value = function(tree, parser, _)
        return parseNumValue(tree, parser, M.newIntegerValue)
    end,
    boolean_value = function(_, _, str)
        return M.newBoolValue(str == "true")
    end,
    float_value = function(tree, parser, _)
        return parseNumValue(tree, parser, M.newFloatValue)
    end,
    string_value = function(_, _, str)
        str = str:sub(2, #str)
        str = str:sub(1, #str - 1)
        return M.newStringValue(str)
    end,
    plain_value = function(_, _, str)
        return M.newPlainValue(str)
    end,
    color_value = function(_, _, str)
        return M.newColorValue(str)
    end,
    call_expression = function(tree, parser, _)
        local fNameNode = tree:child(0)
        assert(fNameNode ~= nil,
            "function_name node is nil in call_expression")
        assert(fNameNode:type() == ts_types.function_name,
            "Expected fNameNode to be 'function_name' type, but got '" .. fNameNode:type() .. "'")
        local fName = parser:getStringFromRange({ fNameNode:start() }, { fNameNode:end_() })
        local fn = cssFunctions[fName]
        assert(fn ~= nil,
            "Could not find function definition for function '" .. fName .. "'")
        local paramsNode = tree:child(1)
        assert(paramsNode ~= nil,
            "Expected arguments node to not be nil")
        assert(paramsNode:type() == ts_types.arguments,
            "Expected paramsNode to have type 'arguments', instead got '" .. paramsNode:type() .. "'")
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
        assert(#params == fn.argsCount,
            "Got incorrect number of arguments for function '" ..
            fName .. "', expected " .. fn.argsCount .. ", but got " .. #params)
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
        assert(child ~= nil,
            "Unreachable")
        return M.parseCssValue(child, parser)
    end,
}

---@param tree TSNode
---@param parser Banana.Ncss.ParseData
---@return Banana.Ncss.StyleValue[]
function M.parseCssValue(tree, parser)
    local p = cssParsers[tree:type()]
    assert(p ~= nil,
        "Could not find value parser for node of type '" .. tree:type() .. "'")
    local str = parser:getStringFromRange({ tree:start() }, { tree:end_() })
    local ret = p(tree, parser, str)
    assert(ret ~= nil,
        "Unreachable")
    if ret[1] ~= nil then
        return ret
    end
    return { ret }
end

return M
