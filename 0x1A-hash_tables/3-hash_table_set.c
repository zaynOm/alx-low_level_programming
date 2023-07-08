#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table
 *
 * @ht: hash table to add or update the key/value to
 * @key: key to add to the hash table
 * @value: value associated with the key
 * Return: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int size, index;
	hash_node_t *node;

	if (strlen(key) == 0)
		return (0);

	size = ht->size;
	index = key_index((unsigned const char*)key, size);

	node = malloc(sizeof(hash_node_t));
	if (!node)
		return (0);

	node->key = (char *)key;
	node->value = strdup(value);
	node->next = NULL;

	if (!ht->array[index])
	{
		ht->array[index] = node;
		return (1);
	}
	node->next = ht->array[index];
	ht->array[index] = node;
	return (1);
}

