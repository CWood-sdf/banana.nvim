---@param document Banana.Instance
return function(document)
  local children = document:querySelectorAll("#flex > div")
  vim.defer_fn(function()
    children[1]:addClass("asdf")
  end, 1000)

  vim.defer_fn(function()
    children[1]:removeClass("asdf")
    children[2]:addClass("asdf")
  end, 4000)
  -- document.DEBUG = true
  -- local flex = document:getElementById("flex")
  -- local i = 1
  --
  -- for node in flex:childIter() do
  --   print("(" ..
  --     node.boundBox.leftX ..
  --     ", " .. node.boundBox.topY .. "), (" .. node.boundBox.rightX .. ", " .. node.boundBox.bottomY .. ")")
  --   break
  -- end
  -- document:on("CursorMoved", {
  --   callback = function()
  --     i = i + 1
  --     for node in flex:childIter() do
  --       if node:isHovering() then
  --         node:addClass("asdf")
  --       else
  --         node:removeClass("asdf")
  --       end
  --     end
  --   end
  -- })
end
