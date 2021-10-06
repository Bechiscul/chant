#include <stdbool.h>

#include "tokenizer.h"

const char *SPLIT_AT = "()[],{}.!*=-+/%^&>|<;: ";

size_t countTokens(const char *source) {
  size_t tokens = 0;
  for (int n = 0; n < strlen(source); n++) {
    if (strchr(SPLIT_AT, source[n]))
      tokens++;
  }
  return tokens;
}

Token stringToToken(const char *source) {
  Token token;
  token.type = TK_UNKNOWN;
  switch (source[0]) {

  case '(':
    token.type = TK_LPAREN;
    break;

  case ')':
    token.type = TK_RPAREN;
    break;

  case '{':
    token.type = TK_LBRACE;
    break;
  }

  return token;
}

/// Source string should never contain new lines,
/// tabs or more than one consecutive spaces.
size_t scanTokens(const char *source, Token *buffer, size_t buffer_size) {
  if (buffer == NULL)
    return countTokens(source);

  // char *last_token = source[0..3];

  size_t tokens = 0;
  size_t token_start = 0;
  size_t token_len = 0;

  for (int n = 0; n < strlen(source); n++) {

    if (strchr(SPLIT_AT, source[n])) {
      // use stringToToken and strncpy(result, str + start, end - start);

      tokens++;
      token_start = n + 1;
      token_len = 0;
    }
    token_len++;
  }
  return tokens;
}
