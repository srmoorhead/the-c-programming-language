#include <stdio.h>

/*  
Exercise 1-14:  Write a program to print a histogram of the frequencies of different characters in its input.

Note:  only including a-z and A-Z
*/

#define ALPHA_SIZE 26 /* the number of letters in the alphabet */

int main() {
  int current, i;
  int lowerCase[ALPHA_SIZE];
  int upperCase[ALPHA_SIZE];

  for(i = 0; i < ALPHA_SIZE; ++i) {
    lowerCase[i] = upperCase[i] = 0;
  }

  // count the chars until EOF
  while((current = getchar()) != EOF) {
    if(current >= 'a' && current <= 'z') {
      ++lowerCase[current - 'a'];
    }
    else if(current >= 'A' && current <= 'Z') {
      ++upperCase[current - 'A'];
    }
  }

  // Display results in a horizontal histogram
  // Combining upper and lower cases for simple display
  int lowerLetter = 'a';
  int upperLetter = 'A';
  int totals[ALPHA_SIZE];

  for(i = 0; i < ALPHA_SIZE; ++i) {
    totals[i] = lowerCase[i] + upperCase[i];
  }

  for(i = 0; i < ALPHA_SIZE; ++i) {
    char letterCombo[3] = {upperLetter, lowerLetter, '\0'};
    printf("%s : ", letterCombo);
    for(int j = 0; j < totals[i]; ++j)
      printf("#");
    printf("\n");
    ++upperLetter;
    ++lowerLetter;
  }

  printf("\n\n");

  // Display results in a vertical histogram
  // Combining upper and lower case letters for simple display
  
  // first, determine the max count
  int max_count = -1;
  int max_index = -1;
  for(i = 0; i < ALPHA_SIZE; ++i) {
    if(totals[i] > max_count) {
      max_count = totals[i];
      max_index = i;
    }
  }

  // next, print the rows
  for(i = max_count; i > 0; --i) {
    for(int j = 0; j < ALPHA_SIZE; ++j) {
      if(totals[j] >= i)
	printf("#  ");
      else
	printf("   ");
    }
    printf("\n");
  }
  
  // print an axis line
  for(i = 0; i < ALPHA_SIZE; ++i)
    printf("---");
  printf("\n");

  // print the column labels
  lowerLetter = 'a';
  upperLetter = 'A';
  for(i = 0; i < ALPHA_SIZE; ++i) {
    char letterCombo[3] = {upperLetter, lowerLetter, '\0'};
    printf("%s ", letterCombo);
    ++upperLetter;
    ++lowerLetter;
  }
  printf("\n");
}
