#include "lists.h"

/**
 * listint_len - counts the number of elements in a linked listint_t list.
 * @h: head of a linked list
 *
 * Return: number of elements
 */
size_t listint_len(const listint_t *h)
{
	if (!h)
		return (0);
	return (1 + listint_len(h->next));
}
