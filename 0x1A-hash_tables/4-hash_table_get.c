#include "hash_tables.h"
/**
 * hash_table_get - retrieves a value associated with a key.
 * @ht:the hash table to look into.
 * @key: the key to look for.
 *
 * Return: value associated with the element, or NULL if key isn’t found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *temp;

	if (!ht || !key)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];

	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}
