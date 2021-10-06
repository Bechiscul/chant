#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "error.h"
#include "tokenizer.h"

typedef struct Parser Parser;

Parser* create_parser(Token* tokens, size_t size);
void destroy_parser(Parser* parser);
