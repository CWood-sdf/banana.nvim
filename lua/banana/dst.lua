-- A Deterministic Simulation Testing series for the zig implementation
--
-- This (as of now) will not check the validity of data, just that we can
-- scream at the system and it survives without crashing
local M = {}

local lb = require("banana.libbanana")

---@return boolean
local function runFunction(name, params)
    local ok, _ = pcall(function ()
        lb[name](unpack(params))
    end)
    return ok
end

function M.new(outFileName)
    local jsonFileName = "zig/dst_decls.json"
    local jsonFile = io.open(jsonFileName, "r")

    if jsonFile == nil then
        error("Could not open json file " .. jsonFileName)
    end

    local jsonStr = jsonFile:read("*a")
    jsonFile:close()

    -- ---@alias param [string, string]
    -- ---@alias ret [string]
    --
    -- ---@class fn
    -- ---@field params (param|ret)[]
    -- ---@field name string


    ---@type fn[]
    local json = vim.json.decode(jsonStr)

    local dst = lb.dst_init()


    local fnames = {}
    ---@type param[]
    local fparams = {}

    for _, fn in ipairs(json) do
        local name = fn.name
        local params = {}
        if name == "box_context_render" then
            goto continue
        end

        lb.dst_new_function(dst, name)
        for _, param in ipairs(fn.params) do
            if #param == 2 then
                -- if param[2] == "string" then
                --     goto continue
                -- end
                if not lb.dst_add_param(dst, param[2]) then
                    -- print("Failed to add param " .. param[2])
                    goto continue
                end
                table.insert(params, param)
            end
        end
        table.insert(fparams, params)
        table.insert(fnames, name)
        lb.dst_push_function(dst)
        ::continue::
    end

    lb.dst_init_random(dst)
    lb.box_context_delete_all()

    local fnCount = 100000 -- lb.dst_get_function_count(dst)

    local outFile = io.open(outFileName, "w")

    if outFile == nil then
        error("Sad couldnt open dst.lua :(")
    end

    outFile:write([[
local lb = require('banana.libbanana')
---@return boolean
local function runFunction(name, params)
    local ok, _ = pcall(function ()
        lb[name](unpack(params))
    end)
    return ok
end
    ]])

    local paramTypes = {
        none = 0,
        string = 1,
        i16 = 2,
        u16 = 3,
        u8 = 4,
    }



    -- print("Creating dst with " .. fnCount .. " fns")
    for _ = 0, fnCount - 1 do
        local fn = lb.dst_get_next_function(dst)
        local params = lb.dst_get_param_count(dst)
        -- local name = lb.dst_get_function_name(dst, fn)
        local ok = false
        local iters = 0
        while not ok and iters < 1 do
            outFile:write("runFunction('" .. fnames[fn + 1] .. "', {")
            outFile:flush()

            local callParams = {}

            iters = iters + 1
            for p = 0, params - 1 do
                local tp = lb.dst_get_param_type(dst, p)
                if tp == paramTypes.none then
                    error("Got none parameter :(")
                end
                if tp == paramTypes.u16 then
                    local value = lb.dst_get_u16_param(dst)
                    outFile:write("" .. value)
                    table.insert(callParams, value)
                elseif tp == paramTypes.i16 then
                    local value = lb.dst_get_i16_param(dst)
                    outFile:write("" .. value)
                    table.insert(callParams, value)
                elseif tp == paramTypes.u8 then
                    local value = lb.dst_get_u8_param(dst)
                    outFile:write("" .. value)
                    table.insert(callParams, value)
                elseif tp == paramTypes.string then
                    ---@type string
                    local value = lb.dst_get_string_param(dst)
                    local replaced = value:gsub("\\", "\\\\")
                    replaced = replaced:gsub("'", "\\'")
                    replaced = replaced:gsub("\n", "\\n")
                    outFile:write("'" .. replaced .. "'")
                    table.insert(callParams, replaced)
                else
                    error("Unkown parameter type " .. tp)
                end
                if p ~= params - 1 then
                    outFile:write(", ")
                end
            end
            outFile:write("})")
            -- outFile:write(fnames[fn + 1] .. "   ")
            -- outFile:write(vim.inspect(callParams))
            outFile:flush()

            ok = runFunction(fnames[fn + 1], callParams)
            if ok then
                outFile:write(" --ok")
            end
            outFile:write("\n")
        end
    end
    outFile:close()
end

function M.spam()
    -- local jobs = {}
    local count = 1000
    local countDone = 0
    local dir = 0
    while vim.fn.filereadable("lua/banana/bench/dst/" .. dir .. "/0.lua") == 1 do
        dir = dir + 1
        if dir > 10 then
            error("ooga")
        end
    end
    for i = 0, count do
        local name = "lua/banana/bench/dst/" .. dir .. "/" .. i .. ".lua"
        if vim.fn.filereadable(name) == 1 then
            goto continue
        end
        M.new(name)
        countDone = countDone + 1
        ::continue::
    end
    if countDone >= count then
        print("DONE")
    end
end

return M
