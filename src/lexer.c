#include "include/lexer.h"
#include "include/token.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*
 * Lexer works the following way:
 *
 * lexer goes through program with lexer_run
 * lexer_run calls lexer_next_token until EOF
 *
 * lexer_next_token checks for type of character and then calls the
 * corresponding functions
 *
 * if character is alpha: lexer_parse_identifier
 *   check if identifier is a keyword
 *
 * if character is numeric:
 */

token_T lexer_parse_identifier(lexer_T *lexer) {

  // identifier start with 16chars and doubles when exceeding 16
  int identifier_size = 16;
  int index = 0;
  char *identifier = (char *)calloc(identifier_size, sizeof(char));
  char *current_identifier = identifier;

  while (isalpha(*lexer->src)) {

    if (index == identifier_size) {
      identifier = (char *)realloc(identifier, identifier_size * 2);
      identifier_size *= 2;
      current_identifier = identifier + index;
    }

    *current_identifier = *lexer->src;

    current_identifier++;
    lexer->src++;
    index++;
  }

  token_T token;
  token.type = TOKEN_IDENTIFIER;
  token.value = identifier;
  return token;
}

token_T lexer_check_for_keywords(token_T token) {
  printf(" test: %s ", token.value);
  if (strcmp(token.value, "int")) {
    token.type = TOKEN_INT;
    free(token.value);
    token.value = NULL;

    return token;
  }
  return token;
}

token_T lexer_next_token(lexer_T *lexer) {

  // skip whitespace
  while (*lexer->src == 13 || *lexer->src == 10 || *lexer->src == ' ' ||
         *lexer->src == '\t') {
    lexer->src++;
  }

  // EOF
  if (*lexer->src == '\0') {
    token_T token;
    token.value = NULL;
    token.type = TOKEN_EOF;

    return token;
    // identifiers and keywords
  } else if (strcmp(lexer->src, "=")) {
    token_T token;
    token.type = TOKEN_EQUALS;
    token.value = NULL;

    lexer->src++;

    return token;
  } else if (strcmp(lexer->src, ";")) {
    token_T token;
    token.type = TOKEN_EQUALS;
    token.type = TOKEN_SEMICOLON;
    token.value = NULL;

    lexer->src++;

    return token;
  } else if (isalpha(*lexer->src)) {
    token_T token = lexer_parse_identifier(lexer);

    token = lexer_check_for_keywords(token);

    return token;
  }
  // numbers

  token_T token;
  token.type = TOKEN_INVALID;
  token.value = NULL;

  return token;
}

token_T *lexer_run(char *src) {
  lexer_T lexer;
  lexer.src = src;

  int tokens_size = 120;
  int tokens_index = 0;
  token_T *tokens = (token_T *)calloc(tokens_size, sizeof(token_T));
  token_T *current_token = tokens;

  while (current_token->type != TOKEN_EOF) {
    // check if tokens size is big enough -> if not realloc
    if (tokens_index == tokens_size) {
      tokens = (token_T *)realloc(tokens, tokens_size * 2);
      tokens_size *= 2;
      current_token = tokens + tokens_index;
    }

    *current_token = lexer_next_token(&lexer);
    token_print(current_token);
    tokens_index++;
  }

  return tokens;
}
