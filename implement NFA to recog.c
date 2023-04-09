#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN_LEN 100
#define MAX_STATES 10
#define NUM_TOKENS 3

enum TokenType { IDENTIFIER, CONSTANT, OPERATOR };

char token[MAX_TOKEN_LEN + 1];
int tokenLen;

enum TokenType getToken(void) {
  int state = 0;
  tokenLen = 0;
  char c;

  while (state != -1) {
    c = getchar();

    int nextState = -1;
    if (isalnum(c))
      nextState = (state == 0) ? 1 : 2;
    else if (c == '+' || c == '-' || c == '*' || c == '/')
      nextState = 3;

    if (nextState != -1) {
      if (tokenLen < MAX_TOKEN_LEN)
        token[tokenLen++] = c;
      state = nextState;
    } else
      state = -1;
  }

  token[tokenLen] = '\0';

  if (tokenLen == 1 && strchr("+-*/", token[0]) != NULL)
    return OPERATOR;
  if (tokenLen > 0 && isdigit(token[0]))
    return CONSTANT;
  return IDENTIFIER;
}

int main(void) {
  enum TokenType t;
  while ((t = getToken()) != -1) {
    switch (t) {
      case IDENTIFIER:
        printf("Identifier: %s\n", token);
        break;
      case CONSTANT:
        printf("Constant: %s\n", token);
        break;
      case OPERATOR:
        printf("Operator: %s\n", token);
        break;
    }
  }

  return 0;
}
