#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at given index
 * @head: pointer to head of list
 * @index: index of the node to delete
 *
 * Return: 1 if it succeeded, -1 if it failed
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;

	if (!temp)
		return (-1);

	while (temp && index--)
		temp = temp->next;
	if (!temp)
		return (-1);

	if (!temp->prev)
	{
		(*head) = temp->next;
		if (*head)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;

	free(temp);

	return (1);
}
