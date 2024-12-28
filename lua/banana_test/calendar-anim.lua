local i = 0
local timer = nil

---@param t number
---@param x1 number
---@param y1 number
---@param x2 number
---@param y2 number
---@return number, number
local function lerp(t, x1, y1, x2, y2)
    return t * (x2 - x1) + x1, t * (y2 - y1) + y1
end

---@param t number
---@param p0 number
---@param p1 number @param p2 number
---@param p3 number
---@return number
local function cubicBezier(t, p0, p1, p2, p3)
    local xl, yl = lerp(t, 0, 0, p0, p1)
    local xr, yr = lerp(t, p2, p3, 1, 1)
    local xm, ym = lerp(t, p0, p1, p2, p3)
    xl, yl = lerp(t, xl, yl, xm, ym)
    xr, yr = lerp(t, xm, ym, xr, yr)
    xm, ym = lerp(t, xl, yl, xr, yr)
    return ym
end

---@param progress number
---@return number
local function easeout(progress)
    return cubicBezier(progress, 0.00, 1, 0, 1)
end

---@param document Banana.Instance
return function (document)
    local calendar = document:body()
    document:on({ "Open", "ScriptDone" }, {
        callback = function ()
            i = 0
            if timer == nil then
                timer = vim.fn.timer_start(20, function ()
                    i = i + 1
                    local v = math.floor(easeout(i / 100) * 100)
                    calendar:setStyleValue("hl-bg",
                        "radial-gradient(blue, hl-extract(bg, NormalFloat) " ..
                        v .. "%)")
                    if i >= 100 then
                        vim.fn.timer_stop(timer)
                        timer = nil
                    end
                end, { ["repeat"] = -1 })
            end
        end,
        group = vim.api.nvim_create_augroup("calendar-anim", { clear = true })
    })
end
