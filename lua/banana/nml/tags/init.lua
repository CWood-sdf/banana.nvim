local M = {}
local _str = require('banana.utils.string')
local _ast = require('banana.nml.ast')

---@enum Banana.Nml.FormatType
M.FormatType = {
    Inline = 1,
    Block = 2,
    -- InlineBlock = 3,
    BlockInline = 4,
    Script = 5,
}

---@alias Banana.RenderRet Banana.Box

---@alias Banana.Renderer fun(self: Banana.TagInfo, ast: Banana.Ast, parentHl: Banana.Highlight?, parentWidth: number, parentHeight: number, startX: number, startY: number): Banana.RenderRet


---@class (exact) Banana.TagInfo
---@field name string
---@field formatType Banana.Nml.FormatType
---@field selfClosing boolean
---@field private render Banana.Renderer
local TagInfo = {
    name = '',
    formatType = M.FormatType.Inline,
    selfClosing = false,
    render = function(_) return {} end,
}

---@param ast Banana.Ast
---@param name string
---@param i number
---@param hl Banana.Highlight?
---@return Banana.Box
local function padLeftRight(ast, name, i, hl)
    local b = require('banana.box')
    local box = b.Box:new(hl);
    box:appendStr(' ', nil)
    box:expandWidthTo(ast[name][i].value)
    return box
end

---@param ast Banana.Ast
---@param name string
---@param i number
---@param hl Banana.Highlight?
---@param width number
---@return Banana.Box
local function padTopBtm(ast, name, i, hl, width)
    local b = require('banana.box')
    local box = b.Box:new(hl);
    box:appendStr(' ', nil)
    box:expandWidthTo(width)
    while #box.lines < ast[name][i].value do
        table.insert(box.lines, box.lines[1])
    end
    return box
end

---@param name string
---@param ast Banana.Ast
---@param ret Banana.Box
---@param hl Banana.Highlight?
---@return Banana.Box
local function applyPad(name, ast, ret, hl)
    local b = require('banana.box')
    if ast[name][_ast.left].value ~= 0 then
        local box = padLeftRight(ast, name, _ast.left, hl)
        box:append(ret, nil)
        ret = box
    end
    if ast[name][_ast.right].value ~= 0 then
        local box = padLeftRight(ast, name, _ast.right, hl)
        ret:append(box, nil)
    end
    if ast[name][_ast.top].value ~= 0 then
        local box = padTopBtm(ast, name, _ast.top, hl, b.lineWidth(ret.lines[1]))
        box:appendBoxBelow(ret)
        ret = box
    end
    if ast[name][_ast.bottom].value ~= 0 then
        local box = padTopBtm(ast, name, _ast.top, hl, b.lineWidth(ret.lines[1]))
        ret:appendBoxBelow(box)
    end
    return ret
end

---@param ast Banana.Ast
---@param parentHl Banana.Highlight?
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@return Banana.RenderRet
function TagInfo:getRendered(ast, parentHl, parentWidth, parentHeight, startX, startY)
    ---@type Banana.Ast.BoundingBox
    local boundBox = {
        topX    = startX,
        topY    = startY,
        bottomX = 0,
        bottomY = 0,
    }
    startX = startX + ast.padding[_ast.left].value + ast.margin[_ast.left].value
    startY = startY + ast.padding[_ast.top].value + ast.margin[_ast.top].value
    local ret = self:render(ast, parentHl, parentWidth, parentHeight, startX, startY)
    local extraWidth =
        parentWidth - ret.width -
        ast.padding[_ast.left].value - ast.padding[_ast.right].value -
        ast.margin[_ast.left].value - ast.margin[_ast.right].value
    if (ast.actualTag.formatType == M.FormatType.Block or ast.actualTag.formatType == M.FormatType.BlockInline) and extraWidth > 0
    then
        ret:clean()
        ret:appendStr(string.rep(' ', extraWidth))
    end
    ret = applyPad('padding', ast, ret, ret.hlgroup)
    ret = applyPad('margin', ast, ret, parentHl)
    boundBox.bottomX = boundBox.topX + ret.width
    boundBox.bottomY = boundBox.topY + #ret.lines
    ast.boundBox = boundBox
    return ret
