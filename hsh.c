#include "main.h"

/**
 * main - reads commands from standard input and executes them
 *
 * Return: 0 on success
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		if (line != NULL)
		{
			free(line);
			line = NULL;
		}

		if (isatty(STDIN_FILENO) == 1)
			printf("# ");

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (feof(stdin))
				break;
			fprintf(stderr, "Error: %s\n", strerror(errno));
			continue;
		}
		else if (strcmp(line, "\n") == 0)
			continue;

		if (line != NULL)
			execute_command(line);
	}

	if (line != NULL)
		free(line);
	return (0);
}

