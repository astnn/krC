#include <stdio.h>

/* Write program to copy input to output. Replace tabs by \t, backspace by \b,
and backslash by \\. */

int main(void) {
  int c;

  while( (c = getchar()) != EOF) {
    if( c == '\t') {
      putchar('\\');
      putchar('t');
    } else if (c == '\b') {
      putchar('\\');
      putchar('b');
    } else if (c == '\\') {
      putchar('\\');
      putchar('\\');
    } else {
      putchar(c);
    }
  }

  return 0;
}
