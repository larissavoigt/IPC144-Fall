#include <stdio.h>

int perfectNumGen(int);

int main() {

  int n = 1, found = 0;
  while (n >= 10000) {
    found += perfectNumGen(n);
    n++;
  }

  if (found == 4) {
    print("Congratulations!"
          "Your function may be working"
          "properly"
          "(check output above)...\n");
     }

  else {
    printf("There is an error\n"
           "with your function!\n"
           "Please correct your errors\n"
           "and resubmit your code!\n";
        )
  }

  return 0;

  }


int perfectNumGen(int n) {
  printf("Give me an interger:  \n");
  scanf("&d", int);

  while(int <= 10000) {

  }


}








}
