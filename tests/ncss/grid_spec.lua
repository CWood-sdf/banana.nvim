local h = require("tests.helpers")
local code = nml([[
<nml>
<head>
<style>
nml {
    width: 10ch;
    height: 9ch;
}
.grid {
    display: grid;
    hl-bg: green;
}
.grid > div {
    hl-bg: red;
}
.grid-template-columns {
    grid-template-columns: repeat(5, 1fr);
}
.grid-template-rows {
    grid-template-rows: repeat(3, 1fr);
}
.grid-template-both {
    grid-template-rows: repeat(3, 1fr);
    grid-template-columns: repeat(5, 1fr);
}
.grid-template-columns-mixed {
    grid-template-columns: 1ch repeat(3, 1fr);
}
.grid-template-rows-mixed {
    grid-template-rows: 1ch repeat(4, 1fr);
}
.grid-template-both-mixed {
    grid-template-rows: 1ch repeat(4, 1fr);
    grid-template-columns: 1ch repeat(3, 1fr);
}
.row-gap-ch {
    row-gap: 1ch;
}
.row-gap-pct {
    row-gap: 20%;
}
.column-gap-ch {
    column-gap: 1ch;
}
.column-gap-pct {
    column-gap: 10%;
}
.row-defined { grid-row: 1;
}
.row-defined-range {
    grid-row: 1 / 3;
}
.row-defined-range-span {
    grid-row: 2 / span 3;
}
.row-span {
    grid-row: span 2;
}
.column-defined {
    grid-column: 1;
}
.column-defined-range {
    grid-column: 1 / 3;
}
.column-defined-range-span {
    grid-column: 3 / span 3;
}
.column-defined-range-span-2 {
    grid-column: 2 / span 3;
}
.column-defined-2 {
    grid-column: 2;
}
.column-span {
    grid-column: span 2;
}
.z {
    z-index: 1;
}
</style>
</head>

<body>
<br>
<div class="grid">

</div>
</body>
</nml>
]])

