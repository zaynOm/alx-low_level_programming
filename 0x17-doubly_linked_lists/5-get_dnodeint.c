#include "lists.h"

/**
 * get_dnodeint_at_index - searches for a node at the list
 * @head: pointer to the head of dlistint_t
 * @index: the index of the node, starting from 0
 *
 * Return: node at @index, or NULL if it does not exists
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	int idx = index;

	while (head && idx--)
		head = head->next;

	return (head);
}
