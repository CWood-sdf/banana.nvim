---@param document Banana.Instance
return function (document)
    document:body():attachRemap("n", "q", {}, function ()
        document:close()
    end)
end
