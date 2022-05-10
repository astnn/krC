#include <stdio.h>
#include <ctype.h> // For isspace() and similar

/* Extend atof to handle scientifc notation on the form "123.45e-6" where a 
floating-point number may be followed by e or E and an optionally signed 
exponent */

#define MAXLINE 100

double atof2(char s[]);

int main(void) {
  char line[] = "123.45e-2";
  
  printf("String \"%s\" is interpreted as double %f\n", line, atof2(line) );
  
  return 0;
}

/* atof2: covert string s to double, alowing for scientific notation 123.45e-6*/
double atof2(char s[]) {
  double val, power;
  int i, sign, signpow, exp;
  
  // Skip whitespaces
  for (i = 0; isspace(s[i]); i++) {
    // No action.
  }
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '-' || s[i] == '+') {
    i++;
  }
  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
  }
  if (s[i] == '.') {
    i++;
  }
  // After dot
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  if (s[i] == 'e' || s[i] == 'E') {
    i++;
  }
  // Handle scientific notation
  signpow = (s[i] == '-') ? -1 : 1;
  if (s[i] == '-' || s[i] == '+') {
    i++;
  }
  for (exp = 0; isdigit(s[i]); i++ ) {
    exp = 10 * exp + (s[i] - '0');
  }
  
  if (signpow > 0) {
    while (exp > 0) {
      power /= 10;
      exp--;
    }
  } else {
    while (exp > 0) {
      power *= 10;
      exp--;
    }
  }
  
  return sign * val / power;
}
