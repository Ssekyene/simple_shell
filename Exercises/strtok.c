#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

/**
 * splitString - splits a string 
 * @str: a pointer to a string
 * @del: a delimeter specifying splitting regions
 *
 * Return: a pointer to an array of each word or 
 		1 on failure
 */
char **splitString(const char *str, char *del)
{
	char **words;
	char *token;
	int i;

	if (strlen(del) != 1)
	{
		fprintf(stderr, "Error: Invalid delimeter\n");
		exit (EXIT_FAILURE);
	}
    words = (char **)malloc(MAX_WORDS * sizeof(char *));
    if (words == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

   
    i = 0;

    /* Tokenize the string*/
    token = strtok((char *)str, del);
    while (token != NULL) {
        /* Allocate memory for the word*/
        words[i] = (char *)malloc((strlen(token) + 1) * sizeof(char));
        if (words[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        /*Copy the token (word) to the array*/
        strcpy(words[i], token);
        i++;

        /* Get the next token*/
        token = strtok(NULL, del);
    }

    /* Null-terminate the array of words*/
    words[i] = NULL;

    return words;
}

int main(int ac, char **av) 
{
	int i;
	char **words;

	if (ac != 3)
	{
		fprintf(stderr, "Error: Invalid number of arguments\n");
		exit (EXIT_FAILURE);
	}
    /* Split the string into words*/
    words = splitString(av[1], av[2]);

    /* Print the array of words*/
    for (i = 0; words[i] != NULL; i++) {
        printf("%s\n", words[i]);
        /* Don't forget to free memory allocated for each word*/
        free(words[i]);
    }

    /* Free memory allocated for the array of words*/
    free(words);

    return 0;
}

