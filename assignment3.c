
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 9
/* NOTE: You will have to code the 2 functions BELOW "checkDups" and "clearArray"
   before running this program to see the generated output.
   */
int checkDups(int [], int, int);
void clearArray(int [], int);

int genSudokuNumbers(int grid[]); /* already coded */

void genSudokuBoard(int grid[], int display[]);
void displaySudokuBoard(int display[], int bigOh);
void printSudokuBoardToFile(int display[], const char *fileName);

int main() {
  int grid[N*N], display[N*N];
  int loops;

  /* students must add code to return the correct
     value for all instructions executed in all loops */
  loops = genSudokuNumbers(grid);
  genSudokuBoard(grid, display);
  displaySudokuBoard(grid, loops);
  printSudokuBoardToFile(display, "data.txt");

  return 0;
}

/* given an array of 'n' elements, this function determines if the
   value 'search' is already present within the array 'nums' and if
   so, sends back a true value (1) or false (0) otherwise */
int checkDups(int nums[], int search, int n) {
  int i;
  int found = 0;
  for (i = 0; i < n; i++) {
    if (nums[i] == search) {
      found = 1;
      break;
    }
  }
  return found;
}

/* Sets all 'n' values in the 'nums' array to 0 */
void clearArray(int nums[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    nums[i] = 0;
  }
}

int genSudokuNumbers(int grid[]) {
  int c, i, j, rowNum, colNum, blockNum;
  int test[N], dup, temp, valid, cnt, iterations=0;

  srand(time(NULL));         /* seeding the random number generator */

  for(i = 0; i < N * N; i++) {     /* initializing the grid array to all 0's */
    ++iterations;
    grid[i] = 0;
  }

  for(c = 0; c < N * N; c++) {     /* main loop to generate N*N numbers for the grid */
    ++iterations;
    temp = rand( ) % N + 1; /* generate random # from 1 to N inclusive */
    valid = dup = cnt = 0;

    /* keep looping as long as the 'valid' flag is false */
    while (!valid) {
      ++iterations;
      clearArray(test, N);

      /* the calculations below determine the row, col,
         and block numbers (index 0 to 8) based on the
         linear index variable 'c' */
      rowNum = c / N;
      colNum = c % N;
      blockNum = (rowNum / 3) * 3 + (colNum / 3);

      /* now check to see if the number 'temp' is a
         duplicate in the row, column, and block to which
         'c' corresponds */

      for (j = 0; j < colNum; j++) {    /* fill row (but only up to colNum) */
        ++iterations;
        test[j] = grid[rowNum * N + j];
      }

      dup += checkDups(test, temp, colNum);

      if (!dup) {                   /* row is valid, now check column */
        clearArray(test, N);
        for (j = 0; j < rowNum; j++) { /* fill column (but only up to rowNum) */
          ++iterations;
          test[j] = grid[j*N + colNum];
        }
        dup += checkDups(test, temp, rowNum);

        if (!dup) {                /* column is valid now check block */
          clearArray(test, N);

          /* equation used to generate array
             coordinates for all N blocks
             (i.e.)
             0, 1, 2,   9, 10, 11,  18, 19, 20  {blk 0}
             3, 4, 5,  12, 13, 14,  21, 22, 23  {blk 1}
             6, 7, 8,  15, 16, 17,  24, 25, 26  {blk 2}

             27, 28, 29, 36, 37, 38, 45, 46, 47 {blk 3}
             30, 31, 32, 39, 40, 41, 48, 49, 50
             33, 34, 35, 42, 43, 44, 51, 52, 53

             54, 55, 56, 63, 64, 65, 72, 73, 74
             57, 58, 59, 66, 67, 68, 75, 76, 77
             60, 61, 62, 69, 70, 71, 78, 79, 80 {blk 8}
             */
          for (j = 0; j < N; j++) {
            ++iterations;
            test[j] = grid[((blockNum/3)*N*3) + (colNum/3)*3 + (j/3)*N + j%3];
          }
          dup += checkDups(test, temp, N);
        }
      }

      if (!dup) { /* no duplicates in row, column, or block, so number
                     can be inserted into the grid */
        grid[c] = temp;
        valid = 1;
        cnt = 0;
      } else {     /* duplicate number found, so reset flags and generate
                      new random number */
        temp = rand() % N + 1;
        dup = 0;
        cnt++;
      }

      if(cnt > N * N) {
        /* if after N*N attempts, no possible value is found
           then reset the entire array and start over
           (brute force algorithm)
           average runtime: 500000 iterations */
        dup = cnt = 0;
        valid = 1;
        clearArray(grid, N*N);
        temp = rand( ) % N + 1;
        c = -1; /* will be reset to 0 in for loop */
      }
    }
  }
  return iterations; /* 'iterations' must be updated within this function BEFORE it is returned */
}

