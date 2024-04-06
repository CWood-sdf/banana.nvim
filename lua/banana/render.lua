-- This file is entirely for turning a BananaAst into a renderable highlight/line array.

local M = {}

---@class Banana.Instance
---@field winid? number
---@field bufnr? number
---@field bufname string
---@field filetype string
---@field bufName string
---@field parser Banana.Parser
---@field highlightNs number
local Instance = {}

---@class Banana.Word
---@field word string
---@field style? table

---@param ast Banana.Ast
---@return Banana.Word[][]
function Instance:virtualRender(ast)
	---TODO: The entire tag system needs to be reworked so that the tag renderers take in an AST and return a list of words.
	---@type Banana.Word[][]
	local ret = {}
	if require("banana.nml.tags").tagExists(ast.tag) then
		local tag = require("banana.nml.tags").makeTag(ast.tag)
		local rendered = tag:render(ast)
		for _, line in ipairs(rendered) do
			table.insert(ret, line)
		end
	end
	return ret
end

---@return Banana.Instance
function Instance.new(filename, bufferName)
	local parser = require("banana.nml.parser").fromFile(filename)
	if parser == nil then
		error("Failed to open nml file")
	end
	---@type Banana.Instance
	local inst = {
		bufname = bufferName,
		filetype = "banana",
		bufName = filename,
		highlightNs = vim.api.nvim_create_namespace("banana"),
		parser = parser,
	}
	local instance = setmetatable(inst, { __index = Instance })
	return instance
end

function Instance:useBuffer(bufnr)
	self.bufnr = bufnr
end
function Instance:useWindow(winid)
	self.winid = winid
end

function Instance:render()
	local startTime = vim.loop.hrtime()
	local ast = self.parser:parse()
	local endTime = vim.loop.hrtime()
	local astTime = endTime - startTime
	if ast == nil then
		error("Failed to parse")
	end
	require("banana.nml.tags").cleanAst(ast)
	startTime = vim.loop.hrtime()
	local stuffToRender = self:virtualRender(ast)
	endTime = vim.loop.hrtime()
	local renderTime = endTime - startTime
	if self.bufnr == nil or not vim.api.nvim_buf_is_valid(self.bufnr) then
		self.bufnr = vim.api.nvim_create_buf(false, true)
		vim.api.nvim_buf_set_name(self.bufnr, self.bufname)
		vim.api.nvim_set_option_value("filetype", self.filetype, { buf = self.bufnr })
	end
	if self.winid == nil or not vim.api.nvim_win_is_valid(self.winid) then
		self.winid = vim.api.nvim_open_win(0, true, {
			relative = "editor",
			width = 60,
			height = 20,
			row = 5,
			col = 5,
			style = "minimal",
			focusable = false,
			zindex = 1000,
		})
		vim.api.nvim_win_set_buf(self.winid, self.bufnr)
		vim.api.nvim_set_current_win(self.winid)
	end
	local lines = {
		astTime / 1e9 .. "s to parse",
		renderTime / 1e9 .. "s to render",
	}
	for _, line in ipairs(stuffToRender) do
		local lineStr = ""
		for _, word in ipairs(line) do
			lineStr = lineStr .. word.word
		end
		table.insert(lines, lineStr)
	end
	vim.api.nvim_buf_set_lines(self.bufnr, 0, -1, false, lines)
end

function Instance:reset()
	self.parser:reset()
end

---@param filename string
---@param bufferName string
---@return Banana.Instance
function M.newInstance(filename, bufferName)
	local instance = Instance.new(filename, bufferName)
	return instance
end

return M
