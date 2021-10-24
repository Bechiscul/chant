#pragma once
#include <stddef.h>
#include <stdint.h>
#include <string.h>

/// The type of the token.
typedef enum TokenType {
  TK_UNKNOWN = -1,    //< Unkown token.
  TK_SYMBOL = 128,    //< A symbol.
  TK_NUMBER = 129,    //< A number. Eg. 123 or 1.2351
  TK_STRING = 130,    //< A string. Eg. "hello world"
  TK_EQUAL = '=',     //< =
  TK_COLON = ':',     //< :
  TK_SEMICOLON = ';', //< ;
  TK_PLUS = '+',      //< +
  TK_MINUS = '-',     //< -
  TK_ASTERISK = '*',  //< *
  TK_SLASH = '/',     //< /
  TK_PERCENT = '%',   //< %
  TK_CARET = '^',     //< ^
  TK_LPAREN = '(',    //< (
  TK_RPAREN = ')',    //< )
  TK_LBRACE = '{',    //< {
  TK_RBRACE = '}',    //< }
  TK_LSQBRACE = '[',  //< [
  TK_RSQBRACE = ']',  //< ]
  TK_EP = '!',        //< !
  TK_AND = '&',       //< &
  TK_GREAT = '>',     //< >
  TK_LESS = '<',      //< <
  TK_DOT = '.',       //< .
  TK_COMMA = ',',     //< ,

  // The amount of different valid tokens. NOTE Doesn't include TK_UNKNOWN.
  MAX_TOKEN
} TokenType;

//"fn_call(x, y)" => ["fn_call", "(", "x", ",", "y", ")"]
typedef struct Token {
  TokenType type;
  char *string;
} Token;

const Token OP_PLUS = {TK_PLUS, "+"};
const Token OP_MINUS = {TK_MINUS, "-"};
const Token OP_ASTERISK = {TK_ASTERISK, "*"};
const Token OP_SLASH = {TK_SLASH, "/"};
const Token OP_PERCENT = {TK_PERCENT, "%"};
const Token OP_CARET = {TK_CARET, "^"};
const Token OP_LPAREN = {TK_LPAREN, "("};
const Token OP_RPAREN = {TK_RPAREN, ")"};
const Token OP_LBRACE = {TK_LBRACE, "{"};
const Token OP_RBRACE = {TK_RBRACE, "}"};
const Token OP_LSQBRACE = {TK_LPAREN, "["};
const Token OP_RSQBRACE = {TK_LPAREN, "]"};
const Token OP_EP = {TK_EP, "!"};
const Token OP_AND = {TK_AND, "&"};
const Token OP_GREAT = {TK_GREAT, ">"};
const Token OP_LESS = {TK_LESS, "<"};
const Token OP_EQUAL = {TK_EQUAL, "="};
const Token OP_COLON = {TK_COLON, ":"};
const Token OP_SEMICOLON = {TK_SEMICOLON, ";"};
const Token OP_COMMA = {TK_COMMA, ","};
const Token OP_DOT = {TK_DOT, "."};

size_t scan_tokens(const char *source, Token *buffer, size_t buffer_size);
