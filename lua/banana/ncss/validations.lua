---@class (exact) Banana.Ncss.PropertyValidation
---@field validations? { [integer]: Banana.Ncss.StyleValue.Types[][] }
---@field custom? fun(value: Banana.Ncss.StyleValue[]): boolean
local Validation = {

}


---@param val { [integer]: Banana.Ncss.StyleValue.Types[][] }|fun(value: Banana.Ncss.StyleValue[]): boolean
---@return Banana.Ncss.PropertyValidation
function Validation:new(val)
    ---@type Banana.Ncss.PropertyValidation
    local ret = nil
    if type(val) == "table" then
        for k, v in pairs(val) do
            for _, y in ipairs(v) do
                assert(#y == k,
                    "Validation does not have the proper size")
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
    assert(validations ~= nil,
        "No validation for size " .. #value .. " exists for property '" .. name .. "'")
    for _, v in pairs(validations) do
        local passes = true
        for i, tp in ipairs(v) do
            if tp ~= value[i].type then
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


local singleUnit = Validation:new(function(a)
    return #a == 1 and a[1].type == "unit"
end)
local singlePlain = Validation:new({ [1] = { { "plain" } } })
local singleInt = Validation:new({ [1] = { { "integer" } } })
local singleStringOrPlain = Validation:new({ [1] = { { "string" }, { "plain" } } })
---@type { [string]: Banana.Ncss.PropertyValidation }
local validations = {
    ['hl-underline'] = boolValid,
    ['hl-italic'] = boolValid,
    ['hl-bold'] = boolValid,
    ['hl-fg'] = Validation:new({ [1] = { { "color" }, { "plain" } } }),
    ['hl-bg'] = Validation:new({ [1] = { { "color" }, { "plain" } } }),
    ['hl-link'] = singleStringOrPlain,
    ['hl-__name'] = singleStringOrPlain,
    ['list-style-type'] = Validation:new({ [1] = { { "string" } } }),
    ['list-base-width'] = singleUnit,
    ['width'] = singleUnit,
    ['height'] = singleUnit,
    ['display'] = singlePlain,
    ['flex-shrink'] = singleInt,
    ['flex-grow'] = singleInt,
    ['text-align'] = singlePlain,
    ['position'] = singlePlain,
    ['z-index'] = Validation:new({ [1] = { { "integer" } } }),
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
        assert(validation ~= nil,
            "Unable to validate property '" .. name .. "'")
        return validation:passes(value, name)
    end,
}
