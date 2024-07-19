local h = require("tests.helpers")
local code = nml([[
<nml>
<head>
<style>
nml {
    width: 5ch;
    height: 5ch;
}

.flex {
    hl-bg: red;
    display: flex;
    padding-left: 1ch;
}

.setw {
    hl-bg: blue;
    width: 3ch;
}

</style>
</head>
<body>
<br>

</body>
</nml>
]])


describe("Stupid things in the past", function()
    it("shouldnt massively overflow line below flex", function()
        local document = require('banana.instance').emptyInstance()
        local flexbox = document:createElement("div")
        flexbox:addClass("flex")
        local setw = document:createElement("setw")
        setw:addClass("setw")

        flexbox:appendNode(setw)
        document:body():appendNode(setw:clone())
        local expectedBody = {
            "     ",
            "~!!!~",
            "!!!  ",
            "     ",
            "     ",
        }
        document:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(document.bufnr), expectedBody)
    end)
end)
