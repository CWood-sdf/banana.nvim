---@param document Banana.Instance
return function(document)
  local tabline = document:getElementById("tabline")

  ---@type { [1]: string, loc: boolean, loaded: boolean }[]
  local plugins = {
    { "banana.nvim", loc = true,  loaded = true },
    { "cloak.nvim",  loc = false, loaded = true },
    { "cloak.nvim",  loc = false, loaded = true },
    { "pineapple",   loc = true,  loaded = false },
    { "venn.nvim",   loc = false, loaded = true },
  }
  local startTime = vim.uv.hrtime()

  local astToClone = document:getElementById("plugin-template"):children()[1]

  local root = document:getElementsByTag('body')[1]
  for _, v in ipairs(plugins) do
    local newAst = astToClone:clone()
    newAst:children()[1]:setTextContent(v[1])
    if v.loc then
      newAst:addClass("local")
    end
    if v.loaded then
      newAst:addClass("plugin-loaded")
    end
    root:appendNode(newAst)
  end
  document:render()


  for i, v in ipairs(tabline:children()) do
    if type(v) ~= "string" then
      local remapStr = v:child(1):getTextContent()
      local remapCh = ''
      local k = 1
      while remapStr:sub(k, k) ~= '(' do
        k = k + 1
      end
      k = k + 1
      remapCh = remapStr:sub(k, k)
      v:attachRemap("n", remapCh, {}, function()
        for j, u in ipairs(tabline:children()) do
          if type(u) == "string" then
            goto continue
          end
          if i == j then
            u:addClass("selected")
            u:defaultStyles()
          else
            u:removeClass("selected")
            u:defaultStyles()
          end
          ::continue::
        end
        document:render()
      end, {})
    end
  end
  print((vim.uv.hrtime() - startTime) / 1e6 .. "ms")


  -- print(document:getElementById("root"):getTextContent())
end
