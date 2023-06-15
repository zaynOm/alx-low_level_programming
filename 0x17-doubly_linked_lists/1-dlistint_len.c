#include "lists.h"

/**
 * dlistint_len - counts number of elements in a linked dlistint_t list
 * @h: head of dlistint_t
 *
 * Return: the number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t len = 0;

	while (h)
	{
		len++;
		h = h->next;
	}

	return (len);
}
