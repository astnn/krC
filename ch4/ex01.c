#include <stdio.h>

/* Write the function strrindex(s,t), which returns the position of the
rightmost occurence of t in s, or -1 if there is none. */

/***** Recommended execution
Use an augmented version of the testdata provided in K&R. Can be executed in a
terminal as:
gcc ex01.c && cat testdata_ex01.txt | ./a.out
*****/

#define MAXLINE 1000

int kr_getline(char s[], int lim);
int strindex(char s[], char t[]);
int strrindex(char s[], char t[]);
int mystrlen(char s[]) ;

char pattern[] = "ould";  // Patern to search for
//char pattern[] = "34";  // Pattern that is easier to confirm

/* Find all lines matching pattern */
int main(void) {
  char line [MAXLINE];
  int found = 0, ind, len;
  
  printf("Search pattern \"%s\"\n", pattern);
  
  while (kr_getline(line, MAXLINE) > 0) {
    if ( (ind = strrindex(line, pattern)) >= 0 ) {
      len = mystrlen(line);
      printf(">>%.*s<< match at rightmost index %d\n", len-1, line, ind);
      found++;
    }
  }
  return found;
}

/* kr_getline: get line into s, return length K&R original. */
int kr_getline(char s[], int lim) {
  int c, i;
  
  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }
  if (c == '\n') {
    s[i++] = c;
  }
  
  s[i] = '\0';
  return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
  int i, j, k;
  
  for (i = 0; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
      // Do nothing;
    }
    if (k > 0 && t[k] == '\0') {
      return i;
    }
  }
  return -1;
}

/* strindex: return the position of the rightmost occurence of t in s, -1 if
none */
int strrindex(char s[], char t[]) {
  int i, j, k;
  
  for (i = 0; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
      // Do nothing;
    }
    if (k > 0 && t[k] == '\0') {
      return i+k-1;
    }
  }
  return -1;
}

/* mystrlen: returns no. of chars in str excluding the null terminator */
int mystrlen(char s[]) {
  int i;
  
  i = 0;
  while (s[i] != '\0') {
    i++;
  }
  return i;
}
