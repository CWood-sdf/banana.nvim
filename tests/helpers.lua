local M = {}

---@param bufnr number
---@return string[]
function M.bufToBgMap(bufnr)
    local lines = vim.api.nvim_buf_get_lines(bufnr, 0, -1, false)
    local ret = {}
    local bgI = 1
    local bgTypes = " ~!@#$%^&*()_+"
    local foundBgs = {

    }
    for i, v in ipairs(lines) do
        local line = ""
        for j = 1, #v do
            local char = v:sub(j, j)
            local ext = vim.inspect_pos(bufnr, i - 1, j - 1).extmarks[1]
            local opts = nil
            if ext == nil then
                opts = {
                    name = require('banana.instance').defaultWinHighlight,
                    link = true,
                }
                ext = {
                    ns_id = require('banana.instance').getInstance(1).highlightNs
                }
            else
                opts = {
                    name = ext.opts.hl_group,
                    link = true,
                }
            end
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
            -- ::continue::
        end
        table.insert(ret, line)
    end
    return ret
end

function M.printRenders(bufMap, expectedMap)
    print("Buffer: ")
    print("--------")
    for _, v in ipairs(bufMap) do
        print(v)
    end
    print("--------")
    print("Expected: ")
    print("--------")
    for _, v in ipairs(expectedMap) do
        print(v)
    end
    print("--------")
end

---@param bufMap string[]
---@param expectedMap string[]
function M.assertBgMapsMatch(bufMap, expectedMap)
    local i = 1
    while i <= #bufMap and i <= #expectedMap do
        if #bufMap[i] < #expectedMap[i] then
            print(#bufMap[i]:sub(#expectedMap[i]))
        end
        if #bufMap[i] < #expectedMap[i] and #bufMap[i]:sub(#expectedMap[i]):gsub("%s*$", "") == "" then

        elseif bufMap[i] ~= expectedMap[i] then
            M.printRenders(bufMap, expectedMap)
            error("line " ..
                i .. " expected '" .. bufMap[i] .. "' to be '" .. expectedMap[i] .. "'")
        end
        i = i + 1
    end
    while i <= #expectedMap do
        if expectedMap[i]:gsub("%s*$", "") ~= "" then
            M.printRenders(bufMap, expectedMap)
            error("Expected no more lines after end")
        end
        i = i + 1
    end
    while i <= #bufMap do
        if bufMap[i]:gsub("%s*$", "") ~= "" then
            M.printRenders(bufMap, expectedMap)
            error("Expected no more lines after end of expected")
        end
        i = i + 1
    end
end

---@param spec string
---@param document Banana.Instance
---@return Banana.Ast
local function parseSpec(spec, document)
    -- print("parsing spec '" .. spec .. "'")
    local name = vim.split(spec, '#')[1]
    -- print("el name '" .. name .. "'")
    spec = vim.split(spec, '#')[2]
    -- print("new spec '" .. spec .. "'")
    local ret = document:createElement(name)
    local split = vim.split(spec, ':')
    local contents = split[#split]
    -- print("contents '" .. contents .. "'")
    ret:setTextContent(contents)
    spec = split[1]
    -- print("new spec '" .. spec .. "'")
    local rest = vim.split(spec, '%.')
    local id = rest[1]
    -- print("id '" .. id .. "'")
    if id ~= "" then
        -- print("setting id")
        ret:setAttribute('id', id)
    end
    for i = 2, #rest do
        -- print("adding class '" .. rest[i] .. "'")
        ret:addClass(rest[i])
    end

    return ret
end

---@param specs string[]
---@param document Banana.Instance
---@param target Banana.Ast?
---@return Banana.Ast[]
function M.createElements(specs, document, target)
    local ret = {}
    for _, v in ipairs(specs) do
        local el = parseSpec(v, document)
        if target ~= nil then
            target:appendNode(el)
        else
            table.insert(ret, el)
        end
    end
    return ret
end

---@param ast Banana.Ast
---@param bound Banana.Ast.BoundingBox
function M.boundsMatch(ast, bound)
    local box = ast.boundBox
    assert(box ~= nil, "Expected a bounding box")
    for k, v in pairs(bound) do
        if box[k] ~= v then
            error("Expected bound '" .. k .. "' to be " .. v .. " but got " .. box[k])
        end
    end
end

return M
