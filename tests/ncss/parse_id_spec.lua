local ncss = require('banana.ncss.parser')
local asts = require('tests.ncss.asts')
---@param rule Banana.Ncss.Query
---@param allowed { [string]: boolean }
local function rule_applys_to(rule, allowed)
    for k, v in pairs(asts) do
        local vals = rule:find(v)
        if #vals == 0 then
            assert(allowed[k] ~= true, "Found no matches for " .. k .. " when expected one")
        else
            assert(allowed[k] == true, "Found matches for " .. k .. " when expected none")
        end
    end
end
describe("ncss selector", function()
    it("id selector should work", function()
        local sheet = "#test {}"
        local rules = ncss.parseText(sheet)
        assert(#rules == 1, "should return 1 rule")
        rule_applys_to(rules[1].query, { id = true })
    end)
end)
