/*
 *Date: Oct 20, 2014
 *Purpose of the program: Calculate the volume of a sphere
 */

#include <stdio.h>

int main() {

  float pi = 3.141592;
  int radius;

  printf("Please enter a value for radius: ");
  scanf("%d", &radius);

  float volume = 4.0/3.0 * pi * (radius * radius * radius);

  printf("Radius: %d\nVolume of the sphere: %.4f\n", radius, volume);

  return 0;

}
