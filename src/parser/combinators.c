#include "combinators.h"
#include "_parser.h"

Parser* next(Parser* parser, ParserError* error) {
	if (parser->next == NULL) {
		error = unexpected_end_of_input();
		return NULL;
	}

	return parser;
}

Parser* expect(Parser* parser, ParserError* error, TokenType type) {
	if (token_neq(parser->next, type)) {
		*error = expected_token(type);
		return NULL;
	}

	return parser;
}