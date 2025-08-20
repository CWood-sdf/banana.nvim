local ent = require("banana.nml.entity")

local M = {}
function M.run()
    local out = [[
Currently, banana supports the following named entities:

]]

    for k, v in pairs(ent) do
        out = out .. "- `" .. k .. "`: `" .. v .. "`\n"
    end

    out = out .. [[

Banana also supports numerical entities (eg &#32; means space (character code 32)). Currently, only decimal numbers are supported as the number
]]

    local file = io.open("./wiki/Entities.md", "w")
    assert(file ~= nil)
    file:write(out)
    file:close()
end

return M
