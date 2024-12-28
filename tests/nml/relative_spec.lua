local h = require("tests.helpers")
local code = nml([[
<nml>
    <style>
    nml {
        width: 10ch;
        height: 5ch;
    }
    body {
    }

    span.rel {
        position: relative;
        top: 1ch;
    }
    span.rel-left {
        left: 1ch;
    }
    span {
        hl-bg: #000000;
        width: 4ch;
        height: 3ch;
    }
    div {

        hl-bg: #ff0000;
    }

    </style>

    <body>
    <br>
    <div>

        <span id="rel"> a </span>
        <span> a </span>
    </div>

    </body>

</nml>
]])

describe("Relative", function ()
    it("relatives", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        local expectedMap = {
            "          ",
            "a~~~a~~~!!",
            "~~~~~~~~!!",
            "~~~~~~~~!!",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)

        local el = inst:getElementById("rel")
        h.boundsMatch(el, {
            leftX = 1,
            rightX = 5,
            topY = 2,
            bottomY = 5,
        })
        el:addClass("rel")
        expectedMap = {
            "          ",
            "~~~~a!!!~~",
            "a!!!!!!!~~",
            "!!!!!!!!~~",
            "!!!!      ",
        }
        inst:forceRerender()
        h.boundsMatch(el, {
            leftX = 1,
            rightX = 5,
            topY = 3,
            bottomY = 6,
        })
        el:addClass("rel-left")
        expectedMap = {
            "          ",
            "~~~~a!!!~~",
            "~a!!!!!!~~",
            "~!!!!!!!~~",
            " !!!!     ",
        }
        inst:forceRerender()
        h.boundsMatch(el, {
            leftX = 2,
            rightX = 6,
            topY = 3,
            bottomY = 6,
        })
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
end)
