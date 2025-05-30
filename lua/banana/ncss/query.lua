---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
local M = {}

---@enum FilterType
M.FilterType = {
    --- takes an ast and returns the descendants that fit
    Selector = 0,
    --- takes an ast and returns whether it matches a specific pattern
    Where = 1,
}

local maxCount = 128
M.Specificity = {
    Important = 1 * maxCount * maxCount * maxCount * maxCount,
    Star = 0,
    Element = 1,
    Class = 1 * maxCount,
    AttributeSelector = 1 * maxCount,
    Pseudoclass = 1 * maxCount,
    Id = 1 * maxCount * maxCount,
    Inline = 1 * maxCount * maxCount * maxCount,
}

---A representation of a selector that takes in an ast and returns new ast nodes (eg child selector)
---@class (exact) Banana.Ncss.Selector
---@field select? fun(ast: Banana.Ast): boolean
---@field manualSelect? fun(ast: Banana.Ast): Banana.Ast[]
---@field filterType FilterType
---@field specificity number
---@field init fun(self: Banana.Ncss.Selector)
---@field requireSorted boolean?
---@field dbg boolean
local Selector = {
    requireSorted = false,
    dbg = false,
    select = function () return true end,
    init = function () end,
    manualSelect = nil,
    filterType = M.FilterType.Selector,
    specificity = 0,
}
---@param ast Banana.Ast
---@param arr Banana.Ast[]
function Selector:_getMatches(ast, arr)
    if self.select(ast) then
        table.insert(arr, ast)
    end
    for _, v in ipairs(ast.nodes) do
        if type(v) ~= "string" then
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
        log.throw(
            "Both selector functions are nil in Ncss Selector")
        error("")
    end
    local ret = {}
    self:_getMatches(ast, ret)
    return ret
end

---@param select fun(ast: Banana.Ast): boolean
---@param specificity number
---@param requireSorted boolean?
---@param init fun(self: Banana.Ncss.Selector)?
---@return Banana.Ncss.Selector
function M.newSelector(select, specificity, requireSorted, init)
    ---@type Banana.Ncss.Selector
    local selector = {
        requireSorted = requireSorted or false,
        init          = init or function () end,
        select        = select,
        filterType    = M.FilterType.Selector,
        specificity   = specificity,
        dbg           = init ~= nil,
    }

    setmetatable(selector, {
        __index = Selector
    })
    return selector
end

---@class (exact) Banana.Ncss.Selector.Defaults
---@field tag fun(name: string): Banana.Ncss.Selector
---@field oneTag fun(name: string): Banana.Ncss.Selector
---@field id fun(name: string): Banana.Ncss.Selector
---@field class fun(name: string): Banana.Ncss.Selector
M.selectors = {
    oneTag = function (name)
        ---@type fun(ast: Banana.Ast): Banana.Ast[]
        local sel = nil
        sel = function (ast)
            if ast.tag == name then
                return { ast }
            end
            for _, v in ipairs(ast.nodes) do
                if type(v) ~= "string" then
                    local r = sel(v)
                    if #r ~= 0 then
                        return r
                    end
                end
            end
            return {}
        end
        return M.newManualSelector(sel, M.Specificity.Element)
    end,
    tag = function (name)
        return M.newSelector(function (ast)
            return ast.tag == name
        end, M.Specificity.Element)
    end,
    class = function (name)
        return M.newSelector(function (ast)
            return ast:hasClass(name)
        end, M.Specificity.Class)
    end,
    id = function (name)
        ---@type fun(ast: Banana.Ast): Banana.Ast[]
        local sel = nil
        sel = function (ast)
            if ast:getAttribute("id") == name then
                return { ast }
            end
            for _, v in ipairs(ast.nodes) do
                if type(v) == "string" then
                    goto continue
                end
                local ret = sel(v)
                if #ret == 1 then
                    return ret
                end
                ::continue::
            end
            return {}
        end
        return M.newManualSelector(sel, M.Specificity.Id)
    end,
}

---@param select fun(ast: Banana.Ast): Banana.Ast[]
---@param specificity number
---@param requireSorted boolean?
---@return Banana.Ncss.Selector
function M.newManualSelector(select, specificity, requireSorted)
    ---@type Banana.Ncss.Selector
    local selector = {
        dbg           = false,
        init          = function ()
        end,
        manualSelect  = select,
        filterType    = M.FilterType.Selector,
        specificity   = specificity,
        requireSorted = requireSorted or false,
    }

    setmetatable(selector, {
        __index = Selector
    })
    return selector
end

---@class (exact) Banana.Ncss.Where
---@field castWarning string?
---@field requireSorted boolean
---@field satisfies fun(ast: Banana.Ast): boolean
---@field filterType FilterType
---@field init fun(self: Banana.Ncss.Where)
---@field specificity number
---@field dbg boolean
local Where = {
    dbg         = false,
    satisfies   = function () return true end,
    filterType  = M.FilterType.Where,
    specificity = 0,
}

