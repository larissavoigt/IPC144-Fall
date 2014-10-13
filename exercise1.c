#include <stdio.h>

main()
{
  float pi = 3.141592;
  float volume;
  int radius;

  printf("Give me a number: ");
  scanf("%d", &radius);

  volume = 4.0/3.0 * pi * radius * radius * radius;

  printf("The volume of a circle with a radius of %d is %.4f\n", radius, volume);

  return 0;
}
