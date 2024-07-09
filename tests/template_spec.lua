-- a test file that serves as a template for other tests
local h = require('tests.helpers')
local code = nml([[
<nml>
<head>
<style>
nml {
    width: 5ch;
    height: 5ch;
}
</style>
</head>

<body>
<br>
</body>
</nml>
]])

describe("template test", function()
    it("renders", function()
        local inst = require('banana.render').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        local expectedMap = {
            "     ",
            "     ",
            "     ",
            "     ",
            "     ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
end)
