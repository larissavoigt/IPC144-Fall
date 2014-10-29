/* Date: October 20th, 2014
 * Purpose: Do temperature conversions / Celsius to Fahrenheit or Fahrenheit to Celsius
 */

#include <stdio.h>

int main() {

  double temperature;
  int choice;

  printf("Which unit would you like to use? \n1 - Celsius to Fahrenheit\n2 - Fahrenheit to Celsius\n");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("Temperature in Celsius: ");
      scanf("%lf", &temperature);
      double temperature_f = temperature * 9.0/5.0 + 32;
      printf("%.0lf in Celsius is %.0lf in Fahrenheit\n", temperature, temperature_f);
      break;

    case 2:
      printf("Temperature in Fahrenheit: ");
      scanf("%lf", &temperature);
      double temperature_c = (temperature - 32) * 5.0/9.0;
      printf("%.0lf in Fahrenheit is %.0lf in Celsius\n", temperature, temperature_c);
      break;

    default:
      printf("Error");
      break;
  }

  return 0;

  }

