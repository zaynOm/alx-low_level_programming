#include "lists.h"

/**
 * sum_dlistint - sums all the data (n) of a dlistint_t linked list.
 * @head: pointer to the head of dlistint_t
 *
 * Return: the sum of data, 0 if the list is empty
*/
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
