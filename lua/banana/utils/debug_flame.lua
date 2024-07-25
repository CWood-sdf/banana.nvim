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

---@type { [string]: number }
local flameCounts = {}

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
    flameCounts[name] = flameCounts[name] or 0
    flameCounts[name] = flameCounts[name] + 1
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
---@param filter? string
---@param per? boolean
---@return { [string]: number }
function M.getFlames(unit, filter, per)
    if not isdev() then return {} end
    filter = filter or "."
    if #flameStack > 1 then
        print("Flames not done")
    end
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
        if not string.match(k, filter) then
            goto continue
        end
        local vDiv = v / div
        if per then
            vDiv = vDiv / flameCounts[k]
        end
        ret[k] = vDiv
        total = total + vDiv
        ::continue::
    end
    if unit == "pct" then
        for k, v in pairs(flameTimes) do
            if not string.match(k, filter) then
                goto continue
            end
            if per then
                v = v / flameCounts[k]
            end
            ret[k] = v / total
            ::continue::
        end
    end
    return ret
end

---@param unit? "millis"|"micros"|"nanos"|"s"|"pct"
---@param filter? string
---@param per? boolean
---@return [string, number]
function M.getWorst(unit, filter, per)
    if not isdev() then return {} end
    local ret = {}
    for k, v in pairs(M.getFlames(unit, filter, per)) do
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
