#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 111
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 66
#define ALIAS_COUNT 0
#define TOKEN_COUNT 42
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 2

enum {
  anon_sym_nml = 1,
  anon_sym_title = 2,
  anon_sym_pre = 3,
  anon_sym_head = 4,
  anon_sym_body = 5,
  anon_sym_div = 6,
  anon_sym_p = 7,
  anon_sym_span = 8,
  anon_sym_ol = 9,
  anon_sym_ul = 10,
  anon_sym_li = 11,
  aux_sym__start_tag_name_token1 = 12,
  aux_sym__start_tag_name_token2 = 13,
  sym_raw_text = 14,
  sym__script_start_tag_name = 15,
  sym__style_start_tag_name = 16,
  aux_sym_erroneous_end_tag_name_token1 = 17,
  anon_sym_LT_BANG_DASH_DASH = 18,
  aux_sym_comment_token1 = 19,
  aux_sym_comment_token2 = 20,
  aux_sym_comment_token3 = 21,
  anon_sym_DASH_DASH_GT = 22,
  anon_sym_meta = 23,
  anon_sym_br = 24,
  anon_sym_hr = 25,
  anon_sym_bound = 26,
  anon_sym_LT_BANG = 27,
  anon_sym_GT = 28,
  sym__doctype = 29,
  anon_sym_LT = 30,
  anon_sym_LT_SLASH = 31,
  anon_sym_SLASH_GT = 32,
  anon_sym_EQ = 33,
  sym_attribute_name = 34,
  sym_attribute_value = 35,
  sym_entity = 36,
  anon_sym_SQUOTE = 37,
  aux_sym_quoted_attribute_value_token1 = 38,
  anon_sym_DQUOTE = 39,
  aux_sym_quoted_attribute_value_token2 = 40,
  sym_text = 41,
  sym_source_file = 42,
  sym__start_tag_name = 43,
  sym__end_tag_name = 44,
  sym_erroneous_end_tag_name = 45,
  sym_comment = 46,
  sym_self_closing_tags = 47,
  sym_doctype = 48,
  sym__node = 49,
  sym_element = 50,
  sym_script_element = 51,
  sym_style_element = 52,
  sym_start_tag = 53,
  sym_script_start_tag = 54,
  sym_script_end_tag = 55,
  sym_style_start_tag = 56,
  sym_style_end_tag = 57,
  sym_self_closing_tag = 58,
  sym_end_tag = 59,
  sym_erroneous_end_tag = 60,
  sym_attribute = 61,
  sym_quoted_attribute_value = 62,
  aux_sym_source_file_repeat1 = 63,
  aux_sym_comment_repeat1 = 64,
  aux_sym_start_tag_repeat1 = 65,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
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
  [anon_sym_li] = "li",
  [aux_sym__start_tag_name_token1] = "_start_tag_name_token1",
  [aux_sym__start_tag_name_token2] = "_start_tag_name_token2",
  [sym_raw_text] = "raw_text",
  [sym__script_start_tag_name] = "tag_name",
  [sym__style_start_tag_name] = "tag_name",
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
  [anon_sym_SQUOTE] = "'",
  [aux_sym_quoted_attribute_value_token1] = "attribute_value",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_quoted_attribute_value_token2] = "attribute_value",
  [sym_text] = "text",
  [sym_source_file] = "source_file",
  [sym__start_tag_name] = "_start_tag_name",
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
  [anon_sym_li] = anon_sym_li,
  [aux_sym__start_tag_name_token1] = aux_sym__start_tag_name_token1,
  [aux_sym__start_tag_name_token2] = aux_sym__start_tag_name_token2,
  [sym_raw_text] = sym_raw_text,
  [sym__script_start_tag_name] = sym__script_start_tag_name,
  [sym__style_start_tag_name] = sym__script_start_tag_name,
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
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_quoted_attribute_value_token1] = sym_attribute_value,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_quoted_attribute_value_token2] = sym_attribute_value,
  [sym_text] = sym_text,
  [sym_source_file] = sym_source_file,
  [sym__start_tag_name] = sym__start_tag_name,
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
  [anon_sym_li] = {
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
  [sym_raw_text] = {
    .visible = true,
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
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 7,
  [9] = 5,
  [10] = 10,
  [11] = 6,
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
  [29] = 22,
  [30] = 18,
  [31] = 31,
  [32] = 32,
  [33] = 32,
  [34] = 19,
  [35] = 20,
  [36] = 21,
  [37] = 13,
  [38] = 23,
  [39] = 26,
  [40] = 24,
  [41] = 41,
  [42] = 27,
  [43] = 28,
  [44] = 25,
  [45] = 14,
  [46] = 16,
  [47] = 17,
  [48] = 15,
  [49] = 49,
  [50] = 50,
  [51] = 31,
  [52] = 52,
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
  [67] = 66,
  [68] = 68,
  [69] = 68,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 75,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 80,
  [85] = 73,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 88,
  [96] = 96,
  [97] = 97,
  [98] = 87,
  [99] = 99,
  [100] = 86,
  [101] = 96,
  [102] = 97,
  [103] = 103,
  [104] = 103,
  [105] = 105,
  [106] = 90,
  [107] = 94,
  [108] = 99,
  [109] = 109,
  [110] = 110,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(96);
      if (lookahead == '"') ADVANCE(243);
      if (lookahead == '&') ADVANCE(5);
      if (lookahead == '\'') ADVANCE(237);
      if (lookahead == '-') ADVANCE(9);
      if (lookahead == '/') ADVANCE(51);
      if (lookahead == '<') ADVANCE(191);
      if (lookahead == '=') ADVANCE(194);
      if (lookahead == '>') ADVANCE(189);
      if (lookahead == 'D') ADVANCE(88);
      if (lookahead == 'b') ADVANCE(77);
      if (lookahead == 'd') ADVANCE(65);
      if (lookahead == 'h') ADVANCE(60);
      if (lookahead == 'l') ADVANCE(66);
      if (lookahead == 'm') ADVANCE(61);
      if (lookahead == 'n') ADVANCE(74);
      if (lookahead == 'o') ADVANCE(69);
      if (lookahead == 'p') ADVANCE(117);
      if (lookahead == 's') ADVANCE(56);
      if (lookahead == 't') ADVANCE(68);
      if (lookahead == 'u') ADVANCE(70);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == '!') ADVANCE(10);
      END_STATE();
    case 2:
      if (lookahead == '!') ADVANCE(10);
      if (lookahead == '/') ADVANCE(192);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(243);
      if (lookahead == '\'') ADVANCE(237);
      if (lookahead == '<') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (lookahead != 0 &&
          lookahead != '=' &&
          lookahead != '>') ADVANCE(196);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(243);
      if (lookahead == '<') ADVANCE(244);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(247);
      if (lookahead != 0) ADVANCE(248);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(91);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(236);
      END_STATE();
    case 6:
      if (lookahead == '&') ADVANCE(5);
      if (lookahead == '<') ADVANCE(191);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(249);
      END_STATE();
    case 7:
      if (lookahead == '\'') ADVANCE(237);
      if (lookahead == '<') ADVANCE(238);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(241);
      if (lookahead != 0) ADVANCE(242);
      END_STATE();
    case 8:
      if (lookahead == '-') ADVANCE(9);
      if (lookahead == '<') ADVANCE(175);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(176);
      if (lookahead != 0) ADVANCE(174);
      END_STATE();
    case 9:
      if (lookahead == '-') ADVANCE(52);
      if (lookahead != 0) ADVANCE(177);
      END_STATE();
    case 10:
      if (lookahead == '-') ADVANCE(11);
      END_STATE();
    case 11:
      if (lookahead == '-') ADVANCE(170);
      END_STATE();
    case 12:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'a') ADVANCE(16);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 13:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'a') ADVANCE(181);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 14:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'a') ADVANCE(34);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 15:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'c') ADVANCE(38);
      if (lookahead == 'p') ADVANCE(14);
      if (lookahead == 't') ADVANCE(44);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 16:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'd') ADVANCE(107);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 17:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'd') ADVANCE(187);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 18:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'd') ADVANCE(43);
      if (lookahead == 'u') ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 19:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'e') ADVANCE(12);
      if (lookahead == 'r') ADVANCE(185);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 20:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'e') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 21:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'e') ADVANCE(104);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 22:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'e') ADVANCE(140);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 23:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'e') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 24:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'i') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 25:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'i') ADVANCE(128);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 26:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'i') ADVANCE(37);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 27:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'i') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 28:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'l') ADVANCE(122);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 29:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'l') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 30:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'l') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 31:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'l') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 32:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'l') ADVANCE(23);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 33:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'm') ADVANCE(30);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 34:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'n') ADVANCE(119);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 35:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'n') ADVANCE(17);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 36:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'o') ADVANCE(18);
      if (lookahead == 'r') ADVANCE(183);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 37:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'p') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 38:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'r') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 39:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 't') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 40:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 't') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 41:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 't') ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 42:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'v') ADVANCE(113);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 43:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'y') ADVANCE(110);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 44:
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'y') ADVANCE(31);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 45:
      if (lookahead == '-') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 46:
      if (lookahead == '/') ADVANCE(51);
      if (lookahead == '<') ADVANCE(1);
      if (lookahead == '=') ADVANCE(194);
      if (lookahead == '>') ADVANCE(189);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(46)
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'') ADVANCE(195);
      END_STATE();
    case 47:
      if (lookahead == '<') ADVANCE(1);
      if (lookahead == 'b') ADVANCE(36);
      if (lookahead == 'd') ADVANCE(24);
      if (lookahead == 'h') ADVANCE(19);
      if (lookahead == 'l') ADVANCE(25);
      if (lookahead == 'm') ADVANCE(20);
      if (lookahead == 'n') ADVANCE(33);
      if (lookahead == 'o') ADVANCE(28);
      if (lookahead == 'p') ADVANCE(115);
      if (lookahead == 's') ADVANCE(15);
      if (lookahead == 't') ADVANCE(27);
      if (lookahead == 'u') ADVANCE(29);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(47)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 48:
      if (lookahead == '<') ADVANCE(141);
      if (lookahead == 'b') ADVANCE(158);
      if (lookahead == 'd') ADVANCE(149);
      if (lookahead == 'h') ADVANCE(146);
      if (lookahead == 'l') ADVANCE(150);
      if (lookahead == 'n') ADVANCE(156);
      if (lookahead == 'o') ADVANCE(152);
      if (lookahead == 'p') ADVANCE(116);
      if (lookahead == 's') ADVANCE(159);
      if (lookahead == 't') ADVANCE(151);
      if (lookahead == 'u') ADVANCE(153);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(166);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 49:
      if (lookahead == '<') ADVANCE(141);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(167);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 50:
      if (lookahead == '<') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(135);
      if (lookahead != 0) ADVANCE(136);
      END_STATE();
    case 51:
      if (lookahead == '>') ADVANCE(193);
      END_STATE();
    case 52:
      if (lookahead == '>') ADVANCE(179);
      if (lookahead != 0 &&
          lookahead != '-') ADVANCE(178);
      END_STATE();
    case 53:
      if (lookahead == 'a') ADVANCE(57);
      END_STATE();
    case 54:
      if (lookahead == 'a') ADVANCE(180);
      END_STATE();
    case 55:
      if (lookahead == 'a') ADVANCE(75);
      END_STATE();
    case 56:
      if (lookahead == 'c') ADVANCE(79);
      if (lookahead == 'p') ADVANCE(55);
      if (lookahead == 't') ADVANCE(85);
      END_STATE();
    case 57:
      if (lookahead == 'd') ADVANCE(106);
      END_STATE();
    case 58:
      if (lookahead == 'd') ADVANCE(186);
      END_STATE();
    case 59:
      if (lookahead == 'd') ADVANCE(84);
      if (lookahead == 'u') ADVANCE(76);
      END_STATE();
    case 60:
      if (lookahead == 'e') ADVANCE(53);
      if (lookahead == 'r') ADVANCE(184);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(130);
      END_STATE();
    case 61:
      if (lookahead == 'e') ADVANCE(81);
      END_STATE();
    case 62:
      if (lookahead == 'e') ADVANCE(103);
      END_STATE();
    case 63:
      if (lookahead == 'e') ADVANCE(139);
      END_STATE();
    case 64:
      if (lookahead == 'e') ADVANCE(100);
      END_STATE();
    case 65:
      if (lookahead == 'i') ADVANCE(83);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(86);
      END_STATE();
    case 66:
      if (lookahead == 'i') ADVANCE(127);
      END_STATE();
    case 67:
      if (lookahead == 'i') ADVANCE(78);
      END_STATE();
    case 68:
      if (lookahead == 'i') ADVANCE(82);
      END_STATE();
    case 69:
      if (lookahead == 'l') ADVANCE(121);
      END_STATE();
    case 70:
      if (lookahead == 'l') ADVANCE(124);
      END_STATE();
    case 71:
      if (lookahead == 'l') ADVANCE(97);
      END_STATE();
    case 72:
      if (lookahead == 'l') ADVANCE(63);
      END_STATE();
    case 73:
      if (lookahead == 'l') ADVANCE(64);
      END_STATE();
    case 74:
      if (lookahead == 'm') ADVANCE(71);
      END_STATE();
    case 75:
      if (lookahead == 'n') ADVANCE(118);
      END_STATE();
    case 76:
      if (lookahead == 'n') ADVANCE(58);
      END_STATE();
    case 77:
      if (lookahead == 'o') ADVANCE(59);
      if (lookahead == 'r') ADVANCE(182);
      END_STATE();
    case 78:
      if (lookahead == 'p') ADVANCE(80);
      END_STATE();
    case 79:
      if (lookahead == 'r') ADVANCE(67);
      END_STATE();
    case 80:
      if (lookahead == 't') ADVANCE(137);
      END_STATE();
    case 81:
      if (lookahead == 't') ADVANCE(54);
      END_STATE();
    case 82:
      if (lookahead == 't') ADVANCE(73);
      END_STATE();
    case 83:
      if (lookahead == 'v') ADVANCE(112);
      END_STATE();
    case 84:
      if (lookahead == 'y') ADVANCE(109);
      END_STATE();
    case 85:
      if (lookahead == 'y') ADVANCE(72);
      END_STATE();
    case 86:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(90);
      END_STATE();
    case 87:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(190);
      END_STATE();
    case 88:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(86);
      END_STATE();
    case 89:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(87);
      END_STATE();
    case 90:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(92);
      END_STATE();
    case 91:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(93);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(202);
      END_STATE();
    case 92:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(89);
      END_STATE();
    case 93:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(207);
      END_STATE();
    case 94:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 95:
      if (eof) ADVANCE(96);
      if (lookahead == '&') ADVANCE(5);
      if (lookahead == '<') ADVANCE(191);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(249);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_nml);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_nml);
      if (lookahead == '-') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_nml);
      if (lookahead == '-') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_title);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_title);
      if (lookahead == '-') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_title);
      if (lookahead == '-') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_pre);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_pre);
      if (lookahead == '-') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_pre);
      if (lookahead == '-') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_head);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_head);
      if (lookahead == '-') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_head);
      if (lookahead == '-') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_body);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_body);
      if (lookahead == '-') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_body);
      if (lookahead == '-') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_div);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_div);
      if (lookahead == '-') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_div);
      if (lookahead == '-') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_p);
      if (lookahead == '-') ADVANCE(94);
      if (lookahead == 'r') ADVANCE(21);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_p);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'r') ADVANCE(147);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_p);
      if (lookahead == 'r') ADVANCE(62);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_span);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_span);
      if (lookahead == '-') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_span);
      if (lookahead == '-') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_ol);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_ol);
      if (lookahead == '-') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_ol);
      if (lookahead == '-') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_ul);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_ul);
      if (lookahead == '-') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_ul);
      if (lookahead == '-') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_li);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_li);
      if (lookahead == '-') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_li);
      if (lookahead == '-') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token1);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token1);
      if (lookahead == '-') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_raw_text);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(135);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(136);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_raw_text);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(136);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym__script_start_tag_name);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym__script_start_tag_name);
      if (lookahead == '-') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym__style_start_tag_name);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym__style_start_tag_name);
      if (lookahead == '-') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '!') ADVANCE(165);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'a') ADVANCE(157);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'a') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'd') ADVANCE(162);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'd') ADVANCE(108);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'e') ADVANCE(143);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'e') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'e') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'i') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'i') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'i') ADVANCE(160);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'l') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'l') ADVANCE(126);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'l') ADVANCE(99);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'l') ADVANCE(148);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'm') ADVANCE(154);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'n') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'o') ADVANCE(144);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'p') ADVANCE(142);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 't') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'v') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == 'y') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(173);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(164);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '<') ADVANCE(141);
      if (lookahead == 'b') ADVANCE(158);
      if (lookahead == 'd') ADVANCE(149);
      if (lookahead == 'h') ADVANCE(146);
      if (lookahead == 'l') ADVANCE(150);
      if (lookahead == 'n') ADVANCE(156);
      if (lookahead == 'o') ADVANCE(152);
      if (lookahead == 'p') ADVANCE(116);
      if (lookahead == 's') ADVANCE(159);
      if (lookahead == 't') ADVANCE(151);
      if (lookahead == 'u') ADVANCE(153);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(166);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '<') ADVANCE(141);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(167);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(248);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(242);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(169);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '!') ADVANCE(10);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '<') ADVANCE(175);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(176);
      if (lookahead != 0 &&
          lookahead != '-') ADVANCE(174);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_comment_token2);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_comment_token3);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(anon_sym_DASH_DASH_GT);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(anon_sym_meta);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(anon_sym_meta);
      if (lookahead == '-') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(anon_sym_br);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(anon_sym_br);
      if (lookahead == '-') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(anon_sym_hr);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(anon_sym_hr);
      if (lookahead == '-') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(anon_sym_bound);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(anon_sym_bound);
      if (lookahead == '-') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(anon_sym_LT_BANG);
      if (lookahead == '-') ADVANCE(11);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym__doctype);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '!') ADVANCE(188);
      if (lookahead == '/') ADVANCE(192);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(anon_sym_LT_SLASH);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(anon_sym_SLASH_GT);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(195);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_attribute_value);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(196);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_entity);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(198);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(199);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(200);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(201);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(198);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(203);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(204);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(205);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(206);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(198);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(209);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(210);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(212);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(213);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(214);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(216);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(218);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(220);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(221);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(222);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(223);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(224);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(225);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(226);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(227);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(229);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(230);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(231);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(233);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(234);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(235);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '!') ADVANCE(240);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(242);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '-') ADVANCE(172);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(242);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '-') ADVANCE(239);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(242);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '<') ADVANCE(238);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(241);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(242);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(242);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '!') ADVANCE(246);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(248);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '-') ADVANCE(171);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(248);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '-') ADVANCE(245);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(248);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '<') ADVANCE(244);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(247);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(248);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(248);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_text);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(249);
      if (lookahead != 0 &&
          lookahead != '&' &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(249);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 95},
  [2] = {.lex_state = 47},
  [3] = {.lex_state = 47},
  [4] = {.lex_state = 95},
  [5] = {.lex_state = 48},
  [6] = {.lex_state = 95},
  [7] = {.lex_state = 95},
  [8] = {.lex_state = 95},
  [9] = {.lex_state = 48},
  [10] = {.lex_state = 95},
  [11] = {.lex_state = 95},
  [12] = {.lex_state = 95},
  [13] = {.lex_state = 95},
  [14] = {.lex_state = 95},
  [15] = {.lex_state = 95},
  [16] = {.lex_state = 95},
  [17] = {.lex_state = 95},
  [18] = {.lex_state = 95},
  [19] = {.lex_state = 95},
  [20] = {.lex_state = 95},
  [21] = {.lex_state = 95},
  [22] = {.lex_state = 95},
  [23] = {.lex_state = 95},
  [24] = {.lex_state = 95},
  [25] = {.lex_state = 95},
  [26] = {.lex_state = 95},
  [27] = {.lex_state = 95},
  [28] = {.lex_state = 95},
  [29] = {.lex_state = 95},
  [30] = {.lex_state = 95},
  [31] = {.lex_state = 46},
  [32] = {.lex_state = 46},
  [33] = {.lex_state = 46},
  [34] = {.lex_state = 95},
  [35] = {.lex_state = 95},
  [36] = {.lex_state = 95},
  [37] = {.lex_state = 95},
  [38] = {.lex_state = 95},
  [39] = {.lex_state = 95},
  [40] = {.lex_state = 95},
  [41] = {.lex_state = 8},
  [42] = {.lex_state = 95},
  [43] = {.lex_state = 95},
  [44] = {.lex_state = 95},
  [45] = {.lex_state = 95},
  [46] = {.lex_state = 95},
  [47] = {.lex_state = 95},
  [48] = {.lex_state = 95},
  [49] = {.lex_state = 95},
  [50] = {.lex_state = 8},
  [51] = {.lex_state = 46},
  [52] = {.lex_state = 95},
  [53] = {.lex_state = 46},
  [54] = {.lex_state = 8},
  [55] = {.lex_state = 3},
  [56] = {.lex_state = 8},
  [57] = {.lex_state = 46},
  [58] = {.lex_state = 46},
  [59] = {.lex_state = 46},
  [60] = {.lex_state = 46},
  [61] = {.lex_state = 46},
  [62] = {.lex_state = 46},
  [63] = {.lex_state = 46},
  [64] = {.lex_state = 46},
  [65] = {.lex_state = 46},
  [66] = {.lex_state = 50},
  [67] = {.lex_state = 50},
  [68] = {.lex_state = 50},
  [69] = {.lex_state = 50},
  [70] = {.lex_state = 46},
  [71] = {.lex_state = 46},
  [72] = {.lex_state = 46},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 7},
  [75] = {.lex_state = 49},
  [76] = {.lex_state = 49},
  [77] = {.lex_state = 50},
  [78] = {.lex_state = 50},
  [79] = {.lex_state = 50},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 50},
  [82] = {.lex_state = 46},
  [83] = {.lex_state = 4},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 49},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 49},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {(TSStateId)(-1)},
  [110] = {(TSStateId)(-1)},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [sym_comment] = STATE(0),
    [ts_builtin_sym_end] = ACTIONS(1),
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
    [anon_sym_li] = ACTIONS(1),
    [aux_sym__start_tag_name_token1] = ACTIONS(1),
    [sym__script_start_tag_name] = ACTIONS(1),
    [sym__style_start_tag_name] = ACTIONS(1),
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
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(91),
    [sym_comment] = STATE(1),
    [sym_doctype] = STATE(15),
    [sym__node] = STATE(17),
    [sym_element] = STATE(15),
    [sym_script_element] = STATE(15),
    [sym_style_element] = STATE(15),
    [sym_start_tag] = STATE(8),
    [sym_script_start_tag] = STATE(69),
    [sym_style_start_tag] = STATE(66),
    [sym_self_closing_tag] = STATE(16),
    [sym_erroneous_end_tag] = STATE(15),
    [aux_sym_source_file_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_LT_BANG_DASH_DASH] = ACTIONS(3),
    [anon_sym_LT_BANG] = ACTIONS(7),
    [anon_sym_LT] = ACTIONS(9),
    [anon_sym_LT_SLASH] = ACTIONS(11),
    [sym_entity] = ACTIONS(13),
    [sym_text] = ACTIONS(13),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(17), 1,
      aux_sym__start_tag_name_token2,
    ACTIONS(19), 1,
      sym__script_start_tag_name,
    ACTIONS(21), 1,
      sym__style_start_tag_name,
    STATE(2), 1,
      sym_comment,
    STATE(32), 1,
      sym_self_closing_tags,
    STATE(57), 1,
      sym__start_tag_name,
    ACTIONS(23), 4,
      anon_sym_meta,
      anon_sym_br,
      anon_sym_hr,
      anon_sym_bound,
    ACTIONS(15), 12,
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
      anon_sym_li,
      aux_sym__start_tag_name_token1,
  [42] = 9,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(17), 1,
      aux_sym__start_tag_name_token2,
    ACTIONS(19), 1,
      sym__script_start_tag_name,
    ACTIONS(21), 1,
      sym__style_start_tag_name,
    STATE(3), 1,
      sym_comment,
    STATE(33), 1,
      sym_self_closing_tags,
    STATE(57), 1,
      sym__start_tag_name,
    ACTIONS(23), 4,
      anon_sym_meta,
      anon_sym_br,
      anon_sym_hr,
      anon_sym_bound,
    ACTIONS(15), 12,
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
      anon_sym_li,
      aux_sym__start_tag_name_token1,
  [84] = 14,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      anon_sym_LT,
    ACTIONS(11), 1,
      anon_sym_LT_SLASH,
    ACTIONS(25), 1,
      ts_builtin_sym_end,
    STATE(4), 1,
      sym_comment,
    STATE(8), 1,
      sym_start_tag,
    STATE(10), 1,
      aux_sym_source_file_repeat1,
    STATE(16), 1,
      sym_self_closing_tag,
    STATE(17), 1,
      sym__node,
    STATE(66), 1,
      sym_style_start_tag,
    STATE(69), 1,
      sym_script_start_tag,
    ACTIONS(13), 2,
      sym_entity,
      sym_text,
    STATE(15), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [132] = 7,
    ACTIONS(27), 1,
      aux_sym_erroneous_end_tag_name_token1,
    ACTIONS(29), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(5), 1,
      sym_comment,
    STATE(93), 1,
      sym__start_tag_name,
    STATE(95), 1,
      sym_erroneous_end_tag_name,
    STATE(101), 1,
      sym__end_tag_name,
    ACTIONS(15), 13,
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
      anon_sym_li,
      aux_sym__start_tag_name_token1,
      aux_sym__start_tag_name_token2,
  [166] = 14,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(31), 1,
      anon_sym_LT_BANG,
    ACTIONS(33), 1,
      anon_sym_LT,
    ACTIONS(35), 1,
      anon_sym_LT_SLASH,
    STATE(6), 1,
      sym_comment,
    STATE(7), 1,
      sym_start_tag,
    STATE(12), 1,
      aux_sym_source_file_repeat1,
    STATE(39), 1,
      sym_end_tag,
    STATE(46), 1,
      sym_self_closing_tag,
    STATE(47), 1,
      sym__node,
    STATE(67), 1,
      sym_style_start_tag,
    STATE(68), 1,
      sym_script_start_tag,
    ACTIONS(37), 2,
      sym_entity,
      sym_text,
    STATE(48), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [214] = 13,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(31), 1,
      anon_sym_LT_BANG,
    ACTIONS(33), 1,
      anon_sym_LT,
    ACTIONS(35), 1,
      anon_sym_LT_SLASH,
    STATE(6), 1,
      aux_sym_source_file_repeat1,
    STATE(45), 1,
      sym_end_tag,
    STATE(46), 1,
      sym_self_closing_tag,
    STATE(47), 1,
      sym__node,
    STATE(67), 1,
      sym_style_start_tag,
    STATE(68), 1,
      sym_script_start_tag,
    ACTIONS(37), 2,
      sym_entity,
      sym_text,
    STATE(7), 2,
      sym_comment,
      sym_start_tag,
    STATE(48), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [260] = 14,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(31), 1,
      anon_sym_LT_BANG,
    ACTIONS(33), 1,
      anon_sym_LT,
    ACTIONS(39), 1,
      anon_sym_LT_SLASH,
    STATE(7), 1,
      sym_start_tag,
    STATE(8), 1,
      sym_comment,
    STATE(11), 1,
      aux_sym_source_file_repeat1,
    STATE(14), 1,
      sym_end_tag,
    STATE(46), 1,
      sym_self_closing_tag,
    STATE(47), 1,
      sym__node,
    STATE(67), 1,
      sym_style_start_tag,
    STATE(68), 1,
      sym_script_start_tag,
    ACTIONS(37), 2,
      sym_entity,
      sym_text,
    STATE(48), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [308] = 7,
    ACTIONS(27), 1,
      aux_sym_erroneous_end_tag_name_token1,
    ACTIONS(29), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(9), 1,
      sym_comment,
    STATE(93), 1,
      sym__start_tag_name,
    STATE(95), 1,
      sym_erroneous_end_tag_name,
    STATE(96), 1,
      sym__end_tag_name,
    ACTIONS(15), 13,
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
      anon_sym_li,
      aux_sym__start_tag_name_token1,
      aux_sym__start_tag_name_token2,
  [342] = 13,
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
    STATE(8), 1,
      sym_start_tag,
    STATE(16), 1,
      sym_self_closing_tag,
    STATE(17), 1,
      sym__node,
    STATE(66), 1,
      sym_style_start_tag,
    STATE(69), 1,
      sym_script_start_tag,
    ACTIONS(52), 2,
      sym_entity,
      sym_text,
    STATE(10), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(15), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [388] = 14,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(31), 1,
      anon_sym_LT_BANG,
    ACTIONS(33), 1,
      anon_sym_LT,
    ACTIONS(39), 1,
      anon_sym_LT_SLASH,
    STATE(7), 1,
      sym_start_tag,
    STATE(11), 1,
      sym_comment,
    STATE(12), 1,
      aux_sym_source_file_repeat1,
    STATE(26), 1,
      sym_end_tag,
    STATE(46), 1,
      sym_self_closing_tag,
    STATE(47), 1,
      sym__node,
    STATE(67), 1,
      sym_style_start_tag,
    STATE(68), 1,
      sym_script_start_tag,
    ACTIONS(37), 2,
      sym_entity,
      sym_text,
    STATE(48), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [436] = 12,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(55), 1,
      anon_sym_LT_BANG,
    ACTIONS(58), 1,
      anon_sym_LT,
    ACTIONS(61), 1,
      anon_sym_LT_SLASH,
    STATE(7), 1,
      sym_start_tag,
    STATE(46), 1,
      sym_self_closing_tag,
    STATE(47), 1,
      sym__node,
    STATE(67), 1,
      sym_style_start_tag,
    STATE(68), 1,
      sym_script_start_tag,
    ACTIONS(64), 2,
      sym_entity,
      sym_text,
    STATE(12), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(48), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [479] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(13), 1,
      sym_comment,
    ACTIONS(69), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(67), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [496] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(14), 1,
      sym_comment,
    ACTIONS(73), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(71), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [513] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(15), 1,
      sym_comment,
    ACTIONS(77), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(75), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [530] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(16), 1,
      sym_comment,
    ACTIONS(81), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(79), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [547] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(17), 1,
      sym_comment,
    ACTIONS(85), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(83), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [564] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(18), 1,
      sym_comment,
    ACTIONS(89), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(87), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [581] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(19), 1,
      sym_comment,
    ACTIONS(93), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(91), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [598] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(20), 1,
      sym_comment,
    ACTIONS(97), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(95), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [615] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(21), 1,
      sym_comment,
    ACTIONS(101), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(99), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [632] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(22), 1,
      sym_comment,
    ACTIONS(105), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(103), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [649] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(23), 1,
      sym_comment,
    ACTIONS(109), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(107), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [666] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(24), 1,
      sym_comment,
    ACTIONS(113), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(111), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [683] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(25), 1,
      sym_comment,
    ACTIONS(117), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(115), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [700] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(26), 1,
      sym_comment,
    ACTIONS(121), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(119), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [717] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(27), 1,
      sym_comment,
    ACTIONS(125), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(123), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [734] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(28), 1,
      sym_comment,
    ACTIONS(129), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(127), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [751] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(29), 1,
      sym_comment,
    ACTIONS(105), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(103), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [767] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(30), 1,
      sym_comment,
    ACTIONS(89), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(87), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [783] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(133), 1,
      sym_attribute_name,
    STATE(31), 1,
      sym_comment,
    STATE(53), 1,
      aux_sym_start_tag_repeat1,
    STATE(72), 1,
      sym_attribute,
    ACTIONS(131), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [803] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(133), 1,
      sym_attribute_name,
    STATE(31), 1,
      aux_sym_start_tag_repeat1,
    STATE(32), 1,
      sym_comment,
    STATE(72), 1,
      sym_attribute,
    ACTIONS(135), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [823] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(133), 1,
      sym_attribute_name,
    STATE(33), 1,
      sym_comment,
    STATE(51), 1,
      aux_sym_start_tag_repeat1,
    STATE(72), 1,
      sym_attribute,
    ACTIONS(137), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [843] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(34), 1,
      sym_comment,
    ACTIONS(93), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(91), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [859] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(35), 1,
      sym_comment,
    ACTIONS(97), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(95), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [875] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(36), 1,
      sym_comment,
    ACTIONS(101), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(99), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [891] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(37), 1,
      sym_comment,
    ACTIONS(69), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(67), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [907] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(38), 1,
      sym_comment,
    ACTIONS(109), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(107), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [923] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(39), 1,
      sym_comment,
    ACTIONS(121), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(119), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [939] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(40), 1,
      sym_comment,
    ACTIONS(113), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(111), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [955] = 4,
    ACTIONS(29), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(142), 1,
      anon_sym_DASH_DASH_GT,
    STATE(41), 2,
      sym_comment,
      aux_sym_comment_repeat1,
    ACTIONS(139), 3,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
  [971] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(42), 1,
      sym_comment,
    ACTIONS(125), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(123), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [987] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(43), 1,
      sym_comment,
    ACTIONS(129), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(127), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [1003] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(44), 1,
      sym_comment,
    ACTIONS(117), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(115), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [1019] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(45), 1,
      sym_comment,
    ACTIONS(73), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(71), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [1035] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(46), 1,
      sym_comment,
    ACTIONS(81), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(79), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [1051] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(47), 1,
      sym_comment,
    ACTIONS(85), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(83), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [1067] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(48), 1,
      sym_comment,
    ACTIONS(77), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(75), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [1083] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(49), 1,
      sym_comment,
    ACTIONS(144), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(146), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [1099] = 5,
    ACTIONS(29), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(150), 1,
      anon_sym_DASH_DASH_GT,
    STATE(41), 1,
      aux_sym_comment_repeat1,
    STATE(50), 1,
      sym_comment,
    ACTIONS(148), 3,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
  [1117] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(133), 1,
      sym_attribute_name,
    STATE(51), 1,
      sym_comment,
    STATE(53), 1,
      aux_sym_start_tag_repeat1,
    STATE(72), 1,
      sym_attribute,
    ACTIONS(152), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [1137] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(52), 1,
      sym_comment,
    ACTIONS(154), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(156), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [1153] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(160), 1,
      sym_attribute_name,
    STATE(72), 1,
      sym_attribute,
    ACTIONS(158), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
    STATE(53), 2,
      sym_comment,
      aux_sym_start_tag_repeat1,
  [1171] = 5,
    ACTIONS(29), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(163), 1,
      anon_sym_DASH_DASH_GT,
    STATE(50), 1,
      aux_sym_comment_repeat1,
    STATE(54), 1,
      sym_comment,
    ACTIONS(148), 3,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
  [1189] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(165), 1,
      sym_attribute_value,
    ACTIONS(167), 1,
      anon_sym_SQUOTE,
    ACTIONS(169), 1,
      anon_sym_DQUOTE,
    STATE(55), 1,
      sym_comment,
    STATE(70), 1,
      sym_quoted_attribute_value,
  [1208] = 3,
    ACTIONS(29), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(56), 1,
      sym_comment,
    ACTIONS(171), 4,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
      anon_sym_DASH_DASH_GT,
  [1221] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(133), 1,
      sym_attribute_name,
    ACTIONS(173), 1,
      anon_sym_GT,
    STATE(57), 1,
      sym_comment,
    STATE(60), 1,
      aux_sym_start_tag_repeat1,
    STATE(72), 1,
      sym_attribute,
  [1240] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(133), 1,
      sym_attribute_name,
    ACTIONS(175), 1,
      anon_sym_GT,
    STATE(58), 1,
      sym_comment,
    STATE(63), 1,
      aux_sym_start_tag_repeat1,
    STATE(72), 1,
      sym_attribute,
  [1259] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(133), 1,
      sym_attribute_name,
    ACTIONS(177), 1,
      anon_sym_GT,
    STATE(59), 1,
      sym_comment,
    STATE(62), 1,
      aux_sym_start_tag_repeat1,
    STATE(72), 1,
      sym_attribute,
  [1278] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(133), 1,
      sym_attribute_name,
    ACTIONS(179), 1,
      anon_sym_GT,
    STATE(53), 1,
      aux_sym_start_tag_repeat1,
    STATE(60), 1,
      sym_comment,
    STATE(72), 1,
      sym_attribute,
  [1297] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(183), 1,
      anon_sym_EQ,
    STATE(61), 1,
      sym_comment,
    ACTIONS(181), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1312] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(133), 1,
      sym_attribute_name,
    ACTIONS(185), 1,
      anon_sym_GT,
    STATE(53), 1,
      aux_sym_start_tag_repeat1,
    STATE(62), 1,
      sym_comment,
    STATE(72), 1,
      sym_attribute,
  [1331] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(133), 1,
      sym_attribute_name,
    ACTIONS(187), 1,
      anon_sym_GT,
    STATE(53), 1,
      aux_sym_start_tag_repeat1,
    STATE(63), 1,
      sym_comment,
    STATE(72), 1,
      sym_attribute,
  [1350] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(64), 1,
      sym_comment,
    ACTIONS(189), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1362] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(65), 1,
      sym_comment,
    ACTIONS(191), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1374] = 5,
    ACTIONS(29), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(193), 1,
      sym_raw_text,
    ACTIONS(195), 1,
      anon_sym_LT_SLASH,
    STATE(28), 1,
      sym_style_end_tag,
    STATE(66), 1,
      sym_comment,
  [1390] = 5,
    ACTIONS(29), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(197), 1,
      sym_raw_text,
    ACTIONS(199), 1,
      anon_sym_LT_SLASH,
    STATE(43), 1,
      sym_style_end_tag,
    STATE(67), 1,
      sym_comment,
  [1406] = 5,
    ACTIONS(29), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(201), 1,
      sym_raw_text,
    ACTIONS(203), 1,
      anon_sym_LT_SLASH,
    STATE(44), 1,
      sym_script_end_tag,
    STATE(68), 1,
      sym_comment,
  [1422] = 5,
    ACTIONS(29), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(205), 1,
      sym_raw_text,
    ACTIONS(207), 1,
      anon_sym_LT_SLASH,
    STATE(25), 1,
      sym_script_end_tag,
    STATE(69), 1,
      sym_comment,
  [1438] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(70), 1,
      sym_comment,
    ACTIONS(209), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1450] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(71), 1,
      sym_comment,
    ACTIONS(211), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1462] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(72), 1,
      sym_comment,
    ACTIONS(213), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1474] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(215), 1,
      anon_sym_LT_SLASH,
    STATE(38), 1,
      sym_script_end_tag,
    STATE(73), 1,
      sym_comment,
  [1487] = 4,
    ACTIONS(29), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(217), 1,
      anon_sym_SQUOTE,
    ACTIONS(219), 1,
      aux_sym_quoted_attribute_value_token1,
    STATE(74), 1,
      sym_comment,
  [1500] = 4,
    ACTIONS(27), 1,
      aux_sym_erroneous_end_tag_name_token1,
    ACTIONS(29), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(75), 1,
      sym_comment,
    STATE(95), 1,
      sym_erroneous_end_tag_name,
  [1513] = 4,
    ACTIONS(27), 1,
      aux_sym_erroneous_end_tag_name_token1,
    ACTIONS(29), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(76), 1,
      sym_comment,
    STATE(88), 1,
      sym_erroneous_end_tag_name,
  [1526] = 4,
    ACTIONS(29), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(221), 1,
      sym_raw_text,
    ACTIONS(223), 1,
      anon_sym_LT_SLASH,
    STATE(77), 1,
      sym_comment,
  [1539] = 4,
    ACTIONS(29), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(225), 1,
      sym_raw_text,
    ACTIONS(227), 1,
      anon_sym_LT_SLASH,
    STATE(78), 1,
      sym_comment,
  [1552] = 4,
    ACTIONS(29), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(229), 1,
      sym_raw_text,
    ACTIONS(231), 1,
      anon_sym_LT_SLASH,
    STATE(79), 1,
      sym_comment,
  [1565] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(233), 1,
      anon_sym_LT_SLASH,
    STATE(37), 1,
      sym_style_end_tag,
    STATE(80), 1,
      sym_comment,
  [1578] = 4,
    ACTIONS(29), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(235), 1,
      sym_raw_text,
    ACTIONS(237), 1,
      anon_sym_LT_SLASH,
    STATE(81), 1,
      sym_comment,
  [1591] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(82), 1,
      sym_comment,
    ACTIONS(239), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1602] = 4,
    ACTIONS(29), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(217), 1,
      anon_sym_DQUOTE,
    ACTIONS(241), 1,
      aux_sym_quoted_attribute_value_token2,
    STATE(83), 1,
      sym_comment,
  [1615] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(243), 1,
      anon_sym_LT_SLASH,
    STATE(13), 1,
      sym_style_end_tag,
    STATE(84), 1,
      sym_comment,
  [1628] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(245), 1,
      anon_sym_LT_SLASH,
    STATE(23), 1,
      sym_script_end_tag,
    STATE(85), 1,
      sym_comment,
  [1641] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(247), 1,
      sym__style_start_tag_name,
    STATE(86), 1,
      sym_comment,
  [1651] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(249), 1,
      anon_sym_GT,
    STATE(87), 1,
      sym_comment,
  [1661] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(251), 1,
      anon_sym_GT,
    STATE(88), 1,
      sym_comment,
  [1671] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(253), 1,
      anon_sym_GT,
    STATE(89), 1,
      sym_comment,
  [1681] = 3,
    ACTIONS(29), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(255), 1,
      aux_sym_erroneous_end_tag_name_token1,
    STATE(90), 1,
      sym_comment,
  [1691] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(257), 1,
      ts_builtin_sym_end,
    STATE(91), 1,
      sym_comment,
  [1701] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(259), 1,
      anon_sym_SQUOTE,
    STATE(92), 1,
      sym_comment,
  [1711] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(261), 1,
      anon_sym_GT,
    STATE(93), 1,
      sym_comment,
  [1721] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(263), 1,
      sym__doctype,
    STATE(94), 1,
      sym_comment,
  [1731] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(265), 1,
      anon_sym_GT,
    STATE(95), 1,
      sym_comment,
  [1741] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(267), 1,
      anon_sym_GT,
    STATE(96), 1,
      sym_comment,
  [1751] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(269), 1,
      anon_sym_GT,
    STATE(97), 1,
      sym_comment,
  [1761] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(271), 1,
      anon_sym_GT,
    STATE(98), 1,
      sym_comment,
  [1771] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(273), 1,
      sym__script_start_tag_name,
    STATE(99), 1,
      sym_comment,
  [1781] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(275), 1,
      sym__style_start_tag_name,
    STATE(100), 1,
      sym_comment,
  [1791] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(277), 1,
      anon_sym_GT,
    STATE(101), 1,
      sym_comment,
  [1801] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(279), 1,
      anon_sym_GT,
    STATE(102), 1,
      sym_comment,
  [1811] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(281), 1,
      anon_sym_GT,
    STATE(103), 1,
      sym_comment,
  [1821] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(283), 1,
      anon_sym_GT,
    STATE(104), 1,
      sym_comment,
  [1831] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(259), 1,
      anon_sym_DQUOTE,
    STATE(105), 1,
      sym_comment,
  [1841] = 3,
    ACTIONS(29), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(285), 1,
      aux_sym_erroneous_end_tag_name_token1,
    STATE(106), 1,
      sym_comment,
  [1851] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(287), 1,
      sym__doctype,
    STATE(107), 1,
      sym_comment,
  [1861] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(289), 1,
      sym__script_start_tag_name,
    STATE(108), 1,
      sym_comment,
  [1871] = 1,
    ACTIONS(291), 1,
      ts_builtin_sym_end,
  [1875] = 1,
    ACTIONS(293), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 42,
  [SMALL_STATE(4)] = 84,
  [SMALL_STATE(5)] = 132,
  [SMALL_STATE(6)] = 166,
  [SMALL_STATE(7)] = 214,
  [SMALL_STATE(8)] = 260,
  [SMALL_STATE(9)] = 308,
  [SMALL_STATE(10)] = 342,
  [SMALL_STATE(11)] = 388,
  [SMALL_STATE(12)] = 436,
  [SMALL_STATE(13)] = 479,
  [SMALL_STATE(14)] = 496,
  [SMALL_STATE(15)] = 513,
  [SMALL_STATE(16)] = 530,
  [SMALL_STATE(17)] = 547,
  [SMALL_STATE(18)] = 564,
  [SMALL_STATE(19)] = 581,
  [SMALL_STATE(20)] = 598,
  [SMALL_STATE(21)] = 615,
  [SMALL_STATE(22)] = 632,
  [SMALL_STATE(23)] = 649,
  [SMALL_STATE(24)] = 666,
  [SMALL_STATE(25)] = 683,
  [SMALL_STATE(26)] = 700,
  [SMALL_STATE(27)] = 717,
  [SMALL_STATE(28)] = 734,
  [SMALL_STATE(29)] = 751,
  [SMALL_STATE(30)] = 767,
  [SMALL_STATE(31)] = 783,
  [SMALL_STATE(32)] = 803,
  [SMALL_STATE(33)] = 823,
  [SMALL_STATE(34)] = 843,
  [SMALL_STATE(35)] = 859,
  [SMALL_STATE(36)] = 875,
  [SMALL_STATE(37)] = 891,
  [SMALL_STATE(38)] = 907,
  [SMALL_STATE(39)] = 923,
  [SMALL_STATE(40)] = 939,
  [SMALL_STATE(41)] = 955,
  [SMALL_STATE(42)] = 971,
  [SMALL_STATE(43)] = 987,
  [SMALL_STATE(44)] = 1003,
  [SMALL_STATE(45)] = 1019,
  [SMALL_STATE(46)] = 1035,
  [SMALL_STATE(47)] = 1051,
  [SMALL_STATE(48)] = 1067,
  [SMALL_STATE(49)] = 1083,
  [SMALL_STATE(50)] = 1099,
  [SMALL_STATE(51)] = 1117,
  [SMALL_STATE(52)] = 1137,
  [SMALL_STATE(53)] = 1153,
  [SMALL_STATE(54)] = 1171,
  [SMALL_STATE(55)] = 1189,
  [SMALL_STATE(56)] = 1208,
  [SMALL_STATE(57)] = 1221,
  [SMALL_STATE(58)] = 1240,
  [SMALL_STATE(59)] = 1259,
  [SMALL_STATE(60)] = 1278,
  [SMALL_STATE(61)] = 1297,
  [SMALL_STATE(62)] = 1312,
  [SMALL_STATE(63)] = 1331,
  [SMALL_STATE(64)] = 1350,
  [SMALL_STATE(65)] = 1362,
  [SMALL_STATE(66)] = 1374,
  [SMALL_STATE(67)] = 1390,
  [SMALL_STATE(68)] = 1406,
  [SMALL_STATE(69)] = 1422,
  [SMALL_STATE(70)] = 1438,
  [SMALL_STATE(71)] = 1450,
  [SMALL_STATE(72)] = 1462,
  [SMALL_STATE(73)] = 1474,
  [SMALL_STATE(74)] = 1487,
  [SMALL_STATE(75)] = 1500,
  [SMALL_STATE(76)] = 1513,
  [SMALL_STATE(77)] = 1526,
  [SMALL_STATE(78)] = 1539,
  [SMALL_STATE(79)] = 1552,
  [SMALL_STATE(80)] = 1565,
  [SMALL_STATE(81)] = 1578,
  [SMALL_STATE(82)] = 1591,
  [SMALL_STATE(83)] = 1602,
  [SMALL_STATE(84)] = 1615,
  [SMALL_STATE(85)] = 1628,
  [SMALL_STATE(86)] = 1641,
  [SMALL_STATE(87)] = 1651,
  [SMALL_STATE(88)] = 1661,
  [SMALL_STATE(89)] = 1671,
  [SMALL_STATE(90)] = 1681,
  [SMALL_STATE(91)] = 1691,
  [SMALL_STATE(92)] = 1701,
  [SMALL_STATE(93)] = 1711,
  [SMALL_STATE(94)] = 1721,
  [SMALL_STATE(95)] = 1731,
  [SMALL_STATE(96)] = 1741,
  [SMALL_STATE(97)] = 1751,
  [SMALL_STATE(98)] = 1761,
  [SMALL_STATE(99)] = 1771,
  [SMALL_STATE(100)] = 1781,
  [SMALL_STATE(101)] = 1791,
  [SMALL_STATE(102)] = 1801,
  [SMALL_STATE(103)] = 1811,
  [SMALL_STATE(104)] = 1821,
  [SMALL_STATE(105)] = 1831,
  [SMALL_STATE(106)] = 1841,
  [SMALL_STATE(107)] = 1851,
  [SMALL_STATE(108)] = 1861,
  [SMALL_STATE(109)] = 1871,
  [SMALL_STATE(110)] = 1875,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [43] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(107),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(3),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(76),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(15),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(94),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(2),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(75),
  [64] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(48),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 3),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 3),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 2),
  [73] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 2),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__node, 1),
  [77] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__node, 1),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 1),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 1),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 1),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 1),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_end_tag, 3),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_end_tag, 3),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_end_tag, 3),
  [93] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_end_tag, 3),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_end_tag, 3),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_end_tag, 3),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 4),
  [101] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 4),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doctype, 4),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_doctype, 4),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 3),
  [109] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 3),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_erroneous_end_tag, 3),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_erroneous_end_tag, 3),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 2),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 2),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 3),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 3),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 3),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 3),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 2),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 2),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [139] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_comment_repeat1, 2), SHIFT_REPEAT(56),
  [142] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_comment_repeat1, 2),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 3, .production_id = 1),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 3, .production_id = 1),
  [148] = {.entry = {.count = 1, .reusable = false}}, SHIFT(56),
  [150] = {.entry = {.count = 1, .reusable = false}}, SHIFT(110),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [154] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 4, .production_id = 1),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 4, .production_id = 1),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2),
  [160] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2), SHIFT_REPEAT(61),
  [163] = {.entry = {.count = 1, .reusable = false}}, SHIFT(109),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_comment_repeat1, 1),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 3),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tags, 1),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [195] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [199] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT(108),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [207] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 2),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 1),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [217] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [219] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 3),
  [223] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_start_tag, 3),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 4),
  [227] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_start_tag, 4),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 3),
  [231] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_start_tag, 3),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 4),
  [237] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_start_tag, 4),
  [239] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__start_tag_name, 1),
  [241] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_erroneous_end_tag_name, 1),
  [255] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [257] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [261] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__end_tag_name, 1),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [281] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [285] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 2),
  [293] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 3),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_nml(void) {
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
