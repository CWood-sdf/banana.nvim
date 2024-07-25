-- because htmx said so
return {
    ---@param document Banana.Instance
    __banana_run = function(document)
        print('asdf')
        local todoItem = document:getElementById("todo")
        vim.keymap.set('n', 'a', function()
            local name = vim.fn.input("Todo item name: ")
            local el = document:createElement("li")
            el:setTextContent(name)
            todoItem:appendNode(el)
            el:attachRemap('n', "X", { "line-hover" }, function()
                el:remove()
            end, {})
        end, {
            buffer = document:getBufnr()
        })
        print(document:getBufnr())
    end
}
