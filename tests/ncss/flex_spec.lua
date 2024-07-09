local h = require('tests.helpers')
local code = nml([[
<nml>
<head>
<style>
nml {
    width: 9ch;
    height: 3ch;
}
#flex {
    display: flex;
    padding-left: 1ch;
    hl-bg: red;
}
.no-shrink {
    flex-shrink: 0;
}
.grow {
    flex-grow: 1;
}
.grow-half {
    flex-grow: 0.5;
}
.fr1 {
    width: 1fr;
}
.pad-left {
    padding-left: 1ch;
}
.green {
    hl-bg: green;
}
</style>
</head>

<body>
<br>
<div id="flex">

</div>
</body>
</nml>
]])

describe("Flex test", function()
    it("uneven frs work", function()
        local inst = require('banana.render').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#:a",
            "div#.fr1:a",
            "div#.fr1:a",
            "div#.fr1:a",
        }, inst, inst:getElementById("flex"))

        local expectedMap = {
            "         ",
            "~aa~~a~a~",
            "         ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("fr units work", function()
        local inst = require('banana.render').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#.fr1:a",
            "div#.fr1:a",
            "div#.fr1:a",
            "div#.fr1:a",
        }, inst, inst:getElementById("flex"))

        local expectedMap = {
            "         ",
            "~a~a~a~a~",
            "         ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("single item with flex properties 2", function()
        local inst = require('banana.render').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#.green:asd"
        }, inst, inst:getElementById("flex"))

        local expectedMap = {
            "         ",
            "~asd~~~~~",
            "         ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("single item with flex properties", function()
        local inst = require('banana.render').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#.grow.green:asd"
        }, inst, inst:getElementById("flex"))

        local expectedMap = {
            "         ",
            "~asd!!!!!",
            "         ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("grow on both and pad 2", function()
        local inst = require('banana.render').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#.pad-left.grow:as",
            "div#.grow:asd"
        }, inst, inst:getElementById("flex"))

        local expectedMap = {
            "         ",
            "~~as~asd~",
            "         ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("grow on both and pad", function()
        local inst = require('banana.render').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#.pad-left.grow:asg",
            "div#.grow:asd"
        }, inst, inst:getElementById("flex"))

        local expectedMap = {
            "         ",
            "~~asg~asd",
            "         ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("grow on both sorta", function()
        local inst = require('banana.render').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#.grow-half:a",
            "div#.grow:a"
        }, inst, inst:getElementById("flex"))

        local expectedMap = {
            "         ",
            "~a~~a~~~~",
            "         ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("grow on both", function()
        local inst = require('banana.render').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#.grow:asg",
            "div#.grow:asd"
        }, inst, inst:getElementById("flex"))

        local expectedMap = {
            "         ",
            "~asg~asd~",
            "         ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("grow on 1", function()
        local inst = require('banana.render').emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#.grow:asg",
            "div#:asd"
        }, inst, inst:getElementById("flex"))

        local expectedMap = {
            "         ",
            "~asg~~asd",
            "         ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
end)
