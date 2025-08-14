---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
-- ---@module 'banana.utils.string'
-- local _str = require("banana.lazyRequire")("banana.utils.string")
---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
-- ---@module 'banana.box'
-- local b = require("banana.lazyRequire")("banana.box")
---@module 'banana.nml.tag'
local _tag = require("banana.lazyRequire")("banana.nml.tag")

---@module 'banana.nml.entity'
local entity = require("banana.lazyRequire")("banana.nml.entity")

---Renders everything in a block
---@param ast Banana.Ast
---@param box Banana.Box
---@param parentHl Banana.Highlight?
---@param i integer
---@param inherit Banana.Renderer.InheritedProperties
---@param extra_ Banana.Renderer.ExtraInfo
---@return integer
return function (ast, box, parentHl, i, inherit, extra_)
    log.trace("TagInfo:renderBlock " .. ast.tag)
    flame.new("renderBlock")
    -- local currentLine = b.Box:new(parentHl)
    local hasElements = false
    local lineHeight = 0
    local width = box:getMaxWidth()
    local height = box:getMaxHeight()
    while i <= #ast.nodes do
        log.trace("TagInfo: renderBlock loop " .. i)
        local v = ast.nodes[i]
        if v == nil then
            break
        end
        if v == "" then
        elseif type(v) == "string" then
            if v:sub(1, 1) == "&" then
                if v:sub(#v, #v) ~= ";" then
                    v = v .. ";"
                end
                local en = v
                v = entity[v]
                if en:sub(2, 2) == "#" then
                    local num = tonumber(en:sub(3, #en - 1))
                    if num == nil then
                        error("Expected valid number for numerical entity")
                    end
                    v = string.char(num)
                elseif v == nil then
                    log.throw("Unknown entity: " .. en)
                    error("")
                end
            elseif v:sub(1, 1) == "%" then
                if v:sub(2, 2) == "%" then
                    v = "%"
                else
                    v = ast:getAttributeSubstitution(v:sub(2, #v)) or ""
                end
            end
            -- local count = _str.charWidth(v)
            -- local box = b.Box:new(parentHl)
            box:appendStr(v)
            lineHeight = 1
            hasElements = true
        else
            local tag = v.actualTag
            local isBlock = tag.formatType == _tag.FormatType.Block or
                tag.formatType == _tag.FormatType.BlockInline
            if isBlock and hasElements then
                break
            end
            v:_resolveUnits(width, height)
            flame.new("renderBlock:tag.getRendered")
            local rendered = tag:getRendered(v, box, parentHl, inherit, extra_)
            flame.pop()

            lineHeight = rendered:render(lineHeight)

            if tag.formatType == _tag.FormatType.Block or tag.formatType == _tag.FormatType.BlockInline then
                i = i + 1
                break
            end

            hasElements = true
        end
        i = i + 1
    end
    -- if extra ~= nil then
    --     extra:appendBoxBelow(currentLine, false)
    --     currentLine = extra
    -- end
    flame.pop()
    return i
end
