---@param document Banana.Instance
return function(document)
  local spans = document:getElementsByClassName("card")
  document:on("CursorMoved", {
    callback = function()
      print("yeet")
      for _, v in ipairs(spans) do
        if v:isHovering() then
          v:addClass("rel")
        else
          v:removeClass("rel")
        end
      end
    end,
  })
  document:body():attachRemap("n", "q", {}, function()
    document:close()
  end, {})
end
