#include <stdio.h>

/* Write a program to print a histogram of the frequencies of different
characters in its input */

/* Count all ASCII symbols between 32 and 126 i.e. "normal" characters.
Expanded from ex14.c, which only counted letters.
Displays badly in a terminal due to the histogram being horisontal.*/

#define ASCII_start 32
#define ASCII_end 126

int main(void) {
  int c;
  char letterCount[ASCII_end-ASCII_start];

  for(int i = 0; i <= ASCII_end-ASCII_start; i++) {
    letterCount[i] = 0;
  }

  while( (c=getchar() ) != EOF ) {
    if( ASCII_start <= c <= ASCII_end ) {
      letterCount[c-ASCII_start]++;
    }
  }

printf("\n");
  for(int i = 0; i <= ASCII_end-ASCII_start; i++) {
    printf("%c  ",i+ASCII_start);
    for(int j = 0; j < letterCount[i]; j++) {
      putchar('-');
    }
    putchar('\n');
  }

  return 0;
}
