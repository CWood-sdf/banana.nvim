---@meta
local M = {}

---@param bs userdata
---@param rowStart number
---@param colStart number
---@param rowEnd number
---@param colEnd number
---@return boolean
function M.grid_turnOnRange(bs, rowStart, colStart, rowEnd, colEnd) end

---@return userdata
function M.grid_getNew() end

---@param bs userdata
function M.grid_freeSection(bs) end

---@param bs userdata
---@param row number
---@param col number
---@return boolean
function M.grid_freeSection(bs, row, col) end

---@param bs userdata
---@param row number
---@param col number
---@return boolean
function M.grid_turnOn(bs, row, col) end

---@param bs userdata
---@param row number
---@param col number
---@return number
function M.grid_turnOn(bs, row, col) end

return M
