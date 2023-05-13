#include "lists.h"

/**
 * get_nodeint_at_index - look for a node at the given index
 * @head: pointer to the first node (head)
 * @index: the index of the node, starting at 0
 *
 * Return: returns the nth node of a linked list, NULL if it does not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	while (head && index--)
		head = head->next;

	return (head);
}
