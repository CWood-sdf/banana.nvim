local _str = require('banana.utils.string')
-- This file is for turning a BananaAst into a renderable highlight/line array.

local M = {}

local ids = 0

---@alias Banana.Line Banana.Word[]


---@class (exact) Banana.Instance
---@field winid? number
---@field bufnr? number
---@field bufname string
---@field filetype string
---@field bufName string
---@field parser Banana.Parser
---@field highlightNs number
---@field instanceId number
---@field winhl table
local Instance = {}

---@class (exact) Banana.Word
---@field word string
---@field style? Banana.Highlight

---@param ast Banana.Ast
---@param width number
---@param height number
---@return Banana.Line[]
function Instance:virtualRender(ast, width, height)
    ---@type Banana.Line[]
    local ret = {}
    if require("banana.nml.tags").tagExists(ast.tag) then
        local tag = require("banana.nml.tags").makeTag(ast.tag)
        local rendered = tag:getRendered(ast, nil, width, height, width)
        for _, line in ipairs(rendered.lines) do
            table.insert(ret, line)
        end
    end
    return ret
end

---@return Banana.Instance
function Instance:new(filename, bufferName)
    local parser = require("banana.nml.parser").fromFile(filename)
    if parser == nil then
        error("Failed to open nml file")
    end
    ---@type Banana.Instance
    local inst = {
        bufname = bufferName,
        filetype = "banana",
        bufName = filename,
        highlightNs = vim.api.nvim_create_namespace("banana_instance_" .. ids),
        parser = parser,
        instanceId = ids,
        winhl = {
            link = "NormalFloat"
        },
    }
    ids = ids + 1
    local instance = setmetatable(inst, { __index = Instance })
    vim.api.nvim_set_hl(inst.highlightNs, M.defaultWinHighlight, inst.winhl)
    return instance
end

function Instance:useBuffer(bufnr)
    self.bufnr = bufnr
end

function Instance:useWindow(winid)
    self.winid = winid
end

