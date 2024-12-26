local function timestampFor(year, month)
    local ret = vim.fn.strptime("%Y %m %d", "" .. year .. " " .. month .. " 1")
    return ret
end

local function monthName(month)
    return vim.fn.strftime("%B", timestampFor(2020, month))
end

---@param month number
---@param day number
---@param year number
---@return number, number
local function getGridPlacement(month, day, year)
    local timestamp = vim.fn.strptime("%Y %m %d",
        year .. " " .. month .. " " .. day)
    local dow = vim.fn.strftime("%a", timestamp)
    local days = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" }
    for i, v in ipairs(days) do
        if dow == v then
            local row = day + 6 - i
            row = (row - row % 7) / 7 + 1
            return row, i
        end
    end
    return 0, 0
end

---@param document Banana.Instance
---@param cont Banana.Ast
---@param month number
---@param year number
local function fillWithDates(document, cont, month, year)
    local timestamp = vim.fn.strptime("%Y %m %d",
        year .. " " .. month .. " 1") + 12 * 3600
    local day = 1
    while true do
        local newDay = document:createElement("Date")
        newDay:setAttribute("day", day .. "")
        newDay:setAttribute("month", month .. "")
        newDay:setAttribute("year", year .. "")
        local row, col = getGridPlacement(month, day, year)
        newDay:setStyle("grid-row: " .. row .. "; grid-column: " .. col .. ";")
        cont:appendChild(newDay)

        day = day + 1
        timestamp = timestamp + 24 * 3600
        local newMonth = tonumber(vim.fn.strftime("%m", timestamp))
        if month ~= newMonth then
            break
        end
    end
end
---@param document Banana.Instance
return function (document)
    local monthNum = tonumber(vim.fn.strftime("%m")) or 12
    local yearNum = tonumber(vim.fn.strftime("%Y")) or 2024
    local container = document:getElementById("calendarContainer")
    local monthDiv = document:getElementById("month")
    local yearDiv = document:getElementById("year")
    local days = document:getElementsByClassName("calendar")[1]
    monthDiv:setTextContent(monthName(monthNum))
    yearDiv:setTextContent(yearNum .. "")
    fillWithDates(document, days, monthNum, yearNum)
    container:attachRemap("n", "w", {}, function ()
        monthNum = monthNum + 1
        if monthNum > 12 then
            monthNum = 1
            yearNum  = yearNum + 1
        end
        yearDiv:setTextContent(yearNum .. "")
        monthDiv:setTextContent(monthName(monthNum))
        days:removeChildren()
        fillWithDates(document, days, monthNum, yearNum)
    end, {})
    container:attachRemap("n", "b", {}, function ()
        monthNum = monthNum - 1
        if monthNum < 1 then
            monthNum = 12
            yearNum  = yearNum - 1
        end
        yearDiv:setTextContent(yearNum .. "")
        monthDiv:setTextContent(monthName(monthNum))
        days:removeChildren()
        fillWithDates(document, days, monthNum, yearNum)
    end, {})
    container:attachRemap("n", "W", {}, function ()
        yearNum = yearNum + 1
        yearDiv:setTextContent(yearNum .. "")
        days:removeChildren()
        fillWithDates(document, days, monthNum, yearNum)
    end, {})
    container:attachRemap("n", "B", {}, function ()
        yearNum = yearNum - 1
        yearDiv:setTextContent(yearNum .. "")
        days:removeChildren()
        fillWithDates(document, days, monthNum, yearNum)
    end, {})
    document:body():attachRemap("n", "q", {}, function ()
        document:close()
    end, {})
end
