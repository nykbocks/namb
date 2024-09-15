#ifndef _LEXER_H
#define _LEXER_H
#include "File.h"
extern int lex_i;

typedef enum Token_Type{
  EXIT_T,
  INT_T,
  SEMI_T,
}Token_Type_t;
typedef struct Token{
    Token_Type_t token_type;
    int token_value;
} Token_t;
void lex_add_token(Token_t new_token);
extern Token_t LEXER_TOKENS[CAPACITY*8];
#endif 
