vim.schedule(function()
    local file = io.open("BANANA_YEET_BANANA.txt", "w")
    file:write("asdf\n")
    local pluginCwd = ""

    for _, v in ipairs(vim.api.nvim_list_runtime_paths()) do
        file:write(v .. ", " .. pluginCwd .. "\n")
        if v:match("banana.nvim(/|)$") then
            pluginCwd = v
        end
    end
    file:close()
    vim.system({ "bash", "./build.sh" }, {
        cwd = pluginCwd
    }):wait()
end)
