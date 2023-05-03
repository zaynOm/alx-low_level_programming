#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list, even if it has a loop
 * @head: Pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tortoise = head, *hare = head;
	size_t count = 0;

	while (hare && hare->next)
	{
		printf("[%p] %d\n", (void *)tortoise, tortoise->n);
		count++;

		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			printf("[%p] %d\n", (void *)tortoise, tortoise->n);
			printf("-> [%p] %d\n", (void *)hare->next, hare->next->n);
			count += 2;
			break;
		}
	}

	if (!hare || !hare->next)
	{
		while (tortoise)
		{
			printf("[%p] %d\n", (void *)tortoise, tortoise->n);
			count++;
			tortoise = tortoise->next;
		}
	}

	return (count);
}

