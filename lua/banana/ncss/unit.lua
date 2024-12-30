local M = {}

---@class Banana.Ncss.UnitValue
---@field value number
---@field unit string
---@field computed number|nil
local Value = {
    value = 0,
    unit = "%",
}

---@param parentWidth number
---@return number
function Value:compute(parentWidth)
    local ret = nil
    if self.unit == "ch" then
        ret = self.value
    elseif self.unit == "%" then
        local mult = self.value / 100
        ret = math.floor(mult * parentWidth)
    end
    self.computed = ret
    if ret ~= nil then
        return ret
    end
    error("Undefined unit '" .. self.unit .. "'")
    return self.value
end

---@param parentWidth number
---@return Banana.Ncss.UnitValue
function Value:computeClone(parentWidth)
    local ret = M.newUnit(self.unit, self.value)
    ret:compute(parentWidth)
    return ret
end

---@param value number
---@param unit string
---@param computed number?
---@return Banana.Ncss.UnitValue
function M.newUnit(unit, value, computed)
    ---@type Banana.Ncss.UnitValue
    local ret = {
        computed = computed,
        value = value,
        unit = unit,
        compute = Value.compute,
        computeClone = Value.computeClone,
    }
    setmetatable(ret, { __index = Value })
    return ret
end

return M
