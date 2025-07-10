#include "s21_cat.h"

#include <getopt.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: cat [option] [filename]\n");
  } else {
    opt_t options = {
        0, 0, 0, 0, 0, 0, 0,
    };
    int index = 1;
    parser(argc, argv, &options);
    if (options.err != 1) {
      for (int i = 1; i < argc; ++i) {
        if (argv[i][0] == '-') continue;
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
          printf("cat: %s: No such file or directory", argv[i]);
          exit(1);
        }
        outprint(fp, &options, &index);
        fclose(fp);
      }
    }
  }

  return 0;
}
void parser(int argc, char **argv, opt_t *options) {
  char *short_options = "beEvnstT";
  struct option long_options[] = {{"number-nonblank", 0, NULL, 'b'},
                                  {"number", 0, NULL, 'n'},
                                  {"squeeze-blank", 0, NULL, 's'},
                                  {0, 0, 0, 0}};

  int c;
  while ((c = getopt_long(argc, argv, short_options, long_options, NULL)) !=
         -1) {
    switch (c) {
      case 'b':
        options->b = 1;
        break;

      case 'e':
        options->v = 1;
        options->E = 1;
        break;

      case 'E':
        options->E = 1;
        break;

      case 'v':
        options->v = 1;
        break;

      case 'n':
        options->n = 1;
        break;

      case 's':
        options->s = 1;
        break;

      case 't':
        options->v = 1;
        options->T = 1;
        break;

      case 'T':
        options->T = 1;
        break;
      default:
        options->err = 1;
        break;
    }
  }
}
void outprint(FILE *fp, opt_t *options, int *index) {
  char pre = '\n';
  int line_print = 0;
  int c = fgetc(fp);
  while (c != EOF) {
    if (!(options->s == 1 && pre == '\n' && c == '\n' && line_print)) {
      if (pre == '\n' && c == '\n')
        line_print = 1;
      else
        line_print = 0;
      if ((options->b == 1 && c != '\0' && c != '\n') && pre == '\n') {
        printf("%6d\t", (*index)++);
      }
      if ((options->n == 1 && options->b != 1) && pre == '\n') {
        printf("%6d\t", (*index)++);
      }
      if (options->E == 1 && c == '\n') printf("$");
      if (options->T == 1 && c == '\t') {
        printf("^");
        c = c + 64;
      }
      if (options->v == 1 && c >= 0 && c <= 31 && c != '\n' && c != '\t') {
        printf("^");
        c = c + 64;
      }
      if (c == 127 && options->v == 1)
        printf("^?");
      else
        fputc(c, stdout);
    }
    pre = c;

    c = fgetc(fp);
  }
}
