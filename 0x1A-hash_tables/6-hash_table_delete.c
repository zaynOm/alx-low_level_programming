#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table.
 * @ht: the hash table to delete.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *temp, *next;
	unsigned long int i = 0;

	if (!ht)
		return;

	while (i < ht->size)
	{
		temp = ht->array[i];
		while (temp)
		{
			next = temp->next;
			free(temp->key);
			free(temp->value);
			free(temp);
			temp = next;
		}
		i++;
	}
	free(ht->array);
	free(ht);
}
