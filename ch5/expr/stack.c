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

void look(void) {
  if (sp > 0) {
    printf("Top of stack is %g\n", val[sp-1]);
  } else {
    printf("Stack is empty\n");
  }
  return;
}

void duplicate(void) {
  if (sp < STACKMAXVAL && sp > 0) {
    val[sp] = val[sp-1];
    sp++;
  } else if (sp == STACKMAXVAL) {
    printf("Error: Stack full, can't dublicate top value %g\n", val[sp-1]);
  } else {
    printf("Error: Stack empty, nothing to duplicate\n");
  }
  return;
}

void swap(void) {
  double temp;
  if (sp > 1) {
    temp = val[sp-1];
    val[sp-1] = val[sp-2];
    val[sp-2] = temp;
  } else {
    printf("Error: Stack has to few entries to swap top. Stack has %d entries\n", sp);
  }
  return;
}

void clear(void) {
  sp = 0;
}
