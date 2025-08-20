---@param document Banana.Instance
return function (document)
    local root = document:getPrimaryNode()
    ---@type Banana.Ast
    local ast = root:getData("ast")
    local children = document:getElementById("children")

    for _, v in ipairs(ast.nodes) do
        if type(v) == "string" then
            local div = document:createElement("div")
            div:setTextContent(v)
            children:appendChild(div)
        else
            local el = document:createElement("Tag")
            children:appendChild(el)
            el:setData("ast", v)
        end
    end
end
