#include <stdio.h>
#include <tree_sitter/parser.h>
#include <wctype.h>

enum TokenType {
  // BLOCK_COMMENT_START,
  // BLOCK_COMMENT_CONTENT,
  // BLOCK_COMMENT_END,
  //
  // STRING_START,
  // STRING_CONTENT,
  // STRING_END,

  IF_CLAUSE,
  SENTINEL,
};

static inline void consume(TSLexer *lexer) { lexer->advance(lexer, false); }
static inline void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

static inline bool consume_char(char c, TSLexer *lexer) {
  if (lexer->lookahead != c) {
    return false;
  }

  consume(lexer);
  return true;
}

static inline uint8_t consume_and_count_char(char c, TSLexer *lexer) {
  uint8_t count = 0;
  while (lexer->lookahead == c) {
    ++count;
    consume(lexer);
  }
  return count;
}

static inline void skip_whitespaces(TSLexer *lexer) {
  while (iswspace(lexer->lookahead)) {
    skip(lexer);
  }
}

void *tree_sitter_nml_external_scanner_create() { return NULL; }
void tree_sitter_nml_external_scanner_destroy(void *payload) {}

char ending_char = 0;
uint8_t level_count = 0;

static inline void reset_state() {
  ending_char = 0;
  level_count = 0;
}

unsigned tree_sitter_nml_external_scanner_serialize(void *payload,
                                                    char *buffer) {
  buffer[0] = ending_char;
  buffer[1] = level_count;
  return 2;
}

void tree_sitter_nml_external_scanner_deserialize(void *payload,
                                                  const char *buffer,
                                                  unsigned length) {
  if (length == 0)
    return;
  ending_char = buffer[0];
  if (length == 1)
    return;
  level_count = buffer[1];
}

static bool scan_if_clause(TSLexer *lexer) {
  uint32_t currentChar = '\0';
  while (true) {
    if (lexer->eof(lexer)) {
      break;
    }
    if (currentChar != '}' && lexer->lookahead == '}') {
      break;
    }
    currentChar = lexer->lookahead;
    lexer->advance(lexer, false);
  }
  lexer->mark_end(lexer);
  lexer->result_symbol = IF_CLAUSE;

  return true;
}

bool tree_sitter_nml_external_scanner_scan(void *payload, TSLexer *lexer,
                                           const bool *valid_symbols) {
  // if (valid_symbols[STRING_END] && scan_string_end(lexer)) {
  //   reset_state();
  //   lexer->result_symbol = STRING_END;
  //   return true;
  // }
  //
  // if (valid_symbols[STRING_CONTENT] && scan_string_content(lexer)) {
  //   lexer->result_symbol = STRING_CONTENT;
  //   return true;
  // }
  //
  // if (valid_symbols[BLOCK_COMMENT_END] && ending_char == 0 &&
  //     scan_block_end(lexer)) {
  //   reset_state();
  //   lexer->result_symbol = BLOCK_COMMENT_END;
  //   return true;
  // }
  //
  // if (valid_symbols[BLOCK_COMMENT_CONTENT] && scan_comment_content(lexer)) {
  //   return true;
  // }
  //
  // skip_whitespaces(lexer);

  // if (valid_symbols[STRING_START] && scan_string_start(lexer)) {
  //   lexer->result_symbol = STRING_START;
  //   return true;
  // }
  //
  // if (valid_symbols[BLOCK_COMMENT_START]) {
  //   if (scan_comment_start(lexer)) {
  //     return true;
  //   }
  // }
  if (valid_symbols[SENTINEL]) {
    return false;
  }
  if (valid_symbols[IF_CLAUSE] && scan_if_clause(lexer)) {
    return true;
  }

  return false;
}
