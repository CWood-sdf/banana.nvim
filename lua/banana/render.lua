local _str = require('banana.utils.string')

local M = {}
M.defaultWinHighlight = "NormalFloat"

---@class Banana.NilAst

---@type Banana.NilAst?
local nilAst = nil

local ids = 0

---@type Banana.Instance[]
local instances = {}

---@alias Banana.Line Banana.Word[]

---@alias Banana.Remap.Constraint "hover"|number|"line-hover"

---@class (exact) Banana.Instance.Keymap
---@field fn fun(): boolean
---@field opts vim.keymap.set.Opts
---@field disabled boolean?

---@class (exact) Banana.Instance
---@field DEBUG boolean
---@field winid? number
---@field bufnr? number
---@field bufname string
---@field highlightNs number
---@field instanceId number
---@field winhl table
---@field ast Banana.Ast
---@field styleRules Banana.Ncss.RuleSet[]
---@field scripts string[]
---@field foreignStyles { [Banana.Ast]: Banana.Ncss.RuleSet[] }
---@field keymaps { [string]: { [string]: Banana.Instance.Keymap[] } }
---@field astMapDeps { [Banana.Ast]: [string, string, Banana.Instance.Keymap][] }
---@field renderRequested boolean
---@field renderStart number
---@field isVisible boolean
---@field winOpts { [string]: any }
---@field bufOpts { [string]: any }
---@field _body Banana.Ast?
---@field augroup number
---@field stripRight boolean
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
        ---@type Banana.Renderer.ExtraInfo
        local extra = {
            trace = require('banana.box').Box:new(),
            debug = false,
        }
        local rendered = tag:renderRoot(ast, nil, width, height, {
            text_align = "left",
            position = "static",
        }, extra)
        if self.stripRight then
            rendered:stripRightSpace()
        end
        if extra.debug then
            rendered:appendBoxBelow(extra.trace)
        end
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
function Instance:new()
    if nilAst == nil then
        nilAst = {}
        for k, v in pairs(require('banana.nml.ast').Ast) do
            if type(v) == "function" then
                if k == "isNil" then
                    nilAst['isNil'] = function() return true end
                else
                    nilAst[k] = function()
                        vim.notify("Calling '" .. k .. "' on the nil ast\n")
                    end
                end
            else
                nilAst[k] = v
            end
        end
    end
    table.insert(instances, {})
    local id = #instances
    ---@type Banana.Instance
    local inst = {
        stripRight = true,
        DEBUG = true,
        isVisible = false,
        foreignStyles = {},
        renderStart = 0,
        renderRequested = false,
        keymaps = {},
        bufname = "Banana empty " .. id,
        highlightNs = vim.api.nvim_create_namespace("banana_instance_" .. ids),
        augroup = vim.api.nvim_create_augroup("banana_instance_" .. ids, {}),
        ---@diagnostic disable-next-line: assign-type-mismatch
        ast = nilAst,
        styleRules = {},
        scripts = {},
        -- parser = parser,
        instanceId = id,
        winhl = {
            link = "NormalFloat"
        },
        astMapDeps = {},
        bufOpts = {
            filetype = "",
        },
        winOpts = {
            signcolumn = "no",
        },
    }
    setmetatable(inst, { __index = Instance })
    instances[id] = inst
    vim.api.nvim_set_hl(inst.highlightNs, M.defaultWinHighlight, inst.winhl)
    inst:_attachAutocmds()
    return inst
end

---@param filename string
function Instance:useFile(filename)
    local ast, styleRules, scripts = require('banana.require').nmlRequire(filename)
    self.scripts = scripts
    self.styleRules = styleRules
    self.ast = ast
    self:applyId(ast)
end

---@param nml string
function Instance:useNml(nml)
    local ast, styleRules, scripts = require('banana.require').nmlLoadString(nml)
    self.scripts = scripts
    self.styleRules = styleRules
    self.ast = ast
    self:applyId(ast)
end

function Instance:_attachAutocmds()
    vim.api.nvim_create_autocmd({ "WinEnter" }, {
        callback = function(args)
            if args.buf == self.bufnr then
                self.isVisible = true
            end
        end,
        group = self.augroup,
    })
    vim.api.nvim_create_autocmd({ "WinLeave" }, {
        group = self.augroup,
        callback = function(args)
            if args.buf == self.bufnr then
                self.isVisible = false
            end
        end,
    })
end

function Instance:close()
    self.isVisible = false
    vim.api.nvim_win_close(self.winid, false)
end

function Instance:open()
    self.isVisible = true
    self:render()
end

---@return boolean
function Instance:isOpen()
    return self.isVisible
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

