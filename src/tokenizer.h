#pragma once
#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef enum TokenType {
  TK_UNKNOWN = -1,
  TK_SYMBOL,
  TK_NUMBER,
  TK_STRING,
  TK_ASSIGN,
  TK_COLON,
  TK_SEMICOLON,
  TK_ADD,
  TK_SUB,
  TK_ASTERISK,
  TK_SLASH,
  TK_MODOLUS,
  TK_POW,
  TK_LPAREN,
  TK_RPAREN,
  TK_ADD_ASSIGN,
  TK_SUB_ASSIGN,
  TK_MUL_ASSIGN,
  TK_DIV_ASSIGN,
  TK_MOD_ASSIGN,
  TK_BIT_XOR,
  TK_BIT_XOR_ASSIGN,
  TK_LBIT_SHIFT,
  TK_RBIT_SHIFT,
  TK_BIT_OR_ASSIGN,
  TK_LBIT_SHIFT_ASSIGN,
  TK_RBIT_SHIFT_ASSIGN,
  TK_NOT,
  TK_EQ,
  TK_NOT_EQ,
  TK_AND,
  TK_OR,
  TK_ARROW,
  TK_GREATER,
  TK_LESSER,
  TK_GREATER_EQ,
  TK_LESSER_EQ,

  MAX_TOKENS,
} TokenType;

//"fn_call(x, y)" => ["fn_call", "(", "x", ",", "y", ")"]

typedef struct Token {
  TokenType type;
  char *string;
} Token;

size_t scanTokens(const char *source, Token *buffer, size_t buffer_size);
