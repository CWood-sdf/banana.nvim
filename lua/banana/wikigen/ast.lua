local gen = require("banana.wikigen.gendoc")

local M = {}

function M.run()
    gen.useFile("lua/banana/nml/ast.lua")

    local stuff = gen.getFns("^function M.Ast:\\(_\\)\\@!", "M.Ast:(%w*)")

    gen.genDocsFor(stuff, "wiki/Ast.md", {

        header = [[
The AST class is the second of two API surfaces that you will use for any interaction with the dom tree in banana (the other one being Instance).

Not all of the browser api functions are implemented, but what I have now is hopefully enough for the API to be usable.
If there are any missing features of the browser API that you would really like ported to banana, submit an issue or a pr.

]],
    })
end

return M
