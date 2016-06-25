#include <stdio.h>

/* Exercise 1-21:  Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing.  Use the same tab stops as for detab.  When either a tab or a single blank would suffice to reach a tab stop, which should be given preference? */

#define SPT 8 // the number of Spaces Per Tab
#define IN 0 // we are in a word
#define OUT 1 // we are out of a word

int main() {
  int c, state, nchars, count, i;

  state = IN;
  nchars = 0; // number of chars to next tabstop
  count = 0; // number of consecutive spaces

  while((c = getchar()) != EOF) {
    ++nchars;
    
    // update the state
    if(c == ' ' && state == IN) {
      state = OUT;
      count = 0;
    }
    else if(c != ' ')
      state = IN;

    // handle each state
    if(state == OUT) {
      if(nchars == SPT) {
	putchar('\t');
	count = 0;
      }
      else
	++count;
    }
    else {
      // pop any spaces onto the output
      for(i = 0; i < count; ++i)
	putchar(' ');
      count = 0;
      putchar(c); // add the current char after the spaces
    }

    // update nchars
    if(nchars == SPT || c == '\n' || c == '\t')
      nchars = 0;
  }
}

