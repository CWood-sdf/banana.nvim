local t = require('banana.nml.tags')
---@param str string
---@param other string
---@return boolean
local function startsWith(str, other)
    return str:sub(1, #other) == other
end

---@type Banana.Renderer
local function renderer(_, ast)
    local inst = require('banana.render').getInstance(ast.instance)
    local name = ast:getAttribute("name")
    assert(name ~= nil,
        "Expected a name attribute on a meta tag")
    local value = ast:getAttribute("value")
    assert(value ~= nil,
        "Expected a value attribute on a meta tag")
    if startsWith(name, "buf-") then
        inst.bufOpts[name:sub(#"buf-" + 1, #name)] = tonumber(value) or value
    elseif startsWith(name, "win-") then
        local newName = name:sub(#"win-" + 1, #name)
        inst.winOpts[newName] = tonumber(value) or value
    else
        error("Unknown option '" .. name .. "'")
    end
    local b = require('banana.box')
    ---@type Banana.Box
    local ret = b.Box:new()
    return ret
end
---@type Banana.TagInfo
local M = t.newTag(
    'meta',
    t.FormatType.Inline,
    true,
    renderer,
    require('banana.nml.tags').defaultInitials()
)

return M
