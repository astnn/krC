#include <stdio.h>

/* Write the function strend(s,t), which returns 1 if the string t occurs at the
end of the string s, and zero otherwise */

#define MAXLINE 100

int strend(char *s, char *t);

int main(void) {
  char str1[MAXLINE] = "hej med dig", str2[MAXLINE] = "";
  
  printf("str1 = \"%s\"\n", str1);
  printf("str2 = \"%s\"\n", str2);
  
  if (strend(str1, str2)) {
    printf("str2 is at the end of str1\n");
  } else {
    printf("str2 is not at the end of str1\n");
  }
  
  return 0;
}

/* stringend: Returns 1 if the string t occurs at the end of s and 0 otherwise
Notice that if t is the empty string t="" the function returns 1. */
int strend(char *s, char *t) {
  int i, j; // Indices to keep track of how many times s and t are incremented
  i = j = 0;
  
  while (*s) { // Go to end of s
    s++;
    i++;
  }
  
  while (*t) { // Go to end of t
    t++;
    j++;
  }
  
  if (j > i) { // If t is longer than s
    return 0;
  }
  
  while(j-- >= 0) {
    if (*s-- != *t--) {
      return 0;
    }
  }
  
  return 1;
}
