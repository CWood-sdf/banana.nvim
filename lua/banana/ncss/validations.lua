---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
---@alias Banana.Ncss.PropertyValidation.Type string|Banana.Ncss.StyleValue.Types

---@class (exact) Banana.Ncss.PropertyValidation
---@field validations? { [integer|"*"]: Banana.Ncss.PropertyValidation.Type[][] }
---@field custom? fun(value: Banana.Ncss.StyleValue[]): boolean
local Validation = {

}


---@param val { [integer|"*"]: Banana.Ncss.PropertyValidation.Type[][] }|fun(value: Banana.Ncss.StyleValue[]): boolean
---@return Banana.Ncss.PropertyValidation
function Validation:new(val)
    -- PERF: Possible optimization: store things in map instead of array

    ---@type Banana.Ncss.PropertyValidation
    local ret = nil
    if type(val) == "table" then
        for k, v in pairs(val) do
            for _, y in ipairs(v) do
                if #y ~= k and k ~= "*" then
                    log.throw(
                        "Validation does not have the proper size")
                    error("")
                end
            end
        end
        ret = {
            validations = val
        }
    else
        ret = {
            custom = val,
        }
    end
    setmetatable(ret, {
        __index = Validation,
    })
    return ret
end

---@param value Banana.Ncss.StyleValue[]
---@param name string
---@return boolean
function Validation:passes(value, name)
    if self.custom ~= nil then
        return self.custom(value)
    end
    local validations = self.validations[#value]
    local isStar = false
    if validations == nil then
        validations = self.validations["*"]
        isStar = true
    end
    if validations == nil then
        log.throw(
            "No validation for size " ..
            #value .. " exists for property '" .. name .. "'")
        error("")
    end
    for _, v in ipairs(validations) do
        local passes = true
        for i, tp in ipairs(v) do
            if tp:sub(1, 1) == "|" then
                if value[i].type ~= "plain" then
                    passes = false
                    break
                end
                if tp ~= "|" .. value[i].value then
                    passes = false
                    break
                end
            elseif tp ~= value[i].type then
                passes = false
                break
            end
        end
        if passes then return true end
    end
    local msg = "Validation for property " .. name .. " failed. Expected:\n"
    for _, v in ipairs(validations) do
        local line = "  "
        for _, tp in ipairs(v) do
            if tp:sub(1, 1) == "|" then
                tp = tp:sub(2, #tp)
                tp = "'" .. tp .. "'"
            end
            line = line .. tp .. ", or"
        end
        line = line .. "\n"
        msg = msg .. line
    end
    msg = msg .. "but got:\n  "
    for _, v in ipairs(value) do
        if v.type == "plain" then
            msg = msg .. v.type .. " ('" .. v.value .. "'),"
        else
            msg = msg .. v.type .. ","
        end
    end
    error(msg)
end

---@param a Banana.Ncss.StyleValue[]
---@return boolean
local function isBool(a)
    return #a == 1 and a[1].type == "boolean"
end
local boolValid = Validation:new(isBool)
local marginValid = Validation:new(function (a)
    if #a ~= 1 and #a ~= 2 and #a ~= 4 then
        return false
    end
    for _, v in ipairs(a) do
        if v.type ~= "unit" then
            return false
        end
    end
    return true
end)


local singleUnit          = Validation:new(function (a)
    return #a == 1 and a[1].type == "unit"
end)
-- local singlePlain         = Validation:new({ [1] = { { "plain" } } })
local singleInt           = Validation:new({ [1] = { { "integer" } } })
local singleStringOrPlain = Validation:new({ [1] = { { "string" }, { "plain" } } })
local singleNumber        = Validation:new({ [1] = { { "integer" }, { "float" } } })
---@return Banana.Ncss.PropertyValidation
local function explicit(...)
    local arr = { ... }
    for i, v in ipairs(arr) do
        arr[i] = { "|" .. v }
    end
    return Validation:new({ [1] = arr })
end
---@type { [string]: Banana.Ncss.PropertyValidation|string }
local validations = {
    ["aspect-ratio"] = singleNumber,
    ["hl-underline"] = boolValid,
    ["hl-undercurl"] = boolValid,
    ["hl-italic"] = boolValid,
    ["hl-bold"] = boolValid,
    ["hl-fg"] = Validation:new({ [1] = { { "color" }, { "plain" } } }),
    ["hl-sp"] = Validation:new({ [1] = { { "color" }, { "plain" } } }),
    ["hl-bg"] = Validation:new({ [1] = { { "color" }, { "plain" } } }),
    ["hl-link"] = singleStringOrPlain,
    ["hl-__name"] = singleStringOrPlain,
    ["list-style-type"] = Validation:new({ [1] = { { "string" }, { "|number" }, { "|roman" }, { "|Roman" }, { "|alpha" }, { "|Alpha" }, { "|star" }, { "|dash" } } }),
    ["width"] = Validation:new({ [1] = { { "unit" }, { "|fit-content" } } }),
    ["height"] = singleUnit,
    ["display"] = explicit("grid", "flex", "inherit", "initial", "none"),
    ["flex-basis"] = singleUnit,
    ["flex-shrink"] = singleNumber,
    ["flex-grow"] = singleNumber,
    ["flex-wrap"] = explicit("wrap", "nowrap"),
    ["text-align"] = explicit("left", "right", "center", "initial", "inherit"),

    ["grid-template-columns"] = Validation:new({ ["*"] = { { "unit" } } }),
    ["grid-template-rows"] = Validation:new({ ["*"] = { { "unit" } } }),
    ["grid-row"] = Validation:new({
        [1] = { { "integer" } },
        [2] = { { "|span", "integer" } },
        [3] = { { "integer", "slash", "integer" } },
        [4] = { { "integer", "slash", "|span", "integer" } }
    }),
    ["grid-column"] = "grid-row",

    ["row-gap"] = singleUnit,
    ["column-gap"] = singleUnit,

    ["position"] = explicit("absolute", "static", "relative", "inherit",
        "initial"),
    ["z-index"] = singleInt,
    ["left"] = singleUnit,
    ["right"] = singleUnit,
    ["top"] = singleUnit,
    ["bottom"] = singleUnit,

    ["padding"] = marginValid,
    ["padding-left"] = singleUnit,
    ["padding-right"] = singleUnit,
    ["padding-top"] = singleUnit,
    ["padding-bottom"] = singleUnit,

    ["margin"] = marginValid,
    ["margin-left"] = singleUnit,
    ["margin-right"] = singleUnit,
    ["margin-top"] = singleUnit,
    ["margin-bottom"] = singleUnit,
}
return {
    validate = function (name, value)
        local validation = validations[name]
        while type(validation) == "string" do
            validation = validations[validation]
        end
        if validation == nil then
            log.throw(
                "Unable to validate property '" .. name .. "'")
            error("")
        end
        return validation:passes(value, name)
    end,
    _validations = validations,
}
