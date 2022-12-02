#include "include/io.h"
#include "include/lexer.h"
#include "include/token.h"

int main(int argc, char *argv[]) {

  if (argc == 2) {
    char *src = read_file(argv[1]);

    // run the lexer
    token_T *tokens = lexer_run(src);
    // token_print(tokens);
  } else {
    printf("Invalid options");
    return 1;
  }

}
