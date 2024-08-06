---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
---@module 'banana.utils.string'
local _str = require("banana.lazyRequire")("banana.utils.string")
local M = {}
---@module 'banana.ncss.tsTypes'
local ts_types = require("banana.lazyRequire")("banana.ncss.tsTypes")
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
    local valueString = parser:getStringFromRange({ tree:start() },
        { tree:end_() })
    if unit ~= nil then
        local unitStr = parser:getStringFromRange({ unit:start() },
            { unit:end_() })

        local valStr = valueString:sub(1,
            _str.charWidth(valueString) - _str.charWidth(unitStr))

        local val = tonumber(valStr)
        if val == nil then
            log.throw(
                "Value is nil (from value string of '" .. valStr .. "')")
            error("")
        end
        return M.newUnitValue(val, unitStr)
    end
    local num = tonumber(valueString)
    if num == nil then
        log.throw(
            "Got a nil value when num parsing '" .. valueString .. "'")
        error("")
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
    if #argsType ~= args and args ~= -1 then
        log.throw(
            "Could not match argument size to type size")
        error("")
    end
    ---@type Banana.Ncss.Function
    local ret = {
        argsCount = args,
        fn = fn,
        argsType = argsType,
    }
    -- if args == -1 and #argsType ~= 1 then
    --     log.throw(
    --         "Got a parameter pack (arglen = -1) in Function:new for css function, but did not get 1 argument type (got " ..
    --         #argsType .. " argument types)")
    -- end
    setmetatable(ret, { __index = Function })
    return ret
end

---@type { [string]: Banana.Ncss.Function}
local cssFunctions = {
    ["repeat"] = Function:new(function (params, _)
        local count = params[1].value
        local ret = {}
        for i = 1, count do
            -- plus 1 to convert back to one base index
            -- plus 1 more because units start at index 2
            local index = (i - 1) % (#params - 1) + 2
            table.insert(ret, params[index])
        end
        return ret
    end, -1, { "integer", "unit" }),
    rgb = Function:new(function (params, _)
        local red = params[1].value
        local green = params[2].value
        local blue = params[3].value
        ---@cast red number
        ---@cast green number
        ---@cast blue number

        local num = red * 256 * 256 + green * 256 + blue
        return M.newColorValue(string.format("#%06x", num))
    end, 3, { "integer", "integer", "integer" }),
    ["hl-extract"] = Function:new(function (params, _)
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
    integer_value = function (tree, parser, _)
        return parseNumValue(tree, parser, M.newIntegerValue)
    end,
    boolean_value = function (_, _, str)
        return M.newBoolValue(str == "true")
    end,
    float_value = function (tree, parser, _)
        return parseNumValue(tree, parser, M.newFloatValue)
    end,
    string_value = function (_, _, str)
        str = str:sub(2, #str)
        str = str:sub(1, #str - 1)
        return M.newStringValue(str)
    end,
    plain_value = function (_, _, str)
        return M.newPlainValue(str)
    end,
    color_value = function (_, _, str)
        return M.newColorValue(str)
    end,
    call_expression = function (tree, parser, _)
        local fNameNode = tree:child(0)
        if fNameNode == nil then
            log.throw(
                "function_name node is nil in call_expression")
            error("")
        end
        if fNameNode:type() ~= ts_types.function_name then
            log.throw(
                "Expected fNameNode to be 'function_name' type, but got '" ..
                fNameNode:type() .. "'")
            error("")
        end
        local fName = parser:getStringFromRange({ fNameNode:start() },
            { fNameNode:end_() })
        local fn = cssFunctions[fName]
        if fn == nil then
            log.throw(
                "Could not find function definition for function '" ..
                fName .. "'")
            error("")
        end
        local paramsNode = tree:child(1)
        if paramsNode == nil then
            log.throw(
                "Expected arguments node to not be nil")
            error("")
        end
        if paramsNode:type() ~= ts_types.arguments then
            log.throw(
                "Expected paramsNode to have type 'arguments', instead got '" ..
                paramsNode:type() .. "'")
            error("")
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
        if #params ~= fn.argsCount and fn.argsCount ~= -1 then
            log.throw(
                "Got incorrect number of arguments for function '" ..
                fName ..
                "', expected " .. fn.argsCount .. ", but got " .. #params)
            error("")
        end
        if fn.argsCount == -1 and #params < #fn.argsType then
            log.throw(
                "Expected at least " ..
                #fn.argsType ..
                " parameters for function '" .. fName .. "', but got " .. #
                params)
            error("")
        end
        for j, v in ipairs(params) do
            local pType = v.type
            local expected = fn.argsType[j]
            if fn.argsCount == -1 then
                expected = fn.argsType[math.min(j, #fn.argsType)]
            end
            if type(expected) == "string" then
                if pType ~= expected then
                    log.throw(
                        "Expected type '" ..
                        expected ..
                        "' for parameter " ..
                        j ..
                        " of ncss function '" ..
                        fName .. "', but got type '" .. pType .. "'")
                    error("")
                end
            else
                local match = false
                for _, e in ipairs(expected) do
                    if e == pType then
                        match = true
                        break
                    end
                end
                if not match then
                    local arr2 = vim.tbl_map(
                    function (s) return "'" .. s .. "', " end, expected)
                    local types = ""
                    for _, s in ipairs(arr2) do
                        types = types .. s
                    end
                    error("Can not match type '" ..
                        pType ..
                        "' to one of expected types " ..
                        types ..
                        " in parameter " ..
                        j .. " of ncss function '" .. fName .. "'")
                end
            end
        end
        return fn.fn(params, parser)
    end,
    parenthesized_value = function (tree, parser, _)
        local child = tree:child(1)
        if child == nil then
            log.throw(
                "Unreachable")
            error("")
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
        log.throw(
            "Could not find value parser for node of type '" ..
            tree:type() .. "'")
        error("")
    end
    local str = parser:getStringFromRange({ tree:start() }, { tree:end_() })
    local ret = p(tree, parser, str)
    if ret == nil then
        log.throw(
            "Unreachable")
        error("")
    end
    if ret[1] ~= nil then
        return ret
    end
    return { ret }
end

return M
