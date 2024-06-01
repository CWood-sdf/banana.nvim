local M = {}
local instance = nil
local render = require('banana.render')

M.yeet = function()
	if instance == nil then
		instance = render.newInstance(os.getenv("HOME") .. "/projects/banana.nvim/test.nml",
			"test.nml")
	end
	-- local filename = os.getenv("HOME") .. '/projects/banana.nvim/test.nml'
	instance:render()

	-- local file = io.open(os.getenv("HOME") .. "/projects/banana.nvim/log", "w")
	-- if file == nil then
	-- 	print("Failed to open log file")
	-- 	return
	-- end
	-- local parser = require('banana.nml.parser').fromFile(os.getenv("HOME") .. '/projects/banana.nvim/test.nml')
	-- if parser == nil then
	--     print('Failed to open nml file')
	--     return
	-- end
	-- local ast = parser:parse()
	-- if ast == nil then
	--     print('Failed to parse')
	--     return
	-- end
	-- file:write(vim.inspect(ast))

	-- file:close()
end

return M
