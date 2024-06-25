local M = {}

---@param bufnr number
---@return string[]
function M.bufToBgMap(bufnr)
    local lines = vim.api.nvim_buf_get_lines(bufnr, 0, -1, false)
    local ret = {}
    local bgI = 1
    local bgTypes = " ~!@#$%^&*"
    local foundBgs = {

    }
    for i, v in ipairs(lines) do
        local line = ""
        for j = 1, #v do
            local char = v:sub(j, j)
            local ext = vim.inspect_pos(bufnr, i - 1, j - 1).extmarks[1]
            local opts = {
                name = ext.opts.hl_group,
                link = false,
            }
            local hl = vim.api.nvim_get_hl(ext.ns_id, opts)
            if hl.bg == nil then
                hl = vim.api.nvim_get_hl(0, { name = "NormalFloat" })
            end
            local bg = string.format("#%06x", hl.bg * 1)
            if bg == nil then
                error("asdf")
            end
            local bgChar = foundBgs[bg]
            if bgChar == nil then
                bgChar = bgTypes:sub(bgI, bgI)
                bgI = bgI + 1
                foundBgs[bg] = bgChar
            end
            if char ~= ' ' then
                line = line .. char
            else
                line = line .. bgChar
            end
        end
        table.insert(ret, line)
    end
    return ret
end

---@param bufMap string[]
---@param expectedMap string[]
function M.assertBgMapsMatch(bufMap, expectedMap)
    for i, v in ipairs(bufMap) do
        bufMap[i] = v:gsub("%s*$", "")
    end
    for i, v in ipairs(expectedMap) do
        expectedMap[i] = v:gsub("%s*$", "")
    end
    local i = 1
    while i <= #bufMap and i <= #expectedMap do
        if bufMap[i] ~= expectedMap[i] then
            error("line " ..
                i .. " expected '" .. bufMap[i] .. "' to be '" .. expectedMap[i] .. "'")
        end
        i = i + 1
    end
    while i <= #expectedMap do
        if expectedMap[i] ~= "" then
            error("Expected no more lines after end")
        end
        i = i + 1
    end
    while i <= #bufMap do
        if bufMap[i] ~= "" then
            error("Expected no more lines after end of expected")
        end
        i = i + 1
    end
end

return M
