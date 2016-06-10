#include <stdio.h>

/* mostly copied from p. 20 of the C Programming Language book */
/* rewritten and reviewed for understanding */

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words and characters */
int main()
{
  int current_char, nlines, nwords, nchars, state;

  state = OUT;
  nlines = nwords = nchars = 0;

  while (( current_char = getchar()) != EOF) {
    ++nchars;
    /* we are counting newlines as chars as well */
    if (current_char == '\n')
      ++nlines;
    if (current_char == ' ' || current_char == '\n' || current_char == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nwords;
    }
  }
  printf("Lines: %d, Words: %d, Chars: %d\n", nlines, nwords, nchars);
  return 1;
}
