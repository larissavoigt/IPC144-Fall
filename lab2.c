#include <stdio.h>

#define ROWS 500

int main (){

  int number_of_rows = 0;
  int spaces_per_line = ROWS - 1;
  int stars_per_line = 1;

  while ( number_of_rows < ROWS ) {
    int current_stars = 0;
    int current_spaces = 0;
    while (current_spaces < spaces_per_line ){
      printf(" ");
      current_spaces++;
    }
    while ( current_stars < stars_per_line ) {
      printf("*");
      current_stars++;
    }
    printf("\n");
    spaces_per_line--;
    stars_per_line = stars_per_line + 2;
    number_of_rows++;
  }
  return 0;

}
