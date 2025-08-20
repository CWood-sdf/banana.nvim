local dir = vim.fn.getcwd()

package.path = package.path .. ";" .. dir .. "/lua/?.lua"

require("banana.wikigen.ast").run()
-- require("banana.wikigen.instance").run()
require("banana.wikigen.entities").run()

print("yuhh\n")
