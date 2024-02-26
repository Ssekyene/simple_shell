#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define MAX_PATH_LEN 1024

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
	//printf("First token: %s\nfile_path: %s\nfilename: %s\n", token, file_path, filename);
	if (token == NULL)
	{
		fprintf(stderr, "Failed to tokenize PATH\n");
		return(0);
	}
	while (token != NULL)
	{
		strcat(file_path, filename);
		//printf("file_path before emptied: %s\n", file_path);
		strcpy(full_path, token);
		strcat(full_path, file_path);

		//printf("FullPath: %s\n", full_path);
		file_path[0] = '\0';
		//printf("file_path: %s\n", file_path);
		strcpy(file_path, "/");
		if (stat(full_path, &file_stat) == 0)
		{
			printf("%s\n", full_path);
			p_count++;
		}
		//else
		//	printf("file %s not found\n", full_path); 
		token = strtok(NULL, ":");
	}
	//free(file_path);
	return (p_count);
}

/**
 * main - stat example
 *
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
	//printf("PATH: %s\n", path); 
	i = 1;
	while (av[i])
	{
		n_paths = search_file(av[i], path);
		
		if(n_paths == 0)
			printf("%s: NOT FOUND\n", av[i]);
	
		else
			printf("%u path(s) found for %s\n", n_paths, av[i]);
		//printf("%s:", av[i]);
		//if (stat(av[i], &st) == 0)
		//{
			//printf(" FOUND\n");
		//}
		//else
		//{
			//printf(" NOT FOUND\n");
		//}
		i++;
	}
    return (0);
}
