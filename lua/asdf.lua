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

  local astToClone = document:getElementById("plugin-template"):children()[1]

  local root = document:getElementById("root")
  for _, v in ipairs(plugins) do
    local newAst = vim.fn.deepcopy(astToClone)
    setmetatable(newAst, { __index = require('banana.nml.ast').Ast })
    setmetatable(newAst:children()[1], { __index = require('banana.nml.ast').Ast })
    ---@cast newAst Banana.Ast
    newAst._parent = root
    newAst:children()[1]:setTextContent(v[1])
    if v.loc then
      newAst:addClass("local")
    else
      newAst:addClass("not-local")
    end
    if v.loaded then
      newAst:addClass("plugin-loaded")
    else
      newAst:addClass("plugin-not-loaded")
    end
    table.insert(root.nodes, newAst)
  end
  vim.defer_fn(function()
    document:render()
  end, 100)


  for i, v in ipairs(tabline:children()) do
    if type(v) ~= "string" then
      local remapStr = v.nodes[2].nodes[1]
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
            u:removeClass("not-selected")
            u:defaultStyles()
          else
            u:removeClass("selected")
            u:addClass("not-selected")
            u:defaultStyles()
          end
          ::continue::
        end
        document:render()
      end, {})
    end
  end


  -- print(document:getElementById("root"):getTextContent())
end
