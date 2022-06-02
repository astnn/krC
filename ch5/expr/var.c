#include <stdio.h> // For printf
#include <string.h> // For strlen



#include "var.h"
#include "stack.h" // For pop

static var_t var[MAXVAR]; // Storage for named variables
static int vp = 0;        // Next free variable

void storevar(char s[]) {
  int i = 0;
  int len = 0;
  
  if (vp < MAXVAR-1) {
    if ( (len = strlen(s)) < MAXVARLEN && len > 0) {
      var[vp].val = pop();
      while (s[i] != '\0') {
        var[vp].name[i] = s[i];
        i++;
      }
      s[i] = '\0';
      vp++;
    } else if (len == 0) {
      printf("Error: When using assignment operator '=' it must be directly "
        "followed by a variable name\n");
      }
      else {
      printf("Error: Variable %s exeeds maximal variable length of %d\n",
        s, MAXVARLEN);
    }
  } else {
    printf("Error: Not enough space to store variable %s\n", s);
  }
}

int checkvar(char s[]) {
  for (int i = 0; i < vp; i++) {
    if (strcmp(s, var[i].name) == 0) {
      return i;
    }
  }
    return -1;
}

double getvar(int extvp) {
  return var[extvp].val;
}

void clearvar(void) {
  vp = 0;
}
