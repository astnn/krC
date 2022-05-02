#include <stdio.h>
#include <limits.h>
#include <float.h>

/* Write a program to determine the ranges of char, short, int, and long as well
as float and double.
I have included long double too, although it seems to be handled
somewhat questionably in printf. */

#define SPC 20

void printd(char *type, long int min, long int max);
void printu(char *type, unsigned long int min, unsigned long int max);
void printe(char *type, double min, double max);
void printle(char *type, long double min, long double max);

int main(int argc, char const *argv[]) {
  
  // Print table header
  printf("%-6s %*s %*s\n", "Type", SPC, "Min", SPC, "Max");
  // Print table content
  printd("char", SCHAR_MIN, SCHAR_MAX);
  printd("uchar", 0, UCHAR_MAX);
  printd("short", SHRT_MIN, SHRT_MAX);
  printd("ushort", 0, USHRT_MAX);
  printd("int", INT_MIN, INT_MAX);
  printu("uint", 0, UINT_MAX);
  printd("long", LONG_MIN, LONG_MAX);
  printu("ulong", 0, ULONG_MAX);
  printe("float", FLT_MIN, FLT_MAX);
  printe("double", DBL_MIN, DBL_MAX);
  printle("ldouble", LDBL_MIN, LDBL_MAX);

  return 0;
}

void printd(char *type, long int min, long int max) {
  printf("%-6s %*ld %*ld \n", type, SPC, min, SPC, max);
  return;
}

void printu(char *type, unsigned long int min, unsigned long int max) {
  printf("%-6s %*lu %*lu \n", type, SPC, min, SPC, max);
  return;
}

void printe(char *type, double min, double max) {
  printf("%-6s %*e %*e \n", type, SPC, min, SPC, max);
  return;
}

void printle(char *type, long double min, long double max) {
  printf("%-6s %*Le %*Le \n", type, SPC, min, SPC, max);
  return;
}
