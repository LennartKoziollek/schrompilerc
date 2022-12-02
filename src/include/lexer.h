#ifndef LEXER_H
#define LEXER_H
#include "token.h"
#include <stdio.h>

typedef struct LEXER {
  char* src;
} lexer_T;


// Complicated parsers

token_T lexer_parse_identifier(lexer_T *lexer);

token_T lexer_check_for_keywords(token_T token);

token_T lexer_parse_number(lexer_T *lexer);


// Running the lexer
token_T lexer_next_token(lexer_T *lexer);

token_T* lexer_run(char* src);

#endif // !LEXER_H
