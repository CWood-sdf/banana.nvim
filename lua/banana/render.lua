local _str = require('banana.utils.string')

local M = {}
M.defaultWinHighlight = "NormalFloat"

---@class Banana.NilAst

---@type Banana.NilAst?
local nilAst = nil

local ids = 0

local instances = {}

---@alias Banana.Line Banana.Word[]

---@alias Banana.Remap.Constraint "hover"|number|"line-hover"


---@class (exact) Banana.Instance.Keymap
---@field fn fun(): boolean
---@field opts vim.keymap.set.Opts
---@field disabled boolean?

---@class (exact) Banana.Instance
---@field winid? number
---@field bufnr? number
---@field bufname string
---@field filetype string
---@field highlightNs number
---@field instanceId number
---@field winhl table
---@field ast Banana.Ast
---@field styleRules Banana.Ncss.RuleSet[]
---@field scripts string[]
---@field foreignStyles { [Banana.Ast]: Banana.Ncss.RuleSet[] }
---@field keymaps { [string]: { [string]: Banana.Instance.Keymap[] } }
---@field astMapDeps { [Banana.Ast]: [string, string, Banana.Instance.Keymap][] }
---@field rendering boolean
---@field renderStart number
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
        local rendered = tag:getRendered(ast, nil, width, height, 1, 1, {
            text_align = "left",
        })
        rendered:stripRightSpace()
        for _, line in ipairs(rendered.lines) do
            table.insert(ret, line)
        end
    end
    return ret
end

function Instance:setBufName(str)
    self.bufname = str
end

---@return Banana.Instance
function Instance:new(filename, bufferName)
    if nilAst == nil then
        nilAst = {}
        for k, v in pairs(require('banana.nml.ast').Ast) do
            if type(v) == "function" then
                if k == "isNil" then
                    nilAst['isNil'] = function() return true end
                else
                    nilAst[k] = function()
                        print("Calling '" .. k .. "' on the nil ast\n")
                    end
                end
            else
                nilAst[k] = v
            end
        end
    end
    local ast, styleRules, scripts = require('banana.require').nmlRequire(filename)
    table.insert(instances, {})
    local id = #instances
    ---@type Banana.Instance
    local inst = {
        foreignStyles = {},
        renderStart = 0,
        rendering = false,
        keymaps = {},
        bufname = bufferName,
        filetype = "banana",
        highlightNs = vim.api.nvim_create_namespace("banana_instance_" .. ids),
        ast = ast,
        styleRules = styleRules,
        scripts = scripts,
        -- parser = parser,
        instanceId = id,
        winhl = {
            link = "NormalFloat"
        },
        astMapDeps = {}
    }
    setmetatable(inst, { __index = Instance })
    instances[id] = inst
    inst:applyId(ast)
    vim.api.nvim_set_hl(inst.highlightNs, M.defaultWinHighlight, inst.winhl)
    return inst
end

---runs a lua require string as a script
---@param str string
---@param opts table
function Instance:runScriptAt(str, opts)
    local script = require(str)
    if type(script) == "function" then
        script(self, opts)
    elseif type(script) == "table" and script.__banana_run ~= nil and type(script.__banana_run) == "function" then
        script.__banana_run(self, opts)
    else
        error("Return value from require('" ..
            str ..
            "' is not a runnable banana script (either fun(Banana.Instance, table): any or { __banana_run: fun(Banana.Instance, table): any })")
    end
end

function Instance:useBuffer(bufnr)
    self.bufnr = bufnr
end

function Instance:useWindow(winid)
    self.winid = winid
end

---comment
---@param mode string
---@param lhs string
---@param rhs string|fun()
---@param opts vim.keymap.set.Opts
---@param dep Banana.Ast
function Instance:_setRemap(mode, lhs, rhs, opts, dep)
    if self.keymaps[mode] == nil then
        self.keymaps[mode] = {}
    end
    if self.bufnr == nil then
        error("Buf does not exist")
    end
    if self.keymaps[mode][lhs] == nil then
        self.keymaps[mode][lhs] = {}
        vim.keymap.set(mode, lhs, function()
            for _, remap in ipairs(self.keymaps[mode][lhs]) do
                if remap.disabled then
                    goto continue
                end
                if remap.fn() then
                    break
                end
                ::continue::
            end
        end, {
            buffer = self.bufnr
        })
    end
    if type(rhs) == "string" then
        local oldRhs = rhs
        rhs = function()
            vim.api.nvim_feedkeys(vim.api.nvim_replace_termcodes(oldRhs, true, true, true), mode, true)
        end
    end
    ---@type Banana.Instance.Keymap
    local ins = { fn = rhs, opts = opts }
    table.insert(self.keymaps[mode][lhs], ins)
    if dep ~= self.ast and dep ~= self:body() then
        self.astMapDeps[dep] = self.astMapDeps[dep] or {}
        table.insert(self.astMapDeps[dep], { mode, lhs, ins })
    end
