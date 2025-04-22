#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;
char *_getenv(const char *name);
char **split_line(const char *str, const char *delim);
void free_tokens(char **tokens);
int execve_command(char *command_path, char **argv, char **environ);
char *find_command_path(char *command);
int handle_builtin(char **tokens);

#endif
