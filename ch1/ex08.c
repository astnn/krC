#include <stdio.h>


/* Write a program to count blanks, tabs, and newlines */
int main(void){
  int c, bl, ta, nl;

  bl=ta=nl=0;

  printf("Enter text to be analysed for blanks, tabs, and newlines. Finish with \"Ctrl+D\":\n");
  while( (c = getchar()) != EOF ) {
    if (c == ' ') {
      ++bl;
    } else if (c == '\t') {
      ++ta;
    } else if (c == '\n') {
      ++nl;
    }

  }
  printf("There were %d blanks, %d tabs, and %d newlines.\n", bl, ta, nl);

  return 0;
}
