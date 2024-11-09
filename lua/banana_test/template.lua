---@param document Banana.Instance
return function (document)
    local c = document:createElement("Asdf")
    local c2 = document:createElement("div")
    c2:appendTextNode("lolll")
    c:appendNode(c2)
    document:body():appendNode(c)
end
