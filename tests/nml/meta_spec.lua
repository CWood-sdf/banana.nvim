local code = [[
<nml>
<head>
<meta name="buf-filetype" value="lua">
</head>

<body>
</body>
</nml>
]]

local codeshort = [[
<nml>
<head>
<meta buf-filetype="lua">
</head>

<body>
</body>
</nml>
]]

describe("Meta ", function ()
    it("sets filetype", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        assert(vim.bo[inst.bufnr].filetype == "lua")
    end)
    it("sets filetype with shorthand", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(codeshort)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        assert(vim.bo[inst.bufnr].filetype == "lua")
    end)
end)
