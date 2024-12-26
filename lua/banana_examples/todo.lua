-- because htmx said so
return {
    ---@param document Banana.Instance
    __banana_run = function (document)
        local todoItem = document:getElementById("todo")
        vim.keymap.set("n", "a", function ()
            local name = vim.fn.input("Todo item name: ")
            local el = document:createElement("li")
            el:setTextContent(name)
            todoItem:appendChild(el)
            -- bufnr unneccessary on attach remap bc banana adds it
            el:attachRemap("n", "X", { "line-hover" }, function ()
                el:remove()
            end, {})
        end, {
            buffer = document:getBufnr()
        })
    end
}
