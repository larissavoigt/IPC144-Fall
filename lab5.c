#include <stdio.h>
#define ROWS 60

int main() {
  char romanNumerals[ROWS][13] = { /* an array of strings of Roman Numerals */
    "MMMCMXCVIII",  "MMMCMXCIX", "MMMCDLVI", "MMCCCXLV", "MMCXII",
    "MDCCCXXXVIII", "CCC",       "I",        "II",       "III",
    "IV",           "V",         "VI",       "VII",      "VIII",
    "IX",           "X",         "XI",       "XII",      "XIII",
    "XIV",          "XV",        "XVI",      "XVII",     "XVIII",
    "XIX",          "XX",        "XXI",      "XXII",     "XXIII",
    "XXIV",         "XXV",       "XXVI",     "XXVII",    "XXVIII",
    "XXIX",         "XXX",       "DLXXXI",   "DLXXXII",  "DLXXXIII",
    "DLXXXIV",      "DLXXXV",    "DLXXXVI",  "DLXXXVII", "DLXXXVIII",
    "DLXXXIX",      "DXC",       "MCMXCIX",  "MM",       "MMX",
    "MMXIV",        "MCMLXIX",   "MCMLXIII", "MMXXVIII", "DCLXXVIII",
    "CD",           "DC",        "DX",       "CXC",      "LXXXVIII" };

  int i;

  for (i = 0; i < ROWS; i++) {
    printf("%d:%s\n", rnti(romanNumerals[i]), romanNumerals[i]);
  }

  return 0;
}

int rnti(const char s[]) {
  int i = 0;
  char c = s[i];
  int decs[13] = {};

  while (c != '\0') {
    switch (c) {
      case 'I':
        decs[i] = 1;
        break;
      case 'V':
        decs[i] = 5;
        break;
      case 'X':
        decs[i] = 10;
        break;
      case 'L':
        decs[i] = 50;
        break;
      case 'C':
        decs[i] = 100;
        break;
      case 'D':
        decs[i] = 500;
        break;
      case 'M':
        decs[i] = 1000;
        break;
      default:
        decs[i] = 0;
    }
    c = s[++i];
  }

  int sum = 0;
  int buffer = 0;
  int j;

  for (j = 0; j < 13; j++) {
    int current = decs[j];
    int next = j + 1;

    if (next >= 13 || current > decs[next]) {
      sum += current + buffer;
      buffer = 0;
    } else if (current < decs[next]) {
      sum -= current + buffer;
      buffer = 0;
    } else {
      buffer += current;
    }
  }

  return sum;
}
