-- local gridSo = require("banana.nml.render.grid").getGridSo()
--
-- local buf = vim.api.nvim_create_buf(false, true)
--
-- local win = vim.api.nvim_open_win(buf, true,
--     { relative = "editor", row = 1, col = 1, width = 10, height = 10, style =
--     "minimal" })
--
-- gridSo.doooga(buf)
---@module "banana.libbanana2"
local ooga = require("banana.libbanana")

-- ooga.box_context_delete(1)

local wins = {}

for z = 0, 1000 do
    local ctx = 0

    while ooga.box_context_exists(ctx) do
        ooga.box_context_delete(ctx)
        ctx = ctx + 1
    end
    ctx = 0
    --
    -- for ctx = 0, 10000 do
    local count = 0
    while not ooga.box_context_exists(ctx) do
        ooga.box_context_create()
        if count > 10 then break end
        count = count + 1
    end


    -- print(ooga.box_context_exists(ctx))
    --
    local box = ooga.box_new_from_context(ctx, 0)
    -- print(box)
    local box2 = ooga.box_new_from_offset(ctx, box, 0, 2)
    local box3 = ooga.box_new_from_offset(ctx, box2, 0, 1)

    local hls = {
        { fg = "red" },
        { bg = "red" },
    }

    -- print(box)
    ooga.box_set_hl(ctx, box, 1)
    ooga.box_append_str(ctx, box, 34)
    local box4 = ooga.box_new_right_from(ctx, box)
    ooga.box_set_hl(ctx, box4, 2)
    ooga.box_append_str(ctx, box4, "idrk lol")
    ooga.box_append_str(ctx, box2, "asdf2")
    ooga.box_append_str(ctx, box2, "asdf2")
    ooga.box_append_str(ctx, box2, "asdf2")
    ooga.box_append_str(ctx, box2, "asdf2")
    ooga.box_append_str(ctx, box2, "asdf2")
    ooga.box_append_str(ctx, box2, "asdf2")
    ooga.box_append_str(ctx, box2, "asdf2")
    ooga.box_append_str(ctx, box2, "asdf2")
    ooga.box_append_str(ctx, box2, "asdf2")
    ooga.box_append_str(ctx, box2, "asdf2")
    ooga.box_append_str(ctx, box3, "box3")

    local buf = vim.api.nvim_create_buf(false, true)
    local win = vim.api.nvim_open_win(buf, false, {
        style = "minimal",
        relative = "win",
        row = 20,
        col = 80,
        width = 20,
        height = 20,
    })
    table.insert(wins, win)

    ooga.box_context_render(ctx, buf)
    local ns = vim.api.nvim_create_namespace("BANANA")
    vim.api.nvim_win_set_hl_ns(win, ns)
    ooga.box_context_highlight(ctx, function (line, startCol, endCol, hl)
        local group = "ban_" .. hl
        vim.api.nvim_set_hl(ns, group, hls[hl])
        vim.api.nvim_buf_set_extmark(buf, ns, line, startCol, {
            end_col = endCol,
            hl_group = group
        })
    end)
    --
    ooga.box_context_delete(ctx)
end

print(vim.inspect(wins))

vim.keymap.set("n", "<leader>qw", function ()
    for _, win in ipairs(wins) do
        vim.api.nvim_win_close(win, true)
    end
    wins = {}
end)
