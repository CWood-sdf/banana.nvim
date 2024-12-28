#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 113
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 73
#define ALIAS_COUNT 0
#define TOKEN_COUNT 47
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
  aux_sym_erroneous_end_tag_name_token1 = 21,
  anon_sym_LT_BANG_DASH_DASH = 22,
  aux_sym_comment_token1 = 23,
  aux_sym_comment_token2 = 24,
  aux_sym_comment_token3 = 25,
  anon_sym_DASH_DASH_GT = 26,
  anon_sym_meta = 27,
  anon_sym_br = 28,
  anon_sym_hr = 29,
  anon_sym_bound = 30,
  anon_sym_LT_BANG = 31,
  anon_sym_GT = 32,
  sym__doctype = 33,
  anon_sym_LT = 34,
  anon_sym_LT_SLASH = 35,
  anon_sym_SLASH_GT = 36,
  anon_sym_EQ = 37,
  sym_attribute_name = 38,
  sym_attribute_value = 39,
  sym_entity = 40,
  sym_substitution = 41,
  anon_sym_SQUOTE = 42,
  aux_sym_quoted_attribute_value_token1 = 43,
  anon_sym_DQUOTE = 44,
  aux_sym_quoted_attribute_value_token2 = 45,
  sym_text = 46,
  sym_source_file = 47,
  sym__start_tag_name = 48,
  sym__script_start_tag_name = 49,
  sym__style_start_tag_name = 50,
  sym__end_tag_name = 51,
  sym_erroneous_end_tag_name = 52,
  sym_comment = 53,
  sym_self_closing_tags = 54,
  sym_doctype = 55,
  sym__node = 56,
  sym_element = 57,
  sym_script_element = 58,
  sym_style_element = 59,
  sym_start_tag = 60,
  sym_script_start_tag = 61,
  sym_script_end_tag = 62,
  sym_style_start_tag = 63,
  sym_style_end_tag = 64,
  sym_self_closing_tag = 65,
  sym_end_tag = 66,
  sym_erroneous_end_tag = 67,
  sym_attribute = 68,
  sym_quoted_attribute_value = 69,
  aux_sym_source_file_repeat1 = 70,
  aux_sym_comment_repeat1 = 71,
  aux_sym_start_tag_repeat1 = 72,
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
  [aux_sym_erroneous_end_tag_name_token1] = "erroneous_end_tag_name_token1",
  [anon_sym_LT_BANG_DASH_DASH] = "<!--",
  [aux_sym_comment_token1] = "comment_token1",
  [aux_sym_comment_token2] = "comment_token2",
  [aux_sym_comment_token3] = "comment_token3",
  [anon_sym_DASH_DASH_GT] = "-->",
  [anon_sym_meta] = "meta",
  [anon_sym_br] = "br",
  [anon_sym_hr] = "hr",
  [anon_sym_bound] = "bound",
  [anon_sym_LT_BANG] = "<!",
  [anon_sym_GT] = ">",
  [sym__doctype] = "doctype",
  [anon_sym_LT] = "<",
  [anon_sym_LT_SLASH] = "</",
  [anon_sym_SLASH_GT] = "/>",
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
  [sym_erroneous_end_tag_name] = "erroneous_end_tag_name",
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
  [aux_sym_erroneous_end_tag_name_token1] = aux_sym_erroneous_end_tag_name_token1,
  [anon_sym_LT_BANG_DASH_DASH] = anon_sym_LT_BANG_DASH_DASH,
  [aux_sym_comment_token1] = aux_sym_comment_token1,
  [aux_sym_comment_token2] = aux_sym_comment_token2,
  [aux_sym_comment_token3] = aux_sym_comment_token3,
  [anon_sym_DASH_DASH_GT] = anon_sym_DASH_DASH_GT,
  [anon_sym_meta] = anon_sym_meta,
  [anon_sym_br] = anon_sym_br,
  [anon_sym_hr] = anon_sym_hr,
  [anon_sym_bound] = anon_sym_bound,
  [anon_sym_LT_BANG] = anon_sym_LT_BANG,
  [anon_sym_GT] = anon_sym_GT,
  [sym__doctype] = sym__doctype,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_LT_SLASH] = anon_sym_LT_SLASH,
  [anon_sym_SLASH_GT] = anon_sym_SLASH_GT,
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
  [sym_erroneous_end_tag_name] = sym_erroneous_end_tag_name,
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
  [aux_sym_erroneous_end_tag_name_token1] = {
    .visible = false,
    .named = false,
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
  [anon_sym_LT_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_GT] = {
    .visible = true,
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
  [sym_erroneous_end_tag_name] = {
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
  [8] = 8,
  [9] = 9,
  [10] = 6,
  [11] = 9,
  [12] = 7,
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
  [30] = 17,
  [31] = 31,
  [32] = 19,
  [33] = 20,
  [34] = 28,
  [35] = 35,
  [36] = 25,
  [37] = 22,
  [38] = 21,
  [39] = 27,
  [40] = 24,
  [41] = 23,
  [42] = 14,
  [43] = 13,
  [44] = 18,
  [45] = 15,
  [46] = 16,
  [47] = 47,
  [48] = 48,
  [49] = 47,
  [50] = 50,
  [51] = 51,
  [52] = 51,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
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
  [69] = 67,
  [70] = 70,
  [71] = 70,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 74,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 78,
  [87] = 80,
  [88] = 88,
  [89] = 76,
  [90] = 90,
  [91] = 79,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 92,
  [101] = 101,
  [102] = 102,
  [103] = 101,
  [104] = 104,
  [105] = 105,
  [106] = 102,
  [107] = 96,
  [108] = 104,
  [109] = 97,
  [110] = 95,
  [111] = 111,
  [112] = 112,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(113);
      ADVANCE_MAP(
        '"', 289,
        '%', 281,
        '&', 5,
        '\'', 283,
        '-', 9,
        '/', 60,
        '<', 234,
        '=', 237,
        '>', 232,
        'D', 105,
        'a', 114,
        'b', 90,
        'd', 77,
        'h', 70,
        'l', 78,
        'm', 71,
        'n', 87,
        'o', 80,
        'p', 137,
        's', 66,
        't', 76,
        'u', 81,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '!') ADVANCE(10);
      END_STATE();
    case 2:
      if (lookahead == '!') ADVANCE(10);
      if (lookahead == '/') ADVANCE(235);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(289);
      if (lookahead == '\'') ADVANCE(283);
      if (lookahead == '<') ADVANCE(1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (lookahead != 0 &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(239);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(289);
      if (lookahead == '<') ADVANCE(290);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(293);
      if (lookahead != 0) ADVANCE(294);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(108);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 6:
      if (lookahead == '%') ADVANCE(281);
      if (lookahead == '&') ADVANCE(5);
      if (lookahead == '<') ADVANCE(234);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(295);
      END_STATE();
    case 7:
      if (lookahead == '\'') ADVANCE(283);
      if (lookahead == '<') ADVANCE(284);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(287);
      if (lookahead != 0) ADVANCE(288);
      END_STATE();
    case 8:
      if (lookahead == '-') ADVANCE(9);
      if (lookahead == '<') ADVANCE(218);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(219);
      if (lookahead != 0) ADVANCE(217);
      END_STATE();
    case 9:
      if (lookahead == '-') ADVANCE(61);
      if (lookahead != 0) ADVANCE(220);
      END_STATE();
    case 10:
      if (lookahead == '-') ADVANCE(11);
      END_STATE();
    case 11:
      if (lookahead == '-') ADVANCE(213);
      END_STATE();
    case 12:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'a') ADVANCE(17);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 13:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'a') ADVANCE(224);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 14:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'a') ADVANCE(38);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 15:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'a') ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 16:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'c') ADVANCE(44);
      if (lookahead == 'l') ADVANCE(41);
      if (lookahead == 'p') ADVANCE(14);
      if (lookahead == 't') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 17:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'd') ADVANCE(127);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 18:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'd') ADVANCE(230);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 19:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'd') ADVANCE(51);
      if (lookahead == 'u') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 20:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'e') ADVANCE(12);
      if (lookahead == 'r') ADVANCE(228);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(157);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 21:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'e') ADVANCE(47);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 22:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'e') ADVANCE(124);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 23:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'e') ADVANCE(174);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 24:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'e') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 25:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'e') ADVANCE(148);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 26:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'e') ADVANCE(36);
      if (lookahead == 'i') ADVANCE(49);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 27:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'i') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 28:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'i') ADVANCE(151);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 29:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'i') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 30:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'l') ADVANCE(142);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 31:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'l') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 32:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'l') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 33:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'l') ADVANCE(23);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 34:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'l') ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 35:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'l') ADVANCE(15);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 36:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'm') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 37:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'm') ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 38:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'n') ADVANCE(139);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 39:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'n') ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 40:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'o') ADVANCE(19);
      if (lookahead == 'r') ADVANCE(226);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 41:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'o') ADVANCE(45);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 42:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'p') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 43:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'p') ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 44:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'r') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 45:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 't') ADVANCE(154);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 46:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 't') ADVANCE(172);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 47:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 't') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 48:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 't') ADVANCE(25);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 49:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 't') ADVANCE(34);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 50:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'v') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 51:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'y') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 52:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'y') ADVANCE(33);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 53:
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 54:
      if (lookahead == '-') ADVANCE(165);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      END_STATE();
    case 55:
      if (lookahead == '/') ADVANCE(60);
      if (lookahead == '<') ADVANCE(1);
      if (lookahead == '=') ADVANCE(237);
      if (lookahead == '>') ADVANCE(232);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(55);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'') ADVANCE(238);
      END_STATE();
    case 56:
      ADVANCE_MAP(
        '<', 1,
        'a', 115,
        'b', 40,
        'd', 27,
        'h', 20,
        'l', 28,
        'm', 21,
        'n', 37,
        'o', 30,
        'p', 135,
        's', 16,
        't', 26,
        'u', 31,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(56);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('c' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(54);
      END_STATE();
    case 57:
      ADVANCE_MAP(
        '<', 175,
        'a', 116,
        'b', 197,
        'd', 186,
        'h', 181,
        'l', 187,
        'n', 195,
        'o', 188,
        'p', 136,
        's', 191,
        't', 185,
        'u', 189,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(209);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('c' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(206);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 58:
      if (lookahead == '<') ADVANCE(175);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(210);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 59:
      if (lookahead == '<') ADVANCE(2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(169);
      if (lookahead != 0) ADVANCE(170);
      END_STATE();
    case 60:
      if (lookahead == '>') ADVANCE(236);
      END_STATE();
    case 61:
      if (lookahead == '>') ADVANCE(222);
      if (lookahead != 0) ADVANCE(221);
      END_STATE();
    case 62:
      if (lookahead == 'a') ADVANCE(67);
      END_STATE();
    case 63:
      if (lookahead == 'a') ADVANCE(223);
      END_STATE();
    case 64:
      if (lookahead == 'a') ADVANCE(88);
      END_STATE();
    case 65:
      if (lookahead == 'a') ADVANCE(98);
      END_STATE();
    case 66:
      if (lookahead == 'c') ADVANCE(94);
      if (lookahead == 'l') ADVANCE(91);
      if (lookahead == 'p') ADVANCE(64);
      if (lookahead == 't') ADVANCE(102);
      END_STATE();
    case 67:
      if (lookahead == 'd') ADVANCE(126);
      END_STATE();
    case 68:
      if (lookahead == 'd') ADVANCE(229);
      END_STATE();
    case 69:
      if (lookahead == 'd') ADVANCE(101);
      if (lookahead == 'u') ADVANCE(89);
      END_STATE();
    case 70:
      if (lookahead == 'e') ADVANCE(62);
      if (lookahead == 'r') ADVANCE(227);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(156);
      END_STATE();
    case 71:
      if (lookahead == 'e') ADVANCE(97);
      END_STATE();
    case 72:
      if (lookahead == 'e') ADVANCE(123);
      END_STATE();
    case 73:
      if (lookahead == 'e') ADVANCE(173);
      END_STATE();
    case 74:
      if (lookahead == 'e') ADVANCE(120);
      END_STATE();
    case 75:
      if (lookahead == 'e') ADVANCE(147);
      END_STATE();
    case 76:
      if (lookahead == 'e') ADVANCE(86);
      if (lookahead == 'i') ADVANCE(99);
      END_STATE();
    case 77:
      if (lookahead == 'i') ADVANCE(100);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(103);
      END_STATE();
    case 78:
      if (lookahead == 'i') ADVANCE(150);
      END_STATE();
    case 79:
      if (lookahead == 'i') ADVANCE(92);
      END_STATE();
    case 80:
      if (lookahead == 'l') ADVANCE(141);
      END_STATE();
    case 81:
      if (lookahead == 'l') ADVANCE(144);
      END_STATE();
    case 82:
      if (lookahead == 'l') ADVANCE(117);
      END_STATE();
    case 83:
      if (lookahead == 'l') ADVANCE(73);
      END_STATE();
    case 84:
      if (lookahead == 'l') ADVANCE(74);
      END_STATE();
    case 85:
      if (lookahead == 'l') ADVANCE(65);
      END_STATE();
    case 86:
      if (lookahead == 'm') ADVANCE(93);
      END_STATE();
    case 87:
      if (lookahead == 'm') ADVANCE(82);
      END_STATE();
    case 88:
      if (lookahead == 'n') ADVANCE(138);
      END_STATE();
    case 89:
      if (lookahead == 'n') ADVANCE(68);
      END_STATE();
    case 90:
      if (lookahead == 'o') ADVANCE(69);
      if (lookahead == 'r') ADVANCE(225);
      END_STATE();
    case 91:
      if (lookahead == 'o') ADVANCE(95);
      END_STATE();
    case 92:
      if (lookahead == 'p') ADVANCE(96);
      END_STATE();
    case 93:
      if (lookahead == 'p') ADVANCE(85);
      END_STATE();
    case 94:
      if (lookahead == 'r') ADVANCE(79);
      END_STATE();
    case 95:
      if (lookahead == 't') ADVANCE(153);
      END_STATE();
    case 96:
      if (lookahead == 't') ADVANCE(171);
      END_STATE();
    case 97:
      if (lookahead == 't') ADVANCE(63);
      END_STATE();
    case 98:
      if (lookahead == 't') ADVANCE(75);
      END_STATE();
    case 99:
      if (lookahead == 't') ADVANCE(84);
      END_STATE();
    case 100:
      if (lookahead == 'v') ADVANCE(132);
      END_STATE();
    case 101:
      if (lookahead == 'y') ADVANCE(129);
      END_STATE();
    case 102:
      if (lookahead == 'y') ADVANCE(83);
      END_STATE();
    case 103:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(107);
      END_STATE();
    case 104:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(233);
      END_STATE();
    case 105:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(103);
      END_STATE();
    case 106:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(104);
      END_STATE();
    case 107:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(109);
      END_STATE();
    case 108:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(110);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(245);
      END_STATE();
    case 109:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(106);
      END_STATE();
    case 110:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(250);
      END_STATE();
    case 111:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(159);
      END_STATE();
    case 112:
      if (eof) ADVANCE(113);
      if (lookahead == '%') ADVANCE(281);
      if (lookahead == '&') ADVANCE(5);
      if (lookahead == '<') ADVANCE(234);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(295);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_a);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_a);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_a);
      if (lookahead == '-') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_nml);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_nml);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_nml);
      if (lookahead == '-') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_title);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_title);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_title);
      if (lookahead == '-') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_pre);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_pre);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_pre);
      if (lookahead == '-') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_head);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_head);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_head);
      if (lookahead == '-') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_body);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_body);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_body);
      if (lookahead == '-') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_div);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_div);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_div);
      if (lookahead == '-') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_p);
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == 'r') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_p);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'r') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_p);
      if (lookahead == 'r') ADVANCE(72);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_span);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_span);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_span);
      if (lookahead == '-') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_ol);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_ol);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_ol);
      if (lookahead == '-') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_ul);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_ul);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_ul);
      if (lookahead == '-') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_template);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_template);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_template);
      if (lookahead == '-') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_li);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_li);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_li);
      if (lookahead == '-') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_slot);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_slot);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_slot);
      if (lookahead == '-') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token1);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token1);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(159);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(165);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(160);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(161);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(166);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '-') ADVANCE(165);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '-') ADVANCE(166);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(164);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '+' ||
          lookahead == '-' ||
          lookahead == '/') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(160);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '+' ||
          lookahead == '-' ||
          lookahead == '/') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '+' ||
          lookahead == '-' ||
          ('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(167);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '+' ||
          lookahead == '-' ||
          ('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym_raw_text);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(169);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(170);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym_raw_text);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(170);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(anon_sym_script);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(anon_sym_style);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(anon_sym_style);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '!') ADVANCE(208);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'a') ADVANCE(196);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'a') ADVANCE(180);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'a') ADVANCE(201);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'd') ADVANCE(204);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'd') ADVANCE(128);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'e') ADVANCE(177);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'e') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'e') ADVANCE(122);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'e') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'e') ADVANCE(194);
      if (lookahead == 'i') ADVANCE(202);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'i') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'i') ADVANCE(152);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'l') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'l') ADVANCE(146);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'l') ADVANCE(119);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'l') ADVANCE(198);
      if (lookahead == 'p') ADVANCE(176);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'l') ADVANCE(183);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'l') ADVANCE(178);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'm') ADVANCE(199);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'm') ADVANCE(190);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'n') ADVANCE(140);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'o') ADVANCE(179);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'o') ADVANCE(200);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'p') ADVANCE(193);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 't') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 't') ADVANCE(184);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 't') ADVANCE(192);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'v') ADVANCE(134);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (lookahead == 'y') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(166);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(164);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(216);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(207);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      ADVANCE_MAP(
        '<', 175,
        'a', 116,
        'b', 197,
        'd', 186,
        'h', 181,
        'l', 187,
        'n', 195,
        'o', 188,
        'p', 136,
        's', 191,
        't', 185,
        'u', 189,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(209);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('c' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(206);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '<') ADVANCE(175);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(210);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(161);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(294);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(288);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(212);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '!') ADVANCE(10);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '<') ADVANCE(218);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(219);
      if (lookahead != 0 &&
          lookahead != '-') ADVANCE(217);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(aux_sym_comment_token2);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(aux_sym_comment_token3);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(anon_sym_DASH_DASH_GT);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(anon_sym_meta);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(anon_sym_meta);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(anon_sym_br);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(anon_sym_br);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(anon_sym_hr);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(anon_sym_hr);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(anon_sym_bound);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(anon_sym_bound);
      if (lookahead == '-') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(anon_sym_LT_BANG);
      if (lookahead == '-') ADVANCE(11);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym__doctype);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '!') ADVANCE(231);
      if (lookahead == '/') ADVANCE(235);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(anon_sym_LT_SLASH);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(anon_sym_SLASH_GT);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(238);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_attribute_value);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(239);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_entity);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(241);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(242);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(243);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(244);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(241);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(246);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(247);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(248);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(249);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(241);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(251);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(252);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(253);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(254);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(255);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(257);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(258);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(259);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(261);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(263);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(264);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(265);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(266);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(267);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(269);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(270);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(271);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(272);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(273);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(274);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(276);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(277);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(278);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_substitution);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_substitution);
      if (lookahead == '%') ADVANCE(280);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_substitution);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '!') ADVANCE(286);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(288);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '-') ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(288);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '-') ADVANCE(285);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(288);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '<') ADVANCE(284);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(287);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(288);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(288);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '!') ADVANCE(292);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '"') ADVANCE(294);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '-') ADVANCE(214);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(294);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '-') ADVANCE(291);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(294);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '<') ADVANCE(290);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(293);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(294);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(294);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_text);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(295);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '&' &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(295);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 112},
  [2] = {.lex_state = 56},
  [3] = {.lex_state = 56},
  [4] = {.lex_state = 57},
  [5] = {.lex_state = 57},
  [6] = {.lex_state = 112},
  [7] = {.lex_state = 112},
  [8] = {.lex_state = 112},
  [9] = {.lex_state = 112},
  [10] = {.lex_state = 112},
  [11] = {.lex_state = 112},
  [12] = {.lex_state = 112},
  [13] = {.lex_state = 112},
  [14] = {.lex_state = 112},
  [15] = {.lex_state = 112},
  [16] = {.lex_state = 112},
  [17] = {.lex_state = 112},
  [18] = {.lex_state = 112},
  [19] = {.lex_state = 112},
  [20] = {.lex_state = 112},
  [21] = {.lex_state = 112},
  [22] = {.lex_state = 112},
  [23] = {.lex_state = 112},
  [24] = {.lex_state = 112},
  [25] = {.lex_state = 112},
  [26] = {.lex_state = 112},
  [27] = {.lex_state = 112},
  [28] = {.lex_state = 112},
  [29] = {.lex_state = 112},
  [30] = {.lex_state = 112},
  [31] = {.lex_state = 112},
  [32] = {.lex_state = 112},
  [33] = {.lex_state = 112},
  [34] = {.lex_state = 112},
  [35] = {.lex_state = 112},
  [36] = {.lex_state = 112},
  [37] = {.lex_state = 112},
  [38] = {.lex_state = 112},
  [39] = {.lex_state = 112},
  [40] = {.lex_state = 112},
  [41] = {.lex_state = 112},
  [42] = {.lex_state = 112},
  [43] = {.lex_state = 112},
  [44] = {.lex_state = 112},
  [45] = {.lex_state = 112},
  [46] = {.lex_state = 112},
  [47] = {.lex_state = 55},
  [48] = {.lex_state = 8},
  [49] = {.lex_state = 55},
  [50] = {.lex_state = 55},
  [51] = {.lex_state = 55},
  [52] = {.lex_state = 55},
  [53] = {.lex_state = 8},
  [54] = {.lex_state = 8},
  [55] = {.lex_state = 55},
  [56] = {.lex_state = 55},
  [57] = {.lex_state = 3},
  [58] = {.lex_state = 55},
  [59] = {.lex_state = 55},
  [60] = {.lex_state = 55},
  [61] = {.lex_state = 55},
  [62] = {.lex_state = 55},
  [63] = {.lex_state = 8},
  [64] = {.lex_state = 55},
  [65] = {.lex_state = 55},
  [66] = {.lex_state = 55},
  [67] = {.lex_state = 59},
  [68] = {.lex_state = 55},
  [69] = {.lex_state = 59},
  [70] = {.lex_state = 59},
  [71] = {.lex_state = 59},
  [72] = {.lex_state = 55},
  [73] = {.lex_state = 55},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 59},
  [76] = {.lex_state = 58},
  [77] = {.lex_state = 59},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 55},
  [83] = {.lex_state = 55},
  [84] = {.lex_state = 7},
  [85] = {.lex_state = 4},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 59},
  [89] = {.lex_state = 58},
  [90] = {.lex_state = 59},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 58},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 58},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0},
  [111] = {(TSStateId)(-1)},
  [112] = {(TSStateId)(-1)},
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
    [sym_source_file] = STATE(99),
    [sym_comment] = STATE(1),
    [sym_doctype] = STATE(14),
    [sym__node] = STATE(13),
    [sym_element] = STATE(14),
    [sym_script_element] = STATE(14),
    [sym_style_element] = STATE(14),
    [sym_start_tag] = STATE(6),
    [sym_script_start_tag] = STATE(67),
    [sym_style_start_tag] = STATE(71),
    [sym_self_closing_tag] = STATE(18),
    [sym_erroneous_end_tag] = STATE(14),
    [aux_sym_source_file_repeat1] = STATE(8),
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
    STATE(51), 1,
      sym_self_closing_tags,
    STATE(58), 1,
      sym__script_start_tag_name,
    STATE(59), 1,
      sym__start_tag_name,
    STATE(60), 1,
      sym__style_start_tag_name,
    ACTIONS(21), 4,
      anon_sym_meta,
      anon_sym_br,
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
  [50] = 10,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(17), 1,
      anon_sym_script,
    ACTIONS(19), 1,
      anon_sym_style,
    STATE(3), 1,
      sym_comment,
    STATE(52), 1,
      sym_self_closing_tags,
    STATE(58), 1,
      sym__script_start_tag_name,
    STATE(59), 1,
      sym__start_tag_name,
    STATE(60), 1,
      sym__style_start_tag_name,
    ACTIONS(21), 4,
      anon_sym_meta,
      anon_sym_br,
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
  [100] = 7,
    ACTIONS(23), 1,
      aux_sym_erroneous_end_tag_name_token1,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(4), 1,
      sym_comment,
    STATE(93), 1,
      sym__start_tag_name,
    STATE(97), 1,
      sym_erroneous_end_tag_name,
    STATE(106), 1,
      sym__end_tag_name,
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
  [138] = 7,
    ACTIONS(23), 1,
      aux_sym_erroneous_end_tag_name_token1,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(5), 1,
      sym_comment,
    STATE(93), 1,
      sym__start_tag_name,
    STATE(97), 1,
      sym_erroneous_end_tag_name,
    STATE(102), 1,
      sym__end_tag_name,
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
  [176] = 14,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      anon_sym_LT_BANG,
    ACTIONS(29), 1,
      anon_sym_LT,
    ACTIONS(31), 1,
      anon_sym_LT_SLASH,
    STATE(6), 1,
      sym_comment,
    STATE(9), 1,
      aux_sym_source_file_repeat1,
    STATE(10), 1,
      sym_start_tag,
    STATE(15), 1,
      sym_end_tag,
    STATE(43), 1,
      sym__node,
    STATE(44), 1,
      sym_self_closing_tag,
    STATE(69), 1,
      sym_script_start_tag,
    STATE(70), 1,
      sym_style_start_tag,
    ACTIONS(33), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(42), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [225] = 13,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(35), 1,
      ts_builtin_sym_end,
    ACTIONS(37), 1,
      anon_sym_LT_BANG,
    ACTIONS(40), 1,
      anon_sym_LT,
    ACTIONS(43), 1,
      anon_sym_LT_SLASH,
    STATE(6), 1,
      sym_start_tag,
    STATE(13), 1,
      sym__node,
    STATE(18), 1,
      sym_self_closing_tag,
    STATE(67), 1,
      sym_script_start_tag,
    STATE(71), 1,
      sym_style_start_tag,
    STATE(7), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    ACTIONS(46), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(14), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [272] = 14,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      anon_sym_LT,
    ACTIONS(11), 1,
      anon_sym_LT_SLASH,
    ACTIONS(49), 1,
      ts_builtin_sym_end,
    STATE(6), 1,
      sym_start_tag,
    STATE(7), 1,
      aux_sym_source_file_repeat1,
    STATE(8), 1,
      sym_comment,
    STATE(13), 1,
      sym__node,
    STATE(18), 1,
      sym_self_closing_tag,
    STATE(67), 1,
      sym_script_start_tag,
    STATE(71), 1,
      sym_style_start_tag,
    ACTIONS(13), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(14), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [321] = 14,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      anon_sym_LT_BANG,
    ACTIONS(29), 1,
      anon_sym_LT,
    ACTIONS(31), 1,
      anon_sym_LT_SLASH,
    STATE(9), 1,
      sym_comment,
    STATE(10), 1,
      sym_start_tag,
    STATE(12), 1,
      aux_sym_source_file_repeat1,
    STATE(28), 1,
      sym_end_tag,
    STATE(43), 1,
      sym__node,
    STATE(44), 1,
      sym_self_closing_tag,
    STATE(69), 1,
      sym_script_start_tag,
    STATE(70), 1,
      sym_style_start_tag,
    ACTIONS(33), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(42), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [370] = 13,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      anon_sym_LT_BANG,
    ACTIONS(29), 1,
      anon_sym_LT,
    ACTIONS(51), 1,
      anon_sym_LT_SLASH,
    STATE(11), 1,
      aux_sym_source_file_repeat1,
    STATE(43), 1,
      sym__node,
    STATE(44), 1,
      sym_self_closing_tag,
    STATE(45), 1,
      sym_end_tag,
    STATE(69), 1,
      sym_script_start_tag,
    STATE(70), 1,
      sym_style_start_tag,
    STATE(10), 2,
      sym_comment,
      sym_start_tag,
    ACTIONS(33), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(42), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [417] = 14,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      anon_sym_LT_BANG,
    ACTIONS(29), 1,
      anon_sym_LT,
    ACTIONS(51), 1,
      anon_sym_LT_SLASH,
    STATE(10), 1,
      sym_start_tag,
    STATE(11), 1,
      sym_comment,
    STATE(12), 1,
      aux_sym_source_file_repeat1,
    STATE(34), 1,
      sym_end_tag,
    STATE(43), 1,
      sym__node,
    STATE(44), 1,
      sym_self_closing_tag,
    STATE(69), 1,
      sym_script_start_tag,
    STATE(70), 1,
      sym_style_start_tag,
    ACTIONS(33), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(42), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [466] = 12,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(53), 1,
      anon_sym_LT_BANG,
    ACTIONS(56), 1,
      anon_sym_LT,
    ACTIONS(59), 1,
      anon_sym_LT_SLASH,
    STATE(10), 1,
      sym_start_tag,
    STATE(43), 1,
      sym__node,
    STATE(44), 1,
      sym_self_closing_tag,
    STATE(69), 1,
      sym_script_start_tag,
    STATE(70), 1,
      sym_style_start_tag,
    STATE(12), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    ACTIONS(62), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(42), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [510] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(13), 1,
      sym_comment,
    ACTIONS(67), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(65), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [528] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(14), 1,
      sym_comment,
    ACTIONS(71), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(69), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [546] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(15), 1,
      sym_comment,
    ACTIONS(75), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(73), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [564] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(16), 1,
      sym_comment,
    ACTIONS(79), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(77), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [582] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(17), 1,
      sym_comment,
    ACTIONS(83), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(81), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [600] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(18), 1,
      sym_comment,
    ACTIONS(87), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(85), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [618] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(19), 1,
      sym_comment,
    ACTIONS(91), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(89), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [636] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(20), 1,
      sym_comment,
    ACTIONS(95), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(93), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [654] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(21), 1,
      sym_comment,
    ACTIONS(99), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(97), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [672] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(22), 1,
      sym_comment,
    ACTIONS(103), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(101), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [690] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(23), 1,
      sym_comment,
    ACTIONS(107), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(105), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [708] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(24), 1,
      sym_comment,
    ACTIONS(111), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(109), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [726] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(25), 1,
      sym_comment,
    ACTIONS(115), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(113), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [744] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(26), 1,
      sym_comment,
    ACTIONS(119), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(117), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [762] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(27), 1,
      sym_comment,
    ACTIONS(123), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(121), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [780] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(28), 1,
      sym_comment,
    ACTIONS(127), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(125), 5,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [798] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(29), 1,
      sym_comment,
    ACTIONS(119), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(117), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [815] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(30), 1,
      sym_comment,
    ACTIONS(83), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(81), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [832] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(31), 1,
      sym_comment,
    ACTIONS(129), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(131), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [849] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(32), 1,
      sym_comment,
    ACTIONS(91), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(89), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [866] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(33), 1,
      sym_comment,
    ACTIONS(95), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(93), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [883] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(34), 1,
      sym_comment,
    ACTIONS(127), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(125), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [900] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(35), 1,
      sym_comment,
    ACTIONS(133), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(135), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [917] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(36), 1,
      sym_comment,
    ACTIONS(115), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(113), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [934] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(37), 1,
      sym_comment,
    ACTIONS(103), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(101), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [951] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(38), 1,
      sym_comment,
    ACTIONS(99), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(97), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [968] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(39), 1,
      sym_comment,
    ACTIONS(123), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(121), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [985] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(40), 1,
      sym_comment,
    ACTIONS(111), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(109), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1002] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(41), 1,
      sym_comment,
    ACTIONS(107), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(105), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1019] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(42), 1,
      sym_comment,
    ACTIONS(71), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(69), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1036] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(43), 1,
      sym_comment,
    ACTIONS(67), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(65), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1053] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(44), 1,
      sym_comment,
    ACTIONS(87), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(85), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1070] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(45), 1,
      sym_comment,
    ACTIONS(75), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(73), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1087] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(46), 1,
      sym_comment,
    ACTIONS(79), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(77), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1104] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(139), 1,
      sym_attribute_name,
    STATE(47), 1,
      sym_comment,
    STATE(50), 1,
      aux_sym_start_tag_repeat1,
    STATE(68), 1,
      sym_attribute,
    ACTIONS(137), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [1124] = 5,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(143), 1,
      anon_sym_DASH_DASH_GT,
    STATE(48), 1,
      sym_comment,
    STATE(54), 1,
      aux_sym_comment_repeat1,
    ACTIONS(141), 3,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
  [1142] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(139), 1,
      sym_attribute_name,
    STATE(49), 1,
      sym_comment,
    STATE(50), 1,
      aux_sym_start_tag_repeat1,
    STATE(68), 1,
      sym_attribute,
    ACTIONS(145), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [1162] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(149), 1,
      sym_attribute_name,
    STATE(68), 1,
      sym_attribute,
    ACTIONS(147), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
    STATE(50), 2,
      sym_comment,
      aux_sym_start_tag_repeat1,
  [1180] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(139), 1,
      sym_attribute_name,
    STATE(49), 1,
      aux_sym_start_tag_repeat1,
    STATE(51), 1,
      sym_comment,
    STATE(68), 1,
      sym_attribute,
    ACTIONS(152), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [1200] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(139), 1,
      sym_attribute_name,
    STATE(47), 1,
      aux_sym_start_tag_repeat1,
    STATE(52), 1,
      sym_comment,
    STATE(68), 1,
      sym_attribute,
    ACTIONS(154), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [1220] = 5,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(156), 1,
      anon_sym_DASH_DASH_GT,
    STATE(48), 1,
      aux_sym_comment_repeat1,
    STATE(53), 1,
      sym_comment,
    ACTIONS(141), 3,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
  [1238] = 4,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(161), 1,
      anon_sym_DASH_DASH_GT,
    STATE(54), 2,
      sym_comment,
      aux_sym_comment_repeat1,
    ACTIONS(158), 3,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
  [1254] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(139), 1,
      sym_attribute_name,
    ACTIONS(163), 1,
      anon_sym_GT,
    STATE(50), 1,
      aux_sym_start_tag_repeat1,
    STATE(55), 1,
      sym_comment,
    STATE(68), 1,
      sym_attribute,
  [1273] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(139), 1,
      sym_attribute_name,
    ACTIONS(165), 1,
      anon_sym_GT,
    STATE(50), 1,
      aux_sym_start_tag_repeat1,
    STATE(56), 1,
      sym_comment,
    STATE(68), 1,
      sym_attribute,
  [1292] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(167), 1,
      sym_attribute_value,
    ACTIONS(169), 1,
      anon_sym_SQUOTE,
    ACTIONS(171), 1,
      anon_sym_DQUOTE,
    STATE(57), 1,
      sym_comment,
    STATE(65), 1,
      sym_quoted_attribute_value,
  [1311] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(139), 1,
      sym_attribute_name,
    ACTIONS(173), 1,
      anon_sym_GT,
    STATE(56), 1,
      aux_sym_start_tag_repeat1,
    STATE(58), 1,
      sym_comment,
    STATE(68), 1,
      sym_attribute,
  [1330] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(139), 1,
      sym_attribute_name,
    ACTIONS(175), 1,
      anon_sym_GT,
    STATE(59), 1,
      sym_comment,
    STATE(62), 1,
      aux_sym_start_tag_repeat1,
    STATE(68), 1,
      sym_attribute,
  [1349] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(139), 1,
      sym_attribute_name,
    ACTIONS(177), 1,
      anon_sym_GT,
    STATE(55), 1,
      aux_sym_start_tag_repeat1,
    STATE(60), 1,
      sym_comment,
    STATE(68), 1,
      sym_attribute,
  [1368] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(181), 1,
      anon_sym_EQ,
    STATE(61), 1,
      sym_comment,
    ACTIONS(179), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1383] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(139), 1,
      sym_attribute_name,
    ACTIONS(183), 1,
      anon_sym_GT,
    STATE(50), 1,
      aux_sym_start_tag_repeat1,
    STATE(62), 1,
      sym_comment,
    STATE(68), 1,
      sym_attribute,
  [1402] = 3,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(63), 1,
      sym_comment,
    ACTIONS(185), 4,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
      anon_sym_DASH_DASH_GT,
  [1415] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(64), 1,
      sym_comment,
    ACTIONS(187), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1427] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(65), 1,
      sym_comment,
    ACTIONS(189), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1439] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(66), 1,
      sym_comment,
    ACTIONS(191), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1451] = 5,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(193), 1,
      sym_raw_text,
    ACTIONS(195), 1,
      anon_sym_LT_SLASH,
    STATE(16), 1,
      sym_script_end_tag,
    STATE(67), 1,
      sym_comment,
  [1467] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(68), 1,
      sym_comment,
    ACTIONS(197), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1479] = 5,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(199), 1,
      sym_raw_text,
    ACTIONS(201), 1,
      anon_sym_LT_SLASH,
    STATE(46), 1,
      sym_script_end_tag,
    STATE(69), 1,
      sym_comment,
  [1495] = 5,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(203), 1,
      sym_raw_text,
    ACTIONS(205), 1,
      anon_sym_LT_SLASH,
    STATE(30), 1,
      sym_style_end_tag,
    STATE(70), 1,
      sym_comment,
  [1511] = 5,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(207), 1,
      sym_raw_text,
    ACTIONS(209), 1,
      anon_sym_LT_SLASH,
    STATE(17), 1,
      sym_style_end_tag,
    STATE(71), 1,
      sym_comment,
  [1527] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(72), 1,
      sym_comment,
    ACTIONS(211), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1539] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(73), 1,
      sym_comment,
    ACTIONS(213), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1550] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(215), 1,
      anon_sym_style,
    STATE(74), 1,
      sym_comment,
    STATE(104), 1,
      sym__style_start_tag_name,
  [1563] = 4,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(217), 1,
      sym_raw_text,
    ACTIONS(219), 1,
      anon_sym_LT_SLASH,
    STATE(75), 1,
      sym_comment,
  [1576] = 4,
    ACTIONS(23), 1,
      aux_sym_erroneous_end_tag_name_token1,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(76), 1,
      sym_comment,
    STATE(109), 1,
      sym_erroneous_end_tag_name,
  [1589] = 4,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(221), 1,
      sym_raw_text,
    ACTIONS(223), 1,
      anon_sym_LT_SLASH,
    STATE(77), 1,
      sym_comment,
  [1602] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(225), 1,
      anon_sym_LT_SLASH,
    STATE(26), 1,
      sym_script_end_tag,
    STATE(78), 1,
      sym_comment,
  [1615] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(227), 1,
      anon_sym_script,
    STATE(79), 1,
      sym_comment,
    STATE(101), 1,
      sym__script_start_tag_name,
  [1628] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(229), 1,
      anon_sym_LT_SLASH,
    STATE(25), 1,
      sym_style_end_tag,
    STATE(80), 1,
      sym_comment,
  [1641] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(215), 1,
      anon_sym_style,
    STATE(81), 1,
      sym_comment,
    STATE(108), 1,
      sym__style_start_tag_name,
  [1654] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(82), 1,
      sym_comment,
    ACTIONS(231), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1665] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(83), 1,
      sym_comment,
    ACTIONS(233), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1676] = 4,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(235), 1,
      anon_sym_SQUOTE,
    ACTIONS(237), 1,
      aux_sym_quoted_attribute_value_token1,
    STATE(84), 1,
      sym_comment,
  [1689] = 4,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(235), 1,
      anon_sym_DQUOTE,
    ACTIONS(239), 1,
      aux_sym_quoted_attribute_value_token2,
    STATE(85), 1,
      sym_comment,
  [1702] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(241), 1,
      anon_sym_LT_SLASH,
    STATE(29), 1,
      sym_script_end_tag,
    STATE(86), 1,
      sym_comment,
  [1715] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(243), 1,
      anon_sym_LT_SLASH,
    STATE(36), 1,
      sym_style_end_tag,
    STATE(87), 1,
      sym_comment,
  [1728] = 4,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(245), 1,
      sym_raw_text,
    ACTIONS(247), 1,
      anon_sym_LT_SLASH,
    STATE(88), 1,
      sym_comment,
  [1741] = 4,
    ACTIONS(23), 1,
      aux_sym_erroneous_end_tag_name_token1,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(89), 1,
      sym_comment,
    STATE(97), 1,
      sym_erroneous_end_tag_name,
  [1754] = 4,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(249), 1,
      sym_raw_text,
    ACTIONS(251), 1,
      anon_sym_LT_SLASH,
    STATE(90), 1,
      sym_comment,
  [1767] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(227), 1,
      anon_sym_script,
    STATE(91), 1,
      sym_comment,
    STATE(103), 1,
      sym__script_start_tag_name,
  [1780] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(253), 1,
      anon_sym_GT,
    STATE(92), 1,
      sym_comment,
  [1790] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(255), 1,
      anon_sym_GT,
    STATE(93), 1,
      sym_comment,
  [1800] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(257), 1,
      anon_sym_GT,
    STATE(94), 1,
      sym_comment,
  [1810] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(259), 1,
      sym__doctype,
    STATE(95), 1,
      sym_comment,
  [1820] = 3,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(261), 1,
      aux_sym_erroneous_end_tag_name_token1,
    STATE(96), 1,
      sym_comment,
  [1830] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(263), 1,
      anon_sym_GT,
    STATE(97), 1,
      sym_comment,
  [1840] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    STATE(98), 1,
      sym_comment,
  [1850] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(267), 1,
      ts_builtin_sym_end,
    STATE(99), 1,
      sym_comment,
  [1860] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(269), 1,
      anon_sym_GT,
    STATE(100), 1,
      sym_comment,
  [1870] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(271), 1,
      anon_sym_GT,
    STATE(101), 1,
      sym_comment,
  [1880] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(273), 1,
      anon_sym_GT,
    STATE(102), 1,
      sym_comment,
  [1890] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(275), 1,
      anon_sym_GT,
    STATE(103), 1,
      sym_comment,
  [1900] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(277), 1,
      anon_sym_GT,
    STATE(104), 1,
      sym_comment,
  [1910] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(265), 1,
      anon_sym_DQUOTE,
    STATE(105), 1,
      sym_comment,
  [1920] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(279), 1,
      anon_sym_GT,
    STATE(106), 1,
      sym_comment,
  [1930] = 3,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(281), 1,
      aux_sym_erroneous_end_tag_name_token1,
    STATE(107), 1,
      sym_comment,
  [1940] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(283), 1,
      anon_sym_GT,
    STATE(108), 1,
      sym_comment,
  [1950] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(285), 1,
      anon_sym_GT,
    STATE(109), 1,
      sym_comment,
  [1960] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(287), 1,
      sym__doctype,
    STATE(110), 1,
      sym_comment,
  [1970] = 1,
    ACTIONS(289), 1,
      ts_builtin_sym_end,
  [1974] = 1,
    ACTIONS(291), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 50,
  [SMALL_STATE(4)] = 100,
  [SMALL_STATE(5)] = 138,
  [SMALL_STATE(6)] = 176,
  [SMALL_STATE(7)] = 225,
  [SMALL_STATE(8)] = 272,
  [SMALL_STATE(9)] = 321,
  [SMALL_STATE(10)] = 370,
  [SMALL_STATE(11)] = 417,
  [SMALL_STATE(12)] = 466,
  [SMALL_STATE(13)] = 510,
  [SMALL_STATE(14)] = 528,
  [SMALL_STATE(15)] = 546,
  [SMALL_STATE(16)] = 564,
  [SMALL_STATE(17)] = 582,
  [SMALL_STATE(18)] = 600,
  [SMALL_STATE(19)] = 618,
  [SMALL_STATE(20)] = 636,
  [SMALL_STATE(21)] = 654,
  [SMALL_STATE(22)] = 672,
  [SMALL_STATE(23)] = 690,
  [SMALL_STATE(24)] = 708,
  [SMALL_STATE(25)] = 726,
  [SMALL_STATE(26)] = 744,
  [SMALL_STATE(27)] = 762,
  [SMALL_STATE(28)] = 780,
  [SMALL_STATE(29)] = 798,
  [SMALL_STATE(30)] = 815,
  [SMALL_STATE(31)] = 832,
  [SMALL_STATE(32)] = 849,
  [SMALL_STATE(33)] = 866,
  [SMALL_STATE(34)] = 883,
  [SMALL_STATE(35)] = 900,
  [SMALL_STATE(36)] = 917,
  [SMALL_STATE(37)] = 934,
  [SMALL_STATE(38)] = 951,
  [SMALL_STATE(39)] = 968,
  [SMALL_STATE(40)] = 985,
  [SMALL_STATE(41)] = 1002,
  [SMALL_STATE(42)] = 1019,
  [SMALL_STATE(43)] = 1036,
  [SMALL_STATE(44)] = 1053,
  [SMALL_STATE(45)] = 1070,
  [SMALL_STATE(46)] = 1087,
  [SMALL_STATE(47)] = 1104,
  [SMALL_STATE(48)] = 1124,
  [SMALL_STATE(49)] = 1142,
  [SMALL_STATE(50)] = 1162,
  [SMALL_STATE(51)] = 1180,
  [SMALL_STATE(52)] = 1200,
  [SMALL_STATE(53)] = 1220,
  [SMALL_STATE(54)] = 1238,
  [SMALL_STATE(55)] = 1254,
  [SMALL_STATE(56)] = 1273,
  [SMALL_STATE(57)] = 1292,
  [SMALL_STATE(58)] = 1311,
  [SMALL_STATE(59)] = 1330,
  [SMALL_STATE(60)] = 1349,
  [SMALL_STATE(61)] = 1368,
  [SMALL_STATE(62)] = 1383,
  [SMALL_STATE(63)] = 1402,
  [SMALL_STATE(64)] = 1415,
  [SMALL_STATE(65)] = 1427,
  [SMALL_STATE(66)] = 1439,
  [SMALL_STATE(67)] = 1451,
  [SMALL_STATE(68)] = 1467,
  [SMALL_STATE(69)] = 1479,
  [SMALL_STATE(70)] = 1495,
  [SMALL_STATE(71)] = 1511,
  [SMALL_STATE(72)] = 1527,
  [SMALL_STATE(73)] = 1539,
  [SMALL_STATE(74)] = 1550,
  [SMALL_STATE(75)] = 1563,
  [SMALL_STATE(76)] = 1576,
  [SMALL_STATE(77)] = 1589,
  [SMALL_STATE(78)] = 1602,
  [SMALL_STATE(79)] = 1615,
  [SMALL_STATE(80)] = 1628,
  [SMALL_STATE(81)] = 1641,
  [SMALL_STATE(82)] = 1654,
  [SMALL_STATE(83)] = 1665,
  [SMALL_STATE(84)] = 1676,
  [SMALL_STATE(85)] = 1689,
  [SMALL_STATE(86)] = 1702,
  [SMALL_STATE(87)] = 1715,
  [SMALL_STATE(88)] = 1728,
  [SMALL_STATE(89)] = 1741,
  [SMALL_STATE(90)] = 1754,
  [SMALL_STATE(91)] = 1767,
  [SMALL_STATE(92)] = 1780,
  [SMALL_STATE(93)] = 1790,
  [SMALL_STATE(94)] = 1800,
  [SMALL_STATE(95)] = 1810,
  [SMALL_STATE(96)] = 1820,
  [SMALL_STATE(97)] = 1830,
  [SMALL_STATE(98)] = 1840,
  [SMALL_STATE(99)] = 1850,
  [SMALL_STATE(100)] = 1860,
  [SMALL_STATE(101)] = 1870,
  [SMALL_STATE(102)] = 1880,
  [SMALL_STATE(103)] = 1890,
  [SMALL_STATE(104)] = 1900,
  [SMALL_STATE(105)] = 1910,
  [SMALL_STATE(106)] = 1920,
  [SMALL_STATE(107)] = 1930,
  [SMALL_STATE(108)] = 1940,
  [SMALL_STATE(109)] = 1950,
  [SMALL_STATE(110)] = 1960,
  [SMALL_STATE(111)] = 1970,
  [SMALL_STATE(112)] = 1974,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(110),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(95),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(76),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [53] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(110),
  [56] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(89),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(42),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 1, 0, 0),
  [67] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 1, 0, 0),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__node, 1, 0, 0),
  [71] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__node, 1, 0, 0),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 2, 0, 0),
  [75] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 2, 0, 0),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 2, 0, 0),
  [79] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 2, 0, 0),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 2, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 2, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 1, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 1, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 3, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 3, 0, 0),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_erroneous_end_tag, 3, 0, 0),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_erroneous_end_tag, 3, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 4, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 4, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doctype, 4, 0, 0),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_doctype, 4, 0, 0),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_end_tag, 3, 0, 0),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_end_tag, 3, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_end_tag, 3, 0, 0),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_end_tag, 3, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 3, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 3, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 3, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 3, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_end_tag, 3, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_end_tag, 3, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 3, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 3, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 3, 0, 1),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 3, 0, 1),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 4, 0, 1),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 4, 0, 1),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [141] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [143] = {.entry = {.count = 1, .reusable = false}}, SHIFT(111),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2, 0, 0),
  [149] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2, 0, 0), SHIFT_REPEAT(61),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [156] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [158] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(63),
  [161] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_comment_repeat1, 2, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [185] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_comment_repeat1, 1, 0, 0),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tags, 1, 0, 0),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3, 0, 0),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 3, 0, 0),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [195] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 1, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [201] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [205] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [209] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 2, 0, 0),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__start_tag_name, 1, 0, 0),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 4, 0, 0),
  [219] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_start_tag, 4, 0, 0),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 4, 0, 0),
  [223] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_start_tag, 4, 0, 0),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__script_start_tag_name, 1, 0, 0),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__style_start_tag_name, 1, 0, 0),
  [235] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [237] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [239] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [245] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 3, 0, 0),
  [247] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_start_tag, 3, 0, 0),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 3, 0, 0),
  [251] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_start_tag, 3, 0, 0),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [255] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__end_tag_name, 1, 0, 0),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_erroneous_end_tag_name, 1, 0, 0),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [261] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [267] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [281] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 3, 0, 0),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 2, 0, 0),
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
