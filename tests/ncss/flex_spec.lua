local h = require("tests.helpers")
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
.no-grow {
    flex-grow: 0;
}
.center {
    text-align: center;
}
.grow-half {
    flex-grow: 0.5;
}
.fr1 {
    flex-grow: 1;
}
.pad-left {
    padding-left: 1ch;
}
.green {
    hl-bg: green;
}
/* .fr-margin-left { */
/*     margin-left: 1fr; */
/* } */
.w2 {
    width: 2ch;
}
.wrap {
    flex-wrap: wrap;
}
.basis-2ch {
    flex-basis: 2ch;
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

describe("Flex test", function ()
    it("text-align works", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#.fr1.center:a",
            "div#.w2.center.no-grow:aa",
            "div#.fr1.center:a",
        }, inst, inst:getElementById("flex"))

        local expectedMap = {
            "         ",
            "~~a~aa~a~",
            "         ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("out of order frs", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#a.fr1:a",
            "div#b:b",
            "div#c.fr1:c",
            "div#d.fr1:d",
        }, inst, inst:getElementById("flex"))

        local expectedMap = {
            "         ",
            "~a~bc~d~~",
            "         ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("uneven frs work", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#a:a",
            "div#b.fr1:b",
            "div#c.fr1:c",
            "div#d.fr1:d",
        }, inst, inst:getElementById("flex"))

        local expectedMap = {
            "         ",
            "~ab~c~d~~",
            "         ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("fr units work", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#a.fr1:a",
            "div#b.fr1:b",
            "div#c.fr1:c",
            "div#d.fr1:d",
        }, inst, inst:getElementById("flex"))

        local expectedMap = {
            "         ",
            "~a~b~c~d~",
            "         ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("single item with flex properties 2", function ()
        local inst = require("banana.instance").emptyInstance()
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
    it("single item with flex properties", function ()
        local inst = require("banana.instance").emptyInstance()
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
    it("grow on both and pad 2", function ()
        local inst = require("banana.instance").emptyInstance()
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
    it("grow on both and pad", function ()
        local inst = require("banana.instance").emptyInstance()
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
            "~~asgasd~",
            "         ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("grow on both sorta", function ()
        local inst = require("banana.instance").emptyInstance()
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
    it("grow on both", function ()
        local inst = require("banana.instance").emptyInstance()
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
    it("grow on 1", function ()
        local inst = require("banana.instance").emptyInstance()
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

    it("flex-basis property", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#a.basis-2ch.grow:a",
            "div#b.grow:b",
            "div#c.grow:c",
        }, inst, inst:getElementById("flex"))

        local expectedMap = {
            "         ",
            "~a~~b~c~~",
            "         ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, inst)
    end)

    it("flex-wrap property with wrapping", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#a.basis-2ch.grow.green:a",
            "div#b.basis-2ch.grow.green:b",
            "div#c.basis-2ch.grow.green:c",
            "div#d.basis-2ch.grow.green:d",
            "div#e.basis-2ch.grow.green:e",
        }, inst, inst:getElementById("flex"))

        inst:getElementById("flex"):addClass("wrap")

        local expectedMap = {
            "         ",
            "~a!b!c!d!",
            "~e!!!!!!!",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, inst, "!", function (k, m)
            if k ~= "e" then
                m.bottomY = 3
            end
            return m
        end)
    end)

    it("flex-wrap property without wrapping", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#a.basis-2ch.grow:a",
            "div#b.basis-2ch.grow:b",
            "div#c.basis-2ch.grow:c",
            "div#d.basis-2ch.grow:d",
            "div#e.basis-2ch.grow:e",
        }, inst, inst:getElementById("flex"))

        local expectedMap = {
            "         ",
            "~ab~cd~e~",
            "         ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
end)
