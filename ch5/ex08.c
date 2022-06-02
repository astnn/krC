#include <stdio.h>

/* There is no error checking in day_of_year or month_day. Remedy this defect */

static char daytab [2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *pmonth, int *pday);


int main(void) {
  int dayofyear, month, day;
  
  // Check legal inputs:
  printf("Checking functions for day_of_year(2000, 2, 29), month_day(2000, 60)\n");
  if ( (dayofyear = day_of_year(2000, 2, 29)) < 1 || month_day(2000, 60,&month, &day) != 0) {
    printf("Caught an error!\n");
  } else {
    printf("Success. day_of_year(2000, 2, 29) = %d, month_day(2000, 60): month = %d, day = %d\n", dayofyear, month, day);
  }
  
  // Check illegal inputs:
  
  printf("Checking function day_of_year(2000, 2, 29)\n");
  if (dayofyear = day_of_year(2001, 2, 29) < 1) {
    printf("Caught an error!\n");
  } else {
    printf("Success. day_of_year(2000, 2, 29) = %d\n", dayofyear);
  }
  
  printf("Checking function month_day(2001, 366)\n");
  if (month_day(2001, 366,&month, &day) != 0) {
    printf("Caught an error!\n");
  } else {
    printf("Success. month_day(2001, 366): month = %d, day = %d\n", month, day);
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
  } else if (day < 1 || day > daytab[leap][month]) {
    return -1;
  }
  
  for (i = 1; i < month; i++) {
    day += daytab[leap][i];
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
  
  for (i = 1; yearday > daytab[leap][i]; i++) {
    yearday -= daytab[leap][i];
  }
  
  *pmonth = i;
  *pday = yearday;
  
  return 0;
}
