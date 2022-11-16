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

#define NOT_FOUND "(simple_shell): " RED "No such file or directory\n" RESET

#include <signal.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int _exec(char *command, char *args[]);
int _isCommand(char *cmd);
int not(int boolean);
void parse(char *line, char **argv);
int prompt(char *str);
void _splitstr(char *str, char **args);
void stripln(char *str, char *command);

#endif /* SHELL_H */
