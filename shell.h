#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int _putchar(char c);
int _string(char *str);
char *store(char *path, char *my_arg);
char *_getpath(char *my_arg);

#endif
