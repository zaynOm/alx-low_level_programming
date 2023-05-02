#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index
 * @head: pointer to the first node (head)
 * @index: index of the node that should be deleted. Index starts at 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *to_delete, *temp = *head;

	if (index == 0 && temp)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}
	while (temp && --index)
		temp = temp->next;

	if (temp && temp->next)
	{
		to_delete = temp->next;
		temp->next = to_delete->next;
		free(to_delete);
		return (1);
	}
	return (-1);
}
