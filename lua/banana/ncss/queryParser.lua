local M = {}
local q = require('banana.ncss.query')
---@alias Banana.Ncss.PseudoGenRet fun(ast: Banana.Ast): boolean
---@type { [string]: fun(node: TSNode?, parser: Banana.Ncss.ParseData): Banana.Ncss.PseudoGenRet, number?}
local pseudoClasses = {
    ["not"] = function(node, parser)
        assert(node ~= nil, ":not requires a selector argument")
        assert(node:child_count() == 3, ":not can only take one argument")
        local child = node:child(1)
        assert(child ~= nil, "Unreachable")
        local query = q.newQuery()
        M.parseQueryComponent(child, query, parser)
        local spec = query.specificity
        return function(ast)
            assert(query.rootSelector.select ~= nil,
                "Expected a whereable root selector in :not")
            if query.rootSelector.select(ast) then return false end
            for _, sel in ipairs(query.filters) do
                assert(sel.filterType ~= q.FilterType.Selector,
                    "Exected only where filters in :not")
                ---@cast sel Banana.Ncss.Where
                if sel.satisfies(ast) then return false end
            end
            return true
        end, spec
    end,

}
local ts_types = require('banana.ncss.tsTypes')
---@type { [Banana.Ncss.TSTypes]: fun(node: TSNode, parser: Banana.Ncss.ParseData): Banana.Ncss.Where|Banana.Ncss.Selector }
M.queryParsers = {
    [ts_types.pseudo_class_selector] = function(node, parser)
        local argsIndex = 3
        local nameTag = node:child(2)
        local isSel = false
        if nameTag == nil or nameTag:type() ~= ts_types.class_name then
            isSel = true
            nameTag = node:child(1)
            argsIndex = argsIndex - 1
        end
        assert(nameTag ~= nil or nameTag:type() ~= ts_types.class_name,
            "Could not parse pseudo class as got no class_name node at the expected spots")

        local name = parser:getStringFromRange({ nameTag:start() }, { nameTag:end_() })
        local parse = pseudoClasses[name]
        assert(parse ~= nil,
            "Could not find pseudo class parser for pseudo class '" .. name .. "'")
        local fn, spec = parse(node:child(argsIndex), parser)
        spec = spec or q.Specificity.Pseudoclass
        if isSel then
            return q.newSelector(fn, spec)
        end
        return q.newWhere(fn, spec)
    end,
    [ts_types.universal_selector] = function()
        return q.newSelector(function() return true end, q.Specificity.Star)
    end,
    [ts_types.descendant_selector] = function(node, parser)
        local el = node:child(1)
        assert(el ~= nil,
            "Unreachable")

        local query = q.newQuery()
        M.parseQueryComponent(el, query, parser)
        assert(query.rootSelector ~= nil,
            "Unexpected nil root selector on query")
        assert(query.rootSelector.select ~= nil,
            "descendant_selector requires the rootSelector to have a select function, not manualSelect")

        ---@type fun(ast: Banana.Ast, arr: Banana.Ast[]): Banana.Ast[]
        local sel = nil
        sel = function(ast, arr)
            if arr == nil then
                arr = {}
            end
            for _, v in ipairs(ast.nodes) do
                if type(v) == "string" then
                    goto continue
                end
                local canInsert = false
                if query.rootSelector.select(v) then
                    canInsert = true
                end
                local i = 1
                while canInsert and query.filters[i] ~= nil do
                    assert(query.filters[i].filterType == q.FilterType.Where,
                        "descendant_selector can only have where filters")
                    canInsert = query.filters[i].satisfies(v)
                    i         = i + 1
                end
                if canInsert then
                    table.insert(arr, v)
                end
                sel(v, arr)
                ::continue::
            end
            return arr
        end

        return q.newManualSelector(sel, query.specificity)
    end,
    [ts_types.tag_name] = function(node, parser)
        local elName = parser:getStringFromRange({ node:start() }, { node:end_() })

        return q.selectors.tag(elName)
    end,
    [ts_types.child_selector] = function(node, parser)
        local el = node:child(2)
        assert(el ~= nil,
            "Unreachable")

        local query = q.newQuery()
        M.parseQueryComponent(el, query, parser)
        assert(query.rootSelector ~= nil,
            "Unexpected nil root selector on query")
        assert(query.rootSelector.select ~= nil,
            "child_selector requires the rootSelector to have a select function, not manualSelect")

        return q.newManualSelector(function(ast)
            local ret = {}
            for _, v in ipairs(ast.nodes) do
                if type(v) == "string" then
                    goto continue
                end
                local canInsert = false
                if query.rootSelector.select(v) then
                    canInsert = true
                end
                local i = 1
                while canInsert and query.filters[i] ~= nil do
                    assert(query.filters[i].filterType == q.FilterType.Where,
                        "child_selector can only have where filters")
                    canInsert = query.filters[i].satisfies(v)
                    i         = i + 1
                end
                if canInsert then
                    table.insert(ret, v)
                end
                ::continue::
            end
            return ret
        end, query.specificity)
    end,

    [ts_types.class_selector] = function(node, parser)
        local nameTag = node:child(2)
        local isSel = false
        if nameTag == nil then
            isSel = true
            nameTag = node:child(1)
        end
        assert(nameTag ~= nil,
            "Expected class_name to not be nil")
        assert(nameTag:type() == ts_types.class_name,
            "Expected nameTag to have type class_name, got '" .. nameTag:type() .. "'")

        local name = parser:getStringFromRange({ nameTag:start() }, { nameTag:end_() })
        if isSel then
            return q.selectors.class(name)
        end
        local fn = function(ast)
            return ast:hasClass(name)
        end
        return q.newWhere(fn, q.Specificity.Class)
    end,
    [ts_types.id_selector] = function(node, parser)
        local nameTag = node:child(1)
        assert(nameTag ~= nil,
            "Expected id_name to not be nil")
        assert(nameTag:type() == ts_types.id_name,
            "Expected nameTag to have type id_name, got '" .. nameTag:type() .. "'")

        local name = parser:getStringFromRange({ nameTag:start() }, { nameTag:end_() })


        return q.selectors.id(name)
    end,

}
---@param tree TSNode
---@param query Banana.Ncss.Query
---@param parser Banana.Ncss.ParseData
function M.parseQueryComponent(tree, query, parser)
    if tree:type() == ts_types.tag_name then
        local text = parser:getStringFromRange({ tree:start() }, { tree:end_() })
        query:setRootSelector(q.selectors.tag(text), true)
    else
        local child = tree:child(0)
        if child == nil then
            return
        end
        M.parseQueryComponent(child, query, parser)
        local p = M.queryParsers[tree:type()]
        assert(p ~= nil,
            "Could not find parser for '" .. tree:type() .. "'")
        local comp = p(tree, parser)
        query:appendFilter(comp, true)
    end
end

return M
