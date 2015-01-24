#include <stdio.h>
#define N 16

int xchg (int *, int *);

int main() {
  int nums[] = {7, 1, 993, -5, 0, 16, -451, 12, 89, 28, 77, 384, -2, 38, -17, 201};
  int x = 5;
  int y = 4;
  int i = 0;
  int j = 0;
  int k = 0;
  int acc = 0;

  for (i = 0; i < N - 1; i++) {
    for (j = i + 1; j < N; j++) {
      acc += xchg(&nums[i], &nums[j]);
    }
    for (k = 0; k < N; k++) {
      if (k == 0) printf("%d", nums[k]);
      else printf(" %d", nums[k]);
    }
    printf("\n");
  }

  printf("total exchanges: %d\n", acc);
  return 0;
}

int xchg (int *x, int *y) {
  if (*y < *x) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
    return 1;
  }
  return 0;
}
