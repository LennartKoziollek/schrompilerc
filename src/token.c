#include "include/token.h"
#include <stdio.h>

void token_print(token_T *token) {

  switch (token->type) {

  case TOKEN_IDENTIFIER:
    printf("Identifier %s ", token->value);
    break;
  case TOKEN_INT:
    printf("INT ");
    break;
  case TOKEN_EQUALS:
    printf("EQUALS ");
    break;
  case TOKEN_NUMBER:
    printf("NUMBER %s ", token->value);
    break;
  case TOKEN_SEMICOLON:
    printf("SEMICOLON ");
    break;
  case TOKEN_INVALID:
    printf("INVALID ");
    break;
  case TOKEN_EOF:
    printf("EOF ");
    break;
  }
}
