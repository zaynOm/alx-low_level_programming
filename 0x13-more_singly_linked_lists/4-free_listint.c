#include "lists.h"

/**
 */
void free_listint(listint_t *head)
{
	if (!head->next)
		return;

	free_listint(head->next);

	free(head->next);
}
