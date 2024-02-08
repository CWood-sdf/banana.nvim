local M = {}

M.yeet = function()
    -- local lex = require('banana.lexer')
    --
    -- if lexer == nil then
    --     print('Failed to open file')
    --     return
    -- end
    local file = io.open(os.getenv("HOME") .. '/projects/banana.nvim/log', 'w')
    if file == nil then
        print('Failed to open log file')
        return
    end
    local parser = require('banana.parser').fromFile(os.getenv("HOME") .. '/projects/banana.nvim/yeet.nml')
    if parser == nil then
        print('Failed to open file')
        return
    end
    local ast = parser:parse()
    if ast == nil then
        print('Failed to parse')
        return
    end
    print(ast)
    file:write(vim.inspect(ast))

    file:close()
end

return M
