#include <stdio.h>

/* Celsius to Fahrenheit table */
int main(void){
  float cels, fahr;
  int lower, upper, step;

  lower=-20;
  upper = 120;
  step = 20;

  printf("Celsius Fahrenheit\n");

  cels = lower;
  while (cels <= upper) {
    fahr = 9.0/5.0*cels+32.0;
    printf("%3.0f %12.1f\n", cels, fahr);
    cels += step;
  }

  return 0;
}
