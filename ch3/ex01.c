#include <stdio.h>
#include <time.h>

/* Our binary search makes two tests inside the loop, when one would suffice
(at the price of more tests outside). Write a version with only one test inside
the loop and measure the difference in runtime.*/

/* Conclusion: The new scheme takes longer. While having a check less makes it
run faster per loop, the downside is that it has to run longer to establish that
a value has been found */

/* The timing bits in main are borrowed from Paul Griffiths
(mail@paulgriffiths.net) as presented here:
https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_3:Exercise_1 */

#define SIZE 1000000

int binsearchNew(int x, int v[], int n); // My version 
int binsearch(int x, int v[], int n); // K&R original

int main(void) {
  int v[SIZE];
  int n, res, i;
  clock_t time_taken;
  
  
  // Create test data
  for (i = 0; i < SIZE; i++) {
    v[i] = i;
  }
  

  /******* New binsearch ******/

  for (i = 0, time_taken = clock(); i < SIZE; i++) {
    res = binsearchNew(v[i], v, SIZE);
  }
  time_taken = clock() - time_taken;
  
  printf("binsearchNew() took %lu clocks (%lu seconds)\n",
    (unsigned long) time_taken, (unsigned long) time_taken / CLOCKS_PER_SEC);


  /******* Original binsearch ******/
  
  for (i = 0, time_taken = clock(); i < SIZE; i++) {
    res = binsearch(v[i], v, SIZE);
  }
  time_taken = clock() - time_taken;
  
  printf("binsearch() took %lu clocks (%lu seconds)\n",
    (unsigned long) time_taken, (unsigned long) time_taken / CLOCKS_PER_SEC);
  
  return 0;
}


/* binsearchNew: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearchNew(int x, int v[], int n) {
  int low, mid, high;
  
  low = 0;
  high = n-1;
  while (low <= high) {
    mid = (low + high)/2;
    if (x <= v[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  
  return (x == v[low]) ? low : -1;
}

/* binsearchNew: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n) {
  int low, mid, high;
  
  low = 0;
  high = n-1;
  while (low <= high) {
    mid = (low + high)/2;
    if (x < v[mid]) {
      high = mid - 1;
    } else if (x > v[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }
  
  return -1;
}
