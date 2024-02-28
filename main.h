#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_ARG_LEN 20

void execute_command(char *line);
int parse_line(char *line, ssize_t *nread);
char **split_line(const char *line);
#endif /*!MAIN_H*/
