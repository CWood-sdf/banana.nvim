local ffi = require('ffi')
local M = {}

--- CDEFS
pcall(function()
    ffi.cdef([[
        typedef struct TSTree TSTree;
        typedef struct TSParser TSParser;

        typedef struct TSNode {
            uint32_t context[4];
            const void* id;
            const TSTree* tree;
        } TSNode;
        typedef struct TSLanguage TSLanguage;
        typedef struct TSPoint {
            uint32_t row;
            uint32_t column;
        } TSPoint;

        TSTree* tree_sitter_ncss_parse_2(const char* source_code, uint32_t charLen);
        TSNode tsTreeRootNode(TSTree* tree);

        void tsTreeDelete(TSTree* tree);
        int tsNodeChildCount(TSNode);
        TSNode tsNodeChild(TSNode, uint32_t);

        const char* tsNodeType(TSNode);

        char* tsNodeString(TSNode node);
        TSPoint tsNodeStartPoint(TSNode);
        TSPoint tsNodeEndPoint(TSNode);
    ]])
end)

local parser = nil; --ffi.load("/home/christopher-wood/projects/banana.nvim/tree-sitter-ncss/src/ncssParser2.so")
for _, path in ipairs(vim.api.nvim_list_runtime_paths()) do
    local ok, c = pcall(ffi.load, path .. "/bin/ncssParser2.so")
    if ok then
        parser = c
    end
end
if parser == nil then
    error("Could not find ncssParser2.so")
end

---@class (exact) Banana.Ncss.FFINode
---@field node userdata
---@field _children Banana.Ncss.FFINode[]
---@field tree Banana.Ncss.FFITree
local Node = {

}
---@param node userdata
---@param tree Banana.Ncss.FFITree
---@return Banana.Ncss.FFINode
function Node:new(node, tree)
    ---@type Banana.Ncss.FFINode
    local ret = {
        node = node,
        _children = {},
        tree = tree,
    }
    setmetatable(ret, {
        __index = Node,
    })
    return ret
end

---@return string
function Node:type()
    return ffi.string(parser.tsNodeType(self.node))
end

---@return number
function Node:child_count()
    return parser.tsNodeChildCount(self.node)
end

---@param i number
---@return Banana.Ncss.FFINode?
function Node:child(i)
    if i >= self:child_count() then
        return nil
    end
    if self._children[i + 1] ~= nil then
        return self._children[i + 1]
    end
    self._children[i + 1] = Node:new(parser.tsNodeChild(self.node, i), self.tree)
    return self._children[i + 1]
end

---@return number, number
function Node:end_()
    local s = parser.tsNodeEndPoint(self.node)
    return s.row, s.column
end

---@return number, number
function Node:start()
    local s = parser.tsNodeStartPoint(self.node)
    return s.row, s.column
end

---@class (exact) Banana.Ncss.FFITree
---@field tree userdata
---@field rootNode Banana.Ncss.FFINode
local Tree = {

}

---@param src string
---@return Banana.Ncss.FFITree
function Tree:new(src)
    local parsed = parser.tree_sitter_ncss_parse_2(src, #src)
    local root = parser.tsTreeRootNode(parsed)
    ---@type Banana.Ncss.FFITree
    local ret = {
        tree = parsed,
        ---@diagnostic disable-next-line: missing-parameter
        rootNode = Node:new(root),
    }
    ret.rootNode.tree = ret
    setmetatable(ret, {
        __index = Tree,
        __gc = function()
            parser.tsTreeDelete(parsed)
        end
    })
    return ret
end

---@return Banana.Ncss.FFINode
function Tree:root()
    return self.rootNode
end

-- local src = [[
--       nml {
--
--       }
-- ]]
--
-- -- local buf = ffi.new("char[?]", #src + 1)
--
-- local start = vim.uv.hrtime()
-- local parsed = parser.tree_sitter_ncss_parse_2(src, #src)
-- local root = parser.tsTreeRootNode(parsed)
-- print((vim.uv.hrtime() - start) / 1e6 .. "ms")
-- print(ffi.string(parser.tsNodeString(root)))
--
-- parser.tsTreeDelete(parsed)
---@param src string
---@return Banana.Ncss.FFITree
function M.getTree(src)
    return Tree:new(src)
end

return M
