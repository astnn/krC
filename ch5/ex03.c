#include <stdio.h>

/* Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s */

#define MAXLINE 100

void mystrcat(char *s, char *t);

int main() {
  char str1[MAXLINE] = "abcde", str2[MAXLINE] = "012345";
  
  mystrcat(str1, str2);
  printf("Concatenated string reads \"%s\"\n", str1);
  
  return 0;
}

/* mystrcat: copies the content of the string t to the end of s */
void mystrcat(char *s, char *t) {
  while (*s) { // Run untill '\0' is encountered
    s++;
  }
  
  while (*s++ = *t++) { // Copy content of t to s
  }
  
  return;
}
