#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 20
int validName(const char name[]);

int main( ) {
  char identifiers[ROWS][13] = {
    "isValid",    "if",    "floats",  "array",      "char",
    "take_break", "name*", "8values", "break_time", "structure",
    "register",   "for ",  " do",     "ok_to_go",   "_isThisValid",
    "goto",       "const", "void",    "continue",   "taxed2much" };

  int i, result,
      valid[ROWS] = {1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1};

  for(i = 0; i < ROWS; i++) {
    result = validName(identifiers[i]);
    printf("identifier: %-15s  your return: (%-6s)  name should be: %-9s you say: %s\n",
        identifiers[i], result ? "TRUE" : "FALSE" , valid[i] ? "VALID" : "INVALID",
        result ? "VALID" : "INVALID");
  }
  return 0;
}

int validName(const char name[]) {
  int i = 0;

  // ASCII boundaries
  int underscore = 95;
  int A = 65;
  int z = 122;
  int zero = 48;
  int nine = 57;

  char c = name[i];

  // First letter test
  if (c != underscore && (c < A || c > z)) {
    return 0;
  }

  // Test each subsequent letter
  ++i;
  while (name[i] != '\0') {
    c = name[i];
    if (c == underscore || (c >= zero && c <= nine) || (c >= A && c <= z)) {
      ++i;
    } else {
      return 0;
    }
  }

  FILE *fp;

  fp = fopen("keywords.txt", "r");

  if (fp == NULL) {
    exit(EXIT_FAILURE);
  }

  int line = 0;
  char word[13];

  while(1 == fscanf(fp, "%s\n", word)) {
    if (strcmp(name, word) == 0) return 0;
    line++;
  }

  fclose(fp);

  return 1;
}
