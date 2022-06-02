#include <stdio.h>
#include "arghandler.h"

#define BUFSIZE 100

static char buf[BUFSIZE];  // buffer for ungetch
static int bufp = 0;       // next free position in buf

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getarg(); // Changed from pcalc!
}

void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: Too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}
