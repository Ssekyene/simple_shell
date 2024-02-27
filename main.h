#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N_ARGS 2

void execute_command(char *line);
int parse_line(char *line, ssize_t *nread);

#endif /*!MAIN_H*/
