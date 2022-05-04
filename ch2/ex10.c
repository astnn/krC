#include <stdio.h>

/* Rewrite the function lower, which converts upper case letters to lower cases,
with a conditional expression instead of if-else */

int lower(int c);
int lower2(int c);

int main(void) {
  int i;
  char input[50] = "THIS is A test STRING.", output[50];
  
  i = 0;
  while(input[i] != '\0') {
    output[i] = lower2(input[i]);
    i++;
  }
  
  printf("Input string: '%s'\n", input);
  printf("Output string after applying lower2(): '%s'\n", output);
  
  return 0;
}


/* lower: convert c to lower case; ASCII only - Original version */
int lower(int c) {
  if (c >= 'A' && c <= 'Z') {
    return c + 'a' - 'A';
  } else {
    return c;
  }
}

/* lower: convert c to lower case; ASCII only - My version */
int lower2(int c) {
  return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
