local ran = false
---@param document Banana.Instance
return function (document)
    if ran then
        return
    end
    ran = true
    ---@type { [1]: string, loc: boolean, loaded: boolean }[]
    local plugins = {
        { "banana.nvim", loc = true,  loaded = true },
        { "cloak.nvim",  loc = false, loaded = true },
        { "cloak.nvim",  loc = false, loaded = true },
        { "pineapple",   loc = true,  loaded = false },
        { "venn.nvim",   loc = false, loaded = true },
    }
    local astToClone = document:getElementById("plugin-template"):children()[1]
    local root = document:getElementById("plugin_list")
    for _, v in ipairs(plugins) do
        local newAst = astToClone:clone()
        newAst:child(1):setAttribute("data_name", v[1])
        if v.loc then
            newAst:addClass("local")
        end
        if v.loaded then
            newAst:addClass("plugin-loaded")
        end
        root:appendChild(newAst)
    end
end
