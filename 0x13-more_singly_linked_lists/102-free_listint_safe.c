#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list.
 * @h: pointer to the first node (head)
 *
 * Return: number of nodes in list
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *temp = *h;
	size_t count = 1;

	if (!h || !(*h))
		return (0);

	if (*h <= (*h)->next)
	{
		*h = NULL;
		free(temp);
	}
	else
	{
		*h = (*h)->next;
		free(temp);
		count += free_listint_safe(h);
	}

	return (count);
}
