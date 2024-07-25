---@param document Banana.Instance
return function(document)
    local counter = document:getElementById("counter")
    counter:attachRemap('n', 'a', { 1 }, function()
        print("NOO I DONT WANT TO ADD 1")
    end, {})
    counter:attachRemap('n', 'a', { "hover" }, function()
        print("Wow hovering over the element")
        local count = tonumber(counter:getTextContent())
        count       = count + 2
        counter:setTextContent(count .. "")
    end, {})
    counter:attachRemap('n', 'a', {}, function()
        print("lame")
        local count = tonumber(counter:getTextContent())
        count       = count + vim.v.count1
        counter:setTextContent(count .. "")
    end, {})
end
