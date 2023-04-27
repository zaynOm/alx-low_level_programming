#include "lists.h"

/**
 * list_len - countes the number of elements in a linked list recursively
 * @h: pointer to the first node
 *
 * Return: the length of a linked list
 */
size_t list_len(const list_t *h)
{
	if (!h)
		return (0);

	return (list_len(h->next) + 1);
}
