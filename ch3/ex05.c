#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* Write the function itob(n,s,b), that converts the interger n into a base b
character representation in the string s. In particular, itob(n,s,16) formats
n as a hexademicam integer in s. */

#define MAXLINE 100

char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int itob(uint32_t n, char s[], int b);
void reverse(char s[]);


int main(void) {
  char str[MAXLINE];
  int inp = 0xFF, base = 2;
  
  itob(inp, str, base);
  
  printf("%X has a base-%d value of %s\n", inp, base, str);
  
  return 0;
}

/* itob: Converts inter n into a base b representation in the string s */
int itob(uint32_t n, char s[], int b) {
  size_t maxbase, i;
  
  maxbase = sizeof(charset)/sizeof(*charset)-1;
  
  // If maxbase does not fit charset, or base to low, exit failure
  if(b > maxbase || b < 2) {
    return -1;
  }
  
  i = 0;
  do {
    s[i++] = charset[n % b];
  } while ((n /= b) > 0 );
  
  s[i] = '\0';
  reverse(s);
  
  return 0;
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
