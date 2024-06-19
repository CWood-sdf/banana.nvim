vim.schedule(function()
    vim.system({ "bash", "./build.sh" }, {}):wait()
end)
