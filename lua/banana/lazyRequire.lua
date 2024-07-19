---@param name string
return function(name)
    local ret = {}

    local obj = nil

    setmetatable(ret, {
        __index = function(_, n)
            if obj == nil then
                obj = require(name)
            end
            return obj[n]
        end,
    })
    return ret
end
