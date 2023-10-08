#include "hash_tables.h"
#include <stdio.h>

/**
 * create_node - creates a new hash element.
 * @key: the key.
 * @value: the value associated with the key.
 *
 * Return: the new hash element.
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *item = malloc(sizeof(hash_node_t));

	if (!item)
		return (0);

	item->key = strdup(key);
	item->value = strdup(value);
	item->next = NULL;

	return (item);
}

/**
 * hash_table_set - adds an element to the hash table.
 * @ht:  the hash table to add or update the key/value to.
 * @key: the key.
 * @value: the value asspciated with the key.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *item, *curr;

	if (!ht || !key || !value || strlen(key) == 0)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	curr = ht->array[index];

	while (curr)
	{
		if (strcmp(curr->key, key) == 0)
		{
			free(curr->value);
			curr->value = strdup(value);
			return (1);
		}
		curr = curr->next;
	}
	item = create_node(key, value);
	item->next = ht->array[index];
	ht->array[index] = item;

	return (1);
}
