#include <stdio.h>
#include <ctype.h>

/* Write the function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value.
The allowable digits are 0 through 9, a through f, and A through F.*/

long htoi(char str[]);

int main(void) {
  printf("%s corresponds to the integer %ld\n","0xF",htoi("0xF"));
  printf("%s corresponds to the integer %ld\n","1f",htoi("1f"));
  printf("%s corresponds to the integer %ld\n","0XFF",htoi("0XFF"));
  printf("%s corresponds to the integer %ld\n","0xa",htoi("0xa"));
  
  return 0;
}

long htoi(char str[]) {
  int i = 0, c;
  long out = 0;
  
  if (str[0] == '0' && tolower(str[1]) == 'x') {
    i = 2;
  }
  
  for (; str[i] != '\n' && str[i] != '\0'; i++) {
    c = tolower(str[i]);
    if (isdigit(c)) {
      out = (out << 4) + c - '0';
    }
    else if (c >= 'a' && c <= 'f') {
      out = (out << 4) + 10 + c - 'a';
    }
    else {
      return -1;
    }
  }
  return out;
}
