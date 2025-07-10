#ifndef GREP_H
#define GREP_H
#include <regex.h>

typedef struct arguments {
  int e, i, v, c, l, n, h, s, f, o;
  char pattern[2048];

  int len_pattern;
} arguments;

void pattern_add(arguments *arg, char *pattern);
void pattern_from_file(arguments *arg, char *filepath);
arguments arguments_parser(int argc, char *argv[]);
void output_line(char *line, int n);
void print_match(regex_t *re, char *line);
void output(arguments arg, int argc, char *argv[]);

#endif