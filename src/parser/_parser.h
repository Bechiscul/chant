#pragma once

#include "parser.h"

typedef struct Parser {
	Token* tokens;
	Token* next;
	size_t size;
	size_t index;
} Parser;