#include <stdio.h>

/* Define a macro swap(t,x,y) that interchanges two arguments of type t.
(Block structure will help.) */

/* To get a feeling of the necessity of using the block, I have added the unused
variable temp to main. If the braces {} in the macro are removed we will get a
compile error due to temp being declared multiple times in the same scope */

#define swap(t,x,y) {t temp = x; x = y; y = temp;}

int main(void) {
  int x = 1, y = 2, temp = 3;
  char * a = "str1", * b = "str2";
  
  printf("x = %d, y = %d\n", x, y);
  swap(int, x, y);
  printf("After swap(int,x,y): x = %d, y = %d\n", x, y);
  
  printf("a = \"%s\", b = \"%s\"\n", a, b);
  swap(char *, a, b);
  printf("After swap(char *,a,b): a = \"%s\", b = \"%s\"\n", a, b);
  
  return 0;
}
