#include <stdio.h>
#include <ctype.h> // For isdigit()
#include "main.h" // For macro NUMBER
#include "getch.h" // For getch() and ungetch() 


/* getop: get next operator or numeric operand */
int getop(char s[]) {
  int i = 0, c;
  
  while ((s[0] = c = getch()) == ' ' || c == '\t' ) {
    // No action
  }
  s[1] = '\0';
  
  if (!isdigit(c) && c != '.' && c != '-') {
    return c; // Not a number
  }

  if (c == '-') { // Handle '-' occurence
    if (!isdigit(c = getch()) && c != '.') { // Subtraction operator
      ungetch(c);
      return '-';
    } else { // Unary operator
      s[++i] = c;
    }
  }

  if (isdigit(c)) { // Collect integer part
    while (isdigit( s[++i] = c = getch() )) {
      // No action
    }
  }

  if (c == '.') { // Collect fraction part
    while (isdigit( s[++i] = c = getch() )) {
      // No action
    }
  }
  s[i] = '\0';
  if (c != EOF && c != ')') {
    ungetch(c);
  }
  return NUMBER;
}
