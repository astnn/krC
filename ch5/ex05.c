#include <stdio.h>

/* Write versions of the library functions strncpy, strncat, and strncmp, which
operates on at most the first n characters of their argument strings. For
example strncpy(s,t,n) copies at most n characters of t to s.
Full descriptions are in Appendix B */

#define MAXLINE 100
#define SHORTLEN 5

char *mystrncpy(char *s, const char *t, size_t n);
char *mystrncat(char *s, const char *t, size_t n);
int mystrncmp(const char *s, const char *t, size_t n);

int main(void) {
  char str1[MAXLINE] = "This is a long string";
  char str2[SHORTLEN];
  char str3[MAXLINE] = "123";
  char str4[MAXLINE] = "456";
  
  printf("Testing mystrncpy: \n");
  printf("Using a max of %d the result of copying \"%s\" is:\n\"%s\"\n",
    SHORTLEN, str1, mystrncpy(str2, str1, SHORTLEN));
    
  printf("\nTesting mystrncat:\n");
  printf("Using a max of %d concatinating \"%s\" and \"%s\" is:\n", 6, str3, str4);
  printf("%s\n", mystrncat(str3,str4,6));
  
  printf("\nTesting mystrncat:\n");
  printf("Using a max of %d comparing \"%s\" and \"%s\" gives: %d\n", 4, str3, str4, mystrncmp(str3,str4,4));
  printf("Using a max of %d comparing \"%s\" and \"%s\" gives: %d\n", 4, str4, str3, mystrncmp(str4,str3,4));
  printf("Using a max of %d comparing \"%s\" and \"%s\" gives: %d\n", 0, str3, str4, mystrncmp(str3,str4,0));
  printf("Using a max of %d comparing \"%s\" and \"%s\" gives: %d\n", 3, str3, str3, mystrncmp(str3,str3,3));
  
  return 0;
}

/* mystrncpy: Copies at most n characters of t to s. n includes the
null-termination such that it can be called as mystrncpy(s,t,ARRAY_LEN_OF_S)*/
char *mystrncpy(char *s, const char *t, size_t n) {
  size_t i = 0;
  
  while (*(t+i) != '\0' && i < n) {
    *(s+i) = *(t+i);
    i++;
  }
  
  if (i < n) {
    *(s+i) = '\0';
  } else {
    *(s+i-1) = '\0';
  }
  
  return s;
}

/* mystrncat: Concatinate s with t up untill s has the maximal length n. n
includes the null termination. */
char *mystrncat(char *s, const char *t, size_t n) {
  size_t i = 0, j = 0; // i holds s index, j holds t index
  
  while (*(s+i) != '\0' && i++ < n) {
  }
  
  while (*(t+j) != '\0' && i < n) {
    *(s+i++) = *(t+j++);
  }
  
  if (i < n) {
    *(s+i) = '\0';
  } else {
    *(s+i-1) = '\0';
  }
  
  return s;
}

/* mystrncmp: Compares at most n characters of string s to string t;
return <0 if s<t, 0 if s==t, or >0 if s>t */
int mystrncmp(const char *s, const char *t, size_t n) {
  size_t i = 0;
  
  while (*(s+i) != '\0' && *(t+i) != '\0' && *(s+i) == *(t+i) && i < n) {
    i++;
  }
  
  if (i == n) { // Stepped one too far. Everything below was equal
    return 0;
  } else {
    return *(s+i) - *(t+i);
  }
  
}
