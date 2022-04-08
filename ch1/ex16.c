#include <stdio.h>

/* Revise the main routine of the longest-line program so it will correctly
print the length of arbitrarily long input lines, and as much as possible of the
text */

#define MAXLINE 40 // Maximum input line size

//Function declerations
int my_getline(char line[], int maxline); /* Note that getline() is alread
  defined in stdio.h and is not useable */
void copy(char to[], char from[]);


int main(void) {
  int len; // Current line lenght
  int max; // Maximum length seen so far
  char line[MAXLINE]; // Current input line
  char longest[MAXLINE]; // Longest line encountered

  max = 0;
  while( (len = my_getline(line,MAXLINE)) > 0) {
    if(len > max) {
      max = len;
      copy(longest,line);
    }
  }
  if(max > 0) { // There was a line
    printf("Longest line has length: %d\n", max);
    if(max <= MAXLINE) {
      printf("The line content is:\n%s",longest);
    } else {
      printf("The maximal line length to be displayed is %d. The truncated line reads:\n%s\n", MAXLINE, longest);
    }
  }
  return 0;
}

/* getline: read a line into s, return length */
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
  if(i < lim-1) {
    s[i] = '\0';
  } else {
    s[lim-1] = '\0';
  }

  return i; // Return length of line
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0'){
    i++;
  }
}
