local h = require("tests.helpers")
describe("Various tests", function ()
    it("fits content and renders new things", function ()
        local code = nml([[
        <nml>
<head>
<style>
nml {
    width: 8ch;
    height: 5ch;
}
span {
    hl-bg: #ff0000;
    margin-right: 2ch;
    padding-left: 1ch;
}
</style>
</head>

<body>
<br>
<div style="width: fit-content; hl-bg: blue;">asdf <span>asd</span></div>
</body>
</nml>
        ]])
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = true
        inst.DEBUG_showBuild = true
        inst.stripRight = false
        inst:open()
        local expectedMap = {
            "        ",
            "asdf~~  ",
            "!asd~~  ",
            "        ",
            "        ",
        }
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("fits content and renders new things", function ()
        local code = nml([[
        <nml>
<head>
<style>
nml {
    width: 8ch;
    height: 5ch;
}
span {
    hl-bg: #ff0000;
    margin-right: 2ch;
    padding-left: 1ch;
}
</style>
</head>

<body>
<br>
<div style="hl-bg: blue;">asdf <span>asd</span></div>
</body>
</nml>
        ]])
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = true
        inst.DEBUG_showBuild = true
        inst.stripRight = false
        inst:open()
        local expectedMap = {
            "        ",
            "asdf~~~~",
            "!asd~~~~",
            "        ",
            "        ",
        }
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
end)
