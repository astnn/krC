#include <stdio.h>
#include <string.h> // strcmp
#include <ctype.h> // isnum
#include <stdlib.h> // atoi

#define USAGE_FMT  "%s [-n NUMLINES]\n"
#define DFLT_NLINES 10
#define TRUE 1

struct linebuffer {
  char buffer[BUFSIZ];
  size_t nlines;
  size_t nbytes;
  struct linebuffer *next;
};
typedef struct linebuffer LBUFFER;



void usage(const char *progname);


// look into fread vs read
/* Implementing a slightly modified version of the pipe_lines function of GNU
tail for reading stdin:
https://github.com/coreutils/coreutils/blob/master/src/tail.c: 627
*/

int main(int argc, char const *argv[]) {
  size_t nlines;
  size_t total_lines = 0;
  size_t n_read;
  
  LBUFFER *first, *last, *tmp;
  
  
  /* Handle input arguments */
  if (argc == 1) {
    nlines = DFLT_NLINES;
  } else if (argc > 2 && strcmp(argv[1],"-n") == 0 && isdigit(argv[2])) {
    nlines = atoi(argv[2]);
  } else {
    usage(argv[0]);
    return 1;
  }
  
  first = last = (LBUFFER *) malloc(sizeof(LBUFFER) );
  first->nlines = 0;
  first->nbytes = 0;
  first->next = NULL;
  tmp = (LBUFFER *) malloc(sizeof(LBUFFER) );
  
  while (TRUE) {
    
    
    n_read = fread(tmp->buffer, sizeof(char), BUFSIZ, stdin);
    if (n_read == 0) {
      break;
    }
    tmp->nlines = 0;
    tmp->nbytes = n_read;
    tmp->next = NULL;
    
    char const *p = tmp->buffer;
    char const *buffer_end = tmp->buffer + n_read;
    
    while (p = (char *) memchr(p, '\n', buffer_end - p)) {
      p++;
      tmp->nlines++;
    }
    total_lines += tmp->nlines;
    
    /* If there is space in last buffer, read tmp data into that one, and re-use
    in the next itteration */
    if (BUFSIZ > last->nbytes + tmp->nbytes) {
      memcpy(last->buffer[last->nbytes], tmp->buffer, tmp->nbytes);
      last->nbytes += tmp->nbytes;
      last->nlines += tmp->nlines;
    } else {
      /* If there are enough lines without first, re-use the memory for the next
      tmp. Else malloc a new block. */
      last = last->next = tmp;
      if (total_lines - first->nlines > nlines) {
        tmp = first;
        total_lines -= first->nlines;
        first = first->next;
      } else {
        tmp = (LBUFFER *) malloc(sizeof(LBUFFER) );
      }
    }
  }
  
  free(tmp);
  
  
  
  /* Pseudocode:
  Initialise first, last, allocate tmp
  WHILE:
    Initialise tmp
    Read stdin into tmp
    Count newlines just read
    increment total lines
      IF space in last buffer, append to that one
      ELSE
        IF enough lines are read, reuse first LBUFFER
        ELSE malloc new at end of list
    Free tmp
    -->Check for empty list
    Check if stdin ends on newline or not. Disregard empty newline
    Skip unneeded buffers
    Goto first line to be printed and print rest
    Free buffers
    
  */
  
  /* Free memory from linked list */
  while (first) {
    tmp = first;
    first = first->next;
    free(tmp);
  }
  
  return 0;
}

void usage(const char *progname) {
  printf(USAGE_FMT, progname);
  
  return;
}
