vim.schedule(function()
    local pluginCwd = ""

    for _, v in ipairs(vim.api.nvim_list_runtime_paths()) do
        if v:match("banana.nvim$") ~= nil then
            pluginCwd = v
        end
    end
    vim.system({ "bash", "./build.sh" }, {
        cwd = pluginCwd
    }):wait()
end)
