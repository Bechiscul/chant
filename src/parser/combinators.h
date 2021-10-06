#pragma once

#include "tokenizer.h"

// Forward declarations from parser.h
typedef struct Parser Parser;
typedef struct ParserError ParserError;

Parser* next(Parser* parser, ParserError* error);
Parser* expect(Parser* parser, ParserError* error, TokenType type);

#define tk_symbol(parser, error) expect(parser, error, TK_SYMBOL)
#define tk_keyword(parser, error) expect(parser, error, TK_KEYWORD)
#define tk_number(parser, error) expect(parser, error, TK_NUMBER)
#define tk_string(parser, error) expect(parser, error, TK_STRING)
#define tk_equal(parser, error) expect(parser, error, TK_EQUAL)
#define tk_colon(parser, error) expect(parser, error, TK_COLON)
#define tk_semicolon(parser, error) expect(parser, error, TK_SEMICOLON)
#define tk_plus(parser, error) expect(parser, error, TK_PLUS)
#define tk_minus(parser, error) expect(parser, error, TK_MINUS)
#define tk_asterisk(parser, error) expect(parser, error, TK_ASTERISK)
#define tk_slash(parser, error) expect(parser, error, TK_SLASH)
#define tk_percent(parser, error) expect(parser, error, TK_PERCENT)
#define tk_caret(parser, error) expect(parser, error, TK_CARET)
#define tk_lparen(parser, error) expect(parser, error, TK_LPAREN)
#define tk_rparen(parser, error) expect(parser, error, TK_RPAREN)
#define tk_lbrace(parser, error) expect(parser, error, TK_LBRACE)
#define tk_rbrace(parser, error) expect(parser, error, TK_RBRACE)
#define tk_qs(parser, error) expect(parser, error, TK_QS)
#define tk_and(parser, error) expect(parser, error, TK_AND)
#define tk_great(parser, error) expect(parser, error, TK_GREAT)
#define tk_less(parser, error) expect(parser, error, TK_LESS)