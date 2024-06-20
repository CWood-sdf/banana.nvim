vim.schedule(function()
    vim.system({ "bash", "./build.sh" }, {
        cwd = require('banana').getInstallDir()
    }):wait()
    require('banana').initTsParsers()
    vim.cmd("TSInstallSync nml")
    vim.cmd("TSInstallSync ncss")
end)
