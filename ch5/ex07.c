#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Rewrite readlines to store lines in an array supplied by main rather than
calling alloc to maintain storage. How much faster is the program? */

/* The restriction "in an array supplied by main" proves to be somewhat
bothersome. The simplest implementation would be to make a global storage
similar to the lineptr storage, but in this case it is not supplied by main.
Alternatively both storage and a storage position has to be passed to all
functions every time.
I have gone with a luke compromise. Storage is supplied by main, the storage
position is a static variable in the store function. */

/* I have not mady any benchmark to test implementation speed. Inspiration might
be taken from ch3 ex01.c */

#define MAXLINES 5000 // max #lines to be sorted
#define MAXLEN 1000 // max length of any input line
#define STORAGELEN MAXLINES*MAXLEN // static storage to store lines in

char *lineptr[MAXLINES]; /* Pointers to the text lines */

int readlines(char *lineptr[], int nlines);
int readlines_alt(char *lineptr[], int maxlines, char *storage);
void writelines(char *lineptr[], int nlines);

void myqsort(char *lineptr[], int left, int right);

/* Sort input lines*/
int main(void) {
  int nlines; /* Number of input lines read */
  char storage[STORAGELEN]; // Static storage for strings
  
  if ( (nlines = readlines_alt(lineptr, MAXLINES, storage)) >= 0) {
    myqsort(lineptr, 0, nlines-1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("Error: Input to big to sort\n");
    return 1;
  }
}



int pgetline(char *, int); // pgetline from ex06.c
char * store(int len, char * storage);

/* store: stores input data to storage */
char * store(int len, char * storage) {
  static int sp = 0; // Next free element in storage
  char *p;
  
  if (sp + len - 1 < STORAGELEN) {
    p = storage + sp;
    sp += len;
    return p;
  } else {
    return NULL;
  }
}

/* readlines: read input lines and store the to dynamic memory. K&R original */
int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];
  
  nlines = 0;
  while ((len = pgetline(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || (p = malloc(len)) == NULL ) {
      return -1;
    } else {
      line[len-1] = '\0'; // Replace newline with null terminator
      strcpy(p,line);
      lineptr[nlines++] = p;
    }
  }
  
  return nlines;
}

/* readlines_alt: read input lines and store them to static memory */
int readlines_alt(char *lineptr[], int maxlines, char *storage) {
  int len, nlines;
  char *p, line[MAXLEN];
  
  nlines = 0;
  while ((len = pgetline(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || (p = store(len, storage)) == NULL ) {
      return -1;
    } else {
      line[len-1] = '\0'; // Replace newline with null terminator
      strcpy(p,line);
      lineptr[nlines++] = p;
    }
  }
  
  return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
  while (nlines-- > 0) {
    printf("%s\n", *lineptr++);
  }
}

/* myqsort: sort v[left]...v[right] into increasing order */
void myqsort(char *v[], int left, int right) {
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right) { // Do nothing if array contains fewer than 2 elements
    return;
  }
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i <= right; i++) {
    if (strcmp(v[i], v[left]) < 0) {
      swap(v, ++last, i);
    }
  }
  swap(v, left, last);
  myqsort(v, left, last-1);
  myqsort(v, last+1, right);
}

/* swap: interchanges v[i] and v[j] */
void swap(char *v[], int i, int j) {
  char *temp;
  
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
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
