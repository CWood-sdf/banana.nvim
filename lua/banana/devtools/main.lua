---comment
---@param document Banana.Instance
---@param elTo Banana.Ast
---@param name Banana.Ast
---@param left string
---@param right string
local function astHeader(document, elTo, name, left, right)
    local open = document:createElement("span")
    open:addClass("delimeter")
    open:setTextContent(left)
    elTo:appendChild(open)

    local nameel = document:createElement("span")
    nameel:addClass("name")
    nameel:setTextContent(name.tag)
    elTo:appendChild(nameel)

    if left ~= "</" then
        local idel = document:createElement("span")
        idel:setTextContent(" " .. name._astId)
        elTo:appendChild(idel)
    end

    local close = document:createElement("span")
    close:addClass("delimeter")
    close:setTextContent(right)
    elTo:appendChild(close)
end

local extmarks = {}

---comment
---@param buf number
---@param ast Banana.Ast
---@param fromInst Banana.Instance
local function highlightElement(buf, ast, fromInst)
    local ns = fromInst.highlightNs

    local bound = {
        topRow = ast.boundBox.topY - 1,
        bottomRow = ast.boundBox.bottomY - 2,
        leftCol = ast.boundBox.leftX - 1,
        rightCol = ast.boundBox.rightX - 1,
    }

    vim.api.nvim_set_hl(ns, "devtools_bg", {
        link = "Visual",
    })
    local i = 1
    for line = bound.topRow, bound.bottomRow do
        extmarks[i] = vim.api.nvim_buf_set_extmark(buf, ns, line,
            bound.leftCol, {
                hl_mode = "combine",
                strict = false,
                id = extmarks[i],
                hl_group = "devtools_bg",
                end_col = bound.rightCol,
            })
        i = i + 1
    end
    while i <= #extmarks do
        vim.api.nvim_buf_del_extmark(buf, ns, extmarks[i])
        i = i + 1
    end
end

---comment
---@param ast Banana.Ast
---@param el Banana.Ast
---@param before Banana.Ast?
local function appendEl(ast, el, before)
    if before ~= nil then
        ast:insertBefore(el, before)
    else
        ast:appendChild(el)
    end
end

---idk
---@param document Banana.Instance
---@param addingTo Banana.Ast
---@param ast Banana.Ast
---@param fromInst Banana.Instance
---@param before Banana.Ast?
local function drawAsts(document, addingTo, ast, fromInst, before)
    local opening = document:createElement("div")
    opening:attachRemap("n", "<CR>", { "line-hover" }, function ()
        highlightElement(fromInst.bufnr, ast, fromInst)
    end, {})
    opening:setAttribute("astid", ast._astId .. "")
    appendEl(addingTo, opening, before)
    if ast.actualTag.selfClosing then
        astHeader(document, opening, ast, "<", "/>")
        return
    end
    astHeader(document, opening, ast, "<", ">")
    local content = document:createElement("div")
    content:addClass("astbody")
    for _, v in ipairs(ast.nodes) do
        if type(v) == "string" then
            local text = document:createElement("div")
            text:setTextContent(v)
            content:appendChild(text)
        else
            drawAsts(document, content, v, fromInst)
        end
    end

    appendEl(addingTo, content, before)

    local closing = document:createElement("div")
    astHeader(document, closing, ast, "</", ">")
    appendEl(addingTo, closing, before)
    closing:setAttribute("astid", ast._astId .. "")
end

---@param document Banana.Instance
return function (document)
    local id = tonumber(document:getScriptParams().params.id) or 0
    local instance = require("banana.instance").getInstance(id)
    if instance == nil then
        vim.notify("Could not find instance :(")
        return
    end

    local root = document:getElementById("root")

    -- local t = document:createElement("Tag")
    -- t:setData("ast", instance:body())
    -- root:appendChild(t)

    local start = vim.uv.hrtime()
    drawAsts(document, root, instance:body(), instance)

    instance:on("RenderDone", {
        callback = function ()
            root:removeChildren()
            drawAsts(document, root, instance:body(), instance)
        end,
    })

    print("Took " .. ((vim.uv.hrtime() - start) / 1e6) .. "ms")
end
