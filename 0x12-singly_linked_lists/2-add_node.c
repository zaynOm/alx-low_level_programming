#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: double pointer to the first node
 * @str: string to add in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	new->len = strlen(str);
	new->next = *head;

	*head = new;
	return (*head);
}

