#include <stdio.h>

int main () {

  int n = 0;
  int s = 0;
  int c = 0;
  int t = 0;

  printf("n s c t\n");

  while (n < 10) {
    printf("%d %d %d %d\n", n, s, c, t);
    n = n + 1;
    s = n * n; /* square */
    c = n * n * n; /* cube */
    t = n + s + c; /* sum of number, square and cube */
  }

  printf("%d %d %d %d\n", n, s, c, t);

  return 0;

}
