#include <stdio.h>

/* Declaration of the environ global variable */
extern char **environ;

int main() {
    /* Iterate through the environment variables */
    for (char **env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }

    return 0;
}