end

---Returns an iterator that renders blocks
---@param ast  Banana.Ast
---@param parentHl Banana.Highlight?
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@return fun(): integer?, Banana.Box?, integer?
function TagInfo:blockIter(ast, parentHl, parentWidth, parentHeight, startX, startY)
    local i = 1
    return function()
        if i > #ast.nodes then
            return nil
        end
        local oldI = i
        local render = nil
        render, i = self:renderBlock(ast, parentHl, i, parentWidth, parentHeight, startX, startY)
        startY = startY + #render.lines
        return oldI, render, i - oldI
    end
end

---@param ast Banana.Ast
---@param parentHl Banana.Highlight?
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@return Banana.Box
function TagInfo:renderInlineEl(ast, parentHl, parentWidth, parentHeight, startX, startY)
    ---@type Banana.Box
    local ret, _ = self:renderBlock(ast, ast:mixHl(parentHl), 1, parentWidth, parentHeight, startX, startY)
    return ret
end

---Renders everything in a block
---@param ast Banana.Ast
---@param parentHl Banana.Highlight?
---@param i integer
---@param parentWidth number
---@param parentHeight number
---@param startX number
---@param startY number
---@return Banana.Box, integer
function TagInfo:renderBlock(ast, parentHl, i, parentWidth, parentHeight, startX, startY)
    local b = require('banana.box')
    local currentLine = b.Box:new(parentHl)
    local hasText = false
    local width = parentWidth - ast.padding[_ast.left].value - ast.padding[_ast.right].value -
        ast.margin[_ast.left].value - ast.margin[_ast.right].value
    local height = parentHeight - ast.padding[_ast.top].value - ast.padding[_ast.bottom].value -
        ast.margin[_ast.top].value - ast.margin[_ast.bottom].value
    while i <= #ast.nodes do
        local v = ast.nodes[i]
        if v == nil then
            break
        end
        if type(v) == 'string' then
            currentLine:appendStr(v, b.MergeStrategy.Bottom)
            startX = startX + _str.charCount(v)
            hasText = true
        else
            local tag = M.makeTag(v.tag)
            if (tag.formatType == M.FormatType.Block or tag.formatType == M.FormatType.BlockInline) and hasText then
                break
            end
            v:resolveUnits(width, height)
            local rendered = tag:getRendered(v, currentLine.hlgroup, width, height, startX, startY)
            startX = startX + rendered.width
            currentLine:append(rendered, b.MergeStrategy.Bottom)
            if tag.formatType == M.FormatType.Block or tag.formatType == M.FormatType.BlockInline then
                i = i + 1
                break
            end

            hasText = true
        end
        i = i + 1
    end
    -- if currentLine.width < width - 2 then
    --     currentLine:expandWidthTo(width - 3)
    -- end
    return currentLine, i
end

---@param name string
---@param inline Banana.Nml.FormatType
---@param selfClosing boolean
---@param renderer Banana.Renderer
function M.newTag(name, inline, selfClosing, renderer)
    ---@type Banana.TagInfo
    local tag = {
        name = name,
        formatType = inline,
        selfClosing = selfClosing,
        render = renderer
    }
    setmetatable(tag, { __index = TagInfo })
    return tag
end

---@param name string
---@return boolean
function M.tagExists(name)
    return pcall(require, 'banana.nml.tags.' .. name)
end

---@param ast Banana.Ast|string
---@return string
function M.firstChar(ast)
    if type(ast) == 'string' then
        if string.len(ast) > 0 then
            return string.sub(ast, 1, 1)
        end
        return ''
    end
    if ast.nodes[1] == nil then
        return ''
    end
    ---@cast ast Banana.Ast
    local i = 1
    while M.firstChar(ast.nodes[i]) == '' do
        i = i + 1
        if i > #ast.nodes then
            return ''
        end
    end
    return M.firstChar(ast.nodes[i])
end

---@return Banana.TagInfo
---@param name string
function M.makeTag(name)
    local ok, mgr = pcall(require, 'banana.nml.tags.' .. name)
    if not ok then
        error("Error while trying to load tag '" .. name .. "'")
    end
    return mgr
