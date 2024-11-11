---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
---@module 'banana.nml.tag'
local t = require("banana.lazyRequire")("banana.nml.tag")
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
    local name = ast:getAttribute("name")
    if name == nil then
        -- flame.pop()
        log.throw(
            "Expected a name attribute on a meta tag")
        error("")
    end
    local value = ast:getAttribute("value")
    if value == nil then
        -- flame.pop()
        log.throw(
            "Expected a value attribute on a meta tag")
        error("")
    end
    if startsWith(name, "buf-") then
        inst.bufOpts[name:sub(#"buf-" + 1, #name)] = tonumber(value) or value
    elseif startsWith(name, "win-") then
        local newName = name:sub(#"win-" + 1, #name)
        inst.winOpts[newName] = tonumber(value) or value
    else
        -- flame.pop()
        error("Unknown option '" .. name .. "'")
    end
    local b = require("banana.box")
    ---@type Banana.Box
    local ret = b.Box:new()
    -- flame.pop()
    return ret
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
