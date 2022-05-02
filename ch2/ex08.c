#include <stdio.h>

/* Write a function rightrot(x,n) that returns the value of the integer x
rotated to the right by n bit positions. */

#define BYTE2BITS 8

unsigned int rightrot(unsigned int x, unsigned int n);

int main(void) {
  unsigned int x = 0xF0F0F0F0, res, n;
  
  n = 4;
  res = rightrot(x,n);
  
  printf("rightrot(x,%d)\n",n);
  printf("  x: %.8X\n",x);
  printf("exp: %.8X\n",0x0F0F0F0F);
  printf("res: %.8X\n",res);

  return 0;
}
/* rightrot: Rotate x n places to the right, looping values that are shifted out
to the other side of the integer.*/
unsigned int rightrot(unsigned int x, unsigned int n) {
  unsigned int leftside;
  
  if(n > sizeof(x)*BYTE2BITS) {
    n %= sizeof(x)*BYTE2BITS;
  }
  
  leftside = x << 32-n;
  x >>= n;
  return x|leftside; 
}
