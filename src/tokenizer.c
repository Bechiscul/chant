#include <stdbool.h>
#include <stdlib.h>

#include "tokenizer.h"

const char *SPLIT_AT = "()[],{}.!*=-+/%^&>|<;: "; // Props don't need this
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
    token.string = (char *)malloc(strlen(source) - 1);
    strncpy(token.string, source + 1, strlen(source) - 1);
  }

  token.type = TK_SYMBOL;
  strcpy(token.string, source); // NOTE: Not needed if symbols is invalid.

  for (int n = 0; n < strlen(source); n++) {
    if (source[n] < 48 || (n == 0 && (source[n] < 58)) ||
        (source[n] > 57 && source[n] < 65) ||
        (source[n] > 90 && source[n] < 97) || source[n] > 122) {
      token.type = TK_UNKNOWN;
    }
  }

  return token;
}

/// Source string should never contain new lines,
/// tabs or more than one consecutive spaces.
size_t scan_tokens(const char *source, Token *dest, size_t buffer_size) {
  if (dest == NULL)
    return count_tokens(source);

  // char *last_token = source[0..3];

  size_t tokens = 0;
  size_t token_start = 0;
  size_t token_len = 0;
  bool is_string = false;

  for (int n = 0; n < strlen(source); n++) {

    if (strchr(SINGLETS, source[n])) { // TODO: Does not split at spaces, and
                                       // needs special case to handle strings
      // use stringToToken and strncpy(result, str + start, end - start);
      char *buffer = (char *)malloc(token_len);
      strncpy(buffer, source + token_start, token_len);
      dest[tokens] = string_to_token(buffer);

      tokens++;
      token_start = n + 1;
      token_len = 0;
    }
    token_len++;
  }
  return tokens;
}
