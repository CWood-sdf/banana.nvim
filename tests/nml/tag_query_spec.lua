describe("Instance tag queries", function ()
    it("returns all matches, including empty and multiple results", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(nml([[
<nml>
<head></head>
<body>
<div>first</div>
<div>second</div>
<span>single</span>
</body>
</nml>
        ]]))
        inst:open()
        local divs = inst:getElementsByTagName("div")
        assert.equals(2, #divs)
        assert.equals("first", divs[1]:getTextContent())
        assert.equals("second", divs[2]:getTextContent())
        divs[2]:setTextContent("updated")
        inst:forceRerender()
        local lines = vim.api.nvim_buf_get_lines(
            inst:getBufnr(), 0, -1, false)
        assert.is_truthy(table.concat(lines, "\n"):find("updated", 1, true))
        assert.equals(1, #inst:getElementsByTagName("span"))
        assert.same({}, inst:getElementsByTagName("canvas"))
        inst:close()
    end)
end)
