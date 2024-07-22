local M = {}
local _isdev = nil
---@return boolean
local function isdev()
    if _isdev == nil then
        _isdev = require("banana.utils.debug").isdev()
    end
    return _isdev
end

---@type string[]
local flameStack = {}

---@type { [string]: number }
local flameTimes = {}

---@type { [string]: number }
local flameStarts = {}

local function recordTime()
    local flame = flameStack[#flameStack]
    if flame == nil then
        return
    end

    flameTimes[flame] = flameTimes[flame] or 0
    flameTimes[flame] = flameTimes[flame] - flameStarts[flame] + vim.loop.hrtime()
end

local function startTime()
    local flame = flameStack[#flameStack]
    if flame == nil then
        return
    end
    flameStarts[flame] = vim.loop.hrtime()
end

---@param name string
function M.new(name)
    if not isdev() then return end
    recordTime()
    table.insert(flameStack, name)
    startTime()
end

function M.pop()
    if not isdev() then return end
    if #flameStack == 0 then
        print("flamestack empty!")
        return
    end
    recordTime()
    table.remove(flameStack)
    startTime()
end

---@param unit? "millis"|"micros"|"nanos"|"s"|"pct"
---@return { [string]: number }
function M.getFlames(unit)
    if not isdev() then return {} end
    local div = 1
    if unit == "millis" then
        div = 1e6
    elseif unit == "micros" then
        div = 1e3
    elseif unit == "s" then
        div = 1e9
    end
    local ret = {}
    local total = 0
    for k, v in pairs(flameTimes) do
        ret[k] = v / div
        total = total + v / div
    end
    if unit == "pct" then
        for k, v in pairs(flameTimes) do
            ret[k] = v / total
        end
    end
    return ret
end

---@param unit? "millis"|"micros"|"nanos"|"s"|"pct"
---@return [string, number]
function M.getWorst(unit)
    if not isdev() then return {} end
    local ret = {}
    for k, v in pairs(M.getFlames(unit)) do
        table.insert(ret, { k, v })
    end
    table.sort(ret, function(l, r)
        return l[2] > r[2]
    end)
    return ret
end

function M.reset()
    flameTimes = {}
end

return M
