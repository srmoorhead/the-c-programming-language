#include <stdio.h>

/* Exercise 1-20:  Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop, say every n columns.  Should n be a variable or a symbolic parameter? */

#define SPT 8 // the number of spaces per tab (n)

int main() {
  int c, spaces;
  spaces = SPT;

  while((c = getchar()) != EOF) {
    if(c == '\t') {
      for(int i = 0; i < spaces; ++i)
	putchar(' ');
      spaces = SPT;
    }
    else {
      putchar(c);
      --spaces;
      
      if(spaces == 0 || c == '\n')
	spaces = SPT;
    }
  }
}

