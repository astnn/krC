

#ifndef _VAR_H
#define _VAR_H

#define MAXVAR 26   // Max amount of variables to store
#define MAXVARLEN 6 // Max namelenght of variables

typedef struct {
  char    name[MAXVARLEN];
  double  val;
} var_t;

void storevar(char s[]);
int checkvar(char s[]);
double getvar(int extvp);
void clearvar(void);

#endif /* _VAR_H */
