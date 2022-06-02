#include <stdio.h>

#define BUFSIZE 20

static char buf[BUFSIZE]; // FIFO buffer
static int bufpin = 0;
static int bufpout = 0;


/* readarguments: Read input arguments from CLI and store them to buffer space
sepperated. Stores newline as last character */
void readarguments(int argc, char *argv[]) {
  int i, c;
  
  while (--argc > 0) {
    argv++;
    i = 0;
    while ( (c = (*argv)[i++]) && bufpin < BUFSIZE) {
      buf[bufpin++] = c;
    }
    if (bufpin < BUFSIZE) {
      buf[bufpin++] = ' ';
    }
    
  }
  buf[bufpin-1] = '\n';
  if (bufpin == BUFSIZE && ( (*argv)[i-1] != '\0' || argc > 0 )) {
    printf("readarguments: Error! Input buffer too small to handle all inputs."
    " Consider increasing buffer from its current size of %d\n", BUFSIZE);
  }
  
  return;
}

/* getarg: returns next stored input arguments. FIFO buffer */
int getarg(void) {
  if (bufpout < bufpin) {
    return buf[bufpout++];
  } else {
    return EOF;
  }
}