/*
 * This function uses the 81 element 'grid' array (containing a fully
 * completed list of valid Sudoku values) and randomly copies 4 numbers
 * from each 3x3 block into the corresponding positions in the 81
 * element 'display' array.
 */
void genSudokuBoard(int grid[], int display[]) {
  int block[9] = {0,1,2,9,10,11,18,19,20};
  int offsets[9] = {0,3,6,27,30,33,54,57,60};
  int i, j;
  clearArray(display, N*N);

  for (i = 0; i < N; i++) {
    j = 0;
    while (j < 4) {
      int rnd = rand() % N;
      int index = block[rnd] + offsets[i];
      if (display[index] == 0) {
        display[index] = grid[index];
        j++;
      }
    }
  }
}

/*
 * This function uses the 81 element 'grid' array (containing a COMPLETE
 * list of valid Sudoku values: all elements filled) and then displays
 * the entire Sudoku board to the screen. You are also required to display
 * the border consisting of '-', '+', and '|' symbols and the title.
 * The final line of output must include the total number iterations (instructions in all loops)
 * that were executed when calling the int genSudokuNumbers(int grid[ ]) function (above)
 * with the output appearing as: "Total Instructions:X" where X is the value stored in "bigOh"
 */
void displaySudokuBoard(int grid[], int bigOh) {
  int i;
  char separator[] = "+-----+-----+-----+";
  printf("PLAY IPC144 SUDOKU\n");

  for(i = 0; i < N * N; i++) {  /* displaying all N*N numbers in the 'grid' array */
    int n = grid[i];
    if (i % 27 == 0) {
      printf("%s\n", separator);
    }
    switch (i % N) {
      case 0: //fall through
      case 3: //fall through
      case 6:
        printf("|%d", n);
        break;
      case 8:
        printf(" %d|\n", n);
        break;
      default:
        printf(" %d", n);
    }
  }
  printf("%s", separator);
  printf("\nTotal Instructions:%d\n", bigOh);
}

/*
 * This function uses the 81 element 'display' array (containing a partial
 * list of valid Sudoku values; 4 values per 3x3 block) and prints
 * the entire Sudoku board to the file named in 'fileName'.
 * You are also required to display the border consisting of '-', '+',
 * and '|' symbols and the title.
 */
void printSudokuBoardToFile(int display[ ], const char *fileName) {
  FILE *fp;
  fp = fopen(fileName, "w");
  if (fp == NULL) {
    printf("error opening file...%s\n", fileName);
    exit(EXIT_FAILURE);
  } else {
    int i;
    char separator[] = "+-----+-----+-----+";
    fprintf(fp, "PLAY IPC144 SUDOKU\n");

    for(i = 0; i < N * N; i++) {  /* displaying all N*N numbers in the 'display' array */
      int n = display[i];
      int blank = n == 0;
      if (i % 27 == 0) {
        fprintf(fp, "%s\n", separator);
      }
      switch (i % N) {
        case 0: //fall through
        case 3: //fall through
        case 6:
          blank ? fprintf(fp, "| ") : fprintf(fp, "|%d", n);
          break;
        case 8:
          blank ? fprintf(fp, "  |\n") : fprintf(fp, " %d|\n", n);
          break;
        default:
          blank ? fprintf(fp, "  ") : fprintf(fp, " %d", n);
      }
    }
    fprintf(fp, "%s\n", separator);
  }
  fclose(fp);
}
