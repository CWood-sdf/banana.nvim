---@param document Banana.Instance
return function (document)
    local grid = document:querySelectorAll(".grid")[1]

    for node in grid:childIter() do
        print("remap")
        node:attachRemap("n", "K", { "hover" }, function ()
            print(node:getTextContent())
        end, {})
    end
    grid:attachRemap("n", "K", { "hover" }, function ()
        print("nope")
    end, {})
end
