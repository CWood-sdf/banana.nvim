---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
local M = {}

local baseFolder = "banana"

---@type { [string]: [Banana.Nml.Parser, Banana.Ast, { [string]: Banana.Component } ] }
local nmlAsts = {

}

---@type { [string]: Banana.Ncss.RuleSet[] }
local ncssAsts = {

}

---@type "memo"|"reload"|"reload_active"
local storeMode = "memo"

function M.parseReload()
    storeMode = "reload"
end

---@param components Banana.Component[]
---@return { [string]: Banana.Component }
local function componentListToMap(components)
    local ret = {}
    for _, v in ipairs(components) do
        ret[v.name] = v
    end
    return ret
end

---comment
---@param path string
---@param name string
---@return Banana.Component?
function M.getComponentFrom(path, name)
    if nmlAsts[path] == nil then
        M.nmlLoad(path)
    end
    local map = nmlAsts[path][3]
    return map[name]
end

---@param filename string
---@return Banana.Ast, Banana.Ncss.RuleSet[], string[], string[]
function M.nmlLoad(filename)
    if nmlAsts[filename] ~= nil and storeMode == "memo" then
        return nmlAsts[filename][2], nmlAsts[filename][1].styleSets,
            nmlAsts[filename][1].preScripts, nmlAsts[filename][1].postScripts
    end

    local endStoreMode = storeMode
    if storeMode == "reload" then
        storeMode = "reload_active"
        endStoreMode = "memo"
    end
    local parser = require("banana.nml.parser").fromFile(filename)
    if parser == nil then
        log.throw("Could not generate parser for file '" .. filename .. "'")
        error("")
    end
    local ast, components = parser:parse()
    if ast == nil then
        log.throw("Unable to parse file '" .. filename .. "'")
        error("")
    end
    require("banana.nml.cleanAst").cleanAst(ast)
    for _, v in ipairs(components or {}) do
        require("banana.nml.cleanAst").cleanAst(v.ast)
    end
    nmlAsts[filename] = { parser, ast, componentListToMap(components or {}) }
    storeMode = endStoreMode
    return ast, parser.styleSets, parser.preScripts, parser.postScripts
end

---@param str string
---@return Banana.Ast, Banana.Ncss.RuleSet[], string[], string[]
function M.nmlLoadString(str)
    local parser = require("banana.nml.parser").fromString(str)
    if parser == nil then
        log.throw("Could not generate parser for string")
        error("")
    end
    local ast, components = parser:parse()
    if components ~= nil and #components ~= 0 then
        log.throw("Cannot have <template> tags in non-file code")
    end
    if ast == nil then
        log.throw("Unable to parse string ")
        error("")
    end
    require("banana.nml.cleanAst").cleanAst(ast)
    for _, v in ipairs(components or {}) do
        require("banana.nml.cleanAst").cleanAst(v.ast)
    end
    return ast, parser.styleSets, parser.preScripts, parser.postScripts
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
    local hasDot = #vim.split(paths[i], "\\.") ~= 1
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
---@param ft "nml"|"ncss"
---@return string?
function M.getPathForRequire(file, ft)
    local path = {}
    for _, v in ipairs(vim.split(file, "/")) do
        if #v ~= 0 then
            table.insert(path, v)
        end
    end
    -- local path = vim.iter(vim.split(file, "/"))
    --                 :filter(function (v) return #v ~= 0 end)
    --                 :totable()
    for _, v in ipairs(vim.api.nvim_list_runtime_paths()) do
        local fname = getPathFor(v .. "/" .. baseFolder, path, ft)
        if fname ~= nil then
            return fname
        end
    end
end

---@param file string
---@param ft string
---@return Banana.Ast, Banana.Ncss.RuleSet[], string[], string[]
local function basicRequire(file, ft)
    local path = M.getPathForRequire(file, ft)
    if path == nil then
        log.throw("Could not find nml file '" .. file .. "'")
        error()
    end
    return M.nmlLoad(path)
end
---@param file string
---@return Banana.Ast, Banana.Ncss.RuleSet[], string[], string[]
function M.nmlRequire(file)
    return basicRequire(file, "nml")
end

---@param filename string
---@return Banana.Ncss.RuleSet[]
function M.ncssLoad(filename)
    if ncssAsts[filename] ~= nil and storeMode == "memo" then
        return ncssAsts[filename]
    end
    local rules = require("banana.ncss.parser").parseFile(filename)
    ncssAsts[filename] = rules
    return rules
end

---@param file string
---@return Banana.Ast, Banana.Ncss.RuleSet[], string[], string[]
function M.ncssRequire(file)
    return basicRequire(file, "ncss")
end

return M
