#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list.
 * @h: pointer to the first node (head)
 *
 * Return: number of nodes in list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 1;

	if (!head)
		return (0);

	if (head < head->next)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++;
		printf("-> [%p] %d\n", (void *)head->next, head->next->n);
	}
	else
	{
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		count += print_listint_safe(head);
	}

	return (count);
}
