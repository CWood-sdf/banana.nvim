---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
local M = {}
---@module 'banana.nml.tag'
local tags = require("banana.lazyRequire")("banana.nml.tag")

---@param str string
---@param clearFirst boolean
---@param clearLast boolean
---@return string, boolean
local function formatInlineText(str, clearFirst, clearLast)
    str = str:gsub("%s+", " ")
    if clearFirst and str:sub(1, 1) == " " then
        str = str:sub(2, #str)
    end
    local lastChar = str:sub(#str, #str)
    if clearLast and lastChar == " " then
        str = str:sub(1, #str - 1)
    end
    lastChar = str:sub(#str, #str)
    clearFirst = lastChar == " "
    return str, clearFirst
end

---Reference for this function:
---https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_display/Block_formatting_context
---@param ast Banana.Ast
function M.formatBlockContext(ast)
    local i = 1
    local inc = true
    local clearFirst = true
    local skip = ast.tag == "pre" or ast.tag == "slot"
    while i <= #ast.nodes do
        local node = ast.nodes[i]
        if type(node) == "string" then
            local nextNode = ast.nodes[i + 1]
            local clearLast = true
            if
                nextNode ~= nil
                and type(nextNode) ~= "string"
                and nextNode.actualTag.formatType == tags.FormatType.Inline

            then
                clearLast = false
            end
            ---@cast node string
            if not skip then
                node, clearFirst = formatInlineText(node, clearFirst, clearLast)
            else
                -- split the node by newlines
                local reps = vim.fn.split(node, "\n")
                if #reps ~= 1 then
                    table.remove(ast.nodes, i)
                    for j = #reps, 1, -1 do
                        table.insert(ast.nodes, i, reps[j])
                    end
                end
            end
            if node == "" then
                table.remove(ast.nodes, i)
                inc = false
            else
                ast.nodes[i] = node
            end
        else
            ---@cast node Banana.Ast
            if node.actualTag.formatType == tags.FormatType.Block then
                M.formatBlockContext(node)
                clearFirst = true
            elseif node.actualTag.formatType == tags.FormatType.BlockInline then
                M.formatInlineContext(node, true, true)
                clearFirst = true
            elseif node.actualTag.formatType == tags.FormatType.Inline then
                local clearLast = false
                local nextNode = ast.nodes[i + 1]
                if
                    nextNode ~= nil
                    and type(nextNode) ~= "string"
                    and (
                        nextNode.actualTag.formatType == tags.FormatType.Block
                        or nextNode.actualTag.formatType == tags.FormatType.BlockInline
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
        if type(node) == "string" then
            node, clearFirst = formatInlineText(node, clearFirst,
                clearLast and last)
            if node == "" then
                table.remove(ast.nodes, i)
                inc = false
            else
                ast.nodes[i] = node
            end
        else
            ---@cast node Banana.Ast
            if node.actualTag.formatType == tags.FormatType.Block then
                log.throw(
                    "A Block or BlockInline format type element is nested in an inline formatting context")
                error("")
            end
            if node.actualTag.formatType == tags.FormatType.BlockInline then
                log.throw(
                    "A Block or BlockInline format type element is nested in an inline formatting context")
                error("")
            end
            clearFirst = M.formatInlineContext(node, clearFirst,
                clearLast and last)
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
    if ast.tag == "pre" then
        return
    end
    if ast.actualTag.formatType == tags.FormatType.Block then
        M.formatBlockContext(ast)
    elseif ast.actualTag.formatType == tags.FormatType.Inline then
        M.formatInlineContext(ast, false, false)
    elseif ast.actualTag.formatType == tags.FormatType.BlockInline then
        M.formatInlineContext(ast, true, true)
    elseif ast.actualTag.formatType == tags.FormatType.Script then
    else
        error("Unreachable")
    end
end

return M
