#include <stdio.h>

void odd_or_even(int number)
{
  if (number % 2 == 0) {
    printf("%d is even\n", number);
  } else {
    printf("%d is odd\n", number);
  }
}

int main()
{

  int number;

  printf("Give me a four digit number: ");
  scanf("%d", &number);

  int fourth = number % 10;
  int third = (number / 10) % 10;
  int second = (number / 100) % 10;
  int first = number / 1000;

  odd_or_even(number);
  odd_or_even(first);
  odd_or_even(second);
  odd_or_even(third);
  odd_or_even(fourth);

  return 0;
}
