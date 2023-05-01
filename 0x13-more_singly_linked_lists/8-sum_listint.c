#include "lists.h"

/**
 * sum_listint - sums all the data (n) of a listint_t linked list.
 * @head: pointer to the first node (head)
 *
 * Return:  the sum of all the data (n) of a listint_t linked list,
 * (0) if the list is empty
 */
int sum_listint(listint_t *head)
{
	if (!head)
		return (0);

	return (head->n + sum_listint(head->next));
}
