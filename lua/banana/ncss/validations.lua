---@module 'banana.utils.log'
local log = require('banana.lazyRequire')('banana.utils.log')
---@alias Banana.Ncss.PropertyValidation.Type string|Banana.Ncss.StyleValue.Types

---@class (exact) Banana.Ncss.PropertyValidation
---@field validations? { [integer]: Banana.Ncss.PropertyValidation.Type[][] }
---@field custom? fun(value: Banana.Ncss.StyleValue[]): boolean
local Validation = {

}


---@param val { [integer]: Banana.Ncss.PropertyValidation.Type[][] }|fun(value: Banana.Ncss.StyleValue[]): boolean
---@return Banana.Ncss.PropertyValidation
function Validation:new(val)
    ---@type Banana.Ncss.PropertyValidation
    local ret = nil
    if type(val) == "table" then
        for k, v in pairs(val) do
            for _, y in ipairs(v) do
                if #y ~= k then
                    log.assert(false,
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
    if validations == nil then
        log.assert(false,
            "No validation for size " .. #value .. " exists for property '" .. name .. "'")
        error("")
    end
    for _, v in pairs(validations) do
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
        msg = msg .. v.type .. ","
    end
    error(msg)
end

---@param a Banana.Ncss.StyleValue[]
---@return boolean
local function isBool(a)
    return #a == 1 and a[1].type == "boolean"
end
local boolValid = Validation:new(isBool)
local marginValid = Validation:new(function(a)
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


local singleUnit          = Validation:new(function(a)
    return #a == 1 and a[1].type == "unit"
end)
local singlePlain         = Validation:new({ [1] = { { "plain" } } })
local singleInt           = Validation:new({ [1] = { { "integer" } } })
local singleStringOrPlain = Validation:new({ [1] = { { "string" }, { "plain" } } })
local singleNumber        = Validation:new({ [1] = { { "integer" }, { "float" } } })
---@type { [string]: Banana.Ncss.PropertyValidation }
local validations         = {
    ['hl-underline'] = boolValid,
    ['hl-italic'] = boolValid,
    ['hl-bold'] = boolValid,
    ['hl-fg'] = Validation:new({ [1] = { { "color" }, { "plain" } } }),
    ['hl-bg'] = Validation:new({ [1] = { { "color" }, { "plain" } } }),
    ['hl-link'] = singleStringOrPlain,
    ['hl-__name'] = singleStringOrPlain,
    ['list-style-type'] = Validation:new({ [1] = { { "string" } } }),
    -- ['list-base-width'] = singleUnit,
    ['width'] = singleUnit,
    ['height'] = singleUnit,
    ['display'] = singlePlain,
    ['flex-basis'] = singleUnit,
    ['flex-shrink'] = singleNumber,
    ['flex-grow'] = singleNumber,
    ['flex-wrap'] = Validation:new({ [1] = { { "|wrap" }, { "|nowrap" } } }),
    ['text-align'] = singlePlain,
    ['position'] = singlePlain,
    ['z-index'] = singleInt,
    ['left'] = singleUnit,
    ['right'] = singleUnit,
    ['top'] = singleUnit,
    ['bottom'] = singleUnit,
    ['padding'] = marginValid,
    ['padding-left'] = singleUnit,
    ['padding-right'] = singleUnit,
    ['padding-top'] = singleUnit,
    ['padding-bottom'] = singleUnit,
    ['margin'] = marginValid,
    ['margin-left'] = singleUnit,
    ['margin-right'] = singleUnit,
    ['margin-top'] = singleUnit,
    ['margin-bottom'] = singleUnit,
}
return {
    validate = function(name, value)
        local validation = validations[name]
        if validation == nil then
            log.assert(false,
                "Unable to validate property '" .. name .. "'")
            error("")
        end
        return validation:passes(value, name)
    end,
    _validations = validations,
}
