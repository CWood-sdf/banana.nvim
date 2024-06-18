#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 352
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 116
#define ALIAS_COUNT 9
#define TOKEN_COUNT 60
#define EXTERNAL_TOKEN_COUNT 3
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 17

enum {
  anon_sym_ATimport = 1,
  anon_sym_COMMA = 2,
  anon_sym_SEMI = 3,
  anon_sym_ATmedia = 4,
  anon_sym_ATcharset = 5,
  anon_sym_ATnamespace = 6,
  anon_sym_ATkeyframes = 7,
  aux_sym_keyframes_statement_token1 = 8,
  anon_sym_LBRACE = 9,
  anon_sym_RBRACE = 10,
  sym_from = 11,
  sym_to = 12,
  anon_sym_ATsupports = 13,
  sym_nesting_selector = 14,
  anon_sym_STAR = 15,
  anon_sym_DOT = 16,
  anon_sym_COLON_COLON = 17,
  anon_sym_POUND = 18,
  anon_sym_LBRACK = 19,
  anon_sym_EQ = 20,
  anon_sym_TILDE_EQ = 21,
  anon_sym_CARET_EQ = 22,
  anon_sym_PIPE_EQ = 23,
  anon_sym_STAR_EQ = 24,
  anon_sym_DOLLAR_EQ = 25,
  anon_sym_RBRACK = 26,
  anon_sym_GT = 27,
  anon_sym_TILDE = 28,
  anon_sym_PLUS = 29,
  anon_sym_PIPE = 30,
  anon_sym_LPAREN = 31,
  anon_sym_RPAREN = 32,
  anon_sym_COLON = 33,
  sym_important = 34,
  anon_sym_LPAREN2 = 35,
  anon_sym_and = 36,
  anon_sym_or = 37,
  anon_sym_not = 38,
  anon_sym_only = 39,
  anon_sym_selector = 40,
  aux_sym_color_value_token1 = 41,
  anon_sym_SQUOTE = 42,
  aux_sym_string_value_token1 = 43,
  anon_sym_DQUOTE = 44,
  aux_sym_string_value_token2 = 45,
  sym_boolean_value = 46,
  aux_sym_integer_value_token1 = 47,
  aux_sym_float_value_token1 = 48,
  sym_unit = 49,
  anon_sym_DASH = 50,
  anon_sym_SLASH = 51,
  sym_identifier = 52,
  sym_at_keyword = 53,
  sym_js_comment = 54,
  sym_comment = 55,
  sym_plain_value = 56,
  sym__descendant_operator = 57,
  sym__pseudo_class_selector_colon = 58,
  sym___error_recovery = 59,
  sym_stylesheet = 60,
  sym_import_statement = 61,
  sym_media_statement = 62,
  sym_charset_statement = 63,
  sym_namespace_statement = 64,
  sym_keyframes_statement = 65,
  sym_keyframe_block_list = 66,
  sym_keyframe_block = 67,
  sym_supports_statement = 68,
  sym_postcss_statement = 69,
  sym_at_rule = 70,
  sym_rule_set = 71,
  sym_selectors = 72,
  sym_block = 73,
  sym__selector = 74,
  sym_universal_selector = 75,
  sym_class_selector = 76,
  sym_pseudo_class_selector = 77,
  sym_pseudo_element_selector = 78,
  sym_id_selector = 79,
  sym_attribute_selector = 80,
  sym_child_selector = 81,
  sym_descendant_selector = 82,
  sym_sibling_selector = 83,
  sym_adjacent_sibling_selector = 84,
  sym_namespace_selector = 85,
  sym_pseudo_class_arguments = 86,
  sym_pseudo_element_arguments = 87,
  sym_declaration = 88,
  sym_last_declaration = 89,
  sym__query = 90,
  sym_feature_query = 91,
  sym_parenthesized_query = 92,
  sym_binary_query = 93,
  sym_unary_query = 94,
  sym_selector_query = 95,
  sym__value = 96,
  sym_parenthesized_value = 97,
  sym_color_value = 98,
  sym_string_value = 99,
  sym_integer_value = 100,
  sym_float_value = 101,
  sym_grid_value = 102,
  sym_call_expression = 103,
  sym_arguments = 104,
  sym_binary_expression = 105,
  aux_sym_stylesheet_repeat1 = 106,
  aux_sym_import_statement_repeat1 = 107,
  aux_sym_keyframe_block_list_repeat1 = 108,
  aux_sym_postcss_statement_repeat1 = 109,
  aux_sym_selectors_repeat1 = 110,
  aux_sym_block_repeat1 = 111,
  aux_sym_pseudo_class_arguments_repeat1 = 112,
  aux_sym_declaration_repeat1 = 113,
  aux_sym_grid_value_repeat1 = 114,
  aux_sym_arguments_repeat1 = 115,
  alias_sym_class_name = 116,
  alias_sym_feature_name = 117,
  alias_sym_function_name = 118,
  alias_sym_id_name = 119,
  alias_sym_keyframes_name = 120,
  alias_sym_keyword_query = 121,
  alias_sym_namespace_name = 122,
  alias_sym_property_name = 123,
  alias_sym_tag_name = 124,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_ATimport] = "@import",
  [anon_sym_COMMA] = ",",
  [anon_sym_SEMI] = ";",
  [anon_sym_ATmedia] = "@media",
  [anon_sym_ATcharset] = "@charset",
  [anon_sym_ATnamespace] = "@namespace",
  [anon_sym_ATkeyframes] = "@keyframes",
  [aux_sym_keyframes_statement_token1] = "at_keyword",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym_from] = "from",
  [sym_to] = "to",
  [anon_sym_ATsupports] = "@supports",
  [sym_nesting_selector] = "nesting_selector",
  [anon_sym_STAR] = "*",
  [anon_sym_DOT] = ".",
  [anon_sym_COLON_COLON] = "::",
  [anon_sym_POUND] = "#",
  [anon_sym_LBRACK] = "[",
  [anon_sym_EQ] = "=",
  [anon_sym_TILDE_EQ] = "~=",
  [anon_sym_CARET_EQ] = "^=",
  [anon_sym_PIPE_EQ] = "|=",
  [anon_sym_STAR_EQ] = "*=",
  [anon_sym_DOLLAR_EQ] = "$=",
  [anon_sym_RBRACK] = "]",
  [anon_sym_GT] = ">",
  [anon_sym_TILDE] = "~",
  [anon_sym_PLUS] = "+",
  [anon_sym_PIPE] = "|",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COLON] = ":",
  [sym_important] = "important",
  [anon_sym_LPAREN2] = "(",
  [anon_sym_and] = "and",
  [anon_sym_or] = "or",
  [anon_sym_not] = "not",
  [anon_sym_only] = "only",
  [anon_sym_selector] = "selector",
  [aux_sym_color_value_token1] = "color_value_token1",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_string_value_token1] = "string_value_token1",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_value_token2] = "string_value_token2",
  [sym_boolean_value] = "boolean_value",
  [aux_sym_integer_value_token1] = "integer_value_token1",
  [aux_sym_float_value_token1] = "float_value_token1",
  [sym_unit] = "unit",
  [anon_sym_DASH] = "-",
  [anon_sym_SLASH] = "/",
  [sym_identifier] = "attribute_name",
  [sym_at_keyword] = "at_keyword",
  [sym_js_comment] = "js_comment",
  [sym_comment] = "comment",
  [sym_plain_value] = "plain_value",
  [sym__descendant_operator] = "_descendant_operator",
  [sym__pseudo_class_selector_colon] = ":",
  [sym___error_recovery] = "__error_recovery",
  [sym_stylesheet] = "stylesheet",
  [sym_import_statement] = "import_statement",
  [sym_media_statement] = "media_statement",
  [sym_charset_statement] = "charset_statement",
  [sym_namespace_statement] = "namespace_statement",
  [sym_keyframes_statement] = "keyframes_statement",
  [sym_keyframe_block_list] = "keyframe_block_list",
  [sym_keyframe_block] = "keyframe_block",
  [sym_supports_statement] = "supports_statement",
  [sym_postcss_statement] = "postcss_statement",
  [sym_at_rule] = "at_rule",
  [sym_rule_set] = "rule_set",
  [sym_selectors] = "selectors",
  [sym_block] = "block",
  [sym__selector] = "_selector",
  [sym_universal_selector] = "universal_selector",
  [sym_class_selector] = "class_selector",
  [sym_pseudo_class_selector] = "pseudo_class_selector",
  [sym_pseudo_element_selector] = "pseudo_element_selector",
  [sym_id_selector] = "id_selector",
  [sym_attribute_selector] = "attribute_selector",
  [sym_child_selector] = "child_selector",
  [sym_descendant_selector] = "descendant_selector",
  [sym_sibling_selector] = "sibling_selector",
  [sym_adjacent_sibling_selector] = "adjacent_sibling_selector",
  [sym_namespace_selector] = "namespace_selector",
  [sym_pseudo_class_arguments] = "arguments",
  [sym_pseudo_element_arguments] = "arguments",
  [sym_declaration] = "declaration",
  [sym_last_declaration] = "declaration",
  [sym__query] = "_query",
  [sym_feature_query] = "feature_query",
  [sym_parenthesized_query] = "parenthesized_query",
  [sym_binary_query] = "binary_query",
  [sym_unary_query] = "unary_query",
  [sym_selector_query] = "selector_query",
  [sym__value] = "_value",
  [sym_parenthesized_value] = "parenthesized_value",
  [sym_color_value] = "color_value",
  [sym_string_value] = "string_value",
  [sym_integer_value] = "integer_value",
  [sym_float_value] = "float_value",
  [sym_grid_value] = "grid_value",
  [sym_call_expression] = "call_expression",
  [sym_arguments] = "arguments",
  [sym_binary_expression] = "binary_expression",
  [aux_sym_stylesheet_repeat1] = "stylesheet_repeat1",
  [aux_sym_import_statement_repeat1] = "import_statement_repeat1",
  [aux_sym_keyframe_block_list_repeat1] = "keyframe_block_list_repeat1",
  [aux_sym_postcss_statement_repeat1] = "postcss_statement_repeat1",
  [aux_sym_selectors_repeat1] = "selectors_repeat1",
  [aux_sym_block_repeat1] = "block_repeat1",
  [aux_sym_pseudo_class_arguments_repeat1] = "pseudo_class_arguments_repeat1",
  [aux_sym_declaration_repeat1] = "declaration_repeat1",
  [aux_sym_grid_value_repeat1] = "grid_value_repeat1",
  [aux_sym_arguments_repeat1] = "arguments_repeat1",
  [alias_sym_class_name] = "class_name",
  [alias_sym_feature_name] = "feature_name",
  [alias_sym_function_name] = "function_name",
  [alias_sym_id_name] = "id_name",
  [alias_sym_keyframes_name] = "keyframes_name",
  [alias_sym_keyword_query] = "keyword_query",
  [alias_sym_namespace_name] = "namespace_name",
  [alias_sym_property_name] = "property_name",
  [alias_sym_tag_name] = "tag_name",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_ATimport] = anon_sym_ATimport,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_ATmedia] = anon_sym_ATmedia,
  [anon_sym_ATcharset] = anon_sym_ATcharset,
  [anon_sym_ATnamespace] = anon_sym_ATnamespace,
  [anon_sym_ATkeyframes] = anon_sym_ATkeyframes,
  [aux_sym_keyframes_statement_token1] = sym_at_keyword,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_from] = sym_from,
  [sym_to] = sym_to,
  [anon_sym_ATsupports] = anon_sym_ATsupports,
  [sym_nesting_selector] = sym_nesting_selector,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_COLON_COLON] = anon_sym_COLON_COLON,
  [anon_sym_POUND] = anon_sym_POUND,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_TILDE_EQ] = anon_sym_TILDE_EQ,
  [anon_sym_CARET_EQ] = anon_sym_CARET_EQ,
  [anon_sym_PIPE_EQ] = anon_sym_PIPE_EQ,
  [anon_sym_STAR_EQ] = anon_sym_STAR_EQ,
  [anon_sym_DOLLAR_EQ] = anon_sym_DOLLAR_EQ,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_TILDE] = anon_sym_TILDE,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_important] = sym_important,
  [anon_sym_LPAREN2] = anon_sym_LPAREN,
  [anon_sym_and] = anon_sym_and,
  [anon_sym_or] = anon_sym_or,
  [anon_sym_not] = anon_sym_not,
  [anon_sym_only] = anon_sym_only,
  [anon_sym_selector] = anon_sym_selector,
  [aux_sym_color_value_token1] = aux_sym_color_value_token1,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_string_value_token1] = aux_sym_string_value_token1,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_value_token2] = aux_sym_string_value_token2,
  [sym_boolean_value] = sym_boolean_value,
  [aux_sym_integer_value_token1] = aux_sym_integer_value_token1,
  [aux_sym_float_value_token1] = aux_sym_float_value_token1,
  [sym_unit] = sym_unit,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [sym_identifier] = sym_identifier,
  [sym_at_keyword] = sym_at_keyword,
  [sym_js_comment] = sym_js_comment,
  [sym_comment] = sym_comment,
  [sym_plain_value] = sym_plain_value,
  [sym__descendant_operator] = sym__descendant_operator,
  [sym__pseudo_class_selector_colon] = anon_sym_COLON,
  [sym___error_recovery] = sym___error_recovery,
  [sym_stylesheet] = sym_stylesheet,
  [sym_import_statement] = sym_import_statement,
  [sym_media_statement] = sym_media_statement,
  [sym_charset_statement] = sym_charset_statement,
  [sym_namespace_statement] = sym_namespace_statement,
  [sym_keyframes_statement] = sym_keyframes_statement,
  [sym_keyframe_block_list] = sym_keyframe_block_list,
  [sym_keyframe_block] = sym_keyframe_block,
  [sym_supports_statement] = sym_supports_statement,
  [sym_postcss_statement] = sym_postcss_statement,
  [sym_at_rule] = sym_at_rule,
  [sym_rule_set] = sym_rule_set,
  [sym_selectors] = sym_selectors,
  [sym_block] = sym_block,
  [sym__selector] = sym__selector,
  [sym_universal_selector] = sym_universal_selector,
  [sym_class_selector] = sym_class_selector,
  [sym_pseudo_class_selector] = sym_pseudo_class_selector,
  [sym_pseudo_element_selector] = sym_pseudo_element_selector,
  [sym_id_selector] = sym_id_selector,
  [sym_attribute_selector] = sym_attribute_selector,
  [sym_child_selector] = sym_child_selector,
  [sym_descendant_selector] = sym_descendant_selector,
  [sym_sibling_selector] = sym_sibling_selector,
  [sym_adjacent_sibling_selector] = sym_adjacent_sibling_selector,
  [sym_namespace_selector] = sym_namespace_selector,
  [sym_pseudo_class_arguments] = sym_arguments,
  [sym_pseudo_element_arguments] = sym_arguments,
  [sym_declaration] = sym_declaration,
  [sym_last_declaration] = sym_declaration,
  [sym__query] = sym__query,
  [sym_feature_query] = sym_feature_query,
  [sym_parenthesized_query] = sym_parenthesized_query,
  [sym_binary_query] = sym_binary_query,
  [sym_unary_query] = sym_unary_query,
  [sym_selector_query] = sym_selector_query,
  [sym__value] = sym__value,
  [sym_parenthesized_value] = sym_parenthesized_value,
  [sym_color_value] = sym_color_value,
  [sym_string_value] = sym_string_value,
  [sym_integer_value] = sym_integer_value,
  [sym_float_value] = sym_float_value,
  [sym_grid_value] = sym_grid_value,
  [sym_call_expression] = sym_call_expression,
  [sym_arguments] = sym_arguments,
  [sym_binary_expression] = sym_binary_expression,
  [aux_sym_stylesheet_repeat1] = aux_sym_stylesheet_repeat1,
  [aux_sym_import_statement_repeat1] = aux_sym_import_statement_repeat1,
  [aux_sym_keyframe_block_list_repeat1] = aux_sym_keyframe_block_list_repeat1,
  [aux_sym_postcss_statement_repeat1] = aux_sym_postcss_statement_repeat1,
  [aux_sym_selectors_repeat1] = aux_sym_selectors_repeat1,
  [aux_sym_block_repeat1] = aux_sym_block_repeat1,
  [aux_sym_pseudo_class_arguments_repeat1] = aux_sym_pseudo_class_arguments_repeat1,
  [aux_sym_declaration_repeat1] = aux_sym_declaration_repeat1,
  [aux_sym_grid_value_repeat1] = aux_sym_grid_value_repeat1,
  [aux_sym_arguments_repeat1] = aux_sym_arguments_repeat1,
  [alias_sym_class_name] = alias_sym_class_name,
  [alias_sym_feature_name] = alias_sym_feature_name,
  [alias_sym_function_name] = alias_sym_function_name,
  [alias_sym_id_name] = alias_sym_id_name,
  [alias_sym_keyframes_name] = alias_sym_keyframes_name,
  [alias_sym_keyword_query] = alias_sym_keyword_query,
  [alias_sym_namespace_name] = alias_sym_namespace_name,
  [alias_sym_property_name] = alias_sym_property_name,
  [alias_sym_tag_name] = alias_sym_tag_name,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_ATimport] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATmedia] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATcharset] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATnamespace] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATkeyframes] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_keyframes_statement_token1] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_from] = {
    .visible = true,
    .named = true,
  },
  [sym_to] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_ATsupports] = {
    .visible = true,
    .named = false,
  },
  [sym_nesting_selector] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TILDE_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOLLAR_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TILDE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [sym_important] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LPAREN2] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_and] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_or] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_not] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_only] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_selector] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_color_value_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_value_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_value_token2] = {
    .visible = false,
    .named = false,
  },
  [sym_boolean_value] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_integer_value_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_float_value_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_unit] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_at_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_js_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_plain_value] = {
    .visible = true,
    .named = true,
  },
  [sym__descendant_operator] = {
    .visible = false,
    .named = true,
  },
  [sym__pseudo_class_selector_colon] = {
    .visible = true,
    .named = false,
  },
  [sym___error_recovery] = {
    .visible = false,
    .named = true,
  },
  [sym_stylesheet] = {
    .visible = true,
    .named = true,
  },
  [sym_import_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_media_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_charset_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_namespace_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_keyframes_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_keyframe_block_list] = {
    .visible = true,
    .named = true,
  },
  [sym_keyframe_block] = {
    .visible = true,
    .named = true,
  },
  [sym_supports_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_postcss_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_at_rule] = {
    .visible = true,
    .named = true,
  },
  [sym_rule_set] = {
    .visible = true,
    .named = true,
  },
  [sym_selectors] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [sym__selector] = {
    .visible = false,
    .named = true,
  },
  [sym_universal_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_class_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_pseudo_class_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_pseudo_element_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_id_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_child_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_descendant_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_sibling_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_adjacent_sibling_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_namespace_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_pseudo_class_arguments] = {
    .visible = true,
    .named = true,
  },
  [sym_pseudo_element_arguments] = {
    .visible = true,
    .named = true,
  },
  [sym_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_last_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym__query] = {
    .visible = false,
    .named = true,
  },
  [sym_feature_query] = {
    .visible = true,
    .named = true,
  },
  [sym_parenthesized_query] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_query] = {
    .visible = true,
    .named = true,
  },
  [sym_unary_query] = {
    .visible = true,
    .named = true,
  },
  [sym_selector_query] = {
    .visible = true,
    .named = true,
  },
  [sym__value] = {
    .visible = false,
    .named = true,
  },
  [sym_parenthesized_value] = {
    .visible = true,
    .named = true,
  },
  [sym_color_value] = {
    .visible = true,
    .named = true,
  },
  [sym_string_value] = {
    .visible = true,
    .named = true,
  },
  [sym_integer_value] = {
    .visible = true,
    .named = true,
  },
  [sym_float_value] = {
    .visible = true,
    .named = true,
  },
  [sym_grid_value] = {
    .visible = true,
    .named = true,
  },
  [sym_call_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_arguments] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_expression] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_stylesheet_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_import_statement_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_keyframe_block_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_postcss_statement_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_selectors_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_pseudo_class_arguments_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_declaration_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_grid_value_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_arguments_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_class_name] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_feature_name] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_function_name] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_id_name] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_keyframes_name] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_keyword_query] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_namespace_name] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_property_name] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_tag_name] = {
    .visible = true,
    .named = true,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [0] = alias_sym_tag_name,
  },
  [2] = {
    [1] = alias_sym_class_name,
  },
  [3] = {
    [0] = sym_plain_value,
  },
  [4] = {
    [0] = alias_sym_keyword_query,
  },
  [5] = {
    [1] = alias_sym_tag_name,
  },
  [6] = {
    [1] = alias_sym_id_name,
  },
  [7] = {
    [0] = alias_sym_function_name,
  },
  [8] = {
    [1] = alias_sym_keyframes_name,
  },
  [9] = {
    [1] = sym_identifier,
  },
  [10] = {
    [2] = alias_sym_class_name,
  },
  [11] = {
    [2] = alias_sym_tag_name,
  },
  [12] = {
    [2] = alias_sym_id_name,
  },
  [13] = {
    [1] = alias_sym_namespace_name,
  },
  [14] = {
    [0] = alias_sym_property_name,
  },
  [15] = {
    [2] = sym_identifier,
  },
  [16] = {
    [1] = alias_sym_feature_name,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  sym_namespace_selector, 2,
    sym_namespace_selector,
    sym_identifier,
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 2,
  [5] = 2,
  [6] = 3,
  [7] = 3,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 14,
  [16] = 16,
  [17] = 17,
  [18] = 17,
  [19] = 19,
  [20] = 20,
  [21] = 20,
  [22] = 22,
  [23] = 23,
  [24] = 23,
  [25] = 23,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 41,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 47,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 47,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 70,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 74,
  [79] = 79,
  [80] = 80,
  [81] = 63,
  [82] = 82,
  [83] = 71,
  [84] = 73,
  [85] = 85,
  [86] = 74,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 71,
  [92] = 92,
  [93] = 93,
  [94] = 62,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 30,
  [101] = 101,
  [102] = 73,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 30,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 109,
  [128] = 128,
  [129] = 129,
  [130] = 130,
  [131] = 128,
  [132] = 110,
  [133] = 133,
  [134] = 121,
  [135] = 112,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 139,
  [140] = 140,
  [141] = 133,
  [142] = 124,
  [143] = 111,
  [144] = 126,
  [145] = 145,
  [146] = 146,
  [147] = 147,
  [148] = 148,
  [149] = 149,
  [150] = 149,
  [151] = 108,
  [152] = 152,
  [153] = 153,
  [154] = 148,
  [155] = 146,
  [156] = 153,
  [157] = 157,
  [158] = 129,
  [159] = 137,
  [160] = 125,
  [161] = 122,
  [162] = 118,
  [163] = 117,
  [164] = 116,
  [165] = 114,
  [166] = 166,
  [167] = 167,
  [168] = 168,
  [169] = 169,
  [170] = 170,
  [171] = 171,
  [172] = 172,
  [173] = 173,
  [174] = 174,
  [175] = 173,
  [176] = 176,
  [177] = 174,
  [178] = 178,
  [179] = 179,
  [180] = 179,
  [181] = 27,
  [182] = 30,
  [183] = 183,
  [184] = 184,
  [185] = 184,
  [186] = 186,
  [187] = 187,
  [188] = 188,
  [189] = 189,
  [190] = 57,
  [191] = 191,
  [192] = 192,
  [193] = 157,
  [194] = 90,
  [195] = 88,
  [196] = 196,
  [197] = 197,
  [198] = 198,
  [199] = 199,
  [200] = 200,
  [201] = 201,
  [202] = 199,
  [203] = 198,
  [204] = 204,
  [205] = 139,
  [206] = 136,
  [207] = 145,
  [208] = 147,
  [209] = 119,
  [210] = 138,
  [211] = 140,
  [212] = 120,
  [213] = 57,
  [214] = 130,
  [215] = 215,
  [216] = 30,
  [217] = 217,
  [218] = 113,
  [219] = 90,
  [220] = 88,
  [221] = 140,
  [222] = 139,
  [223] = 145,
  [224] = 120,
  [225] = 119,
  [226] = 113,
  [227] = 147,
  [228] = 130,
  [229] = 157,
  [230] = 136,
  [231] = 138,
  [232] = 30,
  [233] = 233,
  [234] = 234,
  [235] = 233,
  [236] = 236,
  [237] = 234,
  [238] = 238,
  [239] = 239,
  [240] = 240,
  [241] = 238,
  [242] = 233,
  [243] = 236,
  [244] = 240,
  [245] = 245,
  [246] = 246,
  [247] = 247,
  [248] = 248,
  [249] = 249,
  [250] = 250,
  [251] = 246,
  [252] = 252,
  [253] = 253,
  [254] = 254,
  [255] = 255,
  [256] = 256,
  [257] = 257,
  [258] = 258,
  [259] = 257,
  [260] = 260,
  [261] = 256,
  [262] = 256,
  [263] = 263,
  [264] = 264,
  [265] = 254,
  [266] = 255,
  [267] = 260,
  [268] = 268,
  [269] = 269,
  [270] = 269,
  [271] = 271,
  [272] = 272,
  [273] = 273,
  [274] = 153,
  [275] = 275,
  [276] = 273,
  [277] = 268,
  [278] = 116,
  [279] = 279,
  [280] = 273,
  [281] = 128,
  [282] = 282,
  [283] = 283,
  [284] = 284,
  [285] = 285,
  [286] = 286,
  [287] = 287,
  [288] = 288,
  [289] = 282,
  [290] = 290,
  [291] = 282,
  [292] = 288,
  [293] = 293,
  [294] = 90,
  [295] = 295,
  [296] = 296,
  [297] = 297,
  [298] = 298,
  [299] = 297,
  [300] = 298,
  [301] = 301,
  [302] = 295,
  [303] = 303,
  [304] = 303,
  [305] = 305,
  [306] = 306,
  [307] = 307,
  [308] = 308,
  [309] = 309,
  [310] = 309,
  [311] = 311,
  [312] = 312,
  [313] = 303,
  [314] = 311,
  [315] = 303,
  [316] = 316,
  [317] = 317,
  [318] = 316,
  [319] = 312,
  [320] = 309,
  [321] = 321,
  [322] = 303,
  [323] = 311,
  [324] = 311,
  [325] = 303,
  [326] = 311,
  [327] = 317,
  [328] = 317,
  [329] = 329,
  [330] = 330,
  [331] = 331,
  [332] = 312,
  [333] = 333,
  [334] = 334,
  [335] = 321,
  [336] = 336,
  [337] = 334,
  [338] = 333,
  [339] = 339,
  [340] = 340,
  [341] = 333,
  [342] = 334,
  [343] = 343,
  [344] = 331,
  [345] = 333,
  [346] = 334,
  [347] = 333,
  [348] = 334,
  [349] = 333,
  [350] = 334,
  [351] = 311,
};

