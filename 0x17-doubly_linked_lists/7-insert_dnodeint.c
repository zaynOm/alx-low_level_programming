#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @h: pointer to head of list
 * @idx: the index to insert in, starting from 0
 * @n: number to add
 *
 * Return: address of the new element, or NULL if it failed
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *curr = *h;

	if (idx == 0)
		return (add_dnodeint(h, n));

	idx--;
	while (curr && idx--)
		curr = curr->next;

	new = NULL;
	if (curr)
	{
		new = add_dnodeint(&curr->next, n);
		curr->next = new;
		new->prev = curr;
	}


	return (new);
}
