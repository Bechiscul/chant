#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/tokenizer.c"

void assert_tokens(Token *a, char *b, size_t a_len) {
  size_t buffer_len = scan_tokens(b, NULL, 0);
  Token buffer[buffer_len];
  scan_tokens(b, buffer, buffer_len);
  for (int n = 0; n < buffer_len; n++)
    if (strcmp(a[n].string, buffer[n].string) || a[n].type != buffer[n].type) {
      printf("Assertion failed!\nAt       : \"%s\"\nExpected : ", b);
      print_tokens(a, a_len);
      printf("Found    : ");
      print_tokens(buffer, buffer_len);
      exit(1);
    }
}

int main() {
  // Symbols and Operators
  {
    Token expect[3] = {{TK_SYMBOL, "foo"}, OP_PLUS, {TK_SYMBOL, "bar"}};
    assert_tokens(expect, "foo + bar", 3);
    assert_tokens(expect, "foo+bar", 3);
  }

  // Strings
  {
    Token expect[1] = {{TK_STRING, "bruh \\\"\\\" ! "}};
    assert_tokens(expect, "\"bruh \\\"\\\" ! \"", 1);
  }

  {
    Token expect[3] = {
        {TK_STRING, "bruh dah"}, OP_PLUS, {TK_STRING, "foo bar"}};
    assert_tokens(expect, "\"bruh dah\" + \"foo bar\"", 3);
    assert_tokens(expect, "\"bruh dah\"+\"foo bar\"", 3);
  }

  {
    Token expect[1] = {{TK_NUMBER, "123.456"}};
    assert_tokens(expect, "123.456", 1);
  }

  {
    Token expect[3] = {{TK_NUMBER, "123.456"}, OP_PLUS, {TK_STRING, "foo bar"}};
    assert_tokens(expect, "123.456+ \"foo bar\"", 3);
    assert_tokens(expect, "123.456 +\"foo bar\"", 3);
  }

  {
    Token expect[5] = {{TK_NUMBER, "123.456"},
                       OP_PLUS,
                       {TK_STRING, "foo bar"},
                       OP_PLUS,
                       {TK_SYMBOL, "baz"}};
    assert_tokens(expect, "123.456+\"foo bar\" + baz", 5);
  }
}
