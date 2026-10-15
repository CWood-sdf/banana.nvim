describe("Entity whitespace", function ()
    it("preserves word separation around entities in block content", function ()
        local inst = require("banana.instance").emptyInstance()
        inst:useNml(nml([[
<nml>
<head></head>
<body>
<div>Hello &amp; World</div>
<div>Hello &#38; World</div>
<div>Hello &lt; World</div>
</body>
</nml>
        ]]))
        inst:open()
        local lines = vim.api.nvim_buf_get_lines(inst:getBufnr(), 0, -1, false)
        assert.equals("Hello & World", lines[1])
        assert.equals("Hello & World", lines[2])
        assert.equals("Hello < World", lines[3])
        inst:close()
    end)
end)