end

---@param ast Banana.Ast
function Instance:removeMapsFor(ast)
    for _, vals in ipairs(self.astMapDeps[ast] or {}) do
        local map = vals[3]
        map.disabled = true
    end
    for _, node in ipairs(ast.nodes) do
        if type(node) ~= "string" then
            self:removeMapsFor(node)
        end
    end
    if self.foreignStyles[ast] ~= nil then
        self.foreignStyles[ast] = nil
    end
end

---@return Banana.Ast
function Instance:body()
    if self.ast.tag ~= "nml" then
        return self.ast
    end
    local sel = require('banana.ncss.query').selectors.oneTag("body")
    local arr = sel:getMatches(self.ast)
    if #arr == 0 then
        error("Could not find a body tag in Instance:body()")
    end
    return arr[1]
end

---@param ast Banana.Ast
function Instance:applyId(ast)
    if ast.instance == nil then
        ast.instance = self.instanceId
    end
    for i, v in ipairs(ast.nodes) do
        if type(v) == "string" then
            goto continue
        end
        ---@diagnostic disable-next-line: param-type-mismatch
        self:applyId(ast.nodes[i])
        ::continue::
    end
end

---@param ast Banana.Ast
function Instance:applyInlineStyles(ast)
    ast:applyInlineStyleDeclarations()
    for _, v in ipairs(ast.nodes) do
        if type(v) ~= "string" then
            self:applyInlineStyles(v)
        end
    end
end

---@param ast Banana.Ast?
---@param rules Banana.Ncss.RuleSet[]
function Instance:applyStyleDeclarations(ast, rules)
    if ast == nil then
        error("Ast is nil")
    end
    self:applyInlineStyles(ast)
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
end

