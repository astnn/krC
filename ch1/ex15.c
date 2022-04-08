#include <stdio.h>

/* Rewrite the temmperature conversion program of ex03 to use a function for
conversion */

// Function declerations:
float fahr2cels(float fahr);

/* main as used in ex03.c. Changes are explicitly marked by comments */
int main(void){
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
    celsius = fahr2cels(fahr); // Changed from ex03.c
    printf("%3.0f \t   %6.1f\n", fahr, celsius);
    fahr += step;
  }

  return 0;
}

/* Fahrenheit to celsius conversion function */
float fahr2cels(float fahr) {

  return (5.0/9.0) * (fahr-32.0);

}
