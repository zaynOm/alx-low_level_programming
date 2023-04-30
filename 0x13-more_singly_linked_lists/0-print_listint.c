#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list
 * @h: head of a linked list
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	if (!h)
		return (0);

	printf("%d\n", h->n);

	return (1 + print_listint(h->next));
}
