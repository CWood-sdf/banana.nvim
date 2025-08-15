local cmdTree = {}

-- {

---@class (exact) CmdTree.NvimCmdDefOpts
---@field nargs string?
---@field complete? fun(working: string, current: string): string[]
---@field keepscript boolean?
---@field range boolean?
---@field count boolean?
---@field bang boolean?
---@field bar boolean?
---@field register boolean?
---@field buffer? boolean|number
---@field addr string?

---@class (exact) CmdTree.CmdOpts
---@field name string
---@field fargs string[]
---@field args string
---@field bang boolean
---@field line1 number
---@field line2 number
---@field range number
---@field count number
---@field reg string
---@field mods table
---@field smods table
---@field params string[][]

---@alias CmdTree.ParameterFn fun(args: CmdTree.CmdOpts): string[]|nil

---@class CmdTree.ParameterSet
---@field tp "repeat"|"optional"|"required"|"positional"|"flag"
---@field required? boolean
---@field fn CmdTree.ParameterFn
---@field flagSet? { [string]: boolean }

---@class (exact) CmdTree.RepeatParameter : CmdTree.ParameterSet
---@field tp "repeat"
---@field fn CmdTree.ParameterFn
---@field maxTimes number

---@class (exact) CmdTree.OptionalParameter : CmdTree.ParameterSet
---@field tp "optional"
---@field fn CmdTree.ParameterFn

---@class (exact) CmdTree.RequiredParameter : CmdTree.ParameterSet
---@field tp "required"
---@field fn CmdTree.ParameterFn

---@class (exact) CmdTree.FlagParameter : CmdTree.ParameterSet
---@field tp "flag"
---@field fn CmdTree.ParameterFn
---@field flagSet { [string]: boolean}

---@class (exact) CmdTree.PositionalParameter : CmdTree.ParameterSet
---@field tp "positional"
---@field required boolean
---@field fn CmdTree.ParameterFn

---@class CmdTree.SubTree
---@field _callback? fun(args: CmdTree.CmdOpts): any
---@field [string] CmdTree.SubTree
---@field [number] CmdTree.ParameterSet

---@class CmdTree.CmdTree
---@field [string] CmdTree.SubTree

local testTree = {}


---@return CmdTree.RepeatParameter
---@param fn CmdTree.ParameterFn
---@param maxTimes number|nil
function cmdTree.repeatParams(fn, maxTimes)
    local ret = {
        tp = "repeat",
        fn = fn,
        maxTimes = maxTimes or 100000
    }
    return ret
end

---@return CmdTree.FlagParameter
---@param flags string[]
function cmdTree.flagParam(flags)
    local flagSet = {}
    local hasSpace = false
    for _, v in ipairs(flagSet) do
        if v == " " then
            hasSpace = true
            break
        end
    end
    if not hasSpace then
        table.insert(flags, " ")
    end
    local i = 1
    for _, v in ipairs(flags) do
        flagSet[v] = i
        i          = i + 1
    end
    ---@type CmdTree.FlagParameter
    local ret = {
        tp = "flag",
        fn = function () return flags end,
        flagSet = flagSet,
    }
    return ret
end

---@return CmdTree.PositionalParameter
---@param required boolean
---@param name string
function cmdTree.positionalParam(name, required)
    ---@type CmdTree.PositionalParameter
    local ret = {
        tp = "positional",
        fn = function ()
            return { "[" .. name .. "]" }
        end,
        required = required,
    }
    return ret
end

---@return CmdTree.RequiredParameter
---@param fn CmdTree.ParameterFn
function cmdTree.optionalParams(fn)
    return {
        tp = "optional",
        fn = fn
    }
end

---@return CmdTree.RequiredParameter
---@param fn CmdTree.ParameterFn
function cmdTree.requiredParams(fn)
    return {
        tp = "required",
        fn = fn
    }
end

local function filterCompletion(working, items)
    local newItems = {}
    for _, item in ipairs(items) do
        if item:sub(1, #working) == working or item == " " then
            table.insert(newItems, item)
        end
    end
    return newItems
end

---@param tree CmdTree.SubTree
---@param path string
function cmdTree.validateSubTree(tree, path)
    local keysCount = 0
    for k, v in pairs(tree) do
        if tonumber(k) ~= nil then
            goto continue
        end
        keysCount = keysCount + 1
        if k == "_callback" then
            assert(type(v) == "function",
                "Invalid _callback in cmd tree (got " ..
                type(v) .. ", but expected a function) (at path " .. path .. ")")
            goto continue
        end
        assert(type(v) == "table",
            "Invalid cmd tree, subcmd must be a table (at path " .. path .. ")")
        cmdTree.validateSubTree(v, path .. "." .. k)
        ::continue::
    end
    assert(keysCount > 0,
        "Invalid cmd tree, leaf node must have a _callback (at path " ..
        path .. ")")
    local flagCount = 0
    for k, v in ipairs(tree) do
        assert(tree._callback ~= nil,
            "Invalid cmd tree, leaf node must have a _callback (given parameters, but no _callback) (at path " ..
            path .. ")")
        local location = "at path " .. path .. ", parameter " .. k
        assert(type(v) == "table",
            "Invalid cmd tree, parameter must be a table (" .. location .. ")")
        assert(type(v.tp) == "string",
            "Invalid cmd tree, parameter must have a type (" .. location .. ")")
        assert(type(v.fn) == "function",
            "Invalid cmd tree, parameter must have a function (" ..
            location .. ")")
        assert(
            v.tp == "repeat" or v.tp == "optional" or v.tp == "required" or
            v.tp == "positional" or v.tp == "flag",
            "Invalid cmd tree, parameter type must be repeat, optional, flag, positional, or required (" ..
            location .. ")")
        if v.tp == "repeat" then
            ---@cast v CmdTree.RepeatParameter
            assert(v.maxTimes ~= nil,
                "Invalid cmd tree, repeat parameter must have a maxTimes field (" ..
                location .. ")")
        end
        if v.tp == "optional" then
            assert(k == #tree or (k == #tree - 1 and tree[#tree].tp == "flag"),
                "Invalid cmd tree, optional parameter must be last or last before flags (" ..
                location .. ")")
        end
        if v.tp == "flag" then
            flagCount = flagCount + 1
            assert(k == #tree,
                "Invalid cmd tree, flag parameter set must be last (" ..
                location .. ")")
        end
        if flagCount > 1 then
            error("There can only be one set of flags")
        end
    end
    local isOptional = true
    for i = #tree, 1, -1 do
        ---@type CmdTree.ParameterSet
        local v = tree[i]
        ---@diagnostic disable-next-line: undefined-field
        if v.tp == "optional" or (v.tp == "positional" and not v.required) or v.tp == "flag" then
            if not isOptional then
                error(
                    "There is an optional parameter preceding a required parameter")
            end
        else
            isOptional = false
        end
    end
end

function cmdTree.validateCmdTree(tree)
    for k, _ in pairs(tree) do
        assert(tonumber(k) == nil,
            "Invalid key in cmd tree (got number " ..
            k .. ", but expected a capitalized string)")
        assert(k:sub(1, 1):upper() == k:sub(1, 1),
            "Invalid key in cmd tree (got " ..
            k .. ", but expected a capitalized string)")
        assert(type(tree[k]) == "table",
            "Invalid cmd tree, subcmd tree must be a table (while creating command " ..
            k .. ")")
        cmdTree.validateSubTree(tree[k], k)
    end
end

local function isUpper(c)
    return c:match("[A-Z]") ~= nil
end

---@param cmd string
---@param i? number
---@return string
local function getRngOrNum(cmd, i)
    i = i or 1
    if i > #cmd then
        return ""
    end
    if isUpper(cmd:sub(i, i)) then
        return ""
    end
    return cmd:sub(i, i) .. getRngOrNum(cmd, i + 1)
end

---@param tree CmdTree.SubTree
---@param paramIndex number
---@param repeatCount number
---@param cmdArgs CmdTree.CmdOpts
---@return string[], number, number
local function getNextParams(tree, paramIndex, repeatCount, cmdArgs)
    ::top::
    local flags = nil
    if #tree ~= 0 and tree[#tree].tp == "flag" then
        flags = tree[#tree].fn(cmdArgs) or {}
    end
    if tree[paramIndex] == nil or (flags ~= nil and paramIndex == #tree) then
        return flags or {}, paramIndex, repeatCount
    end
    while tree[paramIndex].tp == "repeat" do
        local t = tree[paramIndex]
        ---@cast t CmdTree.RepeatParameter
        local vals = tree[paramIndex].fn(cmdArgs)
        if repeatCount >= t.maxTimes then
            repeatCount = 0
            paramIndex = paramIndex + 1
            break
        elseif vals == nil then
            repeatCount = 0
            paramIndex = paramIndex + 1
            goto top
        else
            for _, v in ipairs(flags or {}) do
                if v ~= " " then
                    table.insert(vals, v)
                end
            end
            return vals, paramIndex, repeatCount + 1
        end
    end
    if tree[paramIndex] == nil then
        return flags or {}, paramIndex, repeatCount
    end

    if tree[paramIndex].tp == "optional" then
        local vals = tree[paramIndex].fn(cmdArgs)
        paramIndex = paramIndex + 1
        if vals == nil then
            repeatCount = 0
            paramIndex = paramIndex + 1
            goto top
        end
        for _, v in ipairs(flags or {}) do
            table.insert(vals, v)
        end
        return vals, paramIndex, repeatCount
    end
    if tree[paramIndex] == nil then
        return flags or {}, paramIndex, repeatCount
    end

    if tree[paramIndex].tp == "required" or (tree[paramIndex].tp == "positional" and tree[paramIndex].required) then
        local vals = tree[paramIndex].fn(cmdArgs)
        paramIndex = paramIndex + 1
        if vals == nil then
            repeatCount = 0
            paramIndex = paramIndex + 1
            goto top
        end
        for _, v in ipairs(flags or {}) do
            if v ~= " " then
                table.insert(vals, v)
            end
        end
        return vals, paramIndex, repeatCount
    end

    if tree[paramIndex].tp == "positional" then
        local vals = tree[paramIndex].fn(cmdArgs)
        paramIndex = paramIndex + 1
        if vals == nil then
            repeatCount = 0
            paramIndex = paramIndex + 1
            goto top
        end
        for _, v in ipairs(flags or {}) do
            table.insert(vals, v)
        end
        return vals, paramIndex, repeatCount
    end

    return flags or {}, paramIndex, repeatCount
end

---@param tree CmdTree.SubTree
---@param paramIndex number
---@param repeatCount number
---@param cmdArgs CmdTree.CmdOpts
---@return string[], number, number
local function getPossibleParams(tree, paramIndex, repeatCount, cmdArgs)
    local ret = {}
    for k, _ in pairs(tree) do
        if tonumber(k) == nil and k ~= "_callback" then
            table.insert(ret, k)
        end
    end
    local vals, newParamIndex, newRepeatCount = getNextParams(tree, paramIndex,
        repeatCount, cmdArgs)
    for _, v in ipairs(vals) do
        table.insert(ret, v)
    end
    if tree._callback ~= nil and tree[1] == nil then
        table.insert(ret, " ")
    end
    return ret, newParamIndex, newRepeatCount
end

---@param tree CmdTree.SubTree
---@param paramIndex number
---@param expected? string[]
---@param newParamIndex number
---@return string
local function isCallable(tree, paramIndex, expected, newParamIndex)
    if tree._callback == nil then
        return "No callback found"
    end
    local param = tree[paramIndex]
    if param == nil then
        return ""
    end
    if param.tp == "optional" or (param.tp == "positional" and not param.required) or param.tp == "flag" then
        return ""
    end
    if param.tp == "repeat" and paramIndex ~= newParamIndex then
        paramIndex = newParamIndex
        return isCallable(tree, newParamIndex, expected, newParamIndex)
    end
    return "Missing parameters"
end

---@param tree CmdTree.SubTree the cmd tree to traverse
---@param fargs string[]
---@param cmdArgs CmdTree.CmdOpts
---@param expected? string[]
---@param i? number
---@param paramIndex? number the current parameter index
---@param isParams? boolean if we are currently in the parameters section
---@param repeatCount? number the current repeat count
---@param newParamIndex? number what the parameter index will be if we use the parameter
---@param newRepeatCount? number what the repeat count will be if we use the parameter
---@return string[], CmdTree.SubTree?, string -- returns the completion items, the tree at the end of the completion, and an error message if there is one
local function traverseTree(tree, fargs, cmdArgs, expected, i, paramIndex,
                            isParams, repeatCount, newParamIndex,
                            newRepeatCount)
    i = i or 1
    paramIndex = paramIndex or 1
    repeatCount = repeatCount or 0
    newParamIndex = newParamIndex or paramIndex
    newRepeatCount = newRepeatCount or repeatCount
    expected = expected or {}
    isParams = isParams or false

    -- This is the base case, where we don't want to have completion figure out the next paramaters
    if i == 1 and expected[1] == nil then
        local possibleParams, newPI, newRC = getPossibleParams(tree, paramIndex,
            repeatCount, cmdArgs)
        return traverseTree(tree, fargs, cmdArgs, possibleParams, i, paramIndex,
            isParams, repeatCount, newPI, newRC)
    end

    -- If we have gone through all the current parameters, then we just return what we expect the next parameters to be
    -- Also return an error message for when it's command time
    if i > #fargs then
        -- paramIndex = newParamIndex
        return expected, tree, isCallable(tree, paramIndex, expected, #fargs + 1)
    end

    -- This is when we have extra parameters that can't have completion provided
    -- So we just add them all to the current parameter list, and then return the next expected parameters
    if #expected == 0 then
        paramIndex = newParamIndex
        repeatCount = newRepeatCount
        cmdArgs.params[paramIndex] = cmdArgs.params[paramIndex] or {}
        table.insert(cmdArgs.params[paramIndex], fargs[i])
        return traverseTree(tree, fargs, cmdArgs, expected, i + 1, paramIndex,
            isParams, repeatCount, paramIndex,
            repeatCount)
    end

    local found = false
    -- if there is an expected space, then it is optional
    local isOptional = false
    for _, v in ipairs(expected) do
        if v == fargs[i] then
            found = true
            break
        end
        if v:sub(1, 1) == "[" and fargs[i] ~= nil and #fargs[i] ~= 0 then
            found = true
            break
        end
        if v == " " then
            isOptional = true
        end
    end
    --- Basically the user ignored an optional parameter and is now on any random extra parameters (this is the same case as #expected == 0)
    if not found and isOptional then
        paramIndex = newParamIndex
        repeatCount = newRepeatCount
        cmdArgs.params[paramIndex] = cmdArgs.params[paramIndex] or {}
        table.insert(cmdArgs.params[paramIndex], fargs[i])
        return traverseTree(tree, fargs, cmdArgs, {}, i + 1, paramIndex, isParams,
            0, paramIndex, repeatCount)
    end
    --- Umm they are just typing random stuff
    if not found then
        if isParams then
            return {}, nil, "Invalid parameter '" .. fargs[i] .. "'"
        end
        return {}, nil, "Invalid subcommand or parameter '" .. fargs[i] .. "'"
    end

    local current = fargs[i]

    if tree[current] ~= nil and not isParams then
        -- descend the currently defined tree
        local newTree = tree[current]
        local newPI, newRC = 0, 0
        expected, newPI, newRC = getPossibleParams(newTree, 1, 0, cmdArgs)
        return traverseTree(tree[current], fargs, cmdArgs, expected, i + 1,
            paramIndex, false, repeatCount, newPI, newRC)
    else
        -- we have reached a flag, we must update the new index to the end
        if tree[#tree].tp == "flag" and tree[#tree].flagSet[fargs[i]] ~= nil then
            newParamIndex = paramIndex
            cmdArgs.params[#tree] = cmdArgs.params[#tree] or {}
            table.insert(cmdArgs.params[#tree], current)
        else
            cmdArgs.params[paramIndex] = cmdArgs.params[paramIndex] or {}
            table.insert(cmdArgs.params[paramIndex], current)
        end
        -- otherwise add a param to the param list
        paramIndex = newParamIndex
        repeatCount = newRepeatCount
        isParams = true
        local newPI, newRC = 0, 0
        expected, newPI, newRC = getNextParams(tree, paramIndex, repeatCount,
            cmdArgs)
        return traverseTree(tree, fargs, cmdArgs, expected, i + 1, paramIndex,
            isParams, repeatCount, newPI, newRC)
    end
end

-- Basically this function just parses the command, then does completion
function cmdTree.getComplete(tree, name, working, current, cmdOpts)
    -- Split the command by spaces
    local parts = vim.split(current, " ")
    parts = vim.tbl_filter(function (v)
        return v ~= ""
    end, parts)
    -- TODO: add support for % ranges, also add support for spaces between ranges and name

    -- The name section (along with marks)
    local nameSection = parts[1]
    local rangeOrNum = getRngOrNum(nameSection)
    local count = tonumber(rangeOrNum)
    local line1 = 1
    local line2 = 1

    if count == nil and cmdOpts.range then
        local marks = vim.split(rangeOrNum, ",")
        if #marks == 2 then
            local mark1 = marks[1]
            local mark2 = marks[2]
            line1 = vim.fn.getpos(mark1)[2] or 1
            line2 = vim.fn.getpos(mark2)[2] or 1
        end
    end
    local args = current:sub(#parts[1] + 1, -1)
    while args:sub(1, 1) == " " do
        args = args:sub(2, -1)
    end
    if count == nil and cmdOpts.count then
        count = tonumber(parts[2] or "")
        if count ~= nil then
            args = args:sub(#parts[2] + 1, -1)
            while args:sub(1, 1) == " " do
                args = args:sub(2, -1)
            end
        end
    end
    local range = line2 - line1
    local bang = nameSection:sub(#nameSection, #nameSection) == "!"
    local fargs = vim.split(args, " ")
    fargs = vim.tbl_filter(function (v)
        return v ~= ""
    end, fargs)
    local reg = ""
    if cmdOpts.register and fargs[1] ~= nil then
        reg = fargs[1]:sub(1, 1) or ""
        table.remove(fargs, 1)
    elseif cmdOpts.register then
        -- from tversteeg/registers.nvim
        local registers =
        "*+\"-/_=#%.0123456789abcdefghijklmnopqrstuvwxyz:ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        local validRegs = { " " }
        for i = 1, #registers do
            local c = registers:sub(i, i)
            local info = vim.fn.getreginfo(c)
            if info.regcontents ~= nil then
                table.insert(validRegs, c)
            end
        end

        return filterCompletion(working, validRegs)
    end
    if #fargs > 0 and current:sub(#current, #current) ~= " " then
        -- remove the last one bc, it's the one the person is currently typing
        table.remove(fargs, #fargs)
    end
    ---@type CmdTree.CmdOpts
    local cmdArgs = {
        name = name,
        fargs = fargs,
        args = args,
        bang = bang,
        line1 = line1,
        line2 = line2,
        range = range,
        count = count or 0,
        reg = reg,
        mods = {},
        smods = {},
        params = {},
    }
    -- return { "sdf" }
    local cmpl = traverseTree(tree, fargs, cmdArgs)
    return filterCompletion(working, cmpl)
end

---@param tree CmdTree.SubTree
---@param name string
---@param opts CmdTree.NvimCmdDefOpts
function cmdTree.createCmdForTree(tree, name, opts)
    opts = vim.tbl_extend("keep", {
        nargs = "*",
    }, opts)
    opts = vim.tbl_extend("keep", {
        complete = function (working, current)
            return cmdTree.getComplete(tree, name, working, current, opts)
        end,
    }, opts)

    local cmdCallback = function (cmdOpts)
        ---@cast cmdOpts CmdTree.CmdOpts
        cmdOpts.params = {}
        local _, t, callable = traverseTree(tree, cmdOpts.fargs, cmdOpts)
        if callable ~= "" then
            error(callable)
        end
        if t == nil then
            error("Invalid subcommand or parameter")
        end

        if t._callback == nil then
            error("No callback found for command " .. name)
        end
        return t._callback(cmdOpts)
    end

    if opts.buffer then
        local buf = opts.buffer
        if type(buf) == "boolean" then
            buf = vim.api.nvim_get_current_buf()
        end
        vim.api.nvim_buf_create_user_command(buf, name, cmdCallback, opts)
    else
        vim.api.nvim_create_user_command(name, cmdCallback, opts)
    end
end

---@param tree CmdTree.CmdTree
---@param opts CmdTree.NvimCmdDefOpts?
function cmdTree.createCmd(tree, opts)
    opts = opts or {}
    cmdTree.validateCmdTree(tree)
    for name, currentTree in pairs(tree) do
        cmdTree.createCmdForTree(currentTree, name, opts)
    end
end

-- }

vim.api.nvim_create_user_command("BananaSo", function (opts)
    local file
    -- vim.print(opts)
    if #opts.fargs == 0 then
        file = vim.api.nvim_buf_get_name(0)
    else
        file = opts.fargs[1]
    end
    local inst = require("banana.instance").emptyInstance()
    -- inst.DEBUG_showPerf  = true
    -- inst.DEBUG_showBuild = true
    -- inst.DEBUG_stressTest = true
    -- inst.DEBUG           = true
    require("banana.require").parseReload()
    inst:useFile(file)
    inst:setTitle("")
    inst:open()
    print("Instance id: " .. inst.instanceId)
end, {
    nargs = "*",
})

---@type Banana.Instance?
local devtoolsui = nil

cmdTree.createCmd({
    BananaDev = {
        devtools = {
            _callback = function ()
                if devtoolsui == nil then
                    devtoolsui = require("banana.instance").newInstance(
                        "devtools", "")
                end
                local buf = vim.api.nvim_get_current_buf()
                devtoolsui:loadNmlTo("devtoolsui/main?buf=" .. buf,
                    devtoolsui:body(), true, false)
                devtoolsui:open()
            end,
        },
        runBench = {
            cmdTree.requiredParams(function ()
                local installDir = require("banana").getInstallDir() ..
                    "/banana/__internal/bench"
                local benches = vim.fn.readdir(installDir)

                return benches
            end),
            _callback = function (args)
                local path = require("banana").getInstallDir() ..
                    "/banana/__internal/bench/" .. args.params[1][1]
                local inst = require("banana.instance").emptyInstance()
                require("banana.require").parseReload()
                inst:useFile(path)
                inst:open()
            end
        },
    },
})

-- vim.api.nvim_create_user_command("BananaDev", function (opts)
--     local file
--     -- vim.print(opts)
--     if #opts.fargs == 0 then
--         file = vim.api.nvim_buf_get_name(0)
--     else
--         file = opts.args[1]
--     end
--     local buftitle = "scratch"
--     local inst     = require("banana.instance").emptyInstance()
--     -- inst.DEBUG_showPerf  = true
--     -- inst.DEBUG_showBuild = true
--     -- inst.DEBUG_stressTest = true
--     -- inst.DEBUG           = true
--     require("banana.require").parseReload()
--     inst:useFile(file)
--     inst:setBufName(buftitle)
--     inst:open()
--     print("Instance id: " .. inst.instanceId)
-- end, {
--     nargs = "*",
-- })