describe("Grid test", function ()
    it("cursor weirdness", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-both")
        h.createElements({
            "div#:a",
            "div#.column-defined-2:b",
            "div#.column-defined-2:c",
            "div#:d",
            "div#:e",
            "div#:f",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~b~!!!!!!",
            "~~~~!!!!!!",
            "~~~~!!!!!!",
            "!!c~d~e~f~",
            "!!~~~~~~~~",
            "!!~~~~~~~~",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("both-templates-mixed-row-col-precedence", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-both-mixed")
        h.createElements({
            "div#:a",
            "div#:b",
            "div#.row-defined.column-defined:c",
            "div#:d",
            "div#:e",
            "div#:f",
            "div#:g",
            "div#:h",
            "div#:i",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "ca~~b~~d~~",
            "ef~~g~~h~~",
            "~~~~~~~~~~",
            "i!!!!!!!!!",
            "~!!!!!!!!!",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("both-templates-mixed-row-col-precedence-2", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-both-mixed")
        h.createElements({
            "div#:a",
            "div#:b",
            "div#.row-defined.column-defined-2:c",
            "div#.row-defined:d",
            "div#.row-defined:e",
            "div#:f",
            "div#:g",
            "div#:h",
            "div#:i",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "dc~~e~~a~~",
            "bf~~g~~h~~",
            "~~~~~~~~~~",
            "i!!!!!!!!!",
            "~!!!!!!!!!",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("both-templates-mixed-row-col-precedence-3", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-both-mixed")
        h.createElements({
            "div#:a",
            "div#:b",
            "div#.row-defined.column-defined-2:c",
            "div#.row-defined.column-defined-2:j",
            "div#.row-defined:d",
            "div#.row-defined:e",
            "div#:f",
            "div#:g",
            "div#:h",
            "div#:i",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "dj~~e~~a~~",
            "bf~~g~~h~~",
            "~~~~~~~~~~",
            "i!!!!!!!!!",
            "~!!!!!!!!!",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("both-templates-mixed-row-col-precedence-z", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-both-mixed")
        h.createElements({
            "div#:a",
            "div#:b",
            "div#.row-defined.column-defined-2.z:c",
            "div#.row-defined.column-defined-2:j",
            "div#.row-defined:d",
            "div#.row-defined:e",
            "div#:f",
            "div#:g",
            "div#:h",
            "div#:i",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "dc~~e~~a~~",
            "bf~~g~~h~~",
            "~~~~~~~~~~",
            "i!!!!!!!!!",
            "~!!!!!!!!!",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("both-templates-mixed", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-both-mixed")
        h.createElements({
            "div#:a",
            "div#:b",
            "div#:c",
            "div#:d",
            "div#:e",
            "div#:f",
            "div#:g",
            "div#:h",
            "div#:i",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "ab~~c~~d~~",
            "ef~~g~~h~~",
            "~~~~~~~~~~",
            "i!!!!!!!!!",
            "~!!!!!!!!!",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("both-templates", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-both")
        h.createElements({
            "div#:a",
            "div#:b",
            "div#:c",
            "div#:d",
            "div#:e",
            "div#:f",
            "div#:g",
            "div#:h",
            "div#:i",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~b~c~d~e~",
            "~~~~~~~~~~",
            "~~~~~~~~~~",
            "f~g~h~i~!!",
            "~~~~~~~~!!",
            "~~~~~~~~!!",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("columns-mixed", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-columns-mixed")
        h.createElements({
            "div#:a",
            "div#:a",
            "div#:a",
            "div#:a",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "aa~~a~~a~~",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("columns-defined", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-columns")
        h.createElements({
            "div#:a",
            "div#:a",
            "div#:a",
            "div#:a",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~a~a~a~!!",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("rows-mixed", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-rows-mixed")
        h.createElements({
            "div#:a",
            "div#:a",
            "div#:a",
            "div#:a",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~~~~~~~~~",
            "a~~~~~~~~~",
            "~~~~~~~~~~",
            "a~~~~~~~~~",
            "~~~~~~~~~~",
            "a~~~~~~~~~",
            "~~~~~~~~~~",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("rows-defined", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-rows")
        h.createElements({
            "div#:a",
            "div#:a",
            "div#:a",
            "div#:a",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~~~~~~~~~",
            "~~~~~~~~~~",
            "~~~~~~~~~~",
            "a~~~~~~~~~",
            "~~~~~~~~~~",
            "~~~~~~~~~~",
            "a~~~~~~~~~",
            "~~~~~~~~~~",
            "~~~~~~~~~~",
            "a~~~~~~~~~",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("column-gap-pct", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("column-gap-pct")
        h.createElements({
            "div#.row-defined:a",
            "div#.row-defined:a",
            "div#.row-defined:a",
            "div#.row-defined:a",
            "div#.row-defined:a",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~!a!a!a!a",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("column-gap-ch", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("column-gap-ch")
        h.createElements({
            "div#.row-defined:a",
            "div#.row-defined:a",
            "div#.row-defined:a",
            "div#.row-defined:a",
            "div#.row-defined:a",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~!a!a!a!a",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("row-gap-pct", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("row-gap-pct")
        h.createElements({
            "div#:a",
            "div#:a",
            "div#:a",
            "div#:a",
            "div#:a",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~~~~~~~~~",
            "!!!!!!!!!!",
            "a~~~~~~~~~",
            "!!!!!!!!!!",
            "a~~~~~~~~~",
            "!!!!!!!!!!",
            "a~~~~~~~~~",
            "!!!!!!!!!!",
            "a~~~~~~~~~",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("row-gap-ch", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("row-gap-ch")
        h.createElements({
            "div#:a",
            "div#:a",
            "div#:a",
            "div#:a",
            "div#:a",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~~~~~~~~~",
            "!!!!!!!!!!",
            "a~~~~~~~~~",
            "!!!!!!!!!!",
            "a~~~~~~~~~",
            "!!!!!!!!!!",
            "a~~~~~~~~~",
            "!!!!!!!!!!",
            "a~~~~~~~~~",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("basic grid works", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#:a",
            "div#:a",
            "div#:a",
            "div#:a",
            "div#:a",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~~~~~~~~~",
            "a~~~~~~~~~",
            "a~~~~~~~~~",
            "a~~~~~~~~~",
            "a~~~~~~~~~",
            "          ",
            "          ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("basic grid works", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#.row-defined:a",
            "div#.row-defined:a",
            "div#:a",
            "div#:a",
            "div#:a",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~~~~a~~~~",
            "a~~~~a~~~~",
            "a~~~~!!!!!",
            "          ",
            "          ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("row-defined 1", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#.row-defined-range:a",
            "div#.row-defined-range:b",
            "div#:c",
            "div#:d",
            "div#:e",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~~~~b~~~~",
            "~~~~~~~~~~",
            "c~~~~d~~~~",
            "e~~~~!!!!!",
            "          ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("row-defined 2", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#:c",
            "div#:d",
            "div#.row-defined-range:a",
            "div#.row-defined-range:b",
            "div#:e",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~~~~b~~~~",
            "~~~~~~~~~~",
            "c~~~~d~~~~",
            "e~~~~!!!!!",
            "          ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("row-defined 3", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#:c",
            "div#:d",
            "div#.row-span:a",
            "div#.row-span:b",
            "div#:e",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "c~~~~~~~~~",
            "d~~~~~~~~~",
            "a~~~~~~~~~",
            "~~~~~~~~~~",
            "b~~~~~~~~~",
            "~~~~~~~~~~",
            "e~~~~~~~~~",
            "          ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("row-defined 4", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#:c",
            "div#.row-defined-range-span:d",
            "div#.row-defined-range-span:a",
            "div#.row-defined-range-span:b",
            "div#:e",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "c~~~e~~!!!",
            "d~~~a~~b~~",
            "~~~~~~~~~~",
            "~~~~~~~~~~",
            "          ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("col-defined 1", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#.column-defined-range:a",
            "div#.column-defined-range:b",
            "div#:c",
            "div#:d",
            "div#:e",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~~~~~~~~~",
            "b~~~~~~~~~",
            "c~~~~d~~~~",
            "e~~~~!!!!!",
            "          ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("col-defined 2", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#:c",
            "div#.column-defined-range:a",
            "div#.column-defined-range:b",
            "div#:d",
            "div#:e",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "c~~~~!!!!!",
            "a~~~~~~~~~",
            "b~~~~~~~~~",
            "d~~~~e~~~~",
            "          ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("col-defined 3", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#:c",
            "div#:d",
            "div#.column-defined-range:a",
            "div#.column-defined-range:b",
            "div#:e",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "c~~~~d~~~~",
            "a~~~~~~~~~",
            "b~~~~~~~~~",
            "e~~~~!!!!!",
            "          ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("col-defined 4", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#:c",
            "div#:d",
            "div#.column-defined-range-span:a",
            "div#.column-defined-range-span:b",
            "div#:e",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "c~d~a~~~~~",
            "!!!!b~~~~~",
            "e~!!!!!!!!",
            "          ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("col-span", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#:c",
            "div#:d",
            "div#.column-span:b",
            "div#.column-span:a",
            "div#:e",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "c~~~~d~~~~",
            "b~~~~~~~~~",
            "a~~~~~~~~~",
            "e~~~~!!!!!",
            "          ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
    it("col-defined 5", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#:c",
            "div#:d",
            "div#.column-defined-range-span:b",
            "div#.column-defined-range-span-2:a",
            "div#:e",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "c~d~b~~~~~",
            "!!a~~~~~e~",
            "          ",
            "          ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
    end)
end)
