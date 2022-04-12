#include <stdio.h>

/* Write a program to print all input lines that are longer than 50 characters.
Note: Original assignment is to print longer than 80 characters. I redefined to
50 to get hits running the program on its own code, i.e.
"gcc ex17.c && cat ex17.c | ./a.out"*/


#define MAXLINE 1000 // Maximum input line size
#define PRINT_TRESHOLD 50 // Lower threshold for printing line to output

int my_getline(char line[], int maxline);
void printline(char line[]);

int main(void) {
  int len;
  char line[MAXLINE];

  while( (len = my_getline(line, MAXLINE)) > 0 ) {
    if(len > PRINT_TRESHOLD) {
      printline(line);
    }
  }
  return 0;
}

/* my_getLine: read a line into s, return length */
int my_getline(char s[], int lim) {
  int c, i;

  for(i=0; (c = getchar()) != EOF && c != '\n'; i++) {
    if(i < lim-1) { // If there is space in char string, add char
      s[i] = c;
    }
  }
  if(c == '\n') {// If input ends on newline
    if(i < lim-1) { // If we are below the string limit, add \n to output
      s[i] = c;
    }
    i++;
  }

  // Zero terminate string
  if(i < lim) {
    s[i] = '\0';
  } else {
    s[lim-1] = '\0';
  }

  return i; // Return length of line
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
