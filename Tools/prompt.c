#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("$ ");
	nread = getline(&line, &len, stdin);
	if (nread != -1)
		printf("Input command: %s", line);
	else
		fprintf(stderr,"Error reading input\n");
	free(line);
	return (0);

}
