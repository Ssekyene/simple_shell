#include <stdio.h>
#include <string.h>

/* Declaration of the environ global variable */
extern char **environ;

char *_getenv(const char *name)
{
	char **env;

    /* Iterate through the environment variables */
    for (env = environ; *env != NULL; env++) {
        /* Check if the current environment variable matches the name */
        if (strncmp(*env, name, strlen(name)) == 0 && *(*env + strlen(name)) == '=') {
            /* Return the value of the environment variable */
            return *env + strlen(name) + 1;
        }
    }

    /* Return NULL if the environment variable is not found */
    return NULL;
}

int main() {
    /* Example usage */
    char *path = _getenv("PATH");
    if (path != NULL) {
        printf("Value of PATH: %s\n", path);
    } else {
        printf("PATH environment variable not found.\n");
    }

    return 0;
}

