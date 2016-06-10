#include <stdio.h>

/* 
Exercise 1-13:  Write a program to print a histogram of the lengths of words in its input.  
It is easy to draw the histogram with the bars horizontal; 
a vertical orientation is more challenging. 

Note: Will histogram 1-9, with a column for 10+ for simplicity.
*/

#define IN 0  // we are in a word
#define OUT 1 // we are outside a word

int main()
{
  // initialize variables
  int lengths[10];
  int state, current, count, i;

  // assign variables
  state = OUT;
  count = 0;
  for(i = 0; i < 10; ++i) {
    lengths[i] = 0;
  }

  // count word lengths until end of file
  while((current = getchar()) != EOF) {

    if(!((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z'))) {
      
      if(state == IN) {
	
	if(count >= 10)
	  ++lengths[9];
	else
	  ++lengths[count - 1];
	
	count = 0;
	state = OUT;
      }
    }
    else {
      state = IN;
      ++count;
    }
  }
  
  // print in a horizontal histogram
  for(i = 0; i < 9; ++i) {
    printf("%d  : ", i + 1);
    for(int j = 0; j < lengths[i]; ++j) {
      printf("#");
    }
    printf("\n");
  }
  printf("10+: ");
  for(i = 0; i < lengths[9]; ++i)
    printf("#");
  printf("\n");


  // print a vertical histogram
  // first, get the max count
  int max_count = -1;
  int max_len = -1;
  for(i = 0; i < 10; ++i) {
    if(lengths[i] > max_count){
      max_count = lengths[i];
      max_len = i + 1;
    }
  }

  printf("\n\n");
  
  // now, start building the rows
  for(i = max_count; i > 0; --i) {
    for(int j = 0; j < 10; ++j) {
      if(lengths[j] >= i)
	printf("# ");
      else
	printf("  ");
    }
    printf("\n");
  }
  printf("---------------------\n");
  printf("1 2 3 4 5 6 7 8 9 10+\n");
}
