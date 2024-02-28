#include "main.h"
/**
 * parse_command - searches for the command in the PATH
 *@argv: the string with command to parse
 *@path: string with the PATH value
 *
 *Return: a pointer to absolute command path
 *		or NULL on failure
 */
char *parse_command(char **argv, char *path)
{
	char *file_path;

	file_path  = search_in_file_path(argv[0], path);
	if (file_path == NULL)
	{
		printf("%s: file not found\n", argv[0]);
		return (NULL);
	}
	free(argv[0]);
	strcpy(argv[0], file_path);
	return (argv[0]);
}

/**
 * exec_child_ps - runs a child process
 *@argv: array of the arguments
 */
void exec_child_ps(char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		fprintf(stderr, "Failed to create a child process\n");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		/*run child process*/
		if ((execve(argv[0], argv, NULL)) == -1)
		{
			fprintf(stderr, "Failed to locate command\n");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
		wait(&status);
}

/**
 * execute_command - executes a command
 * @line: the command to execute
 *
 * This function takes a command as input and executes it in a new process.
 * It uses the fork and execve functions to create a new process and execute
 * the command in the child process. The parent process waits for the child
 * process to complete using the wait function.
 */
void execute_command(char *line)
{
	int i;
	char path[MAX_PATH_LEN], **argv;

	argv = split_line(line);
	if (argv == NULL)
	{
		fprintf(stderr, "Error: %s\n", strerror(errno));
		return;
	}
	strcpy(path, getenv("PATH"));

	if (!((**argv == '.' && *(*argv + 1) == '/') || **argv == '/'))
	{
		argv[0] = parse_command(argv, path);
		if (argv[0] == NULL)
			return;
	}
	exec_child_ps(argv);
	if (argv != NULL)
	{
		for (i = 0; argv[i]; i++)
			free(argv[i]);
		free(argv);
	}
}
