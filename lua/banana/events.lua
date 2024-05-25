local M = {}
---@alias Banana.Event.Constraint fun(inst: Banana.Instance, ast: Banana.Ast): boolean

---@class (exact) Banana.Event.Data
---@field instance Banana.Instance
---@field instanceId number
---@field remaps { [string]: [Banana.Event.Constraint, Banana.Ast] }


---@param str string
---@return boolean
function M.parseAutocmd(str, opts)
    if str == '' then
        return false
    end
    local split = vim.split(str, ' ')
    if #split > 2 then
        return false
    end
    local name = split[1]
    if not vim.fn.exists("##" .. name) then
        return false
    end
    if #split == 2 then
        if opts.pattern ~= nil and type(opts.pattern) == "string" then
            opts.pattern = { split[2], opts.pattern }
        elseif opts.pattern ~= nil and type(opts.pattern) == "table" then
            opts.pattern[#opts.pattern + 1] = split[2]
        else
            opts.pattern = split[2]
        end
    end
    vim.api.nvim_create_autocmd(name, opts)
    return true
end

function M.parseInternalEvent(str)

end

---parses an event
---@param str string
---@param instanceId number
function M.parseEvent(str, instanceId)
    ---@type string[]
    local splits = vim.split(str, ':')
    local iter = vim.iter(splits)
    iter:filter(function(v) return v ~= '' end)
    splits = iter:totable()
    ---@cast splits string[]
    if splits[1]:sub(1, 1):lower() == splits[1]:sub(1, 1) then

    end
end

return M
