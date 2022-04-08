#include <stdio.h>

/* Write a program to print a histogram of the lengths of words in its input. */

// Used to keep state on if the program is in or outside of a word.
#define OUT 0
#define IN 1

#define MAXWORDLENGTH 3
#define MAX_HIST_LENGTH 20

int main(void) {
  int c, wl, state;
  int wlcount[MAXWORDLENGTH+1];

  //Initialise variables
  state = OUT;
  wl = 0;
  for(int i = 0; i < MAXWORDLENGTH+1; i++) {
    wlcount[i] = 0;
  }

  printf("Enter input to analyse for word length. Exit with \"Ctrl+D\"\n");
  while( (c=getchar()) != EOF ) {
    if(c == ' ' || c == '\n' || c == '\t') {
      if(state == IN && wl <= MAXWORDLENGTH) {
        wlcount[wl-1]++;
      } else if (state == IN && wl > MAXWORDLENGTH) {
        wlcount[MAXWORDLENGTH]++;
      }

      wl = 0;
      state = OUT;
    } else {
      wl++;
      state = IN;
    }
  }

  printf("\nWl\tCount\t Histogram");
  for(int i = 0; i<MAXWORDLENGTH; i++) {
    printf("\n%2d %7d\t", i+1,wlcount[i]);
    for(int j = 0; j < wlcount[i] && j < MAX_HIST_LENGTH; j++) {
      printf("-");
    }
  }
  printf("\n>%d %7d\t", MAXWORDLENGTH, wlcount[MAXWORDLENGTH]);
  for(int j = 0; j < wlcount[MAXWORDLENGTH] && j < MAX_HIST_LENGTH; j++) {
    printf("-");
  }
  printf("\n");

}
