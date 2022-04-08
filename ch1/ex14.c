#include <stdio.h>

/* Write a program to print a histogram of the frequencies of different
characters in its input */

/* Simplifying assumptions: I will only be counting letters.*/
// ASCII a-z, 97-122
// ASCII A-Z, 65-90

#define ASCII_a 97
#define ASCII_z 122
#define ASCII_A 65
#define ASCII_Z 90

int main(void) {
  int c;
  char letterCount[ASCII_z-ASCII_a];

  for(int i = 0; i <= ASCII_z-ASCII_a; i++) {
    letterCount[i] = 0;
  }

  while( (c=getchar() ) != EOF ) {
    if( ASCII_a <= c <= ASCII_z ) {
      letterCount[c-ASCII_a]++;
    } else if(ASCII_A <= c <= ASCII_A){
      letterCount[c-ASCII_A]++;
    }
  }

printf("\n");
  for(int i = 0; i <= ASCII_z-ASCII_a; i++) {
    printf("%c%c  ",i+ASCII_a, i+ASCII_A);
    for(int j = 0; j < letterCount[i]; j++) {
      putchar('-');
    }
    putchar('\n');
  }

  return 0;
}
