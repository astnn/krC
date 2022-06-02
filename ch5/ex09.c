#include <stdio.h>

/* Rewrite the routines day_of_year and month_day with pointers instead of
indexing */

/* I am in doubt of what is meant by this exercise. One interpretation is that
indexing on the form "array[x][y]"" should not be used. Another interpretation
is that instead of using a multidimensional array such as daytab, one should use
an array of pointers. I don't really see the point of either implementation, so
but have arbitrarily elected to solve the first */

/* NOTE: 
*(*(daytab+leap) + month) can be understood as follows:
(daytab + leap) gives a pointer to either "Array 0" or "Array 1" of daytab
*(daytab + leap) de-ereference the pointer to get the array
*(*(daytab+leap) + month) de-reference the array at index month
*/

static char daytab [2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},  // Array 0
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}   // Array 1
};

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *pmonth, int *pday);


int main(void) {
  int dayofyear, month, day;
  int i = 0;
  
  // Check legal inputs:
  printf("Checking functions for day_of_year(2000, 2, 29), month_day(2000, 60)\n");
  if ( (dayofyear = day_of_year(2000, 2, 29)) < 1 || month_day(2000, 60,&month, &day) != 0) {
    printf("Caught an error!\n");
  } else {
    printf("Success. day_of_year(2000, 2, 29) = %d, month_day(2000, 60): month = %d, day = %d\n", dayofyear, month, day);
  }
  
  return 0;
}

/* day_ofyear: set day of year from month & day. If illegal month or day is
given, returns -1 */
int day_of_year(int year, int month, int day) {
  int i, leap;
  
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  
  /* Input validation */
  if (month < 1 || month > 12) {
    return -1;
  } else if (day < 1 || day > *(*(daytab+leap)+month) ) {
    return -1;
  }
  
  for (i = 1; i < month; i++) {
    day += *(*(daytab+leap) + i);
  }
  
  return day;
}

/* month_day: set month, day from day of year. Returns 0 if input is valid, or
-1 for invalid yearday */
int month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;
  
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  
  /* Input validation */
  if (yearday < 1 || yearday > 365 + leap ) {
    return -1;
  }
  
  for (i = 1; yearday > *(*(daytab+leap) + i); i++) {
    yearday -= *(*(daytab+leap) + i);
  }
  
  *pmonth = i;
  *pday = yearday;
  
  return 0;
}
