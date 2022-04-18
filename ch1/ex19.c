#include <stdio.h>

/* Write a function reverse(s) that reverse the character string s. Use it to
write a program that reverse its input a line at a time. */

#define MAXLINE 1000 // Maximum input line size

int my_getline(char s[], int lim);
void reverse(char s[], int len);

int main(void) {
  int len;
  char line[MAXLINE];

  while( (len = my_getline(line, MAXLINE)) > 0) {
    reverse(line, len);
    printf("%s", line);
  }

  return 0;
}

/* reverse: Reverse the input string. If string ends on \n, the \n is not
reversed.*/
void reverse(char s[], int len) {
  int i, ri;
  char ch;

if (s[len-1] == '\n') { // Ends in newline
  for(i = 0; i < (len-1)/2; i++) {
    ri = len-2-i;
    ch = s[i];
    s[i] = s[ri];
    s[ri] = ch;
  }
} else { // No newline
  for(i = 0; i < len/2; i++) {
    ri = len-1-i;
    ch = s[i];
    s[i] = s[ri];
    s[ri] = ch;
  }
}

  
}

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
