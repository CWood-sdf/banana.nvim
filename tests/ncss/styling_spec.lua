local h = require("tests.helpers")
local code = nml([[
<nml>
    <head>

        <style>
            nml {
                width: 2ch;
                height: 5ch;
            }
            div {
                hl-bg: red;
                width: 2ch;
                height: 2ch;
            }
            .asdf {
                hl-bg: blue !important;

            }

        </style>
    </head>

    <body>
    <br>

    <div id="a">
    a
    </div> <div id="b">
    b
    </div>
    </body>

</nml>
]])

describe("Style clearing", function ()
    it("should clear old styles", function ()
        local doc = require("banana.instance").emptyInstance()
        doc:useNml(code)
        doc.DEBUG = false
        doc.stripRight = false
        doc:open()
        local expectedMap = {
            "  ",
            "a~",
            "~~",
            "b~",
            "~~",
        }
        doc:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(doc.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, doc)

        local divs = doc:querySelectorAll("div")

        divs[1]:addClass("asdf")
        expectedMap = {
            "  ",
            "a~",
            "~~",
            "b!",
            "!!",
        }
        doc:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(doc.bufnr), expectedMap)

        divs[1]:removeClass("asdf")
        expectedMap = {
            "  ",
            "a~",
            "~~",
            "b~",
            "~~",
        }
        doc:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(doc.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, doc)
    end)
end)