---@return Banana.Ast
function Instance:render()
    local startTime = vim.loop.hrtime()
    local actualStart = startTime
    local ast = self.parser:parse()
    local astTime = vim.loop.hrtime() - startTime
    if ast == nil then
        error("Failed to parse")
    end
    startTime = vim.loop.hrtime()
    require("banana.nml.tags").cleanAst(ast)
    local rules = self.parser.styleSets
    for _, v in ipairs(rules) do
        if v.query == nil then
            goto continue
        end
        local arr = v.query:find(ast)
        for _, a in ipairs(arr) do
            a:applyStyleDeclarations(v.declarations, v.query.specificity)
        end

        ::continue::
    end
    local styleTime = vim.loop.hrtime() - startTime
    startTime = vim.loop.hrtime()
    local width = 90
    local height = 20
    local stuffToRender = self:virtualRender(ast, width, height)
    local renderTime = vim.loop.hrtime() - startTime
    if self.bufnr == nil or not vim.api.nvim_buf_is_valid(self.bufnr) then
        self.bufnr = vim.api.nvim_create_buf(false, true)
        vim.api.nvim_buf_set_name(self.bufnr, self.bufname)
        vim.api.nvim_set_option_value("filetype", self.filetype, { buf = self.bufnr })
    end
    if self.winid == nil or not vim.api.nvim_win_is_valid(self.winid) then
        self.winid = vim.api.nvim_open_win(self.bufnr, true, {
            relative = "editor",
            width = width,
            height = height,
            row = 5,
            col = 5,
            style = "minimal",
            -- zindex = 1000,
        })
        vim.api.nvim_set_current_win(self.winid)
        vim.api.nvim_win_set_buf(self.winid, self.bufnr)
        vim.api.nvim_set_option_value("signcolumn", "no", { win = self.winid })
    end
    local lines = {
        -- astTime / 1e3 .. "μs to parse",
        -- renderTime / 1e3 .. "μs to render",
    }
    startTime = vim.loop.hrtime()
    for _, line in ipairs(stuffToRender) do
        local lineStr = ""
        for _, word in ipairs(line) do
            lineStr = lineStr .. word.word
        end
        table.insert(lines, lineStr)
    end
    local reductionTime = vim.loop.hrtime() - startTime
    vim.api.nvim_set_option_value("modifiable", true, {
        buf = self.bufnr
    })
    vim.api.nvim_set_option_value("buftype", "nofile", {
        buf = self.bufnr
    })
    vim.api.nvim_buf_set_lines(self.bufnr, 0, -1, false, lines)
    startTime = vim.loop.hrtime()
    self:highlight(stuffToRender, 0)
    local hlTime = vim.loop.hrtime() - startTime
    local totalTime = vim.loop.hrtime() - actualStart
    local extraLines = {
        "",
        astTime / 1e3 .. "μs to parse",
        styleTime / 1e3 .. "μs to style",
        renderTime / 1e3 .. "μs to render",
        reductionTime / 1e3 .. "μs to reduce",
        hlTime / 1e3 .. "μs to highlight",
        totalTime / 1e3 .. "μs total",
    }
    vim.api.nvim_buf_set_lines(self.bufnr, #lines, -1, false, extraLines)
    vim.api.nvim_set_option_value("modifiable", false, {
        buf = self.bufnr
    })
    return ast
end

---@param lines Banana.Line[]
---@param offset number?
function Instance:highlight(lines, offset)
    offset = offset or 0
    vim.api.nvim_win_set_hl_ns(self.winid, self.highlightNs)
    if self.highlightNs ~= nil then
        vim.api.nvim_buf_clear_namespace(0, self.highlightNs, offset, offset + #lines)
        -- self.highlightNs = nil
    end
    if self.highlightNs == nil then
        self.highlightNs = vim.api.nvim_create_namespace("Spaceport")
    end
    vim.api.nvim_win_set_hl_ns(self.winid, self.highlightNs)
    if self.bufnr == nil or not vim.api.nvim_buf_is_valid(self.bufnr) then
        error("Unreachable (buf is invalid in higlightBuffer)")
    end
    local row = offset
    local col = 0
    local hlId = 0
    ---@type table<string, string>
    local usedHighlights = {}
    for _, v in ipairs(lines) do
        for _, word in ipairs(v) do
            local hlGroup = ""
            local ns = self.highlightNs
            if word.style ~= nil then
                local optsStr = vim.inspect(word.style)

                if word.style._name ~= nil then
                    ns = 0
                    hlGroup = word.style._name or "Normal"
                    local hl = vim.api.nvim_get_hl(ns, {
                        name = hlGroup,
                    })
                    local keysCount = #vim.tbl_keys(word.style)
                    -- Apparently i have to use json to detect vim.empty_dict()
                    local hlNotExists = vim.json.encode(hl) == "{}"
                    -- If there are default highlight options, and the highlight does not exist, create it
                    if hlNotExists and keysCount > 1 then
                        local opts = vim.deepcopy(word.style)
                        opts._name = nil
                        if opts == nil then
                            error("Unreachable [highlightBuffer colorOpts is nil]")
                        end
                        vim.api.nvim_set_hl(0, hlGroup, opts)
                    elseif hlNotExists then
                        hlGroup = M.defaultWinHighlight
                    end
                elseif usedHighlights[optsStr] ~= nil then
                    hlGroup = usedHighlights[optsStr]
                else
                    hlGroup = "spaceport_hl_" .. hlId
                    vim.api.nvim_set_hl(self.highlightNs, hlGroup, word.style)
                    hlId = hlId + 1
                    usedHighlights[optsStr] = hlGroup
                end
            else
                -- hlGroup = M.defaultWinHighlight
                hlGroup = "NormalFloat"
                ns = 0
            end
            vim.api.nvim_buf_add_highlight(self.bufnr, ns, hlGroup, row, col, col + _str.charCount(word.word))
            col = col + _str.charCount(word.word)
        end
        col = 0
        row = row + 1
    end
end

function Instance:reset()
    self.parser:reset()
end

M.defaultWinHighlight = "NormalFloat"

---@param filename string
---@param bufferName string
---@return Banana.Instance
function M.newInstance(filename, bufferName)
    local instance = Instance:new(filename, bufferName)
    return instance
end

return M
