#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: pointer to the first node (head)
 *
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow);
		}
	}

	return (NULL);
}
/**
 * print_listint_safe - Prints a listint_t linked list, even if it has a loop
 * @head: Pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	listint_t *loop;
	size_t count = 0;
	int isloop = 1;

	if (!head)
		return (0);

	loop = find_listint_loop((listint_t *)head);
	for (isloop = 1; (head != loop || isloop) && head;)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++;
		if (head == loop)
			isloop = 0;
		head = head->next;
	}
	if (loop)
		printf("-> [%p] %d\n", (void *)head, head->n);
	return (count);
}
