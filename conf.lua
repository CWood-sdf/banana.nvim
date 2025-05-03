vim.keymap.set("n", "<leader>rl", "<cmd>Lazy reload banana.nvim<CR>",
    { desc = "plugin" })
vim.keymap.set("n", "<leader>ri", "<cmd>TSInstallFromGrammar! nml<CR>",
    { desc = "nml treesitter" })
vim.keymap.set("n", "<leader>rs", "<cmd>TSInstallFromGrammar! ncss<CR>",
    { desc = "ncss treesitter" })
vim.keymap.set("n", "<leader>ro", "<cmd>BananaSo<CR>",
    { desc = "banana so" })
