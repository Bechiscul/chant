#pragma once

#include "tokenizer.h"

typedef struct Parser Parser;

typedef struct ParseError {
	const char* msg;
    const char* filename;
    size_t line, col;
} ParseError;

typedef struct ParseResult {
	Parser* parser;
	ParseError error;
} ParseResult;

ParseResult parse_success(Parser* parser);
ParseResult parse_error(ParseError error);