#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define MAX_PATH_LEN 1024

/**
 * search_file - finds out whether a file exits in the
 *			PATH
 *@filename: name of the file
 *@path: current path variable
 *
 *Return: Number of file paths the file exits or
 *		0 on failure to find the file
 */
int search_file(const char *filename, char *path)
{
	char full_path[MAX_PATH_LEN];
	char file_path[MAX_PATH_LEN], *token;
	struct stat file_stat;
	int p_count;

	strcpy(full_path, "");
	p_count = 0;
	strcpy(file_path, "/");
	token = strtok(path, ":");
	if (token == NULL)
	{
		fprintf(stderr, "Failed to tokenize PATH\n");
		return(0);
	}
	while (token != NULL)
	{
		strcat(file_path, filename);
		strcpy(full_path, token);
		strcat(full_path, file_path);

		file_path[0] = '\0';
		strcpy(file_path, "/");
		if (stat(full_path, &file_stat) == 0)
		{
			printf("%s\n", full_path);
			p_count++;
		}
		token = strtok(NULL, ":");
	}
	return (p_count);
}

/**
 * main - locates and prints the file paths
 *		for existing files in the PATH
 *@ac: number of commandline arguments
 *@av: the argument list for files to search
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	unsigned int i, n_paths;
	char *path;
   
	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}
	path = getenv("PATH");
	if (path == NULL)
	{
		printf("Error: PATH environment variable not set.\n");
		return 1;
	}
	i = 1;
	while (av[i])
	{
		n_paths = search_file(av[i], path);
		
		if(n_paths == 0)
			printf("%s: NOT FOUND\n", av[i]);
	
		else
			printf("%u path(s) found for %s\n", n_paths, av[i]);
		i++;
	}
    return (0);
}