end

---@param str string
---@param clearFirst boolean
---@param clearLast boolean
---@return string, boolean
local function formatInlineText(str, clearFirst, clearLast)
    str = str:gsub('%s+', ' ')
    if clearFirst and str:sub(1, 1) == ' ' then
        str = str:sub(2, #str)
    end
    local lastChar = str:sub(#str, #str)
    if clearLast and lastChar == ' ' then
        str = str:sub(1, #str - 1)
    end
    lastChar = str:sub(#str, #str)
    clearFirst = lastChar == ' '
    return str, clearFirst
end

---Reference for this function:
--https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_display/Block_formatting_context
---@param ast Banana.Ast
function M.formatBlockContext(ast)
    local i = 1
    local inc = true
    local clearFirst = true
    while i <= #ast.nodes do
        local node = ast.nodes[i]
        if type(node) == 'string' then
            local nextNode = ast.nodes[i + 1]
            local clearLast = true
            if
                nextNode ~= nil
                and type(nextNode) ~= "string"
                and nextNode.actualTag.formatType == M.FormatType.Inline

            then
                clearLast = false
            end
            ---@cast node string
            node, clearFirst = formatInlineText(node, clearFirst, clearLast)
            if node == "" then
                table.remove(ast.nodes, i)
                inc = false
            else
                ast.nodes[i] = node
            end
        else
            ---@cast node Banana.Ast
            if node.actualTag.formatType == M.FormatType.Block then
                M.formatBlockContext(node)
            elseif node.actualTag.formatType == M.FormatType.BlockInline then
                M.formatInlineContext(node, true, true)
            elseif node.actualTag.formatType == M.FormatType.Inline then
                local clearLast = false
                local nextNode = ast.nodes[i + 1]
                if
                    nextNode ~= nil
                    and type(nextNode) ~= "string"
                    and (
                        nextNode.actualTag.formatType == M.FormatType.Block
                        or nextNode.actualTag.formatType == M.FormatType.BlockInline
                    )
                then
                    clearLast = true
                end
                clearFirst = M.formatInlineContext(node, clearFirst, clearLast)
            end
        end
        if inc then
            i = i + 1
        end
        inc = true
    end
end

---Reference:
---https://developer.mozilla.org/en-US/docs/Web/API/Document_Object_Model/Whitespace
---https://developer.mozilla.org/en-US/docs/Web/CSS/Inline_formatting_context
---@param ast Banana.Ast
---@param clearFirst boolean
---@param clearLast boolean
---@return boolean
function M.formatInlineContext(ast, clearFirst, clearLast)
    local i = 1
    local inc = true
    while i <= #ast.nodes do
        local node = ast.nodes[i]
        local last = i == #ast.nodes
        if type(node) == 'string' then
            node, clearFirst = formatInlineText(node, clearFirst, clearLast and last)
            if node == "" then
                table.remove(ast.nodes, i)
                inc = false
            else
                ast.nodes[i] = node
            end
        else
            ---@cast node Banana.Ast
            if node.actualTag.formatType == M.FormatType.Block or node.actualTag.formatType == M.FormatType.BlockInline then
                error("A Block or BlockInline format type element is nested in an inline formatting context")
            end
            if node.actualTag.formatType == M.FormatType.Inline then
                clearFirst = M.formatInlineContext(node, clearFirst, clearLast and last)
            end
        end
        if inc then
            i = i + 1
        end
        inc = true
    end
    return clearFirst
end

---@param ast Banana.Ast
--- Removes all empty text nodes, and cleans up all whitespace.
function M.cleanAst(ast)
    if ast.actualTag.formatType == M.FormatType.Block then
        M.formatBlockContext(ast)
    elseif ast.actualTag.formatType == M.FormatType.Inline then
        M.formatInlineContext(ast, false, false)
    elseif ast.actualTag.formatType == M.FormatType.BlockInline then
        M.formatInlineContext(ast, true, true)
    elseif ast.actualTag.formatType == M.FormatType.Script then
    else
        error("Unreachable")
    end
end

return M
