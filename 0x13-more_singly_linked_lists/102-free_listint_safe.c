#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list.
 * @h: pointer to the first node (head)
 *
 * Return: number of nodes in list
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *temp;

	if (*h > (*h)->next)
	{
		free(*h);
		*h = NULL;
		return (1);
	}
	temp = (*h)->next;
	free(*h);

	return (1 + free_listint_safe(&temp));
}
