#include <stdio.h>
#include <stdlib.h> // For atof()
#include <math.h>   // For sin, exp, and pow
#include <string.h> // For strcmp

#include "main.h"
#include "stack.h"
#include "getch.h"
#include "getop.h"
#include "var.h"


#define MAXOP 100 // Max size of operand or operator


double lastval = 0.0; // Stores last printed output value

void actonname(char s[]);



int main(void) {
  int type, noprint = 0;
  double op2;
  char s[MAXOP];
  
  printf(">>Polish calculator<<\nSpecial commands:\t?: see top of stack,"
    "\t#: duplicate top of stack,\t\\: swap two latest numbers,\t!: clear stack,"
    "\nVariables can be assigned using the =varname notation\n\n");
  
  while((type = getop(s)) != EOF) {
    switch(type) {
      case NUMBER:
        push(atof(s));
        break;
      case NAME:
        actonname(s);
        break;
      case '=':
        storevar(s);
        noprint++;
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
        clearvar();
        noprint++;
        break;
      case '\n':
        if (noprint == 0) {
          lastval = pop();
          printf("\t%.8g\n", lastval);
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


void actonname(char s[]) {
  double op2;
  int vp;
  
  if (strcmp(s, "sin") == 0) {
    push( sin( pop() ) );
  } else if (strcmp(s, "exp") == 0) {
    push( exp( pop() ) );
  } else if (strcmp(s, "pow") == 0) {
    op2 = pop();
    push( pow( pop(), op2 ) );
  } else if (strcmp(s, "r") == 0) {
    push (lastval);
  } else if ( (vp = checkvar(s)) != -1 ){
    push( getvar(vp) );
  } else {
    printf("Error: Command or variable %s not recognised\n", s );
  }
}
