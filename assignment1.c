/*
 * Assignment 1
 * Subject: IPC144L
 * Student name: Larissa de Jesus Voigt
 * Student number: 024769143
 * Instructor name: Danny Abesdris
 * Due date: October 3, 2014
 * Date submitted: September 28,2014
 * Purpose: First assignment - Fall 2014
 *
 *
 * Student Oath:
 *
 *  "I declare that the attached assignment is wholly my own work in accordance with Seneca Academic Policy. No part of this assignment has been copied manually or electronically from any other source (including web sites) or distributed to other students."
 *
 *  Name Larissa Voigt   Student ID 024769143
 *
 */

#include <stdio.h>

int main(){

  const double MIN_DATE = 2299160.0;
  double jdn;

  printf("Please enter a Julian Day Number greater than %.0lf: ", MIN_DATE);
  scanf("%lf", &jdn);

  if (jdn < MIN_DATE) {
    printf("Invalid date\n");
    return -1; // Return to terminate program
  }

  // else

  long lc, kc, nc, ic, jc;
  int day, month, year;

  lc = jdn + 68569;
  nc = ((4 * lc) / 146097);
  lc = lc - ((146097 * nc + 3) / 4);
  ic = ((4000 * (lc + 1)) / 1461001);
  lc = lc - ((1461 * ic) / 4) + 31;
  jc = ((80 * lc) / 2447);
  day = lc - ((2447 * jc) / 80);
  lc = (jc / 11);
  month = jc + 2 - 12 * lc;
  year = 100 * (nc - 49) + ic + lc;

  printf("%d %d %d\n", day, month, year);

  return 0;

}
