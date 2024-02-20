#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct str_list
{
	char *s;
	struct str_list *next;
}strlist_t;

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: double pointer to the head of the list
 * @n: value of the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
strlist_t *add_nodestr_end(strlist_t **head, char *s)
{
	strlist_t *new_node, *test = *head;

	new_node = malloc(sizeof(strlist_t));
	if (new_node == NULL)
		return (NULL);

	new_node->s = s;
	new_node->next = NULL;

	if (test == NULL)
		*head = new_node;
	else
	{
		while (test->next != NULL)
			test = test->next;
		test->next = new_node;
	}

	return (new_node);
}


/**
 * print_listint - prints all the elements of a listint_t list
 * @h: pointer to head of linked list
 * Return: number of nodes
 */
size_t *copy_strlist_to_arr(const strlist_t *h, char ***arr)
{
	size_t count = 0;

	while (h != NULL)
	{
		//printf("%d\n", h->n);
		*(*arr + count) = h->s;

		h = h->next;
		count++;
	}
	**arr = '\0';

	return (count);
}


/**
 * free_listint - frees a listint_t list
 * @head: pointer to the head of the list
 */
void free_strlist(strlist_t *head)
{
	strlist_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int main(int ac, char **av)
{
	char *token;
	char **arr;
	size_t n_str, i;
	strlist_t *head;
	size_t num_nodes;

	head = NULL;
	if (ac != 3)
	{
		printf("Error: Not more than 2 arguments\n");
		printf("Usage: string delimeter\n");
		exit (EXIT_FAILURE);
	}
	token = strtok(av[1], av[2]);
	if (token == NULL)
	{
		fprintf(stderr, "Failed to tokenize the string");
		exit (EXIT_FAILURE);
	}
	n_str = 0;

	while(token != NULL)
	{
		n_str += 1;
		//printf("%s\n", token);
		head = add_nodestr_end(&head, token);
		token = strtok(NULL, av[2]);
	}
	arr = malloc((sizeof(char *) * n_str) + 1);
	num_nodes = copy_strlist_to_arr(head, &arr);
	if (num_nodes != n_str)
	{
		fprintf(stderr, "Error in copying strings");
		exit (EXIT_FAILURE);
	}
	for (i = 0; arr[i]; i++)
	{
		printf("%s\n", arr[i]);
	}
	free_strlist(head);
	return (0);
}
