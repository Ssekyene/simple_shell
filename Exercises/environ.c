#include <stdio.h>

/* Declaration of the environ global variable */
extern char **environ;

int main()
{
	char **env;

    /* Iterate through the environment variables */
    for (env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }

    return 0;
}

