local mainFile = "zig/src/box.zig"
local file = io.open(mainFile, "r")

if file == nil then
    error("Could not open file " .. mainFile)
end

local contents = file:read("*a")
file:close()

local newFileName = "zig/decls.json"
local newFile = io.open(newFileName, "w")
if newFile == nil then
    error("Could not open new file " .. newFile)
end
newFile:write(contents)
newFile:close()
vim.cmd("e " .. newFileName)
vim.cmd("so zig/transform.vim")
vim.cmd("w")

local typeFileName = "zig/types.lua"
local typeFile = io.open(typeFileName, "w")
if typeFile == nil then
    error("Could not open type file " .. typeFile)
end
typeFile:write(contents)
typeFile:close()
vim.cmd("e " .. typeFileName)
vim.cmd("so zig/transformExpect.vim")
vim.cmd("w")

typeFile = io.open(typeFileName, "r")
if typeFile == nil then
    error("Could not open type file for reading:" .. typeFile)
end
local typeDecls = typeFile:read("*a")
typeFile:close()

local jsonFile = io.open(newFileName, "r")

if jsonFile == nil then
    error("Could not open json file " .. newFileName)
end

local jsonStr = jsonFile:read("*a")
jsonFile:close()

---@alias param [string, string]
---@alias ret [string]

---@class fn
---@field params (param|ret)[]
---@field name string


---@type fn[]
local json = vim.json.decode(jsonStr)

local outname = "lua/banana/libbananabox.lua"
local outfile = io.open(outname, "w")
if outfile == nil then
    error("could not open output file " .. outname)
end

outfile:write("---@meta\n\nlocal M = {}\n\n")

outfile:write(typeDecls .. "\n\n")

for _, fn in ipairs(json) do
    for _, param in ipairs(fn.params) do
        if #param == 1 then
            outfile:write("---@return " .. param[1] .. "\n")
        else
            outfile:write("---@param " .. param[1] .. " " .. param[2] .. "\n")
        end
    end
    outfile:write("function M." .. fn.name .. "(")
    local params = ""
    for _, param in ipairs(fn.params) do
        if #param == 2 then
            params = params .. param[1] .. ", "
        end
    end
    if #params > 2 then
        params = params:sub(1, #params - 2)
    end
    outfile:write(params)
    outfile:write(") end\n\n")
end
outfile:write("\n\nreturn M")

vim.notify("wrote output to " .. outname .. "\n")
