local M = {}

local componentCache = {}

---This function errors instead of return nil because
---not having a component is lowkey a fatal render error
---@param name string
---@return Banana.Ast
function M.getComponentTree(name)
    return require("banana.nml.ast").Ast:new("asdf",
        require("banana.instance").getNilAst())
end

return M
