---@param document Banana.Instance
---@param params Banana.Instance.RouteParams
return function (document, params)
    local root = params.selfNode:getComponentRoot()
    local day = tonumber(root:getAttributeSubstitution("day"))
    local month = root:getAttributeSubstitution("month") or vim.fn.strftime("%m")
    local year = root:getAttributeSubstitution("year") or vim.fn.strftime("%Y")
    local timestamp = vim.fn.strptime("%Y %m %d",
        year .. " " .. month .. " " .. day)
    local dow = vim.fn.strftime("%a", timestamp)
    local days = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" }
    local found = false
    for i, v in ipairs(days) do
        if dow == v then
            local row = day + 7 - i
            row = (row - row % 7) / 7 + 1
            found = true
            root:setStyleValue("grid-column", i .. "")
            root:setStyleValue("grid-row", row .. "")
            break
        end
    end
    if not found then
        print("not found :(")
    end
end
