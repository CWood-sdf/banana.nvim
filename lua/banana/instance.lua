---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
---@module 'banana.utils.string'
local _str = require("banana.lazyRequire")("banana.utils.string")
---@module 'banana.utils.debug_flame'
local flame = require("banana.lazyRequire")("banana.utils.debug_flame")

local M = {}
M.defaultWinHighlight = "NormalFloat"

---@class Banana.NilAst

---@type Banana.NilAst?
local nilAst = nil

local ids = 0

---@class Banana.RouteParams
---@field selfNode Banana.Ast
---@field params { [string]: string }

---@type Banana.Instance[]
local instances = {}

---@alias Banana.Line Banana.Word[]

---@alias Banana.Remap.Constraint "hover"|number|"line-hover"

---@class (exact) Banana.Instance.Keymap
---@field fn fun(): boolean
---@field opts vim.keymap.set.Opts
---@field disabled boolean?

---@class (exact) Banana.Instance
---@field DEBUG_stressTest boolean
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
---@field rendering boolean
---@field DEBUG_showPerf boolean
local Instance = {}

---@class (exact) Banana.Word
---@field word string
---@field style? Banana.Highlight

---@param ast Banana.Ast
---@param width number
---@param height number
---@return Banana.Line[]
function Instance:_virtualRender(ast, width, height)
    --flame.new("virtualRender")
    ---@type Banana.Line[]
    local ret = {}
    setmetatable(ret, { __mode = "kv" })
    local tag = ast.actualTag
    ---@type Banana.Renderer.ExtraInfo
    local extra = {
        useAllHeight = false,
        trace = require("banana.box").Box:new(),
        debug = self.DEBUG,
        isRealRender = true,
    }
    setmetatable(extra, { __mode = "kv" })
    local rendered = tag:renderRoot(ast, nil, width, height, {
        text_align = "left",
        position = "static",
        min_size = false,
        min_size_direction = "horizontal",
        list_style_type = "star",
    }, extra)
    if self.stripRight then
        local bgNum = vim.api.nvim_get_hl(0, {
            name = M.defaultWinHighlight,
            -- name = self.
        }).bg
        local bg = nil
        if bgNum ~= nil then
            bg = string.format("#%06x", bgNum)
        end
        rendered:stripRightSpace(bg)
    end
    if extra.debug then
        rendered:appendBoxBelow(extra.trace)
    end
    return rendered:getLines()
end

function Instance:setBufName(str)
    self.bufname = str
end

---@return Banana.Instance
function Instance:new()
    if nilAst == nil then
        nilAst = {}
        for k, v in pairs(require("banana.nml.ast").Ast) do
            if type(v) == "function" then
                if k == "isNil" then
                    nilAst["isNil"] = function () return true end
                else
                    nilAst[k] = function ()
                        log.warn("Calling '" .. k .. "' on the nil ast")
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
        DEBUG_stressTest = false,
        DEBUG_showPerf = false,
        rendering = false,
        stripRight = true,
        DEBUG = false,
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
    local ast, styleRules, scripts = require("banana.require").nmlRequire(
        filename)
    self.scripts = scripts
    self.styleRules = styleRules
    self.ast = ast
    self:_applyId(ast)
end

---@param nml string
function Instance:useNml(nml)
    local ast, styleRules, scripts = require("banana.require").nmlLoadString(nml)
    self.scripts = scripts
    self.styleRules = styleRules
    self.ast = ast
    self:_applyId(ast)
end

function Instance:_attachAutocmds()
    vim.api.nvim_create_autocmd({ "WinEnter" }, {
        callback = function (args)
            if args.buf == self.bufnr then
                self.isVisible = true
            end
        end,
        group = self.augroup,
    })
    vim.api.nvim_create_autocmd({ "WinLeave" }, {
        group = self.augroup,
        callback = function (args)
            if args.buf == self.bufnr then
                self.isVisible = false
            end
        end,
    })
    vim.api.nvim_create_autocmd({ "VimResized" }, {
        group = self.augroup,
        callback = function (args)
            self:_requestRender()
        end,
    })
