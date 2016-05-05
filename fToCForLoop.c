#include <stdio.h>

#define LOWER 0   /* lower bound */
#define UPPER 300  /* upper bound */
#define STEP 20  /* step size */

int main() {
  printf("Fahrenheit to Celcius Table with For Loop, Reversed\n");
  for(int fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
  }
}
