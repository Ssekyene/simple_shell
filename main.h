#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_ARGS 10
#define MAX_ARG_LEN 20
#define MAX_PATH_LEN 1024

void execute_command(char *line);
int parse_line(char *line, ssize_t *nread);
char **split_line(const char *line);
char *search_in_file_path(const char *filename, char *path);
#endif /*!MAIN_H*/
