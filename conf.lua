vim.keymap.set("n", "<leader>rl", "<cmd>Lazy reload banana.nvim<CR>",
    { desc = "plugin" })
vim.keymap.set("n", "<leader>ri", "<cmd>TSInstallFromGrammar! nml<CR>",
    { desc = "nml treesitter" })
vim.keymap.set("n", "<leader>rs", "<cmd>TSInstallFromGrammar! ncss<CR>",
    { desc = "ncss treesitter" })
vim.keymap.set("n", "<leader>re", "<cmd>restart<CR>",
    { desc = ":restart" })
vim.keymap.set("n", "<leader>ro", "<cmd>BananaSo<CR>",
    { desc = "banana so" })
vim.keymap.set("n", "<leader>rd", "<cmd>BananaDev devtools<CR>",
    { desc = "banana devtools" })
-- vim.keymap.set("n", "<leader>rd", "<cmd>lua require('banana.dst').spam()<CR>",
--     { desc = "banana dst gen" })
vim.keymap.set("n", "<leader>rp",
    "<cmd>lua require('banana.bench.dst.0')<CR>",
    { desc = "banana dst run" })
