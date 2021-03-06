#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "tokenizer.h"
const char *SPLIT_AT = "()[],{}.!*=-+/%^&>|<;: "; // Props don't both of these
const char *SINGLETS = "()[],{}.!*=-+/%^&>|<;:";

void print_token(Token token) {
  if (token.type == TK_UNKNOWN && !strcmp(token.string, "")) {
    printf("_");
  } else {
    printf("\"%s\" : %d", token.string, token.type);
  }
}

void print_tokens(Token *tokens, size_t token_count) {
  printf("Token[ ");
  for (int n = 0; n < token_count - 1; n++) {
    print_token(tokens[n]);
    printf(", ");
  }
  print_token(tokens[token_count - 1]);
  printf(" ]\n");
}

Token string_to_token(const char *source) {
  Token token;
  token.type = TK_UNKNOWN;

  // Is the token an operator?
  if (strchr(SINGLETS, source[0])) {
    token.type = source[0];
    token.string = (char *)malloc(2);
    memset(token.string, 0, 2);
    token.string[0] = source[0];
    return token;
  }

  // Is the token a string?
  if (source[0] == '"') {
    token.type = TK_STRING;
    token.string = (char *)malloc(strlen(source) - 1);
    memset(token.string, 0, strlen(source) - 1);
    strncpy(token.string, source + 1, strlen(source) - 1);
    return token;
  }

  // Is number?
  if (source[0] > 47 && source[0] < 58) {
    token.type = TK_NUMBER;
    token.string = (char *)malloc(strlen(source));
    strcpy(token.string, source);

    return token;
  }

  // Check if token is a valid symbol
  for (int n = 0; n < strlen(source); n++) {
    if (source[n] < 48 || (n == 0 && (source[n] < 58)) ||
        (source[n] > 57 && source[n] < 65) ||
        (source[n] > 90 && source[n] < 97) || source[n] > 122) {
      token.type = TK_UNKNOWN;
      return token;
    }
  }

  token.type = TK_SYMBOL;
  token.string = (char *)malloc(strlen(source));
  strcpy(token.string, source);

  return token;
}

/// Source string should never contain new lines,
/// tabs or more than one consecutive spaces (might actually work fine).
size_t scan_tokens(const char *source, Token *dest, size_t buffer_size) {
  size_t tokens = 0;
  size_t token_start = 0;
  size_t token_len = 0;
  bool is_string = false;
  bool is_num = true;

  for (int n = 0; n < strlen(source); n++) {
    if (token_len == 1 && source[n] == ' ') { // Skip unnecessary spaces.
      token_start++;
      continue;
    }

    is_num = is_num && ((source[n] > 47 && source[n] < 58) || source[n] == '.');
    bool new_token = strchr(SPLIT_AT, source[n]) && !is_string;

    if (source[n] == '\"') {
      if (!is_string) {
        is_string = true;
        new_token = false;
      } else if (is_string && source[n] == '"' && source[abs(n - 1)] != '\\') {
        new_token = true;
        is_string = false;
        if (token_start + token_len == n + 1) { // Removes trailing " charecter
          token_len--;
        }
      }
    }

    if (is_num && source[n] == '.')
      new_token = false;

    if (new_token || source[n] == 0) {
      if (dest != NULL && tokens < buffer_size) {
        char *buffer = (char *)malloc(token_len + 1);
        memset(buffer, 0, token_len + 1);
        strncpy(buffer, source + token_start, token_len);
        dest[tokens] = string_to_token(buffer);
      }

      // Catch cases where singlet is not separated by space.
      // E.g. function(symbol)
      //              ^
      if (strchr(SINGLETS, source[n]) && token_len > 1) {
        tokens++;
        if (tokens < buffer_size && dest != NULL) {
          Token token;

          token.type = source[n];

          token.string = (char *)malloc(2);
          memset(token.string, 0, 2);
          token.string[0] = source[n];

          dest[tokens] = token;
        }
      }

      tokens++;
      token_start = n + 1;
      token_len = 0;
    }
    token_len++;
  }
  return tokens;
}
