local h = require('tests.helpers')
local code = nml([[
<nml>
<head>
<style>
nml {
    width: 5ch;
    height: 5ch;
}
#one {
    hl-bg: #ff0000;
position: absolute;
 left: 1ch;
 top: 1ch;
 width: 3ch;
 height: 3ch;

}
#two {
    hl-bg: #00ff00;
position: absolute;
 left: 2ch;
 top: 2ch;
 width: 3ch;
 height: 3ch;

}
</style>
</head>

<body>
<br>
<div id="one">
</div>
<div id="two">
</div>
</body>
</nml>
]])


describe("Div rendering", function()
    it("absolutes", function()
        local inst = require('banana.instance').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        local expectedMap = {
            "     ",
            " ~~~ ",
            " ~!!!",
            " ~!!!",
            "  !!!",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("z-index 2", function()
        local inst = require('banana.instance').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        local expectedMap = {
            "     ",
            " ~~~ ",
            " ~!!!",
            " ~!!!",
            "  !!!",
        }
        local one = inst:getElementById("one")
        one:setStyleValue("z-index", "1")
        local two = inst:getElementById("two")
        two:setStyleValue("z-index", "2")
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("z-index 1", function()
        local inst = require('banana.instance').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        local expectedMap = {
            "     ",
            " ~~~ ",
            " ~~~!",
            " ~~~!",
            "  !!!",
        }
        local one = inst:getElementById("one")
        one:setStyleValue("z-index", "1")
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
end)