---@param ev string|string[]
---@param opts vim.api.keyset.create_autocmd
---@return number
function Instance:on(ev, opts)
    if opts.command ~= nil then
        local cmd = opts.command
        opts.callback = function()
            if not self.isVisible then
                return
            end
            vim.cmd(cmd)
        end
        opts.command = nil
    else
        local cb = opts.callback
        opts.callback = function()
            if not self.isVisible then
                return
            end
            cb()
        end
    end
    return vim.api.nvim_create_autocmd(ev, opts)
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
    assert(self.bufnr ~= nil,
        "Buf does not exist")
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
    if self._body ~= nil then
        return self._body
    end
    if self.ast.tag ~= "nml" then
        return self.ast
    end
    local sel = require('banana.ncss.query').selectors.oneTag("body")
    local arr = sel:getMatches(self.ast)
    assert(#arr ~= 0,
        "Could not find a body tag in Instance:body()")
    self._body = arr[1]
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
    assert(ast ~= nil,
        "Ast is nil")
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
    assert(f ~= nil,
        "Could not convert script tag to runnable lua function")
    f(opts)
end

---@return number, number
function Instance:createWinAndBuf()
    local headQuery = require('banana.ncss.query').selectors.oneTag("head")
    local headTag = headQuery:getMatches(self.ast)
    if #headTag ~= 0 then
        headTag[1].actualTag:getRendered(headTag[1], nil, 0, 0, 0, 0, {
            position = "static",
            text_align = "left",
        }, {
            trace = require('banana.box').Box:new(),
            debug = self.DEBUG,
        })
    end
    local containerWidth = vim.o.columns
    local containerHeight = vim.o.lines
    local width = vim.o.columns - 8 * 2
    local height = vim.o.lines - 3 * 2 - 4
    if self.ast.tag == "nml" then
        self.ast:resolveUnits(containerWidth, containerHeight)
        if self.ast.style["width"] ~= nil then
            width = self.ast.style.width[1].value.computed
            ---@cast width number
        end
        if self.ast.style["height"] ~= nil then
            height = self.ast.style.height[1].value.computed
            ---@cast height number
        end
    end
    if self.bufnr == nil or not vim.api.nvim_buf_is_valid(self.bufnr) then
        self.bufnr = vim.api.nvim_create_buf(false, false)
        vim.api.nvim_buf_set_name(self.bufnr, self.bufname)
        for k, v in pairs(self.bufOpts) do
            vim.api.nvim_set_option_value(k, v, { buf = self.bufnr })
        end
    end
    if self.winid == nil or not vim.api.nvim_win_is_valid(self.winid) then
        local left = 8
        local top = 3
        if self.ast.style.left ~= nil then
            left = self.ast.style.left[1].value.computed
        elseif self.ast.style.right ~= nil then
            left = containerWidth - self.ast.style.right[1].value.computed - width
        end
        if self.ast.style.top ~= nil then
            top = self.ast.style.top[1].value.computed
        elseif self.ast.style.bottom ~= nil then
            top = containerHeight - self.ast.style.bottom[1].value.computed - height
        end
        self.winid = vim.api.nvim_open_win(self.bufnr, true, {
            relative = "editor",
            width = width,
            height = height,
            row = top,
            col = left,
            style = "minimal",
            -- zindex = 1000,
        })
        vim.api.nvim_set_current_win(self.winid)
        vim.api.nvim_win_set_buf(self.winid, self.bufnr)
        vim.api.nvim_set_option_value("signcolumn", "no", { win = self.winid })
        for k, v in pairs(self.winOpts) do
            vim.api.nvim_set_option_value(k, v, { win = self.winid })
        end
    else
        width = vim.api.nvim_win_get_width(self.winid)
        height = vim.api.nvim_win_get_height(self.winid)
    end
    return width, height
end

function Instance:_requestRender()
    if self.renderRequested then
        return
    end
    self.renderRequested = true
    self.renderStart = vim.loop.hrtime()
    vim.defer_fn(function()
        self.renderRequested = false
        self:render()
    end, 20)
end

function Instance:forceRerender()
    self.renderRequested = false
    self:render()
end

