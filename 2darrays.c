#include <stdio.h>

int main() {
  int a[3] = {1,5,8};
  a[0]; // 1
  a[1]; // 5
  a[2]; // 8

  int b[2][3] = {{1,2,3},{5,6,7}};

  int i, j;

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      b[i][j] += a[j];
      printf("%d\n", b[i][j]);
    }
  }
}
