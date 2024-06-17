---@param document Banana.Instance
return function(document)
  local spans = document:getElementsByClassName("card")
  vim.api.nvim_create_autocmd("CursorMoved", {
    callback = function()
      for i, v in ipairs(spans) do
        print(i)
        if v:isHovering() then
          v:addClass("rel")
        else
          v:removeClass("rel")
        end
      end
      document:render()
    end,
  })
end
