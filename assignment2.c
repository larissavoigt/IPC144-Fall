#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int validate(int low, int high) {
  int input;

  printf("Enter a value (between %d and %d): ", low, high);
  scanf("%d", &input);

  if (input < low || input > high) {
    printf("***Error! You entered '%d'... Value must be between %d and %d inclusive!***\n", input, low, high);
    validate(low, high);
  } else {
    printf("Thank You!\n");
    return input;
  }
}

int genRand(int limit) {
  return rand() % limit;
}

int validatePick(int pick, int first, int second, int third, int fourth, int fifth, int sixth, int seventh) {
  if (pick == first || pick == second || pick == third || pick == fourth ||
      pick == fifth || pick == sixth || pick == seventh) {
    return 0;
  } else {
    return 1;
  }
}

void pickRandomly(int largest, int qty, int choices[]) {
  int index = 0;

  while (qty > 0) {
    int n = genRand(largest);
    int valid = validatePick(n, choices[0], choices[1], choices[2], choices[3],
                choices[4], choices[5], choices[6]);
    if (valid) {
      choices[index] = n;
      ++index;
      --qty;
    }
  }

}

void printNums(int n, int first, int second, int third, int fourth, int fifth, int sixth, int seventh) {
  printf("\nYour RANDOM lottery numbers are: ");
  switch (n) {
    case 1:
      printf("%d", first);
      break;
    case 2:
      printf("%d, %d", first, second);
      break;
    case 3:
      printf("%d, %d, %d", first, second, third);
      break;
    case 4:
      printf("%d, %d, %d, %d", first, second, third, fourth);
      break;
    case 5:
      printf("%d, %d, %d, %d, %d", first, second, third, fourth, fifth);
      break;
    case 6:
      printf("%d, %d, %d, %d, %d, %d", first, second, third, fourth, fifth, sixth);
      break;
    case 7:
      printf("%d, %d, %d, %d, %d, %d, %d", first, second, third, fourth, fifth, sixth, seventh);
      break;
  }
  printf("\n\n");
}

double fac(int n) {
  int i;
  double total = 1;
  for (i = 1; i <= n; i++) {
    total *= i;
  }
  return total;
}

double calcOdds(int n, int k) {
  return fac(n) / (fac(n-k) * fac(k));
}

void showOdds(int n, int k) {
  double odds = calcOdds(n, k);
  double perc = 1 / odds;
  printf("The odds of winning a lottery where %d numbers are chosen\n", k);
  printf("from a set of %d numbers is 1 in %lf!!!\n", n, odds);
  printf("Representing a ratio of: %lf\n", perc);
  printf("Are you sure you still want to PLAY?\n");
  printf("GOOD LUCK!!!\n");
}

int main () {
  int choices[7];

  srand(time(NULL));

  printf("LOTTERY GENERATOR\n");

  printf("Enter the largest number in your LOTTERY:\n");
  int largest = validate(39, 59);
  int qty = validate(3, 7);

  pickRandomly(largest, qty, choices);
  printNums(qty, choices[0], choices[1], choices[2], choices[3], choices[4],
            choices[5], choices[6]);
  showOdds(largest, qty);

  return 0;
}
