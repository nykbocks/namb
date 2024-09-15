#include "../include/Lexer.h"
#include "../include/File.h"
int lex_i = 0;
Token_t LEXER_TOKENS[sizeof(Token_t)*CAPACITY] = {0};
void lex_add_token(Token_t new_token){
  LEXER_TOKENS[lex_i] = new_token; 
  ++lex_i;
};
