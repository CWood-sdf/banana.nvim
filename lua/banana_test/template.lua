---@param document Banana.Instance
return function (document)
    local c = document:createElement("Asdf")
    local c2 = document:createElement("div")
    c2:appendTextNode("lolll")
    c:appendChild(c2)
    document:body():appendChild(c)
end
