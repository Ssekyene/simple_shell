#include "main.h"
/**
 * search_in_file_path - finds out whether a file
 *			exits in the PATH
 *@filename: name of the file
 *@path: file path
 *Return: a pointer to path of the file or
 *		NULL on failure
 */
char *search_in_file_path(const char *filename, char *path)
{
	char full_path[MAX_PATH_LEN];
	char file_path[MAX_PATH_LEN], *token;
	struct stat file_stat;
	char *found_path;

	if (path == NULL)
	{
		printf("Error: PATH environment variable not set.\n");
		return (NULL);
	}
	strcpy(full_path, "");
	strcpy(file_path, "/");
	token = strtok(path, ":");
	if (token == NULL)
	{
		fprintf(stderr, "Failed to tokenize PATH\n");
		return (NULL);
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
			found_path = full_path;
			return (found_path);
		}
		token = strtok(NULL, ":");
	}
	return (NULL);
}
