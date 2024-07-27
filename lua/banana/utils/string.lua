local M = {}
-- Returns the length in bytes of the utf8 character
-- Copilot wrote this and it actually works :O
-- Also stolen from CWood-sdf/spaceport.nvim

---returns the bytelength of a single code point
---@param utf8Char string
---@return integer
function M.codepointLen(utf8Char)
    if utf8Char:byte() < 128 then
        return 1
    elseif utf8Char:byte() < 224 then
        return 2
    elseif utf8Char:byte() < 240 then
        return 3
    else
        return 4
    end
end

---Returns the width the characters will take up on screen
---@param str string
---@return number
function M.charWidth(str)
    return vim.api.nvim_strwidth(str)
end

---Substring using character widths
---@param str string
---@param start number
---@param e number
---@return string
function M.sub(str, start, e)
    local ret = ""
    local c = 1
    local i = 1
    while c < start do
        local char = str:sub(i, i)
        local len = M.codepointLen(char)
        c = c + vim.api.nvim_strwidth(str:sub(i, i + len - 1))
        i = i + len
        if i > #str then
            return ""
        end
    end
    while c <= e do
        local char = str:sub(i, i)
        local len = M.codepointLen(char)
        ret = ret .. str:sub(i, i + len - 1)
        c = c + vim.api.nvim_strwidth(str:sub(i, i + len - 1))
        i = i + len
        if i > #str then
            return ret
        end
    end
    return ret
end

---Returns the number of bytes in a string
function M.byteCount(str)
    return #str
end

return M
