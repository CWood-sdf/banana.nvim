---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
local M = {}
---@module 'banana.ncss.query'
local q = require("banana.lazyRequire")("banana.ncss.query")
---@alias Banana.Ncss.PseudoGenRet fun(ast: Banana.Ast): boolean
---@type { [string]: fun(node: TSNode?, parser: Banana.Ncss.ParseData): Banana.Ncss.PseudoGenRet, number?}
local pseudoClasses = {
    ["not"] = function (node, parser)
        if node == nil then
            log.throw(":not requires a selector argument")
            error("")
        end
        if node:child_count() ~= 3 then
            log.throw(":not can only take one argument")
            error("")
        end
        local child = node:child(1)
        if child == nil then
            log.throw("Unreachable")
            error("")
        end
        local query = q.newQuery()
        M.parseQueryComponent(child, query, parser)
        local spec = query.specificity
        return function (ast)
            if query.rootSelector.select == nil then
                log.throw(
                    "Expected a whereable root selector in :not")
                error("")
            end
            if query.rootSelector.select(ast) then return false end
            for _, sel in ipairs(query.filters) do
                if sel.filterType == q.FilterType.Selector then
                    log.throw(
                        "Exected only where filters in :not")
                    error("")
                end
                ---@cast sel Banana.Ncss.Where
                if sel.satisfies(ast) then return false end
            end
            return true
        end, spec
    end,
    ["last-child"] = function (node, _)
        if node ~= nil then
            log.throw("first-child cannot have any arguments")
            error("")
        end
        local spec = q.Specificity.Class
        ---@type Banana.Ncss.PseudoGenRet
        local fn = function (ast)
            local parent = ast:parent()
            local i = #parent.nodes
            while type(parent.nodes[i]) == "string" do
                i = i - 1
            end
            return parent.nodes[i] == ast
        end
        return fn, spec
    end,
    ["first-child"] = function (node, _)
        if node ~= nil then
            log.throw("first-child cannot have any arguments")
            error("")
        end
        local spec = q.Specificity.Class
        ---@type Banana.Ncss.PseudoGenRet
        local fn = function (ast)
            local parent = ast:parent()
            for n in parent:childIter() do
                if n == ast then
                    return true
                end
                break
            end
            return false
        end
        return fn, spec
    end,

}
---@module 'banana.ncss.tsTypes'
local ts_types = require("banana.lazyRequire")("banana.ncss.tsTypes")
---@type { [Banana.Ncss.TSTypes]: fun(node: TSNode, parser: Banana.Ncss.ParseData): Banana.Ncss.Where|Banana.Ncss.Selector }
M.queryParsers = {
    [ts_types.pseudo_class_selector] = function (node, parser)
        local argsIndex = 3
        local nameTag = node:child(2)
        local isSel = false
        if nameTag == nil or nameTag:type() ~= ts_types.class_name then
            isSel = true
            nameTag = node:child(1)
            argsIndex = argsIndex - 1
        end
        if nameTag == nil or nameTag:type() ~= ts_types.class_name then
            log.throw(
                "Could not parse pseudo class as got no class_name node at the expected spots")
            error("")
        end

        local name = parser:getStringFromRange({ nameTag:start() },
            { nameTag:end_() })
        local parse = pseudoClasses[name]
        if parse == nil then
            log.throw(
                "Could not find pseudo class parser for pseudo class '" ..
                name .. "'")
            error("")
        end
        local fn, spec = parse(node:child(argsIndex), parser)
        spec = spec or q.Specificity.Pseudoclass
        if isSel then
            return q.newSelector(fn, spec)
        end
        return q.newWhere(fn, spec)
    end,
    [ts_types.universal_selector] = function ()
        return q.newSelector(function () return true end, q.Specificity.Star)
    end,
    [ts_types.descendant_selector] = function (node, parser)
        local el = node:child(1)
        if el == nil then
            log.throw(
                "Unreachable")
            error("")
        end

        local query = q.newQuery()
        M.parseQueryComponent(el, query, parser)
        if query.rootSelector == nil then
            log.throw(
                "Unexpected nil root selector on query")
            error("")
        end
        if query.rootSelector.select == nil then
            log.throw(
                "descendant_selector requires the rootSelector to have a select function, not manualSelect")
            error("")
        end

        ---@type fun(ast: Banana.Ast, arr: Banana.Ast[]): Banana.Ast[]
        local sel = nil
        sel = function (ast, arr)
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
                    if query.filters[i].filterType ~= q.FilterType.Where then
                        log.throw(
                            "descendant_selector can only have where filters")
                        error("")
                    end
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
    [ts_types.tag_name] = function (node, parser)
        local elName = parser:getStringFromRange({ node:start() },
            { node:end_() })

        return q.selectors.tag(elName)
    end,
    [ts_types.child_selector] = function (node, parser)
        local el = node:child(2)
        if el == nil then
            log.throw(
                "Unreachable")
            error("")
        end

        local query = q.newQuery()
        M.parseQueryComponent(el, query, parser)
        if query.rootSelector == nil then
            log.throw(
                "Unexpected nil root selector on query")
            error("")
        end
        if query.rootSelector.select == nil then
            log.throw(
                "child_selector requires the rootSelector to have a select function, not manualSelect")
            error("")
        end

        return q.newManualSelector(function (ast)
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
                    if query.filters[i].filterType ~= q.FilterType.Where then
                        log.throw(
                            "child_selector can only have where filters")
                        error("")
                    end
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

    [ts_types.class_selector] = function (node, parser)
        local nameTag = node:child(2)
        local isSel = false
        if nameTag == nil then
            isSel = true
            nameTag = node:child(1)
        end
        if nameTag == nil then
            log.throw(
                "Expected class_name to not be nil")
            error("")
        end
        if nameTag:type() ~= ts_types.class_name then
            log.throw(
                "Expected nameTag to have type class_name, got '" ..
                nameTag:type() .. "'")
            error("")
        end

        local name = parser:getStringFromRange({ nameTag:start() },
            { nameTag:end_() })
        if isSel then
            return q.selectors.class(name)
        end
        local fn = function (ast)
            return ast:hasClass(name)
        end
        return q.newWhere(fn, q.Specificity.Class)
    end,
    [ts_types.id_selector] = function (node, parser)
        local nameTag = node:child(1)
        if nameTag == nil then
            log.throw(
                "Expected id_name to not be nil")
            error("")
        end
        if nameTag:type() ~= ts_types.id_name then
            log.throw(
                "Expected nameTag to have type id_name, got '" ..
                nameTag:type() .. "'")
            error("")
        end

        local name = parser:getStringFromRange({ nameTag:start() },
            { nameTag:end_() })


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
        if p == nil then
            log.throw(
                "Could not find parser for '" .. tree:type() .. "'")
            error("")
        end
        local comp = p(tree, parser)
        query:appendFilter(comp, true)
    end
end

return M
