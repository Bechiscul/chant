#include <stdbool.h>

#include "tokenizer.h"

bool str_contains(const char *source, char c) {
  for (int n = 0; n < strlen(source); n++) {
    if (source[n] == c) {
      return true;
    }
  }
  return false;
}

const char *SPLIT_AT = "()[],{}.!*=-+/%^&>|<;:";

size_t scanTokens(const char *source, Token *buffer, size_t buffer_size) {
  size_t tokens = 0;
  for (int n = 0; n < strlen(source); n++) {
  }
  return tokens;
}
