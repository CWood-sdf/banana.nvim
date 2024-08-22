-- vim.schedule(function ()
local job = vim.fn.jobstart("zig build -Doptimize=ReleaseFast",
    {
        cwd = "./zig",
    })

vim.fn.jobwait({ job })

-- require('banana').initTsParsers()
-- vim.cmd("TSInstallSync nml")
-- vim.cmd("TSInstallSync ncss")
-- vim.cmd("qa!")
-- end)
