local normalFloatBg = tonumber(vim.api.nvim_get_hl(0, { name = "NormalFloat" })
                                  .bg)
vim.api.nvim_set_hl(0, "BananaSidebar", {
    bg = normalFloatBg + 10 * 256 * 256 + 10 * 256 + 10,
})
---@param document Banana.Instance
return function (document)
    local grid = document:querySelectorAll(".grid")[1]
    local flex = document:querySelectorAll(".flex")[1]
    for node in flex:childIter() do
        node:attachRemap("n", "K", { "hover" }, function ()
            for n in flex:childIter() do
                n:removeClass("selected")
            end
            node:addClass("selected")
        end, {})
    end

    for node in grid:childIter() do
        node:attachRemap("n", "K", { "hover" }, function ()
            print(node:getTextContent())
        end, {})
    end
    grid:attachRemap("n", "K", { "hover" }, function ()
        print("nope")
    end, {})
end
