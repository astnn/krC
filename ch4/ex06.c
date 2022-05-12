
/* Add commands for handling variables. Add a variable for the most resent
printed letter */

/*See ch4/pcalc for the full source-code for the polish calculator*/

/* Solution:
Added var.c for storing an array of 26 custom variables having a name and a
value. The top of the stack is assigned to variable NAME by entering "=NAME".
The actonname() function in main is modified to search for variables if
an unknown command is received as text input.
The last printed value can be retrieved by the variable name "r".
*/
