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
#define STATE_COUNT 113
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 74
#define ALIAS_COUNT 0
#define TOKEN_COUNT 48
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
  anon_sym_canvas = 29,
  anon_sym_hr = 30,
  anon_sym_bound = 31,
  anon_sym_LT_BANG = 32,
  anon_sym_GT = 33,
  sym__doctype = 34,
  anon_sym_LT = 35,
  anon_sym_LT_SLASH = 36,
  anon_sym_SLASH_GT = 37,
  anon_sym_EQ = 38,
  sym_attribute_name = 39,
  sym_attribute_value = 40,
  sym_entity = 41,
  sym_substitution = 42,
  anon_sym_SQUOTE = 43,
  aux_sym_quoted_attribute_value_token1 = 44,
  anon_sym_DQUOTE = 45,
  aux_sym_quoted_attribute_value_token2 = 46,
  sym_text = 47,
  sym_source_file = 48,
  sym__start_tag_name = 49,
  sym__script_start_tag_name = 50,
  sym__style_start_tag_name = 51,
  sym__end_tag_name = 52,
  sym_erroneous_end_tag_name = 53,
  sym_comment = 54,
  sym_self_closing_tags = 55,
  sym_doctype = 56,
  sym__node = 57,
  sym_element = 58,
  sym_script_element = 59,
  sym_style_element = 60,
  sym_start_tag = 61,
  sym_script_start_tag = 62,
  sym_script_end_tag = 63,
  sym_style_start_tag = 64,
  sym_style_end_tag = 65,
  sym_self_closing_tag = 66,
  sym_end_tag = 67,
  sym_erroneous_end_tag = 68,
  sym_attribute = 69,
  sym_quoted_attribute_value = 70,
  aux_sym_source_file_repeat1 = 71,
  aux_sym_comment_repeat1 = 72,
  aux_sym_start_tag_repeat1 = 73,
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
  [anon_sym_canvas] = "canvas",
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
  [anon_sym_canvas] = anon_sym_canvas,
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
      if (eof) ADVANCE(123);
      ADVANCE_MAP(
        '"', 301,
        '%', 293,
        '&', 5,
        '\'', 295,
        '-', 9,
        '/', 65,
        '<', 246,
        '=', 249,
        '>', 244,
        'D', 115,
        'a', 124,
        'b', 98,
        'c', 67,
        'd', 84,
        'h', 82,
        'l', 85,
        'm', 77,
        'n', 94,
        'o', 87,
        'p', 147,
        's', 73,
        't', 83,
        'u', 88,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '!') ADVANCE(10);
      END_STATE();
    case 2:
      if (lookahead == '!') ADVANCE(10);
      if (lookahead == '/') ADVANCE(247);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(301);
      if (lookahead == '\'') ADVANCE(295);
      if (lookahead == '<') ADVANCE(1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (lookahead != 0 &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(251);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(301);
      if (lookahead == '<') ADVANCE(302);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(305);
      if (lookahead != 0) ADVANCE(306);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(118);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(291);
      END_STATE();
    case 6:
      if (lookahead == '%') ADVANCE(293);
      if (lookahead == '&') ADVANCE(5);
      if (lookahead == '<') ADVANCE(246);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(307);
      END_STATE();
    case 7:
      if (lookahead == '\'') ADVANCE(295);
      if (lookahead == '<') ADVANCE(296);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(299);
      if (lookahead != 0) ADVANCE(300);
      END_STATE();
    case 8:
      if (lookahead == '-') ADVANCE(9);
      if (lookahead == '<') ADVANCE(228);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(229);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 9:
      if (lookahead == '-') ADVANCE(66);
      if (lookahead != 0) ADVANCE(230);
      END_STATE();
    case 10:
      if (lookahead == '-') ADVANCE(11);
      END_STATE();
    case 11:
      if (lookahead == '-') ADVANCE(223);
      END_STATE();
    case 12:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'a') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 13:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'a') ADVANCE(19);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 14:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'a') ADVANCE(234);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 15:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'a') ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 16:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'a') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 17:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'a') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 18:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'c') ADVANCE(47);
      if (lookahead == 'l') ADVANCE(44);
      if (lookahead == 'p') ADVANCE(16);
      if (lookahead == 't') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 19:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'd') ADVANCE(137);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 20:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'd') ADVANCE(242);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 21:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'd') ADVANCE(56);
      if (lookahead == 'u') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 22:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'e') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 23:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'e') ADVANCE(134);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 24:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'e') ADVANCE(184);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 25:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'e') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 26:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'e') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 27:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'e') ADVANCE(13);
      if (lookahead == 'r') ADVANCE(240);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 28:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'e') ADVANCE(38);
      if (lookahead == 'i') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 29:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'i') ADVANCE(54);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 30:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'i') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 31:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'i') ADVANCE(45);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 32:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'l') ADVANCE(152);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 33:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'l') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 34:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'l') ADVANCE(128);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 35:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'l') ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 36:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'l') ADVANCE(25);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 37:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'l') ADVANCE(17);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 38:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'm') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 39:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'm') ADVANCE(34);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 40:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'n') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 41:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'n') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 42:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'n') ADVANCE(20);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 43:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'o') ADVANCE(21);
      if (lookahead == 'r') ADVANCE(236);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 44:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'o') ADVANCE(49);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 45:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'p') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 46:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'p') ADVANCE(37);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 47:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'r') ADVANCE(31);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 48:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 's') ADVANCE(238);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 49:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 't') ADVANCE(164);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 50:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 't') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 51:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 't') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 52:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 't') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 53:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 't') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 54:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'v') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 55:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'v') ADVANCE(15);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 56:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'y') ADVANCE(140);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 57:
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'y') ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 58:
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 59:
      if (lookahead == '-') ADVANCE(175);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(177);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(173);
      END_STATE();
    case 60:
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '<') ADVANCE(1);
      if (lookahead == '=') ADVANCE(249);
      if (lookahead == '>') ADVANCE(244);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(60);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'') ADVANCE(250);
      END_STATE();
    case 61:
      ADVANCE_MAP(
        '<', 1,
        'a', 125,
        'b', 43,
        'c', 12,
        'd', 29,
        'h', 27,
        'l', 30,
        'm', 22,
        'n', 39,
        'o', 32,
        'p', 145,
        's', 18,
        't', 28,
        'u', 33,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(61);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('e' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(59);
      END_STATE();
    case 62:
      ADVANCE_MAP(
        '<', 185,
        'a', 126,
        'b', 207,
        'd', 196,
        'h', 191,
        'l', 197,
        'n', 205,
        'o', 198,
        'p', 146,
        's', 201,
        't', 195,
        'u', 199,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(219);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('c' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(216);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 63:
      if (lookahead == '<') ADVANCE(185);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(220);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 64:
      if (lookahead == '<') ADVANCE(2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(179);
      if (lookahead != 0) ADVANCE(180);
      END_STATE();
    case 65:
      if (lookahead == '>') ADVANCE(248);
      END_STATE();
    case 66:
      if (lookahead == '>') ADVANCE(232);
      if (lookahead != 0) ADVANCE(231);
      END_STATE();
    case 67:
      if (lookahead == 'a') ADVANCE(96);
      END_STATE();
    case 68:
      if (lookahead == 'a') ADVANCE(74);
      END_STATE();
    case 69:
      if (lookahead == 'a') ADVANCE(233);
      END_STATE();
    case 70:
      if (lookahead == 'a') ADVANCE(103);
      END_STATE();
    case 71:
      if (lookahead == 'a') ADVANCE(95);
      END_STATE();
    case 72:
      if (lookahead == 'a') ADVANCE(107);
      END_STATE();
    case 73:
      if (lookahead == 'c') ADVANCE(102);
      if (lookahead == 'l') ADVANCE(99);
      if (lookahead == 'p') ADVANCE(71);
      if (lookahead == 't') ADVANCE(112);
      END_STATE();
    case 74:
      if (lookahead == 'd') ADVANCE(136);
      END_STATE();
    case 75:
      if (lookahead == 'd') ADVANCE(241);
      END_STATE();
    case 76:
      if (lookahead == 'd') ADVANCE(111);
      if (lookahead == 'u') ADVANCE(97);
      END_STATE();
    case 77:
      if (lookahead == 'e') ADVANCE(106);
      END_STATE();
    case 78:
      if (lookahead == 'e') ADVANCE(133);
      END_STATE();
    case 79:
      if (lookahead == 'e') ADVANCE(183);
      END_STATE();
    case 80:
      if (lookahead == 'e') ADVANCE(130);
      END_STATE();
    case 81:
      if (lookahead == 'e') ADVANCE(157);
      END_STATE();
    case 82:
      if (lookahead == 'e') ADVANCE(68);
      if (lookahead == 'r') ADVANCE(239);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(166);
      END_STATE();
    case 83:
      if (lookahead == 'e') ADVANCE(93);
      if (lookahead == 'i') ADVANCE(108);
      END_STATE();
    case 84:
      if (lookahead == 'i') ADVANCE(109);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(113);
      END_STATE();
    case 85:
      if (lookahead == 'i') ADVANCE(160);
      END_STATE();
    case 86:
      if (lookahead == 'i') ADVANCE(100);
      END_STATE();
    case 87:
      if (lookahead == 'l') ADVANCE(151);
      END_STATE();
    case 88:
      if (lookahead == 'l') ADVANCE(154);
      END_STATE();
    case 89:
      if (lookahead == 'l') ADVANCE(127);
      END_STATE();
    case 90:
      if (lookahead == 'l') ADVANCE(79);
      END_STATE();
    case 91:
      if (lookahead == 'l') ADVANCE(80);
      END_STATE();
    case 92:
      if (lookahead == 'l') ADVANCE(72);
      END_STATE();
    case 93:
      if (lookahead == 'm') ADVANCE(101);
      END_STATE();
    case 94:
      if (lookahead == 'm') ADVANCE(89);
      END_STATE();
    case 95:
      if (lookahead == 'n') ADVANCE(148);
      END_STATE();
    case 96:
      if (lookahead == 'n') ADVANCE(110);
      END_STATE();
    case 97:
      if (lookahead == 'n') ADVANCE(75);
      END_STATE();
    case 98:
      if (lookahead == 'o') ADVANCE(76);
      if (lookahead == 'r') ADVANCE(235);
      END_STATE();
    case 99:
      if (lookahead == 'o') ADVANCE(104);
      END_STATE();
    case 100:
      if (lookahead == 'p') ADVANCE(105);
      END_STATE();
    case 101:
      if (lookahead == 'p') ADVANCE(92);
      END_STATE();
    case 102:
      if (lookahead == 'r') ADVANCE(86);
      END_STATE();
    case 103:
      if (lookahead == 's') ADVANCE(237);
      END_STATE();
    case 104:
      if (lookahead == 't') ADVANCE(163);
      END_STATE();
    case 105:
      if (lookahead == 't') ADVANCE(181);
      END_STATE();
    case 106:
      if (lookahead == 't') ADVANCE(69);
      END_STATE();
    case 107:
      if (lookahead == 't') ADVANCE(81);
      END_STATE();
    case 108:
      if (lookahead == 't') ADVANCE(91);
      END_STATE();
    case 109:
      if (lookahead == 'v') ADVANCE(142);
      END_STATE();
    case 110:
      if (lookahead == 'v') ADVANCE(70);
      END_STATE();
    case 111:
      if (lookahead == 'y') ADVANCE(139);
      END_STATE();
    case 112:
      if (lookahead == 'y') ADVANCE(90);
      END_STATE();
    case 113:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(117);
      END_STATE();
    case 114:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(245);
      END_STATE();
    case 115:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(113);
      END_STATE();
    case 116:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(114);
      END_STATE();
    case 117:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(119);
      END_STATE();
    case 118:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(257);
      END_STATE();
    case 119:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(116);
      END_STATE();
    case 120:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(262);
      END_STATE();
    case 121:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(169);
      END_STATE();
    case 122:
      if (eof) ADVANCE(123);
      if (lookahead == '%') ADVANCE(293);
      if (lookahead == '&') ADVANCE(5);
      if (lookahead == '<') ADVANCE(246);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(307);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_a);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_a);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_a);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_nml);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_nml);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_nml);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_title);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_title);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_title);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_pre);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_pre);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_pre);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_head);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_head);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_head);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_body);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_body);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_body);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_div);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_div);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_div);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_p);
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == 'r') ADVANCE(23);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_p);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'r') ADVANCE(192);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_p);
      if (lookahead == 'r') ADVANCE(78);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_span);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_span);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_span);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_ol);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_ol);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_ol);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_ul);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_ul);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_ul);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(anon_sym_template);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_template);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(anon_sym_template);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(anon_sym_li);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_li);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_li);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_slot);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_slot);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_slot);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token1);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token1);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(169);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(175);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(177);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(170);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(171);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(176);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(178);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(172);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '-') ADVANCE(175);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(177);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(173);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '-') ADVANCE(176);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(178);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '+' ||
          lookahead == '-' ||
          lookahead == '/') ADVANCE(177);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(170);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '+' ||
          lookahead == '-' ||
          lookahead == '/') ADVANCE(178);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(172);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '+' ||
          lookahead == '-' ||
          ('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '+' ||
          lookahead == '-' ||
          ('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_raw_text);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(179);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(180);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_raw_text);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(180);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(anon_sym_script);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(anon_sym_style);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(anon_sym_style);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '!') ADVANCE(218);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'a') ADVANCE(206);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'a') ADVANCE(190);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'a') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'd') ADVANCE(214);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'd') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'e') ADVANCE(187);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'e') ADVANCE(135);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'e') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'e') ADVANCE(159);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'e') ADVANCE(204);
      if (lookahead == 'i') ADVANCE(212);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'i') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'i') ADVANCE(162);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'l') ADVANCE(153);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'l') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'l') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'l') ADVANCE(208);
      if (lookahead == 'p') ADVANCE(186);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'l') ADVANCE(193);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'l') ADVANCE(188);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'm') ADVANCE(209);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'm') ADVANCE(200);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'n') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'o') ADVANCE(189);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'o') ADVANCE(210);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'p') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 't') ADVANCE(165);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 't') ADVANCE(194);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 't') ADVANCE(202);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'v') ADVANCE(144);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead == 'y') ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(176);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(178);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(226);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(217);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      ADVANCE_MAP(
        '<', 185,
        'a', 126,
        'b', 207,
        'd', 196,
        'h', 191,
        'l', 197,
        'n', 205,
        'o', 198,
        'p', 146,
        's', 201,
        't', 195,
        'u', 199,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(219);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('c' <= lookahead && lookahead <= 'z')) ADVANCE(215);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(216);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '<') ADVANCE(185);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(220);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(171);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(306);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(300);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(222);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '!') ADVANCE(10);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '<') ADVANCE(228);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(229);
      if (lookahead != 0 &&
          lookahead != '-') ADVANCE(227);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(aux_sym_comment_token2);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(aux_sym_comment_token3);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(anon_sym_DASH_DASH_GT);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(anon_sym_meta);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(anon_sym_meta);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(anon_sym_br);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(anon_sym_br);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(anon_sym_canvas);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(anon_sym_canvas);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(anon_sym_hr);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(anon_sym_hr);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(anon_sym_bound);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(anon_sym_bound);
      if (lookahead == '-') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(anon_sym_LT_BANG);
      if (lookahead == '-') ADVANCE(11);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym__doctype);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '!') ADVANCE(243);
      if (lookahead == '/') ADVANCE(247);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(anon_sym_LT_SLASH);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(anon_sym_SLASH_GT);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(250);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_attribute_value);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(251);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_entity);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(253);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(254);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(255);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(256);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(253);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(258);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(259);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(260);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(261);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(253);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(263);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(264);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(265);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(266);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(267);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(269);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(270);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(271);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(272);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(273);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(274);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(275);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(276);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(277);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(278);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(279);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(280);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(281);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(283);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(284);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(285);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(286);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(287);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(288);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(289);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(290);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_substitution);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_substitution);
      if (lookahead == '%') ADVANCE(292);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_substitution);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '!') ADVANCE(298);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(300);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '-') ADVANCE(225);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(300);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '-') ADVANCE(297);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(300);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '<') ADVANCE(296);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(299);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(300);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(300);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '!') ADVANCE(304);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '"') ADVANCE(306);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '-') ADVANCE(224);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(306);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '-') ADVANCE(303);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(306);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '<') ADVANCE(302);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(305);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(306);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(306);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_text);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(307);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '&' &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(307);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 122},
  [2] = {.lex_state = 61},
  [3] = {.lex_state = 61},
  [4] = {.lex_state = 62},
  [5] = {.lex_state = 62},
  [6] = {.lex_state = 122},
  [7] = {.lex_state = 122},
  [8] = {.lex_state = 122},
  [9] = {.lex_state = 122},
  [10] = {.lex_state = 122},
  [11] = {.lex_state = 122},
  [12] = {.lex_state = 122},
  [13] = {.lex_state = 122},
  [14] = {.lex_state = 122},
  [15] = {.lex_state = 122},
  [16] = {.lex_state = 122},
  [17] = {.lex_state = 122},
  [18] = {.lex_state = 122},
  [19] = {.lex_state = 122},
  [20] = {.lex_state = 122},
  [21] = {.lex_state = 122},
  [22] = {.lex_state = 122},
  [23] = {.lex_state = 122},
  [24] = {.lex_state = 122},
  [25] = {.lex_state = 122},
  [26] = {.lex_state = 122},
  [27] = {.lex_state = 122},
  [28] = {.lex_state = 122},
  [29] = {.lex_state = 122},
  [30] = {.lex_state = 122},
  [31] = {.lex_state = 122},
  [32] = {.lex_state = 122},
  [33] = {.lex_state = 122},
  [34] = {.lex_state = 122},
  [35] = {.lex_state = 122},
  [36] = {.lex_state = 122},
  [37] = {.lex_state = 122},
  [38] = {.lex_state = 122},
  [39] = {.lex_state = 122},
  [40] = {.lex_state = 122},
  [41] = {.lex_state = 122},
  [42] = {.lex_state = 122},
  [43] = {.lex_state = 122},
  [44] = {.lex_state = 122},
  [45] = {.lex_state = 122},
  [46] = {.lex_state = 122},
  [47] = {.lex_state = 60},
  [48] = {.lex_state = 8},
  [49] = {.lex_state = 60},
  [50] = {.lex_state = 60},
  [51] = {.lex_state = 60},
  [52] = {.lex_state = 60},
  [53] = {.lex_state = 8},
  [54] = {.lex_state = 8},
  [55] = {.lex_state = 60},
  [56] = {.lex_state = 60},
  [57] = {.lex_state = 3},
  [58] = {.lex_state = 60},
  [59] = {.lex_state = 60},
  [60] = {.lex_state = 60},
  [61] = {.lex_state = 60},
  [62] = {.lex_state = 60},
  [63] = {.lex_state = 8},
  [64] = {.lex_state = 60},
  [65] = {.lex_state = 60},
  [66] = {.lex_state = 60},
  [67] = {.lex_state = 64},
  [68] = {.lex_state = 60},
  [69] = {.lex_state = 64},
  [70] = {.lex_state = 64},
  [71] = {.lex_state = 64},
  [72] = {.lex_state = 60},
  [73] = {.lex_state = 60},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 64},
  [76] = {.lex_state = 63},
  [77] = {.lex_state = 64},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 60},
  [83] = {.lex_state = 60},
  [84] = {.lex_state = 7},
  [85] = {.lex_state = 4},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 64},
  [89] = {.lex_state = 63},
  [90] = {.lex_state = 64},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 63},
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
  [107] = {.lex_state = 63},
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
    STATE(52), 1,
      sym_self_closing_tags,
    STATE(58), 1,
      sym__script_start_tag_name,
    STATE(59), 1,
      sym__start_tag_name,
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
  [102] = 7,
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
  [140] = 7,
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
  [178] = 14,
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
  [227] = 13,
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
  [274] = 14,
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
  [323] = 14,
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
  [372] = 13,
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
  [419] = 14,
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
  [468] = 12,
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
  [512] = 4,
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
  [530] = 4,
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
  [548] = 4,
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
  [566] = 4,
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
  [584] = 4,
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
  [602] = 4,
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
  [620] = 4,
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
  [638] = 4,
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
  [656] = 4,
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
  [674] = 4,
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
  [692] = 4,
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
  [710] = 4,
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
  [728] = 4,
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
  [746] = 4,
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
  [764] = 4,
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
  [782] = 4,
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
  [800] = 4,
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
  [817] = 4,
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
  [834] = 4,
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
  [851] = 4,
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
  [868] = 4,
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
  [885] = 4,
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
  [902] = 4,
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
  [919] = 4,
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
  [936] = 4,
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
  [953] = 4,
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
  [970] = 4,
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
  [987] = 4,
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
  [1004] = 4,
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
  [1021] = 4,
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
  [1038] = 4,
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
  [1055] = 4,
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
  [1072] = 4,
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
  [1089] = 4,
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
  [1106] = 6,
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
  [1126] = 5,
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
  [1144] = 6,
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
  [1164] = 5,
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
  [1182] = 6,
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
  [1202] = 6,
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
  [1222] = 5,
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
  [1240] = 4,
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
  [1256] = 6,
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
  [1275] = 6,
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
  [1294] = 6,
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
  [1313] = 6,
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
  [1332] = 6,
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
  [1351] = 6,
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
  [1370] = 4,
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
  [1385] = 6,
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
  [1404] = 3,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(63), 1,
      sym_comment,
    ACTIONS(185), 4,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
      anon_sym_DASH_DASH_GT,
  [1417] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(64), 1,
      sym_comment,
    ACTIONS(187), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1429] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(65), 1,
      sym_comment,
    ACTIONS(189), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1441] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(66), 1,
      sym_comment,
    ACTIONS(191), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1453] = 5,
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
  [1469] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(68), 1,
      sym_comment,
    ACTIONS(197), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1481] = 5,
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
  [1497] = 5,
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
  [1513] = 5,
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
  [1529] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(72), 1,
      sym_comment,
    ACTIONS(211), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1541] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(73), 1,
      sym_comment,
    ACTIONS(213), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1552] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(215), 1,
      anon_sym_style,
    STATE(74), 1,
      sym_comment,
    STATE(104), 1,
      sym__style_start_tag_name,
  [1565] = 4,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(217), 1,
      sym_raw_text,
    ACTIONS(219), 1,
      anon_sym_LT_SLASH,
    STATE(75), 1,
      sym_comment,
  [1578] = 4,
    ACTIONS(23), 1,
      aux_sym_erroneous_end_tag_name_token1,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(76), 1,
      sym_comment,
    STATE(109), 1,
      sym_erroneous_end_tag_name,
  [1591] = 4,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(221), 1,
      sym_raw_text,
    ACTIONS(223), 1,
      anon_sym_LT_SLASH,
    STATE(77), 1,
      sym_comment,
  [1604] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(225), 1,
      anon_sym_LT_SLASH,
    STATE(26), 1,
      sym_script_end_tag,
    STATE(78), 1,
      sym_comment,
  [1617] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(227), 1,
      anon_sym_script,
    STATE(79), 1,
      sym_comment,
    STATE(101), 1,
      sym__script_start_tag_name,
  [1630] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(229), 1,
      anon_sym_LT_SLASH,
    STATE(25), 1,
      sym_style_end_tag,
    STATE(80), 1,
      sym_comment,
  [1643] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(215), 1,
      anon_sym_style,
    STATE(81), 1,
      sym_comment,
    STATE(108), 1,
      sym__style_start_tag_name,
  [1656] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(82), 1,
      sym_comment,
    ACTIONS(231), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1667] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(83), 1,
      sym_comment,
    ACTIONS(233), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1678] = 4,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(235), 1,
      anon_sym_SQUOTE,
    ACTIONS(237), 1,
      aux_sym_quoted_attribute_value_token1,
    STATE(84), 1,
      sym_comment,
  [1691] = 4,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(235), 1,
      anon_sym_DQUOTE,
    ACTIONS(239), 1,
      aux_sym_quoted_attribute_value_token2,
    STATE(85), 1,
      sym_comment,
  [1704] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(241), 1,
      anon_sym_LT_SLASH,
    STATE(29), 1,
      sym_script_end_tag,
    STATE(86), 1,
      sym_comment,
  [1717] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(243), 1,
      anon_sym_LT_SLASH,
    STATE(36), 1,
      sym_style_end_tag,
    STATE(87), 1,
      sym_comment,
  [1730] = 4,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(245), 1,
      sym_raw_text,
    ACTIONS(247), 1,
      anon_sym_LT_SLASH,
    STATE(88), 1,
      sym_comment,
  [1743] = 4,
    ACTIONS(23), 1,
      aux_sym_erroneous_end_tag_name_token1,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(89), 1,
      sym_comment,
    STATE(97), 1,
      sym_erroneous_end_tag_name,
  [1756] = 4,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(249), 1,
      sym_raw_text,
    ACTIONS(251), 1,
      anon_sym_LT_SLASH,
    STATE(90), 1,
      sym_comment,
  [1769] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(227), 1,
      anon_sym_script,
    STATE(91), 1,
      sym_comment,
    STATE(103), 1,
      sym__script_start_tag_name,
  [1782] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(253), 1,
      anon_sym_GT,
    STATE(92), 1,
      sym_comment,
  [1792] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(255), 1,
      anon_sym_GT,
    STATE(93), 1,
      sym_comment,
  [1802] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(257), 1,
      anon_sym_GT,
    STATE(94), 1,
      sym_comment,
  [1812] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(259), 1,
      sym__doctype,
    STATE(95), 1,
      sym_comment,
  [1822] = 3,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(261), 1,
      aux_sym_erroneous_end_tag_name_token1,
    STATE(96), 1,
      sym_comment,
  [1832] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(263), 1,
      anon_sym_GT,
    STATE(97), 1,
      sym_comment,
  [1842] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    STATE(98), 1,
      sym_comment,
  [1852] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(267), 1,
      ts_builtin_sym_end,
    STATE(99), 1,
      sym_comment,
  [1862] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(269), 1,
      anon_sym_GT,
    STATE(100), 1,
      sym_comment,
  [1872] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(271), 1,
      anon_sym_GT,
    STATE(101), 1,
      sym_comment,
  [1882] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(273), 1,
      anon_sym_GT,
    STATE(102), 1,
      sym_comment,
  [1892] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(275), 1,
      anon_sym_GT,
    STATE(103), 1,
      sym_comment,
  [1902] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(277), 1,
      anon_sym_GT,
    STATE(104), 1,
      sym_comment,
  [1912] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(265), 1,
      anon_sym_DQUOTE,
    STATE(105), 1,
      sym_comment,
  [1922] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(279), 1,
      anon_sym_GT,
    STATE(106), 1,
      sym_comment,
  [1932] = 3,
    ACTIONS(25), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(281), 1,
      aux_sym_erroneous_end_tag_name_token1,
    STATE(107), 1,
      sym_comment,
  [1942] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(283), 1,
      anon_sym_GT,
    STATE(108), 1,
      sym_comment,
  [1952] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(285), 1,
      anon_sym_GT,
    STATE(109), 1,
      sym_comment,
  [1962] = 3,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(287), 1,
      sym__doctype,
    STATE(110), 1,
      sym_comment,
  [1972] = 1,
    ACTIONS(289), 1,
      ts_builtin_sym_end,
  [1976] = 1,
    ACTIONS(291), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 51,
  [SMALL_STATE(4)] = 102,
  [SMALL_STATE(5)] = 140,
  [SMALL_STATE(6)] = 178,
  [SMALL_STATE(7)] = 227,
  [SMALL_STATE(8)] = 274,
  [SMALL_STATE(9)] = 323,
  [SMALL_STATE(10)] = 372,
  [SMALL_STATE(11)] = 419,
  [SMALL_STATE(12)] = 468,
  [SMALL_STATE(13)] = 512,
  [SMALL_STATE(14)] = 530,
  [SMALL_STATE(15)] = 548,
  [SMALL_STATE(16)] = 566,
  [SMALL_STATE(17)] = 584,
  [SMALL_STATE(18)] = 602,
  [SMALL_STATE(19)] = 620,
  [SMALL_STATE(20)] = 638,
  [SMALL_STATE(21)] = 656,
  [SMALL_STATE(22)] = 674,
  [SMALL_STATE(23)] = 692,
  [SMALL_STATE(24)] = 710,
  [SMALL_STATE(25)] = 728,
  [SMALL_STATE(26)] = 746,
  [SMALL_STATE(27)] = 764,
  [SMALL_STATE(28)] = 782,
  [SMALL_STATE(29)] = 800,
  [SMALL_STATE(30)] = 817,
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
  [SMALL_STATE(46)] = 1089,
  [SMALL_STATE(47)] = 1106,
  [SMALL_STATE(48)] = 1126,
  [SMALL_STATE(49)] = 1144,
  [SMALL_STATE(50)] = 1164,
  [SMALL_STATE(51)] = 1182,
  [SMALL_STATE(52)] = 1202,
  [SMALL_STATE(53)] = 1222,
  [SMALL_STATE(54)] = 1240,
  [SMALL_STATE(55)] = 1256,
  [SMALL_STATE(56)] = 1275,
  [SMALL_STATE(57)] = 1294,
  [SMALL_STATE(58)] = 1313,
  [SMALL_STATE(59)] = 1332,
  [SMALL_STATE(60)] = 1351,
  [SMALL_STATE(61)] = 1370,
  [SMALL_STATE(62)] = 1385,
  [SMALL_STATE(63)] = 1404,
  [SMALL_STATE(64)] = 1417,
  [SMALL_STATE(65)] = 1429,
  [SMALL_STATE(66)] = 1441,
  [SMALL_STATE(67)] = 1453,
  [SMALL_STATE(68)] = 1469,
  [SMALL_STATE(69)] = 1481,
  [SMALL_STATE(70)] = 1497,
  [SMALL_STATE(71)] = 1513,
  [SMALL_STATE(72)] = 1529,
  [SMALL_STATE(73)] = 1541,
  [SMALL_STATE(74)] = 1552,
  [SMALL_STATE(75)] = 1565,
  [SMALL_STATE(76)] = 1578,
  [SMALL_STATE(77)] = 1591,
  [SMALL_STATE(78)] = 1604,
  [SMALL_STATE(79)] = 1617,
  [SMALL_STATE(80)] = 1630,
  [SMALL_STATE(81)] = 1643,
  [SMALL_STATE(82)] = 1656,
  [SMALL_STATE(83)] = 1667,
  [SMALL_STATE(84)] = 1678,
  [SMALL_STATE(85)] = 1691,
  [SMALL_STATE(86)] = 1704,
  [SMALL_STATE(87)] = 1717,
  [SMALL_STATE(88)] = 1730,
  [SMALL_STATE(89)] = 1743,
  [SMALL_STATE(90)] = 1756,
  [SMALL_STATE(91)] = 1769,
  [SMALL_STATE(92)] = 1782,
  [SMALL_STATE(93)] = 1792,
  [SMALL_STATE(94)] = 1802,
  [SMALL_STATE(95)] = 1812,
  [SMALL_STATE(96)] = 1822,
  [SMALL_STATE(97)] = 1832,
  [SMALL_STATE(98)] = 1842,
  [SMALL_STATE(99)] = 1852,
  [SMALL_STATE(100)] = 1862,
  [SMALL_STATE(101)] = 1872,
  [SMALL_STATE(102)] = 1882,
  [SMALL_STATE(103)] = 1892,
  [SMALL_STATE(104)] = 1902,
  [SMALL_STATE(105)] = 1912,
  [SMALL_STATE(106)] = 1922,
  [SMALL_STATE(107)] = 1932,
  [SMALL_STATE(108)] = 1942,
  [SMALL_STATE(109)] = 1952,
  [SMALL_STATE(110)] = 1962,
  [SMALL_STATE(111)] = 1972,
  [SMALL_STATE(112)] = 1976,
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
