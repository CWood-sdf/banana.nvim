local M = {}

local baseFolder = "banana"

---@type { [string]: [Banana.Nml.Parser, Banana.Ast] }
local nmlAsts = {

}

---@type { [string]: Banana.Ncss.RuleSet[] }
local ncssAsts = {

}

---@param filename string
---@return Banana.Ast, Banana.Ncss.RuleSet[], string[]
function M.nmlLoad(filename)
    if nmlAsts[filename] ~= nil then
        return nmlAsts[filename][2], nmlAsts[filename][1].styleSets, nmlAsts[filename][1].scripts
    end
    local parser = require('banana.nml.parser').fromFile(filename)
    assert(parser ~= nil,
        "Could not generate parser for file '" .. filename .. "'")
    local ast = parser:parse()
    assert(ast ~= nil,
        "Unable to parse file '" .. filename .. "'")
    require("banana.nml.cleanAst").cleanAst(ast)
    nmlAsts[filename] = { parser, ast }
    return ast, parser.styleSets, parser.scripts
end

--- https://stackoverflow.com/questions/1340230/check-if-directory-exists-in-lua
---@param file string
---@return boolean
local function fileExists(file)
    local val = vim.fn.filereadable(file)
    return val == 1
end

---@param path string
---@return boolean
local function isdir(path)
    -- "/" works on both Unix and Windows
    path = path .. "/"
    local ok, _, code = os.rename(path, path)
    if not ok then
        if code == 13 then
            -- Permission denied, but it exists
            return true
        end
    end
    if ok == nil then
        return false
    end
    return ok
end

---@param basePath string
---@param paths string[]
---@param i number?
---@return string?
local function getPathFor(basePath, paths, ft, i)
    i = i or 1
    if i < #paths then
        if not isdir(basePath .. "/" .. paths[i]) then
            return nil
        end
        return getPathFor(basePath .. "/" .. paths[i], paths, ft, i + 1)
    end
    local hasDot = #vim.split(paths[i], '\\.') ~= 1
    if hasDot then
        if fileExists(basePath .. "/" .. paths[i]) then
            return basePath .. "/" .. paths[i]
        else
            return nil
        end
    end
    local fname = basePath .. "/" .. paths[i] .. "." .. ft
    if fileExists(fname) then
        return fname
    end
    fname = basePath .. "/" .. paths[i] .. "/index." .. ft
    if fileExists(fname) then
        return fname
    end
    return nil
end

---@param file string
---@param ft string
---@return Banana.Ast, Banana.Ncss.RuleSet[], string[]
local function basicRequire(file, ft)
    local path = vim.iter(vim.split(file, '/'))
        :filter(function(v) return #v ~= 0 end)
        :totable()
    for _, v in ipairs(vim.api.nvim_list_runtime_paths()) do
        local fname = getPathFor(v .. "/" .. baseFolder, path, ft)
        if fname ~= nil then
            return M.nmlLoad(fname)
        end
    end
    error("Could not find nml file '" .. file .. "'")
end
---@param file string
---@return Banana.Ast, Banana.Ncss.RuleSet[], string[]
function M.nmlRequire(file)
    return basicRequire(file, "nml")
end

---@param filename string
---@return Banana.Ncss.RuleSet[]
function M.ncssLoad(filename)
    if ncssAsts[filename] ~= nil then
        return ncssAsts[filename]
    end
    local rules = require('banana.ncss.parser').parseFile(filename)
    ncssAsts[filename] = rules
    return rules
end

---@param file string
---@return Banana.Ast, Banana.Ncss.RuleSet[], string[]
function M.ncssRequire(file)
    return basicRequire(file, "ncss")
end

return M
