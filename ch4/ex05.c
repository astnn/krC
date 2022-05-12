
/* Add acess to library functions like sin, exp, and pow. */

/*See ch4/pcalc for the full source-code for the polish calculator*/

/* Solution:
Added a check for named commands to getop where the name is loaded into a string
and a NAME flag is returned to main.
Main the switches on the NAME flags and calls the actonname() function, that
checks for predefined strings, e.g. "sin", and calls the appropiate math
function and stack manipulation.
*/
