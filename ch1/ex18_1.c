#include <stdio.h>

/* Write a program to remove trailing blanks and tabs from each line of input,
and to delete entierely blank lines.*/

/* A test input is located in testData_ex18.txt. Recommended procedure is to run
it as "gcc ex18.c && cat testData_ex18.txt | ./a.out" in a terminal. */

#define MAXLINE 1000 // Maximum input line size

int getFilteredLine(char line[], int maxline);
void printline(char line[]);

int main(void) {
  int len;
  char line[MAXLINE];

  while( (len = getFilteredLine(line, MAXLINE)) >= 0 ) {
    if(len > 0) {
      printline(line);
    }
  }

  return 0;
}

/* getFilteredLine: read a line into s, removing trailing blanks and tabs.
If line is blank return 0. If line is EOL, return -1 */
int getFilteredLine(char s[], int lim) {
  int c, i, lastNonBlank;

  lastNonBlank = -1;

  for(i=0; (c = getchar()) != EOF && c != '\n'; i++) {
    if(i < lim-1) { // If there is space in char string, add char
      s[i] = c;
    }
    if(c != ' ' && c != '\t') {
      lastNonBlank = i;
    }
  }
  if(c == '\n') {// If input ends on newline
    if(i < lim-1) { // If we are below the string limit, add \n to output
      s[i] = c;
    }
    i++;
  }

  if(i == 0) {// If EOF as first char
    return -1;
  } else if (lastNonBlank == -1) {// If no non-blank where encountered
    return 0;
  }


  if(c == '\n' && lastNonBlank < lim-1) { /* If line ends on newline, and there
    is room to include it in the output */
    lastNonBlank++;
    s[lastNonBlank] = '\n';
  }

  // Zero terminate string
  if(lastNonBlank < lim-1) {
    s[lastNonBlank+1] = '\0';
  } else {
    s[lim-1] = '\0';
  }

  return lastNonBlank; // Return length of line without trailing blanks
}

/* printLine: Prints the input string.
Assumes input is a zero terminated string as receive from my_getLine. */
void printline(char line[]){
  int i=0;

  while(line[i] != '\0') {
    putchar(line[i]);
    i++;
  }
  putchar(line[i]);
}
