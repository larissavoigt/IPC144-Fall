/*
 *
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
    printf("Invalid JD number! ");
    printf("Please try again with a Julian Day Number greater than %.6lf\n", MIN_DATE);
    /* return to terminate program */
    return -1;
  }

  /* otherwise, continue with the program */

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

  /* time calculation */
  double d_hours, d_mins, d_secs;
  int i_hours, i_mins, i_secs;

  /* get only decimal places */
  int integral = jdn;
  double fraction = jdn - integral;

  d_hours = fraction * 24;
  i_hours = d_hours; /* int casting */

  d_mins = (d_hours - i_hours) * 60;
  i_mins = d_mins; /* int casting */

  d_secs = (d_mins - i_mins) * 60;
  i_secs = d_secs; /* int casting */

  i_hours += 12; /* P.M. */

  /* month names in an array */
  const char *months[] = {"January","February","March","April","May","June",
                          "July","August","September","October","November",
                          "December"};

  printf("%.6lf JD is ", jdn);
  /* Remove 1 from month to match array index (starts with 0) */
  printf("%s %d, %d ", months[month - 1], day, year);
  printf("@ %02d:%02d:%02d P.M.\n", i_hours, i_mins, i_secs);

  return 0;

  /* Result:
   *
   * 1234567.00000
   * Invalid JD number! Please try again with a Julian Day Number greater than 2299160.000000
   *
   * 2462073.000000 JD is October 28, 2028 @ 12:00:00 P.M.
   *
   * 2597701.438960 JD is February 29, 2400 @ 22:32:06 P.M.
   * Leap year
   *
   * 2440423.45556 JD is July 20, 1969 @ 22:56:00 P.M.
   * Apollo 11 Moonwalk
   *
   * 4180057.170830 JD is July 4, 6732 @ 16:05:59 P.M.
   * American Independence Day
   *
   * 2524594.041670 JD is January 1, 2200 @ 13:00:00 P.M.
   *
   * 2438356.02084 JD is November 22, 1963 @ 12:30:00 P.M.
   * President John F. Kennedy was assassinated
   *
   */
}