end

function Instance:close()
    self.isVisible = false
    vim.api.nvim_win_close(self.winid, false)
end

local n = 0
local avg = 0
function Instance:open()
    self.isVisible = true
    n = 0
    avg = 0
    self:_render()
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

function Instance:getBufnr()
    return self.bufnr
end

---@deprecated just use buffer =
---@param ev string|string[]
---@param opts vim.api.keyset.create_autocmd
---@return number
function Instance:on(ev, opts)
    if opts.command ~= nil then
        local cmd = opts.command
        opts.callback = function ()
            if not self.isVisible then
                return
            end
            vim.cmd(cmd)
        end
        opts.command = nil
    else
        local cb = opts.callback
        opts.callback = function ()
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
    if self.bufnr == nil then
        log.throw(
            "Buf does not exist")
        error("")
    end
    if self.keymaps[mode][lhs] == nil then
        self.keymaps[mode][lhs] = {}
        vim.keymap.set(mode, lhs, function ()
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
        rhs = function ()
            vim.api.nvim_feedkeys(
                vim.api.nvim_replace_termcodes(oldRhs, true, true, true), mode,
                true)
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
function Instance:_removeMapsFor(ast)
    for _, vals in ipairs(self.astMapDeps[ast] or {}) do
        local map = vals[3]
        map.disabled = true
    end
    for _, node in ipairs(ast.nodes) do
        if type(node) ~= "string" then
            self:_removeMapsFor(node)
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
    local sel = require("banana.ncss.query").selectors.oneTag("body")
    local arr = sel:getMatches(self.ast)
    if #arr == 0 then
        log.throw(
            "Could not find a body tag in Instance:body()")
        error("")
    end
    self._body = arr[1]
    return arr[1]
end

---@param ast Banana.Ast
function Instance:_applyId(ast)
    if ast.instance == nil then
        ast.instance = self.instanceId
    end
    for i, v in ipairs(ast.nodes) do
        if type(v) == "string" then
            goto continue
        end
        ---@diagnostic disable-next-line: param-type-mismatch
        self:_applyId(ast.nodes[i])
        ::continue::
    end
end

---@param ast Banana.Ast
function Instance:_applyInlineStyles(ast)
    ast:_applyInlineStyleDeclarations()
    for _, v in ipairs(ast.nodes) do
        if type(v) ~= "string" then
            self:_applyInlineStyles(v)
        end
    end
end

---@param ast Banana.Ast?
---@param rules Banana.Ncss.RuleSet[]
function Instance:_applyStyleDeclarations(ast, rules)
    if ast == nil then
        log.throw(
            "Ast is nil")
        error("")
    end
    self:_applyInlineStyles(ast)
    for _, v in ipairs(rules) do
        if v.query == nil then
            goto continue
        end
        local arr = v.query:find(ast)
        for _, a in ipairs(arr) do
            a:_applyStyleDeclarations(v.declarations, v.query.specificity)
        end

        ::continue::
    end
end

---@param script string
---@param opts table
function Instance:_runScript(script, opts)
    ---@type fun(opts: table)|nil
    local f = nil
    if #script > 0 and script:sub(1, 1) == "@" then
        local str = script:sub(2, #script)
        f = function (o)
            self:runScriptAt(str, o)
        end
    else
        script = "local document = require('banana.instance').getInstance(" ..
            self.instanceId .. ")\n" .. script
        f = loadstring(script)
    end
    if f == nil then
        log.throw(
            "Could not convert script tag to runnable lua function")
        error("")
    end
    f(opts)
end

---@return number, number
function Instance:_createWinAndBuf()
    --flame.new("winAndBuf")
    local headQuery = require("banana.ncss.query").selectors.oneTag("head")
    local headTag = headQuery:getMatches(self.ast)
    if #headTag ~= 0 then
        headTag[1].actualTag:renderRoot(headTag[1], nil, 0, 0, {
            list_style_type = "*",
            position = "static",
            text_align = "left",
            min_size = false,
        }, {
            useAllHeight = false,
            trace = require("banana.box").Box:new(),
            debug = self.DEBUG,
            isRealRender = false,
        })
    end
    --flame.expect("winAndBuf")
    --flame.pop()


    local containerWidth = vim.o.columns
    local containerHeight = vim.o.lines
    local width = vim.o.columns - 8 * 2
    local height = vim.o.lines - 3 * 2 - 4
    local left = 8
    local top = 3
    if self.ast.tag == "nml" then
        self.ast:_resolveUnits(containerWidth, containerHeight)
        if self.ast.style["width"] ~= nil then
            width = self.ast.style.width[1].value.computed
            ---@cast width number
        end
        if self.ast.style["height"] ~= nil then
            height = self.ast.style.height[1].value.computed
            ---@cast height number
        end
        if self.ast.style.left ~= nil then
            left = self.ast.style.left[1].value.computed
        elseif self.ast.style.right ~= nil then
            left = containerWidth - self.ast.style.right[1].value.computed -
                width
        end
        if self.ast.style.top ~= nil then
            top = self.ast.style.top[1].value.computed
        elseif self.ast.style.bottom ~= nil then
            top = containerHeight - self.ast.style.bottom[1].value.computed -
                height
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
        vim.api.nvim_set_option_value("wrap", false, { win = self.winid })
        for k, v in pairs(self.winOpts) do
            vim.api.nvim_set_option_value(k, v, { win = self.winid })
        end
    else
        if width ~= vim.api.nvim_win_get_width(self.winid) then
            vim.api.nvim_win_set_width(self.winid, width)
        end
        if height ~= vim.api.nvim_win_get_height(self.winid) then
            vim.api.nvim_win_set_height(self.winid, height)
        end
        local conf = vim.api.nvim_win_get_config(self.winid)
        local change = false
        if left ~= conf.col then
            conf.col = left
            change = true
        end
        if top ~= conf.row then
            conf.row = top
            change = true
        end
        if change then
            vim.api.nvim_win_set_config(self.winid, conf)
        end
    end

    return width, height
end

function Instance:_deferRender()
    vim.defer_fn(function ()
        if self.rendering then
            self:_deferRender()
            return
        end
        self.renderRequested = false
        self.renderStart = vim.loop.hrtime()
        self:_render()
        self.renderRequested = false
        self.rendering = false
    end, 20)
end

function Instance:_requestRender()
    if self.renderRequested then
        return
    end
    self.renderRequested = true
    self.renderStart = vim.loop.hrtime()
    self:_deferRender()
end

function Instance:forceRerender()
    self.renderRequested = false
    self:_render()
end

function Instance:_render()
    if self.DEBUG_showPerf or self.DEBUG then
        flame.overrideIsDev()
    end
    if not self.isVisible then
        return
    end
    local totalTime = 0
    if self.renderRequested then
        return
    end
    -- local mri = require("banana.memorysnapshot")
    -- collectgarbage("count")
    -- mri.m_cMethods.DumpMemorySnapshot("./dumps", n .. "-Before", -1)
    collectgarbage("stop")
    log.trace("Instance:render with " .. #self.scripts .. " scripts")
    flame.newIter()
    -- if n == 30 then
    -- flame.reset()
    -- end
    self.rendering = true
    local startTime = vim.loop.hrtime()
    local actualStart = startTime
    local astTime = 0
    local styleTime = 0
    self.ast:_clearStyles()
    self:_applyStyleDeclarations(self.ast, self.styleRules)
    for ast, rules in pairs(self.foreignStyles) do
        self:_applyStyleDeclarations(ast, rules)
    end
    self:body().relativeBoxes = {}
    self:body().absoluteAsts = {}

    styleTime = vim.loop.hrtime() - startTime
    startTime = vim.loop.hrtime()

    local width, height = self:_createWinAndBuf()

    local winTime = vim.loop.hrtime() - startTime
    startTime = vim.loop.hrtime()

    -- self:body():resolveUnits(width, height, {})
    flame.new("renderAll")
    local stuffToRender = self:_virtualRender(self.ast, width, height)
    flame.pop()

    local renderTime = vim.loop.hrtime() - startTime
    startTime = vim.loop.hrtime()

    local lines = {}
    for _, line in ipairs(stuffToRender) do
        local lineStr = ""
        for _, word in ipairs(line) do
            lineStr = lineStr .. word.word
        end
        table.insert(lines, lineStr)
    end
    -- collectgarbage("count")
    -- mri.m_cMethods.DumpMemorySnapshot("./dumps", n .. "-After", -1)

    local reductionTime = vim.loop.hrtime() - startTime
    startTime = vim.loop.hrtime()

    vim.api.nvim_set_option_value("modifiable", true, {
        buf = self.bufnr
    })
    vim.api.nvim_set_option_value("buftype", "nofile", {
        buf = self.bufnr
    })
    vim.api.nvim_buf_set_lines(self.bufnr, 0, -1, false, lines)
    vim.api.nvim_set_option_value("modifiable", false, {
        buf = self.bufnr
    })

    local bufTime = vim.loop.hrtime() - startTime
    startTime = vim.loop.hrtime()

    self:_highlight(stuffToRender, 0)
    for _, script in ipairs(self.scripts) do
        self:_runScript(script, {})
    end
    self.scripts = {}

    local hlTime = vim.loop.hrtime() - startTime
    totalTime = totalTime + vim.loop.hrtime() - actualStart

    if self.DEBUG or self.DEBUG_showPerf then
        n = n + 1
        avg = (avg * (n - 1) + renderTime) / n
        if self.DEBUG_stressTest then
            -- should be 560MB used on n=600
            -- renderOver pushes that to 2.5GB
            if n < 200 then
                self:_deferRender()
            end
        end
        local extraLines = {
            "",
            astTime / 1e6 .. "ms to parse",
            styleTime / 1e6 .. "ms to style",
            winTime / 1e6 .. "ms to create win",
            renderTime / 1e6 .. "ms to render",
            reductionTime / 1e6 .. "ms to reduce",
            hlTime / 1e6 .. "ms to highlight",
            bufTime / 1e6 .. "ms to set buf",
            totalTime / 1e6 .. "ms total",
            avg / 1e6 .. "ms avg render",
            "Instance id: " .. self.instanceId,
            "",
        }
        local filter = ""
        local flames = flame.getWorst("pct", filter, false)
        local flameMillis = flame.getFlames("millis", filter, false)
        local maxLen = 0
        for _, val in ipairs(flames) do
            maxLen = math.max(maxLen, #val[1] + 2)
        end

        -- local conf = flame.getFlameAlls90Conf("TagInfo:renderGridBlock")
        -- table.insert(extraLines, "(" .. conf[1] .. ", " .. conf[2] .. ")")
        -- print(vim.inspect(flames))
        local total = 0
        for _, val in ipairs(flames) do
            local str = val[1] .. ": "
            if #str < maxLen then
                str = str .. string.rep(" ", maxLen - #str)
            end
            local rep = math.floor(val[2] * 20)
            local pct =
                math.floor(val[2] * 1000) / 10 .. ""
            if #pct < 4 then
                pct = pct .. string.rep(" ", 4 - #pct)
            end
            total = total + flameMillis[val[1]]
            local time = math.floor(flameMillis[val[1]] * 1000) / 1000 ..
                "ms"
            if #time < 9 then
                time = time .. string.rep(" ", 9 - #time)
            end
            local chart = " " ..
                pct .. "% (" .. time .. ") " .. string.rep("#", rep)
            table.insert(extraLines, str .. chart)
        end
        table.insert(extraLines, "Total: " .. total .. "ms")
        vim.api.nvim_set_option_value("modifiable", true, {
            buf = self.bufnr
        })
        vim.api.nvim_buf_set_lines(self.bufnr, #lines, -1, false, extraLines)
        vim.api.nvim_set_option_value("modifiable", false, {
            buf = self.bufnr
        })
    end
    self.rendering = false
    collectgarbage("restart")
    collectgarbage()
end

---@param lines Banana.Line[]
---@param offset number?
function Instance:_highlight(lines, offset)
    offset = offset or 0
    --flame.new("hl:ns")
    vim.api.nvim_win_set_hl_ns(self.winid, self.highlightNs)
    if self.highlightNs ~= nil then
        vim.api.nvim_buf_clear_namespace(0, self.highlightNs, 0, -1)
        -- vim.api.nvim_win_set_hl_ns(self.winid, self.highlightNs)
        -- self.highlightNs = nil
    end
    --flame.pop()
    if self.bufnr == nil or not vim.api.nvim_buf_is_valid(self.bufnr) then
        log.throw(
            "Unreachable (buf is invalid in higlightBuffer)")
        error("")
    end
    --flame.new("hl:loop_outer")
    local row = offset
    local col = 0
    local hlId = 0
    -- ---@type table<string, string>
    -- local usedHighlights = {}
    for _, v in ipairs(lines) do
        --flame.new("hl:loop_inner")
        local i = 1
        while i <= #v do
            local word = v[i]
            --flame.new("hl:loop_inner2")
            local hlGroup = ""
            local ns = self.highlightNs
            -- local delta = _str.charWidth(word.word)
            -- log.debug(word.word .. ": " .. delta)
            local byteCount = _str.byteCount(word.word)
            if word.style ~= nil then
                --flame.new("hl:inspect")
                -- PERF: this is pretty inefficient
                -- local optsStr = vim.inspect(word.style)
                --flame.pop()
                while i + 1 <= #v and v[i + 1].style == word.style do
                    i = i + 1
                    -- delta = delta + _str.charWidth(v[i].word)
                    byteCount = byteCount + _str.byteCount(v[i].word)
                end

                if word.style.__name ~= nil then
                    ns = 0
                    --flame.new("hl:named_hl")
                    hlGroup = word.style.__name or "Normal"
                    local hl = vim.api.nvim_get_hl(ns, {
                        name = hlGroup,
                    })
                    local keysCount = #vim.tbl_keys(word.style)
                    -- Apparently i have to use json to detect vim.empty_dict()
                    local hlNotExists = vim.json.encode(hl) == "{}"
                    -- If there are default highlight options, and the highlight does not exist, create it
                    if hlNotExists and keysCount > 1 then
                        --flame.new("hl:create_named")
                        local opts = vim.deepcopy(word.style)
                        opts.__name = nil
                        if opts == nil then
                            log.throw(
                                "Unreachable [highlightBuffer colorOpts is nil]")
                            error("")
                        end
                        vim.api.nvim_set_hl(0, hlGroup, opts)
                        --flame.pop()
                    elseif hlNotExists then
                        hlGroup = M.defaultWinHighlight
                    end
                    --flame.pop()
                    -- elseif usedHighlights[optsStr] ~= nil then
                    --     hlGroup = usedHighlights[optsStr]
                else
                    --flame.new("hl:set_hl")
                    hlGroup = "banana_hl_" .. hlId
                    vim.api.nvim_set_hl(self.highlightNs, hlGroup, word.style)
                    hlId = hlId + 1
                    -- usedHighlights[optsStr] = hlGroup
                    --flame.pop()
                end
                --flame.new("hl:add_hl")
                vim.api.nvim_buf_add_highlight(self.bufnr, ns, hlGroup, row, col,
                    col + byteCount)
                --flame.pop()
            else
                hlGroup = M.defaultWinHighlight
                -- hlGroup = "NormalFloat"
                ns = 0
            end
            col = col + byteCount
            --flame.pop()
            i = i + 1
        end
        col = 0
        row = row + 1
        --flame.pop()
    end
    --flame.pop()
end

---Loads a partial nml file at {file} to be the content of the ast
---@param file string
---@param ast Banana.Ast
---@param remove boolean? Whether to remove all the child elements, default true
---@param preserve boolean? Whether to not clone the ast, default false.
function Instance:loadNmlTo(file, ast, remove, preserve)
    preserve = preserve or false
    if remove == nil then
        remove = true
    end
    local sides = vim.split(file, "?", {
        plain = true,
    })
    local content, rules, scripts = require("banana.require").nmlRequire(sides
        [1])
    if not preserve then
        content = content:clone()
    end
    if remove then
        ast:removeChildren()
    end
    ast:appendNode(content)
    -- save styles for scoped styles
    self.foreignStyles[content] = rules
    ---@type { [string]: string }
    local params = {}
    if sides[2] ~= nil then
        for v in vim.gsplit(sides[2], "&") do
            local halves = vim.split(v, "=")
            params[halves[1]] = halves[2] or "true"
        end
    end
    for _, script in ipairs(scripts) do
        self:_runScript(script, {
            params = params,
            selfNode = content,
        })
    end
    self:_requestRender()
end

---@param sel string
---@return Banana.Ast[]
function Instance:querySelectorAll(sel)
    local rule = sel .. "{}"
    local styleStuff = require("banana.ncss.parser").parseText(rule)
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
    if nilAst == nil then
        log.throw(
            "Unreachable")
        error("")
    end
    local query = require("banana.ncss.query").selectors.class(name)
    if self.ast == nil then
        log.throw(
            "Instance hasnt parsed yet (should be unreachable)")
        error("")
    end
    local asts = query:getMatches(self.ast)
    return asts
end

---@param name string
---@return Banana.Ast
function Instance:getElementById(name)
    if nilAst == nil then
        log.throw(
            "Unreachable")
        error("")
    end
    local query = require("banana.ncss.query").selectors.id(name)
    if self.ast == nil then
        log.throw(
            "Instance hasnt parsed yet (should be unreachable)")
        error("")
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
        log.throw(
            "Unreachable")
        error("")
    end
    local query = require("banana.ncss.query").selectors.tag(name)
    if self.ast == nil then
        log.throw(
            "Instance hasnt parsed yet (should be unreachable)")
        error("")
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
    local ast = require("banana.nml.ast").Ast:new(name, M.getNilAst())
    self:_applyId(ast)
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
    log.trace("Creating instance with file " ..
        filename .. " and buffername " .. bufferName)
    for _, v in ipairs(instances) do
        if v.bufname == bufferName then
            return v
        end
    end
    local instance = Instance:new()
    instance:setBufName(bufferName)
    instance:useFile(filename)
    return instance
end

---@return Banana.Instance
function M.emptyInstance()
    return Instance:new()
end

---@overload fun(id: string): Banana.Instance?
---@param id number
---@return Banana.Instance
function M.getInstance(id)
    if id == nil then
        log.throw(
            "Given a nil instance id")
        error("")
    end
    if type(id) == "string" then
        for _, v in ipairs(instances) do
            if v.bufname == id then return v end
        end
        return nil
    end
    if instances[id] == nil then
        log.throw(
            "Could not find instance with id " .. id)
        error("")
    end
    return instances[id]
end

---@return Banana.Ast
function M.getNilAst()
    ---@diagnostic disable-next-line: return-type-mismatch
    return nilAst
end

---@return number[]
function M.listInstanceIds()
    local ret = {}
    for i, v in ipairs(instances) do
        table.insert(ret, i)
    end
    return ret
    -- return vim.iter(ipairs(instances)):map(function (i, _) return i end):totable()
end

return M
