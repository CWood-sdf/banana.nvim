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
    it("speed test", function ()
        local start = vim.fn.reltime()
        for i = 1, 100 do
            local inst = require("banana.instance").emptyInstance()
            inst:useNml(code)
            inst.DEBUG = false
            inst.stripRight = false
            inst:open()
            inst:querySelectorAll(".grid")[1]:addClass("grid-template-both")
            h.createElements({
                "div#a:a",
                "div#b.column-defined-2:b",
                "div#c.column-defined-2:c",
                "div#d:d",
                "div#e:e",
                "div#f:f",
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
            h.assertGridBoundsMatch(expectedMap, inst)
        end
        print(vim.fn.reltimestr(vim.fn.reltime(start)))
    end)
    it("cursor weirdness", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-both")
        h.createElements({
            "div#a:a",
            "div#b.column-defined-2:b",
            "div#c.column-defined-2:c",
            "div#d:d",
            "div#e:e",
            "div#f:f",
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
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("both-templates-mixed-row-col-precedence", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-both-mixed")
        h.createElements({
            "div#a:a",
            "div#b:b",
            "div#c.row-defined.column-defined:c",
            "div#d:d",
            "div#e:e",
            "div#f:f",
            "div#g:g",
            "div#h:h",
            "div#i:i",
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
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("both-templates-mixed-row-col-precedence-2", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-both-mixed")
        h.createElements({
            "div#a:a",
            "div#b:b",
            "div#c.row-defined.column-defined-2:c",
            "div#d.row-defined:d",
            "div#e.row-defined:e",
            "div#f:f",
            "div#g:g",
            "div#h:h",
            "div#i:i",
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
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("both-templates-mixed-row-col-precedence-3", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-both-mixed")
        h.createElements({
            "div#a:a",
            "div#b:b",
            "div#c.row-defined.column-defined-2:c",
            "div#j.row-defined.column-defined-2:j",
            "div#d.row-defined:d",
            "div#e.row-defined:e",
            "div#f:f",
            "div#g:g",
            "div#h:h",
            "div#i:i",
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
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("both-templates-mixed-row-col-precedence-z", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-both-mixed")
        h.createElements({
            "div#a:a",
            "div#b:b",
            "div#c.row-defined.column-defined-2.z:c",
            "div#j.row-defined.column-defined-2:j",
            "div#d.row-defined:d",
            "div#e.row-defined:e",
            "div#f:f",
            "div#g:g",
            "div#h:h",
            "div#i:i",
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
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("both-templates-mixed", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-both-mixed")
        h.createElements({
            "div#a:a",
            "div#b:b",
            "div#c:c",
            "div#d:d",
            "div#e:e",
            "div#f:f",
            "div#g:g",
            "div#h:h",
            "div#i:i",
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
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("both-templates", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-both")
        h.createElements({
            "div#a:a",
            "div#b:b",
            "div#c:c",
            "div#d:d",
            "div#e:e",
            "div#f:f",
            "div#g:g",
            "div#h:h",
            "div#i:i",
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
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("columns-mixed", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-columns-mixed")
        h.createElements({
            "div#a:a",
            "div#b:b",
            "div#c:c",
            "div#d:d",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "ab~~c~~d~~",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("columns-defined", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-columns")
        h.createElements({
            "div#a:a",
            "div#b:b",
            "div#c:c",
            "div#d:d",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~b~c~d~!!",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("rows-mixed", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-rows-mixed")
        h.createElements({
            "div#a:a",
            "div#b:b",
            "div#c:c",
            "div#d:d",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~~~~~~~~~",
            "b~~~~~~~~~",
            "~~~~~~~~~~",
            "c~~~~~~~~~",
            "~~~~~~~~~~",
            "d~~~~~~~~~",
            "~~~~~~~~~~",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("rows-defined", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("grid-template-rows")
        h.createElements({
            "div#a:a",
            "div#b:b",
            "div#c:c",
            "div#d:d",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~~~~~~~~~",
            "~~~~~~~~~~",
            "~~~~~~~~~~",
            "b~~~~~~~~~",
            "~~~~~~~~~~",
            "~~~~~~~~~~",
            "c~~~~~~~~~",
            "~~~~~~~~~~",
            "~~~~~~~~~~",
            "d~~~~~~~~~",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("column-gap-pct", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("column-gap-pct")
        h.createElements({
            "div#a.row-defined:a",
            "div#b.row-defined:b",
            "div#c.row-defined:c",
            "div#d.row-defined:d",
            "div#e.row-defined:e",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~!b!c!d!e",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("column-gap-ch", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("column-gap-ch")
        h.createElements({
            "div#a.row-defined:a",
            "div#b.row-defined:b",
            "div#c.row-defined:c",
            "div#d.row-defined:d",
            "div#e.row-defined:e",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~!b!c!d!e",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("row-gap-pct", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("row-gap-pct")
        h.createElements({
            "div#a:a",
            "div#b:b",
            "div#c:c",
            "div#d:d",
            "div#e:e",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~~~~~~~~~",
            "!!!!!!!!!!",
            "b~~~~~~~~~",
            "!!!!!!!!!!",
            "c~~~~~~~~~",
            "!!!!!!!!!!",
            "d~~~~~~~~~",
            "!!!!!!!!!!",
            "e~~~~~~~~~",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("row-gap-ch", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        inst:querySelectorAll(".grid")[1]:addClass("row-gap-ch")
        h.createElements({
            "div#a:a",
            "div#b:b",
            "div#c:c",
            "div#d:d",
            "div#e:e",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~~~~~~~~~",
            "!!!!!!!!!!",
            "b~~~~~~~~~",
            "!!!!!!!!!!",
            "c~~~~~~~~~",
            "!!!!!!!!!!",
            "d~~~~~~~~~",
            "!!!!!!!!!!",
            "e~~~~~~~~~",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("basic grid works", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#a:a",
            "div#b:b",
            "div#c:c",
            "div#d:d",
            "div#e:e",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~~~~~~~~~",
            "b~~~~~~~~~",
            "c~~~~~~~~~",
            "d~~~~~~~~~",
            "e~~~~~~~~~",
            "          ",
            "          ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("basic grid works", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#a.row-defined:a",
            "div#b.row-defined:b",
            "div#c:c",
            "div#d:d",
            "div#e:e",
        }, inst, inst:querySelectorAll(".grid")[1])

        local expectedMap = {
            "          ",
            "a~~~~b~~~~",
            "c~~~~d~~~~",
            "e~~~~!!!!!",
            "          ",
            "          ",
        }
        inst:forceRerender()
        h.assertBgMapsMatch(h.bufToBgMap(inst.bufnr), expectedMap)
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("row-defined 1", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#a.row-defined-range:a",
            "div#b.row-defined-range:b",
            "div#c:c",
            "div#d:d",
            "div#e:e",
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
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("row-defined 2", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#c:c",
            "div#d:d",
            "div#a.row-defined-range:a",
            "div#b.row-defined-range:b",
            "div#e:e",
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
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("row-defined 3", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#c:c",
            "div#d:d",
            "div#a.row-span:a",
            "div#b.row-span:b",
            "div#e:e",
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
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("row-defined 4", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#c:c",
            "div#d.row-defined-range-span:d",
            "div#a.row-defined-range-span:a",
            "div#b.row-defined-range-span:b",
            "div#e:e",
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
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("col-defined 1", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#a.column-defined-range:a",
            "div#b.column-defined-range:b",
            "div#c:c",
            "div#d:d",
            "div#e:e",
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
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("col-defined 2", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#c:c",
            "div#a.column-defined-range:a",
            "div#b.column-defined-range:b",
            "div#d:d",
            "div#e:e",
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
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("col-defined 3", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#c:c",
            "div#d:d",
            "div#a.column-defined-range:a",
            "div#b.column-defined-range:b",
            "div#e:e",
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
        h.assertGridBoundsMatch(expectedMap, inst, "~", function (k, v)
            if k == "d" then
                v.bottomY = 3
            end
            return v
        end)
    end)
    it("col-defined 4", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#c:c",
            "div#d:d",
            "div#a.column-defined-range-span:a",
            "div#b.column-defined-range-span:b",
            "div#e:e",
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
        h.assertGridBoundsMatch(expectedMap, inst)
    end)
    it("col-span", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#c:c",
            "div#d:d",
            "div#b.column-span:b",
            "div#a.column-span:a",
            "div#e:e",
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
        h.assertGridBoundsMatch(expectedMap, inst, "~", function (k, v)
            if k == "d" then
                v.bottomY = 3
            end
            return v
        end)
    end)
    it("col-defined 5", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(code)
        inst.DEBUG = false
        inst.stripRight = false
        inst:open()
        h.createElements({
            "div#c:c",
            "div#d:d",
            "div#b.column-defined-range-span:b",
            "div#a.column-defined-range-span-2:a",
            "div#e:e",
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
        h.assertGridBoundsMatch(expectedMap, inst, "~", function (k, v)
            if k == "b" then
                v.bottomY = 3
            end
            return v
        end)
    end)
end)
