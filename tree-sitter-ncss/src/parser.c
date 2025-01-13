#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
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
#define STATE_COUNT 353
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 118
#define ALIAS_COUNT 9
#define TOKEN_COUNT 60
#define EXTERNAL_TOKEN_COUNT 3
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 17

enum ts_symbol_identifiers {
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
  anon_sym_SLASH = 41,
  aux_sym_color_value_token1 = 42,
  anon_sym_SQUOTE = 43,
  aux_sym_string_value_token1 = 44,
  anon_sym_DQUOTE = 45,
  aux_sym_string_value_token2 = 46,
  sym_boolean_value = 47,
  aux_sym_integer_value_token1 = 48,
  aux_sym_float_value_token1 = 49,
  sym_unit = 50,
  sym_identifier = 51,
  sym_at_keyword = 52,
  sym_js_comment = 53,
  anon_sym_DASH = 54,
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
  sym__usable_value = 96,
  sym_slash_separator = 97,
  sym__value = 98,
  sym_parenthesized_value = 99,
  sym_color_value = 100,
  sym_string_value = 101,
  sym_integer_value = 102,
  sym_float_value = 103,
  sym_grid_value = 104,
  sym_call_expression = 105,
  sym_arguments = 106,
  sym_binary_expression = 107,
  aux_sym_stylesheet_repeat1 = 108,
  aux_sym_import_statement_repeat1 = 109,
  aux_sym_keyframe_block_list_repeat1 = 110,
  aux_sym_postcss_statement_repeat1 = 111,
  aux_sym_selectors_repeat1 = 112,
  aux_sym_block_repeat1 = 113,
  aux_sym_pseudo_class_arguments_repeat1 = 114,
  aux_sym_declaration_repeat1 = 115,
  aux_sym_grid_value_repeat1 = 116,
  aux_sym_arguments_repeat1 = 117,
  alias_sym_class_name = 118,
  alias_sym_feature_name = 119,
  alias_sym_function_name = 120,
  alias_sym_id_name = 121,
  alias_sym_keyframes_name = 122,
  alias_sym_keyword_query = 123,
  alias_sym_namespace_name = 124,
  alias_sym_property_name = 125,
  alias_sym_tag_name = 126,
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
  [anon_sym_SLASH] = "/",
  [aux_sym_color_value_token1] = "color_value_token1",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_string_value_token1] = "string_value_token1",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_value_token2] = "string_value_token2",
  [sym_boolean_value] = "boolean_value",
  [aux_sym_integer_value_token1] = "integer_value_token1",
  [aux_sym_float_value_token1] = "float_value_token1",
  [sym_unit] = "unit",
  [sym_identifier] = "attribute_name",
  [sym_at_keyword] = "at_keyword",
  [sym_js_comment] = "js_comment",
  [anon_sym_DASH] = "-",
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
  [sym__usable_value] = "_usable_value",
  [sym_slash_separator] = "slash_separator",
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
  [anon_sym_SLASH] = anon_sym_SLASH,
  [aux_sym_color_value_token1] = aux_sym_color_value_token1,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_string_value_token1] = aux_sym_string_value_token1,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_value_token2] = aux_sym_string_value_token2,
  [sym_boolean_value] = sym_boolean_value,
  [aux_sym_integer_value_token1] = aux_sym_integer_value_token1,
  [aux_sym_float_value_token1] = aux_sym_float_value_token1,
  [sym_unit] = sym_unit,
  [sym_identifier] = sym_identifier,
  [sym_at_keyword] = sym_at_keyword,
  [sym_js_comment] = sym_js_comment,
  [anon_sym_DASH] = anon_sym_DASH,
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
  [sym__usable_value] = sym__usable_value,
  [sym_slash_separator] = sym_slash_separator,
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
  [anon_sym_SLASH] = {
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
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
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
  [sym__usable_value] = {
    .visible = false,
    .named = true,
  },
  [sym_slash_separator] = {
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
  [5] = 3,
  [6] = 2,
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
  [21] = 21,
  [22] = 22,
  [23] = 20,
  [24] = 24,
  [25] = 20,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 33,
  [35] = 29,
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
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 48,
  [56] = 48,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 61,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 87,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 32,
  [98] = 98,
  [99] = 99,
  [100] = 79,
  [101] = 92,
  [102] = 93,
  [103] = 103,
  [104] = 99,
  [105] = 92,
  [106] = 93,
  [107] = 87,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 108,
  [118] = 118,
  [119] = 119,
  [120] = 111,
  [121] = 112,
  [122] = 115,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 113,
  [127] = 127,
  [128] = 128,
  [129] = 129,
  [130] = 130,
  [131] = 131,
  [132] = 116,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 110,
  [138] = 114,
  [139] = 133,
  [140] = 128,
  [141] = 129,
  [142] = 142,
  [143] = 143,
  [144] = 144,
  [145] = 145,
  [146] = 130,
  [147] = 147,
  [148] = 148,
  [149] = 149,
  [150] = 150,
  [151] = 151,
  [152] = 152,
  [153] = 32,
  [154] = 123,
  [155] = 124,
  [156] = 131,
  [157] = 119,
  [158] = 134,
  [159] = 135,
  [160] = 118,
  [161] = 161,
  [162] = 136,
  [163] = 125,
  [164] = 127,
  [165] = 165,
  [166] = 166,
  [167] = 167,
  [168] = 168,
  [169] = 169,
  [170] = 170,
  [171] = 171,
  [172] = 172,
  [173] = 172,
  [174] = 26,
  [175] = 175,
  [176] = 176,
  [177] = 177,
  [178] = 178,
  [179] = 32,
  [180] = 180,
  [181] = 181,
  [182] = 182,
  [183] = 182,
  [184] = 181,
  [185] = 185,
  [186] = 186,
  [187] = 187,
  [188] = 187,
  [189] = 189,
  [190] = 190,
  [191] = 191,
  [192] = 90,
  [193] = 193,
  [194] = 194,
  [195] = 88,
  [196] = 196,
  [197] = 89,
  [198] = 198,
  [199] = 199,
  [200] = 143,
  [201] = 201,
  [202] = 202,
  [203] = 203,
  [204] = 196,
  [205] = 194,
  [206] = 152,
  [207] = 142,
  [208] = 144,
  [209] = 32,
  [210] = 147,
  [211] = 148,
  [212] = 166,
  [213] = 145,
  [214] = 149,
  [215] = 151,
  [216] = 150,
  [217] = 90,
  [218] = 218,
  [219] = 219,
  [220] = 89,
  [221] = 88,
  [222] = 149,
  [223] = 166,
  [224] = 148,
  [225] = 147,
  [226] = 152,
  [227] = 143,
  [228] = 142,
  [229] = 145,
  [230] = 144,
  [231] = 151,
  [232] = 32,
  [233] = 150,
  [234] = 234,
  [235] = 235,
  [236] = 236,
  [237] = 237,
  [238] = 235,
  [239] = 234,
  [240] = 240,
  [241] = 240,
  [242] = 242,
  [243] = 237,
  [244] = 237,
  [245] = 236,
  [246] = 246,
  [247] = 247,
  [248] = 247,
  [249] = 249,
  [250] = 250,
  [251] = 251,
  [252] = 252,
  [253] = 253,
  [254] = 254,
  [255] = 255,
  [256] = 256,
  [257] = 257,
  [258] = 258,
  [259] = 259,
  [260] = 257,
  [261] = 261,
  [262] = 259,
  [263] = 261,
  [264] = 257,
  [265] = 265,
  [266] = 266,
  [267] = 255,
  [268] = 258,
  [269] = 269,
  [270] = 116,
  [271] = 271,
  [272] = 272,
  [273] = 272,
  [274] = 269,
  [275] = 275,
  [276] = 110,
  [277] = 269,
  [278] = 271,
  [279] = 125,
  [280] = 280,
  [281] = 281,
  [282] = 282,
  [283] = 283,
  [284] = 283,
  [285] = 285,
  [286] = 286,
  [287] = 283,
  [288] = 288,
  [289] = 289,
  [290] = 290,
  [291] = 291,
  [292] = 292,
  [293] = 288,
  [294] = 294,
  [295] = 295,
  [296] = 296,
  [297] = 297,
  [298] = 298,
  [299] = 296,
  [300] = 298,
  [301] = 297,
  [302] = 302,
  [303] = 88,
  [304] = 304,
  [305] = 305,
  [306] = 306,
  [307] = 307,
  [308] = 308,
  [309] = 306,
  [310] = 307,
  [311] = 306,
  [312] = 312,
  [313] = 313,
  [314] = 314,
  [315] = 315,
  [316] = 307,
  [317] = 317,
  [318] = 308,
  [319] = 305,
  [320] = 320,
  [321] = 306,
  [322] = 307,
  [323] = 306,
  [324] = 307,
  [325] = 306,
  [326] = 307,
  [327] = 315,
  [328] = 328,
  [329] = 329,
  [330] = 330,
  [331] = 331,
  [332] = 315,
  [333] = 331,
  [334] = 334,
  [335] = 335,
  [336] = 304,
  [337] = 308,
  [338] = 305,
  [339] = 339,
  [340] = 334,
  [341] = 304,
  [342] = 334,
  [343] = 343,
  [344] = 314,
  [345] = 304,
  [346] = 334,
  [347] = 304,
  [348] = 334,
  [349] = 304,
  [350] = 334,
  [351] = 351,
  [352] = 320,
};

static TSCharacterRange sym_plain_value_character_set_1[] = {
  {0, 0x08}, {0x0e, 0x1f}, {'"', '\''}, {'+', '+'}, {'-', ':'}, {'<', 'Z'}, {'\\', '\\'}, {'^', 'z'},
  {'|', '|'}, {'~', 0x10ffff},
};

static TSCharacterRange sym_plain_value_character_set_2[] = {
  {0, 0x08}, {0x0e, 0x1f}, {'"', '\''}, {'*', '+'}, {'-', ':'}, {'<', 'Z'}, {'\\', '\\'}, {'^', 'z'},
  {'|', '|'}, {'~', 0x10ffff},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(69);
      ADVANCE_MAP(
        '!', 43,
        '"', 175,
        '#', 91,
        '$', 37,
        '&', 85,
        '\'', 165,
        '(', 107,
        ')', 108,
        '*', 87,
        '+', 104,
        ',', 71,
        '-', 330,
        '.', 89,
        '/', 127,
        ':', 109,
        ';', 72,
        '=', 93,
        '>', 100,
        '@', 41,
        '[', 92,
        ']', 99,
        '^', 39,
        'a', 258,
        'f', 246,
        'n', 262,
        'o', 260,
        's', 252,
        't', 263,
        '{', 78,
        '|', 106,
        '}', 79,
        '~', 102,
        'E', 219,
        'e', 219,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(66);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('b' <= lookahead && lookahead <= 'd')) ADVANCE(274);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '!', 43,
        '"', 175,
        '#', 91,
        '%', 218,
        '\'', 165,
        '(', 111,
        ')', 108,
        '*', 86,
        '+', 104,
        ',', 71,
        '-', 329,
        '.', 58,
        '/', 128,
        ';', 72,
        '[', 92,
        '_', 222,
        'f', 210,
        't', 213,
        '}', 79,
        'E', 209,
        'e', 209,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(216);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '!', 43,
        '"', 175,
        '#', 91,
        '&', 85,
        '\'', 165,
        '(', 111,
        ')', 108,
        '*', 86,
        '+', 31,
        ',', 71,
        '-', 30,
        '.', 89,
        '/', 23,
        ':', 36,
        ';', 72,
        '[', 92,
        '_', 222,
        'f', 223,
        't', 236,
        'E', 221,
        'e', 221,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      END_STATE();
    case 3:
      ADVANCE_MAP(
        '!', 43,
        '"', 175,
        '#', 91,
        '\'', 165,
        '(', 107,
        ')', 108,
        '*', 86,
        '+', 104,
        ',', 71,
        '-', 329,
        '.', 89,
        '/', 128,
        ':', 36,
        ';', 72,
        '>', 100,
        '[', 92,
        '_', 222,
        'f', 223,
        't', 236,
        '|', 105,
        '}', 79,
        '~', 101,
        'E', 221,
        'e', 221,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      END_STATE();
    case 4:
      ADVANCE_MAP(
        '!', 43,
        '"', 175,
        '#', 91,
        '\'', 165,
        '(', 107,
        '*', 86,
        '+', 104,
        ',', 71,
        '-', 329,
        '.', 58,
        '/', 128,
        ';', 72,
        '[', 92,
        '_', 222,
        'a', 232,
        'f', 223,
        'o', 238,
        't', 236,
        '{', 78,
        'E', 221,
        'e', 221,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      END_STATE();
    case 5:
      ADVANCE_MAP(
        '!', 43,
        '"', 175,
        '#', 91,
        '\'', 165,
        '(', 111,
        ')', 108,
        '*', 86,
        '+', 104,
        ',', 71,
        '-', 329,
        '.', 89,
        '/', 128,
        ':', 36,
        ';', 72,
        '>', 100,
        '[', 92,
        '_', 222,
        'f', 223,
        't', 236,
        '|', 105,
        '}', 79,
        '~', 101,
        'E', 221,
        'e', 221,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      END_STATE();
    case 6:
      ADVANCE_MAP(
        '!', 43,
        '"', 175,
        '#', 91,
        '\'', 165,
        '(', 111,
        ')', 108,
        '*', 86,
        '+', 104,
        ',', 71,
        '-', 329,
        '.', 58,
        '/', 128,
        ';', 72,
        '[', 92,
        '_', 222,
        'f', 223,
        't', 236,
        '}', 79,
        'E', 221,
        'e', 221,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      END_STATE();
    case 7:
      ADVANCE_MAP(
        '!', 43,
        '"', 175,
        '#', 91,
        '\'', 165,
        '(', 111,
        '*', 86,
        '+', 104,
        ',', 71,
        '-', 329,
        '.', 58,
        '/', 128,
        ';', 72,
        '[', 92,
        '_', 222,
        'a', 232,
        'f', 223,
        'o', 238,
        't', 236,
        '{', 78,
        'E', 221,
        'e', 221,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      END_STATE();
    case 8:
      ADVANCE_MAP(
        '!', 43,
        '"', 175,
        '#', 91,
        '\'', 165,
        '(', 111,
        '+', 31,
        '-', 30,
        '.', 58,
        '/', 23,
        ';', 72,
        '[', 92,
        '_', 222,
        'f', 223,
        'n', 234,
        'o', 233,
        's', 228,
        't', 236,
        '{', 78,
        'E', 221,
        'e', 221,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      END_STATE();
    case 9:
      ADVANCE_MAP(
        '#', 91,
        '$', 37,
        '(', 107,
        ')', 108,
        '*', 38,
        '+', 103,
        ',', 71,
        '.', 88,
        '/', 22,
        ':', 109,
        ';', 72,
        '=', 93,
        '>', 100,
        '[', 92,
        ']', 99,
        '^', 39,
        'a', 47,
        'o', 54,
        '{', 78,
        '|', 106,
        '~', 102,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('b' <= lookahead && lookahead <= 'f')) ADVANCE(61);
      END_STATE();
    case 10:
      ADVANCE_MAP(
        '#', 91,
        '$', 37,
        '(', 107,
        '*', 87,
        '+', 103,
        ',', 71,
        '-', 328,
        '.', 88,
        '/', 127,
        ':', 36,
        '=', 93,
        '>', 100,
        '[', 92,
        ']', 99,
        '^', 39,
        '|', 106,
        '~', 102,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(12);
      END_STATE();
    case 11:
      ADVANCE_MAP(
        '#', 91,
        '$', 37,
        ')', 108,
        '*', 38,
        '+', 103,
        ',', 71,
        '.', 88,
        '/', 22,
        ':', 109,
        ';', 72,
        '=', 93,
        '>', 100,
        '[', 92,
        ']', 99,
        '^', 39,
        'a', 46,
        'o', 54,
        '{', 78,
        '|', 106,
        '~', 102,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      END_STATE();
    case 12:
      ADVANCE_MAP(
        '#', 91,
        '$', 37,
        '*', 87,
        '+', 103,
        ',', 71,
        '-', 328,
        '.', 88,
        '/', 127,
        ':', 36,
        '=', 93,
        '>', 100,
        '[', 92,
        ']', 99,
        '^', 39,
        '|', 106,
        '~', 102,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(12);
      END_STATE();
    case 13:
      ADVANCE_MAP(
        '#', 91,
        '(', 107,
        ')', 108,
        '*', 86,
        '+', 103,
        ',', 71,
        '-', 328,
        '.', 88,
        '/', 127,
        ':', 109,
        ';', 72,
        '>', 100,
        '[', 92,
        ']', 99,
        'a', 46,
        'o', 54,
        '|', 105,
        '~', 101,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(14);
      END_STATE();
    case 14:
      ADVANCE_MAP(
        '#', 91,
        ')', 108,
        '*', 86,
        '+', 103,
        ',', 71,
        '-', 328,
        '.', 88,
        '/', 127,
        ':', 109,
        ';', 72,
        '>', 100,
        '[', 92,
        ']', 99,
        'a', 46,
        'o', 54,
        '|', 105,
        '~', 101,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(14);
      END_STATE();
    case 15:
      ADVANCE_MAP(
        '%', 218,
        '(', 111,
        '*', 86,
        '+', 103,
        '-', 331,
        '/', 127,
        ';', 72,
        '_', 275,
        'n', 202,
        'o', 201,
        's', 198,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(18);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 16:
      ADVANCE_MAP(
        '(', 107,
        '*', 86,
        '+', 103,
        '-', 331,
        '/', 127,
        ';', 72,
        'n', 262,
        'o', 261,
        's', 252,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(18);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 17:
      ADVANCE_MAP(
        '(', 111,
        '*', 86,
        '+', 103,
        '-', 331,
        '/', 127,
        ';', 72,
        'n', 262,
        'o', 261,
        's', 252,
        '{', 78,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(17);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 18:
      ADVANCE_MAP(
        '(', 111,
        '*', 86,
        '+', 103,
        '-', 331,
        '/', 127,
        ';', 72,
        'n', 262,
        'o', 261,
        's', 252,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(18);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 19:
      ADVANCE_MAP(
        '(', 111,
        '-', 63,
        '/', 22,
        ';', 72,
        'n', 262,
        'o', 261,
        's', 252,
        '{', 78,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(19);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 20:
      ADVANCE_MAP(
        ')', 108,
        '*', 86,
        '+', 103,
        ',', 71,
        '-', 328,
        '/', 127,
        ';', 72,
        ']', 99,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(20);
      END_STATE();
    case 21:
      ADVANCE_MAP(
        ')', 108,
        '*', 86,
        '+', 103,
        ',', 71,
        '-', 328,
        '/', 127,
        ';', 72,
        ']', 99,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(20);
      if (lookahead == '%' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(218);
      END_STATE();
    case 22:
      if (lookahead == '*') ADVANCE(25);
      if (lookahead == '/') ADVANCE(327);
      END_STATE();
    case 23:
      if (lookahead == '*') ADVANCE(25);
      if (lookahead == '/') ADVANCE(324);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(35);
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
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(27);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(61);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(274);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 27:
      if (lookahead == '-') ADVANCE(63);
      if (lookahead == '/') ADVANCE(22);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(27);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 28:
      if (lookahead == '-') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(193);
      END_STATE();
    case 29:
      if (lookahead == '-') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(153);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(163);
      END_STATE();
    case 30:
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == '/') ADVANCE(64);
      if (lookahead == '-' ||
          lookahead == '_') ADVANCE(222);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      END_STATE();
    case 31:
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      END_STATE();
    case 32:
      if (lookahead == '/') ADVANCE(22);
      if (lookahead == 'f') ADVANCE(55);
      if (lookahead == 't') ADVANCE(50);
      if (lookahead == '}') ADVANCE(79);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(60);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(32);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(190);
      END_STATE();
    case 33:
      if (lookahead == '/') ADVANCE(22);
      if (lookahead == '{') ADVANCE(78);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(33);
      END_STATE();
    case 34:
      if (lookahead == '/') ADVANCE(22);
      if (lookahead == '{') ADVANCE(78);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(33);
      if (lookahead == '%' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(218);
      END_STATE();
    case 35:
      if (lookahead == '/') ADVANCE(64);
      if (lookahead == '-' ||
          lookahead == '_') ADVANCE(35);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(333);
      END_STATE();
    case 36:
      if (lookahead == ':') ADVANCE(90);
      END_STATE();
    case 37:
      if (lookahead == '=') ADVANCE(98);
      END_STATE();
    case 38:
      if (lookahead == '=') ADVANCE(97);
      END_STATE();
    case 39:
      if (lookahead == '=') ADVANCE(95);
      END_STATE();
    case 40:
      if (lookahead == 'a') ADVANCE(48);
      END_STATE();
    case 41:
      if (lookahead == 'c') ADVANCE(294);
      if (lookahead == 'i') ADVANCE(296);
      if (lookahead == 'k') ADVANCE(284);
      if (lookahead == 'm') ADVANCE(285);
      if (lookahead == 'n') ADVANCE(279);
      if (lookahead == 's') ADVANCE(319);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 42:
      if (lookahead == 'd') ADVANCE(112);
      END_STATE();
    case 43:
      if (lookahead == 'i') ADVANCE(44);
      END_STATE();
    case 44:
      if (lookahead == 'm') ADVANCE(52);
      END_STATE();
    case 45:
      if (lookahead == 'm') ADVANCE(80);
      END_STATE();
    case 46:
      if (lookahead == 'n') ADVANCE(42);
      END_STATE();
    case 47:
      if (lookahead == 'n') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(62);
      END_STATE();
    case 48:
      if (lookahead == 'n') ADVANCE(57);
      END_STATE();
    case 49:
      if (lookahead == 'o') ADVANCE(53);
      END_STATE();
    case 50:
      if (lookahead == 'o') ADVANCE(82);
      END_STATE();
    case 51:
      if (lookahead == 'o') ADVANCE(45);
      END_STATE();
    case 52:
      if (lookahead == 'p') ADVANCE(49);
      END_STATE();
    case 53:
      if (lookahead == 'r') ADVANCE(56);
      END_STATE();
    case 54:
      if (lookahead == 'r') ADVANCE(115);
      END_STATE();
    case 55:
      if (lookahead == 'r') ADVANCE(51);
      END_STATE();
    case 56:
      if (lookahead == 't') ADVANCE(40);
      END_STATE();
    case 57:
      if (lookahead == 't') ADVANCE(110);
      END_STATE();
    case 58:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(192);
      END_STATE();
    case 59:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(193);
      END_STATE();
    case 60:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(190);
      END_STATE();
    case 61:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(62);
      END_STATE();
    case 62:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(163);
      END_STATE();
    case 63:
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 64:
      if ((!eof && set_contains(sym_plain_value_character_set_1, 10, lookahead))) ADVANCE(35);
      END_STATE();
    case 65:
      if ((!eof && set_contains(sym_plain_value_character_set_1, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 66:
      if (eof) ADVANCE(69);
      ADVANCE_MAP(
        '!', 43,
        '"', 175,
        '#', 91,
        '$', 37,
        '&', 85,
        '\'', 165,
        '(', 111,
        ')', 108,
        '*', 87,
        '+', 104,
        ',', 71,
        '-', 330,
        '.', 89,
        '/', 127,
        ':', 109,
        ';', 72,
        '=', 93,
        '>', 100,
        '@', 41,
        '[', 92,
        ']', 99,
        '^', 39,
        'a', 259,
        'f', 247,
        'n', 262,
        'o', 260,
        's', 252,
        't', 263,
        '{', 78,
        '|', 106,
        '}', 79,
        '~', 102,
        'E', 220,
        'e', 220,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(66);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 67:
      if (eof) ADVANCE(69);
      ADVANCE_MAP(
        '"', 175,
        '#', 91,
        '&', 85,
        '\'', 165,
        '(', 107,
        ')', 108,
        '*', 86,
        '+', 103,
        ',', 71,
        '-', 63,
        '.', 88,
        '/', 22,
        ':', 109,
        ';', 72,
        '>', 100,
        '@', 41,
        '[', 92,
        ']', 99,
        '{', 78,
        '|', 105,
        '}', 79,
        '~', 101,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(68);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 68:
      if (eof) ADVANCE(69);
      ADVANCE_MAP(
        '"', 175,
        '#', 91,
        '&', 85,
        '\'', 165,
        ')', 108,
        '*', 86,
        '+', 103,
        ',', 71,
        '-', 63,
        '.', 88,
        '/', 22,
        ':', 109,
        ';', 72,
        '>', 100,
        '@', 41,
        '[', 92,
        ']', 99,
        '{', 78,
        '|', 105,
        '}', 79,
        '~', 101,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(68);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_ATimport);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_ATmedia);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_ATcharset);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_ATnamespace);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_ATkeyframes);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(aux_sym_keyframes_statement_token1);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
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
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
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
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_ATsupports);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
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
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(192);
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
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
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
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_and);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
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
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_or);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_not);
      if (lookahead == '%') ADVANCE(218);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(275);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_not);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_not);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_only);
      if (lookahead == '%') ADVANCE(218);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(275);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_only);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_only);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_selector);
      if (lookahead == '%') ADVANCE(218);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(275);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_selector);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_selector);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '*') ADVANCE(25);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '*') ADVANCE(25);
      if (lookahead == '/') ADVANCE(324);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(35);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(193);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(142);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(129);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(145);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(155);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(147);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(157);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(150);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(159);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(161);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(130);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(136);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(132);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(157);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(131);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(137);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(133);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(159);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(134);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(140);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(193);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(194);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(143);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(164);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(142);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(129);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(148);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(156);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(145);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(155);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(144);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(154);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(146);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(158);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(147);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(157);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(149);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(160);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(150);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(159);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(161);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(164);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(129);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(154);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(275);
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
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(275);
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
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(159);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(160);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(161);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '\n') ADVANCE(172);
      if (lookahead == '\\') ADVANCE(166);
      if (lookahead != 0) ADVANCE(174);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '*') ADVANCE(169);
      if (lookahead == '/') ADVANCE(174);
      if (lookahead == '\\') ADVANCE(173);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'') ADVANCE(172);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '*') ADVANCE(168);
      if (lookahead == '/') ADVANCE(172);
      if (lookahead == '\\') ADVANCE(170);
      if (lookahead == '\n' ||
          lookahead == '\'') ADVANCE(25);
      if (lookahead != 0) ADVANCE(169);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '*') ADVANCE(168);
      if (lookahead == '\\') ADVANCE(170);
      if (lookahead == '\n' ||
          lookahead == '\'') ADVANCE(25);
      if (lookahead != 0) ADVANCE(169);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '*') ADVANCE(168);
      if (lookahead == '\\') ADVANCE(170);
      if (lookahead != 0) ADVANCE(169);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '/') ADVANCE(167);
      if (lookahead == '\\') ADVANCE(173);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(171);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '\'') ADVANCE(172);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '\\') ADVANCE(173);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'') ADVANCE(172);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '\\') ADVANCE(173);
      if (lookahead != 0) ADVANCE(172);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '\\') ADVANCE(166);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'') ADVANCE(174);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '\n') ADVANCE(182);
      if (lookahead == '\\') ADVANCE(176);
      if (lookahead != 0) ADVANCE(184);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '*') ADVANCE(179);
      if (lookahead == '/') ADVANCE(184);
      if (lookahead == '\\') ADVANCE(183);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"') ADVANCE(182);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '*') ADVANCE(178);
      if (lookahead == '/') ADVANCE(182);
      if (lookahead == '\\') ADVANCE(180);
      if (lookahead == '\n' ||
          lookahead == '"') ADVANCE(25);
      if (lookahead != 0) ADVANCE(179);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '*') ADVANCE(178);
      if (lookahead == '\\') ADVANCE(180);
      if (lookahead == '\n' ||
          lookahead == '"') ADVANCE(25);
      if (lookahead != 0) ADVANCE(179);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '*') ADVANCE(178);
      if (lookahead == '\\') ADVANCE(180);
      if (lookahead != 0) ADVANCE(179);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '/') ADVANCE(177);
      if (lookahead == '\\') ADVANCE(183);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(181);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '"') ADVANCE(182);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '\\') ADVANCE(183);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"') ADVANCE(182);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '\\') ADVANCE(183);
      if (lookahead != 0) ADVANCE(182);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '\\') ADVANCE(176);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"') ADVANCE(184);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_boolean_value);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_boolean_value);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_integer_value_token1);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_integer_value_token1);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(189);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_integer_value_token1);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(135);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(163);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(141);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_integer_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(190);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_float_value_token1);
      if (lookahead == '/') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(191);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_float_value_token1);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(192);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_float_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(193);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(aux_sym_float_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(194);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym_float_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(151);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(162);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(218);
      if (lookahead == 'c') ADVANCE(206);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(275);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(218);
      if (lookahead == 'e') ADVANCE(196);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(275);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(218);
      if (lookahead == 'e') ADVANCE(200);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(275);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(218);
      if (lookahead == 'l') ADVANCE(207);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(275);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(218);
      if (lookahead == 'l') ADVANCE(197);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(275);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(218);
      if (lookahead == 'n') ADVANCE(199);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(275);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(218);
      if (lookahead == 'o') ADVANCE(205);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(275);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(218);
      if (lookahead == 'o') ADVANCE(204);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(275);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(218);
      if (lookahead == 'r') ADVANCE(124);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(275);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(218);
      if (lookahead == 't') ADVANCE(118);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(275);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(218);
      if (lookahead == 't') ADVANCE(203);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(275);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(218);
      if (lookahead == 'y') ADVANCE(121);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(275);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(218);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(275);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(217);
      if (lookahead == '-') ADVANCE(244);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '_') ADVANCE(245);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(191);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(216);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(217);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'a') ADVANCE(212);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(245);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(216);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(217);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'e') ADVANCE(216);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(245);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(216);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(217);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'l') ADVANCE(214);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(245);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(216);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(217);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'r') ADVANCE(215);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(245);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(216);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(217);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 's') ADVANCE(211);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(245);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(216);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(217);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'u') ADVANCE(211);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(245);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(216);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(217);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(245);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(216);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '%' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(218);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(272);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(195);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(273);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(272);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(194);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(244);
      if (lookahead == '/') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(191);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(64);
      if (lookahead == '-' ||
          lookahead == '_') ADVANCE(222);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(275);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'a') ADVANCE(229);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'c') ADVANCE(241);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'd') ADVANCE(113);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'e') ADVANCE(185);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'e') ADVANCE(224);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'e') ADVANCE(231);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'l') ADVANCE(239);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'l') ADVANCE(243);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'l') ADVANCE(227);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'n') ADVANCE(225);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'n') ADVANCE(230);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'o') ADVANCE(240);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'o') ADVANCE(237);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'r') ADVANCE(242);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'r') ADVANCE(125);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'r') ADVANCE(116);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 's') ADVANCE(226);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 't') ADVANCE(119);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 't') ADVANCE(235);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'u') ADVANCE(226);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == 'y') ADVANCE(122);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(191);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(253);
      if (lookahead == 'r') ADVANCE(264);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('b' <= lookahead && lookahead <= 'f')) ADVANCE(273);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(254);
      if (lookahead == 'r') ADVANCE(264);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(114);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(248);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(186);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(256);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(267);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(162);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(267);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(271);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(250);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(81);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(273);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(249);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(255);
      if (lookahead == 'r') ADVANCE(117);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(255);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(268);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(83);
      if (lookahead == 'r') ADVANCE(270);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(266);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(126);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(251);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(120);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(265);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(251);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'y') ADVANCE(123);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(194);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(162);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(273);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'a') ADVANCE(306);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'a') ADVANCE(73);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'a') ADVANCE(282);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'a') ADVANCE(297);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'a') ADVANCE(298);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'a') ADVANCE(299);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'c') ADVANCE(286);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'd') ADVANCE(295);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(320);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(283);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(75);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(314);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(317);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(312);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(313);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(321);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'f') ADVANCE(309);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'f') ADVANCE(310);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'h') ADVANCE(276);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'i') ADVANCE(277);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 'm') ADVANCE(302);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 'm') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 'm') ADVANCE(289);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 'm') ADVANCE(290);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 'o') ADVANCE(307);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 'o') ADVANCE(308);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 'p') ADVANCE(300);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 'p') ADVANCE(278);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 'p') ADVANCE(301);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 'p') ADVANCE(304);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 'r') ADVANCE(315);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 'r') ADVANCE(316);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 'r') ADVANCE(318);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 'r') ADVANCE(280);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 'r') ADVANCE(281);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 's') ADVANCE(84);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 's') ADVANCE(76);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 's') ADVANCE(77);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 's') ADVANCE(303);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 's') ADVANCE(288);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 't') ADVANCE(70);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 't') ADVANCE(74);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 't') ADVANCE(311);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 'u') ADVANCE(305);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 'y') ADVANCE(292);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == 'y') ADVANCE(293);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(291);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(323);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(sym_js_comment);
      if (lookahead == '/') ADVANCE(325);
      if (lookahead == '-' ||
          lookahead == '_') ADVANCE(324);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(327);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(sym_js_comment);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ' ||
          lookahead == '!' ||
          ('(' <= lookahead && lookahead <= '*') ||
          lookahead == ',' ||
          lookahead == ';' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(327);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(324);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym_js_comment);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ' ||
          lookahead == '!' ||
          ('(' <= lookahead && lookahead <= '*') ||
          lookahead == ',' ||
          lookahead == ';' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(327);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(334);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(sym_js_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(327);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == '/') ADVANCE(64);
      if (lookahead == '-' ||
          lookahead == '_') ADVANCE(222);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '.') ADVANCE(58);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(220);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(sym_plain_value);
      if (lookahead == '/') ADVANCE(65);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(333);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(sym_plain_value);
      if (lookahead == '/') ADVANCE(326);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(334);
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
  [19] = {.lex_state = 3, .external_lex_state = 3},
  [20] = {.lex_state = 2},
  [21] = {.lex_state = 5},
  [22] = {.lex_state = 5},
  [23] = {.lex_state = 2},
  [24] = {.lex_state = 5},
  [25] = {.lex_state = 2},
  [26] = {.lex_state = 5, .external_lex_state = 3},
  [27] = {.lex_state = 2},
  [28] = {.lex_state = 2},
  [29] = {.lex_state = 5},
  [30] = {.lex_state = 2},
  [31] = {.lex_state = 2},
  [32] = {.lex_state = 5, .external_lex_state = 3},
  [33] = {.lex_state = 5},
  [34] = {.lex_state = 5},
  [35] = {.lex_state = 5},
  [36] = {.lex_state = 67, .external_lex_state = 2},
  [37] = {.lex_state = 67, .external_lex_state = 2},
  [38] = {.lex_state = 67, .external_lex_state = 2},
  [39] = {.lex_state = 67, .external_lex_state = 2},
  [40] = {.lex_state = 10, .external_lex_state = 3},
  [41] = {.lex_state = 67, .external_lex_state = 2},
  [42] = {.lex_state = 2},
  [43] = {.lex_state = 67, .external_lex_state = 2},
  [44] = {.lex_state = 67, .external_lex_state = 2},
  [45] = {.lex_state = 67, .external_lex_state = 2},
  [46] = {.lex_state = 67, .external_lex_state = 2},
  [47] = {.lex_state = 9, .external_lex_state = 3},
  [48] = {.lex_state = 2},
  [49] = {.lex_state = 9, .external_lex_state = 3},
  [50] = {.lex_state = 9, .external_lex_state = 3},
  [51] = {.lex_state = 4},
  [52] = {.lex_state = 2},
  [53] = {.lex_state = 9, .external_lex_state = 3},
  [54] = {.lex_state = 2},
  [55] = {.lex_state = 2},
  [56] = {.lex_state = 2},
  [57] = {.lex_state = 5},
  [58] = {.lex_state = 2},
  [59] = {.lex_state = 2},
  [60] = {.lex_state = 5},
  [61] = {.lex_state = 5},
  [62] = {.lex_state = 5},
  [63] = {.lex_state = 9, .external_lex_state = 3},
  [64] = {.lex_state = 9, .external_lex_state = 3},
  [65] = {.lex_state = 9, .external_lex_state = 3},
  [66] = {.lex_state = 9, .external_lex_state = 3},
  [67] = {.lex_state = 9, .external_lex_state = 3},
  [68] = {.lex_state = 9, .external_lex_state = 3},
  [69] = {.lex_state = 9, .external_lex_state = 3},
  [70] = {.lex_state = 9, .external_lex_state = 3},
  [71] = {.lex_state = 9, .external_lex_state = 3},
  [72] = {.lex_state = 9, .external_lex_state = 3},
  [73] = {.lex_state = 9, .external_lex_state = 3},
  [74] = {.lex_state = 2},
  [75] = {.lex_state = 9, .external_lex_state = 3},
  [76] = {.lex_state = 9, .external_lex_state = 3},
  [77] = {.lex_state = 9, .external_lex_state = 3},
  [78] = {.lex_state = 9, .external_lex_state = 3},
  [79] = {.lex_state = 2},
  [80] = {.lex_state = 9, .external_lex_state = 3},
  [81] = {.lex_state = 9, .external_lex_state = 3},
  [82] = {.lex_state = 9, .external_lex_state = 3},
  [83] = {.lex_state = 9, .external_lex_state = 3},
  [84] = {.lex_state = 9, .external_lex_state = 3},
  [85] = {.lex_state = 9, .external_lex_state = 3},
  [86] = {.lex_state = 9, .external_lex_state = 3},
  [87] = {.lex_state = 2},
  [88] = {.lex_state = 1},
  [89] = {.lex_state = 1},
  [90] = {.lex_state = 3},
  [91] = {.lex_state = 2},
  [92] = {.lex_state = 2},
  [93] = {.lex_state = 2},
  [94] = {.lex_state = 9, .external_lex_state = 3},
  [95] = {.lex_state = 2},
  [96] = {.lex_state = 9, .external_lex_state = 3},
  [97] = {.lex_state = 9, .external_lex_state = 3},
  [98] = {.lex_state = 2},
  [99] = {.lex_state = 2},
  [100] = {.lex_state = 2},
  [101] = {.lex_state = 2},
  [102] = {.lex_state = 2},
  [103] = {.lex_state = 9, .external_lex_state = 3},
  [104] = {.lex_state = 2},
  [105] = {.lex_state = 2},
  [106] = {.lex_state = 2},
  [107] = {.lex_state = 2},
  [108] = {.lex_state = 67, .external_lex_state = 2},
  [109] = {.lex_state = 67, .external_lex_state = 2},
  [110] = {.lex_state = 67, .external_lex_state = 2},
  [111] = {.lex_state = 67, .external_lex_state = 2},
  [112] = {.lex_state = 67, .external_lex_state = 2},
  [113] = {.lex_state = 67, .external_lex_state = 2},
  [114] = {.lex_state = 67, .external_lex_state = 2},
  [115] = {.lex_state = 67, .external_lex_state = 2},
  [116] = {.lex_state = 67, .external_lex_state = 2},
  [117] = {.lex_state = 67, .external_lex_state = 2},
  [118] = {.lex_state = 67, .external_lex_state = 2},
  [119] = {.lex_state = 67, .external_lex_state = 2},
  [120] = {.lex_state = 67, .external_lex_state = 2},
  [121] = {.lex_state = 67, .external_lex_state = 2},
  [122] = {.lex_state = 67, .external_lex_state = 2},
  [123] = {.lex_state = 67, .external_lex_state = 2},
  [124] = {.lex_state = 67, .external_lex_state = 2},
  [125] = {.lex_state = 67, .external_lex_state = 2},
  [126] = {.lex_state = 67, .external_lex_state = 2},
  [127] = {.lex_state = 67, .external_lex_state = 2},
  [128] = {.lex_state = 67, .external_lex_state = 2},
  [129] = {.lex_state = 67, .external_lex_state = 2},
  [130] = {.lex_state = 67, .external_lex_state = 2},
  [131] = {.lex_state = 67, .external_lex_state = 2},
  [132] = {.lex_state = 67, .external_lex_state = 2},
  [133] = {.lex_state = 67, .external_lex_state = 2},
  [134] = {.lex_state = 67, .external_lex_state = 2},
  [135] = {.lex_state = 67, .external_lex_state = 2},
  [136] = {.lex_state = 67, .external_lex_state = 2},
  [137] = {.lex_state = 67, .external_lex_state = 2},
  [138] = {.lex_state = 67, .external_lex_state = 2},
  [139] = {.lex_state = 67, .external_lex_state = 2},
  [140] = {.lex_state = 67, .external_lex_state = 2},
  [141] = {.lex_state = 67, .external_lex_state = 2},
  [142] = {.lex_state = 5},
  [143] = {.lex_state = 5},
  [144] = {.lex_state = 5},
  [145] = {.lex_state = 5},
  [146] = {.lex_state = 67, .external_lex_state = 2},
  [147] = {.lex_state = 5},
  [148] = {.lex_state = 5},
  [149] = {.lex_state = 5},
  [150] = {.lex_state = 5},
  [151] = {.lex_state = 5},
  [152] = {.lex_state = 5},
  [153] = {.lex_state = 5},
  [154] = {.lex_state = 67, .external_lex_state = 2},
  [155] = {.lex_state = 67, .external_lex_state = 2},
  [156] = {.lex_state = 67, .external_lex_state = 2},
  [157] = {.lex_state = 67, .external_lex_state = 2},
  [158] = {.lex_state = 67, .external_lex_state = 2},
  [159] = {.lex_state = 67, .external_lex_state = 2},
  [160] = {.lex_state = 67, .external_lex_state = 2},
  [161] = {.lex_state = 67, .external_lex_state = 2},
  [162] = {.lex_state = 67, .external_lex_state = 2},
  [163] = {.lex_state = 67, .external_lex_state = 2},
  [164] = {.lex_state = 67, .external_lex_state = 2},
  [165] = {.lex_state = 5},
  [166] = {.lex_state = 5},
  [167] = {.lex_state = 9, .external_lex_state = 3},
  [168] = {.lex_state = 9, .external_lex_state = 3},
  [169] = {.lex_state = 3},
  [170] = {.lex_state = 9, .external_lex_state = 3},
  [171] = {.lex_state = 9, .external_lex_state = 3},
  [172] = {.lex_state = 17},
  [173] = {.lex_state = 17},
  [174] = {.lex_state = 13, .external_lex_state = 3},
  [175] = {.lex_state = 5},
  [176] = {.lex_state = 5},
  [177] = {.lex_state = 5},
  [178] = {.lex_state = 5},
  [179] = {.lex_state = 13, .external_lex_state = 3},
  [180] = {.lex_state = 19},
  [181] = {.lex_state = 5},
  [182] = {.lex_state = 5},
  [183] = {.lex_state = 5},
  [184] = {.lex_state = 5},
  [185] = {.lex_state = 67, .external_lex_state = 3},
  [186] = {.lex_state = 67, .external_lex_state = 3},
  [187] = {.lex_state = 67, .external_lex_state = 3},
  [188] = {.lex_state = 67, .external_lex_state = 3},
  [189] = {.lex_state = 67, .external_lex_state = 3},
  [190] = {.lex_state = 67, .external_lex_state = 3},
  [191] = {.lex_state = 67, .external_lex_state = 3},
  [192] = {.lex_state = 16},
  [193] = {.lex_state = 67, .external_lex_state = 3},
  [194] = {.lex_state = 19},
  [195] = {.lex_state = 15},
  [196] = {.lex_state = 19},
  [197] = {.lex_state = 15},
  [198] = {.lex_state = 19},
  [199] = {.lex_state = 67, .external_lex_state = 3},
  [200] = {.lex_state = 17},
  [201] = {.lex_state = 19},
  [202] = {.lex_state = 19},
  [203] = {.lex_state = 19},
  [204] = {.lex_state = 19},
  [205] = {.lex_state = 19},
  [206] = {.lex_state = 17},
  [207] = {.lex_state = 17},
  [208] = {.lex_state = 17},
  [209] = {.lex_state = 17},
  [210] = {.lex_state = 17},
  [211] = {.lex_state = 17},
  [212] = {.lex_state = 17},
  [213] = {.lex_state = 17},
  [214] = {.lex_state = 17},
  [215] = {.lex_state = 17},
  [216] = {.lex_state = 17},
  [217] = {.lex_state = 13},
  [218] = {.lex_state = 67, .external_lex_state = 3},
  [219] = {.lex_state = 13},
  [220] = {.lex_state = 21},
  [221] = {.lex_state = 21},
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
  [234] = {.lex_state = 9},
  [235] = {.lex_state = 32},
  [236] = {.lex_state = 67},
  [237] = {.lex_state = 13},
  [238] = {.lex_state = 32},
  [239] = {.lex_state = 9},
  [240] = {.lex_state = 32},
  [241] = {.lex_state = 32},
  [242] = {.lex_state = 32},
  [243] = {.lex_state = 13},
  [244] = {.lex_state = 13},
  [245] = {.lex_state = 67},
  [246] = {.lex_state = 9},
  [247] = {.lex_state = 9},
  [248] = {.lex_state = 9},
  [249] = {.lex_state = 13},
  [250] = {.lex_state = 9},
  [251] = {.lex_state = 9},
  [252] = {.lex_state = 9},
  [253] = {.lex_state = 9},
  [254] = {.lex_state = 9},
  [255] = {.lex_state = 67},
  [256] = {.lex_state = 9},
  [257] = {.lex_state = 13},
  [258] = {.lex_state = 13},
  [259] = {.lex_state = 67},
  [260] = {.lex_state = 13},
  [261] = {.lex_state = 9},
  [262] = {.lex_state = 67},
  [263] = {.lex_state = 9},
  [264] = {.lex_state = 13},
  [265] = {.lex_state = 13},
  [266] = {.lex_state = 13},
  [267] = {.lex_state = 67},
  [268] = {.lex_state = 13},
  [269] = {.lex_state = 67},
  [270] = {.lex_state = 32},
  [271] = {.lex_state = 9},
  [272] = {.lex_state = 67},
  [273] = {.lex_state = 67},
  [274] = {.lex_state = 67},
  [275] = {.lex_state = 9},
  [276] = {.lex_state = 32},
  [277] = {.lex_state = 67},
  [278] = {.lex_state = 9},
  [279] = {.lex_state = 32},
  [280] = {.lex_state = 67},
  [281] = {.lex_state = 32},
  [282] = {.lex_state = 67},
  [283] = {.lex_state = 67},
  [284] = {.lex_state = 67},
  [285] = {.lex_state = 67},
  [286] = {.lex_state = 9},
  [287] = {.lex_state = 67},
  [288] = {.lex_state = 67},
  [289] = {.lex_state = 67},
  [290] = {.lex_state = 67},
  [291] = {.lex_state = 67},
  [292] = {.lex_state = 67},
  [293] = {.lex_state = 67},
  [294] = {.lex_state = 67},
  [295] = {.lex_state = 67},
  [296] = {.lex_state = 26},
  [297] = {.lex_state = 67},
  [298] = {.lex_state = 67},
  [299] = {.lex_state = 26},
  [300] = {.lex_state = 67},
  [301] = {.lex_state = 67},
  [302] = {.lex_state = 67},
  [303] = {.lex_state = 34},
  [304] = {.lex_state = 171},
  [305] = {.lex_state = 67},
  [306] = {.lex_state = 67},
  [307] = {.lex_state = 67},
  [308] = {.lex_state = 9},
  [309] = {.lex_state = 67},
  [310] = {.lex_state = 67},
  [311] = {.lex_state = 67},
  [312] = {.lex_state = 67},
  [313] = {.lex_state = 67},
  [314] = {.lex_state = 67},
  [315] = {.lex_state = 67},
  [316] = {.lex_state = 67},
  [317] = {.lex_state = 19},
  [318] = {.lex_state = 9},
  [319] = {.lex_state = 67},
  [320] = {.lex_state = 67},
  [321] = {.lex_state = 67},
  [322] = {.lex_state = 67},
  [323] = {.lex_state = 67},
  [324] = {.lex_state = 67},
  [325] = {.lex_state = 67},
  [326] = {.lex_state = 67},
  [327] = {.lex_state = 67},
  [328] = {.lex_state = 67},
  [329] = {.lex_state = 67},
  [330] = {.lex_state = 67},
  [331] = {.lex_state = 67},
  [332] = {.lex_state = 67},
  [333] = {.lex_state = 67},
  [334] = {.lex_state = 181},
  [335] = {.lex_state = 67},
  [336] = {.lex_state = 171},
  [337] = {.lex_state = 9},
  [338] = {.lex_state = 67},
  [339] = {.lex_state = 67},
  [340] = {.lex_state = 181},
  [341] = {.lex_state = 171},
  [342] = {.lex_state = 181},
  [343] = {.lex_state = 67},
  [344] = {.lex_state = 67},
  [345] = {.lex_state = 171},
  [346] = {.lex_state = 181},
  [347] = {.lex_state = 171},
  [348] = {.lex_state = 181},
  [349] = {.lex_state = 171},
  [350] = {.lex_state = 181},
  [351] = {.lex_state = 67},
  [352] = {.lex_state = 67},
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
    [anon_sym_SLASH] = ACTIONS(1),
    [aux_sym_color_value_token1] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym_boolean_value] = ACTIONS(1),
    [aux_sym_integer_value_token1] = ACTIONS(1),
    [aux_sym_float_value_token1] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [sym_at_keyword] = ACTIONS(1),
    [sym_js_comment] = ACTIONS(3),
    [anon_sym_DASH] = ACTIONS(1),
    [sym_comment] = ACTIONS(5),
    [sym__descendant_operator] = ACTIONS(1),
    [sym__pseudo_class_selector_colon] = ACTIONS(1),
    [sym___error_recovery] = ACTIONS(1),
  },
  [1] = {
    [sym_stylesheet] = STATE(335),
    [sym_import_statement] = STATE(9),
    [sym_media_statement] = STATE(9),
    [sym_charset_statement] = STATE(9),
    [sym_namespace_statement] = STATE(9),
    [sym_keyframes_statement] = STATE(9),
    [sym_supports_statement] = STATE(9),
    [sym_at_rule] = STATE(9),
    [sym_rule_set] = STATE(9),
    [sym_selectors] = STATE(301),
    [sym__selector] = STATE(185),
    [sym_universal_selector] = STATE(185),
    [sym_class_selector] = STATE(185),
    [sym_pseudo_class_selector] = STATE(185),
    [sym_pseudo_element_selector] = STATE(185),
    [sym_id_selector] = STATE(185),
    [sym_attribute_selector] = STATE(185),
    [sym_child_selector] = STATE(185),
    [sym_descendant_selector] = STATE(185),
    [sym_sibling_selector] = STATE(185),
    [sym_adjacent_sibling_selector] = STATE(185),
    [sym_namespace_selector] = STATE(185),
    [sym_declaration] = STATE(9),
    [sym_string_value] = STATE(185),
    [aux_sym_stylesheet_repeat1] = STATE(9),
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
    STATE(297), 1,
      sym_selectors,
    STATE(327), 1,
      sym_last_declaration,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(51), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(3), 11,
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
    STATE(185), 13,
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
    STATE(297), 1,
      sym_selectors,
    STATE(338), 1,
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
    STATE(185), 13,
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
    STATE(297), 1,
      sym_selectors,
    STATE(332), 1,
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
    STATE(185), 13,
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
    STATE(297), 1,
      sym_selectors,
    STATE(305), 1,
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
    STATE(185), 13,
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
    STATE(297), 1,
      sym_selectors,
    STATE(315), 1,
      sym_last_declaration,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(51), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(7), 11,
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
    STATE(185), 13,
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
    STATE(297), 1,
      sym_selectors,
    STATE(319), 1,
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
    STATE(185), 13,
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
    STATE(297), 1,
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
    STATE(185), 13,
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
    ACTIONS(124), 1,
      ts_builtin_sym_end,
    STATE(301), 1,
      sym_selectors,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(17), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(10), 10,
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
    STATE(185), 13,
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
    ACTIONS(126), 1,
      ts_builtin_sym_end,
    ACTIONS(128), 1,
      anon_sym_ATimport,
    ACTIONS(131), 1,
      anon_sym_ATmedia,
    ACTIONS(134), 1,
      anon_sym_ATcharset,
    ACTIONS(137), 1,
      anon_sym_ATnamespace,
    ACTIONS(143), 1,
      anon_sym_ATsupports,
    ACTIONS(146), 1,
      sym_nesting_selector,
    ACTIONS(149), 1,
      anon_sym_STAR,
    ACTIONS(152), 1,
      anon_sym_DOT,
    ACTIONS(155), 1,
      anon_sym_COLON_COLON,
    ACTIONS(158), 1,
      anon_sym_POUND,
    ACTIONS(161), 1,
      anon_sym_LBRACK,
    ACTIONS(164), 1,
      anon_sym_SQUOTE,
    ACTIONS(167), 1,
      anon_sym_DQUOTE,
    ACTIONS(170), 1,
      sym_identifier,
    ACTIONS(173), 1,
      sym_at_keyword,
    ACTIONS(176), 1,
      sym__pseudo_class_selector_colon,
    STATE(301), 1,
      sym_selectors,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(140), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(10), 10,
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
    STATE(185), 13,
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
      sym_string_value,
    STATE(27), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(165), 8,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
    STATE(190), 12,
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
    STATE(26), 1,
      sym_string_value,
    STATE(28), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(165), 8,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
    STATE(189), 12,
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
    STATE(26), 1,
      sym_string_value,
    STATE(42), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(165), 8,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
    STATE(193), 12,
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
    STATE(170), 1,
      sym_namespace_selector,
    STATE(174), 1,
      sym_string_value,
    ACTIONS(225), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(237), 8,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
    STATE(218), 11,
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
    STATE(170), 1,
      sym_namespace_selector,
    STATE(174), 1,
      sym_string_value,
    ACTIONS(235), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(243), 8,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
    STATE(218), 11,
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
    STATE(117), 1,
      sym_block,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(239), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
    STATE(165), 9,
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
    STATE(286), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
    STATE(260), 9,
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
    STATE(286), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
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
  [1458] = 8,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(283), 1,
      anon_sym_LPAREN,
    STATE(145), 1,
      sym_arguments,
    ACTIONS(281), 2,
      anon_sym_DOT,
      anon_sym_PLUS,
    ACTIONS(279), 4,
      anon_sym_STAR,
      sym_important,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
    ACTIONS(285), 8,
      anon_sym_LPAREN2,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      anon_sym_DASH,
      sym_plain_value,
    ACTIONS(277), 10,
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
  [1503] = 17,
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
    ACTIONS(289), 1,
      anon_sym_RPAREN,
    ACTIONS(291), 1,
      sym_identifier,
    STATE(30), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(269), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    ACTIONS(287), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    STATE(165), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1565] = 16,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(293), 1,
      anon_sym_COMMA,
    ACTIONS(298), 1,
      anon_sym_POUND,
    ACTIONS(301), 1,
      anon_sym_LBRACK,
    ACTIONS(304), 1,
      sym_important,
    ACTIONS(307), 1,
      anon_sym_LPAREN2,
    ACTIONS(310), 1,
      anon_sym_SLASH,
    ACTIONS(313), 1,
      anon_sym_SQUOTE,
    ACTIONS(316), 1,
      anon_sym_DQUOTE,
    ACTIONS(322), 1,
      aux_sym_integer_value_token1,
    ACTIONS(325), 1,
      aux_sym_float_value_token1,
    ACTIONS(328), 1,
      sym_identifier,
    ACTIONS(296), 2,
      anon_sym_SEMI,
      anon_sym_RBRACE,
    ACTIONS(319), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(21), 10,
      sym__usable_value,
      sym_slash_separator,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      aux_sym_declaration_repeat1,
  [1625] = 17,
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
    ACTIONS(331), 1,
      anon_sym_COMMA,
    ACTIONS(333), 1,
      anon_sym_SEMI,
    ACTIONS(335), 1,
      anon_sym_RBRACE,
    ACTIONS(337), 1,
      sym_important,
    ACTIONS(339), 1,
      anon_sym_SLASH,
    ACTIONS(343), 1,
      sym_identifier,
    ACTIONS(341), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(24), 10,
      sym__usable_value,
      sym_slash_separator,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      aux_sym_declaration_repeat1,
  [1687] = 17,
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
    ACTIONS(345), 1,
      anon_sym_RPAREN,
    STATE(30), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(274), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    ACTIONS(287), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    STATE(165), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1749] = 17,
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
    ACTIONS(331), 1,
      anon_sym_COMMA,
    ACTIONS(339), 1,
      anon_sym_SLASH,
    ACTIONS(343), 1,
      sym_identifier,
    ACTIONS(347), 1,
      anon_sym_SEMI,
    ACTIONS(349), 1,
      anon_sym_RBRACE,
    ACTIONS(351), 1,
      sym_important,
    ACTIONS(353), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(21), 10,
      sym__usable_value,
      sym_slash_separator,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      aux_sym_declaration_repeat1,
  [1811] = 17,
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
    ACTIONS(355), 1,
      anon_sym_RPAREN,
    STATE(30), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(277), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    ACTIONS(287), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    STATE(165), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1873] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(361), 2,
      anon_sym_DOT,
      anon_sym_PLUS,
    ACTIONS(359), 5,
      anon_sym_STAR,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
    ACTIONS(363), 7,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      anon_sym_DASH,
      sym_plain_value,
    ACTIONS(357), 10,
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
  [1912] = 17,
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
    ACTIONS(365), 1,
      anon_sym_COMMA,
    ACTIONS(367), 1,
      anon_sym_RPAREN,
    STATE(30), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(291), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(165), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1973] = 17,
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
    ACTIONS(365), 1,
      anon_sym_COMMA,
    ACTIONS(369), 1,
      anon_sym_RPAREN,
    STATE(30), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(285), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(165), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [2034] = 16,
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
    ACTIONS(331), 1,
      anon_sym_COMMA,
    ACTIONS(339), 1,
      anon_sym_SLASH,
    ACTIONS(343), 1,
      sym_identifier,
    ACTIONS(371), 1,
      anon_sym_SEMI,
    ACTIONS(373), 1,
      sym_important,
    ACTIONS(353), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(21), 10,
      sym__usable_value,
      sym_slash_separator,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      aux_sym_declaration_repeat1,
  [2093] = 15,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(377), 1,
      anon_sym_POUND,
    ACTIONS(380), 1,
      anon_sym_LBRACK,
    ACTIONS(383), 1,
      sym_important,
    ACTIONS(386), 1,
      anon_sym_LPAREN2,
    ACTIONS(389), 1,
      anon_sym_SQUOTE,
    ACTIONS(392), 1,
      anon_sym_DQUOTE,
    ACTIONS(398), 1,
      aux_sym_integer_value_token1,
    ACTIONS(401), 1,
      aux_sym_float_value_token1,
    ACTIONS(404), 1,
      sym_identifier,
    STATE(30), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(395), 2,
      sym_boolean_value,
      sym_plain_value,
    ACTIONS(375), 3,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    STATE(165), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [2150] = 15,
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
    STATE(30), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    ACTIONS(407), 3,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    STATE(165), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [2207] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(411), 9,
      anon_sym_DOT,
      anon_sym_PLUS,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      anon_sym_DASH,
      sym_plain_value,
    ACTIONS(409), 15,
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
  [2242] = 16,
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
    ACTIONS(331), 1,
      anon_sym_COMMA,
    ACTIONS(339), 1,
      anon_sym_SLASH,
    ACTIONS(343), 1,
      sym_identifier,
    ACTIONS(413), 1,
      anon_sym_SEMI,
    ACTIONS(415), 1,
      sym_important,
    ACTIONS(417), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(29), 10,
      sym__usable_value,
      sym_slash_separator,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      aux_sym_declaration_repeat1,
  [2301] = 16,
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
    ACTIONS(331), 1,
      anon_sym_COMMA,
    ACTIONS(333), 1,
      anon_sym_SEMI,
    ACTIONS(339), 1,
      anon_sym_SLASH,
    ACTIONS(343), 1,
      sym_identifier,
    ACTIONS(419), 1,
      sym_important,
    ACTIONS(421), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(35), 10,
      sym__usable_value,
      sym_slash_separator,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      aux_sym_declaration_repeat1,
  [2360] = 16,
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
    ACTIONS(331), 1,
      anon_sym_COMMA,
    ACTIONS(339), 1,
      anon_sym_SLASH,
    ACTIONS(343), 1,
      sym_identifier,
    ACTIONS(347), 1,
      anon_sym_SEMI,
    ACTIONS(423), 1,
      sym_important,
    ACTIONS(353), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(21), 10,
      sym__usable_value,
      sym_slash_separator,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      aux_sym_declaration_repeat1,
  [2419] = 12,
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
    ACTIONS(425), 1,
      sym_nesting_selector,
    ACTIONS(427), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(70), 13,
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
  [2469] = 13,
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
    ACTIONS(429), 1,
      sym_identifier,
    STATE(170), 1,
      sym_namespace_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(218), 12,
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
  [2521] = 12,
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
    ACTIONS(427), 1,
      sym_identifier,
    ACTIONS(431), 1,
      sym_nesting_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(71), 13,
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
  [2571] = 12,
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
    ACTIONS(427), 1,
      sym_identifier,
    ACTIONS(433), 1,
      sym_nesting_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(77), 13,
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
  [2621] = 10,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(437), 1,
      anon_sym_RBRACK,
    ACTIONS(439), 1,
      anon_sym_LPAREN,
    STATE(229), 1,
      sym_arguments,
    ACTIONS(279), 2,
      anon_sym_COMMA,
      anon_sym_DASH,
    ACTIONS(281), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(285), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(435), 6,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
    ACTIONS(277), 8,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
  [2667] = 12,
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
    ACTIONS(427), 1,
      sym_identifier,
    ACTIONS(441), 1,
      sym_nesting_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(66), 13,
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
  [2717] = 15,
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
    STATE(30), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    ACTIONS(443), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    STATE(165), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [2773] = 12,
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
    ACTIONS(427), 1,
      sym_identifier,
    ACTIONS(445), 1,
      sym_nesting_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(199), 13,
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
  [2823] = 12,
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
    ACTIONS(427), 1,
      sym_identifier,
    ACTIONS(447), 1,
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
  [2873] = 13,
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
    ACTIONS(449), 1,
      sym_identifier,
    STATE(171), 1,
      sym_namespace_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(218), 12,
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
  [2925] = 12,
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
    ACTIONS(427), 1,
      sym_identifier,
    ACTIONS(451), 1,
      sym_nesting_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(68), 13,
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
  [2975] = 5,
    ACTIONS(457), 1,
      anon_sym_LPAREN,
    STATE(76), 1,
      sym_pseudo_class_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(455), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(453), 18,
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
  [3010] = 15,
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
    ACTIONS(459), 1,
      anon_sym_RPAREN,
    STATE(23), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(165), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3065] = 5,
    ACTIONS(457), 1,
      anon_sym_LPAREN,
    STATE(72), 1,
      sym_pseudo_class_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(463), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(461), 18,
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
  [3100] = 5,
    ACTIONS(469), 1,
      anon_sym_LPAREN,
    STATE(73), 1,
      sym_pseudo_element_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(467), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(465), 18,
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
  [3135] = 8,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(283), 1,
      anon_sym_LPAREN,
    STATE(145), 1,
      sym_arguments,
    ACTIONS(473), 2,
      anon_sym_and,
      anon_sym_or,
    ACTIONS(471), 3,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
    ACTIONS(279), 6,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
    ACTIONS(285), 9,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      anon_sym_DASH,
      sym_plain_value,
  [3176] = 15,
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
    ACTIONS(475), 1,
      anon_sym_RPAREN,
    STATE(30), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(165), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3231] = 5,
    ACTIONS(469), 1,
      anon_sym_LPAREN,
    STATE(94), 1,
      sym_pseudo_element_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(479), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(477), 18,
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
  [3266] = 15,
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
    ACTIONS(481), 1,
      anon_sym_SEMI,
    STATE(30), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(165), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3321] = 15,
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
    ACTIONS(483), 1,
      anon_sym_RPAREN,
    STATE(20), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(165), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3376] = 15,
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
    ACTIONS(485), 1,
      anon_sym_RPAREN,
    STATE(25), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(165), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3431] = 14,
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
    ACTIONS(339), 1,
      anon_sym_SLASH,
    ACTIONS(343), 1,
      sym_identifier,
    ACTIONS(487), 1,
      sym_important,
    ACTIONS(489), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(22), 9,
      sym__usable_value,
      sym_slash_separator,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
  [3483] = 14,
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
    STATE(52), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(197), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(165), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3535] = 14,
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
    STATE(165), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3587] = 14,
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
    ACTIONS(339), 1,
      anon_sym_SLASH,
    ACTIONS(343), 1,
      sym_identifier,
    ACTIONS(491), 1,
      sym_important,
    ACTIONS(493), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(178), 9,
      sym__usable_value,
      sym_slash_separator,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
  [3639] = 14,
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
    ACTIONS(339), 1,
      anon_sym_SLASH,
    ACTIONS(343), 1,
      sym_identifier,
    ACTIONS(495), 1,
      sym_important,
    ACTIONS(497), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(34), 9,
      sym__usable_value,
      sym_slash_separator,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
  [3691] = 14,
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
    ACTIONS(339), 1,
      anon_sym_SLASH,
    ACTIONS(343), 1,
      sym_identifier,
    ACTIONS(499), 1,
      sym_important,
    ACTIONS(501), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(33), 9,
      sym__usable_value,
      sym_slash_separator,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
  [3743] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(505), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(503), 18,
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
  [3772] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(509), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(507), 18,
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
  [3801] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(513), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(511), 18,
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
  [3830] = 4,
    ACTIONS(517), 1,
      anon_sym_DOT,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(519), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(515), 17,
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
  [3861] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(523), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(521), 18,
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
  [3890] = 4,
    ACTIONS(517), 1,
      anon_sym_DOT,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(527), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(525), 17,
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
  [3921] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(531), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(529), 18,
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
  [3950] = 4,
    ACTIONS(517), 1,
      anon_sym_DOT,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(535), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(533), 17,
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
  [3981] = 4,
    ACTIONS(517), 1,
      anon_sym_DOT,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(539), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(537), 17,
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
  [4012] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(543), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(541), 18,
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
  [4041] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(547), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(545), 18,
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
  [4070] = 13,
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
    ACTIONS(549), 1,
      sym_important,
    ACTIONS(553), 1,
      sym_identifier,
    ACTIONS(551), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(266), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4119] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(557), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(555), 18,
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
  [4148] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(561), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(559), 18,
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
  [4177] = 4,
    ACTIONS(517), 1,
      anon_sym_DOT,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(565), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(563), 17,
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
  [4208] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(569), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(567), 18,
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
  [4237] = 13,
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
    ACTIONS(553), 1,
      sym_identifier,
    ACTIONS(571), 1,
      sym_important,
    ACTIONS(573), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(268), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4286] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(577), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(575), 18,
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
  [4315] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(581), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(579), 18,
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
  [4344] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(585), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(583), 18,
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
  [4373] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(281), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(277), 18,
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
  [4402] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(589), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(587), 18,
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
  [4431] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(593), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(591), 18,
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
  [4460] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(597), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(595), 18,
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
  [4489] = 13,
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
    ACTIONS(553), 1,
      sym_identifier,
    ACTIONS(599), 1,
      sym_important,
    ACTIONS(601), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(223), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4538] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(607), 1,
      sym_unit,
    ACTIONS(605), 8,
      anon_sym_PLUS,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      anon_sym_DASH,
      sym_plain_value,
    ACTIONS(603), 11,
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
  [4571] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(613), 1,
      sym_unit,
    ACTIONS(611), 8,
      anon_sym_PLUS,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      anon_sym_DASH,
      sym_plain_value,
    ACTIONS(609), 11,
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
  [4604] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(283), 1,
      anon_sym_LPAREN,
    STATE(145), 1,
      sym_arguments,
    ACTIONS(279), 9,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
    ACTIONS(285), 9,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      anon_sym_DASH,
      sym_plain_value,
  [4639] = 13,
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
    ACTIONS(615), 1,
      sym_important,
    ACTIONS(617), 2,
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
  [4688] = 13,
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
    ACTIONS(553), 1,
      sym_identifier,
    ACTIONS(619), 1,
      sym_important,
    ACTIONS(621), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(244), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4737] = 13,
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
    ACTIONS(553), 1,
      sym_identifier,
    ACTIONS(623), 1,
      sym_important,
    ACTIONS(625), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(257), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4786] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(629), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(627), 18,
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
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(553), 1,
      sym_identifier,
    ACTIONS(631), 1,
      sym_important,
    ACTIONS(633), 2,
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
  [4864] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(637), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(635), 18,
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
  [4893] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(411), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(409), 18,
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
  [4922] = 13,
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
    ACTIONS(553), 1,
      sym_identifier,
    ACTIONS(639), 1,
      sym_important,
    ACTIONS(641), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(249), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4971] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(643), 1,
      anon_sym_POUND,
    ACTIONS(645), 1,
      anon_sym_LBRACK,
    ACTIONS(647), 1,
      sym_important,
    ACTIONS(649), 1,
      anon_sym_LPAREN2,
    ACTIONS(651), 1,
      anon_sym_SQUOTE,
    ACTIONS(653), 1,
      anon_sym_DQUOTE,
    ACTIONS(657), 1,
      aux_sym_integer_value_token1,
    ACTIONS(659), 1,
      aux_sym_float_value_token1,
    ACTIONS(661), 1,
      sym_identifier,
    ACTIONS(655), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(172), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [5020] = 13,
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
    ACTIONS(553), 1,
      sym_identifier,
    ACTIONS(663), 1,
      sym_important,
    ACTIONS(665), 2,
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
  [5069] = 13,
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
    ACTIONS(553), 1,
      sym_identifier,
    ACTIONS(225), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(237), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [5118] = 13,
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
    ACTIONS(553), 1,
      sym_identifier,
    ACTIONS(269), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(260), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [5167] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(669), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(667), 18,
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
  [5196] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(643), 1,
      anon_sym_POUND,
    ACTIONS(645), 1,
      anon_sym_LBRACK,
    ACTIONS(649), 1,
      anon_sym_LPAREN2,
    ACTIONS(651), 1,
      anon_sym_SQUOTE,
    ACTIONS(653), 1,
      anon_sym_DQUOTE,
    ACTIONS(657), 1,
      aux_sym_integer_value_token1,
    ACTIONS(659), 1,
      aux_sym_float_value_token1,
    ACTIONS(661), 1,
      sym_identifier,
    ACTIONS(671), 1,
      sym_important,
    ACTIONS(673), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(173), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [5245] = 13,
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
    ACTIONS(553), 1,
      sym_identifier,
    ACTIONS(235), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(243), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [5294] = 13,
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
    ACTIONS(553), 1,
      sym_identifier,
    ACTIONS(275), 2,
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
  [5343] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(643), 1,
      anon_sym_POUND,
    ACTIONS(645), 1,
      anon_sym_LBRACK,
    ACTIONS(649), 1,
      anon_sym_LPAREN2,
    ACTIONS(651), 1,
      anon_sym_SQUOTE,
    ACTIONS(653), 1,
      anon_sym_DQUOTE,
    ACTIONS(657), 1,
      aux_sym_integer_value_token1,
    ACTIONS(659), 1,
      aux_sym_float_value_token1,
    ACTIONS(661), 1,
      sym_identifier,
    ACTIONS(675), 1,
      sym_important,
    ACTIONS(677), 2,
      sym_boolean_value,
      sym_plain_value,
    STATE(212), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [5392] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(681), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(679), 11,
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
  [5420] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(683), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(685), 11,
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
  [5448] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(689), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(687), 11,
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
  [5476] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(693), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(691), 11,
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
  [5504] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(697), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(695), 11,
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
  [5532] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(701), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(699), 11,
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
  [5560] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(705), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(703), 11,
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
  [5588] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(709), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(707), 11,
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
  [5616] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(713), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(711), 11,
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
  [5644] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(681), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(679), 11,
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
  [5672] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(715), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(717), 11,
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
  [5700] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(719), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(721), 11,
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
  [5728] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(693), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(691), 11,
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
  [5756] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(697), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(695), 11,
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
  [5784] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(709), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(707), 11,
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
  [5812] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(723), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(725), 11,
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
  [5840] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(727), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(729), 11,
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
  [5868] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(731), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(733), 11,
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
  [5896] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(701), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(699), 11,
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
  [5924] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(735), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(737), 11,
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
  [5952] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(739), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(741), 11,
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
  [5980] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(743), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(745), 11,
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
  [6008] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(747), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(749), 11,
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
  [6036] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(751), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(753), 11,
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
  [6064] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(713), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(711), 11,
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
  [6092] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(755), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(757), 11,
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
  [6120] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(759), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(761), 11,
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
  [6148] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(763), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(765), 11,
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
  [6176] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(767), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(769), 11,
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
  [6204] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(689), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(687), 11,
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
  [6232] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(705), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(703), 11,
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
  [6260] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(755), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(757), 11,
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
  [6288] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(739), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(741), 11,
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
  [6316] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(743), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(745), 11,
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
  [6344] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(773), 8,
      anon_sym_PLUS,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      anon_sym_DASH,
      sym_plain_value,
    ACTIONS(771), 11,
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
  [6374] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(777), 8,
      anon_sym_PLUS,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      anon_sym_DASH,
      sym_plain_value,
    ACTIONS(775), 11,
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
  [6404] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(781), 8,
      anon_sym_PLUS,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      anon_sym_DASH,
      sym_plain_value,
    ACTIONS(779), 11,
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
  [6434] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(785), 8,
      anon_sym_PLUS,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      anon_sym_DASH,
      sym_plain_value,
    ACTIONS(783), 11,
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
  [6464] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(747), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(749), 11,
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
  [6492] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(789), 8,
      anon_sym_PLUS,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      anon_sym_DASH,
      sym_plain_value,
    ACTIONS(787), 11,
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
  [6522] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(793), 8,
      anon_sym_PLUS,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      anon_sym_DASH,
      sym_plain_value,
    ACTIONS(791), 11,
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
  [6552] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(797), 8,
      anon_sym_PLUS,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      anon_sym_DASH,
      sym_plain_value,
    ACTIONS(795), 11,
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
  [6582] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(801), 8,
      anon_sym_PLUS,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      anon_sym_DASH,
      sym_plain_value,
    ACTIONS(799), 11,
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
  [6612] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(805), 8,
      anon_sym_PLUS,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      anon_sym_DASH,
      sym_plain_value,
    ACTIONS(803), 11,
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
  [6642] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(809), 8,
      anon_sym_PLUS,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      anon_sym_DASH,
      sym_plain_value,
    ACTIONS(807), 11,
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
  [6672] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(411), 8,
      anon_sym_PLUS,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      anon_sym_DASH,
      sym_plain_value,
    ACTIONS(409), 11,
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
  [6702] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(723), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(725), 11,
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
  [6730] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(727), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(729), 11,
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
  [6758] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(751), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(753), 11,
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
  [6786] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(719), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(721), 11,
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
  [6814] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(759), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(761), 11,
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
  [6842] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(763), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(765), 11,
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
  [6870] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(715), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(717), 11,
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
  [6898] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(681), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(679), 11,
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
  [6926] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(767), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(769), 11,
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
  [6954] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(731), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(733), 11,
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
  [6982] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(735), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(737), 11,
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
  [7010] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(813), 1,
      anon_sym_STAR,
    ACTIONS(815), 3,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_DASH,
    ACTIONS(817), 5,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      sym_plain_value,
    ACTIONS(811), 9,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7043] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(821), 8,
      anon_sym_PLUS,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      anon_sym_DASH,
      sym_plain_value,
    ACTIONS(819), 10,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7072] = 5,
    ACTIONS(825), 1,
      anon_sym_RBRACK,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(281), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(823), 6,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
    ACTIONS(277), 8,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
  [7102] = 5,
    ACTIONS(437), 1,
      anon_sym_RBRACK,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(281), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(435), 6,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
    ACTIONS(277), 8,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
  [7132] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(283), 1,
      anon_sym_LPAREN,
    STATE(145), 1,
      sym_arguments,
    ACTIONS(829), 7,
      anon_sym_LPAREN2,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      sym_plain_value,
    ACTIONS(827), 8,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7164] = 5,
    ACTIONS(437), 1,
      anon_sym_RBRACK,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(361), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(435), 6,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
    ACTIONS(357), 8,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
  [7194] = 5,
    ACTIONS(825), 1,
      anon_sym_RBRACK,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(361), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(823), 6,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
    ACTIONS(357), 8,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
  [7224] = 10,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(831), 1,
      anon_sym_SEMI,
    ACTIONS(835), 1,
      anon_sym_LPAREN2,
    ACTIONS(839), 1,
      sym_identifier,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    ACTIONS(833), 2,
      anon_sym_STAR,
      anon_sym_PLUS,
    ACTIONS(837), 2,
      anon_sym_SLASH,
      anon_sym_DASH,
    STATE(261), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [7263] = 10,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(835), 1,
      anon_sym_LPAREN2,
    ACTIONS(839), 1,
      sym_identifier,
    ACTIONS(841), 1,
      anon_sym_SEMI,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    ACTIONS(833), 2,
      anon_sym_STAR,
      anon_sym_PLUS,
    ACTIONS(837), 2,
      anon_sym_SLASH,
      anon_sym_DASH,
    STATE(263), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [7302] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(363), 1,
      anon_sym_SLASH,
    ACTIONS(359), 4,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_DASH,
    ACTIONS(357), 10,
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
  [7330] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(845), 1,
      anon_sym_SEMI,
    ACTIONS(847), 1,
      anon_sym_RBRACE,
    ACTIONS(849), 6,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      sym_plain_value,
    ACTIONS(843), 7,
      anon_sym_COMMA,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7360] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(853), 6,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      sym_plain_value,
    ACTIONS(851), 9,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7386] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(347), 1,
      anon_sym_SEMI,
    ACTIONS(349), 1,
      anon_sym_RBRACE,
    ACTIONS(849), 6,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      sym_plain_value,
    ACTIONS(843), 7,
      anon_sym_COMMA,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7416] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(855), 6,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      sym_plain_value,
    ACTIONS(296), 9,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7442] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(411), 1,
      anon_sym_SLASH,
    ACTIONS(409), 14,
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
  [7468] = 9,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(835), 1,
      anon_sym_LPAREN2,
    ACTIONS(839), 1,
      sym_identifier,
    ACTIONS(857), 1,
      anon_sym_SEMI,
    ACTIONS(859), 1,
      anon_sym_LBRACE,
    STATE(108), 1,
      sym_block,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(234), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [7503] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(845), 1,
      anon_sym_SEMI,
    ACTIONS(849), 6,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      sym_plain_value,
    ACTIONS(843), 7,
      anon_sym_COMMA,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7530] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(371), 1,
      anon_sym_SEMI,
    ACTIONS(849), 6,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      sym_plain_value,
    ACTIONS(843), 7,
      anon_sym_COMMA,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7557] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(347), 1,
      anon_sym_SEMI,
    ACTIONS(849), 6,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      sym_plain_value,
    ACTIONS(843), 7,
      anon_sym_COMMA,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7584] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(861), 1,
      anon_sym_SEMI,
    ACTIONS(849), 6,
      anon_sym_SLASH,
      sym_boolean_value,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      sym_plain_value,
    ACTIONS(843), 7,
      anon_sym_COMMA,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7611] = 14,
    ACTIONS(517), 1,
      anon_sym_DOT,
    ACTIONS(863), 1,
      anon_sym_COMMA,
    ACTIONS(865), 1,
      anon_sym_LBRACE,
    ACTIONS(867), 1,
      anon_sym_COLON_COLON,
    ACTIONS(869), 1,
      anon_sym_POUND,
    ACTIONS(871), 1,
      anon_sym_LBRACK,
    ACTIONS(873), 1,
      anon_sym_GT,
    ACTIONS(875), 1,
      anon_sym_TILDE,
    ACTIONS(877), 1,
      anon_sym_PLUS,
    ACTIONS(879), 1,
      anon_sym_PIPE,
    ACTIONS(881), 1,
      sym__descendant_operator,
    ACTIONS(883), 1,
      sym__pseudo_class_selector_colon,
    STATE(292), 1,
      aux_sym_selectors_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [7655] = 3,
    ACTIONS(885), 1,
      anon_sym_COLON,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(277), 12,
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
  [7677] = 3,
    ACTIONS(887), 1,
      anon_sym_COLON,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(277), 12,
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
  [7699] = 3,
    ACTIONS(889), 1,
      anon_sym_COLON,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(277), 12,
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
  [7721] = 14,
    ACTIONS(365), 1,
      anon_sym_COMMA,
    ACTIONS(369), 1,
      anon_sym_RPAREN,
    ACTIONS(517), 1,
      anon_sym_DOT,
    ACTIONS(867), 1,
      anon_sym_COLON_COLON,
    ACTIONS(869), 1,
      anon_sym_POUND,
    ACTIONS(871), 1,
      anon_sym_LBRACK,
    ACTIONS(873), 1,
      anon_sym_GT,
    ACTIONS(875), 1,
      anon_sym_TILDE,
    ACTIONS(877), 1,
      anon_sym_PLUS,
    ACTIONS(879), 1,
      anon_sym_PIPE,
    ACTIONS(881), 1,
      sym__descendant_operator,
    ACTIONS(883), 1,
      sym__pseudo_class_selector_colon,
    STATE(285), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [7765] = 14,
    ACTIONS(365), 1,
      anon_sym_COMMA,
    ACTIONS(367), 1,
      anon_sym_RPAREN,
    ACTIONS(517), 1,
      anon_sym_DOT,
    ACTIONS(867), 1,
      anon_sym_COLON_COLON,
    ACTIONS(869), 1,
      anon_sym_POUND,
    ACTIONS(871), 1,
      anon_sym_LBRACK,
    ACTIONS(873), 1,
      anon_sym_GT,
    ACTIONS(875), 1,
      anon_sym_TILDE,
    ACTIONS(877), 1,
      anon_sym_PLUS,
    ACTIONS(879), 1,
      anon_sym_PIPE,
    ACTIONS(881), 1,
      sym__descendant_operator,
    ACTIONS(883), 1,
      sym__pseudo_class_selector_colon,
    STATE(291), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [7809] = 12,
    ACTIONS(517), 1,
      anon_sym_DOT,
    ACTIONS(867), 1,
      anon_sym_COLON_COLON,
    ACTIONS(869), 1,
      anon_sym_POUND,
    ACTIONS(871), 1,
      anon_sym_LBRACK,
    ACTIONS(873), 1,
      anon_sym_GT,
    ACTIONS(875), 1,
      anon_sym_TILDE,
    ACTIONS(877), 1,
      anon_sym_PLUS,
    ACTIONS(879), 1,
      anon_sym_PIPE,
    ACTIONS(881), 1,
      sym__descendant_operator,
    ACTIONS(883), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(891), 2,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [7848] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(893), 1,
      anon_sym_LPAREN,
    STATE(213), 1,
      sym_arguments,
    ACTIONS(279), 3,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
    ACTIONS(285), 7,
      anon_sym_LPAREN2,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_SLASH,
      sym_identifier,
      anon_sym_DASH,
  [7875] = 12,
    ACTIONS(517), 1,
      anon_sym_DOT,
    ACTIONS(867), 1,
      anon_sym_COLON_COLON,
    ACTIONS(869), 1,
      anon_sym_POUND,
    ACTIONS(871), 1,
      anon_sym_LBRACK,
    ACTIONS(873), 1,
      anon_sym_GT,
    ACTIONS(875), 1,
      anon_sym_TILDE,
    ACTIONS(877), 1,
      anon_sym_PLUS,
    ACTIONS(879), 1,
      anon_sym_PIPE,
    ACTIONS(881), 1,
      sym__descendant_operator,
    ACTIONS(883), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(443), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [7914] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(835), 1,
      anon_sym_LPAREN2,
    ACTIONS(839), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(271), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [7940] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(895), 1,
      sym_unit,
    ACTIONS(603), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(605), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_SLASH,
      sym_identifier,
      anon_sym_DASH,
  [7964] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(835), 1,
      anon_sym_LPAREN2,
    ACTIONS(839), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(248), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [7990] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(897), 1,
      sym_unit,
    ACTIONS(609), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(611), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_SLASH,
      sym_identifier,
      anon_sym_DASH,
  [8014] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(835), 1,
      anon_sym_LPAREN2,
    ACTIONS(899), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(286), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [8040] = 12,
    ACTIONS(517), 1,
      anon_sym_DOT,
    ACTIONS(867), 1,
      anon_sym_COLON_COLON,
    ACTIONS(869), 1,
      anon_sym_POUND,
    ACTIONS(871), 1,
      anon_sym_LBRACK,
    ACTIONS(873), 1,
      anon_sym_GT,
    ACTIONS(875), 1,
      anon_sym_TILDE,
    ACTIONS(877), 1,
      anon_sym_PLUS,
    ACTIONS(879), 1,
      anon_sym_PIPE,
    ACTIONS(881), 1,
      sym__descendant_operator,
    ACTIONS(883), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(901), 1,
      anon_sym_RPAREN,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [8078] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(775), 5,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(777), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_SLASH,
      sym_identifier,
      anon_sym_DASH,
  [8100] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(835), 1,
      anon_sym_LPAREN2,
    ACTIONS(839), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(256), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [8126] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(835), 1,
      anon_sym_LPAREN2,
    ACTIONS(839), 1,
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
  [8152] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(835), 1,
      anon_sym_LPAREN2,
    ACTIONS(839), 1,
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
  [8178] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(835), 1,
      anon_sym_LPAREN2,
    ACTIONS(839), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(247), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [8204] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(835), 1,
      anon_sym_LPAREN2,
    ACTIONS(839), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(247), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(278), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [8230] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(807), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(809), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_SLASH,
      sym_identifier,
      anon_sym_DASH,
  [8251] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(771), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(773), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_SLASH,
      sym_identifier,
      anon_sym_DASH,
  [8272] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(779), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(781), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_SLASH,
      sym_identifier,
      anon_sym_DASH,
  [8293] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(409), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(411), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_SLASH,
      sym_identifier,
      anon_sym_DASH,
  [8314] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(787), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(789), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_SLASH,
      sym_identifier,
      anon_sym_DASH,
  [8335] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(791), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(793), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_SLASH,
      sym_identifier,
      anon_sym_DASH,
  [8356] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(819), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(821), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_SLASH,
      sym_identifier,
      anon_sym_DASH,
  [8377] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(783), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(785), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_SLASH,
      sym_identifier,
      anon_sym_DASH,
  [8398] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(795), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(797), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_SLASH,
      sym_identifier,
      anon_sym_DASH,
  [8419] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(803), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(805), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_SLASH,
      sym_identifier,
      anon_sym_DASH,
  [8440] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(799), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(801), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_SLASH,
      sym_identifier,
      anon_sym_DASH,
  [8461] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(285), 1,
      anon_sym_SLASH,
    ACTIONS(439), 1,
      anon_sym_LPAREN,
    STATE(229), 1,
      sym_arguments,
    ACTIONS(279), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8486] = 11,
    ACTIONS(517), 1,
      anon_sym_DOT,
    ACTIONS(867), 1,
      anon_sym_COLON_COLON,
    ACTIONS(869), 1,
      anon_sym_POUND,
    ACTIONS(871), 1,
      anon_sym_LBRACK,
    ACTIONS(873), 1,
      anon_sym_GT,
    ACTIONS(875), 1,
      anon_sym_TILDE,
    ACTIONS(877), 1,
      anon_sym_PLUS,
    ACTIONS(879), 1,
      anon_sym_PIPE,
    ACTIONS(881), 1,
      sym__descendant_operator,
    ACTIONS(883), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [8521] = 8,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(285), 1,
      anon_sym_SLASH,
    ACTIONS(439), 1,
      anon_sym_LPAREN,
    ACTIONS(903), 1,
      anon_sym_COLON,
    STATE(229), 1,
      sym_arguments,
    ACTIONS(279), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(471), 3,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [8550] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(611), 1,
      anon_sym_SLASH,
    ACTIONS(905), 1,
      sym_unit,
    ACTIONS(609), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8572] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(605), 1,
      anon_sym_SLASH,
    ACTIONS(907), 1,
      sym_unit,
    ACTIONS(603), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8594] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(797), 1,
      anon_sym_SLASH,
    ACTIONS(795), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8613] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(821), 1,
      anon_sym_SLASH,
    ACTIONS(819), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8632] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(793), 1,
      anon_sym_SLASH,
    ACTIONS(791), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8651] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(789), 1,
      anon_sym_SLASH,
    ACTIONS(787), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8670] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(809), 1,
      anon_sym_SLASH,
    ACTIONS(807), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8689] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(777), 1,
      anon_sym_SLASH,
    ACTIONS(775), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8708] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(773), 1,
      anon_sym_SLASH,
    ACTIONS(771), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8727] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(785), 1,
      anon_sym_SLASH,
    ACTIONS(783), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8746] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(781), 1,
      anon_sym_SLASH,
    ACTIONS(779), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8765] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(805), 1,
      anon_sym_SLASH,
    ACTIONS(803), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8784] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(411), 1,
      anon_sym_SLASH,
    ACTIONS(409), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8803] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(801), 1,
      anon_sym_SLASH,
    ACTIONS(799), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8822] = 7,
    ACTIONS(859), 1,
      anon_sym_LBRACE,
    ACTIONS(909), 1,
      anon_sym_COMMA,
    ACTIONS(911), 1,
      anon_sym_SEMI,
    STATE(113), 1,
      sym_block,
    STATE(259), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(913), 2,
      anon_sym_and,
      anon_sym_or,
  [8846] = 6,
    ACTIONS(915), 1,
      anon_sym_RBRACE,
    ACTIONS(919), 1,
      aux_sym_integer_value_token1,
    STATE(302), 1,
      sym_integer_value,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(917), 2,
      sym_from,
      sym_to,
    STATE(241), 2,
      sym_keyframe_block,
      aux_sym_keyframe_block_list_repeat1,
  [8868] = 7,
    ACTIONS(651), 1,
      anon_sym_SQUOTE,
    ACTIONS(653), 1,
      anon_sym_DQUOTE,
    ACTIONS(893), 1,
      anon_sym_LPAREN,
    ACTIONS(921), 1,
      sym_identifier,
    STATE(213), 1,
      sym_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(320), 2,
      sym_string_value,
      sym_call_expression,
  [8892] = 7,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(923), 1,
      anon_sym_COMMA,
    ACTIONS(927), 1,
      anon_sym_RBRACK,
    ACTIONS(929), 1,
      anon_sym_SLASH,
    STATE(284), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(925), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [8916] = 6,
    ACTIONS(919), 1,
      aux_sym_integer_value_token1,
    ACTIONS(931), 1,
      anon_sym_RBRACE,
    STATE(302), 1,
      sym_integer_value,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(917), 2,
      sym_from,
      sym_to,
    STATE(240), 2,
      sym_keyframe_block,
      aux_sym_keyframe_block_list_repeat1,
  [8938] = 7,
    ACTIONS(239), 1,
      anon_sym_LBRACE,
    ACTIONS(909), 1,
      anon_sym_COMMA,
    ACTIONS(933), 1,
      anon_sym_SEMI,
    STATE(126), 1,
      sym_block,
    STATE(262), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(913), 2,
      anon_sym_and,
      anon_sym_or,
  [8962] = 6,
    ACTIONS(919), 1,
      aux_sym_integer_value_token1,
    ACTIONS(935), 1,
      anon_sym_RBRACE,
    STATE(302), 1,
      sym_integer_value,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(917), 2,
      sym_from,
      sym_to,
    STATE(242), 2,
      sym_keyframe_block,
      aux_sym_keyframe_block_list_repeat1,
  [8984] = 6,
    ACTIONS(919), 1,
      aux_sym_integer_value_token1,
    ACTIONS(937), 1,
      anon_sym_RBRACE,
    STATE(302), 1,
      sym_integer_value,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(917), 2,
      sym_from,
      sym_to,
    STATE(242), 2,
      sym_keyframe_block,
      aux_sym_keyframe_block_list_repeat1,
  [9006] = 6,
    ACTIONS(939), 1,
      anon_sym_RBRACE,
    ACTIONS(944), 1,
      aux_sym_integer_value_token1,
    STATE(302), 1,
      sym_integer_value,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(941), 2,
      sym_from,
      sym_to,
    STATE(242), 2,
      sym_keyframe_block,
      aux_sym_keyframe_block_list_repeat1,
  [9028] = 7,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(923), 1,
      anon_sym_COMMA,
    ACTIONS(929), 1,
      anon_sym_SLASH,
    ACTIONS(947), 1,
      anon_sym_RBRACK,
    STATE(287), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(925), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9052] = 7,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(923), 1,
      anon_sym_COMMA,
    ACTIONS(929), 1,
      anon_sym_SLASH,
    ACTIONS(949), 1,
      anon_sym_RBRACK,
    STATE(283), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(925), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9076] = 7,
    ACTIONS(651), 1,
      anon_sym_SQUOTE,
    ACTIONS(653), 1,
      anon_sym_DQUOTE,
    ACTIONS(893), 1,
      anon_sym_LPAREN,
    ACTIONS(921), 1,
      sym_identifier,
    STATE(213), 1,
      sym_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(352), 2,
      sym_string_value,
      sym_call_expression,
  [9100] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(951), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9113] = 6,
    ACTIONS(239), 1,
      anon_sym_LBRACE,
    ACTIONS(909), 1,
      anon_sym_COMMA,
    STATE(120), 1,
      sym_block,
    STATE(272), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(913), 2,
      anon_sym_and,
      anon_sym_or,
  [9134] = 6,
    ACTIONS(859), 1,
      anon_sym_LBRACE,
    ACTIONS(909), 1,
      anon_sym_COMMA,
    STATE(111), 1,
      sym_block,
    STATE(273), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(913), 2,
      anon_sym_and,
      anon_sym_or,
  [9155] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(929), 1,
      anon_sym_SLASH,
    ACTIONS(953), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
    ACTIONS(925), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9174] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(955), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9187] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(957), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9200] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(959), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9213] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(471), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9226] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(961), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9239] = 5,
    ACTIONS(651), 1,
      anon_sym_SQUOTE,
    ACTIONS(653), 1,
      anon_sym_DQUOTE,
    ACTIONS(963), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(314), 2,
      sym_string_value,
      sym_call_expression,
  [9257] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(913), 2,
      anon_sym_and,
      anon_sym_or,
    ACTIONS(965), 3,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [9271] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(929), 1,
      anon_sym_SLASH,
    ACTIONS(967), 1,
      anon_sym_RPAREN,
    ACTIONS(925), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9289] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(929), 1,
      anon_sym_SLASH,
    ACTIONS(969), 1,
      anon_sym_SEMI,
    ACTIONS(925), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9307] = 6,
    ACTIONS(859), 1,
      anon_sym_LBRACE,
    ACTIONS(909), 1,
      anon_sym_COMMA,
    ACTIONS(971), 1,
      anon_sym_SEMI,
    STATE(139), 1,
      sym_block,
    STATE(282), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9327] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(929), 1,
      anon_sym_SLASH,
    ACTIONS(973), 1,
      anon_sym_RPAREN,
    ACTIONS(925), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9345] = 5,
    ACTIONS(909), 1,
      anon_sym_COMMA,
    ACTIONS(975), 1,
      anon_sym_SEMI,
    STATE(288), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(913), 2,
      anon_sym_and,
      anon_sym_or,
  [9363] = 6,
    ACTIONS(239), 1,
      anon_sym_LBRACE,
    ACTIONS(909), 1,
      anon_sym_COMMA,
    ACTIONS(977), 1,
      anon_sym_SEMI,
    STATE(133), 1,
      sym_block,
    STATE(282), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9383] = 5,
    ACTIONS(909), 1,
      anon_sym_COMMA,
    ACTIONS(979), 1,
      anon_sym_SEMI,
    STATE(293), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(913), 2,
      anon_sym_and,
      anon_sym_or,
  [9401] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(929), 1,
      anon_sym_SLASH,
    ACTIONS(981), 1,
      anon_sym_RPAREN,
    ACTIONS(925), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9419] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(929), 1,
      anon_sym_SLASH,
    ACTIONS(983), 1,
      anon_sym_RBRACK,
    ACTIONS(925), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9437] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(929), 1,
      anon_sym_SLASH,
    ACTIONS(985), 1,
      anon_sym_RBRACK,
    ACTIONS(925), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9455] = 5,
    ACTIONS(651), 1,
      anon_sym_SQUOTE,
    ACTIONS(653), 1,
      anon_sym_DQUOTE,
    ACTIONS(987), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(344), 2,
      sym_string_value,
      sym_call_expression,
  [9473] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(929), 1,
      anon_sym_SLASH,
    ACTIONS(989), 1,
      anon_sym_SEMI,
    ACTIONS(925), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9491] = 4,
    ACTIONS(991), 1,
      anon_sym_RPAREN,
    STATE(280), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(287), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [9506] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(711), 4,
      anon_sym_RBRACE,
      sym_from,
      sym_to,
      aux_sym_integer_value_token1,
  [9517] = 4,
    ACTIONS(859), 1,
      anon_sym_LBRACE,
    STATE(155), 1,
      sym_block,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(913), 2,
      anon_sym_and,
      anon_sym_or,
  [9532] = 5,
    ACTIONS(239), 1,
      anon_sym_LBRACE,
    ACTIONS(909), 1,
      anon_sym_COMMA,
    STATE(128), 1,
      sym_block,
    STATE(282), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9549] = 5,
    ACTIONS(859), 1,
      anon_sym_LBRACE,
    ACTIONS(909), 1,
      anon_sym_COMMA,
    STATE(140), 1,
      sym_block,
    STATE(282), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9566] = 4,
    ACTIONS(993), 1,
      anon_sym_RPAREN,
    STATE(280), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(287), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [9581] = 3,
    ACTIONS(903), 1,
      anon_sym_COLON,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(471), 3,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9594] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(687), 4,
      anon_sym_RBRACE,
      sym_from,
      sym_to,
      aux_sym_integer_value_token1,
  [9605] = 4,
    ACTIONS(995), 1,
      anon_sym_RPAREN,
    STATE(280), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(287), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [9620] = 4,
    ACTIONS(239), 1,
      anon_sym_LBRACE,
    STATE(124), 1,
      sym_block,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(913), 2,
      anon_sym_and,
      anon_sym_or,
  [9635] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(733), 4,
      anon_sym_RBRACE,
      sym_from,
      sym_to,
      aux_sym_integer_value_token1,
  [9646] = 4,
    ACTIONS(407), 1,
      anon_sym_RPAREN,
    STATE(280), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(997), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [9661] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(1000), 4,
      anon_sym_RBRACE,
      sym_from,
      sym_to,
      aux_sym_integer_value_token1,
  [9672] = 4,
    ACTIONS(1002), 1,
      anon_sym_COMMA,
    STATE(282), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(965), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [9687] = 4,
    ACTIONS(923), 1,
      anon_sym_COMMA,
    ACTIONS(1005), 1,
      anon_sym_RBRACK,
    STATE(289), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9701] = 4,
    ACTIONS(923), 1,
      anon_sym_COMMA,
    ACTIONS(1007), 1,
      anon_sym_RBRACK,
    STATE(289), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9715] = 4,
    ACTIONS(365), 1,
      anon_sym_COMMA,
    ACTIONS(1009), 1,
      anon_sym_RPAREN,
    STATE(294), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9729] = 3,
    ACTIONS(1011), 1,
      anon_sym_RPAREN,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(913), 2,
      anon_sym_and,
      anon_sym_or,
  [9741] = 4,
    ACTIONS(923), 1,
      anon_sym_COMMA,
    ACTIONS(1013), 1,
      anon_sym_RBRACK,
    STATE(289), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9755] = 4,
    ACTIONS(909), 1,
      anon_sym_COMMA,
    ACTIONS(1015), 1,
      anon_sym_SEMI,
    STATE(282), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9769] = 4,
    ACTIONS(953), 1,
      anon_sym_RBRACK,
    ACTIONS(1017), 1,
      anon_sym_COMMA,
    STATE(289), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9783] = 4,
    ACTIONS(891), 1,
      anon_sym_LBRACE,
    ACTIONS(1020), 1,
      anon_sym_COMMA,
    STATE(290), 1,
      aux_sym_selectors_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9797] = 4,
    ACTIONS(365), 1,
      anon_sym_COMMA,
    ACTIONS(1023), 1,
      anon_sym_RPAREN,
    STATE(294), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9811] = 4,
    ACTIONS(863), 1,
      anon_sym_COMMA,
    ACTIONS(1025), 1,
      anon_sym_LBRACE,
    STATE(290), 1,
      aux_sym_selectors_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9825] = 4,
    ACTIONS(909), 1,
      anon_sym_COMMA,
    ACTIONS(1027), 1,
      anon_sym_SEMI,
    STATE(282), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9839] = 4,
    ACTIONS(443), 1,
      anon_sym_RPAREN,
    ACTIONS(1029), 1,
      anon_sym_COMMA,
    STATE(294), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9853] = 3,
    ACTIONS(893), 1,
      anon_sym_LPAREN,
    STATE(213), 1,
      sym_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9864] = 3,
    ACTIONS(1032), 1,
      aux_sym_color_value_token1,
    ACTIONS(1034), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9875] = 3,
    ACTIONS(239), 1,
      anon_sym_LBRACE,
    STATE(118), 1,
      sym_block,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9886] = 3,
    ACTIONS(1036), 1,
      anon_sym_LBRACE,
    STATE(123), 1,
      sym_keyframe_block_list,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9897] = 3,
    ACTIONS(1034), 1,
      sym_identifier,
    ACTIONS(1038), 1,
      aux_sym_color_value_token1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9908] = 3,
    ACTIONS(1040), 1,
      anon_sym_LBRACE,
    STATE(154), 1,
      sym_keyframe_block_list,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9919] = 3,
    ACTIONS(859), 1,
      anon_sym_LBRACE,
    STATE(160), 1,
      sym_block,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9930] = 3,
    ACTIONS(1042), 1,
      anon_sym_LBRACE,
    STATE(281), 1,
      sym_block,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9941] = 3,
    ACTIONS(603), 1,
      anon_sym_LBRACE,
    ACTIONS(1044), 1,
      sym_unit,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9952] = 2,
    ACTIONS(1046), 1,
      aux_sym_string_value_token1,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [9960] = 2,
    ACTIONS(1048), 1,
      anon_sym_RBRACE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9968] = 2,
    ACTIONS(1050), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9976] = 2,
    ACTIONS(1050), 1,
      anon_sym_DQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9984] = 2,
    ACTIONS(1052), 1,
      aux_sym_color_value_token1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9992] = 2,
    ACTIONS(1054), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10000] = 2,
    ACTIONS(1054), 1,
      anon_sym_DQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10008] = 2,
    ACTIONS(1056), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10016] = 2,
    ACTIONS(1058), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10024] = 2,
    ACTIONS(1060), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10032] = 2,
    ACTIONS(1062), 1,
      anon_sym_SEMI,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10040] = 2,
    ACTIONS(69), 1,
      anon_sym_RBRACE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10048] = 2,
    ACTIONS(1056), 1,
      anon_sym_DQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10056] = 2,
    ACTIONS(1064), 1,
      anon_sym_LPAREN2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10064] = 2,
    ACTIONS(1066), 1,
      aux_sym_color_value_token1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10072] = 2,
    ACTIONS(1068), 1,
      anon_sym_RBRACE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10080] = 2,
    ACTIONS(1070), 1,
      anon_sym_SEMI,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10088] = 2,
    ACTIONS(1072), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10096] = 2,
    ACTIONS(1072), 1,
      anon_sym_DQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10104] = 2,
    ACTIONS(1074), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10112] = 2,
    ACTIONS(1074), 1,
      anon_sym_DQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10120] = 2,
    ACTIONS(1076), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10128] = 2,
    ACTIONS(1076), 1,
      anon_sym_DQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10136] = 2,
    ACTIONS(61), 1,
      anon_sym_RBRACE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10144] = 2,
    ACTIONS(1078), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10152] = 2,
    ACTIONS(1080), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10160] = 2,
    ACTIONS(1082), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10168] = 2,
    ACTIONS(1084), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10176] = 2,
    ACTIONS(65), 1,
      anon_sym_RBRACE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10184] = 2,
    ACTIONS(1086), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10192] = 2,
    ACTIONS(1088), 1,
      aux_sym_string_value_token2,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10200] = 2,
    ACTIONS(1090), 1,
      ts_builtin_sym_end,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10208] = 2,
    ACTIONS(1092), 1,
      aux_sym_string_value_token1,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10216] = 2,
    ACTIONS(1094), 1,
      aux_sym_color_value_token1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10224] = 2,
    ACTIONS(1096), 1,
      anon_sym_RBRACE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10232] = 2,
    ACTIONS(1098), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10240] = 2,
    ACTIONS(1100), 1,
      aux_sym_string_value_token2,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10248] = 2,
    ACTIONS(1102), 1,
      aux_sym_string_value_token1,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10256] = 2,
    ACTIONS(1104), 1,
      aux_sym_string_value_token2,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10264] = 2,
    ACTIONS(1106), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10272] = 2,
    ACTIONS(1108), 1,
      anon_sym_SEMI,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10280] = 2,
    ACTIONS(1110), 1,
      aux_sym_string_value_token1,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10288] = 2,
    ACTIONS(1112), 1,
      aux_sym_string_value_token2,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10296] = 2,
    ACTIONS(1114), 1,
      aux_sym_string_value_token1,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10304] = 2,
    ACTIONS(1116), 1,
      aux_sym_string_value_token2,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10312] = 2,
    ACTIONS(1118), 1,
      aux_sym_string_value_token1,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10320] = 2,
    ACTIONS(1120), 1,
      aux_sym_string_value_token2,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10328] = 2,
    ACTIONS(1122), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10336] = 2,
    ACTIONS(1124), 1,
      anon_sym_SEMI,
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
  [SMALL_STATE(20)] = 1503,
  [SMALL_STATE(21)] = 1565,
  [SMALL_STATE(22)] = 1625,
  [SMALL_STATE(23)] = 1687,
  [SMALL_STATE(24)] = 1749,
  [SMALL_STATE(25)] = 1811,
  [SMALL_STATE(26)] = 1873,
  [SMALL_STATE(27)] = 1912,
  [SMALL_STATE(28)] = 1973,
  [SMALL_STATE(29)] = 2034,
  [SMALL_STATE(30)] = 2093,
  [SMALL_STATE(31)] = 2150,
  [SMALL_STATE(32)] = 2207,
  [SMALL_STATE(33)] = 2242,
  [SMALL_STATE(34)] = 2301,
  [SMALL_STATE(35)] = 2360,
  [SMALL_STATE(36)] = 2419,
  [SMALL_STATE(37)] = 2469,
  [SMALL_STATE(38)] = 2521,
  [SMALL_STATE(39)] = 2571,
  [SMALL_STATE(40)] = 2621,
  [SMALL_STATE(41)] = 2667,
  [SMALL_STATE(42)] = 2717,
  [SMALL_STATE(43)] = 2773,
  [SMALL_STATE(44)] = 2823,
  [SMALL_STATE(45)] = 2873,
  [SMALL_STATE(46)] = 2925,
  [SMALL_STATE(47)] = 2975,
  [SMALL_STATE(48)] = 3010,
  [SMALL_STATE(49)] = 3065,
  [SMALL_STATE(50)] = 3100,
  [SMALL_STATE(51)] = 3135,
  [SMALL_STATE(52)] = 3176,
  [SMALL_STATE(53)] = 3231,
  [SMALL_STATE(54)] = 3266,
  [SMALL_STATE(55)] = 3321,
  [SMALL_STATE(56)] = 3376,
  [SMALL_STATE(57)] = 3431,
  [SMALL_STATE(58)] = 3483,
  [SMALL_STATE(59)] = 3535,
  [SMALL_STATE(60)] = 3587,
  [SMALL_STATE(61)] = 3639,
  [SMALL_STATE(62)] = 3691,
  [SMALL_STATE(63)] = 3743,
  [SMALL_STATE(64)] = 3772,
  [SMALL_STATE(65)] = 3801,
  [SMALL_STATE(66)] = 3830,
  [SMALL_STATE(67)] = 3861,
  [SMALL_STATE(68)] = 3890,
  [SMALL_STATE(69)] = 3921,
  [SMALL_STATE(70)] = 3950,
  [SMALL_STATE(71)] = 3981,
  [SMALL_STATE(72)] = 4012,
  [SMALL_STATE(73)] = 4041,
  [SMALL_STATE(74)] = 4070,
  [SMALL_STATE(75)] = 4119,
  [SMALL_STATE(76)] = 4148,
  [SMALL_STATE(77)] = 4177,
  [SMALL_STATE(78)] = 4208,
  [SMALL_STATE(79)] = 4237,
  [SMALL_STATE(80)] = 4286,
  [SMALL_STATE(81)] = 4315,
  [SMALL_STATE(82)] = 4344,
  [SMALL_STATE(83)] = 4373,
  [SMALL_STATE(84)] = 4402,
  [SMALL_STATE(85)] = 4431,
  [SMALL_STATE(86)] = 4460,
  [SMALL_STATE(87)] = 4489,
  [SMALL_STATE(88)] = 4538,
  [SMALL_STATE(89)] = 4571,
  [SMALL_STATE(90)] = 4604,
  [SMALL_STATE(91)] = 4639,
  [SMALL_STATE(92)] = 4688,
  [SMALL_STATE(93)] = 4737,
  [SMALL_STATE(94)] = 4786,
  [SMALL_STATE(95)] = 4815,
  [SMALL_STATE(96)] = 4864,
  [SMALL_STATE(97)] = 4893,
  [SMALL_STATE(98)] = 4922,
  [SMALL_STATE(99)] = 4971,
  [SMALL_STATE(100)] = 5020,
  [SMALL_STATE(101)] = 5069,
  [SMALL_STATE(102)] = 5118,
  [SMALL_STATE(103)] = 5167,
  [SMALL_STATE(104)] = 5196,
  [SMALL_STATE(105)] = 5245,
  [SMALL_STATE(106)] = 5294,
  [SMALL_STATE(107)] = 5343,
  [SMALL_STATE(108)] = 5392,
  [SMALL_STATE(109)] = 5420,
  [SMALL_STATE(110)] = 5448,
  [SMALL_STATE(111)] = 5476,
  [SMALL_STATE(112)] = 5504,
  [SMALL_STATE(113)] = 5532,
  [SMALL_STATE(114)] = 5560,
  [SMALL_STATE(115)] = 5588,
  [SMALL_STATE(116)] = 5616,
  [SMALL_STATE(117)] = 5644,
  [SMALL_STATE(118)] = 5672,
  [SMALL_STATE(119)] = 5700,
  [SMALL_STATE(120)] = 5728,
  [SMALL_STATE(121)] = 5756,
  [SMALL_STATE(122)] = 5784,
  [SMALL_STATE(123)] = 5812,
  [SMALL_STATE(124)] = 5840,
  [SMALL_STATE(125)] = 5868,
  [SMALL_STATE(126)] = 5896,
  [SMALL_STATE(127)] = 5924,
  [SMALL_STATE(128)] = 5952,
  [SMALL_STATE(129)] = 5980,
  [SMALL_STATE(130)] = 6008,
  [SMALL_STATE(131)] = 6036,
  [SMALL_STATE(132)] = 6064,
  [SMALL_STATE(133)] = 6092,
  [SMALL_STATE(134)] = 6120,
  [SMALL_STATE(135)] = 6148,
  [SMALL_STATE(136)] = 6176,
  [SMALL_STATE(137)] = 6204,
  [SMALL_STATE(138)] = 6232,
  [SMALL_STATE(139)] = 6260,
  [SMALL_STATE(140)] = 6288,
  [SMALL_STATE(141)] = 6316,
  [SMALL_STATE(142)] = 6344,
  [SMALL_STATE(143)] = 6374,
  [SMALL_STATE(144)] = 6404,
  [SMALL_STATE(145)] = 6434,
  [SMALL_STATE(146)] = 6464,
  [SMALL_STATE(147)] = 6492,
  [SMALL_STATE(148)] = 6522,
  [SMALL_STATE(149)] = 6552,
  [SMALL_STATE(150)] = 6582,
  [SMALL_STATE(151)] = 6612,
  [SMALL_STATE(152)] = 6642,
  [SMALL_STATE(153)] = 6672,
  [SMALL_STATE(154)] = 6702,
  [SMALL_STATE(155)] = 6730,
  [SMALL_STATE(156)] = 6758,
  [SMALL_STATE(157)] = 6786,
  [SMALL_STATE(158)] = 6814,
  [SMALL_STATE(159)] = 6842,
  [SMALL_STATE(160)] = 6870,
  [SMALL_STATE(161)] = 6898,
  [SMALL_STATE(162)] = 6926,
  [SMALL_STATE(163)] = 6954,
  [SMALL_STATE(164)] = 6982,
  [SMALL_STATE(165)] = 7010,
  [SMALL_STATE(166)] = 7043,
  [SMALL_STATE(167)] = 7072,
  [SMALL_STATE(168)] = 7102,
  [SMALL_STATE(169)] = 7132,
  [SMALL_STATE(170)] = 7164,
  [SMALL_STATE(171)] = 7194,
  [SMALL_STATE(172)] = 7224,
  [SMALL_STATE(173)] = 7263,
  [SMALL_STATE(174)] = 7302,
  [SMALL_STATE(175)] = 7330,
  [SMALL_STATE(176)] = 7360,
  [SMALL_STATE(177)] = 7386,
  [SMALL_STATE(178)] = 7416,
  [SMALL_STATE(179)] = 7442,
  [SMALL_STATE(180)] = 7468,
  [SMALL_STATE(181)] = 7503,
  [SMALL_STATE(182)] = 7530,
  [SMALL_STATE(183)] = 7557,
  [SMALL_STATE(184)] = 7584,
  [SMALL_STATE(185)] = 7611,
  [SMALL_STATE(186)] = 7655,
  [SMALL_STATE(187)] = 7677,
  [SMALL_STATE(188)] = 7699,
  [SMALL_STATE(189)] = 7721,
  [SMALL_STATE(190)] = 7765,
  [SMALL_STATE(191)] = 7809,
  [SMALL_STATE(192)] = 7848,
  [SMALL_STATE(193)] = 7875,
  [SMALL_STATE(194)] = 7914,
  [SMALL_STATE(195)] = 7940,
  [SMALL_STATE(196)] = 7964,
  [SMALL_STATE(197)] = 7990,
  [SMALL_STATE(198)] = 8014,
  [SMALL_STATE(199)] = 8040,
  [SMALL_STATE(200)] = 8078,
  [SMALL_STATE(201)] = 8100,
  [SMALL_STATE(202)] = 8126,
  [SMALL_STATE(203)] = 8152,
  [SMALL_STATE(204)] = 8178,
  [SMALL_STATE(205)] = 8204,
  [SMALL_STATE(206)] = 8230,
  [SMALL_STATE(207)] = 8251,
  [SMALL_STATE(208)] = 8272,
  [SMALL_STATE(209)] = 8293,
  [SMALL_STATE(210)] = 8314,
  [SMALL_STATE(211)] = 8335,
  [SMALL_STATE(212)] = 8356,
  [SMALL_STATE(213)] = 8377,
  [SMALL_STATE(214)] = 8398,
  [SMALL_STATE(215)] = 8419,
  [SMALL_STATE(216)] = 8440,
  [SMALL_STATE(217)] = 8461,
  [SMALL_STATE(218)] = 8486,
  [SMALL_STATE(219)] = 8521,
  [SMALL_STATE(220)] = 8550,
  [SMALL_STATE(221)] = 8572,
  [SMALL_STATE(222)] = 8594,
  [SMALL_STATE(223)] = 8613,
  [SMALL_STATE(224)] = 8632,
  [SMALL_STATE(225)] = 8651,
  [SMALL_STATE(226)] = 8670,
  [SMALL_STATE(227)] = 8689,
  [SMALL_STATE(228)] = 8708,
  [SMALL_STATE(229)] = 8727,
  [SMALL_STATE(230)] = 8746,
  [SMALL_STATE(231)] = 8765,
  [SMALL_STATE(232)] = 8784,
  [SMALL_STATE(233)] = 8803,
  [SMALL_STATE(234)] = 8822,
  [SMALL_STATE(235)] = 8846,
  [SMALL_STATE(236)] = 8868,
  [SMALL_STATE(237)] = 8892,
  [SMALL_STATE(238)] = 8916,
  [SMALL_STATE(239)] = 8938,
  [SMALL_STATE(240)] = 8962,
  [SMALL_STATE(241)] = 8984,
  [SMALL_STATE(242)] = 9006,
  [SMALL_STATE(243)] = 9028,
  [SMALL_STATE(244)] = 9052,
  [SMALL_STATE(245)] = 9076,
  [SMALL_STATE(246)] = 9100,
  [SMALL_STATE(247)] = 9113,
  [SMALL_STATE(248)] = 9134,
  [SMALL_STATE(249)] = 9155,
  [SMALL_STATE(250)] = 9174,
  [SMALL_STATE(251)] = 9187,
  [SMALL_STATE(252)] = 9200,
  [SMALL_STATE(253)] = 9213,
  [SMALL_STATE(254)] = 9226,
  [SMALL_STATE(255)] = 9239,
  [SMALL_STATE(256)] = 9257,
  [SMALL_STATE(257)] = 9271,
  [SMALL_STATE(258)] = 9289,
  [SMALL_STATE(259)] = 9307,
  [SMALL_STATE(260)] = 9327,
  [SMALL_STATE(261)] = 9345,
  [SMALL_STATE(262)] = 9363,
  [SMALL_STATE(263)] = 9383,
  [SMALL_STATE(264)] = 9401,
  [SMALL_STATE(265)] = 9419,
  [SMALL_STATE(266)] = 9437,
  [SMALL_STATE(267)] = 9455,
  [SMALL_STATE(268)] = 9473,
  [SMALL_STATE(269)] = 9491,
  [SMALL_STATE(270)] = 9506,
  [SMALL_STATE(271)] = 9517,
  [SMALL_STATE(272)] = 9532,
  [SMALL_STATE(273)] = 9549,
  [SMALL_STATE(274)] = 9566,
  [SMALL_STATE(275)] = 9581,
  [SMALL_STATE(276)] = 9594,
  [SMALL_STATE(277)] = 9605,
  [SMALL_STATE(278)] = 9620,
  [SMALL_STATE(279)] = 9635,
  [SMALL_STATE(280)] = 9646,
  [SMALL_STATE(281)] = 9661,
  [SMALL_STATE(282)] = 9672,
  [SMALL_STATE(283)] = 9687,
  [SMALL_STATE(284)] = 9701,
  [SMALL_STATE(285)] = 9715,
  [SMALL_STATE(286)] = 9729,
  [SMALL_STATE(287)] = 9741,
  [SMALL_STATE(288)] = 9755,
  [SMALL_STATE(289)] = 9769,
  [SMALL_STATE(290)] = 9783,
  [SMALL_STATE(291)] = 9797,
  [SMALL_STATE(292)] = 9811,
  [SMALL_STATE(293)] = 9825,
  [SMALL_STATE(294)] = 9839,
  [SMALL_STATE(295)] = 9853,
  [SMALL_STATE(296)] = 9864,
  [SMALL_STATE(297)] = 9875,
  [SMALL_STATE(298)] = 9886,
  [SMALL_STATE(299)] = 9897,
  [SMALL_STATE(300)] = 9908,
  [SMALL_STATE(301)] = 9919,
  [SMALL_STATE(302)] = 9930,
  [SMALL_STATE(303)] = 9941,
  [SMALL_STATE(304)] = 9952,
  [SMALL_STATE(305)] = 9960,
  [SMALL_STATE(306)] = 9968,
  [SMALL_STATE(307)] = 9976,
  [SMALL_STATE(308)] = 9984,
  [SMALL_STATE(309)] = 9992,
  [SMALL_STATE(310)] = 10000,
  [SMALL_STATE(311)] = 10008,
  [SMALL_STATE(312)] = 10016,
  [SMALL_STATE(313)] = 10024,
  [SMALL_STATE(314)] = 10032,
  [SMALL_STATE(315)] = 10040,
  [SMALL_STATE(316)] = 10048,
  [SMALL_STATE(317)] = 10056,
  [SMALL_STATE(318)] = 10064,
  [SMALL_STATE(319)] = 10072,
  [SMALL_STATE(320)] = 10080,
  [SMALL_STATE(321)] = 10088,
  [SMALL_STATE(322)] = 10096,
  [SMALL_STATE(323)] = 10104,
  [SMALL_STATE(324)] = 10112,
  [SMALL_STATE(325)] = 10120,
  [SMALL_STATE(326)] = 10128,
  [SMALL_STATE(327)] = 10136,
  [SMALL_STATE(328)] = 10144,
  [SMALL_STATE(329)] = 10152,
  [SMALL_STATE(330)] = 10160,
  [SMALL_STATE(331)] = 10168,
  [SMALL_STATE(332)] = 10176,
  [SMALL_STATE(333)] = 10184,
  [SMALL_STATE(334)] = 10192,
  [SMALL_STATE(335)] = 10200,
  [SMALL_STATE(336)] = 10208,
  [SMALL_STATE(337)] = 10216,
  [SMALL_STATE(338)] = 10224,
  [SMALL_STATE(339)] = 10232,
  [SMALL_STATE(340)] = 10240,
  [SMALL_STATE(341)] = 10248,
  [SMALL_STATE(342)] = 10256,
  [SMALL_STATE(343)] = 10264,
  [SMALL_STATE(344)] = 10272,
  [SMALL_STATE(345)] = 10280,
  [SMALL_STATE(346)] = 10288,
  [SMALL_STATE(347)] = 10296,
  [SMALL_STATE(348)] = 10304,
  [SMALL_STATE(349)] = 10312,
  [SMALL_STATE(350)] = 10320,
  [SMALL_STATE(351)] = 10328,
  [SMALL_STATE(352)] = 10336,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stylesheet, 0, 0, 0),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(196),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(255),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(333),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(194),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(312),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(329),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(343),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(336),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(340),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(180),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(330),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(204),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(267),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(331),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(205),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(279),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(270),
  [71] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(99),
  [74] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(204),
  [77] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(100),
  [80] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(267),
  [83] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(331),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0),
  [88] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(205),
  [91] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(185),
  [94] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [97] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(312),
  [100] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(329),
  [103] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(343),
  [106] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(37),
  [109] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(336),
  [112] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(340),
  [115] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(187),
  [118] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(16),
  [121] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(330),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stylesheet, 1, 0, 0),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0),
  [128] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(104),
  [131] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(196),
  [134] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(79),
  [137] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(255),
  [140] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(333),
  [143] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(194),
  [146] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(185),
  [149] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [152] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(312),
  [155] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(329),
  [158] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(343),
  [161] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(37),
  [164] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(336),
  [167] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(340),
  [170] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(188),
  [173] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(180),
  [176] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(330),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [181] = {.entry = {.count = 1, .reusable = false}}, SHIFT(312),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(299),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(347),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(348),
  [197] = {.entry = {.count = 1, .reusable = false}}, SHIFT(165),
  [199] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [201] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(296),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(237),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(349),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(350),
  [225] = {.entry = {.count = 1, .reusable = false}}, SHIFT(237),
  [227] = {.entry = {.count = 1, .reusable = false}}, SHIFT(221),
  [229] = {.entry = {.count = 1, .reusable = false}}, SHIFT(220),
  [231] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(243),
  [235] = {.entry = {.count = 1, .reusable = false}}, SHIFT(243),
  [237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(308),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [247] = {.entry = {.count = 1, .reusable = false}}, SHIFT(203),
  [249] = {.entry = {.count = 1, .reusable = false}}, SHIFT(317),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(345),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(346),
  [255] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(337),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(260),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(341),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(342),
  [269] = {.entry = {.count = 1, .reusable = false}}, SHIFT(260),
  [271] = {.entry = {.count = 1, .reusable = false}}, SHIFT(219),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(264),
  [275] = {.entry = {.count = 1, .reusable = false}}, SHIFT(264),
  [277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__selector, 1, 0, 1),
  [279] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__value, 1, 0, 3),
  [281] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__selector, 1, 0, 1),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [285] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__value, 1, 0, 3),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [291] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [293] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(60),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0),
  [298] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(308),
  [301] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(105),
  [304] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(21),
  [307] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(106),
  [310] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(176),
  [313] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(345),
  [316] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(346),
  [319] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(21),
  [322] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(88),
  [325] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(89),
  [328] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(169),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [335] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_last_declaration, 3, 0, 14),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [339] = {.entry = {.count = 1, .reusable = false}}, SHIFT(176),
  [341] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [343] = {.entry = {.count = 1, .reusable = false}}, SHIFT(169),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(231),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [349] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_last_declaration, 4, 0, 14),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [353] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [357] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__selector, 1, 0, 0),
  [359] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__value, 1, 0, 0),
  [361] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__selector, 1, 0, 0),
  [363] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__value, 1, 0, 0),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [367] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [371] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [373] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [375] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0),
  [377] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(308),
  [380] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(105),
  [383] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(165),
  [386] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(106),
  [389] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(345),
  [392] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(346),
  [395] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(165),
  [398] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(88),
  [401] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(89),
  [404] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(90),
  [407] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_arguments_repeat1, 2, 0, 0),
  [409] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_value, 3, 0, 0),
  [411] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_value, 3, 0, 0),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [417] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [419] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [421] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [425] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [427] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [429] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [431] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [435] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [439] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [441] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [443] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pseudo_class_arguments_repeat1, 2, 0, 0),
  [445] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [447] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [449] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [451] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [453] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_selector, 2, 0, 2),
  [455] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_selector, 2, 0, 2),
  [457] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [459] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [461] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_selector, 3, 0, 10),
  [463] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_selector, 3, 0, 10),
  [465] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_selector, 3, 0, 11),
  [467] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_selector, 3, 0, 11),
  [469] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [471] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__query, 1, 0, 4),
  [473] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__query, 1, 0, 4),
  [475] = {.entry = {.count = 1, .reusable = true}}, SHIFT(250),
  [477] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_selector, 2, 0, 5),
  [479] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_selector, 2, 0, 5),
  [481] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [483] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [485] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [487] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [489] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [491] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [493] = {.entry = {.count = 1, .reusable = false}}, SHIFT(178),
  [495] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [497] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [499] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [501] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [503] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_selector, 4, 0, 15),
  [505] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute_selector, 4, 0, 15),
  [507] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_arguments, 2, 0, 0),
  [509] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_arguments, 2, 0, 0),
  [511] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_selector, 2, 0, 2),
  [513] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_class_selector, 2, 0, 2),
  [515] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_descendant_selector, 3, 0, 0),
  [517] = {.entry = {.count = 1, .reusable = true}}, SHIFT(313),
  [519] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_descendant_selector, 3, 0, 0),
  [521] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_id_selector, 3, 0, 12),
  [523] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_id_selector, 3, 0, 12),
  [525] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_child_selector, 3, 0, 0),
  [527] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_child_selector, 3, 0, 0),
  [529] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_id_selector, 2, 0, 6),
  [531] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_id_selector, 2, 0, 6),
  [533] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sibling_selector, 3, 0, 0),
  [535] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_sibling_selector, 3, 0, 0),
  [537] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_adjacent_sibling_selector, 3, 0, 0),
  [539] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_adjacent_sibling_selector, 3, 0, 0),
  [541] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_selector, 4, 0, 10),
  [543] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_selector, 4, 0, 10),
  [545] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_selector, 4, 0, 11),
  [547] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_selector, 4, 0, 11),
  [549] = {.entry = {.count = 1, .reusable = true}}, SHIFT(266),
  [551] = {.entry = {.count = 1, .reusable = false}}, SHIFT(266),
  [553] = {.entry = {.count = 1, .reusable = false}}, SHIFT(217),
  [555] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_universal_selector, 1, 0, 0),
  [557] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_universal_selector, 1, 0, 0),
  [559] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_selector, 3, 0, 2),
  [561] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_selector, 3, 0, 2),
  [563] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace_selector, 3, 0, 0),
  [565] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_namespace_selector, 3, 0, 0),
  [567] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_arguments, 3, 0, 0),
  [569] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_arguments, 3, 0, 0),
  [571] = {.entry = {.count = 1, .reusable = true}}, SHIFT(268),
  [573] = {.entry = {.count = 1, .reusable = false}}, SHIFT(268),
  [575] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_arguments, 2, 0, 0),
  [577] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_arguments, 2, 0, 0),
  [579] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_arguments, 3, 0, 0),
  [581] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_arguments, 3, 0, 0),
  [583] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_selector, 5, 0, 9),
  [585] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute_selector, 5, 0, 9),
  [587] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_arguments, 4, 0, 0),
  [589] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_arguments, 4, 0, 0),
  [591] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_arguments, 4, 0, 0),
  [593] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_arguments, 4, 0, 0),
  [595] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_selector, 6, 0, 15),
  [597] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute_selector, 6, 0, 15),
  [599] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [601] = {.entry = {.count = 1, .reusable = false}}, SHIFT(223),
  [603] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_value, 1, 0, 0),
  [605] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_integer_value, 1, 0, 0),
  [607] = {.entry = {.count = 1, .reusable = false}}, SHIFT(143),
  [609] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_value, 1, 0, 0),
  [611] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_float_value, 1, 0, 0),
  [613] = {.entry = {.count = 1, .reusable = false}}, SHIFT(144),
  [615] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [617] = {.entry = {.count = 1, .reusable = false}}, SHIFT(166),
  [619] = {.entry = {.count = 1, .reusable = true}}, SHIFT(244),
  [621] = {.entry = {.count = 1, .reusable = false}}, SHIFT(244),
  [623] = {.entry = {.count = 1, .reusable = true}}, SHIFT(257),
  [625] = {.entry = {.count = 1, .reusable = false}}, SHIFT(257),
  [627] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_selector, 3, 0, 5),
  [629] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_selector, 3, 0, 5),
  [631] = {.entry = {.count = 1, .reusable = true}}, SHIFT(265),
  [633] = {.entry = {.count = 1, .reusable = false}}, SHIFT(265),
  [635] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_selector, 3, 0, 9),
  [637] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute_selector, 3, 0, 9),
  [639] = {.entry = {.count = 1, .reusable = true}}, SHIFT(249),
  [641] = {.entry = {.count = 1, .reusable = false}}, SHIFT(249),
  [643] = {.entry = {.count = 1, .reusable = true}}, SHIFT(318),
  [645] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [647] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [649] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [651] = {.entry = {.count = 1, .reusable = true}}, SHIFT(304),
  [653] = {.entry = {.count = 1, .reusable = true}}, SHIFT(334),
  [655] = {.entry = {.count = 1, .reusable = false}}, SHIFT(172),
  [657] = {.entry = {.count = 1, .reusable = false}}, SHIFT(195),
  [659] = {.entry = {.count = 1, .reusable = false}}, SHIFT(197),
  [661] = {.entry = {.count = 1, .reusable = false}}, SHIFT(192),
  [663] = {.entry = {.count = 1, .reusable = true}}, SHIFT(258),
  [665] = {.entry = {.count = 1, .reusable = false}}, SHIFT(258),
  [667] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_selector, 3, 0, 10),
  [669] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_class_selector, 3, 0, 10),
  [671] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [673] = {.entry = {.count = 1, .reusable = false}}, SHIFT(173),
  [675] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [677] = {.entry = {.count = 1, .reusable = false}}, SHIFT(212),
  [679] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_at_rule, 2, 0, 0),
  [681] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_at_rule, 2, 0, 0),
  [683] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_postcss_statement, 3, 0, 0),
  [685] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_postcss_statement, 3, 0, 0),
  [687] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 4, 0, 0),
  [689] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 4, 0, 0),
  [691] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_media_statement, 3, 0, 0),
  [693] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_media_statement, 3, 0, 0),
  [695] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_charset_statement, 3, 0, 0),
  [697] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_charset_statement, 3, 0, 0),
  [699] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_at_rule, 3, 0, 0),
  [701] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_at_rule, 3, 0, 0),
  [703] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration, 6, 0, 14),
  [705] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_declaration, 6, 0, 14),
  [707] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace_statement, 3, 0, 0),
  [709] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_namespace_statement, 3, 0, 0),
  [711] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3, 0, 0),
  [713] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3, 0, 0),
  [715] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rule_set, 2, 0, 0),
  [717] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rule_set, 2, 0, 0),
  [719] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import_statement, 3, 0, 0),
  [721] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 3, 0, 0),
  [723] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_keyframes_statement, 3, 0, 8),
  [725] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_keyframes_statement, 3, 0, 8),
  [727] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_supports_statement, 3, 0, 0),
  [729] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_supports_statement, 3, 0, 0),
  [731] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2, 0, 0),
  [733] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2, 0, 0),
  [735] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import_statement, 4, 0, 0),
  [737] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 4, 0, 0),
  [739] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_media_statement, 4, 0, 0),
  [741] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_media_statement, 4, 0, 0),
  [743] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_namespace_statement, 4, 0, 13),
  [745] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace_statement, 4, 0, 13),
  [747] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_keyframe_block_list, 2, 0, 0),
  [749] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_keyframe_block_list, 2, 0, 0),
  [751] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_declaration, 4, 0, 14),
  [753] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration, 4, 0, 14),
  [755] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_at_rule, 4, 0, 0),
  [757] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_at_rule, 4, 0, 0),
  [759] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import_statement, 5, 0, 0),
  [761] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 5, 0, 0),
  [763] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_keyframe_block_list, 3, 0, 0),
  [765] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_keyframe_block_list, 3, 0, 0),
  [767] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_declaration, 5, 0, 14),
  [769] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration, 5, 0, 14),
  [771] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_value, 2, 0, 0),
  [773] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_color_value, 2, 0, 0),
  [775] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_value, 2, 0, 0),
  [777] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_integer_value, 2, 0, 0),
  [779] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_value, 2, 0, 0),
  [781] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_float_value, 2, 0, 0),
  [783] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call_expression, 2, 0, 7),
  [785] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_call_expression, 2, 0, 7),
  [787] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_grid_value, 3, 0, 0),
  [789] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_grid_value, 3, 0, 0),
  [791] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthesized_value, 3, 0, 0),
  [793] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parenthesized_value, 3, 0, 0),
  [795] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arguments, 2, 0, 0),
  [797] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arguments, 2, 0, 0),
  [799] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_grid_value, 4, 0, 0),
  [801] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_grid_value, 4, 0, 0),
  [803] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arguments, 3, 0, 0),
  [805] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arguments, 3, 0, 0),
  [807] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arguments, 4, 0, 0),
  [809] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arguments, 4, 0, 0),
  [811] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 1, 0, 0),
  [813] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [815] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [817] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_postcss_statement_repeat1, 1, 0, 0),
  [819] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3, 0, 0),
  [821] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3, 0, 0),
  [823] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [825] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [827] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__usable_value, 1, 0, 3),
  [829] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__usable_value, 1, 0, 3),
  [831] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [833] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [835] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [837] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [839] = {.entry = {.count = 1, .reusable = false}}, SHIFT(253),
  [841] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [843] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__usable_value, 1, 0, 0),
  [845] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [847] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_last_declaration, 5, 0, 14),
  [849] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__usable_value, 1, 0, 0),
  [851] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_slash_separator, 1, 0, 0),
  [853] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_slash_separator, 1, 0, 0),
  [855] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0),
  [857] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [859] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [861] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [863] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [865] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_selectors, 1, 0, 0),
  [867] = {.entry = {.count = 1, .reusable = true}}, SHIFT(339),
  [869] = {.entry = {.count = 1, .reusable = true}}, SHIFT(351),
  [871] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [873] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [875] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [877] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [879] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [881] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [883] = {.entry = {.count = 1, .reusable = true}}, SHIFT(328),
  [885] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [887] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [889] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [891] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_selectors_repeat1, 2, 0, 0),
  [893] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [895] = {.entry = {.count = 1, .reusable = false}}, SHIFT(200),
  [897] = {.entry = {.count = 1, .reusable = false}}, SHIFT(208),
  [899] = {.entry = {.count = 1, .reusable = false}}, SHIFT(275),
  [901] = {.entry = {.count = 1, .reusable = true}}, SHIFT(254),
  [903] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [905] = {.entry = {.count = 1, .reusable = true}}, SHIFT(230),
  [907] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [909] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [911] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [913] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [915] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [917] = {.entry = {.count = 1, .reusable = true}}, SHIFT(302),
  [919] = {.entry = {.count = 1, .reusable = true}}, SHIFT(303),
  [921] = {.entry = {.count = 1, .reusable = true}}, SHIFT(295),
  [923] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [925] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [927] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [929] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [931] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [933] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [935] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [937] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [939] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_keyframe_block_list_repeat1, 2, 0, 0),
  [941] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_keyframe_block_list_repeat1, 2, 0, 0), SHIFT_REPEAT(302),
  [944] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_keyframe_block_list_repeat1, 2, 0, 0), SHIFT_REPEAT(303),
  [947] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [949] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [951] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthesized_query, 3, 0, 0),
  [953] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_grid_value_repeat1, 2, 0, 0),
  [955] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_feature_query, 5, 0, 16),
  [957] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_query, 2, 0, 0),
  [959] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_query, 3, 0, 0),
  [961] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_selector_query, 4, 0, 0),
  [963] = {.entry = {.count = 1, .reusable = true}}, SHIFT(236),
  [965] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_import_statement_repeat1, 2, 0, 0),
  [967] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [969] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [971] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [973] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [975] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [977] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [979] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [981] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [983] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [985] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [987] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [989] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [991] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [993] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [995] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [997] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_arguments_repeat1, 2, 0, 0), SHIFT_REPEAT(59),
  [1000] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_keyframe_block, 2, 0, 0),
  [1002] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_import_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(201),
  [1005] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [1007] = {.entry = {.count = 1, .reusable = true}}, SHIFT(233),
  [1009] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [1011] = {.entry = {.count = 1, .reusable = true}}, SHIFT(246),
  [1013] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [1015] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [1017] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_grid_value_repeat1, 2, 0, 0), SHIFT_REPEAT(98),
  [1020] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_selectors_repeat1, 2, 0, 0), SHIFT_REPEAT(44),
  [1023] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [1025] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_selectors, 2, 0, 0),
  [1027] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [1029] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pseudo_class_arguments_repeat1, 2, 0, 0), SHIFT_REPEAT(13),
  [1032] = {.entry = {.count = 1, .reusable = false}}, SHIFT(228),
  [1034] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [1036] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [1038] = {.entry = {.count = 1, .reusable = false}}, SHIFT(142),
  [1040] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [1042] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [1044] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [1046] = {.entry = {.count = 1, .reusable = false}}, SHIFT(306),
  [1048] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [1050] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [1052] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [1054] = {.entry = {.count = 1, .reusable = true}}, SHIFT(232),
  [1056] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [1058] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [1060] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [1062] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [1064] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [1066] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [1068] = {.entry = {.count = 1, .reusable = true}}, SHIFT(276),
  [1070] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [1072] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [1074] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [1076] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [1078] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [1080] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [1082] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [1084] = {.entry = {.count = 1, .reusable = true}}, SHIFT(298),
  [1086] = {.entry = {.count = 1, .reusable = true}}, SHIFT(300),
  [1088] = {.entry = {.count = 1, .reusable = false}}, SHIFT(307),
  [1090] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [1092] = {.entry = {.count = 1, .reusable = false}}, SHIFT(311),
  [1094] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [1096] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [1098] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [1100] = {.entry = {.count = 1, .reusable = false}}, SHIFT(316),
  [1102] = {.entry = {.count = 1, .reusable = false}}, SHIFT(309),
  [1104] = {.entry = {.count = 1, .reusable = false}}, SHIFT(310),
  [1106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [1108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [1110] = {.entry = {.count = 1, .reusable = false}}, SHIFT(321),
  [1112] = {.entry = {.count = 1, .reusable = false}}, SHIFT(322),
  [1114] = {.entry = {.count = 1, .reusable = false}}, SHIFT(323),
  [1116] = {.entry = {.count = 1, .reusable = false}}, SHIFT(324),
  [1118] = {.entry = {.count = 1, .reusable = false}}, SHIFT(325),
  [1120] = {.entry = {.count = 1, .reusable = false}}, SHIFT(326),
  [1122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [1124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
};

enum ts_external_scanner_symbol_identifiers {
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

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_ncss_external_scanner_create(void);
void tree_sitter_ncss_external_scanner_destroy(void *);
bool tree_sitter_ncss_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_ncss_external_scanner_serialize(void *, char *);
void tree_sitter_ncss_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_ncss(void) {
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
