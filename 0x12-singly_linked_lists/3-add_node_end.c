#include "lists.h"

/**
 * _strlen - counts the length of a string
 * @str: string
 *
 * Return: length of @str
 */
int _strlen(char *str)
{
	if (!*str)
		return (0);
	return (_strlen(str + 1) + 1);
}

/**
 * add_helper - adds a node at the end of a linked list using recursion
 * @head: double pointer to the first node
 * @new: node to add at the end
 * @str: string
 *
 * Return: address of the new element
 */
list_t *add_helper(list_t **head, list_t *new, char *str)
{
	if (!*head)
	{
		new->str = strdup(str);
		new->len = _strlen(str);
		new->next = NULL;
		*head = new;
		return (*head);
	}
	return (add_helper(&(*head)->next, new, str));
}

/**
 * add_node_end - adds a node at the end of a linked list (list_t)
 * @head: double pointer to the first node
 * @str: string
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;

	new = malloc(sizeof(list_t));

	if (!new)
		return (NULL);

	return (add_helper(&(*head), new, (char *)str));
}
