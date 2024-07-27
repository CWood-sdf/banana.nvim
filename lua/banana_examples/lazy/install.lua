-- this whole file is a *very* contrived example but it is here to demo stuff
---@param document Banana.Instance
return function(document)
  ---@type { [1]: string, loc: boolean, loaded: boolean, installTime: number }[]
  local plugins = {
    { "banana.nvim", loc = true,  loaded = true,  installTime = 1000 },
    { "cloak.nvim",  loc = false, loaded = true,  installTime = 500, },
    { "cloak.nvim",  loc = false, loaded = true,  installTime = 700 },
    { "pineapple",   loc = true,  loaded = false, installTime = 1100 },
    { "venn.nvim",   loc = false, loaded = true,  installTime = 1300 },
  }
  local progress = 0
  local cancelled = false
  local installList = document:getElementById("install_list")
  -- the way this is set up kinda prevents you from like quickly swapping back and forth between the two, but in a real plugin, this would trigger some background lua function that you can then get reports from
  for _, v in ipairs(plugins) do
    local list_item = document:createElement('li')
    list_item:setTextContent(v[1])
    installList:appendNode(list_item)

    vim.defer_fn(function()
      if document:getElementById("progress"):isNil() or cancelled then
        cancelled = true
        return
      end
      list_item:remove()
      progress = progress + 1
      local pct = progress / #plugins
      document:getElementById("working_count"):setAttribute("data_count", (#plugins - progress) .. "")
      local width = document:getElementById("progress"):getWidth()
      document:getElementById("progress-left"):setTextContent(string.rep('—', width * pct))
      document:getElementById("progress-right"):setTextContent(string.rep('—', width * (1 - pct)))
      if pct == 1 then
        vim.defer_fn(function()
          document:getElementById("progress"):remove()
          document:getElementById("working_count"):parent():remove()
        end, 1000)
      end
    end, v.installTime)
  end
end
