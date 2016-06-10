#include <stdio.h>

/* count digits, white space, others */
int main()
{
	int c, i, nwhite, nother;
	int ndigit[10];
	
	// set variables to their initial values
	nwhite = nother = 0;
	for(i = 0; i < 10; ++i)
	  ndigit[i] = 0;
	
	// count everything
	while((c = getchar()) != EOF) {
	  // we are using the ascii values of the characters
	  // but normalized by 0 so we don't have to compare to absolute values
	  if(c >= '0' && c <= '9')
	    ++ndigit[c-'0'];
	  else if (c == ' ' || c == '\n' || c == '\t')
	    ++nwhite;
	  else
	    ++nother;
	}
	
	// display the results
	printf("digits =");
	for(i = 0; i < 10; ++i)
	  printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);
}
