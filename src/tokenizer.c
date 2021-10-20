#include <stdbool.h>
#include <stdlib.h>

#include "tokenizer.h"
const char *SPLIT_AT = "()[],{}.!*=-+/%^&>|<;: "; // Props don't need this
const char *SINGLETS = "()[],{}.!*=-+/%^&>|<;:";

Token string_to_token(const char *source) {
  Token token;
  token.type = TK_UNKNOWN;

  if (strchr(SINGLETS, source[0])) {
    token.type = source[0];
  }

  if (source[0] == '"' && source[strlen(source)] == '"') {
    token.type = TK_STRING;
    token.string = (char *)malloc(strlen(source) - 1);
    memset(token.string, 0, strlen(source));
    strncpy(token.string, source + 1, strlen(source) - 1);
    return token;
  }

  token.type = TK_SYMBOL;
  token.string = (char *)malloc(strlen(source));
  strcpy(token.string, source); // NOTE: Not needed if symbols is invalid.

  for (int n = 0; n < strlen(source); n++) {
    if (source[n] < 48 || (n == 0 && (source[n] < 58)) ||
        (source[n] > 57 && source[n] < 65) ||
        (source[n] > 90 && source[n] < 97) || source[n] > 122) {
      // Check if is alpha numerical
      token.type = TK_UNKNOWN;
      return token;
    }
  }

  return token;
}

/// Source string should never contain new lines,
/// tabs or more than one consecutive spaces.
size_t scan_tokens(const char *source, Token *dest, size_t buffer_size) {
  // char *last_token = source[0..3];

  size_t tokens = 0;
  size_t token_start = 0;
  size_t token_len = 0;
  bool is_string = false;

  for (int n = 0; n < strlen(source); n++) {

    bool new_token = strchr(SPLIT_AT, source[n]);
    if (is_string && source[n] == '"' && source[abs(n - 1)] != '\\') {
      new_token = true;
      is_string = false;
    }

    if (new_token) { // TODO: Does not split at spaces, and
                     // needs special case to handle strings
      // use stringToToken and strncpy(result, str + start, end - start);
      if (dest != NULL) {
        char *buffer = (char *)malloc(token_len + 1);
        memset(buffer, 0, token_len + 1);
        strncpy(buffer, source + token_start, token_len);
        dest[tokens] = string_to_token(buffer);
      }

      tokens++;
      token_start = n + 1;
      token_len = 0;
    }
    token_len++;
  }
  return tokens;
}
