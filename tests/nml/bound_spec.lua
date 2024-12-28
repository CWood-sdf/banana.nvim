local h = require("tests.helpers")
local code = nml([[
<nml>
<head>
<style>
nml {
    width: 8ch;
    height: 5ch;
}

body {
    padding: 2ch 1ch 0ch 0ch;
}
/* #div > span { */
/*     hl-bg: red; */
/* } */
</style>
</head>

<body>
<ol id="ol">
    <li> <span> asd</span> </li>
</ol>
<div id="div">
    <span> asd </span>
</div>
</body>
</nml>
]])


describe("bound box", function ()
    it("ol works properly", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()

        local expectedMap = {
            "        ",
            "  1. asd",
            "  asd   ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.boundsMatch(inst:querySelectorAll("#div > span")[1],
            { leftX = 3, rightX = 7, topY = 3, bottomY = 4 },
            { leftX = 3, rightX = 8, topY = 3, bottomY = 4 }
        )
        h.boundsMatch(inst:querySelectorAll("#ol > li > span")[1],
            { leftX = 6, rightX = 9, topY = 2, bottomY = 3 })
    end)
end)
