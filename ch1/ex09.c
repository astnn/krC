#include <stdio.h>

/* Write program to copy input to output. Replace trailing blanks with a single
blank*/

/* Pseudo code:
Getc har in while loop.
Check if it is blank.
  If blank print a blank and get new chars until not blank or EOF.
Put char
*/

int main(void) {
  int c;

  while( (c = getchar()) != EOF ) {
    if (c == ' ') {
      putchar(c);
      while( (c = getchar()) == ' ' ) {
        //Keep reading as long as input is blank.
      }
    }
    putchar(c);

  }

  return 0;
}
