#include <stdio.h>
#include <string.h>

/* Exercise 1-23:  Write a program to remove all comments from a C program.  Don't forget to handle quoted strings and character constants properly.  C comments do not nest. */

#define IN 1
#define OUT 0

void updateSequence(char sqnc[], int c);

int main() {
  int c, str, lcom, scom;
  char sqnc[3] = {'\0', '\0', '\0'};

  scom = lcom = str = OUT;

  while((c = getchar()) != EOF) {
    updateSequence(sqnc, c);
    
    // update the states
    if(c == '"' && str == OUT && lcom == OUT && scom == OUT)
      str = IN;
    else if(c == '"' && str == IN)
      str = OUT;
    if(strcmp(sqnc, "/*") == 0 && str == OUT && lcom == OUT && scom == OUT)
      lcom = IN;
    else if(strcmp(sqnc, "*/") == 0 && lcom == IN)
      lcom = OUT;
    if(strcmp(sqnc, "//") == 0 && str == OUT && lcom == OUT && scom == OUT)
      scom = IN;
    else if(c == '\n' && scom == IN)
      scom = OUT;
    
    if(scom == OUT && lcom == OUT && c != '/')
      putchar(c);
    else if (str == IN)
      putchar(c);
  }
}

void updateSequence(char sqnc[], int c) {
  sqnc[0] = sqnc[1];
  sqnc[1] = c;
}
