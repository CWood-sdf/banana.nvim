---@class Banana.Doc.Param
---@field name string
---@field tp string
---@field comments string

---@class Banana.Doc.Return
---@field tp string
---@field comments string

---@class Banana.Doc.Function
---@field comments string[]
---@field fnName string
---@field ret Banana.Doc.Return?
---@field params Banana.Doc.Param[]

local M = {}

local buf = -1
local win = -1

---idk
---@param str string filename
function M.useFile(str)
    local file = io.open(str, "r")
    if file == nil then
        error("file does not exist " .. str)
    end
    local contents = file:read("*a")
    file:close()

    local lines = vim.split(contents, "\n")

    if not vim.api.nvim_buf_is_valid(buf) then
        buf = vim.api.nvim_create_buf(false, true)
    end
    vim.api.nvim_buf_set_lines(buf, 0, -1, true, lines)
    if not vim.api.nvim_win_is_valid(win) then
        win = vim.api.nvim_open_win(buf, false, {
            relative = "editor",
            row = 10,
            col = 10,
            width = 20,
            height = 20,
        })
    end
end

---@param line string
---@return string, string
local function extractWord(line)
    local hasWord = false
    local start = 0
    local en = 0
    local wordDone = false
    local rest = ""
    for i = 1, #line do
        if line:sub(i, i) == " " then
            if hasWord and not wordDone then
                en = i - 1
                wordDone = true
                hasWord = false
            end
        elseif wordDone then
            rest = line:sub(i, #line)
            break
        elseif not hasWord then
            hasWord = true
            start = i
        end
    end
    if hasWord then
        en = #line
    end
    local word = line:sub(start, en)
    return word, rest
end

---@param line string
---@return string, string
local function extractType(line)
    local tp = ""
    local word, rest = ":", line

    local contChars = {
        [":"] = true,
        [","] = true,
    }

    while contChars[word:sub(#word, #word)] do
        if word ~= ":" then
            tp = tp .. " "
        end
        word, rest = extractWord(rest)
        tp = tp .. word
    end
    return tp, rest
end

---comment
---@param lines string[]
---@param prefix string
---@return string[], string?
local function removeLinePrefixed(lines, prefix)
    for i, v in ipairs(lines) do
        if #v < #prefix then
            goto continue
        end
        if v:sub(1, #prefix) == prefix then
            table.remove(lines, i)
            return lines, v:sub(#prefix + 1, #v)
        end
        ::continue::
    end
    return lines, nil
end

---@param lines string[]
---@return string[], Banana.Doc.Return?
local function getReturn(lines)
    local line
    lines, line = removeLinePrefixed(lines, "@return")
    if line == nil then
        return lines, nil
    end

    local tp
    tp, line = extractType(line)

    return lines, {
        tp = tp,
        comments = line
    }
end

---@param lines string[]
---@return string[], Banana.Doc.Param?
local function getParam(lines)
    local line
    lines, line = removeLinePrefixed(lines, "@param")
    if line == nil then
        return lines, nil
    end

    local name
    name, line = extractWord(line)

    local tp
    tp, line = extractType(line)

    return lines, {
        name = name,
        tp = tp,
        comments = line
    }
end

---@param lines string[]
---@return string[], Banana.Doc.Param[]
local function getParams(lines)
    local ret = {}
    local param = nil
    local iter = 0
    while iter < 1000 do
        lines, param = getParam(lines)
        if param == nil then
            break
        else
            table.insert(ret, param)
        end
        iter = iter + 1
    end
    return lines, ret
end

---@param lines string[]
---@return string[]
local function removeComment(lines)
    local ret = {}

    local prefix = "---"

    for _, v in ipairs(lines) do
        table.insert(ret, v:sub(#prefix + 1, #v))
    end
    return ret
end

---@param lines string[]
---@param pattern string
---@return string[], string
local function getFnName(lines, pattern)
    local line = lines[#lines]
    table.remove(lines, #lines)
    return lines, line:gmatch(pattern)()
end

---@param search string vim regex
---@param extract string lua regex
---@return Banana.Doc.Function[]
function M.getFns(search, extract, _)
    if not vim.api.nvim_buf_is_valid(buf) then
        error("no buf :(")
    end
    if not vim.api.nvim_win_is_valid(win) then
        error("no win :(")
    end

    vim.api.nvim_set_current_win(win)

    ---@type Banana.Doc.Function[]
    local fns = {}

    local function nextPart()
        vim.cmd("silent! norm gg")
        vim.cmd("/" .. search)
        vim.cmd("silent! norm {")
        vim.cmd("silent! norm dgg")
        local line = vim.api.nvim_buf_get_lines(buf, 0, 1, true)[1]

        if vim.regex(search):match_str(line) ~= nil then
            vim.print("at first")
            return
        end
        vim.cmd("/" .. search)
    end

    while true do
        local ok = pcall(nextPart)
        if not ok then
            break
        end
        local line = vim.fn.line(".")
        local lines = vim.api.nvim_buf_get_lines(buf, 0, line, true)

        lines = removeComment(lines)

        local fname
        lines, fname = getFnName(lines, extract)

        local ret
        lines, ret = getReturn(lines)

        local params = {}
        lines, params = getParams(lines)

        ---@type Banana.Doc.Function
        local fn = {
            comments = lines,
            fnName = fname,
            params = params,
            ret = ret,
        }

        table.insert(fns, fn)


        vim.cmd("silent! norm dgg")
    end
    vim.cmd("q")

    return fns
end

---@class Banana.Doc.genDocsFor.opts
---@field includeToc boolean?
---@field header string?
---@field print boolean?

---@param fns Banana.Doc.Function[]
---@param file string
---@param opts Banana.Doc.genDocsFor.opts
function M.genDocsFor(fns, file, opts)
    opts.includeToc = opts.includeToc or true
    opts.header = opts.header or ""

    local str = ""

    str = str .. opts.header

    if opts.includeToc then
        str = str .. "## TOC\n\n"
        local hasEls = false

        for _, fn in ipairs(fns) do
            if opts.print then
                vim.print(fn)
            end
            str = str .. "- [`" .. fn.fnName .. "`](#" .. fn.fnName .. ")\n"
            hasEls = true
        end
        if hasEls then
            str = str .. "\n"
        end
    end

    for _, v in ipairs(fns) do
        str = str .. "## `" .. v.fnName .. "`\n\n"
        for _, comment in ipairs(v.comments) do
            str = str .. comment .. "\n"
        end
        if #v.comments ~= 0 then
            str = str .. "\n"
        end

        if #v.params ~= 0 then
            str = str .. "- **Parameters**:\n\n"
            for _, p in ipairs(v.params) do
                str = str .. "  - `" .. p.name .. "` (" .. p.tp .. ")"
                if #vim.split(
                        p.comments, " ",
                        { trimempty = true }) ~= 0 then
                    str = str .. ": " .. p.comments
                end
                str = str .. "\n"
            end
            if #v.params ~= 0 then
                str = str .. "\n"
            end
        end
        if v.ret ~= nil then
            str = str .. "- **Returns**: `" .. v.ret.tp .. "`"
            if #vim.split(v.ret.comments, " ", { trimempty = true }) ~= 0 then
                str = str .. " - " .. v.ret.comments
            end
            str = str .. "\n\n"
        end
    end

    local f = io.open(file, "w")
    if f == nil then
        error()
    end
    f:write(str)
    f:close()
end

return M
