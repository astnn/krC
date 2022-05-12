#include <stdio.h>
#include <stdlib.h> // For atof()

#include "main.h"
#include "stack.h"
#include "getch.h"
#include "getop.h"



/* Given the basic framework it is straightforward to extend the calculator. Add
the modulus operator and provisions for negative numbers. */


#define MAXOP 100 // Max size of operand or operator


int main(void) {
  int type, noprint = 0;
  double op2;
  char s[MAXOP];
  
  printf(">>Polish calculator<<\nSpecial commands:\t?: see top of stack,"
    "\t#: duplicate top of stack,\t\\: swap two latest numbers,\t!: clear stack\n" );
  
  while((type = getop(s)) != EOF) {
    switch(type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0 ){
          push(pop() / op2);
        } else {
          printf("Error: Zero divisor\n");
        }
        break;
      case '%':
        op2 = pop();
        push( (long) pop() % (long) op2);
        break;
      case '?':
        look();
        noprint++;
        break;
      case '#':
        duplicate();
        noprint++;
        break;
      case '\\':
        swap();
        noprint++;
        break;
      case '!':
        clear();
        noprint++;
        break;
      case '\n':
        if (noprint == 0) {
          printf("\t%.8g\n", pop());
        } else {
          noprint = 0;
        }
        
        break;
      default:
        printf("Error: Unknown command %s\n", s);
        break;
    }
  }
  
  return 0;
}
