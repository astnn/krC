#include <stdio.h>
#include <string.h> // For strlen in the reverse help function

/* Adapt the ideas of printd to write a recursive version of itoa; that is,
convert an integer into a string by calling a recursive routine */

/* The usage of the "calls" check in itoa3 is inspired by gbar's solution:
https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_4:Exercise_12*/

#define MAXLINE 100

void itoa(int n, char s[]);
void itoa3(int n, char s[]);
void reverse(char s[]);

int main(void) {
  char str[MAXLINE];
  int val[] = {15, -1, 999, -0};
  
  for (int i = 0; i < 4; i++) {
    itoa3(val[i],str);
    printf("%d is interpreted as the string \"%s\"\n",val[i], str);
  }
  
  
  return 0;
}

/* itoa3: converts n to characters in s. Based on recursiion.
    Fails at n = INT_MIN. For inspiration on how to correct this, see itoa2 in
    ch3/ex04.c */
void itoa3(int n, char s[]) {
  static int i = 0, calls = 0;
  calls++; // Used to reset i to zero at end of recursive calls
  
  if (n < 0) {
    s[i++] = '-';
    n = -n;
  }
  
  if (n/10) {
    itoa3(n/10, s);
  }
  s[i++] = n % 10 + '0';
  s[i] = '\0';
  
  calls--;
  
  // Reset i to zero at end of recursion.
  if (calls == 0) {
    i = 0;
  }
}


/* itoa: convert n to characters in s K&R original*/

void itoa(int n, char s[]) {
  int i, sign;
  
  if ((sign = n) < 0) {
    n = -n;
  }
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0 );
  if (sign < 0 ) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int c, i, j;
  
  for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
