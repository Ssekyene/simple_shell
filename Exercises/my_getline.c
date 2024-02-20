#include <stdio.h>
#include <stdlib.h>

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream) {
    char *line = NULL;
    size_t bufsize = 0;
    int c;
    ssize_t chars_read = 0;

    if (lineptr == NULL || n == NULL || stream == NULL) {
        return -1; // Invalid arguments
    }

    if (*lineptr == NULL) {
        bufsize = 0;
    } else {
        bufsize = *n;
    }

    line = (char *)malloc(bufsize);
    if (line == NULL) {
        return -1; // Memory allocation failed
    }

    while ((c = fgetc(stream)) != EOF && c != '\n') 
    {
        if (chars_read + 1 > bufsize) 
	  {
		  if (bufsize == 0)
			  bufsize = 1;
            bufsize *= 2;
            char *new_line = (char *)realloc(line, bufsize);
            if (new_line == NULL) {
                free(line);
                return -1; // Memory reallocation failed
            }
            line = new_line;
        }
        line[chars_read++] = c;
    }

    line[chars_read] = '\0'; // Null-terminate the string

    *lineptr = line;
    *n = bufsize;

    return chars_read;
}

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Enter a line of text: ");
    read = my_getline(&line, &len, stdin);
    if (read != -1) {
        printf("Line read: %s\n", line);
	  printf("Buffer size: %zu\n", len);
    } else {
        printf("Error reading input.\n");
    }

    // Remember to free the allocated memory
    free(line);

    return 0;
}

