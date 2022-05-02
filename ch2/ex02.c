/* Write a for loop equivalent to the one below without using && and || 
operators. 
for(i=0; i<lim-1 && (c=getchar()) != '\n' && c!= EOF; i++) {
  s[i] = c;
}
*/


for (i=0; i<lim-1; i++) {
  c = getchar();
  if( c == '\n' ) {
    break;
  }
  else if( c == EOF ) {
    break;
  }
  
  s[i] = c;
}
