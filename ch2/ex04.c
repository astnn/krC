#include <stdio.h>

/* Write and alternative version of squeeze(s1, s2) that deletes each character
in s1 that matches any character in s2*/

#define MAXLINE 100

void squeezeAlt(char s1[], const char s2[]);

int main(void) {
  char test[MAXLINE] = "This here is a test string", filter[MAXLINE] = "eg";
  
  printf("Removing the characters '%s' from the test string '%s' gives:\n",filter,test);
  squeezeAlt(test,filter);
  printf("%s\n",test);

  return 0;
}

/* squeezeAlt: Deletes any character in s1 that matches one from s2.*/
void squeezeAlt(char s1[], const char s2[]) {
  int i, j, k;
  
  for (i=k=0; s1[i] != '\0'; i++) {
    for (j=0; s2[j] != '\0'; j++) {
      if( s1[i] == s2[j]) {
        break;
      }
    }
    // Did the filter run without matches?
    if (s2[j] == '\0') {
      s1[k++] = s1[i];
    }
  }
  s1[k] = '\0';
}
