#include <stdio.h>

/* Print Fahrenheit-Celcius table in reverse order from 300 to 0 in reverse
    by stepts of 20*/

int main(void){
  float fahr, cels;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  //Print header
  printf("Fahrenheit Celsius\n");

  //Loop in reverse order and construct table
  for(fahr = upper; fahr>= lower; fahr-=step){
    cels = (5.0/9.0)*(fahr-32.0);
    printf("%3.0f %12.1f\n", fahr, cels);
  }
  return 0;
}
