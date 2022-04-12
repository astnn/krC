#include <stdio.h>

/* Write a program to remove trailing blanks and tabs from each line of input,
and to delete entierely blank lines.*/

/* This second version is heavily inspired by the elegant solution of
Jonathan Soto P as presented at
https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_1:Exercise_18 */

/* A test input is located in testData_ex18.txt. Recommended procedure is to run
it as "gcc ex18.c && cat testData_ex18.txt | ./a.out" in a terminal. */

#define MAXLINE 1000 // Maximum input line size

int getFilteredLine(char line[], int maxline);
void printline(char line[]);

int main(void) {
  int len;
  char line[MAXLINE];

  while( (len = getFilteredLine(line, MAXLINE)) > 0 ) {
    if(len > 1) {
      printf("%s",line);
    }
  }

  return 0;
}

/* getFilteredLine: read a line into s, removing trailing blanks and tabs.
Return lenght of line.
If line starts with EOL, return len=0. If line is only blank, return l=1 for the
newline*/
int getFilteredLine(char s[], int lim) {
  int c, i, j;

  i = j = 0;

  for(i=0; (c = getchar()) != EOF && c != '\n'; i++) {
    if(i < lim-1) { // If there is space in char string, add char
      s[i] = c;
    }
    if(c != ' ' && c != '\t') {
      j = i+1;
    }
  }
  if(c == '\n' && j++ < lim) {
    s[j-1] = c;
  }

  s[j < lim ? j : lim-1] = '\0';

  return j; // Return length of line without trailing blanks
}
