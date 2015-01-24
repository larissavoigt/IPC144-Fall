#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
   char item[31];
   float price;
   int qty;
};

float genSummary(struct record list[ ], const char *fileName);

int main() {
   struct record inventory[12];
   char fileNm[21] = "lab7.dat";
   float rv;
   rv = genSummary(inventory, fileNm);

   printf("TOTAL VALUE: $%.2f\n", rv);
   return 0;
}

float genSummary(struct record list[], const char *fileName) {
  const ARRAY_SIZE = 12;
  FILE *fp;
  float total = 0;
  int i = 0;

  fp = fopen(fileName, "r");

  // SCANNING
  while (i < ARRAY_SIZE) {
    char item[31];
    float price;
    int qty;

    if (fscanf(fp, "%[^;];%f;%d\n", item, &price, &qty) == EOF) {
      break;
    }

    struct record r;
    strcpy(r.item, item);
    r.price = price;
    r.qty = qty;

    list[i] = r;

    total += price * qty;
    ++i;
  }

  // SORTING
  int a;
  int b;
  struct record tmp;

  for(a = 0; a < ARRAY_SIZE - 1; a++) {
    for(b = a + 1; b < ARRAY_SIZE; b++) {
      if(strcmp(list[a].item, list[b].item) > 0) {
        tmp = list[a];
        list[a] = list[b];
        list[b] = tmp;
      }
    }
  }


  // PRINTING
  int j;
  for (j = 0; j < ARRAY_SIZE; j++) {
    printf("%s $%.2f %d\n", list[j].item, list[j].price, list[j].qty);
  }

  return total;
}
