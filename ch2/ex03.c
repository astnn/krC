#include <stdio.h>
#include <ctype.h>

/* Write the function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value.
The allowable digits are 0 through 9, a through f, and A through F.*/

#define MAXLINE 100

int my_getline(char s[], int lim);
long htoi(char str[], int len);

int main(void) {
  int len, c;
  long val;
  char line[MAXLINE];
  
  while( (len = my_getline(line, MAXLINE)) > 0) {
    val = htoi(line, len);
    if (val != -1) {
      printf("%ld\n", val);
    } else {
      printf("Error. '%.*s' could not be converted to hexvalue.\n", len-1, line);
    }
  }
  
  return 0;
}



long htoi(char str[], int len) {
  int i = 0, offset = 0, n_hex = 0;
  long out = 0;
  
  if(len > 2 && str[0] == '0' && tolower(str[1]) == 'x') {
    offset = 2;
  }
  
  for (i = len-1; i >= offset; i--, n_hex++) {
    if (str[i] == '\n') {
      n_hex--;
      continue;
    }
    else if (isdigit(str[i])) {
      out += (str[i] - '0') << 4*(n_hex);
    }else if (tolower(str[i]) >= 'a' && tolower(str[i]) <= 'f') {
      out += (10 + str[i] - 'a') << 4*(n_hex);
    }else {
      return -1;
    }
  }
  return out;
}

/* getline: read a line into s, return length */
int my_getline(char s[], int lim) {
  int c, i;

  for(i=0; (c = getchar()) != EOF && c != '\n'; i++) {
    if(i < lim-1) { // If there is space in char string, add char
      s[i] = c;
    }
  }
  if(c == '\n') {// If input ends on newline
    if(i < lim-1) { // If we are below the string limit, add \n to output
      s[i] = c;
    }
    i++;
  }

  // Zero terminate string
  if(i < lim) {
    s[i] = '\0';
  } else {
    s[lim-1] = '\0';
  }

  return i; // Return length of line
}
