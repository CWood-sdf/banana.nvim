---@meta "banana.libbanana"

local M = {}

--- Returns -1 on failure
--- @return number the id of a new box context
function M.box_context_create() end

--- In all cases, if ctx is valid it will be deleted
--- @param ctx number A box context id
--- @return boolean whether the context existed or not
function M.box_context_delete(ctx) end

--- @param ctx number a box context id
--- @return boolean whether the context exists or not
function M.box_context_exists(ctx) end

--- renders the context to a bufer
--- @param ctx number
--- @param buf number
--- @return boolean
function M.box_context_render(ctx, buf) end

---@param ctx number
---@param fn fun(line, startCol, endCol, hl)
---@return boolean
function M.box_context_highlight(ctx, fn) end

---@param ctx number
---@param hlgroup number
---@return number
function M.box_new_from_context(ctx, hlgroup) end

---@param ctx number
---@param box number
---@param x number
---@param y number
---@return number
function M.box_new_from_offset(ctx, box, x, y) end

---@param ctx number
---@param box number
---@return number
function M.box_new_right_from(ctx, box) end

-- prettry sure this is only used for canvas
---@param ctx number
---@param box number
---@param width number
function M.box_shrink_width_to(ctx, box, width) end

---@param ctx number
---@param box number
---@param width number
function M.box_set_width(ctx, box, width) end

---@param ctx number
---@param box number
---@param width number
function M.box_expand_width_to(ctx, box, width) end

---@param ctx number
---@param box number
---@param height number
function M.box_expand_height_to(ctx, box, height) end

---@param ctx number
---@param box number
---@param height number
function M.box_shrink_height_to(ctx, box, height) end

---@param ctx number
---@param box number
---@param height number
function M.box_set_height(ctx, box, height) end

---@param ctx number
---@param box number
---@return number
function M.box_get_height(ctx, box) end

---@param ctx number
---@param box number
---@return number
function M.box_get_width(ctx, box) end

---@param ctx number
---@param box number
function M.box_clean(ctx, box) end

---@param ctx number
---@param box number
---@param str string
function M.box_append_str(ctx, box, str) end

---@param ctx number
---@param box number
---@param style number
function M.box_set_hl(ctx, box, style) end

---@param ctx number
---@param box number
---@param str string
---@param style number
function M.box_append_word(ctx, box, str, style) end

---@param ctx number
---@param expected_bg number
function M.box_strip_right_space(ctx, expected_bg) end

---@param ctx number
---@param box number
---@param otherCtx number
---@param left number
---@param top number
---@return boolean
function M.box_render_over(ctx, box, otherCtx, left, top) end

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
