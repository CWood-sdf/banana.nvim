local ffi = require("ffi")

ffi.cdef([[

typedef struct TSTree TSTree;
typedef struct TSParser TSParser;

typedef struct TSNode {
    uint32_t context[4];
    const void* id;
    const TSTree* tree;
} TSNode;
typedef struct TSLanguage TSLanguage;
typedef struct TSPoint TSPoint;

TSTree* tree_sitter_ncss_parse_2(const char* source_code, uint32_t charLen);
TSNode tsTreeRootNode(TSTree* tree);

void tsTreeDelete(TSTree* tree);
int tsNodeChildCount(TSNode);

const char* tsNodeType(TSNode);

char* tsNodeString(TSNode node);
TSPoint tsNodeStartPoint(TSNode);
]])

local parser = ffi.load(
    "/home/christopher-wood/projects/banana.nvim/tree-sitter-ncss/src/ncssParser2.so")

local src = [[
      nml {

      }
]]

-- local buf = ffi.new("char[?]", #src + 1)

local start = vim.loop.hrtime()
local parsed = parser.tree_sitter_ncss_parse_2(src, #src)
local root = parser.tsTreeRootNode(parsed)
print((vim.loop.hrtime() - start) / 1e6 .. "ms")
print(ffi.string(parser.tsNodeString(root)))

parser.tsTreeDelete(parsed)
