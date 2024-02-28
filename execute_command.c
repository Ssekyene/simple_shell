#include "main.h"

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
	char **argv;
	int status, i;
	pid_t pid;
	char *cmd;

	argv = split_line(line);
	if (argv == NULL)
	{
		fprintf(stderr, "Error: %s\n", strerror(errno));
		return;
	}
	cmd = argv[0];
	if ((**argv != '.' && *(*argv + 1) != '/') || **argv != '/')
	{
		argv[0] = search_in_file_path(argv[0]);
		if (argv[0] == NULL)
		{
			printf("%s: not found\n", cmd);
			return;
		}
	}
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
	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
}
