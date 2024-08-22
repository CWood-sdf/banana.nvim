print("cwd is at: " .. vim.fn.getcwd())
local job = vim.fn.jobstart("zig build -Doptimize=ReleaseFast",
    {
        cwd = "./zig",
        detach = true,
        on_exit = function (p1, p2, p3)
            print("Exit parameters: " .. p1 .. ", " .. p2 .. ", " .. p3)
        end
    })

print("zig build started...")

vim.fn.jobwait({ job })

print("zig build done")