function Instance:render()
    if not self.isVisible then
        return
    end
    local totalTime = 0
    if self.renderRequested then
        return
    end
    local startTime = vim.loop.hrtime()
    local actualStart = startTime
    local astTime = 0
    local styleTime = 0
    self:applyStyleDeclarations(self.ast, self.styleRules)
    for ast, rules in pairs(self.foreignStyles) do
        self:applyStyleDeclarations(ast, rules)
    end
    self:body().relativeBoxes = {}
    self:body().absoluteAsts = {}
    styleTime = vim.loop.hrtime() - startTime
    startTime = vim.loop.hrtime()
    local width, height = self:createWinAndBuf()
    local stuffToRender = self:virtualRender(self.ast, width, height)
    local renderTime = vim.loop.hrtime() - startTime

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
    if self.DEBUG then
        local extraLines = {
            "",
            astTime / 1e3 .. "μs to parse",
            styleTime / 1e3 .. "μs to style",
            renderTime / 1e6 .. "ms to render",
            reductionTime / 1e3 .. "μs to reduce",
            hlTime / 1e3 .. "μs to highlight",
            totalTime / 1e6 .. "ms total",
        }
        vim.api.nvim_set_option_value("modifiable", true, {
            buf = self.bufnr
        })
        vim.api.nvim_buf_set_lines(self.bufnr, #lines, -1, false, extraLines)
        vim.api.nvim_set_option_value("modifiable", false, {
            buf = self.bufnr
        })
    end
    self.renderRequested = false
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
    vim.api.nvim_win_set_hl_ns(self.winid, self.highlightNs)
    assert(self.bufnr ~= nil or not vim.api.nvim_buf_is_valid(self.bufnr),
        "Unreachable (buf is invalid in higlightBuffer)")
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

                if word.style.__name ~= nil then
                    ns = 0
                    hlGroup = word.style.__name or "Normal"
                    local hl = vim.api.nvim_get_hl(ns, {
                        name = hlGroup,
                    })
                    local keysCount = #vim.tbl_keys(word.style)
                    -- Apparently i have to use json to detect vim.empty_dict()
                    local hlNotExists = vim.json.encode(hl) == "{}"
                    -- If there are default highlight options, and the highlight does not exist, create it
                    if hlNotExists and keysCount > 1 then
                        local opts = vim.deepcopy(word.style)
                        opts.__name = nil
                        assert(opts ~= nil,
                            "Unreachable [highlightBuffer colorOpts is nil]")
                        vim.api.nvim_set_hl(0, hlGroup, opts)
                    elseif hlNotExists then
                        hlGroup = M.defaultWinHighlight
                    end
                elseif usedHighlights[optsStr] ~= nil then
                    hlGroup = usedHighlights[optsStr]
                else
                    hlGroup = "banana_hl_" .. hlId
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
    self:_requestRender()
end

---@param sel string
---@return Banana.Ast[]
function Instance:querySelectorAll(sel)
    local rule = sel .. "{}"
    local styleStuff = require('banana.ncss.parser').parseText(rule)
    local query = styleStuff[1].query
    if query == nil then
        error("No query for element")
    end
    local asts = query:find(self.ast)
    return asts
end

---@param name string
---@return Banana.Ast[]
function Instance:getElementsByClassName(name)
    assert(nilAst ~= nil,
        "Unreachable")
    local query = require('banana.ncss.query').selectors.class(name)
    assert(self.ast ~= nil,
        "Instance hasnt parsed yet (should be unreachable)")
    local asts = query:getMatches(self.ast)
    return asts
end

---@param name string
---@return Banana.Ast
function Instance:getElementById(name)
    assert(nilAst ~= nil,
        "Unreachable")
    local query = require('banana.ncss.query').selectors.id(name)
    assert(self.ast ~= nil,
        "Instance hasnt parsed yet (should be unreachable)")
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
    assert(nilAst ~= nil,
        "Unreachable")
    local query = require('banana.ncss.query').selectors.tag(name)
    assert(self.ast ~= nil,
        "Instance hasnt parsed yet (should be unreachable)")
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
function Instance:_addScripts(scripts)
    for _, v in ipairs(scripts) do
        table.insert(self.scripts, v)
    end
end

---@param filename string
---@param bufferName string
---@return Banana.Instance
function M.newInstance(filename, bufferName)
    local instance = Instance:new()
    instance:setBufName(bufferName)
    instance:useFile(filename)
    return instance
end

---@return Banana.Instance
function M.emptyInstance()
    return Instance:new()
end

---@param id number
---@return Banana.Instance
function M.getInstance(id)
    assert(id ~= nil,
        "Given a nil instance id")
    assert(instances[id] ~= nil,
        "Could not find instance with id " .. id)
    return instances[id]
end

---@return Banana.Ast
function M.getNilAst()
    ---@diagnostic disable-next-line: return-type-mismatch
    return nilAst
end

---@return number[]
function M.listInstanceIds()
    return vim.iter(ipairs(instances)):map(function(i, _) return i end):totable()
end

return M
