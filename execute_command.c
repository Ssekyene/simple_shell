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
	char *argv[N_ARGS];
	int status;
	pid_t pid;

	argv[0] = line;
	argv[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		fprintf(stderr, "Failed to create a child process\n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if ((execve(argv[0], argv, NULL)) == -1)
		{
			fprintf(stderr, "Failed to run a child process\n");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(&status);
	}
}
