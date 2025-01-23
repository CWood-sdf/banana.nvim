---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")
---@module 'banana.utils.string'
local _str = require("banana.lazyRequire")("banana.utils.string")
---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
---@module 'banana.box'
local b = require("banana.lazyRequire")("banana.box")
---@module 'banana.nml.tag'
local _tag = require("banana.lazyRequire")("banana.nml.tag")

---@module 'banana.nml.entity'
local entity = require("banana.lazyRequire")("banana.nml.entity")

---@param targetWidth number
---@param box Banana.Box
---@param hl Banana.Highlight?
---@return Banana.Box, Banana.Box
local function splitLineBoxOnce(targetWidth, box, hl)
    -- flame.new("splitLineBoxOnce")
    if targetWidth < 1 then
        targetWidth = 1
    end
    if box:width() <= targetWidth then
        -- flame.pop()
        return box, b.Box:new(hl)
    end
    -- if targetWidth == 0 then
    --     targetWidth = 1
    -- end
    local left = b.Box:new(hl)
    left:appendStr("", nil)
    local right = b.Box:new(hl)
    right:appendStr("", nil)
    local i = 1
    while left:width() + _str.charWidth(box:getLine(1)[i].word) < targetWidth do
        local w = box:getLine(1)[i]
        left:appendWord(w.word, w.style)
        i = i + 1
    end
    local word = box:getLine(1)[i]
    local leftIns = _str.sub(word.word, 1, targetWidth - left:width())
    --Allow unsafe #word.word, bc #word.word is always >= str.charWidth(word.word)
    --so since we are just reading to end of string
    local rightIns = _str.sub(word.word, targetWidth - left:width() + 1,
        #word.word)
    left:appendWord(
        leftIns,
        word.style,
        nil)
    right:appendWord(
        rightIns,
        word.style,
        nil)
    i = i + 1
    while i <= #box:getLine(1) do
        local w = box:getLine(1)[i]
        right:appendWord(w.word, w.style)
        i = i + 1
    end
    -- flame.pop()
    return left, right
end
---@param ast Banana.Ast|string
---@return boolean
local function breakable(ast)
    if type(ast) == "string" then
        return true
    end
    return ast:paddingRight() == 0 and ast:paddingLeft() == 0 and
        not ast:hasStyle("width")
end


---@param ast Banana.Ast
---@param i number
---@param currentLine Banana.Box
---@param append Banana.Box
---@param maxWidth number
---@param hl Banana.Highlight?
---@return Banana.Box, Banana.Box?
local function handleOverflow(ast, i, currentLine, append, maxWidth, hl)
    maxWidth = math.max(1, maxWidth)
    -- flame.new("handleOverflow")
    -- if currentLine:height() == 0 then
    --     currentLine:appendStr("", nil)
    -- end
    if currentLine:width() + append:width() <= maxWidth then
        currentLine:append(append, nil)
        -- flame.pop()
        return currentLine, nil
    end
    if append:height() ~= 1 or not breakable(ast.nodes[i]) then
        -- flame.pop()
        return currentLine, append
    end
    if currentLine:height() > 1 then
        local ap, extra = splitLineBoxOnce(maxWidth - currentLine:width(), append,
            hl)
        currentLine:append(ap, nil)
        -- flame.pop()
        return currentLine, extra
    end
    currentLine:append(append, nil)
    local preStuff = b.Box:new(hl)
    local extra = nil
    repeat
        currentLine, extra = splitLineBoxOnce(maxWidth, currentLine, hl)
        preStuff:appendBoxBelow(currentLine, false)
        currentLine = extra
    until extra:width() <= maxWidth
    -- flame.pop()
    return preStuff, extra
end
---Renders everything in a block
---@param ast Banana.Ast
---@param parentHl Banana.Highlight?
---@param i integer
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@param inherit Banana.Renderer.InheritedProperties
---@param extra_ Banana.Renderer.ExtraInfo
---@return Banana.Box, integer
return function (ast, parentHl, i, parentWidth, parentHeight, startX, startY,
                 inherit, extra_)
    log.trace("TagInfo:renderBlock " .. ast.tag)
    flame.new("renderBlock")
    local currentLine = b.Box:new(parentHl)
    local hasElements = false
    local width = parentWidth
    local height = parentHeight
    ---@type Banana.Box?
    local extra = nil
    local startI = i
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
                if v == nil then
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
            local count = _str.charWidth(v)
            local box = b.Box:new(parentHl)
            box:appendStr(v, nil)
            local overflow = nil
            currentLine, overflow = handleOverflow(ast, i, currentLine, box,
                width, parentHl)
            if overflow ~= nil then
                if extra == nil then
                    extra = currentLine
                else
                    if extra:width() < currentLine:width() then
                        extra:expandWidthTo(currentLine:width())
                    end
                    if currentLine:width() < extra:width() then
                        currentLine:expandWidthTo(extra:width())
                    end
                    extra:appendBoxBelow(currentLine, false)
                end
                currentLine = overflow
            end
            startX = startX + count
            hasElements = true
        else
            local tag = v.actualTag
            if (tag.formatType == _tag.FormatType.Block or tag.formatType == _tag.FormatType.BlockInline) and hasElements then
                break
            end
            v:_resolveUnits(width, height)
            local rendered = tag:getRendered(v, parentHl, width, height, startX,
                startY, inherit, extra_):render()
            startX = startX + rendered:width()
            local overflow = nil
            local orgLines = currentLine:height()
            currentLine, overflow = handleOverflow(ast, i, currentLine, rendered,
                width, parentHl)
            if rendered:height() > orgLines and overflow == nil then
                local yInc = rendered:height() - orgLines
                local currentI = startI
                while currentI < i do
                    local node = ast.nodes[currentI]
                    if type(node) == "string" then
                        goto continue
                    end
                    node:_increaseTopBound(yInc)
                    ::continue::
                    currentI = currentI + 1
                end
            end
            if overflow ~= nil then
                if extra == nil then
                    extra = currentLine
                else
                    extra:appendBoxBelow(currentLine, false)
                end
                currentLine = overflow
            end

            if tag.formatType == _tag.FormatType.Block or tag.formatType == _tag.FormatType.BlockInline then
                i = i + 1
                break
            end

            hasElements = true
        end
        i = i + 1
    end
    if extra ~= nil then
        extra:appendBoxBelow(currentLine, false)
        currentLine = extra
    end
    flame.pop()
    return currentLine, i
end
