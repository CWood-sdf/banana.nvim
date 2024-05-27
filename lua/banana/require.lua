local M = {}

---@type { [string]: [Banana.Nml.Parser, Banana.Ast] }
local nmlAsts = {

}

---@type { [string]: Banana.Ncss.RuleSet[] }
local ncssAsts = {

}

---@param filename string
---@return Banana.Ast, Banana.Ncss.RuleSet[], string[]
function M.nmlRequire(filename)
    if nmlAsts[filename] ~= nil then
        return nmlAsts[filename][2], nmlAsts[filename][1].styleSets, nmlAsts[filename][1].scripts
    end
    local parser = require('banana.nml.parser').fromFile(filename)
    if parser == nil then
        error("Could not generate parser for file '" .. filename .. "'")
    end
    local ast = parser:parse()
    if ast == nil then
        error("Unable to parse file '" .. filename .. "'")
    end
    nmlAsts[filename] = { parser, ast }
    return ast, parser.styleSets, parser.scripts
end

---@param filename string
---@return Banana.Ncss.RuleSet[]
function M.ncssRequire(filename)
    if ncssAsts[filename] ~= nil then
        return ncssAsts[filename]
    end
    local rules = require('banana.ncss.parser').parseFile(filename)
    ncssAsts[filename] = rules
    return rules
end

return M
