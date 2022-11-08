#ifndef SHELL_H
#define SHELL_H

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#define MAX_TERM_LEN 4096

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void prompt(char *str);

#endif /* SHELL_H */
