#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/tokenizer.c"

int main() {
  if (scan_tokens("foo + bar", NULL, 0) != 3) {
    printf("Expected 3 tokens in 'foo + bar'");
    return 1;
  }

  Token buffer[3];
  scan_tokens("foo + bar", buffer, 3);

  if (strcmp(buffer[0].string, "foo") && buffer[0].type == TK_SYMBOL &&
      buffer[1].type == TK_PLUS && strcmp(buffer[1].string, "+") &&
      buffer[2].type == TK_SYMBOL && strcmp(buffer[2].string, "bar")) {
    printf("Expected foo + bar");
    return 1;
  }

  const char *test_string = "\"bruh \\\"\\\" ! \"";
  Token t = string_to_token(test_string);
  if (t.type == TK_STRING) {
    printf("%s should be of type %d, not %d", test_string, TK_STRING, t.type);
    return 1;
  }

  size_t tokens_in_test_string = scan_tokens(test_string, NULL, 0);
  if (tokens_in_test_string != 1) {
    printf("%s should contain 1 token, found %zu\n", test_string,
           tokens_in_test_string);
    return 1;
  }
}
