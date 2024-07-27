---@param document Banana.Instance
return function(document)
  local tabline = document:getElementById("tabline")
  local container = document:getElementById("container")
  -- dont clone the home tab because it is static
  document:loadNmlTo("examples/lazy/home", container, true)

  for v in tabline:childIter() do
    local remapStr = v:child(1):getTextContent()
    local remapCh = ''
    local k = 1
    while remapStr:sub(k, k) ~= '(' do
      k = k + 1
    end
    k = k + 1
    remapCh = remapStr:sub(k, k)
    v:attachRemap("n", remapCh, {}, function()
      for u in tabline:childIter() do
        if u == v then
          if not u:hasClass("selected") then
            u:addClass("selected")
            local link = u:getAttribute("data_link")
            assert(link ~= nil, "Unreachable")
            -- only preserve the home tree, clone all the other trees
            document:loadNmlTo("examples/lazy/" .. link, container, link == "home")
          end
        else
          u:removeClass("selected")
        end
      end
    end, {})
  end
end
