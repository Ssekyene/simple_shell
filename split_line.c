#include "main.h"

/**
 * split_line - splits line into arguments
 * @line: a pointer to the line
 *
 * Return: a pointer to an array of each argument or
 *		NULL on failure
 */
char **split_line(const char *line)
{
	char **argv;
	char *token;
	int i, arg_len;

	argv = (char **)malloc(MAX_ARGS * sizeof(char *));
	if (argv == NULL)
	{
		fprintf(stderr, "Memory allocation for line failed\n");
		return (NULL);
	}

	i = 0;
	/* Tokenize the line*/
	token = strtok((char *)line, " ");
	while (token != NULL)
	{
		/* Allocate memory for the arguments*/
		arg_len = strlen(token);
		if (arg_len > MAX_ARG_LEN)
		{
			fprintf(stderr, "Argument exceeds reserved space\n");
			return (NULL);
		}
		argv[i] = (char *)malloc((arg_len + 1) * sizeof(char));
		if (argv[i] == NULL)
		{
			fprintf(stderr, "Memory allocation for argument failed\n");
			return (NULL);
		}
		/*Copy the token (argument) to the array*/
		strcpy(argv[i], token);
		i++;

		/* Get the next token*/
		token = strtok(NULL, " ");
	}

	/* Null-terminate the array of arguments*/
	argv[i] = NULL;
	return (argv);
}
