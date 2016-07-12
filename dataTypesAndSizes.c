#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>

/* Exercise 2-1:  Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation.  Harder if you compute them:  determine the ranges of various floating-point types. */

#define UCHR "UCHR"  // An unsigned char
#define SCHR "SCHR"  // A signed char
#define USHT "USHT"  // An unsigned short
#define SSHT "SSHT"  // A signed short
#define UINT "UINT"  // An unsigned int
#define SINT "SINT"  // A signed int
#define ULNG "ULNG"  // An unsigned long
#define SLNG "SLNG"  // A signed long

#define NUM_TYPES 8

char types[NUM_TYPES][5] = {UCHR, SCHR, USHT, SSHT, UINT, SINT, ULNG, SLNG};

unsigned long computeMaximum(char type[]);
long computeMinimum(char type[]);
unsigned long headerMaximum(char type[]);
long headerMinimum(char type[]);

int main() {
  unsigned long comp_max, limits_max;
  long comp_min, limits_min;
  int i;
  
  printf("\n%s%25s%25s%25s%25s\n\n", "Type", "Calculated Max", "limits.h Max", "Calculated Min", "limits.h Min");
  for(i = 0; i < NUM_TYPES; ++i) {
    comp_max = computeMaximum(types[i]);
    comp_min = computeMinimum(types[i]);
    limits_max = headerMaximum(types[i]);
    limits_min = headerMinimum(types[i]);
    
    printf("%s%25lu%25lu%25ld%25ld\n", types[i], comp_max, limits_max, comp_min, limits_min);
  }
  printf("\n");
}

// Computes the maximum value of the type
unsigned long computeMaximum(char type[]) {
  unsigned long max;
  
  if(strcmp(type, UCHR) == 0) {
    max = (2 << (CHAR_BIT * sizeof(unsigned char) - 1)) - 1;
  }
  else if (strcmp(type, SCHR) == 0) {
    max = ((2 << (CHAR_BIT * sizeof(signed char) - 1)) / 2) - 1;
  }
  else if (strcmp(type, USHT) == 0) {
    max = (2 << (CHAR_BIT * sizeof(unsigned short) - 1)) - 1;
  }
  else if (strcmp(type, SSHT) == 0) {
    max = ((2 << (CHAR_BIT * sizeof(signed short) - 1)) / 2) - 1;
  }
  else if (strcmp(type, UINT) == 0) {
    max = (((2lu << (CHAR_BIT * sizeof(unsigned int) - 2)) - 1l) * 2l) + 1l;
  }
  else if (strcmp(type, SINT) == 0) {
    max = ((((2lu << (CHAR_BIT * sizeof(signed int) - 2)) - 1l) * 2l) + 1l) / 2l;
  }
  else if (strcmp(type, ULNG) == 0) {
    max = (((2lu << (CHAR_BIT * sizeof(unsigned long) - 2l)) - 1l) * 2l) + 1l;
  }
  else {
    max = ((((2lu << (CHAR_BIT * sizeof(signed long) - 2l)) - 1l) * 2l) + 1l) / 2l;
  }

  return max;
}

// Computes the minimum value of the type
long computeMinimum(char type[]) {
  long min;

  if(strcmp(type, UCHR) == 0) {
    min = 0;
  }
  else if (strcmp(type, SCHR) == 0) {
    min = -(((2 << (CHAR_BIT * sizeof(char) - 1)) / 2) - 1) - 1;
  }
  else if (strcmp(type, USHT) == 0) {
    min = 0;
  }
  else if (strcmp(type, SSHT) == 0) {
    min = -(((2 << (CHAR_BIT * sizeof(short) - 1)) / 2) - 1) - 1;
  }
  else if (strcmp(type, UINT) == 0) {
    min = 0;
  }
  else if (strcmp(type, SINT) == 0) {
    min = -(((((2lu << (CHAR_BIT * sizeof(int) - 2)) - 1l) * 2l) + 1l) / 2l) - 1;
  }
  else if (strcmp(type, ULNG) == 0) {
    min = 0;
  }
  else {
    min = -(((((2lu << (CHAR_BIT * sizeof(long) - 2l)) - 1l) * 2l) + 1l) / 2l) - 1;
  }

  return min;
}


// Retrieves the maximum value from the header limits.h
unsigned long headerMaximum(char type[]) {
  unsigned long max;

  if(strcmp(type, UCHR) == 0) {
    max = UCHAR_MAX;
  }
  else if (strcmp(type, SCHR) == 0) {
    max = CHAR_MAX;
  }
  else if (strcmp(type, USHT) == 0) {
    max = USHRT_MAX;
  }
  else if (strcmp(type, SSHT) == 0) {
    max = SHRT_MAX;
  }
  else if (strcmp(type, UINT) == 0) {
    max = UINT_MAX;
  }
  else if (strcmp(type, SINT) == 0) {
    max = INT_MAX;
  }
  else if (strcmp(type, ULNG) == 0) {
    max = ULONG_MAX;
  }
  else {
    max = LONG_MAX;
  }

  return max;
}

// Retrieves the minimum value from the header limits.h
long headerMinimum(char type[]) {
  long min;

  if(strcmp(type, UCHR) == 0) {
    min = 0;
  }
  else if (strcmp(type, SCHR) == 0) {
    min = SCHAR_MIN;
  }
  else if (strcmp(type, USHT) == 0) {
    min = 0;
  }
  else if (strcmp(type, SSHT) == 0) {
    min = SHRT_MIN;
  }
  else if (strcmp(type, UINT) == 0) {
    min = 0;
  }
  else if (strcmp(type, SINT) == 0) {
    min = INT_MIN;
  }
  else if (strcmp(type, ULNG) == 0) {
    min = 0;
  }
  else {
    min = LONG_MIN;
  }

  return min;
}
