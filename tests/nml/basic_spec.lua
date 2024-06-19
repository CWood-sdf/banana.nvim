local h = require('tests.helpers')
local code = [[
<nml>
<head>
<style>
nml {
    width: 5ch;
    height: 5ch;
}
div {
    hl-bg: #ff0000;
    height: 4ch;
}
</style>
</head>

<body>
<br>
<div>
asd
</div>
</body>
</nml>
]]

describe("Div rendering basic test", function()
    it("pads", function()
        local inst = require('banana.render').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        local div = inst:getElementsByTag("div")[1]
        div:setStyle("width: 100%; height: 100%; text-align: center; padding-bottom: 1ch;")
        local expectedMap = {
            "     ",
            "~~~~~",
            "~~~~~",
            "~~~~~",
            "~asd~",
            "~~~~~",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("centers text", function()
        local inst = require('banana.render').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        local div = inst:getElementsByTag("div")[1]
        div:setStyle("width: 100%; height: 100%; text-align: center;")
        local expectedMap = {
            "     ",
            "~~~~~",
            "~~~~~",
            "~~~~~",
            "~~~~~",
            "~asd~",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("relative positions", function()
        local inst = require('banana.render').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        local div = inst:getElementsByTag("div")[1]
        div:setStyle("width: 2ch; height: 3ch; position: relative; left: 1ch; top: 1ch;")
        local expectedMap = {
            "     ",
            "     ",
            " ~~  ",
            " as  ",
            " d~  ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("Overflow works", function()
        local inst = require('banana.render').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        local div = inst:getElementsByTag("div")[1]
        div:setStyle("width: 2ch; height: 3ch;")
        local expectedMap = {
            "     ",
            "~~   ",
            "as   ",
            "d~   ",
            "     ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("Renders the div", function()
        local inst = require('banana.render').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        local expectedMap = {
            "     ",
            "~~~~~",
            "~~~~~",
            "~~~~~",
            "asd~~"
        }
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)

        local div = inst:getElementsByTag("div")[1]
        div:setStyle("width: 3ch; height: 3ch;")
        expectedMap = {
            "     ",
            "~~~  ",
            "~~~  ",
            "asd  ",
            "     ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
end)
