local h = require("tests.helpers")
local code = nml([[
<nml>
<head>
<style>
nml {
    width: 5ch;
    height: 5ch;
}
#a {
    hl-bg: #ff0000;
position: absolute;
 left: 1ch;
 top: 1ch;
 width: 3ch;
 height: 3ch;

}
#b {
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
<div id="a">
a
</div>
<div id="b">
b
</div>
</body>
</nml>
]])


describe("Div rendering", function ()
    it("absolutes", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        local expectedMap = {
            "     ",
            " a~~ ",
            " ~b!!",
            " ~!!!",
            "  !!!",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, inst, "~",
            function (k, v) if k == "a" then return v end end)
        h.assertGridBoundsMatch(expectedMap, inst, "!",
            function (k, v) if k == "b" then return v end end)
    end)
    it("out of page 1", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        local expectedMap = {
            "     ",
            " a~~ ",
            " ~~bcd",
            " ~~bcd",
            "   !!!",
        }
        local a = inst:getElementById("a")
        a:setStyleValue("z-index", "1")
        local b = inst:getElementById("b")
        b:setTextContent("bcdbcd")
        b:setStyleValue("z-index", "2")
        b:setStyleValue("left", "3ch")
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, inst, "~",
            function (k, v) if k == "a" then return v end end)
        -- h.assertGridBoundsMatch(expectedMap, inst, "!",
        --     function (k, v) if k == "b" then return v end end)
    end)
    it("z-index 2", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        local expectedMap = {
            "     ",
            " a~~ ",
            " ~b!!",
            " ~!!!",
            "  !!!",
        }
        local a = inst:getElementById("a")
        a:setStyleValue("z-index", "1")
        local b = inst:getElementById("b")
        b:setStyleValue("z-index", "2")
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, inst, "~",
            function (k, v) if k == "a" then return v end end)
        h.assertGridBoundsMatch(expectedMap, inst, "!",
            function (k, v) if k == "b" then return v end end)
    end)
    it("z-index 1", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        local expectedMap = {
            "     ",
            " a~~ ",
            " ~~~!",
            " ~~~!",
            "  !!!",
        }
        local a = inst:getElementById("a")
        a:setStyleValue("z-index", "1")
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, inst, "~",
            function (k, v) if k == "a" then return v end end)
        -- h.assertGridBoundsMatch(expectedMap, inst, "!",
        --     function (k, v) if k == "b" then return v end end)
    end)
end)
