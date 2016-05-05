#include <stdio.h>

/* must pipe input and output via terminal */

int main() {
  int c;

  /* includes c assignment in while loop */
  while((c = getchar()) != EOF) {
    putchar(c);
  }

}
