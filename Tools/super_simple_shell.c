#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define EXIT "exit"

int main(void)
{
	char *cmd = NULL;
	size_t len = 0;
	ssize_t nread;
	char **argv;
	pid_t pid;
	int status;

	while (1)
	{

		printf("#cisfun$ ");
		nread = getline(&cmd, &len, stdin);
		if (nread == -1)
		{
			fprintf(stderr, "Error reading input\n");
			exit (EXIT_FAILURE);
		}
		//printf("len: %zd\n", nread);
		if (cmd[nread - 1] == '\n')
			cmd[nread - 1] = '\0';

		//printf("Input command: %s\n", cmd);
		int res = strcmp(cmd, EXIT);
		//printf("strcmp result: %d\n", res);
		if (!res)
		{
			free (cmd);
			exit (EXIT_SUCCESS);
		}
		//printf("After strcmp\n");
		argv = (char *[]){cmd, NULL, NULL};

		pid = fork();
		if (pid == -1)
		{
			fprintf(stderr, "Failed to create a child process\n");
			exit (EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if ((execve(argv[0], argv, NULL)) == -1)
			{
				fprintf(stderr,"Failed to run a child process\n");
				exit (EXIT_FAILURE);
			}
			exit (EXIT_SUCCESS);
		}
		else
		{
			wait(&status);
		}
	}



	free(cmd);
	return (0);
}