---@param script string
---@param opts table
function Instance:runScript(script, opts)
    ---@type fun(opts: table)|nil
    local f = nil
    if #script > 0 and script:sub(1, 1) == "@" then
        local str = script:sub(2, #script)
        f = function(o)
            self:runScriptAt(str, o)
        end
    else
        script = "local document = require('banana.render').getInstance(" .. self.instanceId .. ")\n" .. script
        f = loadstring(script)
    end
    if f == nil then
        error("Could not convert script tag to runnable lua function")
    end
    f(opts)
end

---@return Banana.Ast
function Instance:render()
    local totalTime = 0
    if self.rendering and (vim.loop.hrtime() - self.renderStart) > 2e9 then
        self.rendering = false
    end
    if self.rendering then
        vim.defer_fn(function()
            self:render()
        end, 10)
        return self.ast
    end
    self.rendering = true
    self.renderStart = vim.loop.hrtime()
    local startTime = vim.loop.hrtime()
    local actualStart = startTime
    local astTime = 0
    local styleTime = 0
    self:applyStyleDeclarations(self.ast, self.styleRules)
    for ast, rules in pairs(self.foreignStyles) do
        self:applyStyleDeclarations(ast, rules)
    end
    styleTime = vim.loop.hrtime() - startTime
    startTime = vim.loop.hrtime()
    -- default width
    local width = vim.o.columns - 8 * 2
    local height = vim.o.lines - 3 * 2 - 4
    if self.ast.tag == "nml" then
        self.ast:resolveUnits(vim.o.columns, vim.o.lines)
        if self.ast.style["width"] ~= nil then
            width = self.ast.style.width[1].value.computed
            ---@cast width number
        end
        if self.ast.style["height"] ~= nil then
            height = self.ast.style.height[1].value.computed
            ---@cast height number
        end
    end
    local stuffToRender = self:virtualRender(self.ast, width, height)
    local renderTime = vim.loop.hrtime() - startTime
    if self.bufnr == nil or not vim.api.nvim_buf_is_valid(self.bufnr) then
        self.bufnr = vim.api.nvim_create_buf(false, false)
        vim.api.nvim_buf_set_name(self.bufnr, self.bufname)
        vim.api.nvim_set_option_value("filetype", self.filetype, { buf = self.bufnr })
    end
    if self.winid == nil or not vim.api.nvim_win_is_valid(self.winid) then
        self.winid = vim.api.nvim_open_win(self.bufnr, true, {
            relative = "editor",
            width = width,
            height = height,
            row = 3,
            col = 8,
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
    for _, script in ipairs(self.scripts) do
        self:runScript(script, {})
    end
    self.scripts = {}
    local hlTime = vim.loop.hrtime() - startTime
    totalTime = totalTime + vim.loop.hrtime() - actualStart
    local extraLines = {
        "",
        astTime / 1e3 .. "μs to parse",
        styleTime / 1e3 .. "μs to style",
        renderTime / 1e3 .. "μs to render",
        reductionTime / 1e3 .. "μs to reduce",
        hlTime / 1e3 .. "μs to highlight",
        totalTime / 1e3 .. "μs total",
    }
    vim.api.nvim_set_option_value("modifiable", true, {
        buf = self.bufnr
    })
    vim.api.nvim_buf_set_lines(self.bufnr, #lines, -1, false, extraLines)
    vim.api.nvim_set_option_value("modifiable", false, {
        buf = self.bufnr
    })
    self.rendering = false
    return self.ast
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

---Loads a partial nml file at {file} to be the content of the ast
---@param file string
---@param ast Banana.Ast
---@param preserve boolean? Whether to clone the ast, default false.
function Instance:loadNmlTo(file, ast, preserve)
    preserve = preserve or false
    local sides = vim.split(file, '?', {
        plain = true,
    })
    local content, rules, scripts = require('banana.require').nmlRequire(sides[1])
    if not preserve then
        content = content:clone()
    end
    ast:removeChildren()
    ast:appendNode(content)
    self.foreignStyles[content] = rules
    ---@type { [string]: string }
    local params = {}
    if sides[2] ~= nil then
        for v in vim.gsplit(sides[2], '&') do
            local halves = vim.split(v, '=')
            params[halves[1]] = halves[2] or "true"
        end
    end
    for _, script in ipairs(scripts) do
        self:runScript(script, {
            params = params
        })
    end
end

---@param name string
---@return Banana.Ast[]
function Instance:getElementsByClassName(name)
    if nilAst == nil then
        error("Unreachable")
    end
    local query = require('banana.ncss.query').selectors.class(name)
    if self.ast == nil then
        error("Instance hasnt parsed yet (should be unreachable)")
    end
    local asts = query:getMatches(self.ast)
    return asts
end

---@param name string
---@return Banana.Ast
function Instance:getElementById(name)
    if nilAst == nil then
        error("Unreachable")
    end
    local query = require('banana.ncss.query').selectors.id(name)
    if self.ast == nil then
        error("Instance hasnt parsed yet (should be unreachable)")
    end
    local asts = query:getMatches(self.ast)
    if #asts ~= 1 then
        ---@diagnostic disable-next-line: return-type-mismatch
        return nilAst
    end
    return asts[1]
end

---@param name string
---@return Banana.Ast[]
function Instance:getElementsByTag(name)
    if nilAst == nil then
        error("Unreachable")
    end
    local query = require('banana.ncss.query').selectors.tag(name)
    if self.ast == nil then
        error("Instance hasnt parsed yet (should be unreachable)")
    end
    local asts = query:getMatches(self.ast)
    if #asts ~= 1 then
        ---@diagnostic disable-next-line: return-type-mismatch
        return nilAst
    end
    return asts
end

---@param name string
---@return Banana.Ast
function Instance:createElement(name)
    local ast = require('banana.nml.ast').Ast:new(name, M.getNilAst())
    self:applyId(ast)
    return ast
end

---@param scripts string[]
function Instance:addScripts(scripts)
    for _, v in ipairs(scripts) do
        table.insert(self.scripts, v)
    end
end

---@param filename string
---@param bufferName string
---@return Banana.Instance
function M.newInstance(filename, bufferName)
    local instance = Instance:new(filename, bufferName)
    return instance
end

---@param id number
---@return Banana.Instance
function M.getInstance(id)
    if id == nil then
        error("Given a nil instance id")
    end
    if instances[id] == nil then
        error("Could not find instance with id " .. id)
    end
    return instances[id]
end

---@return Banana.Ast
function M.getNilAst()
    ---@diagnostic disable-next-line: return-type-mismatch
    return nilAst
end

return M
