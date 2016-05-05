#include <stdio.h>

/*  Exercise 1-8:  Write a program to count blanks, tabs, and newlines. */
/*  Input must end in an EOF */

int main() {
  long blanks = 0;
  long tabs = 0;
  long newlines = 0;

  int c;

  while((c = getchar()) != EOF) {
    if(c == ' ')
      ++blanks;
    if(c == '\t')
      ++tabs;
    if(c == '\n')
      ++newlines;
  }
  printf("This input had %ld blanks, %ld tabs, and %ld lines.\n", blanks, tabs, newlines);
}
