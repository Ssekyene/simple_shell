#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - executes the command ls -l /tmp
 *		in 5 different child processes
 * Return: 0 on Success
 */
int main()
{
	pid_t pid, my_pid;
	int status, i;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	
	i = 0;

	while (i < 5)
	{
		printf("Before fork %d\n", i + 1);
		pid = fork();
		if (pid == -1)
		{
			perror("Error: Failed to create a child process");
			return (1);
		}
		my_pid = getpid();

		if (pid == 0)
		{
			printf("Child is running...\nPID[%u]\n\n", my_pid);
			sleep(1);
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		
		}
		else
		{
			printf("Parent is running...\nPPID[%u]\n\n", my_pid);
			printf("Go to child[%d]\n\n", i + 1);
			wait(&status);
			printf("Parent call[%d]: Done!\n\n", ++i);
		}
			
	}
	return (0);
}
