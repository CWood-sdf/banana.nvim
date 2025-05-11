---@meta

local M = {}

---@alias HlExpect fun (line: number, startCol: number, endCol: number, hl: number): nil
---@alias StripRightExpect fun (hl: number): number


---@return number
function M.box_context_create() end

---@param ctx number
---@return boolean
function M.box_context_delete(ctx) end

---@param ctx number
---@return boolean
function M.box_context_wipe(ctx) end

---@param ctx number
---@return boolean
function M.box_context_exists(ctx) end

---@param ctx number
---@param boxid number
---@return number
function M.box_pr_new(ctx, boxid) end

---@param ctx number
---@param partialid number
---@param left number
---@param right number
---@param top number
---@param bottom number
---@return nil
function M.box_pr_set_margin(ctx, partialid, left, right, top, bottom) end

---@param ctx number
---@param partialid number
---@param left number
---@param right number
---@param top number
---@param bottom number
---@return nil
function M.box_pr_set_pad(ctx, partialid, left, right, top, bottom) end

---@param ctx number
---@param partialid number
---@param hl number
---@return nil
function M.box_pr_set_main_hl(ctx, partialid, hl) end

---@param ctx number
---@param partialid number
---@return number
function M.box_pr_get_width(ctx, partialid) end

---@param ctx number
---@param partialid number
---@return number
function M.box_pr_get_height(ctx, partialid) end

---@param ctx number
---@param partialid number
---@param height number
---@return nil
function M.box_pr_set_max_height(ctx, partialid, height) end

---@param ctx number
---@param partialid number
---@param width number
---@return nil
function M.box_pr_set_max_width(ctx, partialid, width) end

---@param ctx number
---@param partialid number
---@return number
function M.box_pr_cursored_box(ctx, partialid) end

---@param ctx number
---@param partialid number
---@return number
function M.box_pr_box(ctx, partialid) end

---@param ctx number
---@param partialid number
---@param al number
---@return nil
function M.box_pr_set_align(ctx, partialid, al) end

---@param ctx number
---@param partialid number
---@return nil
function M.box_pr_render(ctx, partialid) end

---@param ctx number
---@param partialid number
---@param maxWidth number
---@param toX number
---@param toY number
---@return boolean
function M.box_pr_render_with_move(ctx, partialid, maxWidth, toX, toY) end

---@param ctx number
---@param partialid number
---@param lineHeight number
---@return boolean
function M.box_pr_render_cursored(ctx, partialid, lineHeight) end

---@param ctx number
---@param buf number
---@return boolean
function M.box_context_render(ctx, buf) end

---@param ctx number
---@param boxOne number
---@param boxOther number
---@return nil
function M.box_put_cursor_below(ctx, boxOne, boxOther) end

---@param ctx number
---@param L HlExpect
---@return nil
function M.box_context_highlight(ctx, L) end

---@param ctx number
---@param boxid number
---@param extra number
---@return nil
function M.box_shift_right_by(ctx, boxid, extra) end

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

---@param ctx number
---@param box number
---@return number
function M.box_new_below_from(ctx, box) end

---@param ctx number
---@param box number
---@return number
function M.box_new_cursored(ctx, box) end

---@param ctx number
---@param box number
---@param width number
---@return nil
function M.box_shrink_width_to(ctx, box, width) end

---@param ctx number
---@param box number
---@param other number
---@return nil
function M.box_update_cursor_from(ctx, box, other) end

---@param ctx number
---@param box number
---@param width number
---@return nil
function M.box_set_width(ctx, box, width) end

---@param ctx number
---@param box number
---@return number
function M.box_get_hl(ctx, box) end

---@param ctx number
---@param box number
---@param width number
---@return nil
function M.box_set_max_width(ctx, box, width) end

---@param ctx number
---@param box number
---@return number
function M.box_get_width(ctx, box) end

---@param ctx number
---@param box number
---@param width number
---@return nil
function M.box_expand_width_to(ctx, box, width) end

---@param ctx number
---@param box number
---@param height number
---@return nil
function M.box_expand_height_to(ctx, box, height) end

---@param ctx number
---@param box number
---@param height number
---@return nil
function M.box_shrink_height_to(ctx, box, height) end

---@param ctx number
---@param box number
---@param height number
---@return nil
function M.box_set_height(ctx, box, height) end

---@param ctx number
---@param box number
---@return number
function M.box_get_height(ctx, box) end

---@param ctx number
---@param box number
---@return nil
function M.box_clean(ctx, box) end

---@param ctx number
---@param box number
---@param str string
---@return nil
function M.box_append_str(ctx, box, str) end

---@param ctx number
---@param box number
---@param style number
---@return nil
function M.box_set_hl(ctx, box, style) end

---@param ctx number
---@param box number
---@param str string
---@param style number
---@return nil
function M.box_append_word(ctx, box, str, style) end

---@param ctx number
---@param expected_bg StripRightExpect
---@return nil
function M.box_context_strip_right_space(ctx, expected_bg) end

---@param ctx number
---@param box number
---@param otherCtx number
---@param left number
---@param top number
---@return nil
function M.box_render_over(ctx, box, otherCtx, left, top) end

return M

