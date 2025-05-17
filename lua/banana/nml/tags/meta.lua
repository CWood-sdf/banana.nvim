---@module 'banana.utils.debug_flame'
local flame = require("banana.utils.debug_flame")
---@module 'banana.utils.log'
local log = require("banana.utils.log")
---@module 'banana.nml.tag'
local t = require("banana.nml.tag")
---@param str string
---@param other string
---@return boolean
local function startsWith(str, other)
    return str:sub(1, #other) == other
end

---@type Banana.Renderer
local function renderer(_, ast)
    -- flame.new("tag:meta")
    local inst = require("banana.instance").getInstance(ast.instance)
    local name, value = nil, nil
    for k, val in pairs(ast.attributes) do
        if name ~= nil then
            name = nil
            value = nil
            break
        end
        name = k
        value = val
    end
    if name == nil then
        name = ast:getAttribute("name")
        if name == nil then
            log.warn("Expected a name attribute on a meta tag")
            return
        end
        value = ast:getAttribute("value")
        if value == nil then
            log.warn("Expected a value attribute on a meta tag")
            return
        end
    end
    if value == "true" or value == "false" then
        value = value == "true"
    end
    if tonumber(value) ~= nil then
        value = tonumber(value)
    end
    if inst == nil then
        log.warn("Instance is undefined in meta tag")
        return
    end
    if startsWith(name, "buf-") then
        inst.bufOpts[name:sub(#"buf-" + 1, #name)] = tonumber(value) or value
    elseif startsWith(name, "win-") then
        local newName = name:sub(#"win-" + 1, #name)
        inst.winOpts[newName] = tonumber(value) or value
    elseif startsWith(name, "DEBUG") then
        inst[name] = value
    else
        log.warn("Unknown option meta tag option '" .. name .. "'")
    end
    -- flame.pop()
end
---@type Banana.TagInfo
local M = t.newTag(
    "meta",
    t.FormatType.Inline,
    true,
    renderer,
    require("banana.nml.tag").defaultInitials()
)

return M
