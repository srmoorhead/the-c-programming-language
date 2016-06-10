#include <stdio.h>

/* Exercise 1-12 */
/* Assuming we don't want to include multiple spaces, tabs, or newlines */

#define IN 1 /* we are in a word */
#define OUT 0 /* we are not in a word */

int main() {
  int current, state;
  state = IN;
  while((current = getchar()) != EOF) {
    if(current == ' ' || current == '\t' || current == '\n') {
      if(state == IN) {
	state = OUT;
	putchar('\n');
      }
    }
    else {
      state = IN;
      putchar(current);
    }
  }
}
