#include <stdio.h>
#include <stdint.h>

/* Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted, leaving the others unchanged*/

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

uint32_t invert(uint32_t x,uint8_t p, uint8_t n);

int main(void) {
  uint8_t p, n;
  uint32_t x = 0xF0, res;

  p=5; n=4;
  res = invert(x,p,n);
  
  printf("invert(x,%d,%d)\n",p,n);
  printf("pos: 76543210\n");
  printf("  x: "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(x));
  printf("exp: "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(0xCC));
  printf("res: "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(res));
  
  return 0;
}

uint32_t invert(uint32_t x,uint8_t p, uint8_t n) {
  uint32_t mask, inv;
  uint8_t shift;
  
  mask = ~(~0 << n); // Mask of n ones located to the right
  shift = p-n+1; // Shift to bring leftmost 1 of mask to position p
  mask <<= shift;
  
  inv = ~x & mask; // Inv x and apply mask
  x &= ~mask; // Removed masked bits from x
  return x | inv;
}

void print_binary(uint32_t number) {
  if (number >> 1) {
    print_binary(number >> 1);
  }
  putc((number & 1) ? '1' : '0', stdout);
}
