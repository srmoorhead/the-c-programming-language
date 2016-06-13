#include <stdio.h>

/*  Exercise 1-19:  Write a function reverse(s) that reverses a character string s.  Use it to write a program that reverses its input a line at a time. */

#define MAXLEN 1000 /* the max number of chars read from a line */

void reverse(char toBeReversed[], int len);
int getOneLine(char line[], int max);

int main()
{
  char line[MAXLEN];
  int i, len;
  
  while((len = getOneLine(line, MAXLEN)) != 0) {
    reverse(line, len);
    printf("%s", line);
  }
}

int getOneLine(char s[], int max)
{
  int c, i;

  for(i = 0; i < max && (c = getchar()) != '\n' && c != EOF; ++i) {
    s[i] = c;
  }
  if(c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void reverse(char s[], int len)
{
  int i = 0;
  if(s[len - 1] == '\n')
    --len;
  while((len - 1) > i) {
    char temp = s[i];
    s[i] = s[len - 1];
    s[len - 1] = temp;
    ++i;
    --len;
  }
}
