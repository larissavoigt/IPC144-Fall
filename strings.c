#include <stdio.h>

int main() {
  char name[] = "larissa";
  char first[8] = {'l','a','r','i','s','s','a','\0'};

  int i;

  for(i = 0; i < 8; i++) {
    printf("%c", first[i]);
  }
  printf("\n");
}
