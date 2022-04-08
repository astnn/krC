#include <stdio.h>

/* Print Fahrenheit-Celcius table with header for fahr = 0, 20, ... 300;
    floating point version.*/
main(void){
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  //Print header
  printf("Fahrenheit Celsius\n");

  //Construct an print table
  fahr = lower;
  while(fahr <= upper){
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f \t   %6.1f\n", fahr, celsius);
    fahr += step;
  }
}
