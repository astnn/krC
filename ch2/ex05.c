#include <stdio.h>

/* Write the function any(s1,s2), which returns the first location in the string
s1 where any character from the string s2 occurs, or -1 if s1 contains no
characters from s2.*/

#define MAXLINE 100

int any(char s1[], const char s2[]);

int main(void) {
  char test[MAXLINE] = "This here is a test string", filter[MAXLINE] = "ti";
  
  printf("The index of the first occurence of any of the characters in '%s' in '%s' is %d\n", filter, test, any(test,filter));
  
  return 0;
}

/* any: Returns the first location in the string s1 where any character
from the string s2 occurs, or -1 if s1 contains no characters from s2.*/
int any(char s1[], const char s2[]) {
  int i, j;
  
  for (i=0; s1[i] != '\0'; i++) {
    for (j=0; s2[j] != '\0'; j++) {
      if( s1[i] == s2[j]) {
        return i;
      }
    }
  }
  return -1;
}
