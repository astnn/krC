#include <stdio.h>

/* Rewrite appropiate programs from earlier chapters and exercises with pointers
instead of array indexing. Good possiblities include getline (Chapters 1 and 4),
atoi, itoa, and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and
strindex and getop (Chapter 4) */

/* I elected to not revist all the previous exercises, and have only rewritten
getline as presented below. */

#define MAXLINE 100

int pgetline(char *s, int lim);

int main(void) {
  char str[MAXLINE];
  
  while (pgetline(str,10) > 0) {
    printf("%s", str);
  }
  printf("\nEND OF MESSAGE\n");
  
  return 0;
}

int pgetline(char *s, int lim) {
  int c;
  char *sstart = s;
  
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
    *s++ = c;
  }
  if (c == '\n') {
    *s++ = c;
  }
  
  *s = '\0';
  return s - sstart;
}
