#include <stdio.h>

/* Exercise 1-16:  Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as possible of the text. */

#define MAXLEN 1000 /* maximum input line size */

int getOneLine(char line[], int maxline);  // getline is a protected function name
void copy(char to[], char from[]);

int main() 
{
  int len;  /* current line length */
  int max;  /* maximum length seen so far */
  char line[MAXLEN];  /* current input line */
  char longest[MAXLEN];  /* longest line saved here */
  int c;

  max = 0;
  while ((len = getOneLine(line, MAXLEN)) > 0) {
    /* addition for exercise 1-16 */
    if (line[len - 1] != '\n') {
      while((c = getchar()) != '\n' && (c != EOF))
	++len;
    }
    /* end addition */
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0) /* there was a line */
    printf("%s\n%d chars\n", longest, max);
  return 0;
}

// Returns the length of the line
// Changes line[] to the next line of input
// If return == 0, we have reached EOF
int getOneLine(char s[], int lim) 
{
  int c, i;

  for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if(c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}

// Copies the values in from[] to to[]
// Assumes to[] is big enough
void copy(char to[], char from[]) 
{
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0')
    ++i;
}
