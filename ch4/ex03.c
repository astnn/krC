/* Given the basic framework it is straightforward to extend the calculator. Add
the modulus operator and provisions for negative numbers. */

/* I have elected to split the code into multiple files as suggested in section
5.5 albeit with a header for each *.c file. The code is presented in the folder
pcalc and can be compiled by calling GNU make from the directory (see Makefile
for further instructions.). The necessary changes to complete ex03 are repeated
below */

/* For the modulus operation augment main with the following switch case */
case '%':
  op2 = pop();
  push( (long) pop() % (long) op2);
  break;
  
/* I consider '-' as the unary operator when it is places together with the
number without spaces, and as the subtraction operator in all other cases.
Can be implemented by add the folowing part to getop() after white spaces have
been passed */

if (!isdigit(c) && c != '.' && c != '-') {
  return c; // Not a number
}

i = 0;
if (c == '-') { // Handle '-' occurence
  if (!isdigit(c = getch()) && c != '.') { // Subtraction operator
    ungetch(c);
    return '-';
  } else { // Unary operator
    s[++i] = c;
  }
}
