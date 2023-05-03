#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list, even if it has a loop
 * @head: Pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *prev, *node = head;
	size_t count = 0;

	if (!head)
		exit(98);

	while (node)
	{
		printf("[%p] %d\n", (void *)node, node->n);
		count++;
		prev = node;
		node = node->next;

		if (node > prev)
		{
			printf("-> [%p] %d\n", (void *)node, node->n);
			break;
		}

	}
	return (count);
}
