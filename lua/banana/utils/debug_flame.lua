local M = {}
---@module "banana.utils.log"
local log = require("banana.lazyRequire")("banana.utils.log")
local _isdev = nil
---@return boolean
local function isdev()
    if _isdev == nil then
        _isdev = require("banana.utils.debug").isdev()
    end
    return _isdev
end

function M.overrideIsDev()
    _isdev = true
end

local iteration = 0

---@type { [string]: number }
local flameIters = {}

---@type { [string]: number }
local flameLastIter = {}

---@type string[]
local flameStack = {}

---@type { [string]: number }
local flameTimes = {}

---@type { [string]: number }
local flameStarts = {}

---@type { [string]: number }
local flameCounts = {}

---@type { [string]: number[] }
local flameAlls = {}

local function recordTime(time, recordAll)
    if not isdev() then return end
    if #flameStack == 0 then
        return
    end
    local flame = flameStack[#flameStack]
    if flame == nil then
        return
    end
    if flame == "ignore" then
        return
    end
    local delta = time - flameStarts[flame]
    if recordAll then
        flameAlls[flame] = flameAlls[flame] or {}
        local section = flameAlls[flame]
        if #section == flameCounts[flame] then
            section[#section] = section[#section] + delta
        else
            table.insert(flameAlls[flame], delta)
        end
    end
    flameTimes[flame] = flameTimes[flame] or 0
    flameTimes[flame] = flameTimes[flame] + delta
end

local function startTime(time)
    if not isdev() then return end
    local flame = flameStack[#flameStack]
    if flame == nil then
        return
    end
    if flameLastIter[flame] ~= nil and flameLastIter[flame] ~= iteration then
        flameIters[flame] = flameIters[flame] or 0
        flameIters[flame] = flameIters[flame] + 1
        flameLastIter[flame] = iteration
    else
        flameLastIter[flame] = iteration
        flameIters[flame] = flameIters[flame] or 1
    end
    flameStarts[flame] = time
end

---@param name string
function M.new(name, skipLog)
    if not isdev() then return end
    if not skipLog then
        log.trace("flame:new " .. name)
    end
    local switchTime = vim.uv.hrtime() / 1000
    recordTime(switchTime, false)
    table.insert(flameStack, name)
    startTime(switchTime)
    flameCounts[name] = flameCounts[name] or 0
    flameCounts[name] = flameCounts[name] + 1
end

function M.expect(name)
    if not isdev() then return end
    if flameStack[#flameStack] ~= name then
        log.throw("Expected flamestack to be " ..
            name .. ", but got " .. flameStack[#flameStack])
    end
end

function M.pop(skipLog, recordAll)
    skipLog = skipLog or false
    recordAll = recordAll or false
    if not isdev() then return end
    if not skipLog then
        log.trace("flame:pop " .. (flameStack[#flameStack] or ""))
    end
    if #flameStack == 0 then
        log.throw("flamestack empty!")
        print("flamestack empty!")
        return
    end
    local switchTime = vim.uv.hrtime() / 1000
    recordTime(switchTime, recordAll)
    table.remove(flameStack)
    startTime(switchTime)
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
        div = 1e3
    elseif unit == "micros" then
        div = 1e0
    elseif unit == "s" then
        div = 1e6
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
        else
            vDiv = vDiv / flameIters[k]
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
            else
                v = v / flameIters[k]
            end
            ret[k] = v / total
            ::continue::
        end
    end
    return ret
end

function M.newIter()
    iteration = iteration + 1
end

---Returns a 90% confidence interval for the flame at flameAlls
---@param flame string
---@return [number, number]
function M.getFlameAlls90Conf(flame)
    -- get the mean
    local mean = 0
    for _, v in ipairs(flameAlls[flame]) do
        v = v / 1000
        mean = mean + v
    end
    -- print(mean)
    mean = mean / #flameAlls[flame]
    -- print(mean)
    -- print(mean)
    -- get the variance
    -- variance = sum((x - mean)^2) / n
    local variance = 0
    for _, v in ipairs(flameAlls[flame]) do
        v = v / 1000
        variance = variance + (v - mean) * (v - mean)
    end
    variance = variance / #flameAlls[flame]
    -- get the 90% confidence interval
    local stdDev = math.sqrt(variance)
    local z = 1.645
    local conf = z * stdDev / math.sqrt(#flameAlls[flame])
    -- print(mean .. ", " .. conf)
    return { mean - conf, mean + conf }
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
    table.sort(ret, function (l, r)
        return l[2] > r[2]
    end)
    return ret
end

function M.reset()
    flameTimes = {}
end

return M
