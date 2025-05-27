-- a test file that serves as a template for other tests
local h = require("tests.helpers")
local code = nml([[
<nml>
<head>
<style>
nml {
    width: 5ch;
    height: 5ch;
}
.asdf {
    hl-bg: red;
}
</style>
</head>
<body>
<br>
<div> a </div>
</body>
</nml>
]])

describe("clone", function ()
    it("renders", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        local expectedMap = {
            "     ",
            "a    ",
            "     ",
            "     ",
            "     ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        local clone = inst:getElementsByTagName("div")[1]:clone(true)
        inst:body():appendChild(clone)

        expectedMap = {
            "     ",
            "a    ",
            "a    ",
            "     ",
            "     ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        clone:setTextContent("asd")
        expectedMap = {
            "     ",
            "a    ",
            "asd  ",
            "     ",
            "     ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)

        clone:addClass("asdf")
        expectedMap = {
            "     ",
            "a    ",
            "asd~~",
            "     ",
            "     ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)

        local clone2 = clone:clone(true)

        inst:body():appendChild(clone2)
        expectedMap = {
            "     ",
            "a    ",
            "asd~~",
            "asd~~",
            "     ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
end)
