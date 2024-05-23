#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 100
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 58
#define ALIAS_COUNT 0
#define TOKEN_COUNT 36
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 2

enum {
  anon_sym_nml = 1,
  anon_sym_head = 2,
  anon_sym_body = 3,
  anon_sym_div = 4,
  anon_sym_p = 5,
  anon_sym_span = 6,
  anon_sym_a = 7,
  anon_sym_ol = 8,
  anon_sym_li = 9,
  aux_sym__start_tag_name_token1 = 10,
  aux_sym__start_tag_name_token2 = 11,
  sym_raw_text = 12,
  sym__script_start_tag_name = 13,
  sym__style_start_tag_name = 14,
  aux_sym_erroneous_end_tag_name_token1 = 15,
  sym_comment = 16,
  anon_sym_img = 17,
  anon_sym_br = 18,
  anon_sym_hr = 19,
  anon_sym_bound = 20,
  anon_sym_LT_BANG = 21,
  anon_sym_GT = 22,
  sym__doctype = 23,
  anon_sym_LT = 24,
  anon_sym_LT_SLASH = 25,
  anon_sym_SLASH_GT = 26,
  anon_sym_EQ = 27,
  sym_attribute_name = 28,
  sym_attribute_value = 29,
  sym_entity = 30,
  anon_sym_SQUOTE = 31,
  aux_sym_quoted_attribute_value_token1 = 32,
  anon_sym_DQUOTE = 33,
  aux_sym_quoted_attribute_value_token2 = 34,
  sym_text = 35,
  sym_source_file = 36,
  sym__start_tag_name = 37,
  sym__end_tag_name = 38,
  sym_erroneous_end_tag_name = 39,
  sym_self_closing_tags = 40,
  sym_doctype = 41,
  sym__node = 42,
  sym_element = 43,
  sym_script_element = 44,
  sym_style_element = 45,
  sym_start_tag = 46,
  sym_script_start_tag = 47,
  sym_script_end_tag = 48,
  sym_style_start_tag = 49,
  sym_style_end_tag = 50,
  sym_self_closing_tag = 51,
  sym_end_tag = 52,
  sym_erroneous_end_tag = 53,
  sym_attribute = 54,
  sym_quoted_attribute_value = 55,
  aux_sym_source_file_repeat1 = 56,
  aux_sym_start_tag_repeat1 = 57,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_nml] = "nml",
  [anon_sym_head] = "head",
  [anon_sym_body] = "body",
  [anon_sym_div] = "div",
  [anon_sym_p] = "p",
  [anon_sym_span] = "span",
  [anon_sym_a] = "a",
  [anon_sym_ol] = "ol",
  [anon_sym_li] = "li",
  [aux_sym__start_tag_name_token1] = "_start_tag_name_token1",
  [aux_sym__start_tag_name_token2] = "_start_tag_name_token2",
  [sym_raw_text] = "raw_text",
  [sym__script_start_tag_name] = "tag_name",
  [sym__style_start_tag_name] = "tag_name",
  [aux_sym_erroneous_end_tag_name_token1] = "erroneous_end_tag_name_token1",
  [sym_comment] = "comment",
  [anon_sym_img] = "img",
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
  [aux_sym_start_tag_repeat1] = "start_tag_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_nml] = anon_sym_nml,
  [anon_sym_head] = anon_sym_head,
  [anon_sym_body] = anon_sym_body,
  [anon_sym_div] = anon_sym_div,
  [anon_sym_p] = anon_sym_p,
  [anon_sym_span] = anon_sym_span,
  [anon_sym_a] = anon_sym_a,
  [anon_sym_ol] = anon_sym_ol,
  [anon_sym_li] = anon_sym_li,
  [aux_sym__start_tag_name_token1] = aux_sym__start_tag_name_token1,
  [aux_sym__start_tag_name_token2] = aux_sym__start_tag_name_token2,
  [sym_raw_text] = sym_raw_text,
  [sym__script_start_tag_name] = sym__script_start_tag_name,
  [sym__style_start_tag_name] = sym__script_start_tag_name,
  [aux_sym_erroneous_end_tag_name_token1] = aux_sym_erroneous_end_tag_name_token1,
  [sym_comment] = sym_comment,
  [anon_sym_img] = anon_sym_img,
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
  [anon_sym_a] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ol] = {
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
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_img] = {
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
  [8] = 4,
  [9] = 5,
  [10] = 6,
  [11] = 11,
  [12] = 11,
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
  [27] = 15,
  [28] = 16,
  [29] = 29,
  [30] = 23,
  [31] = 25,
  [32] = 21,
  [33] = 26,
  [34] = 22,
  [35] = 13,
  [36] = 36,
  [37] = 20,
  [38] = 38,
  [39] = 29,
  [40] = 24,
  [41] = 14,
  [42] = 42,
  [43] = 17,
  [44] = 18,
  [45] = 45,
  [46] = 19,
  [47] = 38,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 58,
  [60] = 57,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 66,
  [70] = 70,
  [71] = 70,
  [72] = 72,
  [73] = 64,
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
  [88] = 84,
  [89] = 89,
  [90] = 77,
  [91] = 82,
  [92] = 89,
  [93] = 93,
  [94] = 94,
  [95] = 83,
  [96] = 78,
  [97] = 87,
  [98] = 94,
  [99] = 86,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(82);
      if (lookahead == '"') ADVANCE(216);
      if (lookahead == '&') ADVANCE(5);
      if (lookahead == '\'') ADVANCE(207);
      if (lookahead == '/') ADVANCE(44);
      if (lookahead == '<') ADVANCE(161);
      if (lookahead == '=') ADVANCE(164);
      if (lookahead == '>') ADVANCE(159);
      if (lookahead == 'D') ADVANCE(74);
      if (lookahead == 'a') ADVANCE(101);
      if (lookahead == 'b') ADVANCE(65);
      if (lookahead == 'd') ADVANCE(55);
      if (lookahead == 'h') ADVANCE(52);
      if (lookahead == 'i') ADVANCE(61);
      if (lookahead == 'l') ADVANCE(56);
      if (lookahead == 'n') ADVANCE(62);
      if (lookahead == 'o') ADVANCE(58);
      if (lookahead == 'p') ADVANCE(95);
      if (lookahead == 's') ADVANCE(48);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == '!') ADVANCE(8);
      END_STATE();
    case 2:
      if (lookahead == '!') ADVANCE(8);
      if (lookahead == '/') ADVANCE(162);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(216);
      if (lookahead == '\'') ADVANCE(207);
      if (lookahead == '<') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (lookahead != 0 &&
          lookahead != '=' &&
          lookahead != '>') ADVANCE(166);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(216);
      if (lookahead == '<') ADVANCE(217);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(222);
      if (lookahead != 0) ADVANCE(224);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 6:
      if (lookahead == '&') ADVANCE(5);
      if (lookahead == '<') ADVANCE(161);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(225);
      END_STATE();
    case 7:
      if (lookahead == '\'') ADVANCE(207);
      if (lookahead == '<') ADVANCE(208);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(213);
      if (lookahead != 0) ADVANCE(215);
      END_STATE();
    case 8:
      if (lookahead == '-') ADVANCE(9);
      END_STATE();
    case 9:
      if (lookahead == '-') ADVANCE(38);
      END_STATE();
    case 10:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'a') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 11:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'a') ADVANCE(27);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 12:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'c') ADVANCE(31);
      if (lookahead == 'p') ADVANCE(11);
      if (lookahead == 't') ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 13:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'd') ADVANCE(87);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 14:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'd') ADVANCE(157);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 15:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'd') ADVANCE(34);
      if (lookahead == 'u') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 16:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'e') ADVANCE(10);
      if (lookahead == 'r') ADVANCE(155);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 17:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'e') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 18:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'g') ADVANCE(151);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 19:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'i') ADVANCE(33);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 20:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'i') ADVANCE(108);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 21:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'i') ADVANCE(30);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 22:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'l') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 23:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'l') ADVANCE(84);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 24:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'l') ADVANCE(17);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 25:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'm') ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 26:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'm') ADVANCE(23);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 27:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'n') ADVANCE(99);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 28:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'n') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 29:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'o') ADVANCE(15);
      if (lookahead == 'r') ADVANCE(153);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 30:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'p') ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 31:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'r') ADVANCE(21);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 32:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 't') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 33:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'v') ADVANCE(93);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 34:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'y') ADVANCE(90);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 35:
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == 'y') ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 36:
      if (lookahead == '-') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 37:
      if (lookahead == '-') ADVANCE(45);
      END_STATE();
    case 38:
      if (lookahead == '-') ADVANCE(37);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(38);
      END_STATE();
    case 39:
      if (lookahead == '/') ADVANCE(44);
      if (lookahead == '<') ADVANCE(1);
      if (lookahead == '=') ADVANCE(164);
      if (lookahead == '>') ADVANCE(159);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(39)
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'') ADVANCE(165);
      END_STATE();
    case 40:
      if (lookahead == '<') ADVANCE(1);
      if (lookahead == 'a') ADVANCE(102);
      if (lookahead == 'b') ADVANCE(29);
      if (lookahead == 'd') ADVANCE(19);
      if (lookahead == 'h') ADVANCE(16);
      if (lookahead == 'i') ADVANCE(25);
      if (lookahead == 'l') ADVANCE(20);
      if (lookahead == 'n') ADVANCE(26);
      if (lookahead == 'o') ADVANCE(22);
      if (lookahead == 'p') ADVANCE(96);
      if (lookahead == 's') ADVANCE(12);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(40)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('c' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 41:
      if (lookahead == '<') ADVANCE(121);
      if (lookahead == 'a') ADVANCE(103);
      if (lookahead == 'b') ADVANCE(133);
      if (lookahead == 'd') ADVANCE(127);
      if (lookahead == 'h') ADVANCE(126);
      if (lookahead == 'l') ADVANCE(128);
      if (lookahead == 'n') ADVANCE(131);
      if (lookahead == 'o') ADVANCE(129);
      if (lookahead == 'p') ADVANCE(97);
      if (lookahead == 's') ADVANCE(134);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(142);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('c' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 42:
      if (lookahead == '<') ADVANCE(121);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(143);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 43:
      if (lookahead == '<') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(115);
      if (lookahead != 0) ADVANCE(116);
      END_STATE();
    case 44:
      if (lookahead == '>') ADVANCE(163);
      END_STATE();
    case 45:
      if (lookahead == '>') ADVANCE(147);
      END_STATE();
    case 46:
      if (lookahead == 'a') ADVANCE(49);
      END_STATE();
    case 47:
      if (lookahead == 'a') ADVANCE(63);
      END_STATE();
    case 48:
      if (lookahead == 'c') ADVANCE(67);
      if (lookahead == 'p') ADVANCE(47);
      if (lookahead == 't') ADVANCE(71);
      END_STATE();
    case 49:
      if (lookahead == 'd') ADVANCE(86);
      END_STATE();
    case 50:
      if (lookahead == 'd') ADVANCE(156);
      END_STATE();
    case 51:
      if (lookahead == 'd') ADVANCE(70);
      if (lookahead == 'u') ADVANCE(64);
      END_STATE();
    case 52:
      if (lookahead == 'e') ADVANCE(46);
      if (lookahead == 'r') ADVANCE(154);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(110);
      END_STATE();
    case 53:
      if (lookahead == 'e') ADVANCE(119);
      END_STATE();
    case 54:
      if (lookahead == 'g') ADVANCE(150);
      END_STATE();
    case 55:
      if (lookahead == 'i') ADVANCE(69);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(72);
      END_STATE();
    case 56:
      if (lookahead == 'i') ADVANCE(107);
      END_STATE();
    case 57:
      if (lookahead == 'i') ADVANCE(66);
      END_STATE();
    case 58:
      if (lookahead == 'l') ADVANCE(104);
      END_STATE();
    case 59:
      if (lookahead == 'l') ADVANCE(83);
      END_STATE();
    case 60:
      if (lookahead == 'l') ADVANCE(53);
      END_STATE();
    case 61:
      if (lookahead == 'm') ADVANCE(54);
      END_STATE();
    case 62:
      if (lookahead == 'm') ADVANCE(59);
      END_STATE();
    case 63:
      if (lookahead == 'n') ADVANCE(98);
      END_STATE();
    case 64:
      if (lookahead == 'n') ADVANCE(50);
      END_STATE();
    case 65:
      if (lookahead == 'o') ADVANCE(51);
      if (lookahead == 'r') ADVANCE(152);
      END_STATE();
    case 66:
      if (lookahead == 'p') ADVANCE(68);
      END_STATE();
    case 67:
      if (lookahead == 'r') ADVANCE(57);
      END_STATE();
    case 68:
      if (lookahead == 't') ADVANCE(117);
      END_STATE();
    case 69:
      if (lookahead == 'v') ADVANCE(92);
      END_STATE();
    case 70:
      if (lookahead == 'y') ADVANCE(89);
      END_STATE();
    case 71:
      if (lookahead == 'y') ADVANCE(60);
      END_STATE();
    case 72:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(76);
      END_STATE();
    case 73:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(160);
      END_STATE();
    case 74:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(72);
      END_STATE();
    case 75:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(73);
      END_STATE();
    case 76:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(78);
      END_STATE();
    case 77:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(79);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(172);
      END_STATE();
    case 78:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(75);
      END_STATE();
    case 79:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(177);
      END_STATE();
    case 80:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(113);
      END_STATE();
    case 81:
      if (eof) ADVANCE(82);
      if (lookahead == '&') ADVANCE(5);
      if (lookahead == '<') ADVANCE(161);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(225);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_nml);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_nml);
      if (lookahead == '-') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_nml);
      if (lookahead == '-') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_head);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_head);
      if (lookahead == '-') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_head);
      if (lookahead == '-') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_body);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_body);
      if (lookahead == '-') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_body);
      if (lookahead == '-') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_div);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_div);
      if (lookahead == '-') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_div);
      if (lookahead == '-') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_p);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_p);
      if (lookahead == '-') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_p);
      if (lookahead == '-') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_span);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_span);
      if (lookahead == '-') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_span);
      if (lookahead == '-') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_a);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_a);
      if (lookahead == '-') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_a);
      if (lookahead == '-') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_ol);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_ol);
      if (lookahead == '-') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_ol);
      if (lookahead == '-') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_li);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_li);
      if (lookahead == '-') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_li);
      if (lookahead == '-') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token1);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token1);
      if (lookahead == '-') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token1);
      if (lookahead == '-') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(113);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(114);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_raw_text);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(115);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(116);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_raw_text);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(116);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym__script_start_tag_name);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym__script_start_tag_name);
      if (lookahead == '-') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym__style_start_tag_name);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym__style_start_tag_name);
      if (lookahead == '-') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '!') ADVANCE(140);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(145);
      if (lookahead == 'a') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(145);
      if (lookahead == 'a') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(145);
      if (lookahead == 'd') ADVANCE(136);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(145);
      if (lookahead == 'd') ADVANCE(88);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(145);
      if (lookahead == 'e') ADVANCE(123);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(145);
      if (lookahead == 'i') ADVANCE(135);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(145);
      if (lookahead == 'i') ADVANCE(109);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(145);
      if (lookahead == 'l') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(145);
      if (lookahead == 'l') ADVANCE(85);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(145);
      if (lookahead == 'm') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(145);
      if (lookahead == 'n') ADVANCE(100);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(145);
      if (lookahead == 'o') ADVANCE(124);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(145);
      if (lookahead == 'p') ADVANCE(122);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(145);
      if (lookahead == 'v') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(145);
      if (lookahead == 'y') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(141);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(144);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(138);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '-') ADVANCE(139);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(141);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '<') ADVANCE(121);
      if (lookahead == 'a') ADVANCE(103);
      if (lookahead == 'b') ADVANCE(133);
      if (lookahead == 'd') ADVANCE(127);
      if (lookahead == 'h') ADVANCE(126);
      if (lookahead == 'l') ADVANCE(128);
      if (lookahead == 'n') ADVANCE(131);
      if (lookahead == 'o') ADVANCE(129);
      if (lookahead == 'p') ADVANCE(97);
      if (lookahead == 's') ADVANCE(134);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(142);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('c' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '<') ADVANCE(121);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(143);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead == '>') ADVANCE(147);
      if (lookahead != 0) ADVANCE(146);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(114);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(aux_sym_erroneous_end_tag_name_token1);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(146);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(224);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(215);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_img);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_img);
      if (lookahead == '-') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_br);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_br);
      if (lookahead == '-') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_hr);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_hr);
      if (lookahead == '-') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_bound);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(anon_sym_bound);
      if (lookahead == '-') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_LT_BANG);
      if (lookahead == '-') ADVANCE(9);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym__doctype);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '!') ADVANCE(158);
      if (lookahead == '/') ADVANCE(162);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_LT_SLASH);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_SLASH_GT);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym_attribute_value);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(166);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym_entity);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(168);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(169);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(170);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(171);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(168);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(173);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(174);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(175);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(176);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(179);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(180);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(181);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(182);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(184);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(185);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(186);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(188);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(189);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(190);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(191);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(192);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(193);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(194);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(195);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(196);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(197);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(198);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(199);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(200);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(201);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(203);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '!') ADVANCE(211);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(215);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '-') ADVANCE(212);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(215);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '-') ADVANCE(214);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(215);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '-') ADVANCE(209);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(215);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '-') ADVANCE(210);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(212);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(215);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '<') ADVANCE(208);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(213);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(215);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '>') ADVANCE(149);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(215);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(215);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '!') ADVANCE(220);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(224);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '-') ADVANCE(221);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(224);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '-') ADVANCE(223);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(224);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '-') ADVANCE(218);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(224);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '-') ADVANCE(219);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(221);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(224);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '<') ADVANCE(217);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(222);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(224);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '>') ADVANCE(148);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(224);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(224);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_text);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(225);
      if (lookahead != 0 &&
          lookahead != '&' &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(225);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 81},
  [2] = {.lex_state = 40},
  [3] = {.lex_state = 40},
  [4] = {.lex_state = 81},
  [5] = {.lex_state = 81},
  [6] = {.lex_state = 81},
  [7] = {.lex_state = 81},
  [8] = {.lex_state = 81},
  [9] = {.lex_state = 81},
  [10] = {.lex_state = 81},
  [11] = {.lex_state = 41},
  [12] = {.lex_state = 41},
  [13] = {.lex_state = 81},
  [14] = {.lex_state = 81},
  [15] = {.lex_state = 81},
  [16] = {.lex_state = 81},
  [17] = {.lex_state = 81},
  [18] = {.lex_state = 81},
  [19] = {.lex_state = 81},
  [20] = {.lex_state = 81},
  [21] = {.lex_state = 81},
  [22] = {.lex_state = 81},
  [23] = {.lex_state = 81},
  [24] = {.lex_state = 81},
  [25] = {.lex_state = 81},
  [26] = {.lex_state = 81},
  [27] = {.lex_state = 81},
  [28] = {.lex_state = 81},
  [29] = {.lex_state = 39},
  [30] = {.lex_state = 81},
  [31] = {.lex_state = 81},
  [32] = {.lex_state = 81},
  [33] = {.lex_state = 81},
  [34] = {.lex_state = 81},
  [35] = {.lex_state = 81},
  [36] = {.lex_state = 81},
  [37] = {.lex_state = 81},
  [38] = {.lex_state = 39},
  [39] = {.lex_state = 39},
  [40] = {.lex_state = 81},
  [41] = {.lex_state = 81},
  [42] = {.lex_state = 81},
  [43] = {.lex_state = 81},
  [44] = {.lex_state = 81},
  [45] = {.lex_state = 39},
  [46] = {.lex_state = 81},
  [47] = {.lex_state = 39},
  [48] = {.lex_state = 3},
  [49] = {.lex_state = 39},
  [50] = {.lex_state = 39},
  [51] = {.lex_state = 39},
  [52] = {.lex_state = 39},
  [53] = {.lex_state = 39},
  [54] = {.lex_state = 39},
  [55] = {.lex_state = 39},
  [56] = {.lex_state = 39},
  [57] = {.lex_state = 43},
  [58] = {.lex_state = 43},
  [59] = {.lex_state = 43},
  [60] = {.lex_state = 43},
  [61] = {.lex_state = 39},
  [62] = {.lex_state = 39},
  [63] = {.lex_state = 39},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 4},
  [66] = {.lex_state = 42},
  [67] = {.lex_state = 43},
  [68] = {.lex_state = 43},
  [69] = {.lex_state = 42},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 43},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 7},
  [75] = {.lex_state = 39},
  [76] = {.lex_state = 43},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 42},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 42},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_nml] = ACTIONS(1),
    [anon_sym_head] = ACTIONS(1),
    [anon_sym_body] = ACTIONS(1),
    [anon_sym_div] = ACTIONS(1),
    [anon_sym_p] = ACTIONS(1),
    [anon_sym_span] = ACTIONS(1),
    [anon_sym_a] = ACTIONS(1),
    [anon_sym_ol] = ACTIONS(1),
    [anon_sym_li] = ACTIONS(1),
    [aux_sym__start_tag_name_token1] = ACTIONS(1),
    [sym__script_start_tag_name] = ACTIONS(1),
    [sym__style_start_tag_name] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [anon_sym_img] = ACTIONS(1),
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
    [sym_source_file] = STATE(93),
    [sym_doctype] = STATE(7),
    [sym__node] = STATE(7),
    [sym_element] = STATE(7),
    [sym_script_element] = STATE(7),
    [sym_style_element] = STATE(7),
    [sym_start_tag] = STATE(4),
    [sym_script_start_tag] = STATE(57),
    [sym_style_start_tag] = STATE(58),
    [sym_self_closing_tag] = STATE(26),
    [sym_erroneous_end_tag] = STATE(7),
    [aux_sym_source_file_repeat1] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_comment] = ACTIONS(3),
    [anon_sym_LT_BANG] = ACTIONS(7),
    [anon_sym_LT] = ACTIONS(9),
    [anon_sym_LT_SLASH] = ACTIONS(11),
    [sym_entity] = ACTIONS(13),
    [sym_text] = ACTIONS(13),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      aux_sym__start_tag_name_token2,
    ACTIONS(19), 1,
      sym__script_start_tag_name,
    ACTIONS(21), 1,
      sym__style_start_tag_name,
    STATE(38), 1,
      sym_self_closing_tags,
    STATE(53), 1,
      sym__start_tag_name,
    ACTIONS(23), 4,
      anon_sym_img,
      anon_sym_br,
      anon_sym_hr,
      anon_sym_bound,
    ACTIONS(15), 10,
      anon_sym_nml,
      anon_sym_head,
      anon_sym_body,
      anon_sym_div,
      anon_sym_p,
      anon_sym_span,
      anon_sym_a,
      anon_sym_ol,
      anon_sym_li,
      aux_sym__start_tag_name_token1,
  [37] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      aux_sym__start_tag_name_token2,
    ACTIONS(19), 1,
      sym__script_start_tag_name,
    ACTIONS(21), 1,
      sym__style_start_tag_name,
    STATE(47), 1,
      sym_self_closing_tags,
    STATE(53), 1,
      sym__start_tag_name,
    ACTIONS(23), 4,
      anon_sym_img,
      anon_sym_br,
      anon_sym_hr,
      anon_sym_bound,
    ACTIONS(15), 10,
      anon_sym_nml,
      anon_sym_head,
      anon_sym_body,
      anon_sym_div,
      anon_sym_p,
      anon_sym_span,
      anon_sym_a,
      anon_sym_ol,
      anon_sym_li,
      aux_sym__start_tag_name_token1,
  [74] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LT_BANG,
    ACTIONS(27), 1,
      anon_sym_LT,
    ACTIONS(29), 1,
      anon_sym_LT_SLASH,
    STATE(8), 1,
      sym_start_tag,
    STATE(21), 1,
      sym_end_tag,
    STATE(33), 1,
      sym_self_closing_tag,
    STATE(59), 1,
      sym_style_start_tag,
    STATE(60), 1,
      sym_script_start_tag,
    ACTIONS(31), 2,
      sym_entity,
      sym_text,
    STATE(9), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_source_file_repeat1,
  [115] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LT_BANG,
    ACTIONS(27), 1,
      anon_sym_LT,
    ACTIONS(33), 1,
      anon_sym_LT_SLASH,
    STATE(8), 1,
      sym_start_tag,
    STATE(33), 1,
      sym_self_closing_tag,
    STATE(34), 1,
      sym_end_tag,
    STATE(59), 1,
      sym_style_start_tag,
    STATE(60), 1,
      sym_script_start_tag,
    ACTIONS(35), 2,
      sym_entity,
      sym_text,
    STATE(10), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_source_file_repeat1,
  [156] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(37), 1,
      ts_builtin_sym_end,
    ACTIONS(39), 1,
      anon_sym_LT_BANG,
    ACTIONS(42), 1,
      anon_sym_LT,
    ACTIONS(45), 1,
      anon_sym_LT_SLASH,
    STATE(4), 1,
      sym_start_tag,
    STATE(26), 1,
      sym_self_closing_tag,
    STATE(57), 1,
      sym_script_start_tag,
    STATE(58), 1,
      sym_style_start_tag,
    ACTIONS(48), 2,
      sym_entity,
      sym_text,
    STATE(6), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_source_file_repeat1,
  [197] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      anon_sym_LT,
    ACTIONS(11), 1,
      anon_sym_LT_SLASH,
    ACTIONS(51), 1,
      ts_builtin_sym_end,
    STATE(4), 1,
      sym_start_tag,
    STATE(26), 1,
      sym_self_closing_tag,
    STATE(57), 1,
      sym_script_start_tag,
    STATE(58), 1,
      sym_style_start_tag,
    ACTIONS(53), 2,
      sym_entity,
      sym_text,
    STATE(6), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_source_file_repeat1,
  [238] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LT_BANG,
    ACTIONS(27), 1,
      anon_sym_LT,
    ACTIONS(33), 1,
      anon_sym_LT_SLASH,
    STATE(8), 1,
      sym_start_tag,
    STATE(32), 1,
      sym_end_tag,
    STATE(33), 1,
      sym_self_closing_tag,
    STATE(59), 1,
      sym_style_start_tag,
    STATE(60), 1,
      sym_script_start_tag,
    ACTIONS(55), 2,
      sym_entity,
      sym_text,
    STATE(5), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_source_file_repeat1,
  [279] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LT_BANG,
    ACTIONS(27), 1,
      anon_sym_LT,
    ACTIONS(29), 1,
      anon_sym_LT_SLASH,
    STATE(8), 1,
      sym_start_tag,
    STATE(22), 1,
      sym_end_tag,
    STATE(33), 1,
      sym_self_closing_tag,
    STATE(59), 1,
      sym_style_start_tag,
    STATE(60), 1,
      sym_script_start_tag,
    ACTIONS(35), 2,
      sym_entity,
      sym_text,
    STATE(10), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_source_file_repeat1,
  [320] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(57), 1,
      anon_sym_LT_BANG,
    ACTIONS(60), 1,
      anon_sym_LT,
    ACTIONS(63), 1,
      anon_sym_LT_SLASH,
    STATE(8), 1,
      sym_start_tag,
    STATE(33), 1,
      sym_self_closing_tag,
    STATE(59), 1,
      sym_style_start_tag,
    STATE(60), 1,
      sym_script_start_tag,
    ACTIONS(66), 2,
      sym_entity,
      sym_text,
    STATE(10), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_source_file_repeat1,
  [358] = 6,
    ACTIONS(69), 1,
      aux_sym_erroneous_end_tag_name_token1,
    ACTIONS(71), 1,
      sym_comment,
    STATE(77), 1,
      sym__end_tag_name,
    STATE(80), 1,
      sym__start_tag_name,
    STATE(84), 1,
      sym_erroneous_end_tag_name,
    ACTIONS(15), 11,
      anon_sym_nml,
      anon_sym_head,
      anon_sym_body,
      anon_sym_div,
      anon_sym_p,
      anon_sym_span,
      anon_sym_a,
      anon_sym_ol,
      anon_sym_li,
      aux_sym__start_tag_name_token1,
      aux_sym__start_tag_name_token2,
  [387] = 6,
    ACTIONS(69), 1,
      aux_sym_erroneous_end_tag_name_token1,
    ACTIONS(71), 1,
      sym_comment,
    STATE(80), 1,
      sym__start_tag_name,
    STATE(84), 1,
      sym_erroneous_end_tag_name,
    STATE(90), 1,
      sym__end_tag_name,
    ACTIONS(15), 11,
      anon_sym_nml,
      anon_sym_head,
      anon_sym_body,
      anon_sym_div,
      anon_sym_p,
      anon_sym_span,
      anon_sym_a,
      anon_sym_ol,
      anon_sym_li,
      aux_sym__start_tag_name_token1,
      aux_sym__start_tag_name_token2,
  [416] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(75), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(73), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [430] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(79), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(77), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [444] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(83), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(81), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [458] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(87), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(85), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [472] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(91), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(89), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [486] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(95), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(93), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [500] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(99), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(97), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [514] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(103), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(101), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [528] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(107), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(105), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [542] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(111), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(109), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [556] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(115), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(113), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [570] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(117), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [584] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(123), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(121), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [598] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(125), 4,
      ts_builtin_sym_end,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [612] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(83), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(81), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [625] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(87), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(85), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [638] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 1,
      sym_attribute_name,
    ACTIONS(129), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
    STATE(45), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [653] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(115), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(113), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [666] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(123), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(121), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [679] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(107), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(105), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [692] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(125), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [705] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(111), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(109), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [718] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(75), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(73), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [731] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(133), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(135), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [744] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(103), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(101), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [757] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 1,
      sym_attribute_name,
    ACTIONS(137), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
    STATE(39), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [772] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 1,
      sym_attribute_name,
    ACTIONS(139), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
    STATE(45), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [787] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(117), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [800] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(79), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(77), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [813] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(141), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(143), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [826] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(91), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(89), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [839] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(95), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(93), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [852] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(147), 1,
      sym_attribute_name,
    ACTIONS(145), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
    STATE(45), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [867] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(99), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(97), 3,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_text,
  [880] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 1,
      sym_attribute_name,
    ACTIONS(150), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
    STATE(29), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [895] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(152), 1,
      sym_attribute_value,
    ACTIONS(154), 1,
      anon_sym_SQUOTE,
    ACTIONS(156), 1,
      anon_sym_DQUOTE,
    STATE(61), 1,
      sym_quoted_attribute_value,
  [911] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 1,
      sym_attribute_name,
    ACTIONS(158), 1,
      anon_sym_GT,
    STATE(55), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [925] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 1,
      sym_attribute_name,
    ACTIONS(160), 1,
      anon_sym_GT,
    STATE(52), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [939] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 1,
      sym_attribute_name,
    ACTIONS(162), 1,
      anon_sym_GT,
    STATE(45), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [953] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 1,
      sym_attribute_name,
    ACTIONS(164), 1,
      anon_sym_GT,
    STATE(45), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [967] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 1,
      sym_attribute_name,
    ACTIONS(166), 1,
      anon_sym_GT,
    STATE(51), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [981] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(170), 1,
      anon_sym_EQ,
    ACTIONS(168), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [993] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 1,
      sym_attribute_name,
    ACTIONS(172), 1,
      anon_sym_GT,
    STATE(45), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [1007] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(174), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1016] = 4,
    ACTIONS(71), 1,
      sym_comment,
    ACTIONS(176), 1,
      sym_raw_text,
    ACTIONS(178), 1,
      anon_sym_LT_SLASH,
    STATE(25), 1,
      sym_script_end_tag,
  [1029] = 4,
    ACTIONS(71), 1,
      sym_comment,
    ACTIONS(180), 1,
      sym_raw_text,
    ACTIONS(182), 1,
      anon_sym_LT_SLASH,
    STATE(23), 1,
      sym_style_end_tag,
  [1042] = 4,
    ACTIONS(71), 1,
      sym_comment,
    ACTIONS(184), 1,
      sym_raw_text,
    ACTIONS(186), 1,
      anon_sym_LT_SLASH,
    STATE(30), 1,
      sym_style_end_tag,
  [1055] = 4,
    ACTIONS(71), 1,
      sym_comment,
    ACTIONS(188), 1,
      sym_raw_text,
    ACTIONS(190), 1,
      anon_sym_LT_SLASH,
    STATE(31), 1,
      sym_script_end_tag,
  [1068] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(192), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1077] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(194), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1086] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(196), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1095] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(198), 1,
      anon_sym_LT_SLASH,
    STATE(35), 1,
      sym_script_end_tag,
  [1105] = 3,
    ACTIONS(71), 1,
      sym_comment,
    ACTIONS(200), 1,
      anon_sym_DQUOTE,
    ACTIONS(202), 1,
      aux_sym_quoted_attribute_value_token2,
  [1115] = 3,
    ACTIONS(69), 1,
      aux_sym_erroneous_end_tag_name_token1,
    ACTIONS(71), 1,
      sym_comment,
    STATE(88), 1,
      sym_erroneous_end_tag_name,
  [1125] = 3,
    ACTIONS(71), 1,
      sym_comment,
    ACTIONS(204), 1,
      sym_raw_text,
    ACTIONS(206), 1,
      anon_sym_LT_SLASH,
  [1135] = 3,
    ACTIONS(71), 1,
      sym_comment,
    ACTIONS(208), 1,
      sym_raw_text,
    ACTIONS(210), 1,
      anon_sym_LT_SLASH,
  [1145] = 3,
    ACTIONS(69), 1,
      aux_sym_erroneous_end_tag_name_token1,
    ACTIONS(71), 1,
      sym_comment,
    STATE(84), 1,
      sym_erroneous_end_tag_name,
  [1155] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(212), 1,
      anon_sym_LT_SLASH,
    STATE(37), 1,
      sym_style_end_tag,
  [1165] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(214), 1,
      anon_sym_LT_SLASH,
    STATE(20), 1,
      sym_style_end_tag,
  [1175] = 3,
    ACTIONS(71), 1,
      sym_comment,
    ACTIONS(216), 1,
      sym_raw_text,
    ACTIONS(218), 1,
      anon_sym_LT_SLASH,
  [1185] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(220), 1,
      anon_sym_LT_SLASH,
    STATE(13), 1,
      sym_script_end_tag,
  [1195] = 3,
    ACTIONS(71), 1,
      sym_comment,
    ACTIONS(200), 1,
      anon_sym_SQUOTE,
    ACTIONS(222), 1,
      aux_sym_quoted_attribute_value_token1,
  [1205] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(224), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1213] = 3,
    ACTIONS(71), 1,
      sym_comment,
    ACTIONS(226), 1,
      sym_raw_text,
    ACTIONS(228), 1,
      anon_sym_LT_SLASH,
  [1223] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(230), 1,
      anon_sym_GT,
  [1230] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(232), 1,
      anon_sym_GT,
  [1237] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(234), 1,
      anon_sym_GT,
  [1244] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(236), 1,
      anon_sym_GT,
  [1251] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(238), 1,
      anon_sym_SQUOTE,
  [1258] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(240), 1,
      anon_sym_GT,
  [1265] = 2,
    ACTIONS(71), 1,
      sym_comment,
    ACTIONS(242), 1,
      aux_sym_erroneous_end_tag_name_token1,
  [1272] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(244), 1,
      anon_sym_GT,
  [1279] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(238), 1,
      anon_sym_DQUOTE,
  [1286] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(246), 1,
      sym__doctype,
  [1293] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(248), 1,
      sym__script_start_tag_name,
  [1300] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(250), 1,
      anon_sym_GT,
  [1307] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(252), 1,
      anon_sym_GT,
  [1314] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(254), 1,
      anon_sym_GT,
  [1321] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(256), 1,
      anon_sym_GT,
  [1328] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(258), 1,
      anon_sym_GT,
  [1335] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(260), 1,
      ts_builtin_sym_end,
  [1342] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(262), 1,
      sym__style_start_tag_name,
  [1349] = 2,
    ACTIONS(71), 1,
      sym_comment,
    ACTIONS(264), 1,
      aux_sym_erroneous_end_tag_name_token1,
  [1356] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(266), 1,
      anon_sym_GT,
  [1363] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(268), 1,
      sym__script_start_tag_name,
  [1370] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(270), 1,
      sym__style_start_tag_name,
  [1377] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(272), 1,
      sym__doctype,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 37,
  [SMALL_STATE(4)] = 74,
  [SMALL_STATE(5)] = 115,
  [SMALL_STATE(6)] = 156,
  [SMALL_STATE(7)] = 197,
  [SMALL_STATE(8)] = 238,
  [SMALL_STATE(9)] = 279,
  [SMALL_STATE(10)] = 320,
  [SMALL_STATE(11)] = 358,
  [SMALL_STATE(12)] = 387,
  [SMALL_STATE(13)] = 416,
  [SMALL_STATE(14)] = 430,
  [SMALL_STATE(15)] = 444,
  [SMALL_STATE(16)] = 458,
  [SMALL_STATE(17)] = 472,
  [SMALL_STATE(18)] = 486,
  [SMALL_STATE(19)] = 500,
  [SMALL_STATE(20)] = 514,
  [SMALL_STATE(21)] = 528,
  [SMALL_STATE(22)] = 542,
  [SMALL_STATE(23)] = 556,
  [SMALL_STATE(24)] = 570,
  [SMALL_STATE(25)] = 584,
  [SMALL_STATE(26)] = 598,
  [SMALL_STATE(27)] = 612,
  [SMALL_STATE(28)] = 625,
  [SMALL_STATE(29)] = 638,
  [SMALL_STATE(30)] = 653,
  [SMALL_STATE(31)] = 666,
  [SMALL_STATE(32)] = 679,
  [SMALL_STATE(33)] = 692,
  [SMALL_STATE(34)] = 705,
  [SMALL_STATE(35)] = 718,
  [SMALL_STATE(36)] = 731,
  [SMALL_STATE(37)] = 744,
  [SMALL_STATE(38)] = 757,
  [SMALL_STATE(39)] = 772,
  [SMALL_STATE(40)] = 787,
  [SMALL_STATE(41)] = 800,
  [SMALL_STATE(42)] = 813,
  [SMALL_STATE(43)] = 826,
  [SMALL_STATE(44)] = 839,
  [SMALL_STATE(45)] = 852,
  [SMALL_STATE(46)] = 867,
  [SMALL_STATE(47)] = 880,
  [SMALL_STATE(48)] = 895,
  [SMALL_STATE(49)] = 911,
  [SMALL_STATE(50)] = 925,
  [SMALL_STATE(51)] = 939,
  [SMALL_STATE(52)] = 953,
  [SMALL_STATE(53)] = 967,
  [SMALL_STATE(54)] = 981,
  [SMALL_STATE(55)] = 993,
  [SMALL_STATE(56)] = 1007,
  [SMALL_STATE(57)] = 1016,
  [SMALL_STATE(58)] = 1029,
  [SMALL_STATE(59)] = 1042,
  [SMALL_STATE(60)] = 1055,
  [SMALL_STATE(61)] = 1068,
  [SMALL_STATE(62)] = 1077,
  [SMALL_STATE(63)] = 1086,
  [SMALL_STATE(64)] = 1095,
  [SMALL_STATE(65)] = 1105,
  [SMALL_STATE(66)] = 1115,
  [SMALL_STATE(67)] = 1125,
  [SMALL_STATE(68)] = 1135,
  [SMALL_STATE(69)] = 1145,
  [SMALL_STATE(70)] = 1155,
  [SMALL_STATE(71)] = 1165,
  [SMALL_STATE(72)] = 1175,
  [SMALL_STATE(73)] = 1185,
  [SMALL_STATE(74)] = 1195,
  [SMALL_STATE(75)] = 1205,
  [SMALL_STATE(76)] = 1213,
  [SMALL_STATE(77)] = 1223,
  [SMALL_STATE(78)] = 1230,
  [SMALL_STATE(79)] = 1237,
  [SMALL_STATE(80)] = 1244,
  [SMALL_STATE(81)] = 1251,
  [SMALL_STATE(82)] = 1258,
  [SMALL_STATE(83)] = 1265,
  [SMALL_STATE(84)] = 1272,
  [SMALL_STATE(85)] = 1279,
  [SMALL_STATE(86)] = 1286,
  [SMALL_STATE(87)] = 1293,
  [SMALL_STATE(88)] = 1300,
  [SMALL_STATE(89)] = 1307,
  [SMALL_STATE(90)] = 1314,
  [SMALL_STATE(91)] = 1321,
  [SMALL_STATE(92)] = 1328,
  [SMALL_STATE(93)] = 1335,
  [SMALL_STATE(94)] = 1342,
  [SMALL_STATE(95)] = 1349,
  [SMALL_STATE(96)] = 1356,
  [SMALL_STATE(97)] = 1363,
  [SMALL_STATE(98)] = 1370,
  [SMALL_STATE(99)] = 1377,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [39] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(86),
  [42] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(2),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(66),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(6),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [57] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(99),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(3),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(69),
  [66] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(10),
  [69] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [71] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 3),
  [75] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 3),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 4),
  [79] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 4),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_erroneous_end_tag, 3),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_erroneous_end_tag, 3),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 3),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 3),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_end_tag, 3),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_end_tag, 3),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_end_tag, 3),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_end_tag, 3),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_end_tag, 3),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_end_tag, 3),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 3),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 3),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 2),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 2),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 3),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 3),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 2),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 2),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doctype, 4),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_doctype, 4),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 2),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 2),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 1),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 1),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 3, .production_id = 1),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 3, .production_id = 1),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [141] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 4, .production_id = 1),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 4, .production_id = 1),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2),
  [147] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2), SHIFT_REPEAT(54),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 3),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [178] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [182] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [186] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [190] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tags, 1),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 2),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [200] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [202] = {.entry = {.count = 1, .reusable = false}}, SHIFT(85),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 3),
  [206] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_start_tag, 3),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 3),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_start_tag, 3),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 4),
  [218] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_start_tag, 4),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [222] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__start_tag_name, 1),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 4),
  [228] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_start_tag, 4),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_erroneous_end_tag_name, 1),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__end_tag_name, 1),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [242] = {.entry = {.count = 1, .reusable = false}}, SHIFT(96),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [260] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [264] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
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
