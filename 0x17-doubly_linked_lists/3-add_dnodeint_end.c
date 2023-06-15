#include "lists.h"

/**
 * add_dnodeint_end - adding a node at the end of list
 * @head: pointer to the head of dlistint_t
 * @n: number to add
 *
 * Return: address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *curr = (*head);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	while (curr && curr->next)
		curr = curr->next;

	if (curr)
		curr->next = new;
	else
		*head = new;
	new->n = n;
	new->prev = curr;
	new->next = NULL;

	return (new);
}
