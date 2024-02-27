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
	char *argv[10] = {NULL};
	char *token;
	pid_t pid;
	int i = 0, status;

	/* Tokenize the input to remove the newline character */
	token = strtok(line, " \n");
	if (token == NULL)
		return;
	while (token != NULL && i < 9)
	{
		argv[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}

	if (strcmp(argv[0], "cd") == 0)
	{
		cd_command(argv);
		return;
	}
	else if (strcmp(argv[0], "setenv") == 0)
	{
		if (argv[1] && argv[2])
		{
			if (setenv(argv[1], argv[2], 1) == -1)
				fprintf(stderr, "Error: setenv failed\n");
		}
		else
			fprintf(stderr, "Error: setenv requires two arguments\n");
		return;
	}
	else if (strcmp(argv[0], "unsetenv") == 0)
	{
		if (argv[1])
		{
			if (unsetenv(argv[1]) == -1)
				fprintf(stderr, "Error: unsetenv failed\n");
		}
		else
			fprintf(stderr, "Error: unsetenv requires one argument\n");
		return;
	}
	status = check_exit(argv);
	if (status != -1)
	{
		free(line);
		exit(status);
	}

	if (check_env(argv) == 0)
		return;

	if (access(argv[0], X_OK) != 0)
		get_path(argv[0]);

	if (argv[0] == NULL)
		return;

	/* Create a new process */
	pid = fork();
	if (pid == -1)
		perror("Error: fork failed\n");
	else if (pid == 0)
	{
		/* Execute the command in the child process */
		execve(argv[0], argv, NULL);
		exit(EXIT_FAILURE);
	}
	else
		/* Wait for the child process to complete */
		wait(NULL);

}
