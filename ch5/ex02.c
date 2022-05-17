#include <stdio.h>
#include <ctype.h> // For isdigit, isspace

/* Write getfloat, the floating point analog of getint. What type does getfloat
return as its function value? */

/* Answer: Get float returns an int. The read floating point value is loaded
into the input pointer, while the return value is a status signalling how the
function terminated */

/* Test either by running ./a.out without any input, or as:
"gcc ex02.c && echo "-1.2 3 .4 -.5" | ./a.out" in a terminal to test EOF behavor
*/

int getfloat(float *pn);
int getch(void);
void ungetch(int c);

int main(void) {
  int status;
  float res;
  
  while ((status = getfloat(&res)) != 0 && status != EOF) {
    printf("Input value is %f\n", res);
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
int getfloat(float *pn) {
  int c, sign, pow;
  
  while (isspace(c = getch())) {
    // Skip whitespaces
  }
  
  if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
    ungetch(c); // it's not a number
    return 0;
  }
  sign = (c == '-' ? -1 : 1);
  if (c == '-' || c == '+') {
    c = getch();
    if (!isdigit(c) && c != '.' && c != EOF) {
      ungetch(c);
      return 0;
    }
  }
  // Handle integer part
  for (*pn = 0.0; isdigit(c); c = getch()) {
    *pn = 10.0 * *pn + (c - '0');
  }
  // Collect fraction
  pow = 0;
  if (c == '.') {
    c = getchar();
    for ( ; isdigit(c); c = getch(), pow++) {
      *pn = 10.0 * *pn + (c - '0');
    }
  }

  while (pow > 0) {
    *pn /= 10.0;
    pow--;
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
