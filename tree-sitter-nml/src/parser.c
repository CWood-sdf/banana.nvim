#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 113
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 71
#define ALIAS_COUNT 0
#define TOKEN_COUNT 45
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 2

enum ts_symbol_identifiers {
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
  aux_sym__start_tag_name_token3 = 14,
  sym_raw_text = 15,
  anon_sym_script = 16,
  anon_sym_style = 17,
  aux_sym_erroneous_end_tag_name_token1 = 18,
  anon_sym_LT_BANG_DASH_DASH = 19,
  aux_sym_comment_token1 = 20,
  aux_sym_comment_token2 = 21,
  aux_sym_comment_token3 = 22,
  anon_sym_DASH_DASH_GT = 23,
  anon_sym_meta = 24,
  anon_sym_br = 25,
  anon_sym_hr = 26,
  anon_sym_bound = 27,
  anon_sym_slot = 28,
  anon_sym_LT_BANG = 29,
  anon_sym_GT = 30,
  sym__doctype = 31,
  anon_sym_LT = 32,
  anon_sym_LT_SLASH = 33,
  anon_sym_SLASH_GT = 34,
  anon_sym_EQ = 35,
  sym_attribute_name = 36,
  sym_attribute_value = 37,
  sym_entity = 38,
  sym_substitution = 39,
  anon_sym_SQUOTE = 40,
  aux_sym_quoted_attribute_value_token1 = 41,
  anon_sym_DQUOTE = 42,
  aux_sym_quoted_attribute_value_token2 = 43,
  sym_text = 44,
  sym_source_file = 45,
  sym__start_tag_name = 46,
  sym__script_start_tag_name = 47,
  sym__style_start_tag_name = 48,
  sym__end_tag_name = 49,
  sym_erroneous_end_tag_name = 50,
  sym_comment = 51,
  sym_self_closing_tags = 52,
  sym_doctype = 53,
  sym__node = 54,
  sym_element = 55,
  sym_script_element = 56,
  sym_style_element = 57,
  sym_start_tag = 58,
  sym_script_start_tag = 59,
  sym_script_end_tag = 60,
  sym_style_start_tag = 61,
  sym_style_end_tag = 62,
  sym_self_closing_tag = 63,
  sym_end_tag = 64,
  sym_erroneous_end_tag = 65,
  sym_attribute = 66,
  sym_quoted_attribute_value = 67,
  aux_sym_source_file_repeat1 = 68,
  aux_sym_comment_repeat1 = 69,
  aux_sym_start_tag_repeat1 = 70,
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
  [anon_sym_slot] = "slot",
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
  [anon_sym_slot] = anon_sym_slot,
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
  [anon_sym_slot] = {
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
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 5,
  [10] = 8,
  [11] = 4,
  [12] = 6,
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
      if (eof) ADVANCE(103);
      ADVANCE_MAP(
        '"', 262,
        '%', 254,
        '&', 5,
        '\'', 256,
        '-', 9,
        '/', 55,
        '<', 207,
        '=', 210,
        '>', 205,
        'D', 95,
        'b', 82,
        'd', 70,
        'h', 65,
        'l', 71,
        'm', 66,
        'n', 79,
        'o', 74,
        'p', 124,
        's', 61,
        't', 73,
        'u', 75,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '!') ADVANCE(10);
      END_STATE();
    case 2:
      if (lookahead == '!') ADVANCE(10);
      if (lookahead == '/') ADVANCE(208);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(262);
      if (lookahead == '\'') ADVANCE(256);
      if (lookahead == '<') ADVANCE(1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (lookahead != 0 &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(212);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(262);
      if (lookahead == '<') ADVANCE(263);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(266);
      if (lookahead != 0) ADVANCE(267);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(98);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(252);
      END_STATE();
    case 6:
      if (lookahead == '%') ADVANCE(254);
      if (lookahead == '&') ADVANCE(5);
      if (lookahead == '<') ADVANCE(207);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(268);
      END_STATE();
    case 7:
      if (lookahead == '\'') ADVANCE(256);
      if (lookahead == '<') ADVANCE(257);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(260);
      if (lookahead != 0) ADVANCE(261);
      END_STATE();
    case 8:
      if (lookahead == '-') ADVANCE(9);
      if (lookahead == '<') ADVANCE(189);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(190);
      if (lookahead != 0) ADVANCE(188);
      END_STATE();
    case 9:
      if (lookahead == '-') ADVANCE(56);
      if (lookahead != 0) ADVANCE(191);
      END_STATE();
    case 10:
      if (lookahead == '-') ADVANCE(11);
      END_STATE();
    case 11:
      if (lookahead == '-') ADVANCE(184);
      END_STATE();
    case 12:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'a') ADVANCE(16);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 13:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'a') ADVANCE(195);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 14:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'a') ADVANCE(34);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 15:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'c') ADVANCE(39);
      if (lookahead == 'l') ADVANCE(37);
      if (lookahead == 'p') ADVANCE(14);
      if (lookahead == 't') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 16:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'd') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 17:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'd') ADVANCE(201);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 18:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'd') ADVANCE(45);
      if (lookahead == 'u') ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 19:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'e') ADVANCE(12);
      if (lookahead == 'r') ADVANCE(199);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 20:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'e') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 21:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'e') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 22:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'e') ADVANCE(151);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 23:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'e') ADVANCE(108);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 24:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'i') ADVANCE(44);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 25:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'i') ADVANCE(135);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 26:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'i') ADVANCE(38);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 27:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'i') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 28:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'l') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 29:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'l') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 30:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'l') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 31:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'l') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 32:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'l') ADVANCE(23);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 33:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'm') ADVANCE(30);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 34:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'n') ADVANCE(126);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 35:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'n') ADVANCE(17);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 36:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'o') ADVANCE(18);
      if (lookahead == 'r') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 37:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'o') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 38:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'p') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 39:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'r') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 40:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 't') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 41:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 't') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 42:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 't') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 43:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 't') ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 44:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'v') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 45:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'y') ADVANCE(117);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 46:
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'y') ADVANCE(31);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 47:
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 48:
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(49);
      END_STATE();
    case 49:
      if (lookahead == '-') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(49);
      END_STATE();
    case 50:
      if (lookahead == '/') ADVANCE(55);
      if (lookahead == '<') ADVANCE(1);
      if (lookahead == '=') ADVANCE(210);
      if (lookahead == '>') ADVANCE(205);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(50);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'') ADVANCE(211);
      END_STATE();
    case 51:
      ADVANCE_MAP(
        '<', 1,
        'b', 36,
        'd', 24,
        'h', 19,
        'l', 25,
        'm', 20,
        'n', 33,
        'o', 28,
        'p', 122,
        's', 15,
        't', 27,
        'u', 29,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(51);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(48);
      END_STATE();
    case 52:
      ADVANCE_MAP(
        '<', 152,
        'b', 169,
        'd', 160,
        'h', 157,
        'l', 161,
        'n', 167,
        'o', 163,
        'p', 123,
        's', 170,
        't', 162,
        'u', 164,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(179);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(175);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 53:
      if (lookahead == '<') ADVANCE(152);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(180);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 54:
      if (lookahead == '<') ADVANCE(2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(146);
      if (lookahead != 0) ADVANCE(147);
      END_STATE();
    case 55:
      if (lookahead == '>') ADVANCE(209);
      END_STATE();
    case 56:
      if (lookahead == '>') ADVANCE(193);
      if (lookahead != 0) ADVANCE(192);
      END_STATE();
    case 57:
      if (lookahead == '_') ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 58:
      if (lookahead == 'a') ADVANCE(62);
      END_STATE();
    case 59:
      if (lookahead == 'a') ADVANCE(194);
      END_STATE();
    case 60:
      if (lookahead == 'a') ADVANCE(80);
      END_STATE();
    case 61:
      if (lookahead == 'c') ADVANCE(85);
      if (lookahead == 'l') ADVANCE(83);
      if (lookahead == 'p') ADVANCE(60);
      if (lookahead == 't') ADVANCE(92);
      END_STATE();
    case 62:
      if (lookahead == 'd') ADVANCE(113);
      END_STATE();
    case 63:
      if (lookahead == 'd') ADVANCE(200);
      END_STATE();
    case 64:
      if (lookahead == 'd') ADVANCE(91);
      if (lookahead == 'u') ADVANCE(81);
      END_STATE();
    case 65:
      if (lookahead == 'e') ADVANCE(58);
      if (lookahead == 'r') ADVANCE(198);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(137);
      END_STATE();
    case 66:
      if (lookahead == 'e') ADVANCE(88);
      END_STATE();
    case 67:
      if (lookahead == 'e') ADVANCE(110);
      END_STATE();
    case 68:
      if (lookahead == 'e') ADVANCE(150);
      END_STATE();
    case 69:
      if (lookahead == 'e') ADVANCE(107);
      END_STATE();
    case 70:
      if (lookahead == 'i') ADVANCE(90);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(93);
      END_STATE();
    case 71:
      if (lookahead == 'i') ADVANCE(134);
      END_STATE();
    case 72:
      if (lookahead == 'i') ADVANCE(84);
      END_STATE();
    case 73:
      if (lookahead == 'i') ADVANCE(89);
      END_STATE();
    case 74:
      if (lookahead == 'l') ADVANCE(128);
      END_STATE();
    case 75:
      if (lookahead == 'l') ADVANCE(131);
      END_STATE();
    case 76:
      if (lookahead == 'l') ADVANCE(104);
      END_STATE();
    case 77:
      if (lookahead == 'l') ADVANCE(68);
      END_STATE();
    case 78:
      if (lookahead == 'l') ADVANCE(69);
      END_STATE();
    case 79:
      if (lookahead == 'm') ADVANCE(76);
      END_STATE();
    case 80:
      if (lookahead == 'n') ADVANCE(125);
      END_STATE();
    case 81:
      if (lookahead == 'n') ADVANCE(63);
      END_STATE();
    case 82:
      if (lookahead == 'o') ADVANCE(64);
      if (lookahead == 'r') ADVANCE(196);
      END_STATE();
    case 83:
      if (lookahead == 'o') ADVANCE(86);
      END_STATE();
    case 84:
      if (lookahead == 'p') ADVANCE(87);
      END_STATE();
    case 85:
      if (lookahead == 'r') ADVANCE(72);
      END_STATE();
    case 86:
      if (lookahead == 't') ADVANCE(202);
      END_STATE();
    case 87:
      if (lookahead == 't') ADVANCE(148);
      END_STATE();
    case 88:
      if (lookahead == 't') ADVANCE(59);
      END_STATE();
    case 89:
      if (lookahead == 't') ADVANCE(78);
      END_STATE();
    case 90:
      if (lookahead == 'v') ADVANCE(119);
      END_STATE();
    case 91:
      if (lookahead == 'y') ADVANCE(116);
      END_STATE();
    case 92:
      if (lookahead == 'y') ADVANCE(77);
      END_STATE();
    case 93:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(97);
      END_STATE();
    case 94:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(206);
      END_STATE();
    case 95:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(93);
      END_STATE();
    case 96:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(94);
      END_STATE();
    case 97:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(99);
      END_STATE();
    case 98:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(100);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(218);
      END_STATE();
    case 99:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(96);
      END_STATE();
    case 100:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(223);
      END_STATE();
    case 101:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 102:
      if (eof) ADVANCE(103);
      if (lookahead == '%') ADVANCE(254);
      if (lookahead == '&') ADVANCE(5);
      if (lookahead == '<') ADVANCE(207);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(268);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_nml);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_nml);
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_nml);
      if (lookahead == '-') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_title);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_title);
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_title);
      if (lookahead == '-') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_pre);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_pre);
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_pre);
      if (lookahead == '-') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_head);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_head);
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_head);
      if (lookahead == '-') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_body);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_body);
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_body);
      if (lookahead == '-') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_div);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_div);
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_div);
      if (lookahead == '-') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_p);
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'r') ADVANCE(21);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_p);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'r') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_p);
      if (lookahead == 'r') ADVANCE(67);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_span);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_span);
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_span);
      if (lookahead == '-') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_ol);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_ol);
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_ol);
      if (lookahead == '-') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_ul);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_ul);
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_ul);
      if (lookahead == '-') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_li);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_li);
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_li);
      if (lookahead == '-') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token1);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token1);
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(142);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(142);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(143);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(145);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(181);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(145);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_raw_text);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(146);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(147);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_raw_text);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(147);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_script);
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_style);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_style);
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '!') ADVANCE(178);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'a') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'a') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'd') ADVANCE(173);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'd') ADVANCE(115);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'e') ADVANCE(154);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(139);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'e') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'e') ADVANCE(109);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'i') ADVANCE(172);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'i') ADVANCE(136);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'i') ADVANCE(171);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'l') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'l') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'l') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'l') ADVANCE(159);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'm') ADVANCE(165);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'n') ADVANCE(127);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'o') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'p') ADVANCE(153);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 't') ADVANCE(166);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'v') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == 'y') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(176);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(181);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(176);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(187);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(177);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      ADVANCE_MAP(
        '<', 152,
        'b', 169,
        'd', 160,
        'h', 157,
        'l', 161,
        'n', 167,
        'o', 163,
        'p', 123,
        's', 170,
        't', 162,
        'u', 164,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(179);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(175);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '<') ADVANCE(152);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(180);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '_') ADVANCE(144);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(143);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(143);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(267);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(261);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(183);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '!') ADVANCE(10);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '<') ADVANCE(189);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(190);
      if (lookahead != 0 &&
          lookahead != '-') ADVANCE(188);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_comment_token2);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_comment_token3);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(anon_sym_DASH_DASH_GT);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(anon_sym_meta);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(anon_sym_meta);
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(anon_sym_br);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(anon_sym_br);
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(anon_sym_hr);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(anon_sym_hr);
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(anon_sym_bound);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(anon_sym_bound);
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(anon_sym_slot);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(anon_sym_slot);
      if (lookahead == '-') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(anon_sym_LT_BANG);
      if (lookahead == '-') ADVANCE(11);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym__doctype);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '!') ADVANCE(204);
      if (lookahead == '/') ADVANCE(208);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(anon_sym_LT_SLASH);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(anon_sym_SLASH_GT);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(211);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_attribute_value);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(212);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_entity);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(214);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(215);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(216);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(217);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(214);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(219);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(220);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(221);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(222);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(214);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(224);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(225);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(226);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(227);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(229);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(230);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(231);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(233);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(234);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(235);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(236);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(237);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(239);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(240);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(241);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(242);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(243);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(244);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(245);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(246);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(247);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(213);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(251);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_substitution);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_substitution);
      if (lookahead == '%') ADVANCE(253);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(255);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_substitution);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(255);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '!') ADVANCE(259);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(261);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '-') ADVANCE(186);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(261);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '-') ADVANCE(258);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(261);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '<') ADVANCE(257);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(260);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(261);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(261);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '!') ADVANCE(265);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '"') ADVANCE(267);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '-') ADVANCE(185);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(267);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '-') ADVANCE(264);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(267);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '<') ADVANCE(263);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(266);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(267);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(267);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_text);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(268);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '&' &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(268);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 102},
  [2] = {.lex_state = 51},
  [3] = {.lex_state = 51},
  [4] = {.lex_state = 52},
  [5] = {.lex_state = 102},
  [6] = {.lex_state = 102},
  [7] = {.lex_state = 102},
  [8] = {.lex_state = 102},
  [9] = {.lex_state = 102},
  [10] = {.lex_state = 102},
  [11] = {.lex_state = 52},
  [12] = {.lex_state = 102},
  [13] = {.lex_state = 102},
  [14] = {.lex_state = 102},
  [15] = {.lex_state = 102},
  [16] = {.lex_state = 102},
  [17] = {.lex_state = 102},
  [18] = {.lex_state = 102},
  [19] = {.lex_state = 102},
  [20] = {.lex_state = 102},
  [21] = {.lex_state = 102},
  [22] = {.lex_state = 102},
  [23] = {.lex_state = 102},
  [24] = {.lex_state = 102},
  [25] = {.lex_state = 102},
  [26] = {.lex_state = 102},
  [27] = {.lex_state = 102},
  [28] = {.lex_state = 102},
  [29] = {.lex_state = 102},
  [30] = {.lex_state = 102},
  [31] = {.lex_state = 102},
  [32] = {.lex_state = 102},
  [33] = {.lex_state = 102},
  [34] = {.lex_state = 102},
  [35] = {.lex_state = 102},
  [36] = {.lex_state = 102},
  [37] = {.lex_state = 102},
  [38] = {.lex_state = 102},
  [39] = {.lex_state = 102},
  [40] = {.lex_state = 102},
  [41] = {.lex_state = 102},
  [42] = {.lex_state = 102},
  [43] = {.lex_state = 102},
  [44] = {.lex_state = 102},
  [45] = {.lex_state = 102},
  [46] = {.lex_state = 102},
  [47] = {.lex_state = 50},
  [48] = {.lex_state = 8},
  [49] = {.lex_state = 50},
  [50] = {.lex_state = 50},
  [51] = {.lex_state = 50},
  [52] = {.lex_state = 50},
  [53] = {.lex_state = 8},
  [54] = {.lex_state = 8},
  [55] = {.lex_state = 50},
  [56] = {.lex_state = 50},
  [57] = {.lex_state = 3},
  [58] = {.lex_state = 50},
  [59] = {.lex_state = 50},
  [60] = {.lex_state = 50},
  [61] = {.lex_state = 50},
  [62] = {.lex_state = 50},
  [63] = {.lex_state = 8},
  [64] = {.lex_state = 50},
  [65] = {.lex_state = 50},
  [66] = {.lex_state = 50},
  [67] = {.lex_state = 54},
  [68] = {.lex_state = 50},
  [69] = {.lex_state = 54},
  [70] = {.lex_state = 54},
  [71] = {.lex_state = 54},
  [72] = {.lex_state = 50},
  [73] = {.lex_state = 50},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 54},
  [76] = {.lex_state = 53},
  [77] = {.lex_state = 54},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 50},
  [83] = {.lex_state = 50},
  [84] = {.lex_state = 7},
  [85] = {.lex_state = 4},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 54},
  [89] = {.lex_state = 53},
  [90] = {.lex_state = 54},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 53},
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
  [107] = {.lex_state = 53},
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
    [anon_sym_slot] = ACTIONS(1),
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
    [sym_start_tag] = STATE(5),
    [sym_script_start_tag] = STATE(67),
    [sym_style_start_tag] = STATE(71),
    [sym_self_closing_tag] = STATE(18),
    [sym_erroneous_end_tag] = STATE(14),
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
  [0] = 11,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(17), 1,
      aux_sym__start_tag_name_token2,
    ACTIONS(19), 1,
      anon_sym_script,
    ACTIONS(21), 1,
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
    ACTIONS(23), 5,
      anon_sym_meta,
      anon_sym_br,
      anon_sym_hr,
      anon_sym_bound,
      anon_sym_slot,
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
      aux_sym__start_tag_name_token3,
  [50] = 11,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(17), 1,
      aux_sym__start_tag_name_token2,
    ACTIONS(19), 1,
      anon_sym_script,
    ACTIONS(21), 1,
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
    ACTIONS(23), 5,
      anon_sym_meta,
      anon_sym_br,
      anon_sym_hr,
      anon_sym_bound,
      anon_sym_slot,
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
      aux_sym__start_tag_name_token3,
  [100] = 7,
    ACTIONS(25), 1,
      aux_sym_erroneous_end_tag_name_token1,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(4), 1,
      sym_comment,
    STATE(93), 1,
      sym__start_tag_name,
    STATE(97), 1,
      sym_erroneous_end_tag_name,
    STATE(106), 1,
      sym__end_tag_name,
    ACTIONS(15), 14,
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
      aux_sym__start_tag_name_token3,
  [135] = 14,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(29), 1,
      anon_sym_LT_BANG,
    ACTIONS(31), 1,
      anon_sym_LT,
    ACTIONS(33), 1,
      anon_sym_LT_SLASH,
    STATE(5), 1,
      sym_comment,
    STATE(8), 1,
      aux_sym_source_file_repeat1,
    STATE(9), 1,
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
    ACTIONS(35), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(42), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [184] = 13,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(37), 1,
      ts_builtin_sym_end,
    ACTIONS(39), 1,
      anon_sym_LT_BANG,
    ACTIONS(42), 1,
      anon_sym_LT,
    ACTIONS(45), 1,
      anon_sym_LT_SLASH,
    STATE(5), 1,
      sym_start_tag,
    STATE(13), 1,
      sym__node,
    STATE(18), 1,
      sym_self_closing_tag,
    STATE(67), 1,
      sym_script_start_tag,
    STATE(71), 1,
      sym_style_start_tag,
    STATE(6), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    ACTIONS(48), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(14), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [231] = 14,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      anon_sym_LT,
    ACTIONS(11), 1,
      anon_sym_LT_SLASH,
    ACTIONS(51), 1,
      ts_builtin_sym_end,
    STATE(5), 1,
      sym_start_tag,
    STATE(6), 1,
      aux_sym_source_file_repeat1,
    STATE(7), 1,
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
  [280] = 14,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(29), 1,
      anon_sym_LT_BANG,
    ACTIONS(31), 1,
      anon_sym_LT,
    ACTIONS(33), 1,
      anon_sym_LT_SLASH,
    STATE(8), 1,
      sym_comment,
    STATE(9), 1,
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
    ACTIONS(35), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(42), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [329] = 13,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(29), 1,
      anon_sym_LT_BANG,
    ACTIONS(31), 1,
      anon_sym_LT,
    ACTIONS(53), 1,
      anon_sym_LT_SLASH,
    STATE(10), 1,
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
    STATE(9), 2,
      sym_comment,
      sym_start_tag,
    ACTIONS(35), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(42), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [376] = 14,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(29), 1,
      anon_sym_LT_BANG,
    ACTIONS(31), 1,
      anon_sym_LT,
    ACTIONS(53), 1,
      anon_sym_LT_SLASH,
    STATE(9), 1,
      sym_start_tag,
    STATE(10), 1,
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
    ACTIONS(35), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(42), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [425] = 7,
    ACTIONS(25), 1,
      aux_sym_erroneous_end_tag_name_token1,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(11), 1,
      sym_comment,
    STATE(93), 1,
      sym__start_tag_name,
    STATE(97), 1,
      sym_erroneous_end_tag_name,
    STATE(102), 1,
      sym__end_tag_name,
    ACTIONS(15), 14,
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
      aux_sym__start_tag_name_token3,
  [460] = 12,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(55), 1,
      anon_sym_LT_BANG,
    ACTIONS(58), 1,
      anon_sym_LT,
    ACTIONS(61), 1,
      anon_sym_LT_SLASH,
    STATE(9), 1,
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
    ACTIONS(64), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(42), 5,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [504] = 4,
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
  [522] = 4,
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
  [540] = 4,
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
  [558] = 4,
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
  [576] = 4,
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
  [594] = 4,
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
  [612] = 4,
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
  [630] = 4,
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
  [648] = 4,
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
  [666] = 4,
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
  [684] = 4,
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
  [702] = 4,
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
  [720] = 4,
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
  [738] = 4,
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
  [756] = 4,
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
  [774] = 4,
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
  [792] = 4,
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
  [809] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(30), 1,
      sym_comment,
    ACTIONS(85), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(83), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [826] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(31), 1,
      sym_comment,
    ACTIONS(131), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(133), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [843] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(32), 1,
      sym_comment,
    ACTIONS(93), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(91), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [860] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(33), 1,
      sym_comment,
    ACTIONS(97), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(95), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [877] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(34), 1,
      sym_comment,
    ACTIONS(129), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(127), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [894] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(35), 1,
      sym_comment,
    ACTIONS(135), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(137), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [911] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(36), 1,
      sym_comment,
    ACTIONS(117), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(115), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [928] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(37), 1,
      sym_comment,
    ACTIONS(105), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(103), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [945] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(38), 1,
      sym_comment,
    ACTIONS(101), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(99), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [962] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(39), 1,
      sym_comment,
    ACTIONS(125), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(123), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [979] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(40), 1,
      sym_comment,
    ACTIONS(113), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(111), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [996] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(41), 1,
      sym_comment,
    ACTIONS(109), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(107), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1013] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(42), 1,
      sym_comment,
    ACTIONS(73), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(71), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1030] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(43), 1,
      sym_comment,
    ACTIONS(69), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(67), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1047] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(44), 1,
      sym_comment,
    ACTIONS(89), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(87), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1064] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(45), 1,
      sym_comment,
    ACTIONS(77), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(75), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1081] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(46), 1,
      sym_comment,
    ACTIONS(81), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(79), 4,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1098] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(141), 1,
      sym_attribute_name,
    STATE(47), 1,
      sym_comment,
    STATE(50), 1,
      aux_sym_start_tag_repeat1,
    STATE(68), 1,
      sym_attribute,
    ACTIONS(139), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [1118] = 5,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(145), 1,
      anon_sym_DASH_DASH_GT,
    STATE(48), 1,
      sym_comment,
    STATE(54), 1,
      aux_sym_comment_repeat1,
    ACTIONS(143), 3,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
  [1136] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(141), 1,
      sym_attribute_name,
    STATE(49), 1,
      sym_comment,
    STATE(50), 1,
      aux_sym_start_tag_repeat1,
    STATE(68), 1,
      sym_attribute,
    ACTIONS(147), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [1156] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(151), 1,
      sym_attribute_name,
    STATE(68), 1,
      sym_attribute,
    ACTIONS(149), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
    STATE(50), 2,
      sym_comment,
      aux_sym_start_tag_repeat1,
  [1174] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(141), 1,
      sym_attribute_name,
    STATE(49), 1,
      aux_sym_start_tag_repeat1,
    STATE(51), 1,
      sym_comment,
    STATE(68), 1,
      sym_attribute,
    ACTIONS(154), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [1194] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(141), 1,
      sym_attribute_name,
    STATE(47), 1,
      aux_sym_start_tag_repeat1,
    STATE(52), 1,
      sym_comment,
    STATE(68), 1,
      sym_attribute,
    ACTIONS(156), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [1214] = 5,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(158), 1,
      anon_sym_DASH_DASH_GT,
    STATE(48), 1,
      aux_sym_comment_repeat1,
    STATE(53), 1,
      sym_comment,
    ACTIONS(143), 3,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
  [1232] = 4,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(163), 1,
      anon_sym_DASH_DASH_GT,
    STATE(54), 2,
      sym_comment,
      aux_sym_comment_repeat1,
    ACTIONS(160), 3,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
  [1248] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(141), 1,
      sym_attribute_name,
    ACTIONS(165), 1,
      anon_sym_GT,
    STATE(50), 1,
      aux_sym_start_tag_repeat1,
    STATE(55), 1,
      sym_comment,
    STATE(68), 1,
      sym_attribute,
  [1267] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(141), 1,
      sym_attribute_name,
    ACTIONS(167), 1,
      anon_sym_GT,
    STATE(50), 1,
      aux_sym_start_tag_repeat1,
    STATE(56), 1,
      sym_comment,
    STATE(68), 1,
      sym_attribute,
  [1286] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(169), 1,
      sym_attribute_value,
    ACTIONS(171), 1,
      anon_sym_SQUOTE,
    ACTIONS(173), 1,
      anon_sym_DQUOTE,
    STATE(57), 1,
      sym_comment,
    STATE(65), 1,
      sym_quoted_attribute_value,
  [1305] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(141), 1,
      sym_attribute_name,
    ACTIONS(175), 1,
      anon_sym_GT,
    STATE(56), 1,
      aux_sym_start_tag_repeat1,
    STATE(58), 1,
      sym_comment,
    STATE(68), 1,
      sym_attribute,
  [1324] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(141), 1,
      sym_attribute_name,
    ACTIONS(177), 1,
      anon_sym_GT,
    STATE(59), 1,
      sym_comment,
    STATE(62), 1,
      aux_sym_start_tag_repeat1,
    STATE(68), 1,
      sym_attribute,
  [1343] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(141), 1,
      sym_attribute_name,
    ACTIONS(179), 1,
      anon_sym_GT,
    STATE(55), 1,
      aux_sym_start_tag_repeat1,
    STATE(60), 1,
      sym_comment,
    STATE(68), 1,
      sym_attribute,
  [1362] = 4,
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
  [1377] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(141), 1,
      sym_attribute_name,
    ACTIONS(185), 1,
      anon_sym_GT,
    STATE(50), 1,
      aux_sym_start_tag_repeat1,
    STATE(62), 1,
      sym_comment,
    STATE(68), 1,
      sym_attribute,
  [1396] = 3,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(63), 1,
      sym_comment,
    ACTIONS(187), 4,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
      anon_sym_DASH_DASH_GT,
  [1409] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(64), 1,
      sym_comment,
    ACTIONS(189), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1421] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(65), 1,
      sym_comment,
    ACTIONS(191), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1433] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(66), 1,
      sym_comment,
    ACTIONS(193), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1445] = 5,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(195), 1,
      sym_raw_text,
    ACTIONS(197), 1,
      anon_sym_LT_SLASH,
    STATE(16), 1,
      sym_script_end_tag,
    STATE(67), 1,
      sym_comment,
  [1461] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(68), 1,
      sym_comment,
    ACTIONS(199), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1473] = 5,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(201), 1,
      sym_raw_text,
    ACTIONS(203), 1,
      anon_sym_LT_SLASH,
    STATE(46), 1,
      sym_script_end_tag,
    STATE(69), 1,
      sym_comment,
  [1489] = 5,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(205), 1,
      sym_raw_text,
    ACTIONS(207), 1,
      anon_sym_LT_SLASH,
    STATE(30), 1,
      sym_style_end_tag,
    STATE(70), 1,
      sym_comment,
  [1505] = 5,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(209), 1,
      sym_raw_text,
    ACTIONS(211), 1,
      anon_sym_LT_SLASH,
    STATE(17), 1,
      sym_style_end_tag,
    STATE(71), 1,
      sym_comment,
  [1521] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(72), 1,
      sym_comment,
    ACTIONS(213), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1533] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(73), 1,
      sym_comment,
    ACTIONS(215), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1544] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(217), 1,
      anon_sym_style,
    STATE(74), 1,
      sym_comment,
    STATE(104), 1,
      sym__style_start_tag_name,
  [1557] = 4,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(219), 1,
      sym_raw_text,
    ACTIONS(221), 1,
      anon_sym_LT_SLASH,
    STATE(75), 1,
      sym_comment,
  [1570] = 4,
    ACTIONS(25), 1,
      aux_sym_erroneous_end_tag_name_token1,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(76), 1,
      sym_comment,
    STATE(109), 1,
      sym_erroneous_end_tag_name,
  [1583] = 4,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(223), 1,
      sym_raw_text,
    ACTIONS(225), 1,
      anon_sym_LT_SLASH,
    STATE(77), 1,
      sym_comment,
  [1596] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(227), 1,
      anon_sym_LT_SLASH,
    STATE(26), 1,
      sym_script_end_tag,
    STATE(78), 1,
      sym_comment,
  [1609] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(229), 1,
      anon_sym_script,
    STATE(79), 1,
      sym_comment,
    STATE(101), 1,
      sym__script_start_tag_name,
  [1622] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(231), 1,
      anon_sym_LT_SLASH,
    STATE(25), 1,
      sym_style_end_tag,
    STATE(80), 1,
      sym_comment,
  [1635] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(217), 1,
      anon_sym_style,
    STATE(81), 1,
      sym_comment,
    STATE(108), 1,
      sym__style_start_tag_name,
  [1648] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(82), 1,
      sym_comment,
    ACTIONS(233), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1659] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(83), 1,
      sym_comment,
    ACTIONS(235), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1670] = 4,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(237), 1,
      anon_sym_SQUOTE,
    ACTIONS(239), 1,
      aux_sym_quoted_attribute_value_token1,
    STATE(84), 1,
      sym_comment,
  [1683] = 4,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(237), 1,
      anon_sym_DQUOTE,
    ACTIONS(241), 1,
      aux_sym_quoted_attribute_value_token2,
    STATE(85), 1,
      sym_comment,
  [1696] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(243), 1,
      anon_sym_LT_SLASH,
    STATE(29), 1,
      sym_script_end_tag,
    STATE(86), 1,
      sym_comment,
  [1709] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(245), 1,
      anon_sym_LT_SLASH,
    STATE(36), 1,
      sym_style_end_tag,
    STATE(87), 1,
      sym_comment,
  [1722] = 4,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(247), 1,
      sym_raw_text,
    ACTIONS(249), 1,
      anon_sym_LT_SLASH,
    STATE(88), 1,
      sym_comment,
  [1735] = 4,
    ACTIONS(25), 1,
      aux_sym_erroneous_end_tag_name_token1,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(89), 1,
      sym_comment,
    STATE(97), 1,
      sym_erroneous_end_tag_name,
  [1748] = 4,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(251), 1,
      sym_raw_text,
    ACTIONS(253), 1,
      anon_sym_LT_SLASH,
    STATE(90), 1,
      sym_comment,
  [1761] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(229), 1,
      anon_sym_script,
    STATE(91), 1,
      sym_comment,
    STATE(103), 1,
      sym__script_start_tag_name,
  [1774] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(255), 1,
      anon_sym_GT,
    STATE(92), 1,
      sym_comment,
  [1784] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(257), 1,
      anon_sym_GT,
    STATE(93), 1,
      sym_comment,
  [1794] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(259), 1,
      anon_sym_GT,
    STATE(94), 1,
      sym_comment,
  [1804] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(261), 1,
      sym__doctype,
    STATE(95), 1,
      sym_comment,
  [1814] = 3,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(263), 1,
      aux_sym_erroneous_end_tag_name_token1,
    STATE(96), 1,
      sym_comment,
  [1824] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(265), 1,
      anon_sym_GT,
    STATE(97), 1,
      sym_comment,
  [1834] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(267), 1,
      anon_sym_SQUOTE,
    STATE(98), 1,
      sym_comment,
  [1844] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(269), 1,
      ts_builtin_sym_end,
    STATE(99), 1,
      sym_comment,
  [1854] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(271), 1,
      anon_sym_GT,
    STATE(100), 1,
      sym_comment,
  [1864] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(273), 1,
      anon_sym_GT,
    STATE(101), 1,
      sym_comment,
  [1874] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(275), 1,
      anon_sym_GT,
    STATE(102), 1,
      sym_comment,
  [1884] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(277), 1,
      anon_sym_GT,
    STATE(103), 1,
      sym_comment,
  [1894] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(279), 1,
      anon_sym_GT,
    STATE(104), 1,
      sym_comment,
  [1904] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    STATE(105), 1,
      sym_comment,
  [1914] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(281), 1,
      anon_sym_GT,
    STATE(106), 1,
      sym_comment,
  [1924] = 3,
    ACTIONS(27), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(283), 1,
      aux_sym_erroneous_end_tag_name_token1,
    STATE(107), 1,
      sym_comment,
  [1934] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(285), 1,
      anon_sym_GT,
    STATE(108), 1,
      sym_comment,
  [1944] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(287), 1,
      anon_sym_GT,
    STATE(109), 1,
      sym_comment,
  [1954] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(289), 1,
      sym__doctype,
    STATE(110), 1,
      sym_comment,
  [1964] = 1,
    ACTIONS(291), 1,
      ts_builtin_sym_end,
  [1968] = 1,
    ACTIONS(293), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 50,
  [SMALL_STATE(4)] = 100,
  [SMALL_STATE(5)] = 135,
  [SMALL_STATE(6)] = 184,
  [SMALL_STATE(7)] = 231,
  [SMALL_STATE(8)] = 280,
  [SMALL_STATE(9)] = 329,
  [SMALL_STATE(10)] = 376,
  [SMALL_STATE(11)] = 425,
  [SMALL_STATE(12)] = 460,
  [SMALL_STATE(13)] = 504,
  [SMALL_STATE(14)] = 522,
  [SMALL_STATE(15)] = 540,
  [SMALL_STATE(16)] = 558,
  [SMALL_STATE(17)] = 576,
  [SMALL_STATE(18)] = 594,
  [SMALL_STATE(19)] = 612,
  [SMALL_STATE(20)] = 630,
  [SMALL_STATE(21)] = 648,
  [SMALL_STATE(22)] = 666,
  [SMALL_STATE(23)] = 684,
  [SMALL_STATE(24)] = 702,
  [SMALL_STATE(25)] = 720,
  [SMALL_STATE(26)] = 738,
  [SMALL_STATE(27)] = 756,
  [SMALL_STATE(28)] = 774,
  [SMALL_STATE(29)] = 792,
  [SMALL_STATE(30)] = 809,
  [SMALL_STATE(31)] = 826,
  [SMALL_STATE(32)] = 843,
  [SMALL_STATE(33)] = 860,
  [SMALL_STATE(34)] = 877,
  [SMALL_STATE(35)] = 894,
  [SMALL_STATE(36)] = 911,
  [SMALL_STATE(37)] = 928,
  [SMALL_STATE(38)] = 945,
  [SMALL_STATE(39)] = 962,
  [SMALL_STATE(40)] = 979,
  [SMALL_STATE(41)] = 996,
  [SMALL_STATE(42)] = 1013,
  [SMALL_STATE(43)] = 1030,
  [SMALL_STATE(44)] = 1047,
  [SMALL_STATE(45)] = 1064,
  [SMALL_STATE(46)] = 1081,
  [SMALL_STATE(47)] = 1098,
  [SMALL_STATE(48)] = 1118,
  [SMALL_STATE(49)] = 1136,
  [SMALL_STATE(50)] = 1156,
  [SMALL_STATE(51)] = 1174,
  [SMALL_STATE(52)] = 1194,
  [SMALL_STATE(53)] = 1214,
  [SMALL_STATE(54)] = 1232,
  [SMALL_STATE(55)] = 1248,
  [SMALL_STATE(56)] = 1267,
  [SMALL_STATE(57)] = 1286,
  [SMALL_STATE(58)] = 1305,
  [SMALL_STATE(59)] = 1324,
  [SMALL_STATE(60)] = 1343,
  [SMALL_STATE(61)] = 1362,
  [SMALL_STATE(62)] = 1377,
  [SMALL_STATE(63)] = 1396,
  [SMALL_STATE(64)] = 1409,
  [SMALL_STATE(65)] = 1421,
  [SMALL_STATE(66)] = 1433,
  [SMALL_STATE(67)] = 1445,
  [SMALL_STATE(68)] = 1461,
  [SMALL_STATE(69)] = 1473,
  [SMALL_STATE(70)] = 1489,
  [SMALL_STATE(71)] = 1505,
  [SMALL_STATE(72)] = 1521,
  [SMALL_STATE(73)] = 1533,
  [SMALL_STATE(74)] = 1544,
  [SMALL_STATE(75)] = 1557,
  [SMALL_STATE(76)] = 1570,
  [SMALL_STATE(77)] = 1583,
  [SMALL_STATE(78)] = 1596,
  [SMALL_STATE(79)] = 1609,
  [SMALL_STATE(80)] = 1622,
  [SMALL_STATE(81)] = 1635,
  [SMALL_STATE(82)] = 1648,
  [SMALL_STATE(83)] = 1659,
  [SMALL_STATE(84)] = 1670,
  [SMALL_STATE(85)] = 1683,
  [SMALL_STATE(86)] = 1696,
  [SMALL_STATE(87)] = 1709,
  [SMALL_STATE(88)] = 1722,
  [SMALL_STATE(89)] = 1735,
  [SMALL_STATE(90)] = 1748,
  [SMALL_STATE(91)] = 1761,
  [SMALL_STATE(92)] = 1774,
  [SMALL_STATE(93)] = 1784,
  [SMALL_STATE(94)] = 1794,
  [SMALL_STATE(95)] = 1804,
  [SMALL_STATE(96)] = 1814,
  [SMALL_STATE(97)] = 1824,
  [SMALL_STATE(98)] = 1834,
  [SMALL_STATE(99)] = 1844,
  [SMALL_STATE(100)] = 1854,
  [SMALL_STATE(101)] = 1864,
  [SMALL_STATE(102)] = 1874,
  [SMALL_STATE(103)] = 1884,
  [SMALL_STATE(104)] = 1894,
  [SMALL_STATE(105)] = 1904,
  [SMALL_STATE(106)] = 1914,
  [SMALL_STATE(107)] = 1924,
  [SMALL_STATE(108)] = 1934,
  [SMALL_STATE(109)] = 1944,
  [SMALL_STATE(110)] = 1954,
  [SMALL_STATE(111)] = 1964,
  [SMALL_STATE(112)] = 1968,
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
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(110),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [39] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(95),
  [42] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(76),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(110),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(89),
  [64] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(42),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 1, 0, 0),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 1, 0, 0),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__node, 1, 0, 0),
  [73] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__node, 1, 0, 0),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 2, 0, 0),
  [77] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 2, 0, 0),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 2, 0, 0),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 2, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 2, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 2, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 1, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 1, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 3, 0, 0),
  [93] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 3, 0, 0),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_erroneous_end_tag, 3, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_erroneous_end_tag, 3, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 4, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 4, 0, 0),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doctype, 4, 0, 0),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_doctype, 4, 0, 0),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_end_tag, 3, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_end_tag, 3, 0, 0),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_end_tag, 3, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_end_tag, 3, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 3, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 3, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 3, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 3, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_end_tag, 3, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_end_tag, 3, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 3, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 3, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 3, 0, 1),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 3, 0, 1),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 4, 0, 1),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 4, 0, 1),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [143] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [145] = {.entry = {.count = 1, .reusable = false}}, SHIFT(111),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2, 0, 0),
  [151] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2, 0, 0), SHIFT_REPEAT(61),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [158] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [160] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(63),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_comment_repeat1, 2, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1, 0, 0),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_comment_repeat1, 1, 0, 0),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tags, 1, 0, 0),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3, 0, 0),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 3, 0, 0),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [197] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 1, 0, 0),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [207] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [211] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 2, 0, 0),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__start_tag_name, 1, 0, 0),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 4, 0, 0),
  [221] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_start_tag, 4, 0, 0),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 4, 0, 0),
  [225] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_start_tag, 4, 0, 0),
  [227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [231] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__script_start_tag_name, 1, 0, 0),
  [235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__style_start_tag_name, 1, 0, 0),
  [237] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [239] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [241] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 3, 0, 0),
  [249] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_start_tag, 3, 0, 0),
  [251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 3, 0, 0),
  [253] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_start_tag, 3, 0, 0),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__end_tag_name, 1, 0, 0),
  [259] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_erroneous_end_tag_name, 1, 0, 0),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [263] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [269] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [281] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [283] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 3, 0, 0),
  [293] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 2, 0, 0),
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
