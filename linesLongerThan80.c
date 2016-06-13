#include <stdio.h>

/* Exercise 1-17:  Write a program to print all input lines that are longer than 80 characters.
Note, the limit can be changed by changing CHARLIM */

#define MAXLEN 1000 /* the maximum number of stored chars for a line */
#define CHARLIM 80 /* the limit above which we print a line */

int getOneLine(char line[], int max);

int main()
{
  int len, i;
  char line[MAXLEN];

  while((len = getOneLine(line, MAXLEN)) != 0) {
    if(len > CHARLIM)
      printf("%s", line);
  }
}

int getOneLine(char s[], int max)
{
  int i, c;

  for(i = 0; i < max - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
    s[i] = c;
  }
  if(c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
