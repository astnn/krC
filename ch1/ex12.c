#include <stdio.h>


/* Write a program that prints its input one word per line */

#define OUT 0
#define IN 1

int main(void) {
  int c;
  char state;

  state = OUT; // Initial state is OUT. Allows burn-in if it starts non-word.

  while( (c=getchar()) != EOF) {
    if(c == ' ' || c == '\n' || c == '\t') {
      if(state == IN){
        putchar('\n');
      }

      state = OUT;

    } else {
      state = IN;
      putchar(c);
    }
  }

  return 0;
}
