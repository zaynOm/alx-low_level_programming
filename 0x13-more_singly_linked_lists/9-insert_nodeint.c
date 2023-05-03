#include "lists.h"

/**
 * insert_nodeint_at_index -  inserts a new node at a given position.
 * @head: pointer to the first node (head)
 * @idx: index of the list where to add a new node. Index starts at 0
 * @n: data to add to new node
 *
 * Return: the address of the new node, or NULL if it failed
 * or if it's not possible to add the new node at index idx.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *temp;

	if (!head)
		return (NULL);

	new = malloc(sizeof(listint_t));
	temp = *head;

	new->n = n;
	if (idx == 0)
	{
		new->next = temp;
		*head = new;
		return (new);
	}

	while (temp && 1 < idx--)
		temp = temp->next;

	if (temp && new)
	{
		new->next = temp->next;
		temp->next = new;
		return (new);
	}
	return (NULL);
}

