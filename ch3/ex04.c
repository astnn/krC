#include <stdio.h>
#include <string.h>
#include <limits.h>

/* In two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to 
-(2^{wordsize-1}). Explain why not. Modify it to print that value correctly,
regardles of the machine on which it runs.*/

/* Explanation: The problem is due to the two's complement representation. The
positive numbers include 0 and therefor only runs to (2^{wordsize-1})-1.
The if statement at
if ((sign = n) < 0) {
  n = -n;
}
fails as |n_min| = |n_max| + 1. 
Solution: Instead of making negative values positive, I will make positive
values negative and make the necessary corrections. */

#define MAXLINE 100

void itoa(int n, char s[]);
void itoa2(int n, char s[]);
void reverse(char s[]);

int main(void) {
  char str[MAXLINE];
  
  
  itoa2(INT_MIN, str);
  printf("%d can also be printed as the string %s \n", INT_MIN, str);
  itoa2(INT_MAX, str);
  printf("%d can also be printed as the string %s \n", INT_MAX, str);
  
  
  return 0;
}
/* itoa2: convert n to characters in s. Can handle the whole range of INT_MIN to
INT_MAX */
void itoa2(int n, char s[]) {
  int i, sign;
  
  if ((sign = n) > 0) {
    n = -n;
  }
  i = 0;
  do {
    s[i++] = '0' - (n % 10);
  } while ((n /= 10) < 0 );
  if (sign < 0 ) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
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
