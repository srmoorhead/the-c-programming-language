#include <stdio.h>

/* Exercise 1-18:  Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines. */

#define MAXLEN 1000 /* the maximum number of characters read from any line */

int getOneLine(char line[], int max);
void removeTrailingBlanks(char line[], int strLen);

int main()
{
  char line[MAXLEN];
  int length;

  while((length = getOneLine(line, MAXLEN)) != 0) {
    if(length > 1) {
      removeTrailingBlanks(line, length);
      printf("%s", line);
    }
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

void removeTrailingBlanks(char s[], int len) 
{
  int newline;
  
  // if the last char is newline, remove it and save this condition
  if(s[len - 1] == '\n') {
    s[len - 1] = '\0';
    --len;
    newline = 1;
  }
  else
    newline = 0;
  
  // remove the blanks and tabs
  while((s[len - 1] == '\t' || s[len - 1] == ' ') && ((len - 1) >= 0)) {
    s[len - 1] = '\0';
    --len;
  }

  // if the last char was newline, replace it here
  if(newline == 1)
    s[len] = '\n';
}
