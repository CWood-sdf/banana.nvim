local M = {}
local instance = nil
local render = require('banana.render')

M.yeet = function()
	if instance == nil then
		instance = render.newInstance("test2", "asdf")
		instance.DEBUG = true
	end
	instance.showPerf = true
	-- local filename = os.getenv("HOME") .. '/projects/banana.nvim/test.nml'
	instance:open()

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

function M.spam()
	local testFile = [[
			.asdf {
				hl-bg: #0000ff;
			}
		]]
	local startTime = vim.uv.hrtime()
	for _ = 1, 1000 do
		local _ = require('banana.ncss.parser').parseTextSlow(testFile)
	end
	vim.notify((vim.uv.hrtime() - startTime) / 1e6 .. "ms\n")
	startTime = vim.uv.hrtime()
	for _ = 1, 1000 do
		local _ = require('banana.ncss.parser').parseText(testFile)
	end
	vim.notify((vim.uv.hrtime() - startTime) / 1e6 .. "ms\n")
end

function M.getInstallDir()
	local ret = ""

	for _, v in ipairs(vim.api.nvim_list_runtime_paths()) do
		if v:match("banana.nvim$") ~= nil then
			ret = v
		end
	end
	return ret
end

function M.initTsParsers()
	local parser_config = require("nvim-treesitter.parsers").get_parser_configs()
	vim.treesitter.language.register("nml", "nml")
	---@diagnostic disable-next-line: inject-field
	parser_config.nml = {
		install_info = {
			url = M.getInstallDir() .. "/tree-sitter-nml",
			files = { "src/parser.c" },
			branch = "main",
			generate_requires_npm = false,
			requires_generate_from_grammar = false,
		},
		filetype = "nml",
	}
	---@diagnostic disable-next-line: inject-field
	parser_config.ncss = {
		install_info = {
			url = M.getInstallDir() .. "/tree-sitter-ncss",
			files = { "src/parser.c", "src/scanner.c" },
			branch = "main",
			generate_requires_npm = false,
			requires_generate_from_grammar = false,
		},
		filetype = "ncss",
	}
	vim.treesitter.language.register("ncss", "ncss")
end

return M
