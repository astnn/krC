#include <stdio.h>
#include <string.h> // For strlen

/* Write a version of itoa that accepts three arguments instead of two. The
third argument is a minimum field width; the converted number must be padded
with blanks on the leftmif necessary to make it wide enough. */

#define MAXLINE 100

void itoa3(int n, char s[], unsigned short width);
void reverse(char s[]);

int main(void) {
  char str[MAXLINE];
  
  itoa3(-32, str, 5);
  printf("%d with minimum width %d is >%s<\n", -32, 5, str);
  itoa3(100, str, 1);
  printf("%d with minimum width %d is >%s<\n", 100,1,str);
  itoa3(22, str, 10);
  printf("%d with minimum width %d is >%s<\n", 22,10,str);
  
  return 0;
}

/* itoa3: convert n to characters in s with a minimum width of w. Output is 
left-padded with blanks if necessary. Can handle the whole range of INT_MIN to
INT_MAX */
void itoa3(int n, char s[], unsigned short w) {
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
  
  // Zero pad with blanks if applicable
  while(i < w) {
    s[i++] = ' ';
  }
  
  s[i] = '\0';
  reverse(s);
}

/* reverse: Reverse string s. K&R original */
void reverse(char s[]) {
  int c, i, j;
  
  for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
