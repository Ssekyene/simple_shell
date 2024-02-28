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
	int res;

	while (1)
	{
		if (line != NULL)
		{
			free(line);
			line = NULL;
		}
		if (isatty(STDIN_FILENO) == 1)
			printf("($) ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			fprintf(stderr, "Error: %s\n", strerror(errno));
			continue;
		}
		res = parse_line(line, &nread);
		if (res == 1)
			continue;
		else if (res == -1)
			break;
		if (line != NULL)
			execute_command(line);
	}

	if (line != NULL)
		free(line);
	return (0);
}

/**
 *parse_line - resolves the new line character in
 *			the line
 *@line: line from standard input
 *@nread: a pointer to number of read characters
 *
 *Return: 1 if a line has only a newline charater
 *		0 on replacing the trailing new line charater
 *		-1 for exiting
 */
int parse_line(char *line, ssize_t *nread)
{
	if (strcmp(line, "\n") == 0)
		return (1);

	if (line[*nread - 1] == '\n')
		line[*nread - 1] = '\0';
	if (strncmp(line, "exit", 4) == 0)
		return (-1);
	return (0);
}
