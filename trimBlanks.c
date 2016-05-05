#include <stdio.h>

/* Exercise 1-9:  Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank. */

int main() {
  int c;
  
  while((c = getchar()) != EOF) {
    /* copy character */
    putchar(c);
    
    /* if it's a space, keep reading until you find a non-space */
    if(c == ' ') {
      while(c == ' ')
	c = getchar();
      /* print the non-space */
      putchar(c);
    }
  }
}
