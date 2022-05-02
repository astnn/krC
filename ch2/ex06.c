#include <stdio.h>
#include <stdint.h>

/* Write a function setbits(x,p,n,y) that returns x with the n bits that begins
at position p set to the rightmost n bits of y, leaving the other bits unchanged
*/

/* To clarify with an example, I am expecting the following behavior:
  7654 3210  - Index no. of the bits
x=0000 0000
y=1111 1111
f=0000 0011
setbits(x,3,2,y) = 0000 1100
*/

/* The print_binary is iwritten by William Whyte
https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
A %b flag is implemented in the latest glibc version (2.35) if available
*/

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

uint32_t setbits(uint32_t x, uint8_t p, uint8_t n, uint32_t y);
void print_binary(uint32_t number) ;

int main(void) {
  uint8_t p, n;
  uint32_t x = 0, y = 3, res;
  
  p=5; n=2;
  res = setbits(x,p,n,y);
  
  printf("setbits(x,%d,%d,y)\n",p,n);
  printf("pos: 76543210\n");
  printf("  x: "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(x));
  printf("  y: "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(y));
  printf("res: "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(res));
  
  // Structure for printing two bytes in binary: 
  //printf("  x: "BYTE_TO_BINARY_PATTERN" "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(x>>8), BYTE_TO_BINARY(x));

  
  return 0;
}

uint32_t setbits(uint32_t x, uint8_t p, uint8_t n, uint32_t y) {
  uint32_t mask;
  uint8_t shift;
  
  mask = ~(~0 << n); // Mask of n ones located to the right
  shift = p-n+1; // Shift to bring leftmost 1 of mask to position p
  mask <<= shift;
  
  y <<= shift;
  y &= mask; // Filter y so only masked values remain
  x &= ~mask; // Filter x so only masked values are removed
  return x | y; // Moved masked values from y to x
}


void print_binary(uint32_t number) {
  if (number >> 1) {
    print_binary(number >> 1);
  }
  putc((number & 1) ? '1' : '0', stdout);
}
