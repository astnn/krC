#include <stdio.h>
#include <ctype.h> // For isdigit and similar

/* Write a function expand(s1,s2), that expands shorthand notation like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for
letters of either case and didgits, and be prepared to handle cases like a-b-c
and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literaly. */

#define MAXLINE 1000

int expand(char s1[], char s2[], int max);

int main(void) {
  char input[MAXLINE] = "a-z A-C 9-0 c-a a-D 1-A -abc- b-";
  char output[MAXLINE];
  int len;
  
  len = expand(input, output, MAXLINE);
  
  if (len < 0) {
    printf("Warning: The output of expand() was truncated because the maximum "
    "string length was reached.\n");
  }
  
  printf(">>>INPUT<<<\n%s\n", input);
  printf(">>>OUTPUT<<<\n%s\n", output);
  
  return 0;
}

/* expand: Expands shorthand notation like a-z in the string s1 into the
equivalent complete list abc...xyz in s2. Takes both numbers and alphabetics of
both cases, so long as each type on either side of the dash is the same.
Bi-directional c-a becomes cba. */
int expand(char s1[], char s2[], int max) {
  char cur, prev, next;
  int i, j, k;
  int dir;
  
  prev = '\0';
  i = j = 0;
  while ( (cur = s1[i++]) != '\0' && j < max) {
    if ( cur != '-' ) {
      s2[j++] = cur;
      prev = cur;
    } else {
      next = s1[i++];
      // Check if number or alphabetic, and that they are same type
      if (isalnum(prev) && isalnum(next) && (isalpha(prev) == isalpha(next)) ) {
        // Check if number, or alphabetic of same case
        if (isdigit(prev) || islower(prev) == islower(next)) {
          dir = (prev < next) ? 1 : -1;
          
          for (k = prev + dir; k != next + dir && j < max; k += dir) {
            s2[j++] = k;
          }
          
          prev = k + dir;
        } else {
          s2[j++] = cur;
          s2[j++] = next;
          prev = next;
        }
      } else {
        s2[j++] = cur;
        s2[j++] = next;
      }
    }
  }
  
  // Zero terminate output string
  if(j < max) {
    s2[j] = '\0';
    return j;
  } else {
    s2[max-1] = '\0';
    return -1;
  }
  
}
