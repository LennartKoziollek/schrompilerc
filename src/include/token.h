#ifndef TOKEN_H
#define TOKEN_H
typedef struct TOKEN {
  char* value;
  enum {
    TOKEN_IDENTIFIER,
    TOKEN_INT,
    TOKEN_EQUALS,
    TOKEN_NUMBER,
    TOKEN_SEMICOLON,
    TOKEN_INVALID,
    TOKEN_EOF,
  } type;
} token_T;

void token_print(token_T *token);
#endif // !TOKEN_H
