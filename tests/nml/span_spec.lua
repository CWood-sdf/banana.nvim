local h = require("tests.helpers")
local code = [[
<nml>
<head>
<style>
nml {
    width: 5ch;
    height: 5ch;
}
span {
    hl-bg: #ff0000;
}
</style>
</head>

<body>
<br>
<span>
asd
</span>
</body>
</nml>
]]

describe("span rendering", function ()
    it("box spans wrap properly", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        local span = inst:getElementsByTagName("span")[1]
        span:setTextContent("asd")
        local span2 = inst:createElement("span")
        span2:setStyle("width: 3ch; height: 1ch;")
        inst:body():appendChild(span2)
        local expectedMap = {
            "     ",
            "asd  ",
            "~~~  ",
            "     ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        -- span:setStyleValue("width", "5ch")
        -- expectedMap = {
        --     "     ",
        --     "asd~a",
        --     "sd~~~",
        --     "     ",
        -- }
        -- inst:forceRerender()
        -- h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("doesnt completely overflow", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        local span = inst:getElementsByTagName("span")[1]
        span:setTextContent("asd asd")
        local expectedMap = {
            "     ",
            "asd~a",
            "sd   ",
            "     ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        span:setStyleValue("width", "5ch")
        expectedMap = {
            "     ",
            "asd~a",
            "sd~~~",
            "     ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("margins", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        -- inst.DEBUG = true
        inst.stripRight = false
        inst:open()

        local span = inst:getElementsByTagName("span")[1]
        span:setStyle("margin-left: 1ch;")
        local expectedMap = {
            "     ",
            " asd~",
            "     ",
            "     ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("pads", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        local span = inst:getElementsByTagName("span")[1]
        span:setStyle(
            "width: 100%; height: 100%; text-align: center; padding-top: 1ch;")
        local expectedMap = {
            "     ",
            "~~~~~",
            "~asd~",
            "~~~~~",
            "~~~~~",
            "~~~~~",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("centers text", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        local span = inst:getElementsByTagName("span")[1]
        span:setStyle(" text-align: center;")
        local expectedMap = {
            "     ",
            "asd~ ",
            "     ",
            "     ",
            "     ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("centers odd text", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        local span = inst:getElementsByTagName("span")[1]
        span:setStyle("width: 4ch; height: 100%; text-align: center;")
        local expectedMap1 = {
            "     ",
            "~asd ",
            "~~~~ ",
            "~~~~ ",
            "~~~~ ",
            "~~~~ ",
        }
        local expectedMap2 = {
            "     ",
            "asd~ ",
            "~~~~ ",
            "~~~~ ",
            "~~~~ ",
            "~~~~ ",
        }
        inst:forceRerender()
        local ok1, e1 = pcall(h.assertBgMapsMatch, h.bufToBgMap(inst.bufnr),
            expectedMap1)
        local ok2, e2 = pcall(h.assertBgMapsMatch, h.bufToBgMap(inst.bufnr),
            expectedMap2)
        if not (ok1 or ok2) then
            error(
                "Expected one of the centers to work\n Errors given: " ..
                e1 .. ", " .. e2)
        end
    end)
    it("relative positions", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        local span = inst:getElementsByTagName("span")[1]
        span:setStyle(
            "width: 2ch; height: 3ch; position: relative; left: 1ch; top: 1ch;")
        local expectedMap = {
            "     ",
            "     ",
            " as  ",
            " d~  ",
            " ~~  ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("Overflow works", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        local span = inst:getElementsByTagName("span")[1]
        span:setStyle("width: 2ch; height: 3ch;")
        local expectedMap = {
            "     ",
            "as   ",
            "d~   ",
            "~~   ",
            "     ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("Renders the span", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        local expectedMap = {
            "     ",
            "asd~ ",
            "     ",
            "     ",
            "     ",
        }
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)

        local span = inst:getElementsByTagName("span")[1]
        span:setStyle("width: 3ch; height: 3ch;")
        expectedMap = {
            "     ",
            "asd  ",
            "~~~  ",
            "~~~  ",
            "     ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
end)
