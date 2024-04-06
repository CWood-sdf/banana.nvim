-- This file is for managing buffers and windows that banana can render to.

---@type integer?
local bufNr = nil

local M = {}

function M.create()
    if bufNr == nil or not vim.api.nvim_buf_is_valid(bufNr) then
        bufNr = vim.api.nvim_create_buf(false, true)
    end
end

return M
