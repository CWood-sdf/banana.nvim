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
#define STATE_COUNT 126
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 78
#define ALIAS_COUNT 0
#define TOKEN_COUNT 52
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 2

enum ts_symbol_identifiers {
  anon_sym_a = 1,
  anon_sym_nml = 2,
  anon_sym_title = 3,
  anon_sym_pre = 4,
  anon_sym_head = 5,
  anon_sym_body = 6,
  anon_sym_div = 7,
  anon_sym_p = 8,
  anon_sym_span = 9,
  anon_sym_ol = 10,
  anon_sym_ul = 11,
  anon_sym_template = 12,
  anon_sym_li = 13,
  anon_sym_slot = 14,
  aux_sym__start_tag_name_token1 = 15,
  aux_sym__start_tag_name_token2 = 16,
  aux_sym__start_tag_name_token3 = 17,
  sym_raw_text = 18,
  anon_sym_script = 19,
  anon_sym_style = 20,
  sym_erroneous_end_tag_name = 21,
  anon_sym_LT_BANG_DASH_DASH = 22,
  aux_sym_comment_token1 = 23,
  aux_sym_comment_token2 = 24,
  aux_sym_comment_token3 = 25,
  anon_sym_DASH_DASH_GT = 26,
  anon_sym_meta = 27,
  anon_sym_br = 28,
  anon_sym_canvas = 29,
  anon_sym_hr = 30,
  anon_sym_bound = 31,
  anon_sym_LT_BANG = 32,
  aux_sym_doctype_token1 = 33,
  anon_sym_GT = 34,
  sym__doctype = 35,
  anon_sym_LT = 36,
  anon_sym_LF = 37,
  anon_sym_CR = 38,
  anon_sym_LT_SLASH = 39,
  anon_sym_SLASH_GT = 40,
  aux_sym_end_tag_token1 = 41,
  anon_sym_EQ = 42,
  sym_attribute_name = 43,
  sym_attribute_value = 44,
  sym_entity = 45,
  sym_substitution = 46,
  anon_sym_SQUOTE = 47,
  aux_sym_quoted_attribute_value_token1 = 48,
  anon_sym_DQUOTE = 49,
  aux_sym_quoted_attribute_value_token2 = 50,
  sym_text = 51,
  sym_source_file = 52,
  sym__start_tag_name = 53,
  sym__script_start_tag_name = 54,
  sym__style_start_tag_name = 55,
  sym__end_tag_name = 56,
  sym_comment = 57,
  sym_self_closing_tags = 58,
  sym_doctype = 59,
  sym__node = 60,
  sym_element = 61,
  sym_script_element = 62,
  sym_style_element = 63,
  sym_start_tag = 64,
  sym_script_start_tag = 65,
  sym_script_end_tag = 66,
  sym_style_start_tag = 67,
  sym_style_end_tag = 68,
  sym_self_closing_tag = 69,
  sym_end_tag = 70,
  sym_erroneous_end_tag = 71,
  sym_attribute = 72,
  sym_quoted_attribute_value = 73,
  aux_sym_source_file_repeat1 = 74,
  aux_sym_comment_repeat1 = 75,
  aux_sym_start_tag_repeat1 = 76,
  aux_sym_script_start_tag_repeat1 = 77,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_a] = "a",
  [anon_sym_nml] = "nml",
  [anon_sym_title] = "title",
  [anon_sym_pre] = "pre",
  [anon_sym_head] = "head",
  [anon_sym_body] = "body",
  [anon_sym_div] = "div",
  [anon_sym_p] = "p",
  [anon_sym_span] = "span",
  [anon_sym_ol] = "ol",
  [anon_sym_ul] = "ul",
  [anon_sym_template] = "template",
  [anon_sym_li] = "li",
  [anon_sym_slot] = "slot",
  [aux_sym__start_tag_name_token1] = "_start_tag_name_token1",
  [aux_sym__start_tag_name_token2] = "_start_tag_name_token2",
  [aux_sym__start_tag_name_token3] = "_start_tag_name_token3",
  [sym_raw_text] = "raw_text",
  [anon_sym_script] = "script",
  [anon_sym_style] = "style",
  [sym_erroneous_end_tag_name] = "erroneous_end_tag_name",
  [anon_sym_LT_BANG_DASH_DASH] = "<!--",
  [aux_sym_comment_token1] = "comment_token1",
  [aux_sym_comment_token2] = "comment_token2",
  [aux_sym_comment_token3] = "comment_token3",
  [anon_sym_DASH_DASH_GT] = "-->",
  [anon_sym_meta] = "meta",
  [anon_sym_br] = "br",
  [anon_sym_canvas] = "canvas",
  [anon_sym_hr] = "hr",
  [anon_sym_bound] = "bound",
  [anon_sym_LT_BANG] = "<!",
  [aux_sym_doctype_token1] = "doctype_token1",
  [anon_sym_GT] = ">",
  [sym__doctype] = "doctype",
  [anon_sym_LT] = "<",
  [anon_sym_LF] = "\n",
  [anon_sym_CR] = "\r",
  [anon_sym_LT_SLASH] = "</",
  [anon_sym_SLASH_GT] = "/>",
  [aux_sym_end_tag_token1] = "end_tag_token1",
  [anon_sym_EQ] = "=",
  [sym_attribute_name] = "attribute_name",
  [sym_attribute_value] = "attribute_value",
  [sym_entity] = "entity",
  [sym_substitution] = "substitution",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_quoted_attribute_value_token1] = "attribute_value",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_quoted_attribute_value_token2] = "attribute_value",
  [sym_text] = "text",
  [sym_source_file] = "source_file",
  [sym__start_tag_name] = "_start_tag_name",
  [sym__script_start_tag_name] = "tag_name",
  [sym__style_start_tag_name] = "tag_name",
  [sym__end_tag_name] = "tag_name",
  [sym_comment] = "comment",
  [sym_self_closing_tags] = "tag_name",
  [sym_doctype] = "doctype",
  [sym__node] = "_node",
  [sym_element] = "element",
  [sym_script_element] = "script_element",
  [sym_style_element] = "style_element",
  [sym_start_tag] = "start_tag",
  [sym_script_start_tag] = "start_tag",
  [sym_script_end_tag] = "script_end_tag",
  [sym_style_start_tag] = "start_tag",
  [sym_style_end_tag] = "style_end_tag",
  [sym_self_closing_tag] = "self_closing_tag",
  [sym_end_tag] = "end_tag",
  [sym_erroneous_end_tag] = "erroneous_end_tag",
  [sym_attribute] = "attribute",
  [sym_quoted_attribute_value] = "quoted_attribute_value",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_comment_repeat1] = "comment_repeat1",
  [aux_sym_start_tag_repeat1] = "start_tag_repeat1",
  [aux_sym_script_start_tag_repeat1] = "script_start_tag_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_a] = anon_sym_a,
  [anon_sym_nml] = anon_sym_nml,
  [anon_sym_title] = anon_sym_title,
  [anon_sym_pre] = anon_sym_pre,
  [anon_sym_head] = anon_sym_head,
  [anon_sym_body] = anon_sym_body,
  [anon_sym_div] = anon_sym_div,
  [anon_sym_p] = anon_sym_p,
  [anon_sym_span] = anon_sym_span,
  [anon_sym_ol] = anon_sym_ol,
  [anon_sym_ul] = anon_sym_ul,
  [anon_sym_template] = anon_sym_template,
  [anon_sym_li] = anon_sym_li,
  [anon_sym_slot] = anon_sym_slot,
  [aux_sym__start_tag_name_token1] = aux_sym__start_tag_name_token1,
  [aux_sym__start_tag_name_token2] = aux_sym__start_tag_name_token2,
  [aux_sym__start_tag_name_token3] = aux_sym__start_tag_name_token3,
  [sym_raw_text] = sym_raw_text,
  [anon_sym_script] = anon_sym_script,
  [anon_sym_style] = anon_sym_style,
  [sym_erroneous_end_tag_name] = sym_erroneous_end_tag_name,
  [anon_sym_LT_BANG_DASH_DASH] = anon_sym_LT_BANG_DASH_DASH,
  [aux_sym_comment_token1] = aux_sym_comment_token1,
  [aux_sym_comment_token2] = aux_sym_comment_token2,
  [aux_sym_comment_token3] = aux_sym_comment_token3,
  [anon_sym_DASH_DASH_GT] = anon_sym_DASH_DASH_GT,
  [anon_sym_meta] = anon_sym_meta,
  [anon_sym_br] = anon_sym_br,
  [anon_sym_canvas] = anon_sym_canvas,
  [anon_sym_hr] = anon_sym_hr,
  [anon_sym_bound] = anon_sym_bound,
  [anon_sym_LT_BANG] = anon_sym_LT_BANG,
  [aux_sym_doctype_token1] = aux_sym_doctype_token1,
  [anon_sym_GT] = anon_sym_GT,
  [sym__doctype] = sym__doctype,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_LF] = anon_sym_LF,
  [anon_sym_CR] = anon_sym_CR,
  [anon_sym_LT_SLASH] = anon_sym_LT_SLASH,
  [anon_sym_SLASH_GT] = anon_sym_SLASH_GT,
  [aux_sym_end_tag_token1] = aux_sym_end_tag_token1,
  [anon_sym_EQ] = anon_sym_EQ,
  [sym_attribute_name] = sym_attribute_name,
  [sym_attribute_value] = sym_attribute_value,
  [sym_entity] = sym_entity,
  [sym_substitution] = sym_substitution,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_quoted_attribute_value_token1] = sym_attribute_value,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_quoted_attribute_value_token2] = sym_attribute_value,
  [sym_text] = sym_text,
  [sym_source_file] = sym_source_file,
  [sym__start_tag_name] = sym__start_tag_name,
  [sym__script_start_tag_name] = sym__script_start_tag_name,
  [sym__style_start_tag_name] = sym__script_start_tag_name,
  [sym__end_tag_name] = sym__script_start_tag_name,
  [sym_comment] = sym_comment,
  [sym_self_closing_tags] = sym__script_start_tag_name,
  [sym_doctype] = sym_doctype,
  [sym__node] = sym__node,
  [sym_element] = sym_element,
  [sym_script_element] = sym_script_element,
  [sym_style_element] = sym_style_element,
  [sym_start_tag] = sym_start_tag,
  [sym_script_start_tag] = sym_start_tag,
  [sym_script_end_tag] = sym_script_end_tag,
  [sym_style_start_tag] = sym_start_tag,
  [sym_style_end_tag] = sym_style_end_tag,
  [sym_self_closing_tag] = sym_self_closing_tag,
  [sym_end_tag] = sym_end_tag,
  [sym_erroneous_end_tag] = sym_erroneous_end_tag,
  [sym_attribute] = sym_attribute,
  [sym_quoted_attribute_value] = sym_quoted_attribute_value,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_comment_repeat1] = aux_sym_comment_repeat1,
  [aux_sym_start_tag_repeat1] = aux_sym_start_tag_repeat1,
  [aux_sym_script_start_tag_repeat1] = aux_sym_script_start_tag_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_a] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_nml] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_title] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pre] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_head] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_body] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_div] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_p] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_span] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ol] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ul] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_template] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_li] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_slot] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__start_tag_name_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__start_tag_name_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__start_tag_name_token3] = {
    .visible = false,
    .named = false,
  },
  [sym_raw_text] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_script] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_style] = {
    .visible = true,
    .named = false,
  },
  [sym_erroneous_end_tag_name] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LT_BANG_DASH_DASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_comment_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_comment_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_comment_token3] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DASH_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_meta] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_br] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_canvas] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_hr] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bound] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_BANG] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_doctype_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [sym__doctype] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_GT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_end_tag_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [sym_attribute_name] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute_value] = {
    .visible = true,
    .named = true,
  },
  [sym_entity] = {
    .visible = true,
    .named = true,
  },
  [sym_substitution] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_quoted_attribute_value_token1] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_quoted_attribute_value_token2] = {
    .visible = true,
    .named = true,
  },
  [sym_text] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__start_tag_name] = {
    .visible = false,
    .named = true,
  },
  [sym__script_start_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym__style_start_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym__end_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_self_closing_tags] = {
    .visible = true,
    .named = true,
  },
  [sym_doctype] = {
    .visible = true,
    .named = true,
  },
  [sym__node] = {
    .visible = false,
    .named = true,
  },
  [sym_element] = {
    .visible = true,
    .named = true,
  },
  [sym_script_element] = {
    .visible = true,
    .named = true,
  },
  [sym_style_element] = {
    .visible = true,
    .named = true,
  },
  [sym_start_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_script_start_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_script_end_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_style_start_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_style_end_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_self_closing_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_end_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_erroneous_end_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_quoted_attribute_value] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_comment_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_start_tag_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_script_start_tag_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [1] = sym__script_start_tag_name,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  sym__start_tag_name, 2,
    sym__start_tag_name,
    sym__script_start_tag_name,
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 2,
  [4] = 4,
  [5] = 4,
  [6] = 6,
  [7] = 7,
  [8] = 6,
  [9] = 9,
  [10] = 10,
  [11] = 9,
  [12] = 10,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 26,
  [30] = 30,
  [31] = 25,
  [32] = 27,
  [33] = 28,
  [34] = 34,
  [35] = 15,
  [36] = 16,
  [37] = 17,
  [38] = 18,
  [39] = 19,
  [40] = 20,
  [41] = 13,
  [42] = 21,
  [43] = 22,
  [44] = 23,
  [45] = 45,
  [46] = 46,
  [47] = 24,
  [48] = 14,
  [49] = 49,
  [50] = 50,
  [51] = 50,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 54,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 56,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 62,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 63,
  [76] = 64,
  [77] = 72,
  [78] = 74,
  [79] = 61,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 81,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 82,
  [94] = 92,
  [95] = 95,
  [96] = 89,
  [97] = 95,
  [98] = 83,
  [99] = 99,
  [100] = 100,
  [101] = 99,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 104,
  [106] = 102,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 110,
  [112] = 71,
  [113] = 108,
  [114] = 100,
  [115] = 115,
  [116] = 116,
  [117] = 103,
  [118] = 116,
  [119] = 109,
  [120] = 120,
  [121] = 120,
  [122] = 122,
  [123] = 122,
  [124] = 124,
  [125] = 125,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(125);
      ADVANCE_MAP(
        '"', 310,
        '%', 303,
        '&', 6,
        '\'', 304,
        '-', 10,
        '/', 67,
        '<', 252,
        '=', 258,
        '>', 250,
        'D', 117,
        'a', 126,
        'b', 100,
        'c', 69,
        'd', 86,
        'h', 84,
        'l', 87,
        'm', 79,
        'n', 96,
        'o', 89,
        'p', 149,
        's', 75,
        't', 85,
        'u', 90,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(253);
      if (lookahead == '\r') ADVANCE(254);
      if (lookahead == '<') ADVANCE(2);
      if (lookahead == '=') ADVANCE(258);
      if (lookahead == '>') ADVANCE(250);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') SKIP(1);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/') ADVANCE(259);
      END_STATE();
    case 2:
      if (lookahead == '!') ADVANCE(11);
      END_STATE();
    case 3:
      if (lookahead == '!') ADVANCE(11);
      if (lookahead == '/') ADVANCE(255);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(310);
      if (lookahead == '\'') ADVANCE(304);
      if (lookahead == '<') ADVANCE(2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (lookahead != 0 &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(260);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(310);
      if (lookahead == '<') ADVANCE(311);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(314);
      if (lookahead != 0) ADVANCE(315);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(120);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(300);
      END_STATE();
    case 7:
      if (lookahead == '%') ADVANCE(303);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '<') ADVANCE(252);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(7);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(316);
      END_STATE();
    case 8:
      if (lookahead == '\'') ADVANCE(304);
      if (lookahead == '<') ADVANCE(305);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(308);
      if (lookahead != 0) ADVANCE(309);
      END_STATE();
    case 9:
      if (lookahead == '-') ADVANCE(10);
      if (lookahead == '<') ADVANCE(229);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(230);
      if (lookahead != 0) ADVANCE(228);
      END_STATE();
    case 10:
      if (lookahead == '-') ADVANCE(68);
      if (lookahead != 0) ADVANCE(231);
      END_STATE();
    case 11:
      if (lookahead == '-') ADVANCE(12);
      END_STATE();
    case 12:
      if (lookahead == '-') ADVANCE(223);
      END_STATE();
    case 13:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'a') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 14:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'a') ADVANCE(20);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 15:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'a') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 16:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'a') ADVANCE(49);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 17:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'a') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 18:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'a') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 19:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'c') ADVANCE(48);
      if (lookahead == 'l') ADVANCE(45);
      if (lookahead == 'p') ADVANCE(17);
      if (lookahead == 't') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 20:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'd') ADVANCE(139);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 21:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'd') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 22:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'd') ADVANCE(57);
      if (lookahead == 'u') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 23:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'e') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 24:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'e') ADVANCE(136);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 25:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'e') ADVANCE(186);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 26:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'e') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 27:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'e') ADVANCE(160);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 28:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'e') ADVANCE(14);
      if (lookahead == 'r') ADVANCE(241);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(169);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 29:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'e') ADVANCE(39);
      if (lookahead == 'i') ADVANCE(54);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 30:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'i') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 31:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'i') ADVANCE(163);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 32:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'i') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 33:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'l') ADVANCE(154);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 34:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'l') ADVANCE(157);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 35:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'l') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 36:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'l') ADVANCE(25);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 37:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'l') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 38:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'l') ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 39:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'm') ADVANCE(47);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 40:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'm') ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 41:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'n') ADVANCE(151);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 42:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'n') ADVANCE(56);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 43:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'n') ADVANCE(21);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 44:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'o') ADVANCE(22);
      if (lookahead == 'r') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 45:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'o') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 46:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'p') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 47:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'p') ADVANCE(38);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 48:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'r') ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 49:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 's') ADVANCE(239);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 50:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 't') ADVANCE(166);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 51:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 't') ADVANCE(184);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 52:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 't') ADVANCE(15);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 53:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 't') ADVANCE(27);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 54:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 't') ADVANCE(37);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 55:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'v') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 56:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'v') ADVANCE(16);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 57:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'y') ADVANCE(142);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 58:
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'y') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 59:
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 60:
      if (lookahead == '-') ADVANCE(177);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(179);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 61:
      if (lookahead == '/') ADVANCE(67);
      if (lookahead == '<') ADVANCE(2);
      if (lookahead == '=') ADVANCE(258);
      if (lookahead == '>') ADVANCE(250);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(61);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'') ADVANCE(259);
      END_STATE();
    case 62:
      ADVANCE_MAP(
        '<', 2,
        'a', 127,
        'b', 44,
        'c', 13,
        'd', 30,
        'h', 28,
        'l', 31,
        'm', 23,
        'n', 40,
        'o', 33,
        'p', 147,
        's', 19,
        't', 29,
        'u', 34,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('e' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(60);
      END_STATE();
    case 63:
      ADVANCE_MAP(
        '<', 187,
        'a', 128,
        'b', 209,
        'd', 198,
        'h', 193,
        'l', 199,
        'n', 207,
        'o', 200,
        'p', 148,
        's', 203,
        't', 197,
        'u', 201,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(63);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('c' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(218);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 64:
      if (lookahead == '<') ADVANCE(187);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(64);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 65:
      if (lookahead == '<') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(181);
      if (lookahead != 0) ADVANCE(182);
      END_STATE();
    case 66:
      if (lookahead == '<') ADVANCE(245);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(248);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(249);
      END_STATE();
    case 67:
      if (lookahead == '>') ADVANCE(256);
      END_STATE();
    case 68:
      if (lookahead == '>') ADVANCE(233);
      if (lookahead != 0) ADVANCE(232);
      END_STATE();
    case 69:
      if (lookahead == 'a') ADVANCE(98);
      END_STATE();
    case 70:
      if (lookahead == 'a') ADVANCE(76);
      END_STATE();
    case 71:
      if (lookahead == 'a') ADVANCE(234);
      END_STATE();
    case 72:
      if (lookahead == 'a') ADVANCE(105);
      END_STATE();
    case 73:
      if (lookahead == 'a') ADVANCE(97);
      END_STATE();
    case 74:
      if (lookahead == 'a') ADVANCE(109);
      END_STATE();
    case 75:
      if (lookahead == 'c') ADVANCE(104);
      if (lookahead == 'l') ADVANCE(101);
      if (lookahead == 'p') ADVANCE(73);
      if (lookahead == 't') ADVANCE(114);
      END_STATE();
    case 76:
      if (lookahead == 'd') ADVANCE(138);
      END_STATE();
    case 77:
      if (lookahead == 'd') ADVANCE(242);
      END_STATE();
    case 78:
      if (lookahead == 'd') ADVANCE(113);
      if (lookahead == 'u') ADVANCE(99);
      END_STATE();
    case 79:
      if (lookahead == 'e') ADVANCE(108);
      END_STATE();
    case 80:
      if (lookahead == 'e') ADVANCE(135);
      END_STATE();
    case 81:
      if (lookahead == 'e') ADVANCE(185);
      END_STATE();
    case 82:
      if (lookahead == 'e') ADVANCE(132);
      END_STATE();
    case 83:
      if (lookahead == 'e') ADVANCE(159);
      END_STATE();
    case 84:
      if (lookahead == 'e') ADVANCE(70);
      if (lookahead == 'r') ADVANCE(240);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(168);
      END_STATE();
    case 85:
      if (lookahead == 'e') ADVANCE(95);
      if (lookahead == 'i') ADVANCE(110);
      END_STATE();
    case 86:
      if (lookahead == 'i') ADVANCE(111);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(115);
      END_STATE();
    case 87:
      if (lookahead == 'i') ADVANCE(162);
      END_STATE();
    case 88:
      if (lookahead == 'i') ADVANCE(102);
      END_STATE();
    case 89:
      if (lookahead == 'l') ADVANCE(153);
      END_STATE();
    case 90:
      if (lookahead == 'l') ADVANCE(156);
      END_STATE();
    case 91:
      if (lookahead == 'l') ADVANCE(129);
      END_STATE();
    case 92:
      if (lookahead == 'l') ADVANCE(81);
      END_STATE();
    case 93:
      if (lookahead == 'l') ADVANCE(82);
      END_STATE();
    case 94:
      if (lookahead == 'l') ADVANCE(74);
      END_STATE();
    case 95:
      if (lookahead == 'm') ADVANCE(103);
      END_STATE();
    case 96:
      if (lookahead == 'm') ADVANCE(91);
      END_STATE();
    case 97:
      if (lookahead == 'n') ADVANCE(150);
      END_STATE();
    case 98:
      if (lookahead == 'n') ADVANCE(112);
      END_STATE();
    case 99:
      if (lookahead == 'n') ADVANCE(77);
      END_STATE();
    case 100:
      if (lookahead == 'o') ADVANCE(78);
      if (lookahead == 'r') ADVANCE(236);
      END_STATE();
    case 101:
      if (lookahead == 'o') ADVANCE(106);
      END_STATE();
    case 102:
      if (lookahead == 'p') ADVANCE(107);
      END_STATE();
    case 103:
      if (lookahead == 'p') ADVANCE(94);
      END_STATE();
    case 104:
      if (lookahead == 'r') ADVANCE(88);
      END_STATE();
    case 105:
      if (lookahead == 's') ADVANCE(238);
      END_STATE();
    case 106:
      if (lookahead == 't') ADVANCE(165);
      END_STATE();
    case 107:
      if (lookahead == 't') ADVANCE(183);
      END_STATE();
    case 108:
      if (lookahead == 't') ADVANCE(71);
      END_STATE();
    case 109:
      if (lookahead == 't') ADVANCE(83);
      END_STATE();
    case 110:
      if (lookahead == 't') ADVANCE(93);
      END_STATE();
    case 111:
      if (lookahead == 'v') ADVANCE(144);
      END_STATE();
    case 112:
      if (lookahead == 'v') ADVANCE(72);
      END_STATE();
    case 113:
      if (lookahead == 'y') ADVANCE(141);
      END_STATE();
    case 114:
      if (lookahead == 'y') ADVANCE(92);
      END_STATE();
    case 115:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(119);
      END_STATE();
    case 116:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(251);
      END_STATE();
    case 117:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(115);
      END_STATE();
    case 118:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(116);
      END_STATE();
    case 119:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(121);
      END_STATE();
    case 120:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(122);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(266);
      END_STATE();
    case 121:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(118);
      END_STATE();
    case 122:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(271);
      END_STATE();
    case 123:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(171);
      END_STATE();
    case 124:
      if (eof) ADVANCE(125);
      if (lookahead == '%') ADVANCE(303);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '<') ADVANCE(252);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(7);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(316);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_a);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_a);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_a);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_nml);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_nml);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_nml);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_title);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_title);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_title);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_pre);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_pre);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_pre);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_head);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_head);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_head);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_body);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_body);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_body);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_div);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_div);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_div);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_p);
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == 'r') ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_p);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'r') ADVANCE(194);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_p);
      if (lookahead == 'r') ADVANCE(80);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_span);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_span);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_span);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_ol);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_ol);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_ol);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_ul);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(anon_sym_ul);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_ul);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(anon_sym_template);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(anon_sym_template);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_template);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_li);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_li);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_li);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_slot);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_slot);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(anon_sym_slot);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token1);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token1);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(171);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(177);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(179);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(172);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(173);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(178);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(180);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '-') ADVANCE(177);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(179);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '-') ADVANCE(178);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(180);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(176);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '+' ||
          lookahead == '-' ||
          lookahead == '/') ADVANCE(179);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(172);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '+' ||
          lookahead == '-' ||
          lookahead == '/') ADVANCE(180);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '+' ||
          lookahead == '-' ||
          ('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(179);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '+' ||
          lookahead == '-' ||
          ('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(180);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym_raw_text);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(181);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(182);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_raw_text);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(182);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(anon_sym_script);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(anon_sym_style);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(anon_sym_style);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '!') ADVANCE(220);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '!' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'a') ADVANCE(208);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'a') ADVANCE(192);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'a') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'd') ADVANCE(216);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'd') ADVANCE(140);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'e') ADVANCE(189);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(170);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'e') ADVANCE(137);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'e') ADVANCE(134);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'e') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'e') ADVANCE(206);
      if (lookahead == 'i') ADVANCE(214);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'i') ADVANCE(215);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'i') ADVANCE(164);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'l') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'l') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'l') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'l') ADVANCE(210);
      if (lookahead == 'p') ADVANCE(188);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'l') ADVANCE(195);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'l') ADVANCE(190);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'm') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'm') ADVANCE(202);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'n') ADVANCE(152);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'o') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'o') ADVANCE(212);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'p') ADVANCE(205);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 't') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 't') ADVANCE(196);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 't') ADVANCE(204);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'v') ADVANCE(146);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'y') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(178);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(180);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(176);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(224);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(219);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(173);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(315);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(309);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(249);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '!') ADVANCE(11);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '<') ADVANCE(229);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(230);
      if (lookahead != 0 &&
          lookahead != '-') ADVANCE(228);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(aux_sym_comment_token2);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(aux_sym_comment_token3);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(anon_sym_DASH_DASH_GT);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(anon_sym_meta);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(anon_sym_meta);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(anon_sym_br);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(anon_sym_br);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(anon_sym_canvas);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(anon_sym_canvas);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(anon_sym_hr);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(anon_sym_hr);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(anon_sym_bound);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(anon_sym_bound);
      if (lookahead == '-') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(anon_sym_LT_BANG);
      if (lookahead == '-') ADVANCE(12);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(aux_sym_doctype_token1);
      if (lookahead == '!') ADVANCE(247);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(249);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(aux_sym_doctype_token1);
      if (lookahead == '-') ADVANCE(227);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(249);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(aux_sym_doctype_token1);
      if (lookahead == '-') ADVANCE(246);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(249);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(aux_sym_doctype_token1);
      if (lookahead == '<') ADVANCE(245);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(248);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(249);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(aux_sym_doctype_token1);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(249);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym__doctype);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '!') ADVANCE(244);
      if (lookahead == '/') ADVANCE(255);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(253);
      if (lookahead == '\r') ADVANCE(254);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(anon_sym_CR);
      if (lookahead == '\n') ADVANCE(253);
      if (lookahead == '\r') ADVANCE(254);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(anon_sym_LT_SLASH);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(anon_sym_SLASH_GT);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(aux_sym_end_tag_token1);
      if (lookahead == 's') ADVANCE(257);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(259);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_attribute_value);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(260);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_entity);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(262);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(263);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(264);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(265);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(262);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(267);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(268);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(269);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(270);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(272);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(273);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(274);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(276);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(277);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(278);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(280);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(281);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(283);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(284);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(285);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(286);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(287);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(288);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(289);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(290);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(291);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(293);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(295);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(296);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(297);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(298);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(299);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_substitution);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_substitution);
      if (lookahead == ';') ADVANCE(301);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(302);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_substitution);
      if (lookahead == '%' ||
          lookahead == ';') ADVANCE(301);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(302);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '!') ADVANCE(307);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(309);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '-') ADVANCE(226);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(309);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '-') ADVANCE(306);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(309);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '<') ADVANCE(305);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(309);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(309);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '!') ADVANCE(313);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '"') ADVANCE(315);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '-') ADVANCE(225);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(315);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '-') ADVANCE(312);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(315);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '<') ADVANCE(311);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(315);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(315);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(sym_text);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(316);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '&' &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(316);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 124},
  [2] = {.lex_state = 62},
  [3] = {.lex_state = 62},
  [4] = {.lex_state = 63},
  [5] = {.lex_state = 63},
  [6] = {.lex_state = 124},
  [7] = {.lex_state = 124},
  [8] = {.lex_state = 124},
  [9] = {.lex_state = 124},
  [10] = {.lex_state = 124},
  [11] = {.lex_state = 124},
  [12] = {.lex_state = 124},
  [13] = {.lex_state = 124},
  [14] = {.lex_state = 124},
  [15] = {.lex_state = 124},
  [16] = {.lex_state = 124},
  [17] = {.lex_state = 124},
  [18] = {.lex_state = 124},
  [19] = {.lex_state = 124},
  [20] = {.lex_state = 124},
  [21] = {.lex_state = 124},
  [22] = {.lex_state = 124},
  [23] = {.lex_state = 124},
  [24] = {.lex_state = 124},
  [25] = {.lex_state = 124},
  [26] = {.lex_state = 124},
  [27] = {.lex_state = 124},
  [28] = {.lex_state = 124},
  [29] = {.lex_state = 124},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 124},
  [32] = {.lex_state = 124},
  [33] = {.lex_state = 124},
  [34] = {.lex_state = 124},
  [35] = {.lex_state = 124},
  [36] = {.lex_state = 124},
  [37] = {.lex_state = 124},
  [38] = {.lex_state = 124},
  [39] = {.lex_state = 124},
  [40] = {.lex_state = 124},
  [41] = {.lex_state = 124},
  [42] = {.lex_state = 124},
  [43] = {.lex_state = 124},
  [44] = {.lex_state = 124},
  [45] = {.lex_state = 1},
  [46] = {.lex_state = 1},
  [47] = {.lex_state = 124},
  [48] = {.lex_state = 124},
  [49] = {.lex_state = 124},
  [50] = {.lex_state = 61},
  [51] = {.lex_state = 61},
  [52] = {.lex_state = 61},
  [53] = {.lex_state = 9},
  [54] = {.lex_state = 61},
  [55] = {.lex_state = 9},
  [56] = {.lex_state = 1},
  [57] = {.lex_state = 61},
  [58] = {.lex_state = 9},
  [59] = {.lex_state = 61},
  [60] = {.lex_state = 61},
  [61] = {.lex_state = 1},
  [62] = {.lex_state = 4},
  [63] = {.lex_state = 1},
  [64] = {.lex_state = 1},
  [65] = {.lex_state = 61},
  [66] = {.lex_state = 9},
  [67] = {.lex_state = 61},
  [68] = {.lex_state = 1},
  [69] = {.lex_state = 61},
  [70] = {.lex_state = 4},
  [71] = {.lex_state = 1},
  [72] = {.lex_state = 65},
  [73] = {.lex_state = 61},
  [74] = {.lex_state = 65},
  [75] = {.lex_state = 61},
  [76] = {.lex_state = 61},
  [77] = {.lex_state = 65},
  [78] = {.lex_state = 65},
  [79] = {.lex_state = 61},
  [80] = {.lex_state = 61},
  [81] = {.lex_state = 8},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 65},
  [85] = {.lex_state = 61},
  [86] = {.lex_state = 61},
  [87] = {.lex_state = 65},
  [88] = {.lex_state = 8},
  [89] = {.lex_state = 5},
  [90] = {.lex_state = 65},
  [91] = {.lex_state = 65},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 5},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 64},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 257},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 257},
  [116] = {.lex_state = 66},
  [117] = {.lex_state = 64},
  [118] = {.lex_state = 66},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 257},
  [121] = {.lex_state = 257},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 0},
  [124] = {(TSStateId)(-1)},
  [125] = {(TSStateId)(-1)},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [sym_comment] = STATE(0),
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_a] = ACTIONS(1),
    [anon_sym_nml] = ACTIONS(1),
    [anon_sym_title] = ACTIONS(1),
    [anon_sym_pre] = ACTIONS(1),
    [anon_sym_head] = ACTIONS(1),
    [anon_sym_body] = ACTIONS(1),
    [anon_sym_div] = ACTIONS(1),
    [anon_sym_p] = ACTIONS(1),
    [anon_sym_span] = ACTIONS(1),
    [anon_sym_ol] = ACTIONS(1),
    [anon_sym_ul] = ACTIONS(1),
    [anon_sym_template] = ACTIONS(1),
    [anon_sym_li] = ACTIONS(1),
    [anon_sym_slot] = ACTIONS(1),
    [aux_sym__start_tag_name_token1] = ACTIONS(1),
    [anon_sym_script] = ACTIONS(1),
    [anon_sym_style] = ACTIONS(1),
    [anon_sym_LT_BANG_DASH_DASH] = ACTIONS(3),
    [aux_sym_comment_token2] = ACTIONS(1),
    [aux_sym_comment_token3] = ACTIONS(1),
    [anon_sym_DASH_DASH_GT] = ACTIONS(1),
    [anon_sym_meta] = ACTIONS(1),
    [anon_sym_br] = ACTIONS(1),
    [anon_sym_canvas] = ACTIONS(1),
    [anon_sym_hr] = ACTIONS(1),
    [anon_sym_bound] = ACTIONS(1),
    [anon_sym_LT_BANG] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [sym__doctype] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_LT_SLASH] = ACTIONS(1),
    [anon_sym_SLASH_GT] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [sym_entity] = ACTIONS(1),
    [sym_substitution] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(107),
    [sym_comment] = STATE(1),
    [sym_doctype] = STATE(24),
    [sym__node] = STATE(14),
    [sym_element] = STATE(24),
    [sym_script_element] = STATE(24),
    [sym_style_element] = STATE(24),
    [sym_start_tag] = STATE(9),
    [sym_script_start_tag] = STATE(72),
    [sym_style_start_tag] = STATE(74),
    [sym_self_closing_tag] = STATE(26),
    [sym_erroneous_end_tag] = STATE(24),
    [aux_sym_source_file_repeat1] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_LT_BANG_DASH_DASH] = ACTIONS(3),
    [anon_sym_LT_BANG] = ACTIONS(7),
    [anon_sym_LT] = ACTIONS(9),
    [anon_sym_LT_SLASH] = ACTIONS(11),
    [sym_entity] = ACTIONS(13),
    [sym_substitution] = ACTIONS(13),
    [sym_text] = ACTIONS(13),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 10,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(17), 1,
      anon_sym_script,
    ACTIONS(19), 1,
      anon_sym_style,
    STATE(2), 1,
      sym_comment,
    STATE(46), 1,
      sym__start_tag_name,
    STATE(57), 1,
      sym_self_closing_tags,
    STATE(59), 1,
      sym__script_start_tag_name,
    STATE(60), 1,
      sym__style_start_tag_name,
    ACTIONS(21), 5,
      anon_sym_meta,
      anon_sym_br,
      anon_sym_canvas,
      anon_sym_hr,
      anon_sym_bound,
    ACTIONS(15), 17,
      anon_sym_a,
      anon_sym_nml,
      anon_sym_title,
      anon_sym_pre,
      anon_sym_head,
      anon_sym_body,
      anon_sym_div,
      anon_sym_p,
      anon_sym_span,
      anon_sym_ol,
      anon_sym_ul,
      anon_sym_template,
      anon_sym_li,
      anon_sym_slot,
      aux_sym__start_tag_name_token1,
      aux_sym__start_tag_name_token2,
      aux_sym__start_tag_name_token3,
  [51] = 10,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(17), 1,
      anon_sym_script,
    ACTIONS(19), 1,
      anon_sym_style,
    STATE(3), 1,
      sym_comment,
    STATE(46), 1,
      sym__start_tag_name,
    STATE(54), 1,
      sym_self_closing_tags,
    STATE(59), 1,
      sym__script_start_tag_name,
    STATE(60), 1,
      sym__style_start_tag_name,
    ACTIONS(21), 5,
      anon_sym_meta,
      anon_sym_br,
      anon_sym_canvas,
      anon_sym_hr,
      anon_sym_bound,
    ACTIONS(15), 17,
      anon_sym_a,
      anon_sym_nml,
      anon_sym_title,
      anon_sym_pre,
      anon_sym_head,
      anon_sym_body,
      anon_sym_div,
      anon_sym_p,
      anon_sym_span,
      anon_sym_ol,
      anon_sym_ul,
      anon_sym_template,
      anon_sym_li,
      anon_sym_slot,
      aux_sym__start_tag_name_token1,
      aux_sym__start_tag_name_token2,
      aux_sym__start_tag_name_token3,
  [102] = 6,
    ACTIONS(25), 1,
      sym_erroneous_end_tag_name,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(4), 1,
      sym_comment,
    STATE(115), 1,
      sym__start_tag_name,
    STATE(120), 1,
      sym__end_tag_name,
    ACTIONS(23), 17,
      anon_sym_a,
      anon_sym_nml,
      anon_sym_title,
      anon_sym_pre,
      anon_sym_head,
      anon_sym_body,
      anon_sym_div,
      anon_sym_p,
      anon_sym_span,
      anon_sym_ol,
      anon_sym_ul,
      anon_sym_template,
      anon_sym_li,
      anon_sym_slot,
      aux_sym__start_tag_name_token1,
      aux_sym__start_tag_name_token2,
      aux_sym__start_tag_name_token3,
  [137] = 6,
    ACTIONS(25), 1,
      sym_erroneous_end_tag_name,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(5), 1,
      sym_comment,
    STATE(115), 1,
      sym__start_tag_name,
    STATE(121), 1,
      sym__end_tag_name,
    ACTIONS(23), 17,
      anon_sym_a,
      anon_sym_nml,
      anon_sym_title,
      anon_sym_pre,
      anon_sym_head,
      anon_sym_body,
      anon_sym_div,
      anon_sym_p,
      anon_sym_span,
      anon_sym_ol,
      anon_sym_ul,
      anon_sym_template,
      anon_sym_li,
      anon_sym_slot,
      aux_sym__start_tag_name_token1,
      aux_sym__start_tag_name_token2,
      aux_sym__start_tag_name_token3,
  [172] = 14,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(29), 1,
      anon_sym_LT_BANG,
    ACTIONS(31), 1,
      anon_sym_LT,
    ACTIONS(33), 1,
      anon_sym_LT_SLASH,
    STATE(6), 1,
      sym_comment,
    STATE(11), 1,
      sym_start_tag,
    STATE(12), 1,
      aux_sym_source_file_repeat1,
    STATE(17), 1,
      sym_end_tag,
    STATE(29), 1,
      sym_self_closing_tag,
    STATE(48), 1,
      sym__node,
    STATE(77), 1,
      sym_script_start_tag,
    STATE(78), 1,
      sym_style_start_tag,
    ACTIONS(35), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(47), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [221] = 14,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      anon_sym_LT,
    ACTIONS(11), 1,
      anon_sym_LT_SLASH,
    ACTIONS(37), 1,
      ts_builtin_sym_end,
    STATE(7), 1,
      sym_comment,
    STATE(9), 1,
      sym_start_tag,
    STATE(10), 1,
      aux_sym_source_file_repeat1,
    STATE(14), 1,
      sym__node,
    STATE(26), 1,
      sym_self_closing_tag,
    STATE(72), 1,
      sym_script_start_tag,
    STATE(74), 1,
      sym_style_start_tag,
    ACTIONS(13), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(24), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [270] = 14,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(29), 1,
      anon_sym_LT_BANG,
    ACTIONS(31), 1,
      anon_sym_LT,
    ACTIONS(39), 1,
      anon_sym_LT_SLASH,
    STATE(8), 1,
      sym_comment,
    STATE(11), 1,
      sym_start_tag,
    STATE(12), 1,
      aux_sym_source_file_repeat1,
    STATE(29), 1,
      sym_self_closing_tag,
    STATE(37), 1,
      sym_end_tag,
    STATE(48), 1,
      sym__node,
    STATE(77), 1,
      sym_script_start_tag,
    STATE(78), 1,
      sym_style_start_tag,
    ACTIONS(35), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(47), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [319] = 14,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(29), 1,
      anon_sym_LT_BANG,
    ACTIONS(31), 1,
      anon_sym_LT,
    ACTIONS(33), 1,
      anon_sym_LT_SLASH,
    STATE(6), 1,
      aux_sym_source_file_repeat1,
    STATE(9), 1,
      sym_comment,
    STATE(11), 1,
      sym_start_tag,
    STATE(25), 1,
      sym_end_tag,
    STATE(29), 1,
      sym_self_closing_tag,
    STATE(48), 1,
      sym__node,
    STATE(77), 1,
      sym_script_start_tag,
    STATE(78), 1,
      sym_style_start_tag,
    ACTIONS(35), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(47), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [368] = 13,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(41), 1,
      ts_builtin_sym_end,
    ACTIONS(43), 1,
      anon_sym_LT_BANG,
    ACTIONS(46), 1,
      anon_sym_LT,
    ACTIONS(49), 1,
      anon_sym_LT_SLASH,
    STATE(9), 1,
      sym_start_tag,
    STATE(14), 1,
      sym__node,
    STATE(26), 1,
      sym_self_closing_tag,
    STATE(72), 1,
      sym_script_start_tag,
    STATE(74), 1,
      sym_style_start_tag,
    STATE(10), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    ACTIONS(52), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(24), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [415] = 13,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(29), 1,
      anon_sym_LT_BANG,
    ACTIONS(31), 1,
      anon_sym_LT,
    ACTIONS(39), 1,
      anon_sym_LT_SLASH,
    STATE(8), 1,
      aux_sym_source_file_repeat1,
    STATE(29), 1,
      sym_self_closing_tag,
    STATE(31), 1,
      sym_end_tag,
    STATE(48), 1,
      sym__node,
    STATE(77), 1,
      sym_script_start_tag,
    STATE(78), 1,
      sym_style_start_tag,
    STATE(11), 2,
      sym_comment,
      sym_start_tag,
    ACTIONS(35), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(47), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [462] = 12,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(55), 1,
      anon_sym_LT_BANG,
    ACTIONS(58), 1,
      anon_sym_LT,
    ACTIONS(61), 1,
      anon_sym_LT_SLASH,
    STATE(11), 1,
      sym_start_tag,
    STATE(29), 1,
      sym_self_closing_tag,
    STATE(48), 1,
      sym__node,
    STATE(77), 1,
      sym_script_start_tag,
    STATE(78), 1,
      sym_style_start_tag,
    STATE(12), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    ACTIONS(64), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(47), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [506] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(13), 1,
      sym_comment,
    ACTIONS(69), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(67), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [524] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(14), 1,
      sym_comment,
    ACTIONS(73), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(71), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [542] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(15), 1,
      sym_comment,
    ACTIONS(77), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(75), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [560] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(16), 1,
      sym_comment,
    ACTIONS(81), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(79), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [578] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(17), 1,
      sym_comment,
    ACTIONS(85), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(83), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [596] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(18), 1,
      sym_comment,
    ACTIONS(89), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(87), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [614] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(19), 1,
      sym_comment,
    ACTIONS(93), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(91), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [632] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(20), 1,
      sym_comment,
    ACTIONS(97), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(95), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [650] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(21), 1,
      sym_comment,
    ACTIONS(101), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(99), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [668] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(22), 1,
      sym_comment,
    ACTIONS(105), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(103), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [686] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(23), 1,
      sym_comment,
    ACTIONS(109), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(107), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [704] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(24), 1,
      sym_comment,
    ACTIONS(113), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(111), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [722] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(25), 1,
      sym_comment,
    ACTIONS(117), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(115), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [740] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(26), 1,
      sym_comment,
    ACTIONS(121), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(119), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [758] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(27), 1,
      sym_comment,
    ACTIONS(125), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(123), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [776] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(28), 1,
      sym_comment,
    ACTIONS(129), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(127), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [794] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(29), 1,
      sym_comment,
    ACTIONS(121), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(119), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [811] = 7,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(131), 1,
      anon_sym_GT,
    ACTIONS(135), 1,
      sym_attribute_name,
    STATE(30), 1,
      sym_comment,
    STATE(45), 1,
      aux_sym_start_tag_repeat1,
    STATE(68), 1,
      sym_attribute,
    ACTIONS(133), 2,
      anon_sym_LF,
      anon_sym_CR,
  [834] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(31), 1,
      sym_comment,
    ACTIONS(117), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(115), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [851] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(32), 1,
      sym_comment,
    ACTIONS(125), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(123), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [868] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(33), 1,
      sym_comment,
    ACTIONS(129), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(127), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [885] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(34), 1,
      sym_comment,
    ACTIONS(137), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(139), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [902] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(35), 1,
      sym_comment,
    ACTIONS(77), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(75), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [919] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(36), 1,
      sym_comment,
    ACTIONS(81), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(79), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [936] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(37), 1,
      sym_comment,
    ACTIONS(85), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(83), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [953] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(38), 1,
      sym_comment,
    ACTIONS(89), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(87), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [970] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(39), 1,
      sym_comment,
    ACTIONS(93), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(91), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [987] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(40), 1,
      sym_comment,
    ACTIONS(97), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(95), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1004] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(41), 1,
      sym_comment,
    ACTIONS(69), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(67), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1021] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(42), 1,
      sym_comment,
    ACTIONS(101), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(99), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1038] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(43), 1,
      sym_comment,
    ACTIONS(105), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(103), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1055] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(44), 1,
      sym_comment,
    ACTIONS(109), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(107), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1072] = 6,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(141), 1,
      anon_sym_GT,
    ACTIONS(146), 1,
      sym_attribute_name,
    STATE(68), 1,
      sym_attribute,
    ACTIONS(143), 2,
      anon_sym_LF,
      anon_sym_CR,
    STATE(45), 2,
      sym_comment,
      aux_sym_start_tag_repeat1,
  [1093] = 7,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(135), 1,
      sym_attribute_name,
    ACTIONS(149), 1,
      anon_sym_GT,
    STATE(30), 1,
      aux_sym_start_tag_repeat1,
    STATE(46), 1,
      sym_comment,
    STATE(68), 1,
      sym_attribute,
    ACTIONS(133), 2,
      anon_sym_LF,
      anon_sym_CR,
  [1116] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(47), 1,
      sym_comment,
    ACTIONS(113), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(111), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1133] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(48), 1,
      sym_comment,
    ACTIONS(73), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(71), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1150] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(49), 1,
      sym_comment,
    ACTIONS(151), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(153), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1167] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(157), 1,
      sym_attribute_name,
    STATE(50), 1,
      sym_comment,
    STATE(52), 1,
      aux_sym_script_start_tag_repeat1,
    STATE(80), 1,
      sym_attribute,
    ACTIONS(155), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [1187] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(157), 1,
      sym_attribute_name,
    STATE(51), 1,
      sym_comment,
    STATE(52), 1,
      aux_sym_script_start_tag_repeat1,
    STATE(80), 1,
      sym_attribute,
    ACTIONS(159), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [1207] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(163), 1,
      sym_attribute_name,
    STATE(80), 1,
      sym_attribute,
    ACTIONS(161), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
    STATE(52), 2,
      sym_comment,
      aux_sym_script_start_tag_repeat1,
  [1225] = 5,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(168), 1,
      anon_sym_DASH_DASH_GT,
    STATE(53), 1,
      sym_comment,
    STATE(58), 1,
      aux_sym_comment_repeat1,
    ACTIONS(166), 3,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
  [1243] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(157), 1,
      sym_attribute_name,
    STATE(51), 1,
      aux_sym_script_start_tag_repeat1,
    STATE(54), 1,
      sym_comment,
    STATE(80), 1,
      sym_attribute,
    ACTIONS(170), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [1263] = 4,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(175), 1,
      anon_sym_DASH_DASH_GT,
    STATE(55), 2,
      sym_comment,
      aux_sym_comment_repeat1,
    ACTIONS(172), 3,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
  [1279] = 4,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(179), 1,
      anon_sym_EQ,
    STATE(56), 1,
      sym_comment,
    ACTIONS(177), 4,
      anon_sym_GT,
      anon_sym_LF,
      anon_sym_CR,
      sym_attribute_name,
  [1295] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(157), 1,
      sym_attribute_name,
    STATE(50), 1,
      aux_sym_script_start_tag_repeat1,
    STATE(57), 1,
      sym_comment,
    STATE(80), 1,
      sym_attribute,
    ACTIONS(181), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [1315] = 5,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(183), 1,
      anon_sym_DASH_DASH_GT,
    STATE(55), 1,
      aux_sym_comment_repeat1,
    STATE(58), 1,
      sym_comment,
    ACTIONS(166), 3,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
  [1333] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(157), 1,
      sym_attribute_name,
    ACTIONS(185), 1,
      anon_sym_GT,
    STATE(59), 1,
      sym_comment,
    STATE(67), 1,
      aux_sym_script_start_tag_repeat1,
    STATE(80), 1,
      sym_attribute,
  [1352] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(157), 1,
      sym_attribute_name,
    ACTIONS(187), 1,
      anon_sym_GT,
    STATE(60), 1,
      sym_comment,
    STATE(69), 1,
      aux_sym_script_start_tag_repeat1,
    STATE(80), 1,
      sym_attribute,
  [1371] = 3,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(61), 1,
      sym_comment,
    ACTIONS(189), 4,
      anon_sym_GT,
      anon_sym_LF,
      anon_sym_CR,
      sym_attribute_name,
  [1384] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(191), 1,
      sym_attribute_value,
    ACTIONS(193), 1,
      anon_sym_SQUOTE,
    ACTIONS(195), 1,
      anon_sym_DQUOTE,
    STATE(62), 1,
      sym_comment,
    STATE(63), 1,
      sym_quoted_attribute_value,
  [1403] = 3,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(63), 1,
      sym_comment,
    ACTIONS(197), 4,
      anon_sym_GT,
      anon_sym_LF,
      anon_sym_CR,
      sym_attribute_name,
  [1416] = 3,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(64), 1,
      sym_comment,
    ACTIONS(199), 4,
      anon_sym_GT,
      anon_sym_LF,
      anon_sym_CR,
      sym_attribute_name,
  [1429] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(203), 1,
      anon_sym_EQ,
    STATE(65), 1,
      sym_comment,
    ACTIONS(201), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1444] = 3,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(66), 1,
      sym_comment,
    ACTIONS(205), 4,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
      anon_sym_DASH_DASH_GT,
  [1457] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(157), 1,
      sym_attribute_name,
    ACTIONS(207), 1,
      anon_sym_GT,
    STATE(52), 1,
      aux_sym_script_start_tag_repeat1,
    STATE(67), 1,
      sym_comment,
    STATE(80), 1,
      sym_attribute,
  [1476] = 3,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(68), 1,
      sym_comment,
    ACTIONS(209), 4,
      anon_sym_GT,
      anon_sym_LF,
      anon_sym_CR,
      sym_attribute_name,
  [1489] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(157), 1,
      sym_attribute_name,
    ACTIONS(211), 1,
      anon_sym_GT,
    STATE(52), 1,
      aux_sym_script_start_tag_repeat1,
    STATE(69), 1,
      sym_comment,
    STATE(80), 1,
      sym_attribute,
  [1508] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(213), 1,
      sym_attribute_value,
    ACTIONS(215), 1,
      anon_sym_SQUOTE,
    ACTIONS(217), 1,
      anon_sym_DQUOTE,
    STATE(70), 1,
      sym_comment,
    STATE(75), 1,
      sym_quoted_attribute_value,
  [1527] = 3,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(71), 1,
      sym_comment,
    ACTIONS(219), 4,
      anon_sym_GT,
      anon_sym_LF,
      anon_sym_CR,
      sym_attribute_name,
  [1540] = 5,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(221), 1,
      sym_raw_text,
    ACTIONS(223), 1,
      anon_sym_LT_SLASH,
    STATE(27), 1,
      sym_script_end_tag,
    STATE(72), 1,
      sym_comment,
  [1556] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(73), 1,
      sym_comment,
    ACTIONS(225), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1568] = 5,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(227), 1,
      sym_raw_text,
    ACTIONS(229), 1,
      anon_sym_LT_SLASH,
    STATE(28), 1,
      sym_style_end_tag,
    STATE(74), 1,
      sym_comment,
  [1584] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(75), 1,
      sym_comment,
    ACTIONS(231), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1596] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(76), 1,
      sym_comment,
    ACTIONS(233), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1608] = 5,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(235), 1,
      sym_raw_text,
    ACTIONS(237), 1,
      anon_sym_LT_SLASH,
    STATE(32), 1,
      sym_script_end_tag,
    STATE(77), 1,
      sym_comment,
  [1624] = 5,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(239), 1,
      sym_raw_text,
    ACTIONS(241), 1,
      anon_sym_LT_SLASH,
    STATE(33), 1,
      sym_style_end_tag,
    STATE(78), 1,
      sym_comment,
  [1640] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(79), 1,
      sym_comment,
    ACTIONS(243), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1652] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(80), 1,
      sym_comment,
    ACTIONS(245), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1664] = 4,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(247), 1,
      anon_sym_SQUOTE,
    ACTIONS(249), 1,
      aux_sym_quoted_attribute_value_token1,
    STATE(81), 1,
      sym_comment,
  [1677] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(251), 1,
      anon_sym_LT_SLASH,
    STATE(19), 1,
      sym_style_end_tag,
    STATE(82), 1,
      sym_comment,
  [1690] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(253), 1,
      anon_sym_style,
    STATE(83), 1,
      sym_comment,
    STATE(102), 1,
      sym__style_start_tag_name,
  [1703] = 4,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(255), 1,
      sym_raw_text,
    ACTIONS(257), 1,
      anon_sym_LT_SLASH,
    STATE(84), 1,
      sym_comment,
  [1716] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(85), 1,
      sym_comment,
    ACTIONS(259), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1727] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(86), 1,
      sym_comment,
    ACTIONS(261), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1738] = 4,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(263), 1,
      sym_raw_text,
    ACTIONS(265), 1,
      anon_sym_LT_SLASH,
    STATE(87), 1,
      sym_comment,
  [1751] = 4,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(267), 1,
      anon_sym_SQUOTE,
    ACTIONS(269), 1,
      aux_sym_quoted_attribute_value_token1,
    STATE(88), 1,
      sym_comment,
  [1764] = 4,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(271), 1,
      aux_sym_quoted_attribute_value_token2,
    STATE(89), 1,
      sym_comment,
  [1777] = 4,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(273), 1,
      sym_raw_text,
    ACTIONS(275), 1,
      anon_sym_LT_SLASH,
    STATE(90), 1,
      sym_comment,
  [1790] = 4,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(277), 1,
      sym_raw_text,
    ACTIONS(279), 1,
      anon_sym_LT_SLASH,
    STATE(91), 1,
      sym_comment,
  [1803] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(281), 1,
      anon_sym_LT_SLASH,
    STATE(38), 1,
      sym_script_end_tag,
    STATE(92), 1,
      sym_comment,
  [1816] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(283), 1,
      anon_sym_LT_SLASH,
    STATE(39), 1,
      sym_style_end_tag,
    STATE(93), 1,
      sym_comment,
  [1829] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(285), 1,
      anon_sym_LT_SLASH,
    STATE(18), 1,
      sym_script_end_tag,
    STATE(94), 1,
      sym_comment,
  [1842] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(287), 1,
      anon_sym_script,
    STATE(95), 1,
      sym_comment,
    STATE(119), 1,
      sym__script_start_tag_name,
  [1855] = 4,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(247), 1,
      anon_sym_DQUOTE,
    ACTIONS(289), 1,
      aux_sym_quoted_attribute_value_token2,
    STATE(96), 1,
      sym_comment,
  [1868] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(287), 1,
      anon_sym_script,
    STATE(97), 1,
      sym_comment,
    STATE(109), 1,
      sym__script_start_tag_name,
  [1881] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(253), 1,
      anon_sym_style,
    STATE(98), 1,
      sym_comment,
    STATE(106), 1,
      sym__style_start_tag_name,
  [1894] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(291), 1,
      anon_sym_DQUOTE,
    STATE(99), 1,
      sym_comment,
  [1904] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(293), 1,
      anon_sym_SQUOTE,
    STATE(100), 1,
      sym_comment,
  [1914] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(293), 1,
      anon_sym_DQUOTE,
    STATE(101), 1,
      sym_comment,
  [1924] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(295), 1,
      anon_sym_GT,
    STATE(102), 1,
      sym_comment,
  [1934] = 3,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(297), 1,
      sym_erroneous_end_tag_name,
    STATE(103), 1,
      sym_comment,
  [1944] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(299), 1,
      anon_sym_GT,
    STATE(104), 1,
      sym_comment,
  [1954] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(301), 1,
      anon_sym_GT,
    STATE(105), 1,
      sym_comment,
  [1964] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(303), 1,
      anon_sym_GT,
    STATE(106), 1,
      sym_comment,
  [1974] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(305), 1,
      ts_builtin_sym_end,
    STATE(107), 1,
      sym_comment,
  [1984] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(307), 1,
      anon_sym_GT,
    STATE(108), 1,
      sym_comment,
  [1994] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(309), 1,
      anon_sym_GT,
    STATE(109), 1,
      sym_comment,
  [2004] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(311), 1,
      anon_sym_GT,
    STATE(110), 1,
      sym_comment,
  [2014] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(313), 1,
      anon_sym_GT,
    STATE(111), 1,
      sym_comment,
  [2024] = 3,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(315), 1,
      aux_sym_end_tag_token1,
    STATE(112), 1,
      sym_comment,
  [2034] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(317), 1,
      anon_sym_GT,
    STATE(113), 1,
      sym_comment,
  [2044] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(291), 1,
      anon_sym_SQUOTE,
    STATE(114), 1,
      sym_comment,
  [2054] = 3,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(319), 1,
      aux_sym_end_tag_token1,
    STATE(115), 1,
      sym_comment,
  [2064] = 3,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(321), 1,
      aux_sym_doctype_token1,
    STATE(116), 1,
      sym_comment,
  [2074] = 3,
    ACTIONS(25), 1,
      sym_erroneous_end_tag_name,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(117), 1,
      sym_comment,
  [2084] = 3,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(323), 1,
      aux_sym_doctype_token1,
    STATE(118), 1,
      sym_comment,
  [2094] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(325), 1,
      anon_sym_GT,
    STATE(119), 1,
      sym_comment,
  [2104] = 3,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(327), 1,
      aux_sym_end_tag_token1,
    STATE(120), 1,
      sym_comment,
  [2114] = 3,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(329), 1,
      aux_sym_end_tag_token1,
    STATE(121), 1,
      sym_comment,
  [2124] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(331), 1,
      sym__doctype,
    STATE(122), 1,
      sym_comment,
  [2134] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(333), 1,
      sym__doctype,
    STATE(123), 1,
      sym_comment,
  [2144] = 1,
    ACTIONS(335), 1,
      ts_builtin_sym_end,
  [2148] = 1,
    ACTIONS(337), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 51,
  [SMALL_STATE(4)] = 102,
  [SMALL_STATE(5)] = 137,
  [SMALL_STATE(6)] = 172,
  [SMALL_STATE(7)] = 221,
  [SMALL_STATE(8)] = 270,
  [SMALL_STATE(9)] = 319,
  [SMALL_STATE(10)] = 368,
  [SMALL_STATE(11)] = 415,
  [SMALL_STATE(12)] = 462,
  [SMALL_STATE(13)] = 506,
  [SMALL_STATE(14)] = 524,
  [SMALL_STATE(15)] = 542,
  [SMALL_STATE(16)] = 560,
  [SMALL_STATE(17)] = 578,
  [SMALL_STATE(18)] = 596,
  [SMALL_STATE(19)] = 614,
  [SMALL_STATE(20)] = 632,
  [SMALL_STATE(21)] = 650,
  [SMALL_STATE(22)] = 668,
  [SMALL_STATE(23)] = 686,
  [SMALL_STATE(24)] = 704,
  [SMALL_STATE(25)] = 722,
  [SMALL_STATE(26)] = 740,
  [SMALL_STATE(27)] = 758,
  [SMALL_STATE(28)] = 776,
  [SMALL_STATE(29)] = 794,
  [SMALL_STATE(30)] = 811,
  [SMALL_STATE(31)] = 834,
  [SMALL_STATE(32)] = 851,
  [SMALL_STATE(33)] = 868,
  [SMALL_STATE(34)] = 885,
  [SMALL_STATE(35)] = 902,
  [SMALL_STATE(36)] = 919,
  [SMALL_STATE(37)] = 936,
  [SMALL_STATE(38)] = 953,
  [SMALL_STATE(39)] = 970,
  [SMALL_STATE(40)] = 987,
  [SMALL_STATE(41)] = 1004,
  [SMALL_STATE(42)] = 1021,
  [SMALL_STATE(43)] = 1038,
  [SMALL_STATE(44)] = 1055,
  [SMALL_STATE(45)] = 1072,
  [SMALL_STATE(46)] = 1093,
  [SMALL_STATE(47)] = 1116,
  [SMALL_STATE(48)] = 1133,
  [SMALL_STATE(49)] = 1150,
  [SMALL_STATE(50)] = 1167,
  [SMALL_STATE(51)] = 1187,
  [SMALL_STATE(52)] = 1207,
  [SMALL_STATE(53)] = 1225,
  [SMALL_STATE(54)] = 1243,
  [SMALL_STATE(55)] = 1263,
  [SMALL_STATE(56)] = 1279,
  [SMALL_STATE(57)] = 1295,
  [SMALL_STATE(58)] = 1315,
  [SMALL_STATE(59)] = 1333,
  [SMALL_STATE(60)] = 1352,
  [SMALL_STATE(61)] = 1371,
  [SMALL_STATE(62)] = 1384,
  [SMALL_STATE(63)] = 1403,
  [SMALL_STATE(64)] = 1416,
  [SMALL_STATE(65)] = 1429,
  [SMALL_STATE(66)] = 1444,
  [SMALL_STATE(67)] = 1457,
  [SMALL_STATE(68)] = 1476,
  [SMALL_STATE(69)] = 1489,
  [SMALL_STATE(70)] = 1508,
  [SMALL_STATE(71)] = 1527,
  [SMALL_STATE(72)] = 1540,
  [SMALL_STATE(73)] = 1556,
  [SMALL_STATE(74)] = 1568,
  [SMALL_STATE(75)] = 1584,
  [SMALL_STATE(76)] = 1596,
  [SMALL_STATE(77)] = 1608,
  [SMALL_STATE(78)] = 1624,
  [SMALL_STATE(79)] = 1640,
  [SMALL_STATE(80)] = 1652,
  [SMALL_STATE(81)] = 1664,
  [SMALL_STATE(82)] = 1677,
  [SMALL_STATE(83)] = 1690,
  [SMALL_STATE(84)] = 1703,
  [SMALL_STATE(85)] = 1716,
  [SMALL_STATE(86)] = 1727,
  [SMALL_STATE(87)] = 1738,
  [SMALL_STATE(88)] = 1751,
  [SMALL_STATE(89)] = 1764,
  [SMALL_STATE(90)] = 1777,
  [SMALL_STATE(91)] = 1790,
  [SMALL_STATE(92)] = 1803,
  [SMALL_STATE(93)] = 1816,
  [SMALL_STATE(94)] = 1829,
  [SMALL_STATE(95)] = 1842,
  [SMALL_STATE(96)] = 1855,
  [SMALL_STATE(97)] = 1868,
  [SMALL_STATE(98)] = 1881,
  [SMALL_STATE(99)] = 1894,
  [SMALL_STATE(100)] = 1904,
  [SMALL_STATE(101)] = 1914,
  [SMALL_STATE(102)] = 1924,
  [SMALL_STATE(103)] = 1934,
  [SMALL_STATE(104)] = 1944,
  [SMALL_STATE(105)] = 1954,
  [SMALL_STATE(106)] = 1964,
  [SMALL_STATE(107)] = 1974,
  [SMALL_STATE(108)] = 1984,
  [SMALL_STATE(109)] = 1994,
  [SMALL_STATE(110)] = 2004,
  [SMALL_STATE(111)] = 2014,
  [SMALL_STATE(112)] = 2024,
  [SMALL_STATE(113)] = 2034,
  [SMALL_STATE(114)] = 2044,
  [SMALL_STATE(115)] = 2054,
  [SMALL_STATE(116)] = 2064,
  [SMALL_STATE(117)] = 2074,
  [SMALL_STATE(118)] = 2084,
  [SMALL_STATE(119)] = 2094,
  [SMALL_STATE(120)] = 2104,
  [SMALL_STATE(121)] = 2114,
  [SMALL_STATE(122)] = 2124,
  [SMALL_STATE(123)] = 2134,
  [SMALL_STATE(124)] = 2144,
  [SMALL_STATE(125)] = 2148,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(123),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(85),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [43] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(123),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(103),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(24),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(122),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(117),
  [64] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(47),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 4, 0, 0),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 4, 0, 0),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 1, 0, 0),
  [73] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 1, 0, 0),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 3, 0, 0),
  [77] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 3, 0, 0),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_erroneous_end_tag, 3, 0, 0),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_erroneous_end_tag, 3, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 3, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 3, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 3, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 3, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 3, 0, 0),
  [93] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 3, 0, 0),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doctype, 4, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_doctype, 4, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_end_tag, 3, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_end_tag, 3, 0, 0),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_end_tag, 3, 0, 0),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_end_tag, 3, 0, 0),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_end_tag, 4, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_end_tag, 4, 0, 0),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__node, 1, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__node, 1, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 2, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 2, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 1, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 1, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 2, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 2, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 2, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 2, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [133] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [135] = {.entry = {.count = 1, .reusable = false}}, SHIFT(56),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 4, 0, 1),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 4, 0, 1),
  [141] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_start_tag_repeat1, 2, 0, 0),
  [143] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_start_tag_repeat1, 2, 0, 0), SHIFT_REPEAT(68),
  [146] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_start_tag_repeat1, 2, 0, 0), SHIFT_REPEAT(56),
  [149] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 3, 0, 1),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 3, 0, 1),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_start_tag_repeat1, 2, 0, 0),
  [163] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_start_tag_repeat1, 2, 0, 0), SHIFT_REPEAT(65),
  [166] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [168] = {.entry = {.count = 1, .reusable = false}}, SHIFT(124),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [172] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(66),
  [175] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_comment_repeat1, 2, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 1, 0, 0),
  [179] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [183] = {.entry = {.count = 1, .reusable = false}}, SHIFT(125),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [189] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quoted_attribute_value, 2, 0, 0),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [197] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 3, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quoted_attribute_value, 3, 0, 0),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1, 0, 0),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [205] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_comment_repeat1, 1, 0, 0),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [209] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_start_tag_repeat1, 1, 0, 0),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [219] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__start_tag_name, 1, 0, 0),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [223] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tags, 1, 0, 0),
  [227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [229] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3, 0, 0),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 3, 0, 0),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [237] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [241] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [243] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 2, 0, 0),
  [245] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_start_tag_repeat1, 1, 0, 0),
  [247] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [249] = {.entry = {.count = 1, .reusable = false}}, SHIFT(114),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [255] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 4, 0, 0),
  [257] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_start_tag, 4, 0, 0),
  [259] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__script_start_tag_name, 1, 0, 0),
  [261] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__style_start_tag_name, 1, 0, 0),
  [263] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 3, 0, 0),
  [265] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_start_tag, 3, 0, 0),
  [267] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [269] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [271] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 4, 0, 0),
  [275] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_start_tag, 4, 0, 0),
  [277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 3, 0, 0),
  [279] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_start_tag, 3, 0, 0),
  [281] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [289] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [297] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [305] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [315] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__start_tag_name, 1, 0, 0),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [319] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__end_tag_name, 1, 0, 0),
  [321] = {.entry = {.count = 1, .reusable = false}}, SHIFT(113),
  [323] = {.entry = {.count = 1, .reusable = false}}, SHIFT(108),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [335] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 2, 0, 0),
  [337] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 3, 0, 0),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_nml(void) {
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
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
