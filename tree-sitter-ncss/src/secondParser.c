#define NULL 0
#include <stdint.h>
typedef struct TSLanguage TSLanguage;
typedef struct TSParser TSParser;
typedef struct TSTree TSTree;
typedef struct {
    uint32_t row;
    uint32_t column;
} TSPoint;

typedef struct TSNode {
    uint32_t context[4];
    const void* id;
    const TSTree* tree;
} TSNode;

TSNode ts_tree_root_node(TSTree*);

struct TSParser* ts_parser_new();
void ts_parser_set_language(TSParser*, const TSLanguage*);
TSTree* ts_parser_parse_string(
    TSParser* self, const TSTree* old_tree, const char* string, uint32_t length
);
void ts_tree_delete(TSTree*);
void ts_parser_delete(TSParser*);

const char* ts_node_type(TSNode);

const TSLanguage* tree_sitter_ncss(void);

TSTree* tree_sitter_ncss_parse_2(const char* source_code, uint32_t charLen) {
    // Create a parser.
    TSParser* parser = ts_parser_new();

    // Set the parser's language (JSON in this case).
    ts_parser_set_language(parser, tree_sitter_ncss());

    // Build a syntax tree based on source code stored in a string.
    TSTree* tree = ts_parser_parse_string(parser, NULL, source_code, charLen);
    ts_parser_delete(parser);
    return tree;
}
TSNode tsTreeRootNode(TSTree* tree) {
    return ts_tree_root_node(tree);
}

void tsTreeDelete(TSTree* tree) {
    ts_tree_delete(tree);
}
void tsParserDelete(TSParser* parser) {
    ts_parser_delete(parser);
}
const char* tsNodeType(TSNode node) {
    return ts_node_type(node);
}

int ts_node_child_count(TSNode node);
int tsNodeChildCount(TSNode node) {
    return ts_node_child_count(node);
}

char* ts_node_string(TSNode node);
char* tsNodeString(TSNode node) {
    return ts_node_string(node);
}

TSPoint ts_node_end_point(TSNode node);
TSPoint tsNodeEndPoint(TSNode node) {
    return ts_node_end_point(node);
}

TSPoint ts_node_start_point(TSNode node);
TSPoint tsNodeStartPoint(TSNode node) {
    return ts_node_start_point(node);
}

TSNode ts_node_child(TSNode, uint32_t);
TSNode tsNodeChild(TSNode node, uint32_t i) {
    return ts_node_child(node, i);
}
