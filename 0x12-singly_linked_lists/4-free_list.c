#include "lists.h"

/**
 * free_list - frees a linked list (list_t)
 * @head: pointer to the first node (head)
 */

void free_list(list_t *head)
{
	list_t *temp;

	if (!head->next)
		return;
	temp = head->next;
	free(head->str);
	free(head);
	free_list(temp);
}
