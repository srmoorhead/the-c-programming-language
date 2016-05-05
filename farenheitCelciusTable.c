#include <stdio.h>

/* print Farenheit - Celcius table
   for fahr = 0, 20, 40, 60, ..., 300 */
int main() {
  float fahr, cels;
  int lower, upper, step;

  lower = 0;  /* lower limit of farenheit table */
  upper = 300; /* upper limit of farenheit table */
  step = 20; /* step size between adjacent farenheit table values */
  
  printf("Farenheit to Celcius Conversion Table\n");
  
  fahr = lower;
  while (fahr <= upper) {
    cels = 5.0 * (fahr - 32.0) / 9.0; 
    printf("%3.0f %6.1f\n", fahr, cels);
    fahr = fahr + step;
  }
}
