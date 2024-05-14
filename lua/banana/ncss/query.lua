local M = {}
---@enum FilterType
M.FilterType = {
    Selector = 0,
    Where = 1,
}

---@class (exact) Banana.Ncss.Selector
---@field select? fun(ast: Banana.Ast): boolean
---@field manualSelect? fun(ast: Banana.Ast): Banana.Ast[]
---@field filterType FilterType
local Selector = {
    select = function() return true end,
    manualSelect = nil,
    filterType = M.FilterType.Selector
}
---@param ast Banana.Ast
---@param arr Banana.Ast[]
function Selector:_getMatches(ast, arr)
    if self.select(ast) then
        table.insert(arr, ast)
    end
    for _, v in ipairs(ast.nodes) do
        if type(v) ~= "string" then
            ---@cast v Banana.Ast
            if self.select(ast) then
                table.insert(arr, v)
            end
            self:_getMatches(v, arr)
        end
    end
end

---@param ast Banana.Ast
---@return Banana.Ast[]
function Selector:getMatches(ast)
    if self.manualSelect ~= nil then
        return self.manualSelect(ast)
    end
    if self.select == nil then
        error("Both selector functions are nil in Ncss Selector")
    end
    local ret = {}
    self:_getMatches(ast, ret)
    return ret
end

---@param select fun(ast: Banana.Ast): boolean
---@return Banana.Ncss.Selector
function M.newSelector(select)
    ---@type Banana.Ncss.Selector
    local selector = {
        select     = select,
        filterType = M.FilterType.Selector
    }

    setmetatable(selector, {
        __index = Selector
    })
    return selector
end

---@class (exact) Banana.Ncss.Selector.Defaults
---@field tag fun(name: string): Banana.Ncss.Selector
M.selectors = {
    tag = function(name)
        return M.newSelector(function(ast)
            return ast.tag == name
        end)
    end,
}

---@param select fun(ast: Banana.Ast): Banana.Ast[]
---@return Banana.Ncss.Selector
function M.newManualSelector(select)
    ---@type Banana.Ncss.Selector
    local selector = {
        manualSelect = select,
        filterType   = M.FilterType.Selector
    }

    setmetatable(selector, {
        __index = Selector
    })
    return selector
end

---@class (exact) Banana.Ncss.Where
---@field satisfies fun(ast: Banana.Ast): boolean
---@field filterType FilterType
local Where = {
    satisfies  = function() return true end,
    filterType = M.FilterType.Where
}

---@param satisfies fun(ast: Banana.Ast): boolean
---@return Banana.Ncss.Where
function M.newWhere(satisfies)
    ---@type Banana.Ncss.Where
    local where = {
        satisfies  = satisfies,
        filterType = M.FilterType.Where
    }

    setmetatable(where, {
        __index = Where
    })
    return where
end

---@class (exact) Banana.Ncss.Query
---@field rootSelector Banana.Ncss.Selector?
---@field filters (Banana.Ncss.Selector|Banana.Ncss.Where)[]
local Query = {
    rootSelector = nil,
    filters = {}
}

---@param ast Banana.Ast
---@return Banana.Ast[]
function Query:find(ast)
    if self.rootSelector == nil then
        error("rootSelector is nil in Ncss Query")
    end
    local ret = self.rootSelector:getMatches(ast)
    for _, v in ipairs(self.filters) do
        if v.filterType == M.FilterType.Where then
            ---@cast v Banana.Ncss.Where
            for i = #ret, 1, -1 do
                if not v.satisfies(ret[i]) then
                    table.remove(ret, i)
                end
            end
        elseif v.filterType == M.FilterType.Selector then
            --PERF: This might be slow because duplicates

            ---@type { [Banana.Ast]: boolean }
            local newRet = {}
            ---@cast v Banana.Ncss.Selector
            for _, a in ipairs(ret) do
                local extras = v:getMatches(a)
                for _, r in ipairs(extras) do
                    newRet[r] = true
                end
            end
            ret = {}
            for k, _ in pairs(newRet) do
                table.insert(ret, k)
            end
        end
    end

    return ret
end

---@param f Banana.Ncss.Selector|Banana.Ncss.Where
function Query:appendFilter(f)
    table.insert(self.filters, f)
end

---@param sel Banana.Ncss.Selector
---@param force boolean
function Query:setRootSelector(sel, force)
    if self.rootSelector ~= nil and not force then
        error("Overwriting the root selector of an Ncss Query")
    end
    self.rootSelector = sel
end

---@return Banana.Ncss.Query
function M.newQuery()
    ---@type Banana.Ncss.Query
    local query = {
        rootSelector = nil,
        filters = {}
    }
    setmetatable(query, {
        __index = Query,
    })
    return query
end

return M
