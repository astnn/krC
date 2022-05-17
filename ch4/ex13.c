#include <stdio.h>
#include <string.h>

/* Write a recursive version of the function reverse(s), which reverses the
string s in place */

/* I have included the solution by gbar as reverse3, as I find it to be an
elegant use of recursion:
https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_4:Exercise_13#Solution_by_gbar
*/

#define MAXLINE 100

void reverse(char s[]);
void reverse2(char s[], int left, int right);
void reverse3(char s[]);
void swap(char s[], int i, int j);

int main(void) {
  char str[MAXLINE] = "This is a test string.";
  
  printf("Original string is: \"%s\"\n", str );
  reverse2(str, 0, (int) strlen(str)-1);
  printf("Reversed string is: \"%s\"\n", str );
  reverse3(str);
  printf("Double reversed string is: \"%s\"\n", str );
  
  return 0;
}

/* reverse2: reverse the string s between the indices left and right. To reverse
complete string use it as reverse(str, 0, strlen(str)-1). I dislike this
solution, as I would expect a reverse function to only take the string as an
argument */
void reverse2(char s[], int left, int right) {
  
  if (left >= right) {
    return;
  }
  
  swap(s, left++, right--);
  reverse2(s, left, right);
  
  return;
}

void swap(char s[], int i, int j) {
  char c;
  
  c = s[i];
  s[i] = s[j];
  s[j] = c;
  
  return;
}

/* reverse3: reverse the string s. By gbar. See introduction comment for
reference */
void reverse3(char s[]) {
  static int i = 0, j = 0;
  
  if (s[i] != '\0') {
    int c = s[i++];
    reverse3(s);
    s[j++] = c;
  }
  
  // At end of recursion, reset static variables
  if (i == j) {
    i = j = 0;
  }
  return;
}

/* reverse: reverse the string s. K&R original. */
void reverse(char s[]) {
  int c, i, j;
  
  for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