---@return Banana.Ncss.Selector
function Where:toSelector()
    if self.castWarning ~= nil then
        log.throw(self.castWarning)
    end
    return M.newSelector(self.satisfies, self.specificity, self.requireSorted,
        self.init)
end

---@param satisfies fun(ast: Banana.Ast): boolean
---@param specificity number
---@param requireSorted boolean?
---@param init fun(self: Banana.Ncss.Where)?
---@param castWarning string?
---@return Banana.Ncss.Where
function M.newWhere(satisfies, specificity, requireSorted, init, castWarning)
    ---@type Banana.Ncss.Where
    local where = {
        requireSorted = requireSorted or false,
        init          = init or function () end,
        dbg           = init ~= nil,
        satisfies     = satisfies,
        filterType    = M.FilterType.Where,
        specificity   = specificity,
        castWarning   = castWarning
    }

    setmetatable(where, {
        __index = Where
    })
    return where
end

---@class (exact) Banana.Ncss.Query
---@field rootSelector Banana.Ncss.Selector?
---@field filters (Banana.Ncss.Selector|Banana.Ncss.Where)[]
---@field specificity integer
local Query = {
    specificity = 0,
    rootSelector = nil,
    filters = {}
}

---@param arr Banana.Ast[]
function Query:_sortArr(arr)
    ---@type { [Banana.Ast]: number }
    local elementMap = {}
    table.sort(arr, function (l, r)
        local ln = 0
        if elementMap[l] == nil then
            for i, node in l._parent:childIterWithI() do
                elementMap[node] = i
                if node == l then
                    ln = i
                    break
                end
            end
        else
            ln = elementMap[l]
        end
        local rn = 0
        if elementMap[r] == nil then
            for i, node in r._parent:childIterWithI() do
                elementMap[node] = i
                if node == r then
                    rn = i
                    break
                end
            end
        else
            rn = elementMap[r]
        end
        return ln < rn
    end)
end

---@return boolean
function Query:_matches(ast)
    if not self.rootSelector.select(ast) then
        return false
    end
    for _, f in ipairs(self.filters) do
        if f.filterType ~= M.FilterType.Where then
            log.throw("_matches can only use filters")
            error("")
        end
        if not f.satisfies(ast) then
            return false
        end
    end
    return true
end

---@param arr (Banana.Ast|string)[]
---@return Banana.Ast[]
function Query:_applyTo(arr)
    local ret = {}
    for _, v in ipairs(self.filters) do
        v:init()
    end
    for _, v in ipairs(arr) do
        -- this is just to allow child_selector to be fast
        if type(v) == "string" then
            goto continue
        end
        if self:_matches(v) then
            table.insert(ret, v)
        end
        ::continue::
    end
    return ret
end

---@param ast Banana.Ast
---@return Banana.Ast[]
function Query:find(ast)
    if self.rootSelector == nil then
        log.throw(
            "rootSelector is nil in Ncss Query")
        error("")
    end
    self.rootSelector:init()
    local ret = self.rootSelector:getMatches(ast)
    local sorted = false
    for _, v in ipairs(self.filters) do
        v:init()
        if v.requireSorted and not sorted then
            sorted = true
            self:_sortArr(ret)
        end
        if v.filterType == M.FilterType.Where then
            ---@cast v Banana.Ncss.Where
            local i = 1
            while i <= #ret do
                if not v.satisfies(ret[i]) then
                    table.remove(ret, i)
                else
                    i = i + 1
                end
            end
        elseif v.filterType == M.FilterType.Selector then
            sorted = false
            ---@type { [Banana.Ast]: boolean }
            local retMap = {}
            ---@type Banana.Ast[]
            local newRet = {}
            ---@cast v Banana.Ncss.Selector
            for _, a in ipairs(ret) do
                local extras = v:getMatches(a)
                for _, r in ipairs(extras) do
                    if retMap[r] == nil then
                        retMap[r] = true
                        table.insert(newRet, r)
                    end
                end
            end
            ret = newRet
        end
    end

    return ret
end

---@param f Banana.Ncss.Selector|Banana.Ncss.Where
---@param promote boolean
function Query:appendFilter(f, promote)
    if promote and self.rootSelector == nil and f.filterType == M.FilterType.Selector then
        ---@cast f Banana.Ncss.Selector
        self:setRootSelector(f, true)
    else
        table.insert(self.filters, f)
        self.specificity = self.specificity + f.specificity
    end
end

---@param sel Banana.Ncss.Selector
---@param force boolean
function Query:setRootSelector(sel, force)
    if self.rootSelector ~= nil and not force then
        log.throw(
            "Overwriting the root selector of an Ncss Query")
        error("")
    end
    self.rootSelector = sel
    self.specificity = self.specificity + sel.specificity
end

---@return Banana.Ncss.Query
function M.newQuery()
    ---@type Banana.Ncss.Query
    local query = {
        rootSelector = nil,
        filters = {},
        specificity = 0,
    }
    setmetatable(query, {
        __index = Query,
    })
    return query
end

return M
