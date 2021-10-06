#include <stdlib.h>
#include <assert.h>

#include "parser.h"
#include "_parser.h"

Parser* create_parser(Token* tokens, size_t size) {
	Parser* parser = (Parser*)malloc(sizeof(Parser));
	parser->tokens = (Parser*)memcpy(malloc(sizeof(Token) * size), tokens, size);
	parser->size = size;
	parser->index = 0;
}

void destroy_parser(Parser* parser) {
	assert(parser != NULL);

	if (parser->tokens != NULL) {
		free(parser->tokens);
	}

	free(parser);
}