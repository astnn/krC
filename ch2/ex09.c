#include <stdio.h>

/*x-1 flips the lowest bit of x that is one to a zero, but does not alter the
higher 1's in x. Consequently, when taking x & x-1 the lowest 1 is removed.
Example:
 0111 0000 x
+1111 1111
=0110 1111
&0111 0000 x
=0110 0000
*/

int bitcount(unsigned int x);

int main(void) {
  int x = 0xF;
  
  printf("0x%X has %d ones in it\n", x, bitcount(x));
  printf("0x%X has %d ones in it\n", ~0, bitcount(~0));
  
  return 0;
}

int bitcount(unsigned int x) {
  int i = 0;
  
  while (x) {
    x &= (x-1);
    i++;
  }
  return i;
}
