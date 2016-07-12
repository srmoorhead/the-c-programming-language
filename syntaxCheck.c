#include <stdio.h>

/* Exercise 1-24:  Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses, brackets and braces.  Don't forget about quotes, both single and double, escape sequences, and comments.  (This program is hard if you do it in full generality.) */

#define MAXELS 1000 /* the maximum number of elements in our "stack" char array */
#define IN 0 /* we are in a string, char, or escape sequence */
#define OUT 1 /* we are out of a string, char, or escape sequence */

int main() {
  int c, i, line, strState, charState, escState, error;
  char stack[MAXELS];
  
  i = 0; // stack index
  line = 1; // line in file
  strState = charState = escState = error = OUT;

  while((c = getchar()) != EOF && error != IN) {
    if(c == '\n')
      ++line;

    // pushing to the stack
    if((c == '(' || c == '{' || c == '[' || c == '<') && strState == OUT && charState == OUT) {
      stack[i] = c;
      ++i;
    }  
    else if(c == '"' && strState == OUT && charState == OUT) {
      stack[i] = c;
      ++i;
      strState = IN;
    }
    else if(c == '\'' && strState == OUT && charState == OUT) {
      stack[i] = c;
      ++i;
      charState = IN;
    }
    
    // popping from the stack
    if(c == ')' && strState == OUT && charState == OUT) {
      --i;
      if(stack[i] != '(')
	error = IN;
    }
    else if(c == '}' && strState == OUT && charState == OUT) {
      --i;
      if(stack[i] != '{')
	error = IN;
    }
    else if(c == ']' && strState == OUT && charState == OUT) {
      --i;
      if(stack[i] != '[')
	error = IN;
    }
    else if(c == '>' && strState == OUT && charState == OUT) {
      --i;
      if(stack[i] != '<')
	error = IN;
    }
    
    if(c == '"' && strState == IN && escState == OUT) {
      --i;
      if(stack[i] != '"')
	error = IN;
      strState = OUT;
    }

    if(c == '\'' && charState == IN && escState == OUT) {
      --i;
      if(stack[i] != '\'')
	error = IN;
      charState = OUT;
    }
    
    // Updating the escape state
    if(c == '\\' && escState == OUT)
      escState = IN;
    else
      escState = OUT;
  }
  
  // Let the user know how things went
  if(error == IN)
    printf("There is an error on line %d\n", line);
  else
    printf("No errors were found.  Good job!\n");
}
