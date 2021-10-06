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

  // The amount of different valid tokens. NOTE Doesn't include TK_UNKNOWN.
  MAX_TOKEN
} TokenType;

//"fn_call(x, y)" => ["fn_call", "(", "x", ",", "y", ")"]
typedef struct Token {
  TokenType type;
  char *string;
} Token;

size_t scan_tokens(const char *source, Token *buffer, size_t buffer_size);
