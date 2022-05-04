#include <stdio.h>

/* Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s.
Use a switch. Write a function for the other direction as well, converting
escape sequences into real characters. */

#define MAXLINE 36

void escape(char s[], char t[], int max);
void unescape(char s[], char t[], int max);

int main(void) {
  char input[MAXLINE] = "First line: \tTEXT\nSecond line \\s";
  char output[MAXLINE], restored[MAXLINE];
  
  escape(output, input, MAXLINE);
  unescape(restored, output, MAXLINE);
  
  printf(">>>Input string<<<\n%s\n\n", input);
  printf(">>>Output string<<<:\n%s\n\n", output);
  printf(">>>Restored string<<<:\n%s\n\n", restored);
  
  return 0;
}
/* escape: copies the string t to s converting characters like newline and tab
into visible escape sequences like \n and \t.
Perferably should return an integer with information on wether max was reached
before all data could be copied over */
void escape(char s[], char t[], int max) {
  int i, j;
  char c;
  
  i = j = 0;
  while ( (c = t[i++]) != '\0' && j < max -2) { // Have to be able to print two chars and \0
    switch (c) {
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        break;
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        break;
      case '\\':
        s[j++] = '\\';
        s[j++] = '\\';
        break;
      default:
        s[j++] = c;
        break;
    }
  }
  s[j] = '\0';
  
  return;
}
/* unescape: copies the string t to s converting visible escape sequences like
\n and \t into characters like newline and tab */
void unescape(char s[], char t[], int max) {
  int i, j;
  char c;
  
  i = j = 0;
  while ( (c = t[i++]) != '\0' && i < max) {
    if ( c == '\\' && t[i] != '\0') {
      switch (c = t[i++]) {
        case 'n':
          s[j++] = '\n';
          break;
        case 't':
          s[j++] = '\t';
          break;
        case '\\':
          s[j++] = '\\';
        break;
        default:
          s[j++] = '\\';
          s[j++] = c;
          break;
      }
    } else {
      s[j++] = c;
    }
    
  }
  s[j] = '\0';
  
  return;
}
