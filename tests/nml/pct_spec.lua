local h = require('tests.helpers')
local code = nml([[
<nml>
<head>
<style>
.w50 {
    width: 50%;
    height: 50%;
}
div {
    hl-bg: red;
}
nml {
    width: 8ch;
    height: 8ch;
}
</style>
</head>
<body>
<br>
<div class="w50">

</div>
</body>
</nml>
]])

describe("Percentage tests", function()
    it("regular percents", function()
        local inst = require('banana.render').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:getElementsByTag("div")[1]:setStyleValue("margin-left", "50%")

        local expectedMap = {
            "        ",
            "    ~~~~",
            "    ~~~~",
            "    ~~~~",
            "    ~~~~",
            "        ",
            "        ",
            "        ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("regular percents", function()
        local inst = require('banana.render').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        local expectedMap = {
            "        ",
            "~~~~    ",
            "~~~~    ",
            "~~~~    ",
            "~~~~    ",
            "        ",
            "        ",
            "        ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("percents with padding", function()
        local inst = require('banana.render').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:body():setStyleValue("padding-left", "50%")

        local expectedMap = {
            "        ",
            "    ~~  ",
            "    ~~  ",
            "    ~~  ",
            "    ~~  ",
            "        ",
            "        ",
            "        ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
end)
