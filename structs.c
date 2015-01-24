#include <stdio.h>

struct person {
  int age;
  float height;
  char* name;
  char gender;
};

int main(){
  struct person larissa;
  larissa.age = 27;
  larissa.height = 5.5;
  larissa.name = "larissa";
  larissa.gender = 'f';

  printf("%d\n", sizeof(larissa));
  printf("%d\n", larissa.age);
  printf("%.1f\n", larissa.height);
  printf("%s\n", larissa.name);
  printf("%c\n", larissa.gender);

  return 0;
}
