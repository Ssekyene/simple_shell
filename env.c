#include "main.h"

extern char **environ;
void env()
{
	char *env_var;

	env_var = NULL;
	while ((env_var = *environ++) != NULL)
		printf("%s\n", env_var);
	return;
}
