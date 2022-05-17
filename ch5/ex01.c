#include <stdio.h>
#include <ctype.h> // For isdigit, isspace

/* As written, getint treats a + or - not followed by a digit as a valid
representation of zero. Fix it to push such a character back on the input */

/* Test either by running ./a.out without any input, or as:
"gcc ex01.c && echo "-1 2 -003" | ./a.out" in a terminal to test EOF behavor */

int getint(int *pn);
int getint2(int *pn);
int getch(void);
void ungetch(int c);

int main(void) {
  int res, status;
  
  while ((status = getint2(&res)) != 0 && status != EOF) {
    printf("Input integer is %d\n", res);
  }
  if (status == EOF ) {
    printf("Reached EOF\n");
  } else {
    printf("Input was not an integer\n");
  }
  
  return 0;
}


/* getint: get next integer from input into *pn . Returns EOF for end of file,
zero if input is not a number and a positive value if input contains number. */
int getint2(int *pn) {
  int c, sign;
  
  while (isspace(c = getch())) {
    // Skip whitespaces
  }
  
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); // it's not a number
    return 0;
  }
  sign = (c == '-' ? -1 : 1);
  if (c == '-' || c == '+') {
    c = getch();
    if (!isdigit(c) && c != EOF) {
      ungetch(c);
      return 0;
    }
  }
  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = 10 * *pn + (c - '0');
  }
  *pn *= sign;
  if (c != EOF) {
    ungetch(c);
  }
  return c;
}

/* getint: get next integer from input into *pn . Returns EOF for end of file,
zero if input is not a number and a positive value if input contains number.
K&R original */
int getint(int *pn) {
  int c, sign;
  
  while (isspace(c = getch())) {
    // Skip whitespaces
  }
  
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); // it's not a number
    return 0;
  }
  sign = (c == '-' ? -1 : 1);
  if (c == '-' || c == '+') {
    c = getch();
  }
  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = 10 * *pn + (c - '0');
  }
  *pn *= sign;
  if (c != EOF) {
    ungetch(c);
  }
  return c;
}


/***** getch and ungetch from krC/ch4/pcalc/getch.c *****/
#define BUFSIZE 100
static char buf[BUFSIZE];  // buffer for ungetch
static int bufp = 0;       // next free position in buf

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: Too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}
