#include <stdbool.h>

#include "tokenizer.h"

const char *SPLIT_AT = "()[],{}.!*=-+/%^&>|<;: ";
const char *SINGLETS = "()[],{}.!*=-+/%^&>|<;:";

size_t count_tokens(const char *source) {
  size_t tokens = 0;
  for (int n = 0; n < strlen(source); n++) {
    if (strchr(SPLIT_AT, source[n]))
      tokens++;
  }
  return tokens;
}

Token string_to_token(const char *source) {
  Token token;
  token.type = TK_UNKNOWN;

  if (strchr(SINGLETS, source[0])) {
    token.type = source[0];
  }

  if (source[0] == '"' && source[strlen(source)] == '"') {
    token.type = TK_STRING;
    // Bellow token.string is uninitialized. Does this mean it will crash?
    strncpy(token.string, source + 1, strlen(source) - 1);
  }

  return token;
}

/// Source string should never contain new lines,
/// tabs or more than one consecutive spaces.
size_t scan_tokens(const char *source, Token *buffer, size_t buffer_size) {
  if (buffer == NULL)
    return count_tokens(source);

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
