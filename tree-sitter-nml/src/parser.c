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
#define STATE_COUNT 215
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 103
#define ALIAS_COUNT 0
#define TOKEN_COUNT 66
#define EXTERNAL_TOKEN_COUNT 2
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 7
#define PRODUCTION_ID_COUNT 3

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
  anon_sym_if = 32,
  sym_named_variable = 33,
  anon_sym_for = 34,
  anon_sym_COMMA = 35,
  anon_sym_in = 36,
  anon_sym_elseif = 37,
  anon_sym_else = 38,
  sym_templating_cont_open = 39,
  sym_templating_open = 40,
  sym_templating_close = 41,
  sym_templating_close_start = 42,
  aux_sym_templating_token1 = 43,
  anon_sym_LT_BANG = 44,
  aux_sym_doctype_token1 = 45,
  anon_sym_GT = 46,
  sym__doctype = 47,
  anon_sym_LT = 48,
  anon_sym_LF = 49,
  anon_sym_CR = 50,
  anon_sym_LT_SLASH = 51,
  anon_sym_SLASH_GT = 52,
  aux_sym_end_tag_token1 = 53,
  anon_sym_EQ = 54,
  sym_attribute_name = 55,
  sym_attribute_value = 56,
  sym_entity = 57,
  sym_substitution = 58,
  anon_sym_SQUOTE = 59,
  aux_sym_quoted_attribute_value_token1 = 60,
  anon_sym_DQUOTE = 61,
  aux_sym_quoted_attribute_value_token2 = 62,
  sym_text = 63,
  sym_if_clause = 64,
  sym_sentinel = 65,
  sym_source_file = 66,
  sym__start_tag_name = 67,
  sym__script_start_tag_name = 68,
  sym__style_start_tag_name = 69,
  sym__end_tag_name = 70,
  sym_comment = 71,
  sym_self_closing_tags = 72,
  sym_templating_decl_if = 73,
  sym_templating_decl_for = 74,
  sym_conditional = 75,
  sym_templating_decl = 76,
  sym_templating_repeat_elseif = 77,
  sym_templating_repeat_else = 78,
  sym_templating_repeat_decl = 79,
  sym_template_repeat = 80,
  sym_templating = 81,
  sym_doctype = 82,
  sym__node = 83,
  sym_element = 84,
  sym_script_element = 85,
  sym_style_element = 86,
  sym_start_tag = 87,
  sym_script_start_tag = 88,
  sym_script_end_tag = 89,
  sym_style_start_tag = 90,
  sym_style_end_tag = 91,
  sym_self_closing_tag = 92,
  sym_end_tag = 93,
  sym_erroneous_end_tag = 94,
  sym_attribute = 95,
  sym_quoted_attribute_value = 96,
  aux_sym_source_file_repeat1 = 97,
  aux_sym_comment_repeat1 = 98,
  aux_sym_templating_decl_for_repeat1 = 99,
  aux_sym_templating_repeat1 = 100,
  aux_sym_start_tag_repeat1 = 101,
  aux_sym_script_start_tag_repeat1 = 102,
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
  [anon_sym_if] = "if",
  [sym_named_variable] = "named_variable",
  [anon_sym_for] = "for",
  [anon_sym_COMMA] = "comma",
  [anon_sym_in] = "loop_in",
  [anon_sym_elseif] = "conditional",
  [anon_sym_else] = "conditional",
  [sym_templating_cont_open] = "templating_cont_open",
  [sym_templating_open] = "templating_open",
  [sym_templating_close] = "templating_close",
  [sym_templating_close_start] = "templating_close_start",
  [aux_sym_templating_token1] = "templating_token1",
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
  [sym_if_clause] = "if_clause",
  [sym_sentinel] = "sentinel",
  [sym_source_file] = "source_file",
  [sym__start_tag_name] = "_start_tag_name",
  [sym__script_start_tag_name] = "tag_name",
  [sym__style_start_tag_name] = "tag_name",
  [sym__end_tag_name] = "tag_name",
  [sym_comment] = "comment",
  [sym_self_closing_tags] = "tag_name",
  [sym_templating_decl_if] = "templating_decl_if",
  [sym_templating_decl_for] = "templating_decl_for",
  [sym_conditional] = "conditional",
  [sym_templating_decl] = "templating_decl",
  [sym_templating_repeat_elseif] = "templating_repeat_elseif",
  [sym_templating_repeat_else] = "templating_repeat_else",
  [sym_templating_repeat_decl] = "templating_repeat_decl",
  [sym_template_repeat] = "template_repeat",
  [sym_templating] = "templating",
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
  [aux_sym_templating_decl_for_repeat1] = "templating_decl_for_repeat1",
  [aux_sym_templating_repeat1] = "templating_repeat1",
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
  [anon_sym_if] = anon_sym_if,
  [sym_named_variable] = sym_named_variable,
  [anon_sym_for] = anon_sym_for,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_in] = anon_sym_in,
  [anon_sym_elseif] = sym_conditional,
  [anon_sym_else] = sym_conditional,
  [sym_templating_cont_open] = sym_templating_cont_open,
  [sym_templating_open] = sym_templating_open,
  [sym_templating_close] = sym_templating_close,
  [sym_templating_close_start] = sym_templating_close_start,
  [aux_sym_templating_token1] = aux_sym_templating_token1,
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
  [sym_if_clause] = sym_if_clause,
  [sym_sentinel] = sym_sentinel,
  [sym_source_file] = sym_source_file,
  [sym__start_tag_name] = sym__start_tag_name,
  [sym__script_start_tag_name] = sym__script_start_tag_name,
  [sym__style_start_tag_name] = sym__script_start_tag_name,
  [sym__end_tag_name] = sym__script_start_tag_name,
  [sym_comment] = sym_comment,
  [sym_self_closing_tags] = sym__script_start_tag_name,
  [sym_templating_decl_if] = sym_templating_decl_if,
  [sym_templating_decl_for] = sym_templating_decl_for,
  [sym_conditional] = sym_conditional,
  [sym_templating_decl] = sym_templating_decl,
  [sym_templating_repeat_elseif] = sym_templating_repeat_elseif,
  [sym_templating_repeat_else] = sym_templating_repeat_else,
  [sym_templating_repeat_decl] = sym_templating_repeat_decl,
  [sym_template_repeat] = sym_template_repeat,
  [sym_templating] = sym_templating,
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
  [aux_sym_templating_decl_for_repeat1] = aux_sym_templating_decl_for_repeat1,
  [aux_sym_templating_repeat1] = aux_sym_templating_repeat1,
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
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [sym_named_variable] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_for] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_in] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_elseif] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_else] = {
    .visible = true,
    .named = true,
  },
  [sym_templating_cont_open] = {
    .visible = true,
    .named = true,
  },
  [sym_templating_open] = {
    .visible = true,
    .named = true,
  },
  [sym_templating_close] = {
    .visible = true,
    .named = true,
  },
  [sym_templating_close_start] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_templating_token1] = {
    .visible = false,
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
  [sym_if_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_sentinel] = {
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
  [sym_templating_decl_if] = {
    .visible = true,
    .named = true,
  },
  [sym_templating_decl_for] = {
    .visible = true,
    .named = true,
  },
  [sym_conditional] = {
    .visible = true,
    .named = true,
  },
  [sym_templating_decl] = {
    .visible = true,
    .named = true,
  },
  [sym_templating_repeat_elseif] = {
    .visible = true,
    .named = true,
  },
  [sym_templating_repeat_else] = {
    .visible = true,
    .named = true,
  },
  [sym_templating_repeat_decl] = {
    .visible = true,
    .named = true,
  },
  [sym_template_repeat] = {
    .visible = true,
    .named = true,
  },
  [sym_templating] = {
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
  [aux_sym_templating_decl_for_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_templating_repeat1] = {
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
    [0] = sym_conditional,
  },
  [2] = {
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
  [4] = 2,
  [5] = 5,
  [6] = 5,
  [7] = 7,
  [8] = 5,
  [9] = 7,
  [10] = 10,
  [11] = 7,
  [12] = 12,
  [13] = 12,
  [14] = 14,
  [15] = 15,
  [16] = 12,
  [17] = 17,
  [18] = 18,
  [19] = 17,
  [20] = 18,
  [21] = 17,
  [22] = 18,
  [23] = 14,
  [24] = 24,
  [25] = 25,
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
  [43] = 27,
  [44] = 29,
  [45] = 32,
  [46] = 33,
  [47] = 34,
  [48] = 42,
  [49] = 40,
  [50] = 39,
  [51] = 36,
  [52] = 35,
  [53] = 28,
  [54] = 41,
  [55] = 38,
  [56] = 37,
  [57] = 26,
  [58] = 58,
  [59] = 30,
  [60] = 31,
  [61] = 29,
  [62] = 32,
  [63] = 63,
  [64] = 41,
  [65] = 36,
  [66] = 35,
  [67] = 38,
  [68] = 37,
  [69] = 33,
  [70] = 34,
  [71] = 26,
  [72] = 58,
  [73] = 27,
  [74] = 28,
  [75] = 42,
  [76] = 40,
  [77] = 77,
  [78] = 30,
  [79] = 31,
  [80] = 39,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 86,
  [89] = 89,
  [90] = 90,
  [91] = 84,
  [92] = 85,
  [93] = 86,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 84,
  [98] = 85,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 104,
  [107] = 94,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 101,
  [117] = 100,
  [118] = 103,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 112,
  [124] = 122,
  [125] = 122,
  [126] = 112,
  [127] = 115,
  [128] = 113,
  [129] = 129,
  [130] = 115,
  [131] = 113,
  [132] = 132,
  [133] = 133,
  [134] = 132,
  [135] = 135,
  [136] = 135,
  [137] = 137,
  [138] = 137,
  [139] = 139,
  [140] = 139,
  [141] = 141,
  [142] = 142,
  [143] = 132,
  [144] = 135,
  [145] = 145,
  [146] = 146,
  [147] = 147,
  [148] = 146,
  [149] = 149,
  [150] = 150,
  [151] = 146,
  [152] = 147,
  [153] = 147,
  [154] = 154,
  [155] = 155,
  [156] = 156,
  [157] = 157,
  [158] = 158,
  [159] = 159,
  [160] = 160,
  [161] = 160,
  [162] = 162,
  [163] = 163,
  [164] = 164,
  [165] = 165,
  [166] = 166,
  [167] = 164,
  [168] = 155,
  [169] = 169,
  [170] = 170,
  [171] = 159,
  [172] = 162,
  [173] = 173,
  [174] = 174,
  [175] = 175,
  [176] = 176,
  [177] = 177,
  [178] = 159,
  [179] = 179,
  [180] = 160,
  [181] = 162,
  [182] = 102,
  [183] = 165,
  [184] = 155,
  [185] = 173,
  [186] = 166,
  [187] = 187,
  [188] = 188,
  [189] = 158,
  [190] = 190,
  [191] = 191,
  [192] = 192,
  [193] = 173,
  [194] = 166,
  [195] = 165,
  [196] = 196,
  [197] = 158,
  [198] = 198,
  [199] = 199,
  [200] = 156,
  [201] = 201,
  [202] = 202,
  [203] = 169,
  [204] = 156,
  [205] = 170,
  [206] = 174,
  [207] = 174,
  [208] = 163,
  [209] = 163,
  [210] = 210,
  [211] = 211,
  [212] = 164,
  [213] = 213,
  [214] = 214,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      ACCEPT_TOKEN(aux_sym_end_tag_token1);
      if (eof) ADVANCE(105);
      ADVANCE_MAP(
        '\n', 260,
        '\r', 261,
        '"', 318,
        '%', 220,
        '&', 200,
        '\'', 313,
        ',', 235,
        '-', 11,
        '/', 219,
        '<', 259,
        '=', 267,
        '>', 256,
        'D', 202,
        'a', 106,
        'b', 216,
        'c', 204,
        'd', 210,
        'e', 212,
        'f', 217,
        'h', 206,
        'i', 209,
        'l', 211,
        'm', 207,
        'n', 215,
        'o', 213,
        'p', 120,
        's', 205,
        't', 208,
        'u', 214,
        '{', 201,
        '}', 244,
        '\t', 221,
        0x0b, 221,
        '\f', 221,
        ' ', 221,
      );
      if (('0' <= lookahead && lookahead <= '9') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(218);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(203);
      if (lookahead != 0) ADVANCE(198);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '\n', 260,
        '\r', 261,
        '<', 2,
        '=', 267,
        '>', 256,
        '\t', 246,
        0x0b, 246,
        '\f', 246,
        ' ', 246,
      );
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/') ADVANCE(268);
      END_STATE();
    case 2:
      if (lookahead == '!') ADVANCE(69);
      END_STATE();
    case 3:
      if (lookahead == '!') ADVANCE(69);
      if (lookahead == '/') ADVANCE(262);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(318);
      if (lookahead == '\'') ADVANCE(313);
      if (lookahead == '<') ADVANCE(2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(246);
      if (lookahead != 0 &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(269);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(318);
      if (lookahead == '<') ADVANCE(319);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(249);
      if (lookahead != 0) ADVANCE(322);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(99);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(309);
      END_STATE();
    case 7:
      if (lookahead == '#') ADVANCE(243);
      if (lookahead == '/') ADVANCE(245);
      if (lookahead == ':') ADVANCE(242);
      END_STATE();
    case 8:
      if (lookahead == '\'') ADVANCE(313);
      if (lookahead == '<') ADVANCE(314);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(248);
      if (lookahead != 0) ADVANCE(317);
      END_STATE();
    case 9:
      ADVANCE_MAP(
        ',', 235,
        '<', 2,
        'e', 85,
        'f', 87,
        'i', 82,
        's', 79,
        'D', 96,
        'd', 96,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(246);
      END_STATE();
    case 10:
      if (lookahead == '-') ADVANCE(11);
      if (lookahead == '<') ADVANCE(199);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(221);
      if (lookahead != 0) ADVANCE(198);
      END_STATE();
    case 11:
      if (lookahead == '-') ADVANCE(78);
      if (lookahead != 0) ADVANCE(222);
      END_STATE();
    case 12:
      if (lookahead == '-') ADVANCE(147);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(145);
      END_STATE();
    case 13:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'a') ADVANCE(44);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 14:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'a') ADVANCE(20);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 15:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'a') ADVANCE(225);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 16:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'a') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 17:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'a') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 18:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'a') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 19:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'c') ADVANCE(51);
      if (lookahead == 'l') ADVANCE(47);
      if (lookahead == 'p') ADVANCE(17);
      if (lookahead == 't') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 20:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'd') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 21:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'd') ADVANCE(229);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 22:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'd') ADVANCE(61);
      if (lookahead == 'u') ADVANCE(45);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 23:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'e') ADVANCE(14);
      if (lookahead == 'r') ADVANCE(228);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(134);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 24:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'e') ADVANCE(56);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 25:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'e') ADVANCE(42);
      if (lookahead == 'i') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 26:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'e') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 27:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'e') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 28:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'e') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 29:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'e') ADVANCE(110);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 30:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'e') ADVANCE(128);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 31:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'f') ADVANCE(239);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 32:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'i') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 33:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'i') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 34:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'i') ADVANCE(49);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 35:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'l') ADVANCE(124);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 36:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'l') ADVANCE(126);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 37:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'l') ADVANCE(108);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 38:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'l') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 39:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'l') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 40:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'l') ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 41:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'm') ADVANCE(37);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 42:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'm') ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 43:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'n') ADVANCE(122);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 44:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'n') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 45:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'n') ADVANCE(21);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 46:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'o') ADVANCE(22);
      if (lookahead == 'r') ADVANCE(226);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 47:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'o') ADVANCE(54);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 48:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'p') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 49:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'p') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 50:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'r') ADVANCE(234);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 51:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'r') ADVANCE(34);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 52:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 's') ADVANCE(227);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 53:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 's') ADVANCE(27);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 54:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 't') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 55:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 't') ADVANCE(154);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 56:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 't') ADVANCE(15);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 57:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 't') ADVANCE(30);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 58:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 't') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 59:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'v') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 60:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'v') ADVANCE(16);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 61:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'y') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 62:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'y') ADVANCE(38);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 63:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 64:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(258);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 65:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 66:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(67);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 67:
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 68:
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 69:
      if (lookahead == '-') ADVANCE(70);
      END_STATE();
    case 70:
      if (lookahead == '-') ADVANCE(193);
      END_STATE();
    case 71:
      if (lookahead == '/') ADVANCE(77);
      if (lookahead == '<') ADVANCE(2);
      if (lookahead == '=') ADVANCE(267);
      if (lookahead == '>') ADVANCE(256);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(246);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'') ADVANCE(268);
      END_STATE();
    case 72:
      if (lookahead == '<') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(151);
      if (lookahead != 0) ADVANCE(152);
      END_STATE();
    case 73:
      ADVANCE_MAP(
        '<', 157,
        'a', 107,
        'b', 179,
        'd', 168,
        'h', 163,
        'l', 169,
        'n', 177,
        'o', 170,
        'p', 121,
        's', 173,
        't', 167,
        'u', 171,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('c' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(188);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 74:
      if (lookahead == '<') ADVANCE(157);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(246);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 75:
      if (lookahead == '<') ADVANCE(2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 76:
      if (lookahead == '<') ADVANCE(252);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(250);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(255);
      END_STATE();
    case 77:
      if (lookahead == '>') ADVANCE(263);
      END_STATE();
    case 78:
      if (lookahead == '>') ADVANCE(224);
      if (lookahead != 0) ADVANCE(223);
      END_STATE();
    case 79:
      if (lookahead == 'c') ADVANCE(90);
      if (lookahead == 't') ADVANCE(93);
      END_STATE();
    case 80:
      if (lookahead == 'e') ADVANCE(241);
      END_STATE();
    case 81:
      if (lookahead == 'e') ADVANCE(155);
      END_STATE();
    case 82:
      if (lookahead == 'f') ADVANCE(230);
      if (lookahead == 'n') ADVANCE(236);
      END_STATE();
    case 83:
      if (lookahead == 'f') ADVANCE(238);
      END_STATE();
    case 84:
      if (lookahead == 'i') ADVANCE(88);
      END_STATE();
    case 85:
      if (lookahead == 'l') ADVANCE(91);
      END_STATE();
    case 86:
      if (lookahead == 'l') ADVANCE(81);
      END_STATE();
    case 87:
      if (lookahead == 'o') ADVANCE(89);
      END_STATE();
    case 88:
      if (lookahead == 'p') ADVANCE(92);
      END_STATE();
    case 89:
      if (lookahead == 'r') ADVANCE(233);
      END_STATE();
    case 90:
      if (lookahead == 'r') ADVANCE(84);
      END_STATE();
    case 91:
      if (lookahead == 's') ADVANCE(80);
      END_STATE();
    case 92:
      if (lookahead == 't') ADVANCE(153);
      END_STATE();
    case 93:
      if (lookahead == 'y') ADVANCE(86);
      END_STATE();
    case 94:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(98);
      END_STATE();
    case 95:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(257);
      END_STATE();
    case 96:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(94);
      END_STATE();
    case 97:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(95);
      END_STATE();
    case 98:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(100);
      END_STATE();
    case 99:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(275);
      END_STATE();
    case 100:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(97);
      END_STATE();
    case 101:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(280);
      END_STATE();
    case 102:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      END_STATE();
    case 103:
      if (eof) ADVANCE(105);
      ADVANCE_MAP(
        '"', 318,
        '\'', 313,
        '<', 3,
        '>', 256,
        'a', 106,
        'b', 46,
        'c', 13,
        'd', 32,
        'h', 23,
        'l', 33,
        'm', 24,
        'n', 41,
        'o', 35,
        'p', 120,
        's', 19,
        't', 25,
        'u', 36,
        '}', 244,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('e' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(12);
      END_STATE();
    case 104:
      if (eof) ADVANCE(105);
      if (lookahead == '%') ADVANCE(312);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '<') ADVANCE(259);
      if (lookahead == '{') ADVANCE(7);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(247);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(323);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_a);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_a);
      if (lookahead == '-') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_nml);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_nml);
      if (lookahead == '-') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_title);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_title);
      if (lookahead == '-') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_pre);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_pre);
      if (lookahead == '-') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_head);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_head);
      if (lookahead == '-') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_body);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_body);
      if (lookahead == '-') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_div);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_div);
      if (lookahead == '-') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_p);
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'r') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_p);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'r') ADVANCE(164);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_span);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_span);
      if (lookahead == '-') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_ol);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_ol);
      if (lookahead == '-') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_ul);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_ul);
      if (lookahead == '-') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_template);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_template);
      if (lookahead == '-') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_li);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_li);
      if (lookahead == '-') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_slot);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_slot);
      if (lookahead == '-') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token1);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token1);
      if (lookahead == '-') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(147);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(137);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token2);
      if (lookahead == '-') ADVANCE(148);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(139);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '-') ADVANCE(147);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(149);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(145);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '-') ADVANCE(147);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(149);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(145);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '-') ADVANCE(147);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(149);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(145);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '-') ADVANCE(147);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(149);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(144);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(145);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '-') ADVANCE(147);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(149);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(142);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(145);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '-') ADVANCE(147);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(145);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '-') ADVANCE(148);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '+' ||
          lookahead == '-' ||
          lookahead == '/') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '+' ||
          lookahead == '-' ||
          lookahead == '/') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(139);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '+' ||
          lookahead == '-' ||
          ('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(149);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(aux_sym__start_tag_name_token3);
      if (lookahead == '+' ||
          lookahead == '-' ||
          ('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(150);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_raw_text);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(151);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(152);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym_raw_text);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(152);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_script);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_style);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_style);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '!') ADVANCE(190);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '!' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'a') ADVANCE(178);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'a') ADVANCE(162);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'a') ADVANCE(183);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'd') ADVANCE(186);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'd') ADVANCE(115);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'e') ADVANCE(159);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(135);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'e') ADVANCE(113);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'e') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'e') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'e') ADVANCE(176);
      if (lookahead == 'i') ADVANCE(184);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'i') ADVANCE(185);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'i') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'l') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'l') ADVANCE(127);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'l') ADVANCE(109);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'l') ADVANCE(180);
      if (lookahead == 'p') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'l') ADVANCE(165);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'l') ADVANCE(160);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'm') ADVANCE(181);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'm') ADVANCE(172);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'n') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'o') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'o') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'p') ADVANCE(175);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 't') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 't') ADVANCE(166);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 't') ADVANCE(174);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'v') ADVANCE(119);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (lookahead == 'y') ADVANCE(117);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(148);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(194);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead == '-') ADVANCE(189);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_erroneous_end_tag_name);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '>') ADVANCE(192);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(322);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(317);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(anon_sym_LT_BANG_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(255);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '!') ADVANCE(69);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '#') ADVANCE(99);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(309);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '#') ADVANCE(243);
      if (lookahead == '/') ADVANCE(245);
      if (lookahead == ':') ADVANCE(242);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '-') ADVANCE(147);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(149);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(140);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(145);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '-') ADVANCE(147);
      if (lookahead == '+' ||
          lookahead == '/') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(145);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'a') ADVANCE(44);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'c') ADVANCE(51);
      if (lookahead == 'l') ADVANCE(47);
      if (lookahead == 'p') ADVANCE(17);
      if (lookahead == 's') ADVANCE(264);
      if (lookahead == 't') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'e') ADVANCE(14);
      if (lookahead == 'r') ADVANCE(228);
      if (('1' <= lookahead && lookahead <= '6')) ADVANCE(134);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'e') ADVANCE(56);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'e') ADVANCE(42);
      if (lookahead == 'i') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'f') ADVANCE(231);
      if (lookahead == 'n') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'i') ADVANCE(59);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(63);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'i') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'l') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'l') ADVANCE(124);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'l') ADVANCE(126);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'm') ADVANCE(37);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'o') ADVANCE(22);
      if (lookahead == 'r') ADVANCE(226);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'o') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '>') ADVANCE(263);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '%' ||
          lookahead == ';') ADVANCE(310);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(311);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(246);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(aux_sym_comment_token2);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(aux_sym_comment_token3);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(anon_sym_DASH_DASH_GT);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(anon_sym_meta);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(anon_sym_br);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(anon_sym_canvas);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(anon_sym_hr);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(anon_sym_bound);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(anon_sym_if);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_named_variable);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(anon_sym_for);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(anon_sym_for);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(anon_sym_in);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(anon_sym_elseif);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(anon_sym_elseif);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(anon_sym_else);
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 'i') ADVANCE(31);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(anon_sym_else);
      if (lookahead == 'i') ADVANCE(83);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_templating_cont_open);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_templating_open);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_templating_close);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_templating_close_start);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(aux_sym_templating_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(246);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(aux_sym_templating_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(247);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '&' &&
          lookahead != '<' &&
          lookahead != '>' &&
          lookahead != '{') ADVANCE(323);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(aux_sym_templating_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(248);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(317);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(aux_sym_templating_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(249);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(322);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(aux_sym_templating_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(250);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(255);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(anon_sym_LT_BANG);
      if (lookahead == '-') ADVANCE(70);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(aux_sym_doctype_token1);
      if (lookahead == '!') ADVANCE(254);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(255);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(aux_sym_doctype_token1);
      if (lookahead == '-') ADVANCE(197);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(255);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(aux_sym_doctype_token1);
      if (lookahead == '-') ADVANCE(253);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(255);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(aux_sym_doctype_token1);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(255);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym__doctype);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym__doctype);
      if (lookahead == '-') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '!') ADVANCE(251);
      if (lookahead == '/') ADVANCE(262);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(anon_sym_LF);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(246);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(anon_sym_CR);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(246);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(anon_sym_LT_SLASH);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(anon_sym_SLASH_GT);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(aux_sym_end_tag_token1);
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == 's') ADVANCE(264);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(aux_sym_end_tag_token1);
      if (lookahead == '<') ADVANCE(2);
      if (lookahead == 's') ADVANCE(266);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(246);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(aux_sym_end_tag_token1);
      if (lookahead == 's') ADVANCE(266);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(268);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_attribute_value);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(269);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_entity);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(272);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(273);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(274);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(271);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(276);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(277);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(278);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(279);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(271);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(281);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(283);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(284);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(285);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(286);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(287);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(288);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(289);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(290);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(291);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(293);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(295);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(296);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(297);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(298);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(299);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(300);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(301);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(302);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(303);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(304);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(305);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(306);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(307);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_substitution);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_substitution);
      if (lookahead == ';') ADVANCE(310);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(311);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_substitution);
      if (lookahead == '%' ||
          lookahead == ';') ADVANCE(310);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(311);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '!') ADVANCE(316);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(317);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '-') ADVANCE(196);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(317);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '-') ADVANCE(315);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(317);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(317);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '!') ADVANCE(321);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '"') ADVANCE(322);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '-') ADVANCE(195);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(322);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '-') ADVANCE(320);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(322);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(322);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym_text);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(323);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '&' &&
          lookahead != '<' &&
          lookahead != '>' &&
          lookahead != '{') ADVANCE(323);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 104},
  [2] = {.lex_state = 103},
  [3] = {.lex_state = 103},
  [4] = {.lex_state = 103},
  [5] = {.lex_state = 104},
  [6] = {.lex_state = 104},
  [7] = {.lex_state = 104},
  [8] = {.lex_state = 104},
  [9] = {.lex_state = 104},
  [10] = {.lex_state = 104},
  [11] = {.lex_state = 104},
  [12] = {.lex_state = 73},
  [13] = {.lex_state = 73},
  [14] = {.lex_state = 104},
  [15] = {.lex_state = 104},
  [16] = {.lex_state = 73},
  [17] = {.lex_state = 104},
  [18] = {.lex_state = 104},
  [19] = {.lex_state = 104},
  [20] = {.lex_state = 104},
  [21] = {.lex_state = 104},
  [22] = {.lex_state = 104},
  [23] = {.lex_state = 104},
  [24] = {.lex_state = 104},
  [25] = {.lex_state = 104},
  [26] = {.lex_state = 104},
  [27] = {.lex_state = 104},
  [28] = {.lex_state = 104},
  [29] = {.lex_state = 104},
  [30] = {.lex_state = 104},
  [31] = {.lex_state = 104},
  [32] = {.lex_state = 104},
  [33] = {.lex_state = 104},
  [34] = {.lex_state = 104},
  [35] = {.lex_state = 104},
  [36] = {.lex_state = 104},
  [37] = {.lex_state = 104},
  [38] = {.lex_state = 104},
  [39] = {.lex_state = 104},
  [40] = {.lex_state = 104},
  [41] = {.lex_state = 104},
  [42] = {.lex_state = 104},
  [43] = {.lex_state = 104},
  [44] = {.lex_state = 104},
  [45] = {.lex_state = 104},
  [46] = {.lex_state = 104},
  [47] = {.lex_state = 104},
  [48] = {.lex_state = 104},
  [49] = {.lex_state = 104},
  [50] = {.lex_state = 104},
  [51] = {.lex_state = 104},
  [52] = {.lex_state = 104},
  [53] = {.lex_state = 104},
  [54] = {.lex_state = 104},
  [55] = {.lex_state = 104},
  [56] = {.lex_state = 104},
  [57] = {.lex_state = 104},
  [58] = {.lex_state = 104},
  [59] = {.lex_state = 104},
  [60] = {.lex_state = 104},
  [61] = {.lex_state = 104},
  [62] = {.lex_state = 104},
  [63] = {.lex_state = 104},
  [64] = {.lex_state = 104},
  [65] = {.lex_state = 104},
  [66] = {.lex_state = 104},
  [67] = {.lex_state = 104},
  [68] = {.lex_state = 104},
  [69] = {.lex_state = 104},
  [70] = {.lex_state = 104},
  [71] = {.lex_state = 104},
  [72] = {.lex_state = 104},
  [73] = {.lex_state = 104},
  [74] = {.lex_state = 104},
  [75] = {.lex_state = 104},
  [76] = {.lex_state = 104},
  [77] = {.lex_state = 104},
  [78] = {.lex_state = 104},
  [79] = {.lex_state = 104},
  [80] = {.lex_state = 104},
  [81] = {.lex_state = 1},
  [82] = {.lex_state = 1},
  [83] = {.lex_state = 1},
  [84] = {.lex_state = 71},
  [85] = {.lex_state = 9},
  [86] = {.lex_state = 71},
  [87] = {.lex_state = 10},
  [88] = {.lex_state = 71},
  [89] = {.lex_state = 10},
  [90] = {.lex_state = 9},
  [91] = {.lex_state = 71},
  [92] = {.lex_state = 9},
  [93] = {.lex_state = 71},
  [94] = {.lex_state = 1},
  [95] = {.lex_state = 10},
  [96] = {.lex_state = 71},
  [97] = {.lex_state = 71},
  [98] = {.lex_state = 9},
  [99] = {.lex_state = 71},
  [100] = {.lex_state = 1},
  [101] = {.lex_state = 1},
  [102] = {.lex_state = 1},
  [103] = {.lex_state = 1},
  [104] = {.lex_state = 4},
  [105] = {.lex_state = 71},
  [106] = {.lex_state = 4},
  [107] = {.lex_state = 71},
  [108] = {.lex_state = 71},
  [109] = {.lex_state = 71},
  [110] = {.lex_state = 10},
  [111] = {.lex_state = 1},
  [112] = {.lex_state = 72},
  [113] = {.lex_state = 9},
  [114] = {.lex_state = 9},
  [115] = {.lex_state = 9},
  [116] = {.lex_state = 71},
  [117] = {.lex_state = 71},
  [118] = {.lex_state = 71},
  [119] = {.lex_state = 9},
  [120] = {.lex_state = 71},
  [121] = {.lex_state = 9},
  [122] = {.lex_state = 72},
  [123] = {.lex_state = 72},
  [124] = {.lex_state = 72},
  [125] = {.lex_state = 72},
  [126] = {.lex_state = 72},
  [127] = {.lex_state = 9},
  [128] = {.lex_state = 9},
  [129] = {.lex_state = 71},
  [130] = {.lex_state = 9},
  [131] = {.lex_state = 9},
  [132] = {.lex_state = 103},
  [133] = {.lex_state = 72},
  [134] = {.lex_state = 103},
  [135] = {.lex_state = 103},
  [136] = {.lex_state = 103},
  [137] = {.lex_state = 8},
  [138] = {.lex_state = 8},
  [139] = {.lex_state = 5},
  [140] = {.lex_state = 5},
  [141] = {.lex_state = 72},
  [142] = {.lex_state = 71},
  [143] = {.lex_state = 103},
  [144] = {.lex_state = 103},
  [145] = {.lex_state = 72},
  [146] = {.lex_state = 9},
  [147] = {.lex_state = 9},
  [148] = {.lex_state = 9},
  [149] = {.lex_state = 9},
  [150] = {.lex_state = 71},
  [151] = {.lex_state = 9},
  [152] = {.lex_state = 9},
  [153] = {.lex_state = 9},
  [154] = {.lex_state = 72},
  [155] = {.lex_state = 103},
  [156] = {.lex_state = 9},
  [157] = {.lex_state = 103},
  [158] = {.lex_state = 265},
  [159] = {.lex_state = 103},
  [160] = {.lex_state = 103},
  [161] = {.lex_state = 103},
  [162] = {.lex_state = 103},
  [163] = {.lex_state = 103},
  [164] = {.lex_state = 103},
  [165] = {.lex_state = 103},
  [166] = {.lex_state = 76},
  [167] = {.lex_state = 103},
  [168] = {.lex_state = 103},
  [169] = {.lex_state = 103},
  [170] = {.lex_state = 103},
  [171] = {.lex_state = 103},
  [172] = {.lex_state = 103},
  [173] = {.lex_state = 74},
  [174] = {.lex_state = 103},
  [175] = {.lex_state = 103},
  [176] = {.lex_state = 103},
  [177] = {.lex_state = 103, .external_lex_state = 2},
  [178] = {.lex_state = 103},
  [179] = {.lex_state = 103},
  [180] = {.lex_state = 103},
  [181] = {.lex_state = 103},
  [182] = {.lex_state = 265},
  [183] = {.lex_state = 103},
  [184] = {.lex_state = 103},
  [185] = {.lex_state = 74},
  [186] = {.lex_state = 76},
  [187] = {.lex_state = 103, .external_lex_state = 2},
  [188] = {.lex_state = 103},
  [189] = {.lex_state = 265},
  [190] = {.lex_state = 103},
  [191] = {.lex_state = 103},
  [192] = {.lex_state = 103},
  [193] = {.lex_state = 74},
  [194] = {.lex_state = 76},
  [195] = {.lex_state = 103},
  [196] = {.lex_state = 75},
  [197] = {.lex_state = 265},
  [198] = {.lex_state = 103, .external_lex_state = 2},
  [199] = {.lex_state = 265},
  [200] = {.lex_state = 9},
  [201] = {.lex_state = 103},
  [202] = {.lex_state = 103},
  [203] = {.lex_state = 103},
  [204] = {.lex_state = 9},
  [205] = {.lex_state = 103},
  [206] = {.lex_state = 103},
  [207] = {.lex_state = 103},
  [208] = {.lex_state = 103},
  [209] = {.lex_state = 103},
  [210] = {.lex_state = 103, .external_lex_state = 2},
  [211] = {.lex_state = 75},
  [212] = {.lex_state = 103},
  [213] = {(TSStateId)(-1)},
  [214] = {(TSStateId)(-1)},
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
    [aux_sym__start_tag_name_token2] = ACTIONS(1),
    [aux_sym__start_tag_name_token3] = ACTIONS(1),
    [anon_sym_script] = ACTIONS(1),
    [anon_sym_style] = ACTIONS(1),
    [anon_sym_LT_BANG_DASH_DASH] = ACTIONS(3),
    [aux_sym_comment_token1] = ACTIONS(1),
    [aux_sym_comment_token2] = ACTIONS(1),
    [aux_sym_comment_token3] = ACTIONS(1),
    [anon_sym_DASH_DASH_GT] = ACTIONS(1),
    [anon_sym_meta] = ACTIONS(1),
    [anon_sym_br] = ACTIONS(1),
    [anon_sym_canvas] = ACTIONS(1),
    [anon_sym_hr] = ACTIONS(1),
    [anon_sym_bound] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_for] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_in] = ACTIONS(1),
    [anon_sym_elseif] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [sym_templating_cont_open] = ACTIONS(1),
    [sym_templating_open] = ACTIONS(1),
    [sym_templating_close] = ACTIONS(1),
    [sym_templating_close_start] = ACTIONS(1),
    [aux_sym_templating_token1] = ACTIONS(5),
    [anon_sym_LT_BANG] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [sym__doctype] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_LF] = ACTIONS(1),
    [anon_sym_CR] = ACTIONS(1),
    [anon_sym_LT_SLASH] = ACTIONS(1),
    [anon_sym_SLASH_GT] = ACTIONS(1),
    [aux_sym_end_tag_token1] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [sym_entity] = ACTIONS(1),
    [sym_substitution] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym_if_clause] = ACTIONS(1),
    [sym_sentinel] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(202),
    [sym_comment] = STATE(1),
    [sym_templating] = STATE(57),
    [sym_doctype] = STATE(57),
    [sym__node] = STATE(58),
    [sym_element] = STATE(57),
    [sym_script_element] = STATE(57),
    [sym_style_element] = STATE(57),
    [sym_start_tag] = STATE(21),
    [sym_script_start_tag] = STATE(124),
    [sym_style_start_tag] = STATE(112),
    [sym_self_closing_tag] = STATE(43),
    [sym_erroneous_end_tag] = STATE(57),
    [aux_sym_source_file_repeat1] = STATE(15),
    [ts_builtin_sym_end] = ACTIONS(7),
    [anon_sym_LT_BANG_DASH_DASH] = ACTIONS(3),
    [sym_templating_open] = ACTIONS(9),
    [aux_sym_templating_token1] = ACTIONS(5),
    [anon_sym_LT_BANG] = ACTIONS(11),
    [anon_sym_LT] = ACTIONS(13),
    [anon_sym_LT_SLASH] = ACTIONS(15),
    [sym_entity] = ACTIONS(17),
    [sym_substitution] = ACTIONS(17),
    [sym_text] = ACTIONS(17),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 11,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(21), 1,
      anon_sym_script,
    ACTIONS(23), 1,
      anon_sym_style,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    STATE(2), 1,
      sym_comment,
    STATE(83), 1,
      sym__start_tag_name,
    STATE(88), 1,
      sym_self_closing_tags,
    STATE(99), 1,
      sym__style_start_tag_name,
    STATE(109), 1,
      sym__script_start_tag_name,
    ACTIONS(25), 5,
      anon_sym_meta,
      anon_sym_br,
      anon_sym_canvas,
      anon_sym_hr,
      anon_sym_bound,
    ACTIONS(19), 17,
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
  [54] = 11,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(21), 1,
      anon_sym_script,
    ACTIONS(23), 1,
      anon_sym_style,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    STATE(3), 1,
      sym_comment,
    STATE(83), 1,
      sym__start_tag_name,
    STATE(86), 1,
      sym_self_closing_tags,
    STATE(99), 1,
      sym__style_start_tag_name,
    STATE(109), 1,
      sym__script_start_tag_name,
    ACTIONS(25), 5,
      anon_sym_meta,
      anon_sym_br,
      anon_sym_canvas,
      anon_sym_hr,
      anon_sym_bound,
    ACTIONS(19), 17,
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
  [108] = 11,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(21), 1,
      anon_sym_script,
    ACTIONS(23), 1,
      anon_sym_style,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    STATE(4), 1,
      sym_comment,
    STATE(83), 1,
      sym__start_tag_name,
    STATE(93), 1,
      sym_self_closing_tags,
    STATE(99), 1,
      sym__style_start_tag_name,
    STATE(109), 1,
      sym__script_start_tag_name,
    ACTIONS(25), 5,
      anon_sym_meta,
      anon_sym_br,
      anon_sym_canvas,
      anon_sym_hr,
      anon_sym_bound,
    ACTIONS(19), 17,
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
  [162] = 17,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(29), 1,
      sym_templating_cont_open,
    ACTIONS(31), 1,
      sym_templating_open,
    ACTIONS(33), 1,
      sym_templating_close_start,
    ACTIONS(35), 1,
      aux_sym_templating_token1,
    ACTIONS(37), 1,
      anon_sym_LT_BANG,
    ACTIONS(39), 1,
      anon_sym_LT,
    ACTIONS(41), 1,
      anon_sym_LT_SLASH,
    STATE(5), 1,
      sym_comment,
    STATE(11), 1,
      aux_sym_templating_repeat1,
    STATE(17), 1,
      sym_start_tag,
    STATE(27), 1,
      sym_self_closing_tag,
    STATE(125), 1,
      sym_script_start_tag,
    STATE(126), 1,
      sym_style_start_tag,
    STATE(24), 2,
      sym_template_repeat,
      sym__node,
    ACTIONS(43), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(26), 6,
      sym_templating,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [222] = 17,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(29), 1,
      sym_templating_cont_open,
    ACTIONS(31), 1,
      sym_templating_open,
    ACTIONS(35), 1,
      aux_sym_templating_token1,
    ACTIONS(37), 1,
      anon_sym_LT_BANG,
    ACTIONS(39), 1,
      anon_sym_LT,
    ACTIONS(41), 1,
      anon_sym_LT_SLASH,
    ACTIONS(45), 1,
      sym_templating_close_start,
    STATE(6), 1,
      sym_comment,
    STATE(7), 1,
      aux_sym_templating_repeat1,
    STATE(17), 1,
      sym_start_tag,
    STATE(27), 1,
      sym_self_closing_tag,
    STATE(125), 1,
      sym_script_start_tag,
    STATE(126), 1,
      sym_style_start_tag,
    STATE(24), 2,
      sym_template_repeat,
      sym__node,
    ACTIONS(43), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(26), 6,
      sym_templating,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [282] = 17,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(29), 1,
      sym_templating_cont_open,
    ACTIONS(31), 1,
      sym_templating_open,
    ACTIONS(35), 1,
      aux_sym_templating_token1,
    ACTIONS(37), 1,
      anon_sym_LT_BANG,
    ACTIONS(39), 1,
      anon_sym_LT,
    ACTIONS(41), 1,
      anon_sym_LT_SLASH,
    ACTIONS(47), 1,
      sym_templating_close_start,
    STATE(7), 1,
      sym_comment,
    STATE(10), 1,
      aux_sym_templating_repeat1,
    STATE(17), 1,
      sym_start_tag,
    STATE(27), 1,
      sym_self_closing_tag,
    STATE(125), 1,
      sym_script_start_tag,
    STATE(126), 1,
      sym_style_start_tag,
    STATE(24), 2,
      sym_template_repeat,
      sym__node,
    ACTIONS(43), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(26), 6,
      sym_templating,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [342] = 17,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(29), 1,
      sym_templating_cont_open,
    ACTIONS(31), 1,
      sym_templating_open,
    ACTIONS(35), 1,
      aux_sym_templating_token1,
    ACTIONS(37), 1,
      anon_sym_LT_BANG,
    ACTIONS(39), 1,
      anon_sym_LT,
    ACTIONS(41), 1,
      anon_sym_LT_SLASH,
    ACTIONS(49), 1,
      sym_templating_close_start,
    STATE(8), 1,
      sym_comment,
    STATE(9), 1,
      aux_sym_templating_repeat1,
    STATE(17), 1,
      sym_start_tag,
    STATE(27), 1,
      sym_self_closing_tag,
    STATE(125), 1,
      sym_script_start_tag,
    STATE(126), 1,
      sym_style_start_tag,
    STATE(24), 2,
      sym_template_repeat,
      sym__node,
    ACTIONS(43), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(26), 6,
      sym_templating,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [402] = 17,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(29), 1,
      sym_templating_cont_open,
    ACTIONS(31), 1,
      sym_templating_open,
    ACTIONS(35), 1,
      aux_sym_templating_token1,
    ACTIONS(37), 1,
      anon_sym_LT_BANG,
    ACTIONS(39), 1,
      anon_sym_LT,
    ACTIONS(41), 1,
      anon_sym_LT_SLASH,
    ACTIONS(51), 1,
      sym_templating_close_start,
    STATE(9), 1,
      sym_comment,
    STATE(10), 1,
      aux_sym_templating_repeat1,
    STATE(17), 1,
      sym_start_tag,
    STATE(27), 1,
      sym_self_closing_tag,
    STATE(125), 1,
      sym_script_start_tag,
    STATE(126), 1,
      sym_style_start_tag,
    STATE(24), 2,
      sym_template_repeat,
      sym__node,
    ACTIONS(43), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(26), 6,
      sym_templating,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [462] = 16,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(53), 1,
      sym_templating_cont_open,
    ACTIONS(56), 1,
      sym_templating_open,
    ACTIONS(59), 1,
      sym_templating_close_start,
    ACTIONS(61), 1,
      aux_sym_templating_token1,
    ACTIONS(64), 1,
      anon_sym_LT_BANG,
    ACTIONS(67), 1,
      anon_sym_LT,
    ACTIONS(70), 1,
      anon_sym_LT_SLASH,
    STATE(17), 1,
      sym_start_tag,
    STATE(27), 1,
      sym_self_closing_tag,
    STATE(125), 1,
      sym_script_start_tag,
    STATE(126), 1,
      sym_style_start_tag,
    STATE(10), 2,
      sym_comment,
      aux_sym_templating_repeat1,
    STATE(24), 2,
      sym_template_repeat,
      sym__node,
    ACTIONS(73), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(26), 6,
      sym_templating,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [520] = 17,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(29), 1,
      sym_templating_cont_open,
    ACTIONS(31), 1,
      sym_templating_open,
    ACTIONS(35), 1,
      aux_sym_templating_token1,
    ACTIONS(37), 1,
      anon_sym_LT_BANG,
    ACTIONS(39), 1,
      anon_sym_LT,
    ACTIONS(41), 1,
      anon_sym_LT_SLASH,
    ACTIONS(76), 1,
      sym_templating_close_start,
    STATE(10), 1,
      aux_sym_templating_repeat1,
    STATE(11), 1,
      sym_comment,
    STATE(17), 1,
      sym_start_tag,
    STATE(27), 1,
      sym_self_closing_tag,
    STATE(125), 1,
      sym_script_start_tag,
    STATE(126), 1,
      sym_style_start_tag,
    STATE(24), 2,
      sym_template_repeat,
      sym__node,
    ACTIONS(43), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(26), 6,
      sym_templating,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [580] = 7,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(80), 1,
      sym_erroneous_end_tag_name,
    ACTIONS(82), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(12), 1,
      sym_comment,
    STATE(158), 1,
      sym__end_tag_name,
    STATE(199), 1,
      sym__start_tag_name,
    ACTIONS(78), 17,
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
  [618] = 7,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(80), 1,
      sym_erroneous_end_tag_name,
    ACTIONS(82), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(13), 1,
      sym_comment,
    STATE(197), 1,
      sym__end_tag_name,
    STATE(199), 1,
      sym__start_tag_name,
    ACTIONS(78), 17,
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
  [656] = 15,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(84), 1,
      ts_builtin_sym_end,
    ACTIONS(86), 1,
      sym_templating_open,
    ACTIONS(89), 1,
      anon_sym_LT_BANG,
    ACTIONS(92), 1,
      anon_sym_LT,
    ACTIONS(95), 1,
      anon_sym_LT_SLASH,
    STATE(21), 1,
      sym_start_tag,
    STATE(43), 1,
      sym_self_closing_tag,
    STATE(58), 1,
      sym__node,
    STATE(112), 1,
      sym_style_start_tag,
    STATE(124), 1,
      sym_script_start_tag,
    STATE(14), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    ACTIONS(98), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(57), 6,
      sym_templating,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [710] = 16,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(9), 1,
      sym_templating_open,
    ACTIONS(11), 1,
      anon_sym_LT_BANG,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_LT_SLASH,
    ACTIONS(101), 1,
      ts_builtin_sym_end,
    STATE(14), 1,
      aux_sym_source_file_repeat1,
    STATE(15), 1,
      sym_comment,
    STATE(21), 1,
      sym_start_tag,
    STATE(43), 1,
      sym_self_closing_tag,
    STATE(58), 1,
      sym__node,
    STATE(112), 1,
      sym_style_start_tag,
    STATE(124), 1,
      sym_script_start_tag,
    ACTIONS(17), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(57), 6,
      sym_templating,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [766] = 7,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(80), 1,
      sym_erroneous_end_tag_name,
    ACTIONS(82), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(16), 1,
      sym_comment,
    STATE(189), 1,
      sym__end_tag_name,
    STATE(199), 1,
      sym__start_tag_name,
    ACTIONS(78), 17,
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
  [804] = 16,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(103), 1,
      sym_templating_open,
    ACTIONS(105), 1,
      anon_sym_LT_BANG,
    ACTIONS(107), 1,
      anon_sym_LT,
    ACTIONS(109), 1,
      anon_sym_LT_SLASH,
    STATE(17), 1,
      sym_comment,
    STATE(19), 1,
      sym_start_tag,
    STATE(20), 1,
      aux_sym_source_file_repeat1,
    STATE(28), 1,
      sym_end_tag,
    STATE(72), 1,
      sym__node,
    STATE(73), 1,
      sym_self_closing_tag,
    STATE(122), 1,
      sym_script_start_tag,
    STATE(123), 1,
      sym_style_start_tag,
    ACTIONS(111), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(71), 6,
      sym_templating,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [860] = 16,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(103), 1,
      sym_templating_open,
    ACTIONS(105), 1,
      anon_sym_LT_BANG,
    ACTIONS(107), 1,
      anon_sym_LT,
    ACTIONS(113), 1,
      anon_sym_LT_SLASH,
    STATE(18), 1,
      sym_comment,
    STATE(19), 1,
      sym_start_tag,
    STATE(23), 1,
      aux_sym_source_file_repeat1,
    STATE(69), 1,
      sym_end_tag,
    STATE(72), 1,
      sym__node,
    STATE(73), 1,
      sym_self_closing_tag,
    STATE(122), 1,
      sym_script_start_tag,
    STATE(123), 1,
      sym_style_start_tag,
    ACTIONS(111), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(71), 6,
      sym_templating,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [916] = 15,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(103), 1,
      sym_templating_open,
    ACTIONS(105), 1,
      anon_sym_LT_BANG,
    ACTIONS(107), 1,
      anon_sym_LT,
    ACTIONS(113), 1,
      anon_sym_LT_SLASH,
    STATE(18), 1,
      aux_sym_source_file_repeat1,
    STATE(72), 1,
      sym__node,
    STATE(73), 1,
      sym_self_closing_tag,
    STATE(74), 1,
      sym_end_tag,
    STATE(122), 1,
      sym_script_start_tag,
    STATE(123), 1,
      sym_style_start_tag,
    STATE(19), 2,
      sym_comment,
      sym_start_tag,
    ACTIONS(111), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(71), 6,
      sym_templating,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [970] = 16,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(103), 1,
      sym_templating_open,
    ACTIONS(105), 1,
      anon_sym_LT_BANG,
    ACTIONS(107), 1,
      anon_sym_LT,
    ACTIONS(109), 1,
      anon_sym_LT_SLASH,
    STATE(19), 1,
      sym_start_tag,
    STATE(20), 1,
      sym_comment,
    STATE(23), 1,
      aux_sym_source_file_repeat1,
    STATE(33), 1,
      sym_end_tag,
    STATE(72), 1,
      sym__node,
    STATE(73), 1,
      sym_self_closing_tag,
    STATE(122), 1,
      sym_script_start_tag,
    STATE(123), 1,
      sym_style_start_tag,
    ACTIONS(111), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(71), 6,
      sym_templating,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [1026] = 16,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(103), 1,
      sym_templating_open,
    ACTIONS(105), 1,
      anon_sym_LT_BANG,
    ACTIONS(107), 1,
      anon_sym_LT,
    ACTIONS(115), 1,
      anon_sym_LT_SLASH,
    STATE(19), 1,
      sym_start_tag,
    STATE(21), 1,
      sym_comment,
    STATE(22), 1,
      aux_sym_source_file_repeat1,
    STATE(53), 1,
      sym_end_tag,
    STATE(72), 1,
      sym__node,
    STATE(73), 1,
      sym_self_closing_tag,
    STATE(122), 1,
      sym_script_start_tag,
    STATE(123), 1,
      sym_style_start_tag,
    ACTIONS(111), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(71), 6,
      sym_templating,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [1082] = 16,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(103), 1,
      sym_templating_open,
    ACTIONS(105), 1,
      anon_sym_LT_BANG,
    ACTIONS(107), 1,
      anon_sym_LT,
    ACTIONS(115), 1,
      anon_sym_LT_SLASH,
    STATE(19), 1,
      sym_start_tag,
    STATE(22), 1,
      sym_comment,
    STATE(23), 1,
      aux_sym_source_file_repeat1,
    STATE(46), 1,
      sym_end_tag,
    STATE(72), 1,
      sym__node,
    STATE(73), 1,
      sym_self_closing_tag,
    STATE(122), 1,
      sym_script_start_tag,
    STATE(123), 1,
      sym_style_start_tag,
    ACTIONS(111), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(71), 6,
      sym_templating,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [1138] = 14,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(117), 1,
      sym_templating_open,
    ACTIONS(120), 1,
      anon_sym_LT_BANG,
    ACTIONS(123), 1,
      anon_sym_LT,
    ACTIONS(126), 1,
      anon_sym_LT_SLASH,
    STATE(19), 1,
      sym_start_tag,
    STATE(72), 1,
      sym__node,
    STATE(73), 1,
      sym_self_closing_tag,
    STATE(122), 1,
      sym_script_start_tag,
    STATE(123), 1,
      sym_style_start_tag,
    STATE(23), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    ACTIONS(129), 3,
      sym_entity,
      sym_substitution,
      sym_text,
    STATE(71), 6,
      sym_templating,
      sym_doctype,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
  [1189] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(24), 1,
      sym_comment,
    ACTIONS(134), 3,
      aux_sym_templating_token1,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(132), 7,
      sym_templating_cont_open,
      sym_templating_open,
      sym_templating_close_start,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1210] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(25), 1,
      sym_comment,
    ACTIONS(138), 3,
      aux_sym_templating_token1,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(136), 7,
      sym_templating_cont_open,
      sym_templating_open,
      sym_templating_close_start,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1231] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(26), 1,
      sym_comment,
    ACTIONS(142), 3,
      aux_sym_templating_token1,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(140), 7,
      sym_templating_cont_open,
      sym_templating_open,
      sym_templating_close_start,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1252] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(27), 1,
      sym_comment,
    ACTIONS(146), 3,
      aux_sym_templating_token1,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(144), 7,
      sym_templating_cont_open,
      sym_templating_open,
      sym_templating_close_start,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1273] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(28), 1,
      sym_comment,
    ACTIONS(150), 3,
      aux_sym_templating_token1,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(148), 7,
      sym_templating_cont_open,
      sym_templating_open,
      sym_templating_close_start,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1294] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(29), 1,
      sym_comment,
    ACTIONS(154), 3,
      aux_sym_templating_token1,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(152), 7,
      sym_templating_cont_open,
      sym_templating_open,
      sym_templating_close_start,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1315] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(30), 1,
      sym_comment,
    ACTIONS(158), 3,
      aux_sym_templating_token1,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(156), 7,
      sym_templating_cont_open,
      sym_templating_open,
      sym_templating_close_start,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1336] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(31), 1,
      sym_comment,
    ACTIONS(162), 3,
      aux_sym_templating_token1,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(160), 7,
      sym_templating_cont_open,
      sym_templating_open,
      sym_templating_close_start,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1357] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(32), 1,
      sym_comment,
    ACTIONS(166), 3,
      aux_sym_templating_token1,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(164), 7,
      sym_templating_cont_open,
      sym_templating_open,
      sym_templating_close_start,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1378] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(33), 1,
      sym_comment,
    ACTIONS(170), 3,
      aux_sym_templating_token1,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(168), 7,
      sym_templating_cont_open,
      sym_templating_open,
      sym_templating_close_start,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1399] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(34), 1,
      sym_comment,
    ACTIONS(174), 3,
      aux_sym_templating_token1,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(172), 7,
      sym_templating_cont_open,
      sym_templating_open,
      sym_templating_close_start,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1420] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(35), 1,
      sym_comment,
    ACTIONS(178), 3,
      aux_sym_templating_token1,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(176), 7,
      sym_templating_cont_open,
      sym_templating_open,
      sym_templating_close_start,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1441] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(36), 1,
      sym_comment,
    ACTIONS(182), 3,
      aux_sym_templating_token1,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(180), 7,
      sym_templating_cont_open,
      sym_templating_open,
      sym_templating_close_start,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1462] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(37), 1,
      sym_comment,
    ACTIONS(186), 3,
      aux_sym_templating_token1,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(184), 7,
      sym_templating_cont_open,
      sym_templating_open,
      sym_templating_close_start,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1483] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(38), 1,
      sym_comment,
    ACTIONS(190), 3,
      aux_sym_templating_token1,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(188), 7,
      sym_templating_cont_open,
      sym_templating_open,
      sym_templating_close_start,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1504] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(39), 1,
      sym_comment,
    ACTIONS(194), 3,
      aux_sym_templating_token1,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(192), 7,
      sym_templating_cont_open,
      sym_templating_open,
      sym_templating_close_start,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1525] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(40), 1,
      sym_comment,
    ACTIONS(198), 3,
      aux_sym_templating_token1,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(196), 7,
      sym_templating_cont_open,
      sym_templating_open,
      sym_templating_close_start,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1546] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(41), 1,
      sym_comment,
    ACTIONS(202), 3,
      aux_sym_templating_token1,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(200), 7,
      sym_templating_cont_open,
      sym_templating_open,
      sym_templating_close_start,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1567] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(42), 1,
      sym_comment,
    ACTIONS(206), 3,
      aux_sym_templating_token1,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(204), 7,
      sym_templating_cont_open,
      sym_templating_open,
      sym_templating_close_start,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1588] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(43), 1,
      sym_comment,
    ACTIONS(146), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(144), 6,
      ts_builtin_sym_end,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1610] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(44), 1,
      sym_comment,
    ACTIONS(154), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(152), 6,
      ts_builtin_sym_end,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1632] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(45), 1,
      sym_comment,
    ACTIONS(166), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(164), 6,
      ts_builtin_sym_end,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1654] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(46), 1,
      sym_comment,
    ACTIONS(170), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(168), 6,
      ts_builtin_sym_end,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1676] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(47), 1,
      sym_comment,
    ACTIONS(174), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(172), 6,
      ts_builtin_sym_end,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1698] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(48), 1,
      sym_comment,
    ACTIONS(206), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(204), 6,
      ts_builtin_sym_end,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1720] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(49), 1,
      sym_comment,
    ACTIONS(198), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(196), 6,
      ts_builtin_sym_end,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1742] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(50), 1,
      sym_comment,
    ACTIONS(194), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(192), 6,
      ts_builtin_sym_end,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1764] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(51), 1,
      sym_comment,
    ACTIONS(182), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(180), 6,
      ts_builtin_sym_end,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1786] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(52), 1,
      sym_comment,
    ACTIONS(178), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(176), 6,
      ts_builtin_sym_end,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1808] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(53), 1,
      sym_comment,
    ACTIONS(150), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(148), 6,
      ts_builtin_sym_end,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1830] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(54), 1,
      sym_comment,
    ACTIONS(202), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(200), 6,
      ts_builtin_sym_end,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1852] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(55), 1,
      sym_comment,
    ACTIONS(190), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(188), 6,
      ts_builtin_sym_end,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1874] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(56), 1,
      sym_comment,
    ACTIONS(186), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(184), 6,
      ts_builtin_sym_end,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1896] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(57), 1,
      sym_comment,
    ACTIONS(142), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(140), 6,
      ts_builtin_sym_end,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1918] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(58), 1,
      sym_comment,
    ACTIONS(210), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(208), 6,
      ts_builtin_sym_end,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1940] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(59), 1,
      sym_comment,
    ACTIONS(158), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(156), 6,
      ts_builtin_sym_end,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1962] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(60), 1,
      sym_comment,
    ACTIONS(162), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(160), 6,
      ts_builtin_sym_end,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [1984] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(61), 1,
      sym_comment,
    ACTIONS(154), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(152), 5,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [2005] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(62), 1,
      sym_comment,
    ACTIONS(166), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(164), 5,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [2026] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(63), 1,
      sym_comment,
    ACTIONS(214), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(212), 5,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [2047] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(64), 1,
      sym_comment,
    ACTIONS(202), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(200), 5,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [2068] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(65), 1,
      sym_comment,
    ACTIONS(182), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(180), 5,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [2089] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(66), 1,
      sym_comment,
    ACTIONS(178), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(176), 5,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [2110] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(67), 1,
      sym_comment,
    ACTIONS(190), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(188), 5,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [2131] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(68), 1,
      sym_comment,
    ACTIONS(186), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(184), 5,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [2152] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(69), 1,
      sym_comment,
    ACTIONS(170), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(168), 5,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [2173] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(70), 1,
      sym_comment,
    ACTIONS(174), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(172), 5,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [2194] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(71), 1,
      sym_comment,
    ACTIONS(142), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(140), 5,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [2215] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(72), 1,
      sym_comment,
    ACTIONS(210), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(208), 5,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [2236] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(73), 1,
      sym_comment,
    ACTIONS(146), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(144), 5,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [2257] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(74), 1,
      sym_comment,
    ACTIONS(150), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(148), 5,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [2278] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(75), 1,
      sym_comment,
    ACTIONS(206), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(204), 5,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [2299] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(76), 1,
      sym_comment,
    ACTIONS(198), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(196), 5,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [2320] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(77), 1,
      sym_comment,
    ACTIONS(218), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(216), 5,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [2341] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(78), 1,
      sym_comment,
    ACTIONS(158), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(156), 5,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [2362] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(79), 1,
      sym_comment,
    ACTIONS(162), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(160), 5,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [2383] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(80), 1,
      sym_comment,
    ACTIONS(194), 2,
      anon_sym_LT_BANG,
      anon_sym_LT,
    ACTIONS(192), 5,
      sym_templating_open,
      anon_sym_LT_SLASH,
      sym_entity,
      sym_substitution,
      sym_text,
  [2404] = 7,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(220), 1,
      anon_sym_GT,
    ACTIONS(225), 1,
      sym_attribute_name,
    STATE(111), 1,
      sym_attribute,
    ACTIONS(222), 2,
      anon_sym_LF,
      anon_sym_CR,
    STATE(81), 2,
      sym_comment,
      aux_sym_start_tag_repeat1,
  [2428] = 8,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(228), 1,
      anon_sym_GT,
    ACTIONS(232), 1,
      sym_attribute_name,
    STATE(81), 1,
      aux_sym_start_tag_repeat1,
    STATE(82), 1,
      sym_comment,
    STATE(111), 1,
      sym_attribute,
    ACTIONS(230), 2,
      anon_sym_LF,
      anon_sym_CR,
  [2454] = 8,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(232), 1,
      sym_attribute_name,
    ACTIONS(234), 1,
      anon_sym_GT,
    STATE(82), 1,
      aux_sym_start_tag_repeat1,
    STATE(83), 1,
      sym_comment,
    STATE(111), 1,
      sym_attribute,
    ACTIONS(230), 2,
      anon_sym_LF,
      anon_sym_CR,
  [2480] = 7,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(238), 1,
      sym_attribute_name,
    STATE(84), 1,
      sym_comment,
    STATE(96), 1,
      aux_sym_script_start_tag_repeat1,
    STATE(129), 1,
      sym_attribute,
    ACTIONS(236), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [2503] = 7,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(240), 1,
      anon_sym_if,
    ACTIONS(242), 1,
      anon_sym_for,
    STATE(85), 1,
      sym_comment,
    STATE(163), 1,
      sym_templating_decl,
    STATE(201), 2,
      sym_templating_decl_if,
      sym_templating_decl_for,
  [2526] = 7,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(238), 1,
      sym_attribute_name,
    STATE(86), 1,
      sym_comment,
    STATE(91), 1,
      aux_sym_script_start_tag_repeat1,
    STATE(129), 1,
      sym_attribute,
    ACTIONS(244), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [2549] = 7,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(246), 1,
      aux_sym_comment_token1,
    ACTIONS(250), 1,
      anon_sym_DASH_DASH_GT,
    STATE(87), 1,
      sym_comment,
    STATE(89), 1,
      aux_sym_comment_repeat1,
    ACTIONS(248), 2,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
  [2572] = 7,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(238), 1,
      sym_attribute_name,
    STATE(88), 1,
      sym_comment,
    STATE(97), 1,
      aux_sym_script_start_tag_repeat1,
    STATE(129), 1,
      sym_attribute,
    ACTIONS(252), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [2595] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(254), 1,
      aux_sym_comment_token1,
    ACTIONS(260), 1,
      anon_sym_DASH_DASH_GT,
    ACTIONS(257), 2,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
    STATE(89), 2,
      sym_comment,
      aux_sym_comment_repeat1,
  [2616] = 7,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(262), 1,
      anon_sym_elseif,
    ACTIONS(264), 1,
      anon_sym_else,
    STATE(90), 1,
      sym_comment,
    STATE(191), 1,
      sym_templating_repeat_decl,
    STATE(190), 2,
      sym_templating_repeat_elseif,
      sym_templating_repeat_else,
  [2639] = 7,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(238), 1,
      sym_attribute_name,
    STATE(91), 1,
      sym_comment,
    STATE(96), 1,
      aux_sym_script_start_tag_repeat1,
    STATE(129), 1,
      sym_attribute,
    ACTIONS(266), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [2662] = 7,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(240), 1,
      anon_sym_if,
    ACTIONS(242), 1,
      anon_sym_for,
    STATE(92), 1,
      sym_comment,
    STATE(208), 1,
      sym_templating_decl,
    STATE(201), 2,
      sym_templating_decl_if,
      sym_templating_decl_for,
  [2685] = 7,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(238), 1,
      sym_attribute_name,
    STATE(84), 1,
      aux_sym_script_start_tag_repeat1,
    STATE(93), 1,
      sym_comment,
    STATE(129), 1,
      sym_attribute,
    ACTIONS(268), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [2708] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(274), 1,
      anon_sym_EQ,
    STATE(94), 1,
      sym_comment,
    ACTIONS(270), 2,
      anon_sym_GT,
      sym_attribute_name,
    ACTIONS(272), 2,
      anon_sym_LF,
      anon_sym_CR,
  [2729] = 7,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(246), 1,
      aux_sym_comment_token1,
    ACTIONS(276), 1,
      anon_sym_DASH_DASH_GT,
    STATE(87), 1,
      aux_sym_comment_repeat1,
    STATE(95), 1,
      sym_comment,
    ACTIONS(248), 2,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
  [2752] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(280), 1,
      sym_attribute_name,
    STATE(129), 1,
      sym_attribute,
    ACTIONS(278), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
    STATE(96), 2,
      sym_comment,
      aux_sym_script_start_tag_repeat1,
  [2773] = 7,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(238), 1,
      sym_attribute_name,
    STATE(96), 1,
      aux_sym_script_start_tag_repeat1,
    STATE(97), 1,
      sym_comment,
    STATE(129), 1,
      sym_attribute,
    ACTIONS(283), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [2796] = 7,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(240), 1,
      anon_sym_if,
    ACTIONS(242), 1,
      anon_sym_for,
    STATE(98), 1,
      sym_comment,
    STATE(209), 1,
      sym_templating_decl,
    STATE(201), 2,
      sym_templating_decl_if,
      sym_templating_decl_for,
  [2819] = 7,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(238), 1,
      sym_attribute_name,
    ACTIONS(285), 1,
      anon_sym_GT,
    STATE(99), 1,
      sym_comment,
    STATE(108), 1,
      aux_sym_script_start_tag_repeat1,
    STATE(129), 1,
      sym_attribute,
  [2841] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(100), 1,
      sym_comment,
    ACTIONS(287), 2,
      anon_sym_GT,
      sym_attribute_name,
    ACTIONS(289), 2,
      anon_sym_LF,
      anon_sym_CR,
  [2859] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(101), 1,
      sym_comment,
    ACTIONS(291), 2,
      anon_sym_GT,
      sym_attribute_name,
    ACTIONS(293), 2,
      anon_sym_LF,
      anon_sym_CR,
  [2877] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(102), 1,
      sym_comment,
    ACTIONS(295), 2,
      anon_sym_GT,
      sym_attribute_name,
    ACTIONS(297), 2,
      anon_sym_LF,
      anon_sym_CR,
  [2895] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(103), 1,
      sym_comment,
    ACTIONS(299), 2,
      anon_sym_GT,
      sym_attribute_name,
    ACTIONS(301), 2,
      anon_sym_LF,
      anon_sym_CR,
  [2913] = 7,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(303), 1,
      sym_attribute_value,
    ACTIONS(305), 1,
      anon_sym_SQUOTE,
    ACTIONS(307), 1,
      anon_sym_DQUOTE,
    STATE(104), 1,
      sym_comment,
    STATE(116), 1,
      sym_quoted_attribute_value,
  [2935] = 7,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(238), 1,
      sym_attribute_name,
    ACTIONS(309), 1,
      anon_sym_GT,
    STATE(96), 1,
      aux_sym_script_start_tag_repeat1,
    STATE(105), 1,
      sym_comment,
    STATE(129), 1,
      sym_attribute,
  [2957] = 7,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(311), 1,
      sym_attribute_value,
    ACTIONS(313), 1,
      anon_sym_SQUOTE,
    ACTIONS(315), 1,
      anon_sym_DQUOTE,
    STATE(101), 1,
      sym_quoted_attribute_value,
    STATE(106), 1,
      sym_comment,
  [2979] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(317), 1,
      anon_sym_EQ,
    STATE(107), 1,
      sym_comment,
    ACTIONS(270), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [2997] = 7,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(238), 1,
      sym_attribute_name,
    ACTIONS(319), 1,
      anon_sym_GT,
    STATE(96), 1,
      aux_sym_script_start_tag_repeat1,
    STATE(108), 1,
      sym_comment,
    STATE(129), 1,
      sym_attribute,
  [3019] = 7,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(238), 1,
      sym_attribute_name,
    ACTIONS(321), 1,
      anon_sym_GT,
    STATE(105), 1,
      aux_sym_script_start_tag_repeat1,
    STATE(109), 1,
      sym_comment,
    STATE(129), 1,
      sym_attribute,
  [3041] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(323), 1,
      aux_sym_comment_token1,
    STATE(110), 1,
      sym_comment,
    ACTIONS(325), 3,
      aux_sym_comment_token2,
      aux_sym_comment_token3,
      anon_sym_DASH_DASH_GT,
  [3059] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(111), 1,
      sym_comment,
    ACTIONS(327), 2,
      anon_sym_GT,
      sym_attribute_name,
    ACTIONS(329), 2,
      anon_sym_LF,
      anon_sym_CR,
  [3077] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(331), 1,
      sym_raw_text,
    ACTIONS(333), 1,
      anon_sym_LT_SLASH,
    STATE(59), 1,
      sym_style_end_tag,
    STATE(112), 1,
      sym_comment,
  [3096] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    STATE(113), 1,
      sym_comment,
    STATE(184), 1,
      sym_conditional,
    ACTIONS(335), 2,
      anon_sym_if,
      anon_sym_for,
  [3113] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(337), 1,
      anon_sym_COMMA,
    ACTIONS(339), 1,
      anon_sym_in,
    STATE(114), 1,
      sym_comment,
    STATE(121), 1,
      aux_sym_templating_decl_for_repeat1,
  [3132] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    STATE(115), 1,
      sym_comment,
    STATE(195), 1,
      sym_conditional,
    ACTIONS(335), 2,
      anon_sym_if,
      anon_sym_for,
  [3149] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    STATE(116), 1,
      sym_comment,
    ACTIONS(291), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [3164] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    STATE(117), 1,
      sym_comment,
    ACTIONS(287), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [3179] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    STATE(118), 1,
      sym_comment,
    ACTIONS(299), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [3194] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(337), 1,
      anon_sym_COMMA,
    ACTIONS(341), 1,
      anon_sym_in,
    STATE(114), 1,
      aux_sym_templating_decl_for_repeat1,
    STATE(119), 1,
      sym_comment,
  [3213] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    STATE(120), 1,
      sym_comment,
    ACTIONS(343), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [3228] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(345), 1,
      anon_sym_COMMA,
    ACTIONS(348), 1,
      anon_sym_in,
    STATE(121), 2,
      sym_comment,
      aux_sym_templating_decl_for_repeat1,
  [3245] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(350), 1,
      sym_raw_text,
    ACTIONS(352), 1,
      anon_sym_LT_SLASH,
    STATE(61), 1,
      sym_script_end_tag,
    STATE(122), 1,
      sym_comment,
  [3264] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(354), 1,
      sym_raw_text,
    ACTIONS(356), 1,
      anon_sym_LT_SLASH,
    STATE(78), 1,
      sym_style_end_tag,
    STATE(123), 1,
      sym_comment,
  [3283] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(358), 1,
      sym_raw_text,
    ACTIONS(360), 1,
      anon_sym_LT_SLASH,
    STATE(44), 1,
      sym_script_end_tag,
    STATE(124), 1,
      sym_comment,
  [3302] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(362), 1,
      sym_raw_text,
    ACTIONS(364), 1,
      anon_sym_LT_SLASH,
    STATE(29), 1,
      sym_script_end_tag,
    STATE(125), 1,
      sym_comment,
  [3321] = 6,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(366), 1,
      sym_raw_text,
    ACTIONS(368), 1,
      anon_sym_LT_SLASH,
    STATE(30), 1,
      sym_style_end_tag,
    STATE(126), 1,
      sym_comment,
  [3340] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    STATE(127), 1,
      sym_comment,
    STATE(165), 1,
      sym_conditional,
    ACTIONS(335), 2,
      anon_sym_if,
      anon_sym_for,
  [3357] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    STATE(128), 1,
      sym_comment,
    STATE(168), 1,
      sym_conditional,
    ACTIONS(335), 2,
      anon_sym_if,
      anon_sym_for,
  [3374] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    STATE(129), 1,
      sym_comment,
    ACTIONS(370), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [3389] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    STATE(130), 1,
      sym_comment,
    STATE(183), 1,
      sym_conditional,
    ACTIONS(335), 2,
      anon_sym_if,
      anon_sym_for,
  [3406] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    STATE(131), 1,
      sym_comment,
    STATE(155), 1,
      sym_conditional,
    ACTIONS(335), 2,
      anon_sym_if,
      anon_sym_for,
  [3423] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(360), 1,
      anon_sym_LT_SLASH,
    STATE(47), 1,
      sym_script_end_tag,
    STATE(132), 1,
      sym_comment,
  [3439] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(133), 1,
      sym_comment,
    ACTIONS(372), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [3453] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(352), 1,
      anon_sym_LT_SLASH,
    STATE(70), 1,
      sym_script_end_tag,
    STATE(134), 1,
      sym_comment,
  [3469] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(356), 1,
      anon_sym_LT_SLASH,
    STATE(75), 1,
      sym_style_end_tag,
    STATE(135), 1,
      sym_comment,
  [3485] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(333), 1,
      anon_sym_LT_SLASH,
    STATE(48), 1,
      sym_style_end_tag,
    STATE(136), 1,
      sym_comment,
  [3501] = 5,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(82), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(374), 1,
      anon_sym_SQUOTE,
    ACTIONS(376), 1,
      aux_sym_quoted_attribute_value_token1,
    STATE(137), 1,
      sym_comment,
  [3517] = 5,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(82), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(378), 1,
      anon_sym_SQUOTE,
    ACTIONS(380), 1,
      aux_sym_quoted_attribute_value_token1,
    STATE(138), 1,
      sym_comment,
  [3533] = 5,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(82), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(378), 1,
      anon_sym_DQUOTE,
    ACTIONS(382), 1,
      aux_sym_quoted_attribute_value_token2,
    STATE(139), 1,
      sym_comment,
  [3549] = 5,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(82), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(374), 1,
      anon_sym_DQUOTE,
    ACTIONS(384), 1,
      aux_sym_quoted_attribute_value_token2,
    STATE(140), 1,
      sym_comment,
  [3565] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(141), 1,
      sym_comment,
    ACTIONS(386), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [3579] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    STATE(142), 1,
      sym_comment,
    ACTIONS(388), 2,
      anon_sym_GT,
      sym_attribute_name,
  [3593] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(364), 1,
      anon_sym_LT_SLASH,
    STATE(34), 1,
      sym_script_end_tag,
    STATE(143), 1,
      sym_comment,
  [3609] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(368), 1,
      anon_sym_LT_SLASH,
    STATE(42), 1,
      sym_style_end_tag,
    STATE(144), 1,
      sym_comment,
  [3625] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(145), 1,
      sym_comment,
    ACTIONS(390), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [3639] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(392), 1,
      anon_sym_script,
    STATE(146), 1,
      sym_comment,
    STATE(161), 1,
      sym__script_start_tag_name,
  [3655] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(394), 1,
      anon_sym_style,
    STATE(147), 1,
      sym_comment,
    STATE(162), 1,
      sym__style_start_tag_name,
  [3671] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(392), 1,
      anon_sym_script,
    STATE(148), 1,
      sym_comment,
    STATE(160), 1,
      sym__script_start_tag_name,
  [3687] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    STATE(149), 1,
      sym_comment,
    ACTIONS(348), 2,
      anon_sym_COMMA,
      anon_sym_in,
  [3701] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    STATE(150), 1,
      sym_comment,
    ACTIONS(396), 2,
      anon_sym_GT,
      sym_attribute_name,
  [3715] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(392), 1,
      anon_sym_script,
    STATE(151), 1,
      sym_comment,
    STATE(180), 1,
      sym__script_start_tag_name,
  [3731] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(394), 1,
      anon_sym_style,
    STATE(152), 1,
      sym_comment,
    STATE(181), 1,
      sym__style_start_tag_name,
  [3747] = 5,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(394), 1,
      anon_sym_style,
    STATE(153), 1,
      sym_comment,
    STATE(172), 1,
      sym__style_start_tag_name,
  [3763] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    STATE(154), 1,
      sym_comment,
    ACTIONS(398), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [3777] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(400), 1,
      sym_templating_close,
    STATE(155), 1,
      sym_comment,
  [3790] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(402), 1,
      sym__doctype,
    STATE(156), 1,
      sym_comment,
  [3803] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(404), 1,
      sym_templating_close,
    STATE(157), 1,
      sym_comment,
  [3816] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(406), 1,
      aux_sym_end_tag_token1,
    STATE(158), 1,
      sym_comment,
  [3829] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(408), 1,
      anon_sym_GT,
    STATE(159), 1,
      sym_comment,
  [3842] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(410), 1,
      anon_sym_GT,
    STATE(160), 1,
      sym_comment,
  [3855] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(412), 1,
      anon_sym_GT,
    STATE(161), 1,
      sym_comment,
  [3868] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(414), 1,
      anon_sym_GT,
    STATE(162), 1,
      sym_comment,
  [3881] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(416), 1,
      sym_templating_close,
    STATE(163), 1,
      sym_comment,
  [3894] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(418), 1,
      anon_sym_GT,
    STATE(164), 1,
      sym_comment,
  [3907] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(420), 1,
      sym_templating_close,
    STATE(165), 1,
      sym_comment,
  [3920] = 4,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(82), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(422), 1,
      aux_sym_doctype_token1,
    STATE(166), 1,
      sym_comment,
  [3933] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(424), 1,
      anon_sym_GT,
    STATE(167), 1,
      sym_comment,
  [3946] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(426), 1,
      sym_templating_close,
    STATE(168), 1,
      sym_comment,
  [3959] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(428), 1,
      anon_sym_SQUOTE,
    STATE(169), 1,
      sym_comment,
  [3972] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(428), 1,
      anon_sym_DQUOTE,
    STATE(170), 1,
      sym_comment,
  [3985] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(430), 1,
      anon_sym_GT,
    STATE(171), 1,
      sym_comment,
  [3998] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(432), 1,
      anon_sym_GT,
    STATE(172), 1,
      sym_comment,
  [4011] = 4,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(82), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(434), 1,
      sym_erroneous_end_tag_name,
    STATE(173), 1,
      sym_comment,
  [4024] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(436), 1,
      anon_sym_GT,
    STATE(174), 1,
      sym_comment,
  [4037] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(438), 1,
      sym_templating_close,
    STATE(175), 1,
      sym_comment,
  [4050] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(440), 1,
      sym_templating_close,
    STATE(176), 1,
      sym_comment,
  [4063] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(442), 1,
      sym_if_clause,
    STATE(177), 1,
      sym_comment,
  [4076] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(444), 1,
      anon_sym_GT,
    STATE(178), 1,
      sym_comment,
  [4089] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(446), 1,
      sym_templating_close,
    STATE(179), 1,
      sym_comment,
  [4102] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(448), 1,
      anon_sym_GT,
    STATE(180), 1,
      sym_comment,
  [4115] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(450), 1,
      anon_sym_GT,
    STATE(181), 1,
      sym_comment,
  [4128] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(297), 1,
      aux_sym_end_tag_token1,
    STATE(182), 1,
      sym_comment,
  [4141] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(452), 1,
      sym_templating_close,
    STATE(183), 1,
      sym_comment,
  [4154] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(454), 1,
      sym_templating_close,
    STATE(184), 1,
      sym_comment,
  [4167] = 4,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(82), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(456), 1,
      sym_erroneous_end_tag_name,
    STATE(185), 1,
      sym_comment,
  [4180] = 4,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(82), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(458), 1,
      aux_sym_doctype_token1,
    STATE(186), 1,
      sym_comment,
  [4193] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(460), 1,
      sym_if_clause,
    STATE(187), 1,
      sym_comment,
  [4206] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(462), 1,
      sym_templating_close,
    STATE(188), 1,
      sym_comment,
  [4219] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(464), 1,
      aux_sym_end_tag_token1,
    STATE(189), 1,
      sym_comment,
  [4232] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(466), 1,
      sym_templating_close,
    STATE(190), 1,
      sym_comment,
  [4245] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(468), 1,
      sym_templating_close,
    STATE(191), 1,
      sym_comment,
  [4258] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(470), 1,
      sym_templating_close,
    STATE(192), 1,
      sym_comment,
  [4271] = 4,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(80), 1,
      sym_erroneous_end_tag_name,
    ACTIONS(82), 1,
      anon_sym_LT_BANG_DASH_DASH,
    STATE(193), 1,
      sym_comment,
  [4284] = 4,
    ACTIONS(5), 1,
      aux_sym_templating_token1,
    ACTIONS(82), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(472), 1,
      aux_sym_doctype_token1,
    STATE(194), 1,
      sym_comment,
  [4297] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(474), 1,
      sym_templating_close,
    STATE(195), 1,
      sym_comment,
  [4310] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(476), 1,
      sym_named_variable,
    STATE(196), 1,
      sym_comment,
  [4323] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(478), 1,
      aux_sym_end_tag_token1,
    STATE(197), 1,
      sym_comment,
  [4336] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(480), 1,
      sym_if_clause,
    STATE(198), 1,
      sym_comment,
  [4349] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(482), 1,
      aux_sym_end_tag_token1,
    STATE(199), 1,
      sym_comment,
  [4362] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(484), 1,
      sym__doctype,
    STATE(200), 1,
      sym_comment,
  [4375] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(486), 1,
      sym_templating_close,
    STATE(201), 1,
      sym_comment,
  [4388] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(488), 1,
      ts_builtin_sym_end,
    STATE(202), 1,
      sym_comment,
  [4401] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(490), 1,
      anon_sym_SQUOTE,
    STATE(203), 1,
      sym_comment,
  [4414] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(492), 1,
      sym__doctype,
    STATE(204), 1,
      sym_comment,
  [4427] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(490), 1,
      anon_sym_DQUOTE,
    STATE(205), 1,
      sym_comment,
  [4440] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(494), 1,
      anon_sym_GT,
    STATE(206), 1,
      sym_comment,
  [4453] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(496), 1,
      anon_sym_GT,
    STATE(207), 1,
      sym_comment,
  [4466] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(498), 1,
      sym_templating_close,
    STATE(208), 1,
      sym_comment,
  [4479] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(500), 1,
      sym_templating_close,
    STATE(209), 1,
      sym_comment,
  [4492] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(502), 1,
      sym_if_clause,
    STATE(210), 1,
      sym_comment,
  [4505] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(504), 1,
      sym_named_variable,
    STATE(211), 1,
      sym_comment,
  [4518] = 4,
    ACTIONS(3), 1,
      anon_sym_LT_BANG_DASH_DASH,
    ACTIONS(27), 1,
      aux_sym_templating_token1,
    ACTIONS(506), 1,
      anon_sym_GT,
    STATE(212), 1,
      sym_comment,
  [4531] = 1,
    ACTIONS(508), 1,
      ts_builtin_sym_end,
  [4535] = 1,
    ACTIONS(510), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 54,
  [SMALL_STATE(4)] = 108,
  [SMALL_STATE(5)] = 162,
  [SMALL_STATE(6)] = 222,
  [SMALL_STATE(7)] = 282,
  [SMALL_STATE(8)] = 342,
  [SMALL_STATE(9)] = 402,
  [SMALL_STATE(10)] = 462,
  [SMALL_STATE(11)] = 520,
  [SMALL_STATE(12)] = 580,
  [SMALL_STATE(13)] = 618,
  [SMALL_STATE(14)] = 656,
  [SMALL_STATE(15)] = 710,
  [SMALL_STATE(16)] = 766,
  [SMALL_STATE(17)] = 804,
  [SMALL_STATE(18)] = 860,
  [SMALL_STATE(19)] = 916,
  [SMALL_STATE(20)] = 970,
  [SMALL_STATE(21)] = 1026,
  [SMALL_STATE(22)] = 1082,
  [SMALL_STATE(23)] = 1138,
  [SMALL_STATE(24)] = 1189,
  [SMALL_STATE(25)] = 1210,
  [SMALL_STATE(26)] = 1231,
  [SMALL_STATE(27)] = 1252,
  [SMALL_STATE(28)] = 1273,
  [SMALL_STATE(29)] = 1294,
  [SMALL_STATE(30)] = 1315,
  [SMALL_STATE(31)] = 1336,
  [SMALL_STATE(32)] = 1357,
  [SMALL_STATE(33)] = 1378,
  [SMALL_STATE(34)] = 1399,
  [SMALL_STATE(35)] = 1420,
  [SMALL_STATE(36)] = 1441,
  [SMALL_STATE(37)] = 1462,
  [SMALL_STATE(38)] = 1483,
  [SMALL_STATE(39)] = 1504,
  [SMALL_STATE(40)] = 1525,
  [SMALL_STATE(41)] = 1546,
  [SMALL_STATE(42)] = 1567,
  [SMALL_STATE(43)] = 1588,
  [SMALL_STATE(44)] = 1610,
  [SMALL_STATE(45)] = 1632,
  [SMALL_STATE(46)] = 1654,
  [SMALL_STATE(47)] = 1676,
  [SMALL_STATE(48)] = 1698,
  [SMALL_STATE(49)] = 1720,
  [SMALL_STATE(50)] = 1742,
  [SMALL_STATE(51)] = 1764,
  [SMALL_STATE(52)] = 1786,
  [SMALL_STATE(53)] = 1808,
  [SMALL_STATE(54)] = 1830,
  [SMALL_STATE(55)] = 1852,
  [SMALL_STATE(56)] = 1874,
  [SMALL_STATE(57)] = 1896,
  [SMALL_STATE(58)] = 1918,
  [SMALL_STATE(59)] = 1940,
  [SMALL_STATE(60)] = 1962,
  [SMALL_STATE(61)] = 1984,
  [SMALL_STATE(62)] = 2005,
  [SMALL_STATE(63)] = 2026,
  [SMALL_STATE(64)] = 2047,
  [SMALL_STATE(65)] = 2068,
  [SMALL_STATE(66)] = 2089,
  [SMALL_STATE(67)] = 2110,
  [SMALL_STATE(68)] = 2131,
  [SMALL_STATE(69)] = 2152,
  [SMALL_STATE(70)] = 2173,
  [SMALL_STATE(71)] = 2194,
  [SMALL_STATE(72)] = 2215,
  [SMALL_STATE(73)] = 2236,
  [SMALL_STATE(74)] = 2257,
  [SMALL_STATE(75)] = 2278,
  [SMALL_STATE(76)] = 2299,
  [SMALL_STATE(77)] = 2320,
  [SMALL_STATE(78)] = 2341,
  [SMALL_STATE(79)] = 2362,
  [SMALL_STATE(80)] = 2383,
  [SMALL_STATE(81)] = 2404,
  [SMALL_STATE(82)] = 2428,
  [SMALL_STATE(83)] = 2454,
  [SMALL_STATE(84)] = 2480,
  [SMALL_STATE(85)] = 2503,
  [SMALL_STATE(86)] = 2526,
  [SMALL_STATE(87)] = 2549,
  [SMALL_STATE(88)] = 2572,
  [SMALL_STATE(89)] = 2595,
  [SMALL_STATE(90)] = 2616,
  [SMALL_STATE(91)] = 2639,
  [SMALL_STATE(92)] = 2662,
  [SMALL_STATE(93)] = 2685,
  [SMALL_STATE(94)] = 2708,
  [SMALL_STATE(95)] = 2729,
  [SMALL_STATE(96)] = 2752,
  [SMALL_STATE(97)] = 2773,
  [SMALL_STATE(98)] = 2796,
  [SMALL_STATE(99)] = 2819,
  [SMALL_STATE(100)] = 2841,
  [SMALL_STATE(101)] = 2859,
  [SMALL_STATE(102)] = 2877,
  [SMALL_STATE(103)] = 2895,
  [SMALL_STATE(104)] = 2913,
  [SMALL_STATE(105)] = 2935,
  [SMALL_STATE(106)] = 2957,
  [SMALL_STATE(107)] = 2979,
  [SMALL_STATE(108)] = 2997,
  [SMALL_STATE(109)] = 3019,
  [SMALL_STATE(110)] = 3041,
  [SMALL_STATE(111)] = 3059,
  [SMALL_STATE(112)] = 3077,
  [SMALL_STATE(113)] = 3096,
  [SMALL_STATE(114)] = 3113,
  [SMALL_STATE(115)] = 3132,
  [SMALL_STATE(116)] = 3149,
  [SMALL_STATE(117)] = 3164,
  [SMALL_STATE(118)] = 3179,
  [SMALL_STATE(119)] = 3194,
  [SMALL_STATE(120)] = 3213,
  [SMALL_STATE(121)] = 3228,
  [SMALL_STATE(122)] = 3245,
  [SMALL_STATE(123)] = 3264,
  [SMALL_STATE(124)] = 3283,
  [SMALL_STATE(125)] = 3302,
  [SMALL_STATE(126)] = 3321,
  [SMALL_STATE(127)] = 3340,
  [SMALL_STATE(128)] = 3357,
  [SMALL_STATE(129)] = 3374,
  [SMALL_STATE(130)] = 3389,
  [SMALL_STATE(131)] = 3406,
  [SMALL_STATE(132)] = 3423,
  [SMALL_STATE(133)] = 3439,
  [SMALL_STATE(134)] = 3453,
  [SMALL_STATE(135)] = 3469,
  [SMALL_STATE(136)] = 3485,
  [SMALL_STATE(137)] = 3501,
  [SMALL_STATE(138)] = 3517,
  [SMALL_STATE(139)] = 3533,
  [SMALL_STATE(140)] = 3549,
  [SMALL_STATE(141)] = 3565,
  [SMALL_STATE(142)] = 3579,
  [SMALL_STATE(143)] = 3593,
  [SMALL_STATE(144)] = 3609,
  [SMALL_STATE(145)] = 3625,
  [SMALL_STATE(146)] = 3639,
  [SMALL_STATE(147)] = 3655,
  [SMALL_STATE(148)] = 3671,
  [SMALL_STATE(149)] = 3687,
  [SMALL_STATE(150)] = 3701,
  [SMALL_STATE(151)] = 3715,
  [SMALL_STATE(152)] = 3731,
  [SMALL_STATE(153)] = 3747,
  [SMALL_STATE(154)] = 3763,
  [SMALL_STATE(155)] = 3777,
  [SMALL_STATE(156)] = 3790,
  [SMALL_STATE(157)] = 3803,
  [SMALL_STATE(158)] = 3816,
  [SMALL_STATE(159)] = 3829,
  [SMALL_STATE(160)] = 3842,
  [SMALL_STATE(161)] = 3855,
  [SMALL_STATE(162)] = 3868,
  [SMALL_STATE(163)] = 3881,
  [SMALL_STATE(164)] = 3894,
  [SMALL_STATE(165)] = 3907,
  [SMALL_STATE(166)] = 3920,
  [SMALL_STATE(167)] = 3933,
  [SMALL_STATE(168)] = 3946,
  [SMALL_STATE(169)] = 3959,
  [SMALL_STATE(170)] = 3972,
  [SMALL_STATE(171)] = 3985,
  [SMALL_STATE(172)] = 3998,
  [SMALL_STATE(173)] = 4011,
  [SMALL_STATE(174)] = 4024,
  [SMALL_STATE(175)] = 4037,
  [SMALL_STATE(176)] = 4050,
  [SMALL_STATE(177)] = 4063,
  [SMALL_STATE(178)] = 4076,
  [SMALL_STATE(179)] = 4089,
  [SMALL_STATE(180)] = 4102,
  [SMALL_STATE(181)] = 4115,
  [SMALL_STATE(182)] = 4128,
  [SMALL_STATE(183)] = 4141,
  [SMALL_STATE(184)] = 4154,
  [SMALL_STATE(185)] = 4167,
  [SMALL_STATE(186)] = 4180,
  [SMALL_STATE(187)] = 4193,
  [SMALL_STATE(188)] = 4206,
  [SMALL_STATE(189)] = 4219,
  [SMALL_STATE(190)] = 4232,
  [SMALL_STATE(191)] = 4245,
  [SMALL_STATE(192)] = 4258,
  [SMALL_STATE(193)] = 4271,
  [SMALL_STATE(194)] = 4284,
  [SMALL_STATE(195)] = 4297,
  [SMALL_STATE(196)] = 4310,
  [SMALL_STATE(197)] = 4323,
  [SMALL_STATE(198)] = 4336,
  [SMALL_STATE(199)] = 4349,
  [SMALL_STATE(200)] = 4362,
  [SMALL_STATE(201)] = 4375,
  [SMALL_STATE(202)] = 4388,
  [SMALL_STATE(203)] = 4401,
  [SMALL_STATE(204)] = 4414,
  [SMALL_STATE(205)] = 4427,
  [SMALL_STATE(206)] = 4440,
  [SMALL_STATE(207)] = 4453,
  [SMALL_STATE(208)] = 4466,
  [SMALL_STATE(209)] = 4479,
  [SMALL_STATE(210)] = 4492,
  [SMALL_STATE(211)] = 4505,
  [SMALL_STATE(212)] = 4518,
  [SMALL_STATE(213)] = 4531,
  [SMALL_STATE(214)] = 4535,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(156),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(150),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(142),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(120),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(204),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_templating_repeat1, 2, 0, 0), SHIFT_REPEAT(90),
  [56] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_templating_repeat1, 2, 0, 0), SHIFT_REPEAT(98),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_templating_repeat1, 2, 0, 0),
  [61] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_templating_repeat1, 2, 0, 0), SHIFT_REPEAT(24),
  [64] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_templating_repeat1, 2, 0, 0), SHIFT_REPEAT(204),
  [67] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_templating_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [70] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_templating_repeat1, 2, 0, 0), SHIFT_REPEAT(185),
  [73] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_templating_repeat1, 2, 0, 0), SHIFT_REPEAT(26),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [78] = {.entry = {.count = 1, .reusable = false}}, SHIFT(182),
  [80] = {.entry = {.count = 1, .reusable = false}}, SHIFT(206),
  [82] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [86] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(85),
  [89] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(156),
  [92] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [95] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(173),
  [98] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(57),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(200),
  [107] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [117] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(92),
  [120] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(200),
  [123] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [126] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(193),
  [129] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(71),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_templating_repeat1, 1, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_templating_repeat1, 1, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template_repeat, 3, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_template_repeat, 3, 0, 0),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__node, 1, 0, 0),
  [142] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__node, 1, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 1, 0, 0),
  [146] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 1, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 2, 0, 0),
  [150] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 2, 0, 0),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 2, 0, 0),
  [154] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 2, 0, 0),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 2, 0, 0),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 2, 0, 0),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 3, 0, 0),
  [162] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 3, 0, 0),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_erroneous_end_tag, 3, 0, 0),
  [166] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_erroneous_end_tag, 3, 0, 0),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 3, 0, 0),
  [170] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 3, 0, 0),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 3, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 3, 0, 0),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_end_tag, 3, 0, 0),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_end_tag, 3, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_end_tag, 3, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_end_tag, 3, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_templating, 7, 0, 0),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_templating, 7, 0, 0),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_templating, 6, 0, 0),
  [190] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_templating, 6, 0, 0),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 4, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 4, 0, 0),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doctype, 4, 0, 0),
  [198] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_doctype, 4, 0, 0),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_end_tag, 4, 0, 0),
  [202] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_end_tag, 4, 0, 0),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 3, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 3, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 1, 0, 0),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 1, 0, 0),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 4, 0, 2),
  [214] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 4, 0, 2),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 3, 0, 2),
  [218] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 3, 0, 2),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2, 0, 0),
  [222] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_start_tag_repeat1, 2, 0, 0), SHIFT_REPEAT(111),
  [225] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2, 0, 0), SHIFT_REPEAT(94),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [230] = {.entry = {.count = 1, .reusable = false}}, SHIFT(111),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [246] = {.entry = {.count = 1, .reusable = false}}, SHIFT(110),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [254] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(110),
  [257] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(110),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_comment_repeat1, 2, 0, 0),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [264] = {.entry = {.count = 1, .reusable = false}}, SHIFT(188),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1, 0, 0),
  [272] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 1, 0, 0),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_start_tag_repeat1, 2, 0, 0),
  [280] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_start_tag_repeat1, 2, 0, 0), SHIFT_REPEAT(107),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [287] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 2, 0, 0),
  [289] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quoted_attribute_value, 2, 0, 0),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3, 0, 0),
  [293] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 3, 0, 0),
  [295] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__start_tag_name, 1, 0, 0),
  [297] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__start_tag_name, 1, 0, 0),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 3, 0, 0),
  [301] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quoted_attribute_value, 3, 0, 0),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [323] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_comment_repeat1, 1, 0, 0),
  [325] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_comment_repeat1, 1, 0, 0),
  [327] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 1, 0, 0),
  [329] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_start_tag_repeat1, 1, 0, 0),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [343] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tags, 1, 0, 0),
  [345] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_templating_decl_for_repeat1, 2, 0, 0), SHIFT_REPEAT(196),
  [348] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_templating_decl_for_repeat1, 2, 0, 0),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [370] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_start_tag_repeat1, 1, 0, 0),
  [372] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 3, 0, 0),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [376] = {.entry = {.count = 1, .reusable = false}}, SHIFT(203),
  [378] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [380] = {.entry = {.count = 1, .reusable = false}}, SHIFT(169),
  [382] = {.entry = {.count = 1, .reusable = false}}, SHIFT(170),
  [384] = {.entry = {.count = 1, .reusable = false}}, SHIFT(205),
  [386] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 4, 0, 0),
  [388] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__style_start_tag_name, 1, 0, 0),
  [390] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 3, 0, 0),
  [392] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [396] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__script_start_tag_name, 1, 0, 0),
  [398] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 4, 0, 0),
  [400] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [402] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [404] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_templating_decl_if, 2, 0, 1),
  [406] = {.entry = {.count = 1, .reusable = false}}, SHIFT(167),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [416] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [422] = {.entry = {.count = 1, .reusable = false}}, SHIFT(171),
  [424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [434] = {.entry = {.count = 1, .reusable = false}}, SHIFT(207),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [438] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_templating_decl_for, 5, 0, 1),
  [440] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_templating_decl_for, 4, 0, 1),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [446] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_templating_repeat_elseif, 2, 0, 0),
  [448] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [456] = {.entry = {.count = 1, .reusable = false}}, SHIFT(174),
  [458] = {.entry = {.count = 1, .reusable = false}}, SHIFT(159),
  [460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [462] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_templating_repeat_else, 1, 0, 0),
  [464] = {.entry = {.count = 1, .reusable = false}}, SHIFT(164),
  [466] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_templating_repeat_decl, 1, 0, 0),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [470] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_conditional, 1, 0, 0),
  [472] = {.entry = {.count = 1, .reusable = false}}, SHIFT(178),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [478] = {.entry = {.count = 1, .reusable = false}}, SHIFT(212),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [482] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__end_tag_name, 1, 0, 0),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [486] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_templating_decl, 1, 0, 0),
  [488] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [490] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [492] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [494] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [496] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [500] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [502] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [504] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [506] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [508] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 3, 0, 0),
  [510] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 2, 0, 0),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token_if_clause = 0,
  ts_external_token_sentinel = 1,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_if_clause] = sym_if_clause,
  [ts_external_token_sentinel] = sym_sentinel,
};

static const bool ts_external_scanner_states[3][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_if_clause] = true,
    [ts_external_token_sentinel] = true,
  },
  [2] = {
    [ts_external_token_if_clause] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_nml_external_scanner_create(void);
void tree_sitter_nml_external_scanner_destroy(void *);
bool tree_sitter_nml_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_nml_external_scanner_serialize(void *, char *);
void tree_sitter_nml_external_scanner_deserialize(void *, const char *, unsigned);

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
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_nml_external_scanner_create,
      tree_sitter_nml_external_scanner_destroy,
      tree_sitter_nml_external_scanner_scan,
      tree_sitter_nml_external_scanner_serialize,
      tree_sitter_nml_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