static inline bool sym_js_comment_character_set_1(int32_t c) {
  return (c < ';'
    ? (c < ' '
      ? (c < '\r'
        ? c == '\t'
        : c <= '\r')
      : (c <= '!' || (c < ','
        ? (c >= '(' && c <= '*')
        : c <= ',')))
    : (c <= ';' || (c < '{'
      ? (c < ']'
        ? c == '['
        : c <= ']')
      : (c <= '{' || c == '}'))));
}

static inline bool sym_plain_value_character_set_1(int32_t c) {
  return (c < ','
    ? (c < '\r'
      ? (c < '\t'
        ? c == 0
        : c <= '\n')
      : (c <= '\r' || (c < '('
        ? (c >= ' ' && c <= '!')
        : c <= ')')))
    : (c <= ',' || (c < ']'
      ? (c < '['
        ? c == ';'
        : c <= '[')
      : (c <= ']' || (c < '}'
        ? c == '{'
        : c <= '}')))));
}

static inline bool sym_plain_value_character_set_2(int32_t c) {
  return (c < ','
    ? (c < '\r'
      ? (c < '\t'
        ? c == 0
        : c <= '\n')
      : (c <= '\r' || (c < '('
        ? (c >= ' ' && c <= '!')
        : c <= '*')))
    : (c <= ',' || (c < ']'
      ? (c < '['
        ? c == ';'
        : c <= '[')
      : (c <= ']' || (c < '}'
        ? c == '{'
        : c <= '}')))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(69);
      if (lookahead == '!') ADVANCE(41);
      if (lookahead == '"') ADVANCE(173);
      if (lookahead == '#') ADVANCE(91);
      if (lookahead == '$') ADVANCE(35);
      if (lookahead == '&') ADVANCE(85);
      if (lookahead == '\'') ADVANCE(163);
      if (lookahead == '(') ADVANCE(107);
      if (lookahead == ')') ADVANCE(108);
      if (lookahead == '*') ADVANCE(87);
      if (lookahead == '+') ADVANCE(104);
      if (lookahead == ',') ADVANCE(71);
      if (lookahead == '-') ADVANCE(219);
      if (lookahead == '.') ADVANCE(89);
      if (lookahead == '/') ADVANCE(221);
      if (lookahead == ':') ADVANCE(109);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == '=') ADVANCE(93);
      if (lookahead == '>') ADVANCE(100);
      if (lookahead == '@') ADVANCE(39);
      if (lookahead == '[') ADVANCE(92);
      if (lookahead == ']') ADVANCE(99);
      if (lookahead == '^') ADVANCE(37);
      if (lookahead == 'a') ADVANCE(262);
      if (lookahead == 'f') ADVANCE(250);
      if (lookahead == 'n') ADVANCE(266);
      if (lookahead == 'o') ADVANCE(264);
      if (lookahead == 's') ADVANCE(256);
      if (lookahead == 't') ADVANCE(267);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '|') ADVANCE(106);
      if (lookahead == '}') ADVANCE(79);
      if (lookahead == '~') ADVANCE(102);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(223);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(66)
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('b' <= lookahead && lookahead <= 'd')) ADVANCE(278);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 1:
      if (lookahead == '!') ADVANCE(41);
      if (lookahead == '"') ADVANCE(173);
      if (lookahead == '#') ADVANCE(91);
      if (lookahead == '%') ADVANCE(216);
      if (lookahead == '\'') ADVANCE(163);
      if (lookahead == '(') ADVANCE(111);
      if (lookahead == ')') ADVANCE(108);
      if (lookahead == '*') ADVANCE(86);
      if (lookahead == '+') ADVANCE(104);
      if (lookahead == ',') ADVANCE(71);
      if (lookahead == '-') ADVANCE(218);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == '/') ADVANCE(222);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == '[') ADVANCE(92);
      if (lookahead == '_') ADVANCE(226);
      if (lookahead == 'f') ADVANCE(208);
      if (lookahead == 't') ADVANCE(211);
      if (lookahead == '}') ADVANCE(79);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(207);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(185);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(214);
      END_STATE();
    case 2:
      if (lookahead == '!') ADVANCE(41);
      if (lookahead == '"') ADVANCE(173);
      if (lookahead == '#') ADVANCE(91);
      if (lookahead == '&') ADVANCE(85);
      if (lookahead == '\'') ADVANCE(163);
      if (lookahead == '(') ADVANCE(111);
      if (lookahead == ')') ADVANCE(108);
      if (lookahead == '*') ADVANCE(86);
      if (lookahead == '+') ADVANCE(30);
      if (lookahead == ',') ADVANCE(71);
      if (lookahead == '-') ADVANCE(57);
      if (lookahead == '.') ADVANCE(89);
      if (lookahead == '/') ADVANCE(23);
      if (lookahead == ':') ADVANCE(34);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == '[') ADVANCE(92);
      if (lookahead == '_') ADVANCE(226);
      if (lookahead == 'f') ADVANCE(227);
      if (lookahead == 't') ADVANCE(240);
      if (lookahead == '}') ADVANCE(79);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(225);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(185);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      END_STATE();
    case 3:
      if (lookahead == '!') ADVANCE(41);
      if (lookahead == '"') ADVANCE(173);
      if (lookahead == '#') ADVANCE(91);
      if (lookahead == '\'') ADVANCE(163);
      if (lookahead == '(') ADVANCE(107);
      if (lookahead == ')') ADVANCE(108);
      if (lookahead == '*') ADVANCE(86);
      if (lookahead == '+') ADVANCE(104);
      if (lookahead == ',') ADVANCE(71);
      if (lookahead == '-') ADVANCE(218);
      if (lookahead == '.') ADVANCE(89);
      if (lookahead == '/') ADVANCE(222);
      if (lookahead == ':') ADVANCE(34);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == '>') ADVANCE(100);
      if (lookahead == '[') ADVANCE(92);
      if (lookahead == '_') ADVANCE(226);
      if (lookahead == 'f') ADVANCE(227);
      if (lookahead == 't') ADVANCE(240);
      if (lookahead == '|') ADVANCE(105);
      if (lookahead == '}') ADVANCE(79);
      if (lookahead == '~') ADVANCE(101);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(225);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(185);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      END_STATE();
    case 4:
      if (lookahead == '!') ADVANCE(41);
      if (lookahead == '"') ADVANCE(173);
      if (lookahead == '#') ADVANCE(91);
      if (lookahead == '\'') ADVANCE(163);
      if (lookahead == '(') ADVANCE(107);
      if (lookahead == '*') ADVANCE(86);
      if (lookahead == '+') ADVANCE(104);
      if (lookahead == ',') ADVANCE(71);
      if (lookahead == '-') ADVANCE(218);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == '/') ADVANCE(222);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == '[') ADVANCE(92);
      if (lookahead == '_') ADVANCE(226);
      if (lookahead == 'a') ADVANCE(236);
      if (lookahead == 'f') ADVANCE(227);
      if (lookahead == 'o') ADVANCE(242);
      if (lookahead == 't') ADVANCE(240);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(225);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(7)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(185);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      END_STATE();
    case 5:
      if (lookahead == '!') ADVANCE(41);
      if (lookahead == '"') ADVANCE(173);
      if (lookahead == '#') ADVANCE(91);
      if (lookahead == '\'') ADVANCE(163);
      if (lookahead == '(') ADVANCE(111);
      if (lookahead == ')') ADVANCE(108);
      if (lookahead == '*') ADVANCE(86);
      if (lookahead == '+') ADVANCE(104);
      if (lookahead == ',') ADVANCE(71);
      if (lookahead == '-') ADVANCE(218);
      if (lookahead == '.') ADVANCE(89);
      if (lookahead == '/') ADVANCE(222);
      if (lookahead == ':') ADVANCE(34);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == '>') ADVANCE(100);
      if (lookahead == '[') ADVANCE(92);
      if (lookahead == '_') ADVANCE(226);
      if (lookahead == 'f') ADVANCE(227);
      if (lookahead == 't') ADVANCE(240);
      if (lookahead == '|') ADVANCE(105);
      if (lookahead == '}') ADVANCE(79);
      if (lookahead == '~') ADVANCE(101);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(225);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(185);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      END_STATE();
    case 6:
      if (lookahead == '!') ADVANCE(41);
      if (lookahead == '"') ADVANCE(173);
      if (lookahead == '#') ADVANCE(91);
      if (lookahead == '\'') ADVANCE(163);
      if (lookahead == '(') ADVANCE(111);
      if (lookahead == ')') ADVANCE(108);
      if (lookahead == '*') ADVANCE(86);
      if (lookahead == '+') ADVANCE(104);
      if (lookahead == ',') ADVANCE(71);
      if (lookahead == '-') ADVANCE(218);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == '/') ADVANCE(222);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == '[') ADVANCE(92);
      if (lookahead == '_') ADVANCE(226);
      if (lookahead == 'f') ADVANCE(227);
      if (lookahead == 't') ADVANCE(240);
      if (lookahead == '}') ADVANCE(79);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(225);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(185);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      END_STATE();
    case 7:
      if (lookahead == '!') ADVANCE(41);
      if (lookahead == '"') ADVANCE(173);
      if (lookahead == '#') ADVANCE(91);
      if (lookahead == '\'') ADVANCE(163);
      if (lookahead == '(') ADVANCE(111);
      if (lookahead == '*') ADVANCE(86);
      if (lookahead == '+') ADVANCE(104);
      if (lookahead == ',') ADVANCE(71);
      if (lookahead == '-') ADVANCE(218);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == '/') ADVANCE(222);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == '[') ADVANCE(92);
      if (lookahead == '_') ADVANCE(226);
      if (lookahead == 'a') ADVANCE(236);
      if (lookahead == 'f') ADVANCE(227);
      if (lookahead == 'o') ADVANCE(242);
      if (lookahead == 't') ADVANCE(240);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(225);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(7)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(185);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      END_STATE();
    case 8:
      if (lookahead == '!') ADVANCE(41);
      if (lookahead == '"') ADVANCE(173);
      if (lookahead == '#') ADVANCE(91);
      if (lookahead == '\'') ADVANCE(163);
      if (lookahead == '(') ADVANCE(111);
      if (lookahead == '+') ADVANCE(30);
      if (lookahead == '-') ADVANCE(57);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == '/') ADVANCE(23);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == '[') ADVANCE(92);
      if (lookahead == '_') ADVANCE(226);
      if (lookahead == 'f') ADVANCE(227);
      if (lookahead == 'n') ADVANCE(238);
      if (lookahead == 'o') ADVANCE(237);
      if (lookahead == 's') ADVANCE(232);
      if (lookahead == 't') ADVANCE(240);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(225);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(185);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      END_STATE();
    case 9:
      if (lookahead == '#') ADVANCE(91);
      if (lookahead == '$') ADVANCE(35);
      if (lookahead == '(') ADVANCE(107);
      if (lookahead == ')') ADVANCE(108);
      if (lookahead == '*') ADVANCE(36);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == ',') ADVANCE(71);
      if (lookahead == '.') ADVANCE(88);
      if (lookahead == '/') ADVANCE(22);
      if (lookahead == ':') ADVANCE(109);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == '=') ADVANCE(93);
      if (lookahead == '>') ADVANCE(100);
      if (lookahead == '[') ADVANCE(92);
      if (lookahead == ']') ADVANCE(99);
      if (lookahead == '^') ADVANCE(37);
      if (lookahead == 'a') ADVANCE(45);
      if (lookahead == 'o') ADVANCE(52);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '|') ADVANCE(106);
      if (lookahead == '~') ADVANCE(102);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(11)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('b' <= lookahead && lookahead <= 'f')) ADVANCE(61);
      END_STATE();
    case 10:
      if (lookahead == '#') ADVANCE(91);
      if (lookahead == '$') ADVANCE(35);
      if (lookahead == '(') ADVANCE(107);
      if (lookahead == '*') ADVANCE(87);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == ',') ADVANCE(71);
      if (lookahead == '-') ADVANCE(217);
      if (lookahead == '.') ADVANCE(88);
      if (lookahead == '/') ADVANCE(221);
      if (lookahead == ':') ADVANCE(34);
      if (lookahead == '=') ADVANCE(93);
      if (lookahead == '>') ADVANCE(100);
      if (lookahead == '[') ADVANCE(92);
      if (lookahead == ']') ADVANCE(99);
      if (lookahead == '^') ADVANCE(37);
      if (lookahead == '|') ADVANCE(106);
      if (lookahead == '~') ADVANCE(102);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(12)
      END_STATE();
    case 11:
      if (lookahead == '#') ADVANCE(91);
      if (lookahead == '$') ADVANCE(35);
      if (lookahead == ')') ADVANCE(108);
      if (lookahead == '*') ADVANCE(36);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == ',') ADVANCE(71);
      if (lookahead == '.') ADVANCE(88);
      if (lookahead == '/') ADVANCE(22);
      if (lookahead == ':') ADVANCE(109);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == '=') ADVANCE(93);
      if (lookahead == '>') ADVANCE(100);
      if (lookahead == '[') ADVANCE(92);
      if (lookahead == ']') ADVANCE(99);
      if (lookahead == '^') ADVANCE(37);
      if (lookahead == 'a') ADVANCE(44);
      if (lookahead == 'o') ADVANCE(52);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '|') ADVANCE(106);
      if (lookahead == '~') ADVANCE(102);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(11)
      END_STATE();
    case 12:
      if (lookahead == '#') ADVANCE(91);
      if (lookahead == '$') ADVANCE(35);
      if (lookahead == '*') ADVANCE(87);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == ',') ADVANCE(71);
      if (lookahead == '-') ADVANCE(217);
      if (lookahead == '.') ADVANCE(88);
      if (lookahead == '/') ADVANCE(221);
      if (lookahead == ':') ADVANCE(34);
      if (lookahead == '=') ADVANCE(93);
      if (lookahead == '>') ADVANCE(100);
      if (lookahead == '[') ADVANCE(92);
      if (lookahead == ']') ADVANCE(99);
      if (lookahead == '^') ADVANCE(37);
      if (lookahead == '|') ADVANCE(106);
      if (lookahead == '~') ADVANCE(102);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(12)
      END_STATE();
    case 13:
      if (lookahead == '#') ADVANCE(91);
      if (lookahead == '(') ADVANCE(107);
      if (lookahead == ')') ADVANCE(108);
      if (lookahead == '*') ADVANCE(86);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == ',') ADVANCE(71);
      if (lookahead == '-') ADVANCE(217);
      if (lookahead == '.') ADVANCE(88);
      if (lookahead == '/') ADVANCE(221);
      if (lookahead == ':') ADVANCE(109);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == '>') ADVANCE(100);
      if (lookahead == '[') ADVANCE(92);
      if (lookahead == ']') ADVANCE(99);
      if (lookahead == 'a') ADVANCE(44);
      if (lookahead == 'o') ADVANCE(52);
      if (lookahead == '|') ADVANCE(105);
      if (lookahead == '~') ADVANCE(101);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(14)
      END_STATE();
    case 14:
      if (lookahead == '#') ADVANCE(91);
      if (lookahead == ')') ADVANCE(108);
      if (lookahead == '*') ADVANCE(86);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == ',') ADVANCE(71);
      if (lookahead == '-') ADVANCE(217);
      if (lookahead == '.') ADVANCE(88);
      if (lookahead == '/') ADVANCE(221);
      if (lookahead == ':') ADVANCE(109);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == '>') ADVANCE(100);
      if (lookahead == '[') ADVANCE(92);
      if (lookahead == ']') ADVANCE(99);
      if (lookahead == 'a') ADVANCE(44);
      if (lookahead == 'o') ADVANCE(52);
      if (lookahead == '|') ADVANCE(105);
      if (lookahead == '~') ADVANCE(101);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(14)
      END_STATE();
    case 15:
      if (lookahead == '%') ADVANCE(216);
      if (lookahead == '(') ADVANCE(111);
      if (lookahead == '*') ADVANCE(86);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == '-') ADVANCE(220);
      if (lookahead == '/') ADVANCE(221);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == '_') ADVANCE(279);
      if (lookahead == 'n') ADVANCE(200);
      if (lookahead == 'o') ADVANCE(199);
      if (lookahead == 's') ADVANCE(196);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(18)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 16:
      if (lookahead == '(') ADVANCE(107);
      if (lookahead == '*') ADVANCE(86);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == '-') ADVANCE(220);
      if (lookahead == '/') ADVANCE(221);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == 'n') ADVANCE(266);
      if (lookahead == 'o') ADVANCE(265);
      if (lookahead == 's') ADVANCE(256);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(18)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 17:
      if (lookahead == '(') ADVANCE(111);
      if (lookahead == '*') ADVANCE(86);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == '-') ADVANCE(220);
      if (lookahead == '/') ADVANCE(221);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == 'n') ADVANCE(266);
      if (lookahead == 'o') ADVANCE(265);
      if (lookahead == 's') ADVANCE(256);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(17)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 18:
      if (lookahead == '(') ADVANCE(111);
      if (lookahead == '*') ADVANCE(86);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == '-') ADVANCE(220);
      if (lookahead == '/') ADVANCE(221);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == 'n') ADVANCE(266);
      if (lookahead == 'o') ADVANCE(265);
      if (lookahead == 's') ADVANCE(256);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(18)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 19:
      if (lookahead == '(') ADVANCE(111);
      if (lookahead == '-') ADVANCE(63);
      if (lookahead == '/') ADVANCE(22);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == 'n') ADVANCE(266);
      if (lookahead == 'o') ADVANCE(265);
      if (lookahead == 's') ADVANCE(256);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(19)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 20:
      if (lookahead == ')') ADVANCE(108);
      if (lookahead == '*') ADVANCE(86);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == ',') ADVANCE(71);
      if (lookahead == '-') ADVANCE(217);
      if (lookahead == '/') ADVANCE(221);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == ']') ADVANCE(99);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(20)
      END_STATE();
    case 21:
      if (lookahead == ')') ADVANCE(108);
      if (lookahead == '*') ADVANCE(86);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == ',') ADVANCE(71);
      if (lookahead == '-') ADVANCE(217);
      if (lookahead == '/') ADVANCE(221);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == ']') ADVANCE(99);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(20)
      if (lookahead == '%' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(216);
      END_STATE();
    case 22:
      if (lookahead == '*') ADVANCE(25);
      if (lookahead == '/') ADVANCE(331);
      END_STATE();
    case 23:
      if (lookahead == '*') ADVANCE(25);
      if (lookahead == '/') ADVANCE(328);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(33);
      END_STATE();
    case 24:
      if (lookahead == '*') ADVANCE(24);
      if (lookahead == '/') ADVANCE(332);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 25:
      if (lookahead == '*') ADVANCE(24);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 26:
      if (lookahead == '-') ADVANCE(63);
      if (lookahead == '/') ADVANCE(22);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(27)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(61);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(278);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 27:
      if (lookahead == '-') ADVANCE(63);
      if (lookahead == '/') ADVANCE(22);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(27)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 28:
      if (lookahead == '-') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(191);
      END_STATE();
    case 29:
      if (lookahead == '-') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(151);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(161);
      END_STATE();
    case 30:
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(185);
      END_STATE();
    case 31:
      if (lookahead == '/') ADVANCE(22);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(31)
      END_STATE();
    case 32:
      if (lookahead == '/') ADVANCE(22);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(31)
      if (lookahead == '%' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(216);
      END_STATE();
    case 33:
      if (lookahead == '/') ADVANCE(64);
      if (lookahead == '-' ||
          lookahead == '_') ADVANCE(33);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(333);
      END_STATE();
    case 34:
      if (lookahead == ':') ADVANCE(90);
      END_STATE();
    case 35:
      if (lookahead == '=') ADVANCE(98);
      END_STATE();
    case 36:
      if (lookahead == '=') ADVANCE(97);
      END_STATE();
    case 37:
      if (lookahead == '=') ADVANCE(95);
      END_STATE();
    case 38:
      if (lookahead == 'a') ADVANCE(46);
      END_STATE();
    case 39:
      if (lookahead == 'c') ADVANCE(298);
      if (lookahead == 'i') ADVANCE(300);
      if (lookahead == 'k') ADVANCE(288);
      if (lookahead == 'm') ADVANCE(289);
      if (lookahead == 'n') ADVANCE(283);
      if (lookahead == 's') ADVANCE(323);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 40:
      if (lookahead == 'd') ADVANCE(112);
      END_STATE();
    case 41:
      if (lookahead == 'i') ADVANCE(42);
      END_STATE();
    case 42:
      if (lookahead == 'm') ADVANCE(50);
      END_STATE();
    case 43:
      if (lookahead == 'm') ADVANCE(80);
      END_STATE();
    case 44:
      if (lookahead == 'n') ADVANCE(40);
      END_STATE();
    case 45:
      if (lookahead == 'n') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(62);
      END_STATE();
    case 46:
      if (lookahead == 'n') ADVANCE(55);
      END_STATE();
    case 47:
      if (lookahead == 'o') ADVANCE(51);
      END_STATE();
    case 48:
      if (lookahead == 'o') ADVANCE(82);
      END_STATE();
    case 49:
      if (lookahead == 'o') ADVANCE(43);
      END_STATE();
    case 50:
      if (lookahead == 'p') ADVANCE(47);
      END_STATE();
    case 51:
      if (lookahead == 'r') ADVANCE(54);
      END_STATE();
    case 52:
      if (lookahead == 'r') ADVANCE(115);
      END_STATE();
    case 53:
      if (lookahead == 'r') ADVANCE(49);
      END_STATE();
    case 54:
      if (lookahead == 't') ADVANCE(38);
      END_STATE();
    case 55:
      if (lookahead == 't') ADVANCE(110);
      END_STATE();
    case 56:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(60);
      if (lookahead == '/') ADVANCE(22);
      if (lookahead == 'f') ADVANCE(53);
      if (lookahead == 't') ADVANCE(48);
      if (lookahead == '}') ADVANCE(79);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(56)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      END_STATE();
    case 57:
      if (lookahead == '-' ||
          lookahead == '_') ADVANCE(226);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == '/') ADVANCE(64);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(225);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(185);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      END_STATE();
    case 58:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(190);
      END_STATE();
    case 59:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(191);
      END_STATE();
    case 60:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      END_STATE();
    case 61:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(62);
      END_STATE();
    case 62:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(161);
      END_STATE();
    case 63:
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 64:
      if (!sym_plain_value_character_set_2(lookahead)) ADVANCE(33);
      END_STATE();
    case 65:
      if (!sym_plain_value_character_set_2(lookahead)) ADVANCE(333);
      END_STATE();
    case 66:
      if (eof) ADVANCE(69);
      if (lookahead == '!') ADVANCE(41);
      if (lookahead == '"') ADVANCE(173);
      if (lookahead == '#') ADVANCE(91);
      if (lookahead == '$') ADVANCE(35);
      if (lookahead == '&') ADVANCE(85);
      if (lookahead == '\'') ADVANCE(163);
      if (lookahead == '(') ADVANCE(111);
      if (lookahead == ')') ADVANCE(108);
      if (lookahead == '*') ADVANCE(87);
      if (lookahead == '+') ADVANCE(104);
      if (lookahead == ',') ADVANCE(71);
      if (lookahead == '-') ADVANCE(219);
      if (lookahead == '.') ADVANCE(89);
      if (lookahead == '/') ADVANCE(221);
      if (lookahead == ':') ADVANCE(109);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == '=') ADVANCE(93);
      if (lookahead == '>') ADVANCE(100);
      if (lookahead == '@') ADVANCE(39);
      if (lookahead == '[') ADVANCE(92);
      if (lookahead == ']') ADVANCE(99);
      if (lookahead == '^') ADVANCE(37);
      if (lookahead == 'a') ADVANCE(263);
      if (lookahead == 'f') ADVANCE(251);
      if (lookahead == 'n') ADVANCE(266);
      if (lookahead == 'o') ADVANCE(264);
      if (lookahead == 's') ADVANCE(256);
      if (lookahead == 't') ADVANCE(267);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '|') ADVANCE(106);
      if (lookahead == '}') ADVANCE(79);
      if (lookahead == '~') ADVANCE(102);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(224);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(66)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(185);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 67:
      if (eof) ADVANCE(69);
      if (lookahead == '"') ADVANCE(173);
      if (lookahead == '#') ADVANCE(91);
      if (lookahead == '&') ADVANCE(85);
      if (lookahead == '\'') ADVANCE(163);
      if (lookahead == '(') ADVANCE(107);
      if (lookahead == ')') ADVANCE(108);
      if (lookahead == '*') ADVANCE(86);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == ',') ADVANCE(71);
      if (lookahead == '-') ADVANCE(63);
      if (lookahead == '.') ADVANCE(88);
      if (lookahead == '/') ADVANCE(22);
      if (lookahead == ':') ADVANCE(109);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == '>') ADVANCE(100);
      if (lookahead == '@') ADVANCE(39);
      if (lookahead == '[') ADVANCE(92);
      if (lookahead == ']') ADVANCE(99);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '|') ADVANCE(105);
      if (lookahead == '}') ADVANCE(79);
      if (lookahead == '~') ADVANCE(101);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(68)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 68:
      if (eof) ADVANCE(69);
      if (lookahead == '"') ADVANCE(173);
      if (lookahead == '#') ADVANCE(91);
      if (lookahead == '&') ADVANCE(85);
      if (lookahead == '\'') ADVANCE(163);
      if (lookahead == ')') ADVANCE(108);
      if (lookahead == '*') ADVANCE(86);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == ',') ADVANCE(71);
      if (lookahead == '-') ADVANCE(63);
      if (lookahead == '.') ADVANCE(88);
      if (lookahead == '/') ADVANCE(22);
      if (lookahead == ':') ADVANCE(109);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == '>') ADVANCE(100);
      if (lookahead == '@') ADVANCE(39);
      if (lookahead == '[') ADVANCE(92);
      if (lookahead == ']') ADVANCE(99);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '|') ADVANCE(105);
      if (lookahead == '}') ADVANCE(79);
      if (lookahead == '~') ADVANCE(101);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(68)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_ATimport);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_ATmedia);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_ATcharset);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_ATnamespace);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_ATkeyframes);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(aux_sym_keyframes_statement_token1);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_from);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_from);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_to);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_to);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_ATsupports);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_nesting_selector);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '=') ADVANCE(97);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(190);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_COLON_COLON);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_TILDE_EQ);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_CARET_EQ);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_PIPE_EQ);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_STAR_EQ);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_DOLLAR_EQ);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_TILDE);
      if (lookahead == '=') ADVANCE(94);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(185);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '=') ADVANCE(96);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ':') ADVANCE(90);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_important);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_LPAREN2);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_and);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_and);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_and);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_or);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_or);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_or);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_not);
      if (lookahead == '%') ADVANCE(216);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_not);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_not);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_only);
      if (lookahead == '%') ADVANCE(216);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_only);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_only);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_selector);
      if (lookahead == '%') ADVANCE(216);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_selector);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_selector);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(191);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(140);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(127);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(143);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(153);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(145);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(155);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(148);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(157);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(150);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(159);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(185);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(128);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(127);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(134);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(130);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(137);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(129);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(153);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(135);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(131);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(157);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(136);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(132);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(159);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(191);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(192);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(141);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(162);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(140);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(127);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(146);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(154);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(143);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(153);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(142);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(152);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(144);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(156);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(145);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(155);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(147);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(158);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(148);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(157);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(150);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(159);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(162);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(127);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(152);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(153);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(154);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(155);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(156);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(157);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(158);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(159);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '\n') ADVANCE(169);
      if (lookahead != 0 &&
          lookahead != '\\') ADVANCE(170);
      if (lookahead == '\\') ADVANCE(164);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '*') ADVANCE(167);
      if (lookahead == '/') ADVANCE(170);
      if (lookahead == '\\') ADVANCE(172);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'') ADVANCE(169);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '*') ADVANCE(166);
      if (lookahead == '/') ADVANCE(169);
      if (lookahead == '\\') ADVANCE(171);
      if (lookahead == '\n' ||
          lookahead == '\'') ADVANCE(25);
      if (lookahead != 0) ADVANCE(167);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '*') ADVANCE(166);
      if (lookahead == '\\') ADVANCE(171);
      if (lookahead == '\n' ||
          lookahead == '\'') ADVANCE(25);
      if (lookahead != 0) ADVANCE(167);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '/') ADVANCE(165);
      if (lookahead == '\\') ADVANCE(172);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(168);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'') ADVANCE(169);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '\\') ADVANCE(172);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'') ADVANCE(169);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '\\') ADVANCE(164);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'') ADVANCE(170);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead != 0 &&
          lookahead != '*' &&
          lookahead != '\\') ADVANCE(167);
      if (lookahead == '*') ADVANCE(166);
      if (lookahead == '\\') ADVANCE(171);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead != 0 &&
          lookahead != '\\') ADVANCE(169);
      if (lookahead == '\\') ADVANCE(172);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '\n') ADVANCE(179);
      if (lookahead != 0 &&
          lookahead != '\\') ADVANCE(180);
      if (lookahead == '\\') ADVANCE(174);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '*') ADVANCE(177);
      if (lookahead == '/') ADVANCE(180);
      if (lookahead == '\\') ADVANCE(182);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"') ADVANCE(179);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '*') ADVANCE(176);
      if (lookahead == '/') ADVANCE(179);
      if (lookahead == '\\') ADVANCE(181);
      if (lookahead == '\n' ||
          lookahead == '"') ADVANCE(25);
      if (lookahead != 0) ADVANCE(177);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '*') ADVANCE(176);
      if (lookahead == '\\') ADVANCE(181);
      if (lookahead == '\n' ||
          lookahead == '"') ADVANCE(25);
      if (lookahead != 0) ADVANCE(177);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '/') ADVANCE(175);
      if (lookahead == '\\') ADVANCE(182);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(178);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"') ADVANCE(179);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '\\') ADVANCE(182);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"') ADVANCE(179);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '\\') ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"') ADVANCE(180);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead != 0 &&
          lookahead != '*' &&
          lookahead != '\\') ADVANCE(177);
      if (lookahead == '*') ADVANCE(176);
      if (lookahead == '\\') ADVANCE(181);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead != 0 &&
          lookahead != '\\') ADVANCE(179);
      if (lookahead == '\\') ADVANCE(182);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_boolean_value);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_boolean_value);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_integer_value_token1);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(185);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_integer_value_token1);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_integer_value_token1);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(133);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_integer_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_float_value_token1);
      if (lookahead == '/') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(189);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_float_value_token1);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(190);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_float_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(191);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_float_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(192);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_float_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(149);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(160);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(216);
      if (lookahead == 'c') ADVANCE(204);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(216);
      if (lookahead == 'e') ADVANCE(194);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(216);
      if (lookahead == 'e') ADVANCE(198);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(216);
      if (lookahead == 'l') ADVANCE(205);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(216);
      if (lookahead == 'l') ADVANCE(195);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(216);
      if (lookahead == 'n') ADVANCE(197);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(216);
      if (lookahead == 'o') ADVANCE(203);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(216);
      if (lookahead == 'o') ADVANCE(202);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(216);
      if (lookahead == 'r') ADVANCE(124);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(216);
      if (lookahead == 't') ADVANCE(118);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(216);
      if (lookahead == 't') ADVANCE(201);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(216);
      if (lookahead == 'y') ADVANCE(121);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(216);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(215);
      if (lookahead == '-') ADVANCE(248);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '_') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(189);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(214);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(215);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'a') ADVANCE(210);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(214);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(215);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'e') ADVANCE(214);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(214);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(215);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'l') ADVANCE(212);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(214);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(215);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'r') ADVANCE(213);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(214);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(215);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 's') ADVANCE(209);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(214);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(215);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'u') ADVANCE(209);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(214);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(215);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(214);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '%' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(216);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-' ||
          lookahead == '_') ADVANCE(226);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == '/') ADVANCE(64);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(225);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(185);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('F' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'd') ||
          ('f' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(224);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(185);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '*') ADVANCE(25);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '*') ADVANCE(25);
      if (lookahead == '/') ADVANCE(328);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(33);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(276);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(193);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(277);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(276);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(192);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(248);
      if (lookahead == '/') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(189);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(64);
      if (lookahead == '-' ||
          lookahead == '_') ADVANCE(226);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'a') ADVANCE(233);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'c') ADVANCE(245);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'd') ADVANCE(113);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'e') ADVANCE(183);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'e') ADVANCE(228);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'e') ADVANCE(235);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'l') ADVANCE(243);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'l') ADVANCE(247);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'l') ADVANCE(231);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'n') ADVANCE(229);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'n') ADVANCE(234);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'o') ADVANCE(244);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'o') ADVANCE(241);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'r') ADVANCE(246);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'r') ADVANCE(125);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'r') ADVANCE(116);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 's') ADVANCE(230);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 't') ADVANCE(119);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 't') ADVANCE(239);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'u') ADVANCE(230);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'y') ADVANCE(122);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(189);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(257);
      if (lookahead == 'r') ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('b' <= lookahead && lookahead <= 'f')) ADVANCE(277);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(258);
      if (lookahead == 'r') ADVANCE(268);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(273);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(114);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(252);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(184);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(260);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(271);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(160);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(271);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(275);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(254);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(81);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(253);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(277);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(253);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(259);
      if (lookahead == 'r') ADVANCE(117);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(259);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(272);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(83);
      if (lookahead == 'r') ADVANCE(274);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(261);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(270);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(126);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(255);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(120);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(255);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'y') ADVANCE(123);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(192);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(160);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(277);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'a') ADVANCE(310);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'a') ADVANCE(73);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'a') ADVANCE(286);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'a') ADVANCE(301);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'a') ADVANCE(302);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'a') ADVANCE(303);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'c') ADVANCE(290);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'd') ADVANCE(299);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(324);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(287);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(75);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(318);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(321);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(316);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(317);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(325);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'f') ADVANCE(313);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'f') ADVANCE(314);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'h') ADVANCE(280);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'i') ADVANCE(281);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 'm') ADVANCE(306);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 'm') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 'm') ADVANCE(293);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 'm') ADVANCE(294);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 'o') ADVANCE(311);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 'o') ADVANCE(312);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 'p') ADVANCE(304);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 'p') ADVANCE(282);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 'p') ADVANCE(305);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 'p') ADVANCE(308);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 'r') ADVANCE(319);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 'r') ADVANCE(320);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 'r') ADVANCE(322);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 'r') ADVANCE(284);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 'r') ADVANCE(285);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 's') ADVANCE(84);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 's') ADVANCE(76);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 's') ADVANCE(77);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 's') ADVANCE(307);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 's') ADVANCE(292);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 't') ADVANCE(70);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 't') ADVANCE(74);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 't') ADVANCE(315);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 'u') ADVANCE(309);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 'y') ADVANCE(296);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == 'y') ADVANCE(297);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(295);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(327);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(327);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(sym_js_comment);
      if (lookahead == '/') ADVANCE(329);
      if (lookahead == '-' ||
          lookahead == '_') ADVANCE(328);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(331);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(sym_js_comment);
      if (sym_js_comment_character_set_1(lookahead)) ADVANCE(331);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(328);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(sym_js_comment);
      if (sym_js_comment_character_set_1(lookahead)) ADVANCE(331);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(334);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(sym_js_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(331);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(sym_plain_value);
      if (lookahead == '/') ADVANCE(65);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(333);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(sym_plain_value);
      if (lookahead == '/') ADVANCE(330);
      if (!sym_plain_value_character_set_1(lookahead)) ADVANCE(334);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 67, .external_lex_state = 2},
  [2] = {.lex_state = 67, .external_lex_state = 2},
  [3] = {.lex_state = 67, .external_lex_state = 2},
  [4] = {.lex_state = 67, .external_lex_state = 2},
  [5] = {.lex_state = 67, .external_lex_state = 2},
  [6] = {.lex_state = 67, .external_lex_state = 2},
  [7] = {.lex_state = 67, .external_lex_state = 2},
  [8] = {.lex_state = 67, .external_lex_state = 2},
  [9] = {.lex_state = 67, .external_lex_state = 2},
  [10] = {.lex_state = 67, .external_lex_state = 2},
  [11] = {.lex_state = 2, .external_lex_state = 2},
  [12] = {.lex_state = 2, .external_lex_state = 2},
  [13] = {.lex_state = 2, .external_lex_state = 2},
  [14] = {.lex_state = 2, .external_lex_state = 2},
  [15] = {.lex_state = 2, .external_lex_state = 2},
  [16] = {.lex_state = 8},
  [17] = {.lex_state = 8},
  [18] = {.lex_state = 8},
  [19] = {.lex_state = 5},
  [20] = {.lex_state = 5},
  [21] = {.lex_state = 5},
  [22] = {.lex_state = 3, .external_lex_state = 3},
  [23] = {.lex_state = 2},
  [24] = {.lex_state = 2},
  [25] = {.lex_state = 2},
  [26] = {.lex_state = 2},
  [27] = {.lex_state = 5, .external_lex_state = 3},
  [28] = {.lex_state = 2},
  [29] = {.lex_state = 2},
  [30] = {.lex_state = 5, .external_lex_state = 3},
  [31] = {.lex_state = 2},
  [32] = {.lex_state = 2},
  [33] = {.lex_state = 2},
  [34] = {.lex_state = 67, .external_lex_state = 2},
  [35] = {.lex_state = 67, .external_lex_state = 2},
  [36] = {.lex_state = 10, .external_lex_state = 3},
  [37] = {.lex_state = 67, .external_lex_state = 2},
  [38] = {.lex_state = 2},
  [39] = {.lex_state = 67, .external_lex_state = 2},
  [40] = {.lex_state = 67, .external_lex_state = 2},
  [41] = {.lex_state = 2},
  [42] = {.lex_state = 67, .external_lex_state = 2},
  [43] = {.lex_state = 67, .external_lex_state = 2},
  [44] = {.lex_state = 67, .external_lex_state = 2},
  [45] = {.lex_state = 67, .external_lex_state = 2},
  [46] = {.lex_state = 2},
  [47] = {.lex_state = 2},
  [48] = {.lex_state = 9, .external_lex_state = 3},
  [49] = {.lex_state = 9, .external_lex_state = 3},
  [50] = {.lex_state = 2},
  [51] = {.lex_state = 2},
  [52] = {.lex_state = 4},
  [53] = {.lex_state = 9, .external_lex_state = 3},
  [54] = {.lex_state = 2},
  [55] = {.lex_state = 9, .external_lex_state = 3},
  [56] = {.lex_state = 2},
  [57] = {.lex_state = 3},
  [58] = {.lex_state = 2},
  [59] = {.lex_state = 2},
  [60] = {.lex_state = 9, .external_lex_state = 3},
  [61] = {.lex_state = 9, .external_lex_state = 3},
  [62] = {.lex_state = 2},
  [63] = {.lex_state = 2},
  [64] = {.lex_state = 9, .external_lex_state = 3},
  [65] = {.lex_state = 2},
  [66] = {.lex_state = 9, .external_lex_state = 3},
  [67] = {.lex_state = 9, .external_lex_state = 3},
  [68] = {.lex_state = 9, .external_lex_state = 3},
  [69] = {.lex_state = 9, .external_lex_state = 3},
  [70] = {.lex_state = 2},
  [71] = {.lex_state = 2},
  [72] = {.lex_state = 2},
  [73] = {.lex_state = 2},
  [74] = {.lex_state = 2},
  [75] = {.lex_state = 2},
  [76] = {.lex_state = 2},
  [77] = {.lex_state = 9, .external_lex_state = 3},
  [78] = {.lex_state = 2},
  [79] = {.lex_state = 9, .external_lex_state = 3},
  [80] = {.lex_state = 9, .external_lex_state = 3},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 9, .external_lex_state = 3},
  [83] = {.lex_state = 2},
  [84] = {.lex_state = 2},
  [85] = {.lex_state = 9, .external_lex_state = 3},
  [86] = {.lex_state = 2},
  [87] = {.lex_state = 9, .external_lex_state = 3},
  [88] = {.lex_state = 1},
  [89] = {.lex_state = 2},
  [90] = {.lex_state = 1},
  [91] = {.lex_state = 2},
  [92] = {.lex_state = 9, .external_lex_state = 3},
  [93] = {.lex_state = 9, .external_lex_state = 3},
  [94] = {.lex_state = 2},
  [95] = {.lex_state = 9, .external_lex_state = 3},
  [96] = {.lex_state = 9, .external_lex_state = 3},
  [97] = {.lex_state = 9, .external_lex_state = 3},
  [98] = {.lex_state = 2},
  [99] = {.lex_state = 9, .external_lex_state = 3},
  [100] = {.lex_state = 9, .external_lex_state = 3},
  [101] = {.lex_state = 9, .external_lex_state = 3},
  [102] = {.lex_state = 2},
  [103] = {.lex_state = 9, .external_lex_state = 3},
  [104] = {.lex_state = 9, .external_lex_state = 3},
  [105] = {.lex_state = 9, .external_lex_state = 3},
  [106] = {.lex_state = 9, .external_lex_state = 3},
  [107] = {.lex_state = 9, .external_lex_state = 3},
  [108] = {.lex_state = 67, .external_lex_state = 2},
  [109] = {.lex_state = 67, .external_lex_state = 2},
  [110] = {.lex_state = 67, .external_lex_state = 2},
  [111] = {.lex_state = 67, .external_lex_state = 2},
  [112] = {.lex_state = 67, .external_lex_state = 2},
  [113] = {.lex_state = 5},
  [114] = {.lex_state = 67, .external_lex_state = 2},
  [115] = {.lex_state = 5},
  [116] = {.lex_state = 67, .external_lex_state = 2},
  [117] = {.lex_state = 67, .external_lex_state = 2},
  [118] = {.lex_state = 67, .external_lex_state = 2},
  [119] = {.lex_state = 5},
  [120] = {.lex_state = 5},
  [121] = {.lex_state = 67, .external_lex_state = 2},
  [122] = {.lex_state = 67, .external_lex_state = 2},
  [123] = {.lex_state = 67, .external_lex_state = 2},
  [124] = {.lex_state = 67, .external_lex_state = 2},
  [125] = {.lex_state = 67, .external_lex_state = 2},
  [126] = {.lex_state = 67, .external_lex_state = 2},
  [127] = {.lex_state = 67, .external_lex_state = 2},
  [128] = {.lex_state = 67, .external_lex_state = 2},
  [129] = {.lex_state = 67, .external_lex_state = 2},
  [130] = {.lex_state = 5},
  [131] = {.lex_state = 67, .external_lex_state = 2},
  [132] = {.lex_state = 67, .external_lex_state = 2},
  [133] = {.lex_state = 67, .external_lex_state = 2},
  [134] = {.lex_state = 67, .external_lex_state = 2},
  [135] = {.lex_state = 67, .external_lex_state = 2},
  [136] = {.lex_state = 5},
  [137] = {.lex_state = 67, .external_lex_state = 2},
  [138] = {.lex_state = 5},
  [139] = {.lex_state = 5},
  [140] = {.lex_state = 5},
  [141] = {.lex_state = 67, .external_lex_state = 2},
  [142] = {.lex_state = 67, .external_lex_state = 2},
  [143] = {.lex_state = 67, .external_lex_state = 2},
  [144] = {.lex_state = 67, .external_lex_state = 2},
  [145] = {.lex_state = 5},
  [146] = {.lex_state = 67, .external_lex_state = 2},
  [147] = {.lex_state = 5},
  [148] = {.lex_state = 67, .external_lex_state = 2},
  [149] = {.lex_state = 67, .external_lex_state = 2},
  [150] = {.lex_state = 67, .external_lex_state = 2},
  [151] = {.lex_state = 67, .external_lex_state = 2},
  [152] = {.lex_state = 67, .external_lex_state = 2},
  [153] = {.lex_state = 67, .external_lex_state = 2},
  [154] = {.lex_state = 67, .external_lex_state = 2},
  [155] = {.lex_state = 67, .external_lex_state = 2},
  [156] = {.lex_state = 67, .external_lex_state = 2},
  [157] = {.lex_state = 5},
  [158] = {.lex_state = 67, .external_lex_state = 2},
  [159] = {.lex_state = 67, .external_lex_state = 2},
  [160] = {.lex_state = 67, .external_lex_state = 2},
  [161] = {.lex_state = 67, .external_lex_state = 2},
  [162] = {.lex_state = 67, .external_lex_state = 2},
  [163] = {.lex_state = 67, .external_lex_state = 2},
  [164] = {.lex_state = 67, .external_lex_state = 2},
  [165] = {.lex_state = 67, .external_lex_state = 2},
  [166] = {.lex_state = 5},
  [167] = {.lex_state = 5},
  [168] = {.lex_state = 5},
  [169] = {.lex_state = 5},
  [170] = {.lex_state = 5},
  [171] = {.lex_state = 9, .external_lex_state = 3},
  [172] = {.lex_state = 9, .external_lex_state = 3},
  [173] = {.lex_state = 5},
  [174] = {.lex_state = 5},
  [175] = {.lex_state = 5},
  [176] = {.lex_state = 9, .external_lex_state = 3},
  [177] = {.lex_state = 5},
  [178] = {.lex_state = 9, .external_lex_state = 3},
  [179] = {.lex_state = 17},
  [180] = {.lex_state = 17},
  [181] = {.lex_state = 13, .external_lex_state = 3},
  [182] = {.lex_state = 13, .external_lex_state = 3},
  [183] = {.lex_state = 19},
  [184] = {.lex_state = 67, .external_lex_state = 3},
  [185] = {.lex_state = 67, .external_lex_state = 3},
  [186] = {.lex_state = 67, .external_lex_state = 3},
  [187] = {.lex_state = 67, .external_lex_state = 3},
  [188] = {.lex_state = 67, .external_lex_state = 3},
  [189] = {.lex_state = 67, .external_lex_state = 3},
  [190] = {.lex_state = 16},
  [191] = {.lex_state = 67, .external_lex_state = 3},
  [192] = {.lex_state = 67, .external_lex_state = 3},
  [193] = {.lex_state = 17},
  [194] = {.lex_state = 15},
  [195] = {.lex_state = 15},
  [196] = {.lex_state = 19},
  [197] = {.lex_state = 19},
  [198] = {.lex_state = 19},
  [199] = {.lex_state = 19},
  [200] = {.lex_state = 19},
  [201] = {.lex_state = 19},
  [202] = {.lex_state = 19},
  [203] = {.lex_state = 19},
  [204] = {.lex_state = 67, .external_lex_state = 3},
  [205] = {.lex_state = 17},
  [206] = {.lex_state = 17},
  [207] = {.lex_state = 17},
  [208] = {.lex_state = 17},
  [209] = {.lex_state = 17},
  [210] = {.lex_state = 17},
  [211] = {.lex_state = 17},
  [212] = {.lex_state = 17},
  [213] = {.lex_state = 13},
  [214] = {.lex_state = 17},
  [215] = {.lex_state = 13},
  [216] = {.lex_state = 17},
  [217] = {.lex_state = 67, .external_lex_state = 3},
  [218] = {.lex_state = 17},
  [219] = {.lex_state = 21},
  [220] = {.lex_state = 21},
  [221] = {.lex_state = 13},
  [222] = {.lex_state = 13},
  [223] = {.lex_state = 13},
  [224] = {.lex_state = 13},
  [225] = {.lex_state = 13},
  [226] = {.lex_state = 13},
  [227] = {.lex_state = 13},
  [228] = {.lex_state = 13},
  [229] = {.lex_state = 13},
  [230] = {.lex_state = 13},
  [231] = {.lex_state = 13},
  [232] = {.lex_state = 13},
  [233] = {.lex_state = 13},
  [234] = {.lex_state = 67},
  [235] = {.lex_state = 13},
  [236] = {.lex_state = 56},
  [237] = {.lex_state = 67},
  [238] = {.lex_state = 9},
  [239] = {.lex_state = 56},
  [240] = {.lex_state = 56},
  [241] = {.lex_state = 9},
  [242] = {.lex_state = 13},
  [243] = {.lex_state = 56},
  [244] = {.lex_state = 56},
  [245] = {.lex_state = 13},
  [246] = {.lex_state = 9},
  [247] = {.lex_state = 9},
  [248] = {.lex_state = 9},
  [249] = {.lex_state = 9},
  [250] = {.lex_state = 9},
  [251] = {.lex_state = 9},
  [252] = {.lex_state = 9},
  [253] = {.lex_state = 9},
  [254] = {.lex_state = 13},
  [255] = {.lex_state = 67},
  [256] = {.lex_state = 13},
  [257] = {.lex_state = 67},
  [258] = {.lex_state = 13},
  [259] = {.lex_state = 67},
  [260] = {.lex_state = 9},
  [261] = {.lex_state = 13},
  [262] = {.lex_state = 13},
  [263] = {.lex_state = 9},
  [264] = {.lex_state = 13},
  [265] = {.lex_state = 13},
  [266] = {.lex_state = 67},
  [267] = {.lex_state = 9},
  [268] = {.lex_state = 9},
  [269] = {.lex_state = 67},
  [270] = {.lex_state = 67},
  [271] = {.lex_state = 9},
  [272] = {.lex_state = 67},
  [273] = {.lex_state = 67},
  [274] = {.lex_state = 56},
  [275] = {.lex_state = 56},
  [276] = {.lex_state = 67},
  [277] = {.lex_state = 9},
  [278] = {.lex_state = 56},
  [279] = {.lex_state = 67},
  [280] = {.lex_state = 67},
  [281] = {.lex_state = 56},
  [282] = {.lex_state = 67},
  [283] = {.lex_state = 67},
  [284] = {.lex_state = 67},
  [285] = {.lex_state = 67},
  [286] = {.lex_state = 67},
  [287] = {.lex_state = 9},
  [288] = {.lex_state = 67},
  [289] = {.lex_state = 67},
  [290] = {.lex_state = 67},
  [291] = {.lex_state = 67},
  [292] = {.lex_state = 67},
  [293] = {.lex_state = 67},
  [294] = {.lex_state = 32},
  [295] = {.lex_state = 67},
  [296] = {.lex_state = 67},
  [297] = {.lex_state = 67},
  [298] = {.lex_state = 26},
  [299] = {.lex_state = 67},
  [300] = {.lex_state = 26},
  [301] = {.lex_state = 67},
  [302] = {.lex_state = 67},
  [303] = {.lex_state = 67},
  [304] = {.lex_state = 67},
  [305] = {.lex_state = 67},
  [306] = {.lex_state = 67},
  [307] = {.lex_state = 67},
  [308] = {.lex_state = 67},
  [309] = {.lex_state = 67},
  [310] = {.lex_state = 67},
  [311] = {.lex_state = 67},
  [312] = {.lex_state = 9},
  [313] = {.lex_state = 67},
  [314] = {.lex_state = 67},
  [315] = {.lex_state = 67},
  [316] = {.lex_state = 67},
  [317] = {.lex_state = 67},
  [318] = {.lex_state = 67},
  [319] = {.lex_state = 9},
  [320] = {.lex_state = 67},
  [321] = {.lex_state = 67},
  [322] = {.lex_state = 67},
  [323] = {.lex_state = 67},
  [324] = {.lex_state = 67},
  [325] = {.lex_state = 67},
  [326] = {.lex_state = 67},
  [327] = {.lex_state = 67},
  [328] = {.lex_state = 67},
  [329] = {.lex_state = 19},
  [330] = {.lex_state = 67},
  [331] = {.lex_state = 67},
  [332] = {.lex_state = 9},
  [333] = {.lex_state = 168},
  [334] = {.lex_state = 178},
  [335] = {.lex_state = 67},
  [336] = {.lex_state = 67},
  [337] = {.lex_state = 178},
  [338] = {.lex_state = 168},
  [339] = {.lex_state = 67},
  [340] = {.lex_state = 67},
  [341] = {.lex_state = 168},
  [342] = {.lex_state = 178},
  [343] = {.lex_state = 67},
  [344] = {.lex_state = 67},
  [345] = {.lex_state = 168},
  [346] = {.lex_state = 178},
  [347] = {.lex_state = 168},
  [348] = {.lex_state = 178},
  [349] = {.lex_state = 168},
  [350] = {.lex_state = 178},
  [351] = {.lex_state = 67},
};

