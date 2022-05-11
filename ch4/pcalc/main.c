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
  int type;
  double op2;
  char s[MAXOP];
  
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
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("Error: Unknown command %s\n", s);
        break;
    }
  }
  
  return 0;
}
