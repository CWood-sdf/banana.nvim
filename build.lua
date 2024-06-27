vim.schedule(function()
    local dir = vim.fn.fnamemodify(debug.getinfo(1, "S").source:sub(2), ":p:h")
    vim.system({ "bash", "./build.sh" }, {
        cwd = dir
    }):wait()
    -- require('banana').initTsParsers()
    -- vim.cmd("TSInstallSync nml")
    -- vim.cmd("TSInstallSync ncss")
end)
