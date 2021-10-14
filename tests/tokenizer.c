#include <stdlib.h>
#include <string.h>

#include "../src/tokenizer.c"

int main() {
  if (scan_tokens("foo + bar", NULL, 0) != 3) { // This test is passing.
    return 1;
  }

  Token buffer[3];
  scan_tokens("foo + bar", buffer, 3);

  if (strcmp(buffer[0].string, "foo") == 0 && buffer[0].type == TK_SYMBOL) {
    // FIXME: This test segfaults.
    return 1;
  }
}
