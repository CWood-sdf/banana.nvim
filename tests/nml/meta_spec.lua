local code = nml([[
<nml>
<head>
<meta name="buf-filetype" value="txt">
</head>

<body>
</body>
</nml>
]])

local codeshort = nml([[
<nml>
<head>
<meta buf-filetype="txt">
</head>

<body>
</body>
</nml>
]])

describe("Meta ", function ()
    it("sets filetype", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        assert(vim.bo[inst.bufnr].filetype == "txt")
    end)
    it("sets filetype with shorthand", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(codeshort)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        assert(vim.bo[inst.bufnr].filetype == "txt")
    end)
    it("sets booleans", function ()
        local inst = require("banana.instance").emptyInstance()
        local c = nml([[
<nml>
<head>
<meta buf-eof="true">
<meta buf-modifiable="true">
</head>
<body>
</body>
</nml>
]])
        inst:useNml(c)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:forceRerender()

        assert(vim.bo[inst.bufnr].eof == true, "eof not true?")
        assert(vim.bo[inst.bufnr].modifiable == true, "eof not true?")
    end)
    it("sets numbers", function ()
        local inst = require("banana.instance").emptyInstance()
        local c = nml([[
<nml>
<head>
<meta buf-ul="20">
</head>
<body>
</body>
</nml>
]])
        inst:useNml(c)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:forceRerender()

        assert(vim.bo[inst.bufnr].ul == 20, "ul not 20?")
    end)
end)
