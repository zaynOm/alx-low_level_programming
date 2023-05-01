#include "lists.h"

/**
 * free_listint - frees a listint_t list.
 * @head:  pointer to the first node (head)
 */
void free_listint(listint_t *head)
{
	if (!head)
		return;
	free_listint(head->next);
	free(head);
}
