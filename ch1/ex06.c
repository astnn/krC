#include <stdio.h>

//Verify that getchar() != EOF is 0 or 1.

int main(void){
  int a;

  printf("Input any char to have it checked against EOF: ");
  a = getchar() != EOF;

  if(a = 1){
    printf("The char is not EOF.\n");
  } else{
    printf("The char is EOF.\n");
  }

  return 0;
}
