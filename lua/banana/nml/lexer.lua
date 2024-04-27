local M = {}

---@class (exact) Banana.Lexer
---@field currentLine integer
---@field currentCol integer
---@field program string[]
---@field file string
local Lexer = {
    currentLine = 1,
    currentCol = 1,
    program = {},
    file = "",
}


---@param left integer[]
---@param right integer[]
---@return string
function Lexer:getStrFromRange(left, right)
    local row = left[1] + 1
    local col = left[2] + 1
    local ret = ""
    while row < right[1] + 1 or col < right[2] + 1 do
        ret = ret .. self.program[row]:sub(col, col)
        col = col + 1
        if col > #self.program[row] then
            row = row + 1
            col = 1
        end
    end

    return ret
end

---@param file string
---@return Banana.Lexer?
function M.fromPath(file)
    ---@type file*?
    local f = io.open(file, "r")
    if f == nil then
        return nil
    end
    local program = {}
    for line in f:lines() do
        table.insert(program, line .. "\n")
    end
    local lexer = {
        currentLine = 1,
        currentCol = 1,
        file = file,
        program = program,
    }
    setmetatable(lexer, { __index = Lexer })
    return lexer
end

---@param str string
---@return Banana.Lexer
function M.fromString(str)
    local program = {}
    local split = vim.split(str, "\n")
    for _, line in ipairs(split) do
        table.insert(program, line .. "\n")
    end
    ---@type Banana.Lexer
    local lexer = {
        currentLine = 1,
        currentCol = 1,
        program = program,
        file = "string",
    }
    setmetatable(lexer, { __index = Lexer })
    return lexer
end

return M