enum {
  ts_external_token__descendant_operator = 0,
  ts_external_token__pseudo_class_selector_colon = 1,
  ts_external_token___error_recovery = 2,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__descendant_operator] = sym__descendant_operator,
  [ts_external_token__pseudo_class_selector_colon] = sym__pseudo_class_selector_colon,
  [ts_external_token___error_recovery] = sym___error_recovery,
};

static const bool ts_external_scanner_states[4][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__descendant_operator] = true,
    [ts_external_token__pseudo_class_selector_colon] = true,
    [ts_external_token___error_recovery] = true,
  },
  [2] = {
    [ts_external_token__pseudo_class_selector_colon] = true,
  },
  [3] = {
    [ts_external_token__descendant_operator] = true,
    [ts_external_token__pseudo_class_selector_colon] = true,
  },
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_ATimport] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_ATmedia] = ACTIONS(1),
    [anon_sym_ATcharset] = ACTIONS(1),
    [anon_sym_ATnamespace] = ACTIONS(1),
    [anon_sym_ATkeyframes] = ACTIONS(1),
    [aux_sym_keyframes_statement_token1] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym_from] = ACTIONS(1),
    [sym_to] = ACTIONS(1),
    [anon_sym_ATsupports] = ACTIONS(1),
    [sym_nesting_selector] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_COLON_COLON] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_TILDE_EQ] = ACTIONS(1),
    [anon_sym_CARET_EQ] = ACTIONS(1),
    [anon_sym_PIPE_EQ] = ACTIONS(1),
    [anon_sym_STAR_EQ] = ACTIONS(1),
    [anon_sym_DOLLAR_EQ] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_TILDE] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [sym_important] = ACTIONS(1),
    [anon_sym_LPAREN2] = ACTIONS(1),
    [anon_sym_and] = ACTIONS(1),
    [anon_sym_or] = ACTIONS(1),
    [anon_sym_not] = ACTIONS(1),
    [anon_sym_only] = ACTIONS(1),
    [anon_sym_selector] = ACTIONS(1),
    [aux_sym_color_value_token1] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym_boolean_value] = ACTIONS(1),
    [aux_sym_integer_value_token1] = ACTIONS(1),
    [aux_sym_float_value_token1] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [sym_at_keyword] = ACTIONS(1),
    [sym_js_comment] = ACTIONS(3),
    [sym_comment] = ACTIONS(5),
    [sym__descendant_operator] = ACTIONS(1),
    [sym__pseudo_class_selector_colon] = ACTIONS(1),
    [sym___error_recovery] = ACTIONS(1),
  },
  [1] = {
    [sym_stylesheet] = STATE(336),
    [sym_import_statement] = STATE(10),
    [sym_media_statement] = STATE(10),
    [sym_charset_statement] = STATE(10),
    [sym_namespace_statement] = STATE(10),
    [sym_keyframes_statement] = STATE(10),
    [sym_supports_statement] = STATE(10),
    [sym_at_rule] = STATE(10),
    [sym_rule_set] = STATE(10),
    [sym_selectors] = STATE(297),
    [sym__selector] = STATE(189),
    [sym_universal_selector] = STATE(189),
    [sym_class_selector] = STATE(189),
    [sym_pseudo_class_selector] = STATE(189),
    [sym_pseudo_element_selector] = STATE(189),
    [sym_id_selector] = STATE(189),
    [sym_attribute_selector] = STATE(189),
    [sym_child_selector] = STATE(189),
    [sym_descendant_selector] = STATE(189),
    [sym_sibling_selector] = STATE(189),
    [sym_adjacent_sibling_selector] = STATE(189),
    [sym_namespace_selector] = STATE(189),
    [sym_declaration] = STATE(10),
    [sym_string_value] = STATE(189),
    [aux_sym_stylesheet_repeat1] = STATE(10),
    [ts_builtin_sym_end] = ACTIONS(7),
    [anon_sym_ATimport] = ACTIONS(9),
    [anon_sym_ATmedia] = ACTIONS(11),
    [anon_sym_ATcharset] = ACTIONS(13),
    [anon_sym_ATnamespace] = ACTIONS(15),
    [anon_sym_ATkeyframes] = ACTIONS(17),
    [aux_sym_keyframes_statement_token1] = ACTIONS(17),
    [anon_sym_ATsupports] = ACTIONS(19),
    [sym_nesting_selector] = ACTIONS(21),
    [anon_sym_STAR] = ACTIONS(23),
    [anon_sym_DOT] = ACTIONS(25),
    [anon_sym_COLON_COLON] = ACTIONS(27),
    [anon_sym_POUND] = ACTIONS(29),
    [anon_sym_LBRACK] = ACTIONS(31),
    [anon_sym_SQUOTE] = ACTIONS(33),
    [anon_sym_DQUOTE] = ACTIONS(35),
    [sym_identifier] = ACTIONS(37),
    [sym_at_keyword] = ACTIONS(39),
    [sym_js_comment] = ACTIONS(5),
    [sym_comment] = ACTIONS(5),
    [sym__pseudo_class_selector_colon] = ACTIONS(41),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 23,
    ACTIONS(21), 1,
      sym_nesting_selector,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(43), 1,
      anon_sym_ATimport,
    ACTIONS(45), 1,
      anon_sym_ATmedia,
    ACTIONS(47), 1,
      anon_sym_ATcharset,
    ACTIONS(49), 1,
      anon_sym_ATnamespace,
    ACTIONS(53), 1,
      anon_sym_RBRACE,
    ACTIONS(55), 1,
      anon_sym_ATsupports,
    ACTIONS(57), 1,
      sym_identifier,
    ACTIONS(59), 1,
      sym_at_keyword,
    STATE(299), 1,
      sym_selectors,
    STATE(320), 1,
      sym_last_declaration,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(51), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(8), 11,
      sym_import_statement,
      sym_media_statement,
      sym_charset_statement,
      sym_namespace_statement,
      sym_keyframes_statement,
      sym_supports_statement,
      sym_postcss_statement,
      sym_at_rule,
      sym_rule_set,
      sym_declaration,
      aux_sym_block_repeat1,
    STATE(189), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [94] = 23,
    ACTIONS(21), 1,
      sym_nesting_selector,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(43), 1,
      anon_sym_ATimport,
    ACTIONS(45), 1,
      anon_sym_ATmedia,
    ACTIONS(47), 1,
      anon_sym_ATcharset,
    ACTIONS(49), 1,
      anon_sym_ATnamespace,
    ACTIONS(55), 1,
      anon_sym_ATsupports,
    ACTIONS(57), 1,
      sym_identifier,
    ACTIONS(59), 1,
      sym_at_keyword,
    ACTIONS(61), 1,
      anon_sym_RBRACE,
    STATE(299), 1,
      sym_selectors,
    STATE(328), 1,
      sym_last_declaration,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(51), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(4), 11,
      sym_import_statement,
      sym_media_statement,
      sym_charset_statement,
      sym_namespace_statement,
      sym_keyframes_statement,
      sym_supports_statement,
      sym_postcss_statement,
      sym_at_rule,
      sym_rule_set,
      sym_declaration,
      aux_sym_block_repeat1,
    STATE(189), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [188] = 23,
    ACTIONS(21), 1,
      sym_nesting_selector,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(43), 1,
      anon_sym_ATimport,
    ACTIONS(45), 1,
      anon_sym_ATmedia,
    ACTIONS(47), 1,
      anon_sym_ATcharset,
    ACTIONS(49), 1,
      anon_sym_ATnamespace,
    ACTIONS(55), 1,
      anon_sym_ATsupports,
    ACTIONS(57), 1,
      sym_identifier,
    ACTIONS(59), 1,
      sym_at_keyword,
    ACTIONS(63), 1,
      anon_sym_RBRACE,
    STATE(299), 1,
      sym_selectors,
    STATE(309), 1,
      sym_last_declaration,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(51), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(8), 11,
      sym_import_statement,
      sym_media_statement,
      sym_charset_statement,
      sym_namespace_statement,
      sym_keyframes_statement,
      sym_supports_statement,
      sym_postcss_statement,
      sym_at_rule,
      sym_rule_set,
      sym_declaration,
      aux_sym_block_repeat1,
    STATE(189), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [282] = 23,
    ACTIONS(21), 1,
      sym_nesting_selector,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(43), 1,
      anon_sym_ATimport,
    ACTIONS(45), 1,
      anon_sym_ATmedia,
    ACTIONS(47), 1,
      anon_sym_ATcharset,
    ACTIONS(49), 1,
      anon_sym_ATnamespace,
    ACTIONS(55), 1,
      anon_sym_ATsupports,
    ACTIONS(57), 1,
      sym_identifier,
    ACTIONS(59), 1,
      sym_at_keyword,
    ACTIONS(65), 1,
      anon_sym_RBRACE,
    STATE(299), 1,
      sym_selectors,
    STATE(310), 1,
      sym_last_declaration,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(51), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(8), 11,
      sym_import_statement,
      sym_media_statement,
      sym_charset_statement,
      sym_namespace_statement,
      sym_keyframes_statement,
      sym_supports_statement,
      sym_postcss_statement,
      sym_at_rule,
      sym_rule_set,
      sym_declaration,
      aux_sym_block_repeat1,
    STATE(189), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [376] = 23,
    ACTIONS(21), 1,
      sym_nesting_selector,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(43), 1,
      anon_sym_ATimport,
    ACTIONS(45), 1,
      anon_sym_ATmedia,
    ACTIONS(47), 1,
      anon_sym_ATcharset,
    ACTIONS(49), 1,
      anon_sym_ATnamespace,
    ACTIONS(55), 1,
      anon_sym_ATsupports,
    ACTIONS(57), 1,
      sym_identifier,
    ACTIONS(59), 1,
      sym_at_keyword,
    ACTIONS(67), 1,
      anon_sym_RBRACE,
    STATE(299), 1,
      sym_selectors,
    STATE(317), 1,
      sym_last_declaration,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(51), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(2), 11,
      sym_import_statement,
      sym_media_statement,
      sym_charset_statement,
      sym_namespace_statement,
      sym_keyframes_statement,
      sym_supports_statement,
      sym_postcss_statement,
      sym_at_rule,
      sym_rule_set,
      sym_declaration,
      aux_sym_block_repeat1,
    STATE(189), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [470] = 23,
    ACTIONS(21), 1,
      sym_nesting_selector,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(43), 1,
      anon_sym_ATimport,
    ACTIONS(45), 1,
      anon_sym_ATmedia,
    ACTIONS(47), 1,
      anon_sym_ATcharset,
    ACTIONS(49), 1,
      anon_sym_ATnamespace,
    ACTIONS(55), 1,
      anon_sym_ATsupports,
    ACTIONS(57), 1,
      sym_identifier,
    ACTIONS(59), 1,
      sym_at_keyword,
    ACTIONS(69), 1,
      anon_sym_RBRACE,
    STATE(299), 1,
      sym_selectors,
    STATE(327), 1,
      sym_last_declaration,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(51), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(5), 11,
      sym_import_statement,
      sym_media_statement,
      sym_charset_statement,
      sym_namespace_statement,
      sym_keyframes_statement,
      sym_supports_statement,
      sym_postcss_statement,
      sym_at_rule,
      sym_rule_set,
      sym_declaration,
      aux_sym_block_repeat1,
    STATE(189), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [564] = 22,
    ACTIONS(71), 1,
      anon_sym_ATimport,
    ACTIONS(74), 1,
      anon_sym_ATmedia,
    ACTIONS(77), 1,
      anon_sym_ATcharset,
    ACTIONS(80), 1,
      anon_sym_ATnamespace,
    ACTIONS(86), 1,
      anon_sym_RBRACE,
    ACTIONS(88), 1,
      anon_sym_ATsupports,
    ACTIONS(91), 1,
      sym_nesting_selector,
    ACTIONS(94), 1,
      anon_sym_STAR,
    ACTIONS(97), 1,
      anon_sym_DOT,
    ACTIONS(100), 1,
      anon_sym_COLON_COLON,
    ACTIONS(103), 1,
      anon_sym_POUND,
    ACTIONS(106), 1,
      anon_sym_LBRACK,
    ACTIONS(109), 1,
      anon_sym_SQUOTE,
    ACTIONS(112), 1,
      anon_sym_DQUOTE,
    ACTIONS(115), 1,
      sym_identifier,
    ACTIONS(118), 1,
      sym_at_keyword,
    ACTIONS(121), 1,
      sym__pseudo_class_selector_colon,
    STATE(299), 1,
      sym_selectors,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(83), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(8), 11,
      sym_import_statement,
      sym_media_statement,
      sym_charset_statement,
      sym_namespace_statement,
      sym_keyframes_statement,
      sym_supports_statement,
      sym_postcss_statement,
      sym_at_rule,
      sym_rule_set,
      sym_declaration,
      aux_sym_block_repeat1,
    STATE(189), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [655] = 22,
    ACTIONS(124), 1,
      ts_builtin_sym_end,
    ACTIONS(126), 1,
      anon_sym_ATimport,
    ACTIONS(129), 1,
      anon_sym_ATmedia,
    ACTIONS(132), 1,
      anon_sym_ATcharset,
    ACTIONS(135), 1,
      anon_sym_ATnamespace,
    ACTIONS(141), 1,
      anon_sym_ATsupports,
    ACTIONS(144), 1,
      sym_nesting_selector,
    ACTIONS(147), 1,
      anon_sym_STAR,
    ACTIONS(150), 1,
      anon_sym_DOT,
    ACTIONS(153), 1,
      anon_sym_COLON_COLON,
    ACTIONS(156), 1,
      anon_sym_POUND,
    ACTIONS(159), 1,
      anon_sym_LBRACK,
    ACTIONS(162), 1,
      anon_sym_SQUOTE,
    ACTIONS(165), 1,
      anon_sym_DQUOTE,
    ACTIONS(168), 1,
      sym_identifier,
    ACTIONS(171), 1,
      sym_at_keyword,
    ACTIONS(174), 1,
      sym__pseudo_class_selector_colon,
    STATE(297), 1,
      sym_selectors,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(138), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(9), 10,
      sym_import_statement,
      sym_media_statement,
      sym_charset_statement,
      sym_namespace_statement,
      sym_keyframes_statement,
      sym_supports_statement,
      sym_at_rule,
      sym_rule_set,
      sym_declaration,
      aux_sym_stylesheet_repeat1,
    STATE(189), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [745] = 22,
    ACTIONS(9), 1,
      anon_sym_ATimport,
    ACTIONS(11), 1,
      anon_sym_ATmedia,
    ACTIONS(13), 1,
      anon_sym_ATcharset,
    ACTIONS(15), 1,
      anon_sym_ATnamespace,
    ACTIONS(19), 1,
      anon_sym_ATsupports,
    ACTIONS(21), 1,
      sym_nesting_selector,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(37), 1,
      sym_identifier,
    ACTIONS(39), 1,
      sym_at_keyword,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(177), 1,
      ts_builtin_sym_end,
    STATE(297), 1,
      sym_selectors,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(17), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(9), 10,
      sym_import_statement,
      sym_media_statement,
      sym_charset_statement,
      sym_namespace_statement,
      sym_keyframes_statement,
      sym_supports_statement,
      sym_at_rule,
      sym_rule_set,
      sym_declaration,
      aux_sym_stylesheet_repeat1,
    STATE(189), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [835] = 22,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(179), 1,
      sym_nesting_selector,
    ACTIONS(181), 1,
      anon_sym_DOT,
    ACTIONS(183), 1,
      anon_sym_POUND,
    ACTIONS(185), 1,
      anon_sym_LBRACK,
    ACTIONS(187), 1,
      anon_sym_RPAREN,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(193), 1,
      anon_sym_SQUOTE,
    ACTIONS(195), 1,
      anon_sym_DQUOTE,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(203), 1,
      sym_identifier,
    STATE(26), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(27), 1,
      sym_string_value,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(167), 8,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
    STATE(186), 12,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
  [921] = 22,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(181), 1,
      anon_sym_DOT,
    ACTIONS(183), 1,
      anon_sym_POUND,
    ACTIONS(185), 1,
      anon_sym_LBRACK,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(193), 1,
      anon_sym_SQUOTE,
    ACTIONS(195), 1,
      anon_sym_DQUOTE,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(203), 1,
      sym_identifier,
    ACTIONS(205), 1,
      sym_nesting_selector,
    ACTIONS(207), 1,
      anon_sym_RPAREN,
    STATE(27), 1,
      sym_string_value,
    STATE(29), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(167), 8,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
    STATE(188), 12,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
  [1007] = 21,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(181), 1,
      anon_sym_DOT,
    ACTIONS(183), 1,
      anon_sym_POUND,
    ACTIONS(185), 1,
      anon_sym_LBRACK,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(193), 1,
      anon_sym_SQUOTE,
    ACTIONS(195), 1,
      anon_sym_DQUOTE,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(203), 1,
      sym_identifier,
    ACTIONS(209), 1,
      sym_nesting_selector,
    STATE(27), 1,
      sym_string_value,
    STATE(38), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(167), 8,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
    STATE(192), 12,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
  [1090] = 21,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(181), 1,
      anon_sym_DOT,
    ACTIONS(211), 1,
      sym_nesting_selector,
    ACTIONS(213), 1,
      anon_sym_POUND,
    ACTIONS(215), 1,
      anon_sym_LBRACK,
    ACTIONS(217), 1,
      sym_important,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(221), 1,
      anon_sym_SQUOTE,
    ACTIONS(223), 1,
      anon_sym_DQUOTE,
    ACTIONS(227), 1,
      aux_sym_integer_value_token1,
    ACTIONS(229), 1,
      aux_sym_float_value_token1,
    ACTIONS(231), 1,
      sym_identifier,
    STATE(172), 1,
      sym_namespace_selector,
    STATE(181), 1,
      sym_string_value,
    ACTIONS(225), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(235), 8,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
    STATE(217), 11,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
  [1172] = 21,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(181), 1,
      anon_sym_DOT,
    ACTIONS(211), 1,
      sym_nesting_selector,
    ACTIONS(213), 1,
      anon_sym_POUND,
    ACTIONS(215), 1,
      anon_sym_LBRACK,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(221), 1,
      anon_sym_SQUOTE,
    ACTIONS(223), 1,
      anon_sym_DQUOTE,
    ACTIONS(227), 1,
      aux_sym_integer_value_token1,
    ACTIONS(229), 1,
      aux_sym_float_value_token1,
    ACTIONS(231), 1,
      sym_identifier,
    ACTIONS(233), 1,
      sym_important,
    STATE(172), 1,
      sym_namespace_selector,
    STATE(181), 1,
      sym_string_value,
    ACTIONS(235), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(233), 8,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
    STATE(217), 11,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
  [1254] = 20,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(237), 1,
      anon_sym_SEMI,
    ACTIONS(239), 1,
      anon_sym_LBRACE,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(245), 1,
      anon_sym_LPAREN2,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(255), 1,
      sym_identifier,
    STATE(54), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(146), 1,
      sym_block,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(238), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
    STATE(167), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1330] = 16,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(227), 1,
      aux_sym_integer_value_token1,
    ACTIONS(229), 1,
      aux_sym_float_value_token1,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(261), 1,
      sym_important,
    ACTIONS(263), 1,
      anon_sym_LPAREN2,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(271), 1,
      sym_identifier,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    ACTIONS(269), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(287), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
    STATE(261), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1394] = 16,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(227), 1,
      aux_sym_integer_value_token1,
    ACTIONS(229), 1,
      aux_sym_float_value_token1,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(263), 1,
      anon_sym_LPAREN2,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(271), 1,
      sym_identifier,
    ACTIONS(273), 1,
      sym_important,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    ACTIONS(275), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(287), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
    STATE(262), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1458] = 19,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(277), 1,
      anon_sym_COMMA,
    ACTIONS(279), 1,
      anon_sym_SEMI,
    ACTIONS(281), 1,
      anon_sym_RBRACE,
    ACTIONS(283), 1,
      anon_sym_STAR,
    ACTIONS(287), 1,
      sym_important,
    ACTIONS(291), 1,
      sym_identifier,
    STATE(28), 1,
      aux_sym_declaration_repeat1,
    ACTIONS(289), 2,
      sym_boolean_value,
      sym_plain_value,
    ACTIONS(285), 3,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_SLASH,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1527] = 18,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(277), 1,
      anon_sym_COMMA,
    ACTIONS(279), 1,
      anon_sym_SEMI,
    ACTIONS(283), 1,
      anon_sym_STAR,
    ACTIONS(291), 1,
      sym_identifier,
    ACTIONS(293), 1,
      sym_important,
    STATE(46), 1,
      aux_sym_declaration_repeat1,
    ACTIONS(289), 2,
      sym_boolean_value,
      sym_plain_value,
    ACTIONS(285), 3,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_SLASH,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1593] = 18,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(277), 1,
      anon_sym_COMMA,
    ACTIONS(283), 1,
      anon_sym_STAR,
    ACTIONS(291), 1,
      sym_identifier,
    ACTIONS(295), 1,
      anon_sym_SEMI,
    ACTIONS(297), 1,
      sym_important,
    STATE(41), 1,
      aux_sym_declaration_repeat1,
    ACTIONS(289), 2,
      sym_boolean_value,
      sym_plain_value,
    ACTIONS(285), 3,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_SLASH,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1659] = 8,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(305), 1,
      anon_sym_LPAREN,
    STATE(145), 1,
      sym_arguments,
    ACTIONS(303), 2,
      anon_sym_DOT,
      anon_sym_PLUS,
    ACTIONS(301), 4,
      anon_sym_STAR,
      sym_important,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
    ACTIONS(307), 8,
      anon_sym_LPAREN2,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(299), 10,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_TILDE,
      anon_sym_PIPE,
      anon_sym_RPAREN,
  [1704] = 17,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(291), 1,
      sym_identifier,
    ACTIONS(311), 1,
      anon_sym_RPAREN,
    STATE(31), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(276), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    ACTIONS(309), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    STATE(167), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1766] = 17,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(291), 1,
      sym_identifier,
    ACTIONS(313), 1,
      anon_sym_RPAREN,
    STATE(31), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(273), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    ACTIONS(309), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    STATE(167), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1828] = 17,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(291), 1,
      sym_identifier,
    ACTIONS(315), 1,
      anon_sym_RPAREN,
    STATE(31), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(280), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    ACTIONS(309), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    STATE(167), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1890] = 17,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(291), 1,
      sym_identifier,
    ACTIONS(317), 1,
      anon_sym_COMMA,
    ACTIONS(319), 1,
      anon_sym_RPAREN,
    STATE(31), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(285), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(167), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1951] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(325), 2,
      anon_sym_DOT,
      anon_sym_PLUS,
    ACTIONS(323), 5,
      anon_sym_STAR,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
    ACTIONS(327), 7,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(321), 10,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_TILDE,
      anon_sym_PIPE,
      anon_sym_RPAREN,
  [1990] = 17,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(277), 1,
      anon_sym_COMMA,
    ACTIONS(291), 1,
      sym_identifier,
    ACTIONS(329), 1,
      anon_sym_SEMI,
    ACTIONS(331), 1,
      anon_sym_RBRACE,
    ACTIONS(333), 1,
      sym_important,
    STATE(32), 1,
      aux_sym_declaration_repeat1,
    ACTIONS(289), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [2051] = 17,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(291), 1,
      sym_identifier,
    ACTIONS(317), 1,
      anon_sym_COMMA,
    ACTIONS(335), 1,
      anon_sym_RPAREN,
    STATE(31), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(290), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(167), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [2112] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(339), 9,
      anon_sym_DOT,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(337), 15,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_TILDE,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [2147] = 15,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(343), 1,
      anon_sym_POUND,
    ACTIONS(346), 1,
      anon_sym_LBRACK,
    ACTIONS(349), 1,
      sym_important,
    ACTIONS(352), 1,
      anon_sym_LPAREN2,
    ACTIONS(355), 1,
      anon_sym_SQUOTE,
    ACTIONS(358), 1,
      anon_sym_DQUOTE,
    ACTIONS(364), 1,
      aux_sym_integer_value_token1,
    ACTIONS(367), 1,
      aux_sym_float_value_token1,
    ACTIONS(370), 1,
      sym_identifier,
    STATE(31), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(361), 2,
      sym_boolean_value,
      sym_plain_value,
    ACTIONS(341), 3,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    STATE(167), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [2204] = 16,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(373), 1,
      anon_sym_COMMA,
    ACTIONS(378), 1,
      anon_sym_POUND,
    ACTIONS(381), 1,
      anon_sym_LBRACK,
    ACTIONS(384), 1,
      sym_important,
    ACTIONS(387), 1,
      anon_sym_LPAREN2,
    ACTIONS(390), 1,
      anon_sym_SQUOTE,
    ACTIONS(393), 1,
      anon_sym_DQUOTE,
    ACTIONS(399), 1,
      aux_sym_integer_value_token1,
    ACTIONS(402), 1,
      aux_sym_float_value_token1,
    ACTIONS(405), 1,
      sym_identifier,
    STATE(32), 1,
      aux_sym_declaration_repeat1,
    ACTIONS(376), 2,
      anon_sym_SEMI,
      anon_sym_RBRACE,
    ACTIONS(396), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [2263] = 15,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(291), 1,
      sym_identifier,
    STATE(31), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    ACTIONS(408), 3,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    STATE(167), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [2320] = 12,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(410), 1,
      sym_nesting_selector,
    ACTIONS(412), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(96), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [2370] = 12,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(412), 1,
      sym_identifier,
    ACTIONS(414), 1,
      sym_nesting_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(101), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [2420] = 10,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(418), 1,
      anon_sym_RBRACK,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    STATE(223), 1,
      sym_arguments,
    ACTIONS(301), 2,
      anon_sym_COMMA,
      anon_sym_DASH,
    ACTIONS(303), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(307), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(416), 6,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
    ACTIONS(299), 8,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
  [2466] = 12,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(412), 1,
      sym_identifier,
    ACTIONS(422), 1,
      sym_nesting_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(191), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [2516] = 15,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(291), 1,
      sym_identifier,
    STATE(31), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    ACTIONS(424), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    STATE(167), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [2572] = 12,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(412), 1,
      sym_identifier,
    ACTIONS(426), 1,
      sym_nesting_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(107), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [2622] = 13,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(211), 1,
      sym_nesting_selector,
    ACTIONS(428), 1,
      sym_identifier,
    STATE(172), 1,
      sym_namespace_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(217), 12,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_string_value,
  [2674] = 16,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(277), 1,
      anon_sym_COMMA,
    ACTIONS(291), 1,
      sym_identifier,
    ACTIONS(430), 1,
      anon_sym_SEMI,
    ACTIONS(432), 1,
      sym_important,
    STATE(32), 1,
      aux_sym_declaration_repeat1,
    ACTIONS(289), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [2732] = 12,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(412), 1,
      sym_identifier,
    ACTIONS(434), 1,
      sym_nesting_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(204), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [2782] = 12,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(412), 1,
      sym_identifier,
    ACTIONS(436), 1,
      sym_nesting_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(93), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [2832] = 12,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(412), 1,
      sym_identifier,
    ACTIONS(438), 1,
      sym_nesting_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(95), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [2882] = 13,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(211), 1,
      sym_nesting_selector,
    ACTIONS(440), 1,
      sym_identifier,
    STATE(178), 1,
      sym_namespace_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(217), 12,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_string_value,
  [2934] = 16,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(277), 1,
      anon_sym_COMMA,
    ACTIONS(291), 1,
      sym_identifier,
    ACTIONS(329), 1,
      anon_sym_SEMI,
    ACTIONS(442), 1,
      sym_important,
    STATE(32), 1,
      aux_sym_declaration_repeat1,
    ACTIONS(289), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [2992] = 15,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(291), 1,
      sym_identifier,
    ACTIONS(444), 1,
      anon_sym_RPAREN,
    STATE(25), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(167), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3047] = 5,
    ACTIONS(450), 1,
      anon_sym_LPAREN,
    STATE(69), 1,
      sym_pseudo_class_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(448), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(446), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3082] = 5,
    ACTIONS(456), 1,
      anon_sym_LPAREN,
    STATE(68), 1,
      sym_pseudo_element_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(454), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(452), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3117] = 15,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(291), 1,
      sym_identifier,
    ACTIONS(458), 1,
      anon_sym_RPAREN,
    STATE(24), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(167), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3172] = 15,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(291), 1,
      sym_identifier,
    ACTIONS(460), 1,
      anon_sym_RPAREN,
    STATE(31), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(167), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3227] = 8,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(305), 1,
      anon_sym_LPAREN,
    STATE(145), 1,
      sym_arguments,
    ACTIONS(464), 2,
      anon_sym_and,
      anon_sym_or,
    ACTIONS(462), 3,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
    ACTIONS(301), 6,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
    ACTIONS(307), 9,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
  [3268] = 5,
    ACTIONS(456), 1,
      anon_sym_LPAREN,
    STATE(97), 1,
      sym_pseudo_element_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(468), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(466), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3303] = 15,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(291), 1,
      sym_identifier,
    ACTIONS(470), 1,
      anon_sym_SEMI,
    STATE(31), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(167), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3358] = 5,
    ACTIONS(450), 1,
      anon_sym_LPAREN,
    STATE(79), 1,
      sym_pseudo_class_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(474), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(472), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3393] = 15,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(291), 1,
      sym_identifier,
    ACTIONS(476), 1,
      anon_sym_RPAREN,
    STATE(23), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(167), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3448] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(305), 1,
      anon_sym_LPAREN,
    STATE(145), 1,
      sym_arguments,
    ACTIONS(307), 9,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(301), 10,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [3484] = 14,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(291), 1,
      sym_identifier,
    STATE(51), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(167), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3536] = 14,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(291), 1,
      sym_identifier,
    STATE(33), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(167), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3588] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(480), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(478), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3617] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(484), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(482), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3646] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(227), 1,
      aux_sym_integer_value_token1,
    ACTIONS(229), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(486), 1,
      sym_important,
    ACTIONS(490), 1,
      sym_identifier,
    ACTIONS(488), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(254), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3695] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(492), 1,
      anon_sym_POUND,
    ACTIONS(494), 1,
      anon_sym_LBRACK,
    ACTIONS(496), 1,
      sym_important,
    ACTIONS(498), 1,
      anon_sym_LPAREN2,
    ACTIONS(500), 1,
      anon_sym_SQUOTE,
    ACTIONS(502), 1,
      anon_sym_DQUOTE,
    ACTIONS(506), 1,
      aux_sym_integer_value_token1,
    ACTIONS(508), 1,
      aux_sym_float_value_token1,
    ACTIONS(510), 1,
      sym_identifier,
    ACTIONS(504), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(180), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3744] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(514), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(512), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3773] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(227), 1,
      aux_sym_integer_value_token1,
    ACTIONS(229), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(490), 1,
      sym_identifier,
    ACTIONS(516), 1,
      sym_important,
    ACTIONS(518), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(264), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3822] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(522), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(520), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3851] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(526), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(524), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3880] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(530), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(528), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3909] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(534), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(532), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3938] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(291), 1,
      sym_identifier,
    ACTIONS(536), 1,
      sym_important,
    ACTIONS(538), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(20), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3987] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(227), 1,
      aux_sym_integer_value_token1,
    ACTIONS(229), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(490), 1,
      sym_identifier,
    ACTIONS(540), 1,
      sym_important,
    ACTIONS(542), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(242), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4036] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(291), 1,
      sym_identifier,
    ACTIONS(544), 1,
      sym_important,
    ACTIONS(546), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(21), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4085] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(227), 1,
      aux_sym_integer_value_token1,
    ACTIONS(229), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(490), 1,
      sym_identifier,
    ACTIONS(548), 1,
      sym_important,
    ACTIONS(550), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(256), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4134] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(227), 1,
      aux_sym_integer_value_token1,
    ACTIONS(229), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(490), 1,
      sym_identifier,
    ACTIONS(552), 1,
      sym_important,
    ACTIONS(554), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(228), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4183] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(291), 1,
      sym_identifier,
    ACTIONS(556), 1,
      sym_important,
    ACTIONS(558), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(19), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4232] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(291), 1,
      sym_identifier,
    ACTIONS(560), 1,
      sym_important,
    ACTIONS(562), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(166), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4281] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(566), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(564), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4310] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(199), 1,
      aux_sym_integer_value_token1,
    ACTIONS(201), 1,
      aux_sym_float_value_token1,
    ACTIONS(241), 1,
      anon_sym_POUND,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(291), 1,
      sym_identifier,
    ACTIONS(568), 1,
      sym_important,
    ACTIONS(570), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(130), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4359] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(574), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(572), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4388] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(578), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(576), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4417] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(492), 1,
      anon_sym_POUND,
    ACTIONS(494), 1,
      anon_sym_LBRACK,
    ACTIONS(498), 1,
      anon_sym_LPAREN2,
    ACTIONS(500), 1,
      anon_sym_SQUOTE,
    ACTIONS(502), 1,
      anon_sym_DQUOTE,
    ACTIONS(506), 1,
      aux_sym_integer_value_token1,
    ACTIONS(508), 1,
      aux_sym_float_value_token1,
    ACTIONS(510), 1,
      sym_identifier,
    ACTIONS(580), 1,
      sym_important,
    ACTIONS(582), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(179), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4466] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(586), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(584), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4495] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(217), 1,
      sym_important,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(227), 1,
      aux_sym_integer_value_token1,
    ACTIONS(229), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(490), 1,
      sym_identifier,
    ACTIONS(225), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(235), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4544] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(227), 1,
      aux_sym_integer_value_token1,
    ACTIONS(229), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(273), 1,
      sym_important,
    ACTIONS(490), 1,
      sym_identifier,
    ACTIONS(275), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(262), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4593] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(590), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(588), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4622] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(492), 1,
      anon_sym_POUND,
    ACTIONS(494), 1,
      anon_sym_LBRACK,
    ACTIONS(498), 1,
      anon_sym_LPAREN2,
    ACTIONS(500), 1,
      anon_sym_SQUOTE,
    ACTIONS(502), 1,
      anon_sym_DQUOTE,
    ACTIONS(506), 1,
      aux_sym_integer_value_token1,
    ACTIONS(508), 1,
      aux_sym_float_value_token1,
    ACTIONS(510), 1,
      sym_identifier,
    ACTIONS(592), 1,
      sym_important,
    ACTIONS(594), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(214), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4671] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(598), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(596), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4700] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(604), 1,
      sym_unit,
    ACTIONS(602), 8,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(600), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [4733] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(227), 1,
      aux_sym_integer_value_token1,
    ACTIONS(229), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(490), 1,
      sym_identifier,
    ACTIONS(606), 1,
      sym_important,
    ACTIONS(608), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(245), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4782] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(614), 1,
      sym_unit,
    ACTIONS(612), 8,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(610), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [4815] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(227), 1,
      aux_sym_integer_value_token1,
    ACTIONS(229), 1,
      aux_sym_float_value_token1,
    ACTIONS(233), 1,
      sym_important,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(490), 1,
      sym_identifier,
    ACTIONS(235), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(233), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4864] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(618), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(616), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4893] = 4,
    ACTIONS(622), 1,
      anon_sym_DOT,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(624), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(620), 17,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4924] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(227), 1,
      aux_sym_integer_value_token1,
    ACTIONS(229), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(490), 1,
      sym_identifier,
    ACTIONS(626), 1,
      sym_important,
    ACTIONS(628), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(265), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4973] = 4,
    ACTIONS(622), 1,
      anon_sym_DOT,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(632), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(630), 17,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [5004] = 4,
    ACTIONS(622), 1,
      anon_sym_DOT,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(636), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(634), 17,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [5035] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(640), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(638), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [5064] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(227), 1,
      aux_sym_integer_value_token1,
    ACTIONS(229), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(490), 1,
      sym_identifier,
    ACTIONS(642), 1,
      sym_important,
    ACTIONS(644), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(258), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [5113] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(648), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(646), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [5142] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(339), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(337), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [5171] = 4,
    ACTIONS(622), 1,
      anon_sym_DOT,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(652), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(650), 17,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [5202] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(227), 1,
      aux_sym_integer_value_token1,
    ACTIONS(229), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(261), 1,
      sym_important,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(490), 1,
      sym_identifier,
    ACTIONS(269), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(261), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [5251] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(656), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(654), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [5280] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(660), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(658), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [5309] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(664), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(662), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [5338] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(303), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(299), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [5367] = 4,
    ACTIONS(622), 1,
      anon_sym_DOT,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(668), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(666), 17,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [5398] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(672), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(670), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5426] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(674), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(676), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5454] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(680), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(678), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5482] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(682), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(684), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5510] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(686), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(688), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5538] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(692), 8,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(690), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [5568] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(696), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(694), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5596] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(339), 8,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(337), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [5626] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(700), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(698), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5654] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(704), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(702), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5682] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(708), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(706), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5710] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(712), 8,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(710), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [5740] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(716), 8,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(714), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [5770] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(720), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(718), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5798] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(724), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(722), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5826] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(726), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(728), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5854] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(730), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(732), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5882] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(736), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(734), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5910] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(738), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(740), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5938] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(674), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(676), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5966] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(744), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(742), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5994] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(748), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(746), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6022] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(752), 8,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(750), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [6052] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(744), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(742), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6080] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(680), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(678), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6108] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(754), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(756), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6136] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(720), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(718), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6164] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(686), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(688), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6192] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(760), 8,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(758), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [6222] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(762), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(764), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6250] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(768), 8,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(766), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [6280] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(772), 8,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(770), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [6310] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(776), 8,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(774), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [6340] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(754), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(756), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6368] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(730), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(732), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6396] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(682), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(684), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6424] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(738), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(740), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6452] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(780), 8,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(778), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [6482] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(782), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(784), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6510] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(788), 8,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(786), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [6540] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(790), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(792), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6568] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(796), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(794), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6596] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(796), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(794), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6624] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(672), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(670), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6652] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(782), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(784), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6680] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(798), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(800), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6708] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(790), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(792), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6736] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(782), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(784), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6764] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(798), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(800), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6792] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(804), 8,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(802), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [6822] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(748), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(746), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6850] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(762), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(764), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6878] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(736), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(734), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6906] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(724), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(722), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6934] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(708), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(706), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6962] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(704), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(702), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6990] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(700), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(698), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [7018] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(696), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(694), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [7046] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(283), 1,
      anon_sym_STAR,
    ACTIONS(285), 3,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(806), 5,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      sym_plain_value,
    ACTIONS(376), 9,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7079] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(283), 1,
      anon_sym_STAR,
    ACTIONS(285), 3,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(810), 5,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      sym_plain_value,
    ACTIONS(808), 9,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7112] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(812), 1,
      anon_sym_SEMI,
    ACTIONS(814), 1,
      anon_sym_RBRACE,
    ACTIONS(323), 8,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
    ACTIONS(327), 8,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
  [7145] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(329), 1,
      anon_sym_SEMI,
    ACTIONS(331), 1,
      anon_sym_RBRACE,
    ACTIONS(323), 8,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
    ACTIONS(327), 8,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
  [7178] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(283), 1,
      anon_sym_STAR,
    ACTIONS(285), 3,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(818), 5,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      sym_plain_value,
    ACTIONS(816), 9,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7211] = 5,
    ACTIONS(418), 1,
      anon_sym_RBRACK,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(303), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(416), 6,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
    ACTIONS(299), 8,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
  [7241] = 5,
    ACTIONS(418), 1,
      anon_sym_RBRACK,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(325), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(416), 6,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
    ACTIONS(321), 8,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
  [7271] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(430), 1,
      anon_sym_SEMI,
    ACTIONS(323), 8,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
    ACTIONS(327), 8,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
  [7301] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(812), 1,
      anon_sym_SEMI,
    ACTIONS(323), 8,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
    ACTIONS(327), 8,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
  [7331] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(329), 1,
      anon_sym_SEMI,
    ACTIONS(323), 8,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
    ACTIONS(327), 8,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
  [7361] = 5,
    ACTIONS(822), 1,
      anon_sym_RBRACK,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(303), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(820), 6,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
    ACTIONS(299), 8,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
  [7391] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(824), 1,
      anon_sym_SEMI,
    ACTIONS(323), 8,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
    ACTIONS(327), 8,
      anon_sym_PLUS,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
  [7421] = 5,
    ACTIONS(822), 1,
      anon_sym_RBRACK,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(325), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(820), 6,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
    ACTIONS(321), 8,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
  [7451] = 10,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(826), 1,
      anon_sym_SEMI,
    ACTIONS(830), 1,
      anon_sym_LPAREN2,
    ACTIONS(834), 1,
      sym_identifier,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    ACTIONS(828), 2,
      anon_sym_STAR,
      anon_sym_PLUS,
    ACTIONS(832), 2,
      anon_sym_DASH,
      anon_sym_SLASH,
    STATE(260), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [7490] = 10,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(830), 1,
      anon_sym_LPAREN2,
    ACTIONS(834), 1,
      sym_identifier,
    ACTIONS(836), 1,
      anon_sym_SEMI,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    ACTIONS(828), 2,
      anon_sym_STAR,
      anon_sym_PLUS,
    ACTIONS(832), 2,
      anon_sym_DASH,
      anon_sym_SLASH,
    STATE(267), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [7529] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(327), 1,
      anon_sym_SLASH,
    ACTIONS(323), 4,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_DASH,
    ACTIONS(321), 10,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_TILDE,
      anon_sym_PLUS,
      anon_sym_PIPE,
  [7557] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(339), 1,
      anon_sym_SLASH,
    ACTIONS(337), 14,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_TILDE,
      anon_sym_PLUS,
      anon_sym_PIPE,
      anon_sym_DASH,
  [7583] = 9,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(830), 1,
      anon_sym_LPAREN2,
    ACTIONS(834), 1,
      sym_identifier,
    ACTIONS(838), 1,
      anon_sym_SEMI,
    ACTIONS(840), 1,
      anon_sym_LBRACE,
    STATE(155), 1,
      sym_block,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(241), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [7618] = 3,
    ACTIONS(842), 1,
      anon_sym_COLON,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(299), 12,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_TILDE,
      anon_sym_PLUS,
      anon_sym_PIPE,
  [7640] = 3,
    ACTIONS(844), 1,
      anon_sym_COLON,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(299), 12,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_TILDE,
      anon_sym_PLUS,
      anon_sym_PIPE,
  [7662] = 14,
    ACTIONS(317), 1,
      anon_sym_COMMA,
    ACTIONS(319), 1,
      anon_sym_RPAREN,
    ACTIONS(622), 1,
      anon_sym_DOT,
    ACTIONS(846), 1,
      anon_sym_COLON_COLON,
    ACTIONS(848), 1,
      anon_sym_POUND,
    ACTIONS(850), 1,
      anon_sym_LBRACK,
    ACTIONS(852), 1,
      anon_sym_GT,
    ACTIONS(854), 1,
      anon_sym_TILDE,
    ACTIONS(856), 1,
      anon_sym_PLUS,
    ACTIONS(858), 1,
      anon_sym_PIPE,
    ACTIONS(860), 1,
      sym__descendant_operator,
    ACTIONS(862), 1,
      sym__pseudo_class_selector_colon,
    STATE(285), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [7706] = 3,
    ACTIONS(864), 1,
      anon_sym_COLON,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(299), 12,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_TILDE,
      anon_sym_PLUS,
      anon_sym_PIPE,
  [7728] = 14,
    ACTIONS(317), 1,
      anon_sym_COMMA,
    ACTIONS(335), 1,
      anon_sym_RPAREN,
    ACTIONS(622), 1,
      anon_sym_DOT,
    ACTIONS(846), 1,
      anon_sym_COLON_COLON,
    ACTIONS(848), 1,
      anon_sym_POUND,
    ACTIONS(850), 1,
      anon_sym_LBRACK,
    ACTIONS(852), 1,
      anon_sym_GT,
    ACTIONS(854), 1,
      anon_sym_TILDE,
    ACTIONS(856), 1,
      anon_sym_PLUS,
    ACTIONS(858), 1,
      anon_sym_PIPE,
    ACTIONS(860), 1,
      sym__descendant_operator,
    ACTIONS(862), 1,
      sym__pseudo_class_selector_colon,
    STATE(290), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [7772] = 14,
    ACTIONS(622), 1,
      anon_sym_DOT,
    ACTIONS(846), 1,
      anon_sym_COLON_COLON,
    ACTIONS(848), 1,
      anon_sym_POUND,
    ACTIONS(850), 1,
      anon_sym_LBRACK,
    ACTIONS(852), 1,
      anon_sym_GT,
    ACTIONS(854), 1,
      anon_sym_TILDE,
    ACTIONS(856), 1,
      anon_sym_PLUS,
    ACTIONS(858), 1,
      anon_sym_PIPE,
    ACTIONS(860), 1,
      sym__descendant_operator,
    ACTIONS(862), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(866), 1,
      anon_sym_COMMA,
    ACTIONS(868), 1,
      anon_sym_LBRACE,
    STATE(283), 1,
      aux_sym_selectors_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [7816] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(870), 1,
      anon_sym_LPAREN,
    STATE(207), 1,
      sym_arguments,
    ACTIONS(301), 3,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
    ACTIONS(307), 7,
      anon_sym_LPAREN2,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [7843] = 12,
    ACTIONS(622), 1,
      anon_sym_DOT,
    ACTIONS(846), 1,
      anon_sym_COLON_COLON,
    ACTIONS(848), 1,
      anon_sym_POUND,
    ACTIONS(850), 1,
      anon_sym_LBRACK,
    ACTIONS(852), 1,
      anon_sym_GT,
    ACTIONS(854), 1,
      anon_sym_TILDE,
    ACTIONS(856), 1,
      anon_sym_PLUS,
    ACTIONS(858), 1,
      anon_sym_PIPE,
    ACTIONS(860), 1,
      sym__descendant_operator,
    ACTIONS(862), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(872), 2,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [7882] = 12,
    ACTIONS(622), 1,
      anon_sym_DOT,
    ACTIONS(846), 1,
      anon_sym_COLON_COLON,
    ACTIONS(848), 1,
      anon_sym_POUND,
    ACTIONS(850), 1,
      anon_sym_LBRACK,
    ACTIONS(852), 1,
      anon_sym_GT,
    ACTIONS(854), 1,
      anon_sym_TILDE,
    ACTIONS(856), 1,
      anon_sym_PLUS,
    ACTIONS(858), 1,
      anon_sym_PIPE,
    ACTIONS(860), 1,
      sym__descendant_operator,
    ACTIONS(862), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(424), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [7921] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(802), 5,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(804), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [7943] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(874), 1,
      sym_unit,
    ACTIONS(610), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(612), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [7967] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(876), 1,
      sym_unit,
    ACTIONS(600), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(602), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [7991] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(830), 1,
      anon_sym_LPAREN2,
    ACTIONS(878), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(287), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [8017] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(830), 1,
      anon_sym_LPAREN2,
    ACTIONS(834), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(252), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [8043] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(830), 1,
      anon_sym_LPAREN2,
    ACTIONS(834), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(251), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [8069] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(830), 1,
      anon_sym_LPAREN2,
    ACTIONS(834), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(268), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [8095] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(830), 1,
      anon_sym_LPAREN2,
    ACTIONS(834), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(250), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [8121] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(830), 1,
      anon_sym_LPAREN2,
    ACTIONS(834), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(263), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [8147] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(830), 1,
      anon_sym_LPAREN2,
    ACTIONS(834), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(277), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [8173] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(830), 1,
      anon_sym_LPAREN2,
    ACTIONS(834), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(246), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [8199] = 12,
    ACTIONS(622), 1,
      anon_sym_DOT,
    ACTIONS(846), 1,
      anon_sym_COLON_COLON,
    ACTIONS(848), 1,
      anon_sym_POUND,
    ACTIONS(850), 1,
      anon_sym_LBRACK,
    ACTIONS(852), 1,
      anon_sym_GT,
    ACTIONS(854), 1,
      anon_sym_TILDE,
    ACTIONS(856), 1,
      anon_sym_PLUS,
    ACTIONS(858), 1,
      anon_sym_PIPE,
    ACTIONS(860), 1,
      sym__descendant_operator,
    ACTIONS(862), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(880), 1,
      anon_sym_RPAREN,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [8237] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(770), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(772), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8258] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(758), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(760), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8279] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(778), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(780), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8300] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(786), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(788), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8321] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(710), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(712), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8342] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(766), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(768), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8363] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(774), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(776), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8384] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(714), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(716), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8405] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(307), 1,
      anon_sym_SLASH,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    STATE(223), 1,
      sym_arguments,
    ACTIONS(301), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8430] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(750), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(752), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8451] = 8,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(307), 1,
      anon_sym_SLASH,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    ACTIONS(882), 1,
      anon_sym_COLON,
    STATE(223), 1,
      sym_arguments,
    ACTIONS(301), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(462), 3,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [8480] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(337), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(339), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8501] = 11,
    ACTIONS(622), 1,
      anon_sym_DOT,
    ACTIONS(846), 1,
      anon_sym_COLON_COLON,
    ACTIONS(848), 1,
      anon_sym_POUND,
    ACTIONS(850), 1,
      anon_sym_LBRACK,
    ACTIONS(852), 1,
      anon_sym_GT,
    ACTIONS(854), 1,
      anon_sym_TILDE,
    ACTIONS(856), 1,
      anon_sym_PLUS,
    ACTIONS(858), 1,
      anon_sym_PIPE,
    ACTIONS(860), 1,
      sym__descendant_operator,
    ACTIONS(862), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [8536] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(690), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(692), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8557] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(612), 1,
      anon_sym_SLASH,
    ACTIONS(884), 1,
      sym_unit,
    ACTIONS(610), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8579] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(602), 1,
      anon_sym_SLASH,
    ACTIONS(886), 1,
      sym_unit,
    ACTIONS(600), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8601] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(776), 1,
      anon_sym_SLASH,
    ACTIONS(774), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8620] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(772), 1,
      anon_sym_SLASH,
    ACTIONS(770), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8639] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(780), 1,
      anon_sym_SLASH,
    ACTIONS(778), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8658] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(716), 1,
      anon_sym_SLASH,
    ACTIONS(714), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8677] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(712), 1,
      anon_sym_SLASH,
    ACTIONS(710), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8696] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(692), 1,
      anon_sym_SLASH,
    ACTIONS(690), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8715] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(788), 1,
      anon_sym_SLASH,
    ACTIONS(786), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8734] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(752), 1,
      anon_sym_SLASH,
    ACTIONS(750), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8753] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(804), 1,
      anon_sym_SLASH,
    ACTIONS(802), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8772] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(760), 1,
      anon_sym_SLASH,
    ACTIONS(758), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8791] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(768), 1,
      anon_sym_SLASH,
    ACTIONS(766), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8810] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(339), 1,
      anon_sym_SLASH,
    ACTIONS(337), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8829] = 7,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(888), 1,
      anon_sym_COMMA,
    ACTIONS(892), 1,
      anon_sym_RBRACK,
    ACTIONS(894), 1,
      anon_sym_SLASH,
    STATE(282), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(890), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [8853] = 7,
    ACTIONS(500), 1,
      anon_sym_SQUOTE,
    ACTIONS(502), 1,
      anon_sym_DQUOTE,
    ACTIONS(870), 1,
      anon_sym_LPAREN,
    ACTIONS(896), 1,
      sym_identifier,
    STATE(207), 1,
      sym_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(321), 2,
      sym_string_value,
      sym_call_expression,
  [8877] = 7,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(888), 1,
      anon_sym_COMMA,
    ACTIONS(894), 1,
      anon_sym_SLASH,
    ACTIONS(898), 1,
      anon_sym_RBRACK,
    STATE(289), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(890), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [8901] = 6,
    ACTIONS(900), 1,
      anon_sym_RBRACE,
    ACTIONS(904), 1,
      aux_sym_integer_value_token1,
    STATE(296), 1,
      sym_integer_value,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(902), 2,
      sym_from,
      sym_to,
    STATE(240), 2,
      sym_keyframe_block,
      aux_sym_keyframe_block_list_repeat1,
  [8923] = 7,
    ACTIONS(500), 1,
      anon_sym_SQUOTE,
    ACTIONS(502), 1,
      anon_sym_DQUOTE,
    ACTIONS(870), 1,
      anon_sym_LPAREN,
    ACTIONS(896), 1,
      sym_identifier,
    STATE(207), 1,
      sym_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(335), 2,
      sym_string_value,
      sym_call_expression,
  [8947] = 7,
    ACTIONS(239), 1,
      anon_sym_LBRACE,
    ACTIONS(906), 1,
      anon_sym_COMMA,
    ACTIONS(908), 1,
      anon_sym_SEMI,
    STATE(165), 1,
      sym_block,
    STATE(255), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(910), 2,
      anon_sym_and,
      anon_sym_or,
  [8971] = 6,
    ACTIONS(912), 1,
      anon_sym_RBRACE,
    ACTIONS(917), 1,
      aux_sym_integer_value_token1,
    STATE(296), 1,
      sym_integer_value,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(914), 2,
      sym_from,
      sym_to,
    STATE(239), 2,
      sym_keyframe_block,
      aux_sym_keyframe_block_list_repeat1,
  [8993] = 6,
    ACTIONS(904), 1,
      aux_sym_integer_value_token1,
    ACTIONS(920), 1,
      anon_sym_RBRACE,
    STATE(296), 1,
      sym_integer_value,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(902), 2,
      sym_from,
      sym_to,
    STATE(239), 2,
      sym_keyframe_block,
      aux_sym_keyframe_block_list_repeat1,
  [9015] = 7,
    ACTIONS(840), 1,
      anon_sym_LBRACE,
    ACTIONS(906), 1,
      anon_sym_COMMA,
    ACTIONS(922), 1,
      anon_sym_SEMI,
    STATE(114), 1,
      sym_block,
    STATE(266), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(910), 2,
      anon_sym_and,
      anon_sym_or,
  [9039] = 7,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(888), 1,
      anon_sym_COMMA,
    ACTIONS(894), 1,
      anon_sym_SLASH,
    ACTIONS(924), 1,
      anon_sym_RBRACK,
    STATE(291), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(890), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9063] = 6,
    ACTIONS(904), 1,
      aux_sym_integer_value_token1,
    ACTIONS(926), 1,
      anon_sym_RBRACE,
    STATE(296), 1,
      sym_integer_value,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(902), 2,
      sym_from,
      sym_to,
    STATE(244), 2,
      sym_keyframe_block,
      aux_sym_keyframe_block_list_repeat1,
  [9085] = 6,
    ACTIONS(904), 1,
      aux_sym_integer_value_token1,
    ACTIONS(928), 1,
      anon_sym_RBRACE,
    STATE(296), 1,
      sym_integer_value,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(902), 2,
      sym_from,
      sym_to,
    STATE(239), 2,
      sym_keyframe_block,
      aux_sym_keyframe_block_list_repeat1,
  [9107] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(894), 1,
      anon_sym_SLASH,
    ACTIONS(930), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
    ACTIONS(890), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9126] = 6,
    ACTIONS(840), 1,
      anon_sym_LBRACE,
    ACTIONS(906), 1,
      anon_sym_COMMA,
    STATE(129), 1,
      sym_block,
    STATE(269), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(910), 2,
      anon_sym_and,
      anon_sym_or,
  [9147] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(932), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9160] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(462), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9173] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(934), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9186] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(936), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9199] = 6,
    ACTIONS(239), 1,
      anon_sym_LBRACE,
    ACTIONS(906), 1,
      anon_sym_COMMA,
    STATE(158), 1,
      sym_block,
    STATE(270), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(910), 2,
      anon_sym_and,
      anon_sym_or,
  [9220] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(938), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9233] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(940), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9246] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(894), 1,
      anon_sym_SLASH,
    ACTIONS(942), 1,
      anon_sym_SEMI,
    ACTIONS(890), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9264] = 6,
    ACTIONS(239), 1,
      anon_sym_LBRACE,
    ACTIONS(906), 1,
      anon_sym_COMMA,
    ACTIONS(944), 1,
      anon_sym_SEMI,
    STATE(137), 1,
      sym_block,
    STATE(279), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9284] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(894), 1,
      anon_sym_SLASH,
    ACTIONS(946), 1,
      anon_sym_RPAREN,
    ACTIONS(890), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9302] = 5,
    ACTIONS(500), 1,
      anon_sym_SQUOTE,
    ACTIONS(502), 1,
      anon_sym_DQUOTE,
    ACTIONS(948), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(318), 2,
      sym_string_value,
      sym_call_expression,
  [9320] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(894), 1,
      anon_sym_SLASH,
    ACTIONS(950), 1,
      anon_sym_RBRACK,
    ACTIONS(890), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9338] = 5,
    ACTIONS(500), 1,
      anon_sym_SQUOTE,
    ACTIONS(502), 1,
      anon_sym_DQUOTE,
    ACTIONS(952), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(316), 2,
      sym_string_value,
      sym_call_expression,
  [9356] = 5,
    ACTIONS(906), 1,
      anon_sym_COMMA,
    ACTIONS(954), 1,
      anon_sym_SEMI,
    STATE(288), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(910), 2,
      anon_sym_and,
      anon_sym_or,
  [9374] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(894), 1,
      anon_sym_SLASH,
    ACTIONS(956), 1,
      anon_sym_RPAREN,
    ACTIONS(890), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9392] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(894), 1,
      anon_sym_SLASH,
    ACTIONS(958), 1,
      anon_sym_RPAREN,
    ACTIONS(890), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9410] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(910), 2,
      anon_sym_and,
      anon_sym_or,
    ACTIONS(960), 3,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [9424] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(894), 1,
      anon_sym_SLASH,
    ACTIONS(962), 1,
      anon_sym_RBRACK,
    ACTIONS(890), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9442] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(894), 1,
      anon_sym_SLASH,
    ACTIONS(964), 1,
      anon_sym_SEMI,
    ACTIONS(890), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9460] = 6,
    ACTIONS(840), 1,
      anon_sym_LBRACE,
    ACTIONS(906), 1,
      anon_sym_COMMA,
    ACTIONS(966), 1,
      anon_sym_SEMI,
    STATE(159), 1,
      sym_block,
    STATE(279), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9480] = 5,
    ACTIONS(906), 1,
      anon_sym_COMMA,
    ACTIONS(968), 1,
      anon_sym_SEMI,
    STATE(292), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(910), 2,
      anon_sym_and,
      anon_sym_or,
  [9498] = 4,
    ACTIONS(239), 1,
      anon_sym_LBRACE,
    STATE(163), 1,
      sym_block,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(910), 2,
      anon_sym_and,
      anon_sym_or,
  [9513] = 5,
    ACTIONS(840), 1,
      anon_sym_LBRACE,
    ACTIONS(906), 1,
      anon_sym_COMMA,
    STATE(141), 1,
      sym_block,
    STATE(279), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9530] = 5,
    ACTIONS(239), 1,
      anon_sym_LBRACE,
    ACTIONS(906), 1,
      anon_sym_COMMA,
    STATE(133), 1,
      sym_block,
    STATE(279), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9547] = 3,
    ACTIONS(882), 1,
      anon_sym_COLON,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(462), 3,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9560] = 4,
    ACTIONS(408), 1,
      anon_sym_RPAREN,
    STATE(272), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(970), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [9575] = 4,
    ACTIONS(973), 1,
      anon_sym_RPAREN,
    STATE(272), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(309), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [9590] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(800), 4,
      anon_sym_RBRACE,
      sym_from,
      sym_to,
      aux_sym_integer_value_token1,
  [9601] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(975), 4,
      anon_sym_RBRACE,
      sym_from,
      sym_to,
      aux_sym_integer_value_token1,
  [9612] = 4,
    ACTIONS(977), 1,
      anon_sym_RPAREN,
    STATE(272), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(309), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [9627] = 4,
    ACTIONS(840), 1,
      anon_sym_LBRACE,
    STATE(117), 1,
      sym_block,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(910), 2,
      anon_sym_and,
      anon_sym_or,
  [9642] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(698), 4,
      anon_sym_RBRACE,
      sym_from,
      sym_to,
      aux_sym_integer_value_token1,
  [9653] = 4,
    ACTIONS(979), 1,
      anon_sym_COMMA,
    STATE(279), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(960), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [9668] = 4,
    ACTIONS(982), 1,
      anon_sym_RPAREN,
    STATE(272), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(309), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [9683] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(742), 4,
      anon_sym_RBRACE,
      sym_from,
      sym_to,
      aux_sym_integer_value_token1,
  [9694] = 4,
    ACTIONS(888), 1,
      anon_sym_COMMA,
    ACTIONS(984), 1,
      anon_sym_RBRACK,
    STATE(284), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9708] = 4,
    ACTIONS(866), 1,
      anon_sym_COMMA,
    ACTIONS(986), 1,
      anon_sym_LBRACE,
    STATE(286), 1,
      aux_sym_selectors_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9722] = 4,
    ACTIONS(930), 1,
      anon_sym_RBRACK,
    ACTIONS(988), 1,
      anon_sym_COMMA,
    STATE(284), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9736] = 4,
    ACTIONS(317), 1,
      anon_sym_COMMA,
    ACTIONS(991), 1,
      anon_sym_RPAREN,
    STATE(293), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9750] = 4,
    ACTIONS(872), 1,
      anon_sym_LBRACE,
    ACTIONS(993), 1,
      anon_sym_COMMA,
    STATE(286), 1,
      aux_sym_selectors_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9764] = 3,
    ACTIONS(996), 1,
      anon_sym_RPAREN,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(910), 2,
      anon_sym_and,
      anon_sym_or,
  [9776] = 4,
    ACTIONS(906), 1,
      anon_sym_COMMA,
    ACTIONS(998), 1,
      anon_sym_SEMI,
    STATE(279), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9790] = 4,
    ACTIONS(888), 1,
      anon_sym_COMMA,
    ACTIONS(1000), 1,
      anon_sym_RBRACK,
    STATE(284), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9804] = 4,
    ACTIONS(317), 1,
      anon_sym_COMMA,
    ACTIONS(1002), 1,
      anon_sym_RPAREN,
    STATE(293), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9818] = 4,
    ACTIONS(888), 1,
      anon_sym_COMMA,
    ACTIONS(1004), 1,
      anon_sym_RBRACK,
    STATE(284), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9832] = 4,
    ACTIONS(906), 1,
      anon_sym_COMMA,
    ACTIONS(1006), 1,
      anon_sym_SEMI,
    STATE(279), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9846] = 4,
    ACTIONS(424), 1,
      anon_sym_RPAREN,
    ACTIONS(1008), 1,
      anon_sym_COMMA,
    STATE(293), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9860] = 3,
    ACTIONS(610), 1,
      anon_sym_LBRACE,
    ACTIONS(1011), 1,
      sym_unit,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9871] = 3,
    ACTIONS(1013), 1,
      anon_sym_LBRACE,
    STATE(162), 1,
      sym_keyframe_block_list,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9882] = 3,
    ACTIONS(1015), 1,
      anon_sym_LBRACE,
    STATE(275), 1,
      sym_block,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9893] = 3,
    ACTIONS(840), 1,
      anon_sym_LBRACE,
    STATE(154), 1,
      sym_block,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9904] = 3,
    ACTIONS(1017), 1,
      aux_sym_color_value_token1,
    ACTIONS(1019), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9915] = 3,
    ACTIONS(239), 1,
      anon_sym_LBRACE,
    STATE(148), 1,
      sym_block,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9926] = 3,
    ACTIONS(1019), 1,
      sym_identifier,
    ACTIONS(1021), 1,
      aux_sym_color_value_token1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9937] = 3,
    ACTIONS(870), 1,
      anon_sym_LPAREN,
    STATE(207), 1,
      sym_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9948] = 3,
    ACTIONS(1023), 1,
      anon_sym_LBRACE,
    STATE(118), 1,
      sym_keyframe_block_list,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9959] = 2,
    ACTIONS(1025), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9967] = 2,
    ACTIONS(1027), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9975] = 2,
    ACTIONS(1029), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9983] = 2,
    ACTIONS(1031), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9991] = 2,
    ACTIONS(1033), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9999] = 2,
    ACTIONS(1035), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10007] = 2,
    ACTIONS(1037), 1,
      anon_sym_RBRACE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10015] = 2,
    ACTIONS(1039), 1,
      anon_sym_RBRACE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10023] = 2,
    ACTIONS(1041), 1,
      anon_sym_DQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10031] = 2,
    ACTIONS(1043), 1,
      aux_sym_color_value_token1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10039] = 2,
    ACTIONS(1045), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10047] = 2,
    ACTIONS(1045), 1,
      anon_sym_DQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10055] = 2,
    ACTIONS(1041), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10063] = 2,
    ACTIONS(1047), 1,
      anon_sym_SEMI,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10071] = 2,
    ACTIONS(53), 1,
      anon_sym_RBRACE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10079] = 2,
    ACTIONS(1049), 1,
      anon_sym_SEMI,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10087] = 2,
    ACTIONS(1051), 1,
      aux_sym_color_value_token1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10095] = 2,
    ACTIONS(1053), 1,
      anon_sym_RBRACE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10103] = 2,
    ACTIONS(1055), 1,
      anon_sym_SEMI,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10111] = 2,
    ACTIONS(1057), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10119] = 2,
    ACTIONS(1057), 1,
      anon_sym_DQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10127] = 2,
    ACTIONS(1025), 1,
      anon_sym_DQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10135] = 2,
    ACTIONS(1059), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10143] = 2,
    ACTIONS(1059), 1,
      anon_sym_DQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10151] = 2,
    ACTIONS(65), 1,
      anon_sym_RBRACE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10159] = 2,
    ACTIONS(63), 1,
      anon_sym_RBRACE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10167] = 2,
    ACTIONS(1061), 1,
      anon_sym_LPAREN2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10175] = 2,
    ACTIONS(1063), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10183] = 2,
    ACTIONS(1065), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10191] = 2,
    ACTIONS(1067), 1,
      aux_sym_color_value_token1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10199] = 2,
    ACTIONS(1069), 1,
      aux_sym_string_value_token1,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10207] = 2,
    ACTIONS(1071), 1,
      aux_sym_string_value_token2,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10215] = 2,
    ACTIONS(1073), 1,
      anon_sym_SEMI,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10223] = 2,
    ACTIONS(1075), 1,
      ts_builtin_sym_end,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10231] = 2,
    ACTIONS(1077), 1,
      aux_sym_string_value_token2,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10239] = 2,
    ACTIONS(1079), 1,
      aux_sym_string_value_token1,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10247] = 2,
    ACTIONS(1081), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10255] = 2,
    ACTIONS(1083), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10263] = 2,
    ACTIONS(1085), 1,
      aux_sym_string_value_token1,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10271] = 2,
    ACTIONS(1087), 1,
      aux_sym_string_value_token2,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10279] = 2,
    ACTIONS(1089), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10287] = 2,
    ACTIONS(1091), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10295] = 2,
    ACTIONS(1093), 1,
      aux_sym_string_value_token1,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10303] = 2,
    ACTIONS(1095), 1,
      aux_sym_string_value_token2,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10311] = 2,
    ACTIONS(1097), 1,
      aux_sym_string_value_token1,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10319] = 2,
    ACTIONS(1099), 1,
      aux_sym_string_value_token2,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10327] = 2,
    ACTIONS(1101), 1,
      aux_sym_string_value_token1,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10335] = 2,
    ACTIONS(1103), 1,
      aux_sym_string_value_token2,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10343] = 2,
    ACTIONS(1027), 1,
      anon_sym_DQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 94,
  [SMALL_STATE(4)] = 188,
  [SMALL_STATE(5)] = 282,
  [SMALL_STATE(6)] = 376,
  [SMALL_STATE(7)] = 470,
  [SMALL_STATE(8)] = 564,
  [SMALL_STATE(9)] = 655,
  [SMALL_STATE(10)] = 745,
  [SMALL_STATE(11)] = 835,
  [SMALL_STATE(12)] = 921,
  [SMALL_STATE(13)] = 1007,
  [SMALL_STATE(14)] = 1090,
  [SMALL_STATE(15)] = 1172,
  [SMALL_STATE(16)] = 1254,
  [SMALL_STATE(17)] = 1330,
  [SMALL_STATE(18)] = 1394,
  [SMALL_STATE(19)] = 1458,
  [SMALL_STATE(20)] = 1527,
  [SMALL_STATE(21)] = 1593,
  [SMALL_STATE(22)] = 1659,
  [SMALL_STATE(23)] = 1704,
  [SMALL_STATE(24)] = 1766,
  [SMALL_STATE(25)] = 1828,
  [SMALL_STATE(26)] = 1890,
  [SMALL_STATE(27)] = 1951,
  [SMALL_STATE(28)] = 1990,
  [SMALL_STATE(29)] = 2051,
  [SMALL_STATE(30)] = 2112,
  [SMALL_STATE(31)] = 2147,
  [SMALL_STATE(32)] = 2204,
  [SMALL_STATE(33)] = 2263,
  [SMALL_STATE(34)] = 2320,
  [SMALL_STATE(35)] = 2370,
  [SMALL_STATE(36)] = 2420,
  [SMALL_STATE(37)] = 2466,
  [SMALL_STATE(38)] = 2516,
  [SMALL_STATE(39)] = 2572,
  [SMALL_STATE(40)] = 2622,
  [SMALL_STATE(41)] = 2674,
  [SMALL_STATE(42)] = 2732,
  [SMALL_STATE(43)] = 2782,
  [SMALL_STATE(44)] = 2832,
  [SMALL_STATE(45)] = 2882,
  [SMALL_STATE(46)] = 2934,
  [SMALL_STATE(47)] = 2992,
  [SMALL_STATE(48)] = 3047,
  [SMALL_STATE(49)] = 3082,
  [SMALL_STATE(50)] = 3117,
  [SMALL_STATE(51)] = 3172,
  [SMALL_STATE(52)] = 3227,
  [SMALL_STATE(53)] = 3268,
  [SMALL_STATE(54)] = 3303,
  [SMALL_STATE(55)] = 3358,
  [SMALL_STATE(56)] = 3393,
  [SMALL_STATE(57)] = 3448,
  [SMALL_STATE(58)] = 3484,
  [SMALL_STATE(59)] = 3536,
  [SMALL_STATE(60)] = 3588,
  [SMALL_STATE(61)] = 3617,
  [SMALL_STATE(62)] = 3646,
  [SMALL_STATE(63)] = 3695,
  [SMALL_STATE(64)] = 3744,
  [SMALL_STATE(65)] = 3773,
  [SMALL_STATE(66)] = 3822,
  [SMALL_STATE(67)] = 3851,
  [SMALL_STATE(68)] = 3880,
  [SMALL_STATE(69)] = 3909,
  [SMALL_STATE(70)] = 3938,
  [SMALL_STATE(71)] = 3987,
  [SMALL_STATE(72)] = 4036,
  [SMALL_STATE(73)] = 4085,
  [SMALL_STATE(74)] = 4134,
  [SMALL_STATE(75)] = 4183,
  [SMALL_STATE(76)] = 4232,
  [SMALL_STATE(77)] = 4281,
  [SMALL_STATE(78)] = 4310,
  [SMALL_STATE(79)] = 4359,
  [SMALL_STATE(80)] = 4388,
  [SMALL_STATE(81)] = 4417,
  [SMALL_STATE(82)] = 4466,
  [SMALL_STATE(83)] = 4495,
  [SMALL_STATE(84)] = 4544,
  [SMALL_STATE(85)] = 4593,
  [SMALL_STATE(86)] = 4622,
  [SMALL_STATE(87)] = 4671,
  [SMALL_STATE(88)] = 4700,
  [SMALL_STATE(89)] = 4733,
  [SMALL_STATE(90)] = 4782,
  [SMALL_STATE(91)] = 4815,
  [SMALL_STATE(92)] = 4864,
  [SMALL_STATE(93)] = 4893,
  [SMALL_STATE(94)] = 4924,
  [SMALL_STATE(95)] = 4973,
  [SMALL_STATE(96)] = 5004,
  [SMALL_STATE(97)] = 5035,
  [SMALL_STATE(98)] = 5064,
  [SMALL_STATE(99)] = 5113,
  [SMALL_STATE(100)] = 5142,
  [SMALL_STATE(101)] = 5171,
  [SMALL_STATE(102)] = 5202,
  [SMALL_STATE(103)] = 5251,
  [SMALL_STATE(104)] = 5280,
  [SMALL_STATE(105)] = 5309,
  [SMALL_STATE(106)] = 5338,
  [SMALL_STATE(107)] = 5367,
  [SMALL_STATE(108)] = 5398,
  [SMALL_STATE(109)] = 5426,
  [SMALL_STATE(110)] = 5454,
  [SMALL_STATE(111)] = 5482,
  [SMALL_STATE(112)] = 5510,
  [SMALL_STATE(113)] = 5538,
  [SMALL_STATE(114)] = 5568,
  [SMALL_STATE(115)] = 5596,
  [SMALL_STATE(116)] = 5626,
  [SMALL_STATE(117)] = 5654,
  [SMALL_STATE(118)] = 5682,
  [SMALL_STATE(119)] = 5710,
  [SMALL_STATE(120)] = 5740,
  [SMALL_STATE(121)] = 5770,
  [SMALL_STATE(122)] = 5798,
  [SMALL_STATE(123)] = 5826,
  [SMALL_STATE(124)] = 5854,
  [SMALL_STATE(125)] = 5882,
  [SMALL_STATE(126)] = 5910,
  [SMALL_STATE(127)] = 5938,
  [SMALL_STATE(128)] = 5966,
  [SMALL_STATE(129)] = 5994,
  [SMALL_STATE(130)] = 6022,
  [SMALL_STATE(131)] = 6052,
  [SMALL_STATE(132)] = 6080,
  [SMALL_STATE(133)] = 6108,
  [SMALL_STATE(134)] = 6136,
  [SMALL_STATE(135)] = 6164,
  [SMALL_STATE(136)] = 6192,
  [SMALL_STATE(137)] = 6222,
  [SMALL_STATE(138)] = 6250,
  [SMALL_STATE(139)] = 6280,
  [SMALL_STATE(140)] = 6310,
  [SMALL_STATE(141)] = 6340,
  [SMALL_STATE(142)] = 6368,
  [SMALL_STATE(143)] = 6396,
  [SMALL_STATE(144)] = 6424,
  [SMALL_STATE(145)] = 6452,
  [SMALL_STATE(146)] = 6482,
  [SMALL_STATE(147)] = 6510,
  [SMALL_STATE(148)] = 6540,
  [SMALL_STATE(149)] = 6568,
  [SMALL_STATE(150)] = 6596,
  [SMALL_STATE(151)] = 6624,
  [SMALL_STATE(152)] = 6652,
  [SMALL_STATE(153)] = 6680,
  [SMALL_STATE(154)] = 6708,
  [SMALL_STATE(155)] = 6736,
  [SMALL_STATE(156)] = 6764,
  [SMALL_STATE(157)] = 6792,
  [SMALL_STATE(158)] = 6822,
  [SMALL_STATE(159)] = 6850,
  [SMALL_STATE(160)] = 6878,
  [SMALL_STATE(161)] = 6906,
  [SMALL_STATE(162)] = 6934,
  [SMALL_STATE(163)] = 6962,
  [SMALL_STATE(164)] = 6990,
  [SMALL_STATE(165)] = 7018,
  [SMALL_STATE(166)] = 7046,
  [SMALL_STATE(167)] = 7079,
  [SMALL_STATE(168)] = 7112,
  [SMALL_STATE(169)] = 7145,
  [SMALL_STATE(170)] = 7178,
  [SMALL_STATE(171)] = 7211,
  [SMALL_STATE(172)] = 7241,
  [SMALL_STATE(173)] = 7271,
  [SMALL_STATE(174)] = 7301,
  [SMALL_STATE(175)] = 7331,
  [SMALL_STATE(176)] = 7361,
  [SMALL_STATE(177)] = 7391,
  [SMALL_STATE(178)] = 7421,
  [SMALL_STATE(179)] = 7451,
  [SMALL_STATE(180)] = 7490,
  [SMALL_STATE(181)] = 7529,
  [SMALL_STATE(182)] = 7557,
  [SMALL_STATE(183)] = 7583,
  [SMALL_STATE(184)] = 7618,
  [SMALL_STATE(185)] = 7640,
  [SMALL_STATE(186)] = 7662,
  [SMALL_STATE(187)] = 7706,
  [SMALL_STATE(188)] = 7728,
  [SMALL_STATE(189)] = 7772,
  [SMALL_STATE(190)] = 7816,
  [SMALL_STATE(191)] = 7843,
  [SMALL_STATE(192)] = 7882,
  [SMALL_STATE(193)] = 7921,
  [SMALL_STATE(194)] = 7943,
  [SMALL_STATE(195)] = 7967,
  [SMALL_STATE(196)] = 7991,
  [SMALL_STATE(197)] = 8017,
  [SMALL_STATE(198)] = 8043,
  [SMALL_STATE(199)] = 8069,
  [SMALL_STATE(200)] = 8095,
  [SMALL_STATE(201)] = 8121,
  [SMALL_STATE(202)] = 8147,
  [SMALL_STATE(203)] = 8173,
  [SMALL_STATE(204)] = 8199,
  [SMALL_STATE(205)] = 8237,
  [SMALL_STATE(206)] = 8258,
  [SMALL_STATE(207)] = 8279,
  [SMALL_STATE(208)] = 8300,
  [SMALL_STATE(209)] = 8321,
  [SMALL_STATE(210)] = 8342,
  [SMALL_STATE(211)] = 8363,
  [SMALL_STATE(212)] = 8384,
  [SMALL_STATE(213)] = 8405,
  [SMALL_STATE(214)] = 8430,
  [SMALL_STATE(215)] = 8451,
  [SMALL_STATE(216)] = 8480,
  [SMALL_STATE(217)] = 8501,
  [SMALL_STATE(218)] = 8536,
  [SMALL_STATE(219)] = 8557,
  [SMALL_STATE(220)] = 8579,
  [SMALL_STATE(221)] = 8601,
  [SMALL_STATE(222)] = 8620,
  [SMALL_STATE(223)] = 8639,
  [SMALL_STATE(224)] = 8658,
  [SMALL_STATE(225)] = 8677,
  [SMALL_STATE(226)] = 8696,
  [SMALL_STATE(227)] = 8715,
  [SMALL_STATE(228)] = 8734,
  [SMALL_STATE(229)] = 8753,
  [SMALL_STATE(230)] = 8772,
  [SMALL_STATE(231)] = 8791,
  [SMALL_STATE(232)] = 8810,
  [SMALL_STATE(233)] = 8829,
  [SMALL_STATE(234)] = 8853,
  [SMALL_STATE(235)] = 8877,
  [SMALL_STATE(236)] = 8901,
  [SMALL_STATE(237)] = 8923,
  [SMALL_STATE(238)] = 8947,
  [SMALL_STATE(239)] = 8971,
  [SMALL_STATE(240)] = 8993,
  [SMALL_STATE(241)] = 9015,
  [SMALL_STATE(242)] = 9039,
  [SMALL_STATE(243)] = 9063,
  [SMALL_STATE(244)] = 9085,
  [SMALL_STATE(245)] = 9107,
  [SMALL_STATE(246)] = 9126,
  [SMALL_STATE(247)] = 9147,
  [SMALL_STATE(248)] = 9160,
  [SMALL_STATE(249)] = 9173,
  [SMALL_STATE(250)] = 9186,
  [SMALL_STATE(251)] = 9199,
  [SMALL_STATE(252)] = 9220,
  [SMALL_STATE(253)] = 9233,
  [SMALL_STATE(254)] = 9246,
  [SMALL_STATE(255)] = 9264,
  [SMALL_STATE(256)] = 9284,
  [SMALL_STATE(257)] = 9302,
  [SMALL_STATE(258)] = 9320,
  [SMALL_STATE(259)] = 9338,
  [SMALL_STATE(260)] = 9356,
  [SMALL_STATE(261)] = 9374,
  [SMALL_STATE(262)] = 9392,
  [SMALL_STATE(263)] = 9410,
  [SMALL_STATE(264)] = 9424,
  [SMALL_STATE(265)] = 9442,
  [SMALL_STATE(266)] = 9460,
  [SMALL_STATE(267)] = 9480,
  [SMALL_STATE(268)] = 9498,
  [SMALL_STATE(269)] = 9513,
  [SMALL_STATE(270)] = 9530,
  [SMALL_STATE(271)] = 9547,
  [SMALL_STATE(272)] = 9560,
  [SMALL_STATE(273)] = 9575,
  [SMALL_STATE(274)] = 9590,
  [SMALL_STATE(275)] = 9601,
  [SMALL_STATE(276)] = 9612,
  [SMALL_STATE(277)] = 9627,
  [SMALL_STATE(278)] = 9642,
  [SMALL_STATE(279)] = 9653,
  [SMALL_STATE(280)] = 9668,
  [SMALL_STATE(281)] = 9683,
  [SMALL_STATE(282)] = 9694,
  [SMALL_STATE(283)] = 9708,
  [SMALL_STATE(284)] = 9722,
  [SMALL_STATE(285)] = 9736,
  [SMALL_STATE(286)] = 9750,
  [SMALL_STATE(287)] = 9764,
  [SMALL_STATE(288)] = 9776,
  [SMALL_STATE(289)] = 9790,
  [SMALL_STATE(290)] = 9804,
  [SMALL_STATE(291)] = 9818,
  [SMALL_STATE(292)] = 9832,
  [SMALL_STATE(293)] = 9846,
  [SMALL_STATE(294)] = 9860,
  [SMALL_STATE(295)] = 9871,
  [SMALL_STATE(296)] = 9882,
  [SMALL_STATE(297)] = 9893,
  [SMALL_STATE(298)] = 9904,
  [SMALL_STATE(299)] = 9915,
  [SMALL_STATE(300)] = 9926,
  [SMALL_STATE(301)] = 9937,
  [SMALL_STATE(302)] = 9948,
  [SMALL_STATE(303)] = 9959,
  [SMALL_STATE(304)] = 9967,
  [SMALL_STATE(305)] = 9975,
  [SMALL_STATE(306)] = 9983,
  [SMALL_STATE(307)] = 9991,
  [SMALL_STATE(308)] = 9999,
  [SMALL_STATE(309)] = 10007,
  [SMALL_STATE(310)] = 10015,
  [SMALL_STATE(311)] = 10023,
  [SMALL_STATE(312)] = 10031,
  [SMALL_STATE(313)] = 10039,
  [SMALL_STATE(314)] = 10047,
  [SMALL_STATE(315)] = 10055,
  [SMALL_STATE(316)] = 10063,
  [SMALL_STATE(317)] = 10071,
  [SMALL_STATE(318)] = 10079,
  [SMALL_STATE(319)] = 10087,
  [SMALL_STATE(320)] = 10095,
  [SMALL_STATE(321)] = 10103,
  [SMALL_STATE(322)] = 10111,
  [SMALL_STATE(323)] = 10119,
  [SMALL_STATE(324)] = 10127,
  [SMALL_STATE(325)] = 10135,
  [SMALL_STATE(326)] = 10143,
  [SMALL_STATE(327)] = 10151,
  [SMALL_STATE(328)] = 10159,
  [SMALL_STATE(329)] = 10167,
  [SMALL_STATE(330)] = 10175,
  [SMALL_STATE(331)] = 10183,
  [SMALL_STATE(332)] = 10191,
  [SMALL_STATE(333)] = 10199,
  [SMALL_STATE(334)] = 10207,
  [SMALL_STATE(335)] = 10215,
  [SMALL_STATE(336)] = 10223,
  [SMALL_STATE(337)] = 10231,
  [SMALL_STATE(338)] = 10239,
  [SMALL_STATE(339)] = 10247,
  [SMALL_STATE(340)] = 10255,
  [SMALL_STATE(341)] = 10263,
  [SMALL_STATE(342)] = 10271,
  [SMALL_STATE(343)] = 10279,
  [SMALL_STATE(344)] = 10287,
  [SMALL_STATE(345)] = 10295,
  [SMALL_STATE(346)] = 10303,
  [SMALL_STATE(347)] = 10311,
  [SMALL_STATE(348)] = 10319,
  [SMALL_STATE(349)] = 10327,
  [SMALL_STATE(350)] = 10335,
  [SMALL_STATE(351)] = 10343,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stylesheet, 0),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(203),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(257),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(344),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(202),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(343),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(340),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(339),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(338),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(337),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(183),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(330),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(198),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(259),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(331),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(274),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(199),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(278),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [71] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(63),
  [74] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(198),
  [77] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(62),
  [80] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(259),
  [83] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(331),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2),
  [88] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(199),
  [91] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(189),
  [94] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(61),
  [97] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(343),
  [100] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(340),
  [103] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(339),
  [106] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(40),
  [109] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(338),
  [112] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(337),
  [115] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(184),
  [118] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(16),
  [121] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(330),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2),
  [126] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2), SHIFT_REPEAT(81),
  [129] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2), SHIFT_REPEAT(203),
  [132] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2), SHIFT_REPEAT(94),
  [135] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2), SHIFT_REPEAT(257),
  [138] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2), SHIFT_REPEAT(344),
  [141] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2), SHIFT_REPEAT(202),
  [144] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2), SHIFT_REPEAT(189),
  [147] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2), SHIFT_REPEAT(61),
  [150] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2), SHIFT_REPEAT(343),
  [153] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2), SHIFT_REPEAT(340),
  [156] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2), SHIFT_REPEAT(339),
  [159] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2), SHIFT_REPEAT(40),
  [162] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2), SHIFT_REPEAT(338),
  [165] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2), SHIFT_REPEAT(337),
  [168] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2), SHIFT_REPEAT(185),
  [171] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2), SHIFT_REPEAT(183),
  [174] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2), SHIFT_REPEAT(330),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stylesheet, 1),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [181] = {.entry = {.count = 1, .reusable = false}}, SHIFT(343),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(298),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(347),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(348),
  [197] = {.entry = {.count = 1, .reusable = false}}, SHIFT(167),
  [199] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [201] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(300),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(349),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(350),
  [225] = {.entry = {.count = 1, .reusable = false}}, SHIFT(235),
  [227] = {.entry = {.count = 1, .reusable = false}}, SHIFT(219),
  [229] = {.entry = {.count = 1, .reusable = false}}, SHIFT(220),
  [231] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(233),
  [235] = {.entry = {.count = 1, .reusable = false}}, SHIFT(233),
  [237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(312),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [247] = {.entry = {.count = 1, .reusable = false}}, SHIFT(197),
  [249] = {.entry = {.count = 1, .reusable = false}}, SHIFT(329),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(345),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(346),
  [255] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(319),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(261),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(341),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(342),
  [269] = {.entry = {.count = 1, .reusable = false}}, SHIFT(261),
  [271] = {.entry = {.count = 1, .reusable = false}}, SHIFT(215),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(262),
  [275] = {.entry = {.count = 1, .reusable = false}}, SHIFT(262),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_last_declaration, 3, .production_id = 14),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [285] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [289] = {.entry = {.count = 1, .reusable = false}}, SHIFT(170),
  [291] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__selector, 1, .production_id = 1),
  [301] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__value, 1, .production_id = 3),
  [303] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__selector, 1, .production_id = 1),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [307] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__value, 1, .production_id = 3),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [321] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__selector, 1),
  [323] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__value, 1),
  [325] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__selector, 1),
  [327] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__value, 1),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [331] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_last_declaration, 4, .production_id = 14),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [337] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_value, 3),
  [339] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_value, 3),
  [341] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2),
  [343] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2), SHIFT_REPEAT(312),
  [346] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2), SHIFT_REPEAT(83),
  [349] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2), SHIFT_REPEAT(167),
  [352] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2), SHIFT_REPEAT(102),
  [355] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2), SHIFT_REPEAT(345),
  [358] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2), SHIFT_REPEAT(346),
  [361] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_postcss_statement_repeat1, 2), SHIFT_REPEAT(167),
  [364] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_postcss_statement_repeat1, 2), SHIFT_REPEAT(90),
  [367] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_postcss_statement_repeat1, 2), SHIFT_REPEAT(88),
  [370] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_postcss_statement_repeat1, 2), SHIFT_REPEAT(57),
  [373] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2), SHIFT_REPEAT(76),
  [376] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2),
  [378] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2), SHIFT_REPEAT(312),
  [381] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2), SHIFT_REPEAT(83),
  [384] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2), SHIFT_REPEAT(170),
  [387] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2), SHIFT_REPEAT(102),
  [390] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2), SHIFT_REPEAT(345),
  [393] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2), SHIFT_REPEAT(346),
  [396] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_declaration_repeat1, 2), SHIFT_REPEAT(170),
  [399] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_declaration_repeat1, 2), SHIFT_REPEAT(90),
  [402] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_declaration_repeat1, 2), SHIFT_REPEAT(88),
  [405] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_declaration_repeat1, 2), SHIFT_REPEAT(57),
  [408] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_arguments_repeat1, 2),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [416] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [424] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pseudo_class_arguments_repeat1, 2),
  [426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(230),
  [446] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_selector, 3, .production_id = 10),
  [448] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_selector, 3, .production_id = 10),
  [450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [452] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_selector, 3, .production_id = 11),
  [454] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_selector, 3, .production_id = 11),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(247),
  [462] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__query, 1, .production_id = 4),
  [464] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__query, 1, .production_id = 4),
  [466] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_selector, 2, .production_id = 5),
  [468] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_selector, 2, .production_id = 5),
  [470] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [472] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_selector, 2, .production_id = 2),
  [474] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_selector, 2, .production_id = 2),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [478] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_selector, 3, .production_id = 10),
  [480] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_class_selector, 3, .production_id = 10),
  [482] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_universal_selector, 1),
  [484] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_universal_selector, 1),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(254),
  [488] = {.entry = {.count = 1, .reusable = false}}, SHIFT(254),
  [490] = {.entry = {.count = 1, .reusable = false}}, SHIFT(213),
  [492] = {.entry = {.count = 1, .reusable = true}}, SHIFT(332),
  [494] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [496] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [500] = {.entry = {.count = 1, .reusable = true}}, SHIFT(333),
  [502] = {.entry = {.count = 1, .reusable = true}}, SHIFT(334),
  [504] = {.entry = {.count = 1, .reusable = false}}, SHIFT(180),
  [506] = {.entry = {.count = 1, .reusable = false}}, SHIFT(194),
  [508] = {.entry = {.count = 1, .reusable = false}}, SHIFT(195),
  [510] = {.entry = {.count = 1, .reusable = false}}, SHIFT(190),
  [512] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_selector, 4, .production_id = 15),
  [514] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute_selector, 4, .production_id = 15),
  [516] = {.entry = {.count = 1, .reusable = true}}, SHIFT(264),
  [518] = {.entry = {.count = 1, .reusable = false}}, SHIFT(264),
  [520] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_selector, 2, .production_id = 2),
  [522] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_class_selector, 2, .production_id = 2),
  [524] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_id_selector, 2, .production_id = 6),
  [526] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_id_selector, 2, .production_id = 6),
  [528] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_selector, 4, .production_id = 11),
  [530] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_selector, 4, .production_id = 11),
  [532] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_selector, 4, .production_id = 10),
  [534] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_selector, 4, .production_id = 10),
  [536] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [538] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [540] = {.entry = {.count = 1, .reusable = true}}, SHIFT(242),
  [542] = {.entry = {.count = 1, .reusable = false}}, SHIFT(242),
  [544] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [546] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [548] = {.entry = {.count = 1, .reusable = true}}, SHIFT(256),
  [550] = {.entry = {.count = 1, .reusable = false}}, SHIFT(256),
  [552] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [554] = {.entry = {.count = 1, .reusable = false}}, SHIFT(228),
  [556] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [558] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [560] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [562] = {.entry = {.count = 1, .reusable = false}}, SHIFT(166),
  [564] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_arguments, 2),
  [566] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_arguments, 2),
  [568] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [570] = {.entry = {.count = 1, .reusable = false}}, SHIFT(130),
  [572] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_selector, 3, .production_id = 2),
  [574] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_selector, 3, .production_id = 2),
  [576] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_selector, 6, .production_id = 15),
  [578] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute_selector, 6, .production_id = 15),
  [580] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [582] = {.entry = {.count = 1, .reusable = false}}, SHIFT(179),
  [584] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_arguments, 4),
  [586] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_arguments, 4),
  [588] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_arguments, 3),
  [590] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_arguments, 3),
  [592] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [594] = {.entry = {.count = 1, .reusable = false}}, SHIFT(214),
  [596] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_arguments, 4),
  [598] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_arguments, 4),
  [600] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_value, 1),
  [602] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_float_value, 1),
  [604] = {.entry = {.count = 1, .reusable = false}}, SHIFT(147),
  [606] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [608] = {.entry = {.count = 1, .reusable = false}}, SHIFT(245),
  [610] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_value, 1),
  [612] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_integer_value, 1),
  [614] = {.entry = {.count = 1, .reusable = false}}, SHIFT(157),
  [616] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_arguments, 2),
  [618] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_arguments, 2),
  [620] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace_selector, 3),
  [622] = {.entry = {.count = 1, .reusable = true}}, SHIFT(307),
  [624] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_namespace_selector, 3),
  [626] = {.entry = {.count = 1, .reusable = true}}, SHIFT(265),
  [628] = {.entry = {.count = 1, .reusable = false}}, SHIFT(265),
  [630] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_adjacent_sibling_selector, 3),
  [632] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_adjacent_sibling_selector, 3),
  [634] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sibling_selector, 3),
  [636] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_sibling_selector, 3),
  [638] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_selector, 3, .production_id = 5),
  [640] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_selector, 3, .production_id = 5),
  [642] = {.entry = {.count = 1, .reusable = true}}, SHIFT(258),
  [644] = {.entry = {.count = 1, .reusable = false}}, SHIFT(258),
  [646] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_selector, 3, .production_id = 9),
  [648] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute_selector, 3, .production_id = 9),
  [650] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_child_selector, 3),
  [652] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_child_selector, 3),
  [654] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_arguments, 3),
  [656] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_arguments, 3),
  [658] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_selector, 5, .production_id = 9),
  [660] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute_selector, 5, .production_id = 9),
  [662] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_id_selector, 3, .production_id = 12),
  [664] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_id_selector, 3, .production_id = 12),
  [666] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_descendant_selector, 3),
  [668] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_descendant_selector, 3),
  [670] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 3),
  [672] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import_statement, 3),
  [674] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import_statement, 5),
  [676] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 5),
  [678] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration, 5, .production_id = 14),
  [680] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_declaration, 5, .production_id = 14),
  [682] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_namespace_statement, 4, .production_id = 13),
  [684] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace_statement, 4, .production_id = 13),
  [686] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import_statement, 4),
  [688] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 4),
  [690] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arguments, 4),
  [692] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arguments, 4),
  [694] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_at_rule, 3),
  [696] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_at_rule, 3),
  [698] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2),
  [700] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2),
  [702] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_supports_statement, 3),
  [704] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_supports_statement, 3),
  [706] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_keyframes_statement, 3, .production_id = 8),
  [708] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_keyframes_statement, 3, .production_id = 8),
  [710] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arguments, 3),
  [712] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arguments, 3),
  [714] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_grid_value, 4),
  [716] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_grid_value, 4),
  [718] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_keyframe_block_list, 3),
  [720] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_keyframe_block_list, 3),
  [722] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace_statement, 3),
  [724] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_namespace_statement, 3),
  [726] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_postcss_statement, 3),
  [728] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_postcss_statement, 3),
  [730] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_declaration, 6, .production_id = 14),
  [732] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration, 6, .production_id = 14),
  [734] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_charset_statement, 3),
  [736] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_charset_statement, 3),
  [738] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_keyframe_block_list, 2),
  [740] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_keyframe_block_list, 2),
  [742] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 4),
  [744] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 4),
  [746] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_media_statement, 3),
  [748] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_media_statement, 3),
  [750] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3),
  [752] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3),
  [754] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_media_statement, 4),
  [756] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_media_statement, 4),
  [758] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arguments, 2),
  [760] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arguments, 2),
  [762] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_at_rule, 4),
  [764] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_at_rule, 4),
  [766] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthesized_value, 3),
  [768] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parenthesized_value, 3),
  [770] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_value, 2),
  [772] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_color_value, 2),
  [774] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_grid_value, 3),
  [776] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_grid_value, 3),
  [778] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call_expression, 2, .production_id = 7),
  [780] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_call_expression, 2, .production_id = 7),
  [782] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_at_rule, 2),
  [784] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_at_rule, 2),
  [786] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_value, 2),
  [788] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_float_value, 2),
  [790] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rule_set, 2),
  [792] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rule_set, 2),
  [794] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration, 4, .production_id = 14),
  [796] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_declaration, 4, .production_id = 14),
  [798] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3),
  [800] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3),
  [802] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_value, 2),
  [804] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_integer_value, 2),
  [806] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_declaration_repeat1, 2),
  [808] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 1),
  [810] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_postcss_statement_repeat1, 1),
  [812] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [814] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_last_declaration, 5, .production_id = 14),
  [816] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 1),
  [818] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_declaration_repeat1, 1),
  [820] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [822] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [824] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [826] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [828] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [830] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [832] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [834] = {.entry = {.count = 1, .reusable = false}}, SHIFT(248),
  [836] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [838] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [840] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [842] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [844] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [846] = {.entry = {.count = 1, .reusable = true}}, SHIFT(306),
  [848] = {.entry = {.count = 1, .reusable = true}}, SHIFT(305),
  [850] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [852] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [854] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [856] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [858] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [860] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [862] = {.entry = {.count = 1, .reusable = true}}, SHIFT(308),
  [864] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [866] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [868] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_selectors, 1),
  [870] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [872] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_selectors_repeat1, 2),
  [874] = {.entry = {.count = 1, .reusable = false}}, SHIFT(193),
  [876] = {.entry = {.count = 1, .reusable = false}}, SHIFT(208),
  [878] = {.entry = {.count = 1, .reusable = false}}, SHIFT(271),
  [880] = {.entry = {.count = 1, .reusable = true}}, SHIFT(253),
  [882] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [884] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [886] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [888] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [890] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [892] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [894] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [896] = {.entry = {.count = 1, .reusable = true}}, SHIFT(301),
  [898] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [900] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [902] = {.entry = {.count = 1, .reusable = true}}, SHIFT(296),
  [904] = {.entry = {.count = 1, .reusable = true}}, SHIFT(294),
  [906] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [908] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [910] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [912] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_keyframe_block_list_repeat1, 2),
  [914] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_keyframe_block_list_repeat1, 2), SHIFT_REPEAT(296),
  [917] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_keyframe_block_list_repeat1, 2), SHIFT_REPEAT(294),
  [920] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [922] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [924] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [926] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [928] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [930] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_grid_value_repeat1, 2),
  [932] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_feature_query, 5, .production_id = 16),
  [934] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthesized_query, 3),
  [936] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_query, 3),
  [938] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_query, 2),
  [940] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_selector_query, 4),
  [942] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [944] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [946] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [948] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [950] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [952] = {.entry = {.count = 1, .reusable = true}}, SHIFT(237),
  [954] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [956] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [958] = {.entry = {.count = 1, .reusable = true}}, SHIFT(231),
  [960] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_import_statement_repeat1, 2),
  [962] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [964] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [966] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [968] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [970] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_arguments_repeat1, 2), SHIFT_REPEAT(59),
  [973] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [975] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_keyframe_block, 2),
  [977] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [979] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_import_statement_repeat1, 2), SHIFT_REPEAT(201),
  [982] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [984] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [986] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_selectors, 2),
  [988] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_grid_value_repeat1, 2), SHIFT_REPEAT(89),
  [991] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [993] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_selectors_repeat1, 2), SHIFT_REPEAT(37),
  [996] = {.entry = {.count = 1, .reusable = true}}, SHIFT(249),
  [998] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [1000] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [1002] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [1004] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [1006] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [1008] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pseudo_class_arguments_repeat1, 2), SHIFT_REPEAT(13),
  [1011] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [1013] = {.entry = {.count = 1, .reusable = true}}, SHIFT(243),
  [1015] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [1017] = {.entry = {.count = 1, .reusable = false}}, SHIFT(139),
  [1019] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [1021] = {.entry = {.count = 1, .reusable = false}}, SHIFT(222),
  [1023] = {.entry = {.count = 1, .reusable = true}}, SHIFT(236),
  [1025] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [1027] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [1029] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [1031] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [1033] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [1035] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [1037] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [1039] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [1041] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [1043] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [1045] = {.entry = {.count = 1, .reusable = true}}, SHIFT(232),
  [1047] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [1049] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [1051] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [1053] = {.entry = {.count = 1, .reusable = true}}, SHIFT(281),
  [1055] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [1057] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [1059] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [1061] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [1063] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [1065] = {.entry = {.count = 1, .reusable = true}}, SHIFT(295),
  [1067] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [1069] = {.entry = {.count = 1, .reusable = false}}, SHIFT(304),
  [1071] = {.entry = {.count = 1, .reusable = false}}, SHIFT(351),
  [1073] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [1075] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [1077] = {.entry = {.count = 1, .reusable = false}}, SHIFT(311),
  [1079] = {.entry = {.count = 1, .reusable = false}}, SHIFT(315),
  [1081] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [1083] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [1085] = {.entry = {.count = 1, .reusable = false}}, SHIFT(313),
  [1087] = {.entry = {.count = 1, .reusable = false}}, SHIFT(314),
  [1089] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [1091] = {.entry = {.count = 1, .reusable = true}}, SHIFT(302),
  [1093] = {.entry = {.count = 1, .reusable = false}}, SHIFT(322),
  [1095] = {.entry = {.count = 1, .reusable = false}}, SHIFT(323),
  [1097] = {.entry = {.count = 1, .reusable = false}}, SHIFT(303),
  [1099] = {.entry = {.count = 1, .reusable = false}}, SHIFT(324),
  [1101] = {.entry = {.count = 1, .reusable = false}}, SHIFT(325),
  [1103] = {.entry = {.count = 1, .reusable = false}}, SHIFT(326),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_ncss_external_scanner_create(void);
void tree_sitter_ncss_external_scanner_destroy(void *);
bool tree_sitter_ncss_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_ncss_external_scanner_serialize(void *, char *);
void tree_sitter_ncss_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_ncss(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_ncss_external_scanner_create,
      tree_sitter_ncss_external_scanner_destroy,
      tree_sitter_ncss_external_scanner_scan,
      tree_sitter_ncss_external_scanner_serialize,
      tree_sitter_ncss_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
