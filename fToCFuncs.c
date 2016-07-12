#include <stdio.h>

/* Exercise 1-15:  Rewrite the temperature conversion program of Section 1.2 to use a function for the conversion */

#define UPPER 300 /* the upper bound */
#define LOWER 0 /* the lower bound */
#define STEP 20 /* the step size */

int fahrToC(float fahr);
// int celsToF(float cels);

int main() {
  int cels, fahr;

  // print header
  printf("Fahrenheit\tCelsius\n");

  for(cels = LOWER; cels <= UPPER; cels += STEP) {
    fahr = fahrToC(cels);
    printf("%3d\t%6.1d\n", cels, fahr);
  }
}

// Converts a fahrenheit value to celsius
int fahrToC(float fahr) {
  return (5.0)/(9.0) * (fahr - 32.0);
}

/*
// Converts a celsius value to fahrenheit
int celsToF(fload cels) {
  return (cels * (9.0 / 5.0)) + 32.0;
}
*/
