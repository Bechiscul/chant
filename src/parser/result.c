#include "result.h"

ParseResult parse_success(Parser* parser) {
	ParseResult result = { parser, NULL };
	return result;
}

ParseResult parse_error(ParseError error) {
	ParseResult result = { NULL, error };
	return result;
}