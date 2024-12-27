local h = require("tests.helpers")
local code = [[
<nml>
<head>
<meta name="buf-filetype" value="lua">
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
end)
