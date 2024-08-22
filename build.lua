print("cwd is at: " .. vim.fn.getcwd())
local job = vim.fn.jobstart("zig build -Doptimize=ReleaseFast",
    {
        cwd = "./zig",
        detach = true,
        on_exit = function (p1, p2, p3)
            print("Exit parameters: " .. p1 .. ", " .. p2 .. ", " .. p3)
        end,
        on_stderr = function (p1, p2, p3)
            p1 = p1 or ""
            p2 = p2 or ""
            p3 = p3 or ""
            print("Stderr params: " ..
                vim.inspect(p1) ..
                ", " .. vim.inspect(p2) .. ", " .. vim.inspect(p3))
        end,
        on_stdout = function (p1, p2, p3)
            p1 = p1 or ""
            p2 = p2 or ""
            p3 = p3 or ""
            print("stdout params: " ..
                vim.inspect(p1) ..
                ", " .. vim.inspect(p2) .. ", " .. vim.inspect(p3))
        end
    })

print("zig build started...")

vim.fn.jobwait({ job })

print("zig build done")
