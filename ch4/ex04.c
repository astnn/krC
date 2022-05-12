/* Add commands to print the top element of the stack without popping, to
to duplicate it, and to swap the top two elements. Add a command to clear the
stack. */

/*See ch4/pcalc for the full source-code for the polish calculator*/

/* Solution: The stack operations are defined in stack.c, and four extra
commands have been added to the main switch-statement to activate them. The
commands are:
?: View top of stack
#: Duplicate top of stack
\: Swap two topmost stack entries
!: Clear stack
*/
