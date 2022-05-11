#include <stdio.h> // For printf


#include "stack.h"

#define STACKMAXVAL 100 // Maximum depth of val stack

static int sp = 0; // Next free stack position
static double val[STACKMAXVAL]; // Value stack

/* push: push f onto value stack */
void push(double f) {
  if (sp < STACKMAXVAL) {
    val[sp++] = f;
  } else {
    printf("Error: Stack full, can't push %g\n", f);
  }
  return;
}

/* pop: pop and return top value from stack */
double pop(void) {
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("Error: Stack empty\n");
    return 0.0;
  }
}
