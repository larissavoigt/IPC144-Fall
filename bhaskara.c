/* Date: Oct 20th, 2014
 * Purpose: Calculate Bhaskara's formula
 */

#include <stdio.h>
#include <math.h>

int main () {

  double a, b, c;

  printf("Give me a value for a, b and c: ");
  scanf("%lf %lf %lf", &a, &b, &c);

  double delta = (b * b) - 4 * a * c;

  if (delta < 0){
    printf("There is no real root because delta is negative.\n");
    return 0;
  }

  double x1 = (-b + sqrt(delta)) / (2 * a);

  double x2 = (-b - sqrt(delta)) / (2 * a);

  printf("delta is: %.0lf\n x1 is: %.0lf\n x2 is: %.0lf\n", delta, x1, x2);

  return 0;

}
