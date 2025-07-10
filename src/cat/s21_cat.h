#include <stdio.h>
#ifndef S21_CAT_H
#define S21_CAT_H

typedef struct options_s {
  int b, E, v, n, s, T, err;
} opt_t;

void parser(int, char **, opt_t *);
void outprint(FILE *, opt_t *, int *);

#endif