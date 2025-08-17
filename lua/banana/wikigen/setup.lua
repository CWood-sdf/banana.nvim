local dir = vim.fn.getcwd()

package.path = package.path .. ";" .. dir .. "/lua/?.lua"

require("banana.wikigen.ast").run()

print("yuhh\n")
