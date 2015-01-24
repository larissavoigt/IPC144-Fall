#include <stdio.h>

int main() {
  int a[3];
  a[0] = 1;
  a[1] = 2;
  a[2] = 3;

  int b[] = {1,2,3};
  int c[3];

  int i;

  for(i = 0; i < 3; i++) {
    c[i] = a[i] * b[i];
    printf("%d\n", c[i]);
  }

  return 0;
}
