#include <stdio.h>
#include <ctype.h> // For isdigit()
#include "main.h" // For macro NUMBER
#include "getch.h" // For getch() and ungetch() 


/* getop: get next operator or numeric operand */
int getop(char s[]) {
  int i = 0, c;
  
  // Skip white spaces
  while ((s[0] = c = getch()) == ' ' || c == '\t' ) {
    // No action
  }
  s[1] = '\0';
  
  // Check if an opereator excluding '-' and '='
  if (!isdigit(c) && !isalpha(c) && c != '.' && c != '-' && c != '=') {
    return c; // Not a number
  }
  
  // Check if '=' operator
  if (c == '=') {
    while (isalpha( s[i++] = c = getch() )) {
      // No action
    }
    s[i-1] = '\0';
    if (c != EOF) {
      ungetch(c);
    }
    return '=';
  }
  
  // Check if a named command
  if (isalpha(c)) { // Collect named command
    while (isalpha( s[++i] = c = getch() )) {
      // No action
    }
    s[i] = '\0';
    if (c != EOF) {
      ungetch(c);
    }
    return NAME;
  }

  // Handle '-' occurence
  if (c == '-') {
    if (!isdigit(c = getch()) && c != '.') { // Subtraction operator
      ungetch(c);
      return '-';
    } else { // Unary operator
      s[++i] = c;
    }
  }

  // Handle numbers
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
  if (c != EOF) {
    ungetch(c);
  }
  return NUMBER;
}
