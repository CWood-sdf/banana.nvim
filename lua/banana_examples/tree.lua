---@param t table
---@param node Banana.Ast
---@param name string
---@param document Banana.Instance
local function walkTree(t, node, name, document)
    local li = document:createElement("li")
    li:setTextContent(name)
    li:attachRemap("n", "a", { "line-hover" }, function ()
        node:toggleClass("selected")
    end, {})
    node:appendChild(li)
    if type(t) ~= "table" then return end
    for n, v in pairs(t) do
        if type(n) ~= "string" then
            goto continue
        end
        local treeEl = document:createElement("div")
        treeEl:addClass("tree")
        node:appendChild(treeEl)
        walkTree(v, treeEl, n, document)
        local leafDiv = document:createElement("div")
        treeEl:appendChild(leafDiv)
        ::continue::
    end
    local otherDiv = document:createElement("div")
    otherDiv:addClass("tree")
    for _, leafName in ipairs(t) do
        local leaf = document:createElement("li")
        leaf:setTextContent(leafName)
        leaf:addClass("leaf")
        otherDiv:appendChild(leaf)
    end
    node:appendChild(otherDiv)
end
---@param document Banana.Instance
return function (document)
    local tree = {
        asdf = {
            ogoa = {
                "thing"
            },
            "asdf child",
        },
        omg = {
            "idk"
        },
    }
    local node = document:querySelectorAll(".tree")[1]
    walkTree(tree, node, "tree", document)
end
