-- local gridSo = require("banana.nml.render.grid").getGridSo()
--
-- local buf = vim.api.nvim_create_buf(false, true)
--
-- local win = vim.api.nvim_open_win(buf, true,
--     { relative = "editor", row = 1, col = 1, width = 10, height = 10, style =
--     "minimal" })
--
-- gridSo.doThing(buf)
local thing = require("banana.libbanana")

-- thing.box_context_delete(1)


local ctx = 0

-- while thing.box_context_exists(ctx) do
--     thing.box_context_delete(ctx)
--     ctx = ctx + 1
-- end
-- ctx = 0

-- for ctx = 0, 10000 do
while not thing.box_context_exists(ctx) do
    thing.box_context_create()
end


-- print(thing.box_context_exists(ctx))

local box = thing.box_new_from_context(ctx)
local box2 = thing.box_new_from_offset(ctx, box, 0, 2)
local box3 = thing.box_new_from_offset(ctx, box2, 0, 1)

local hls = {
    { fg = "red" },
    { bg = "red" },
}

-- print(box)
thing.box_set_hl(ctx, box, 1)
thing.box_append_str(ctx, box, 34)
local box4 = thing.box_new_right_from(ctx, box)
thing.box_set_hl(ctx, box4, 2)
thing.box_append_str(ctx, box4, "idrk lol")
thing.box_append_str(ctx, box2, "asdf2")
thing.box_append_str(ctx, box2, "asdf2")
thing.box_append_str(ctx, box2, "asdf2")
thing.box_append_str(ctx, box2, "asdf2")
thing.box_append_str(ctx, box2, "asdf2")
thing.box_append_str(ctx, box2, "asdf2")
thing.box_append_str(ctx, box2, "asdf2")
thing.box_append_str(ctx, box2, "asdf2")
thing.box_append_str(ctx, box2, "asdf2")
thing.box_append_str(ctx, box2, "asdf2")
thing.box_append_str(ctx, box3, "box3")

local buf = vim.api.nvim_create_buf(false, true)
local win = vim.api.nvim_open_win(buf, false, {
    style = "minimal",
    relative = "win",
    row = 20,
    col = 80,
    width = 20,
    height = 20,
})

thing.box_context_render(ctx, buf)
local ns = vim.api.nvim_create_namespace("BANANA")
vim.api.nvim_win_set_hl_ns(win, ns)
thing.box_context_highlight(function (line, startCol, endCol, hl)
    local group = "ban_" .. hl
    vim.api.nvim_set_hl(ns, group, hls[hl])
    vim.api.nvim_buf_set_extmark(buf, ns, line, startCol, {
        end_col = endCol,
        hl_group = group
    })
end, ctx)

thing.box_context_delete(ctx)
-- end
