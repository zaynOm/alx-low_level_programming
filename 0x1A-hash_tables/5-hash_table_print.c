#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table.
 * @ht: the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	char **keys = malloc(sizeof(char *) * ht->size);
	hash_node_t *temp;
	unsigned long int j = 0, i = 0;

	printf("{");
	while (ht->size > i)
	{
		temp = ht->array[i];
		if (temp)
		{
			printf("'%s': '%s', ", temp->key, temp->value);
			keys[j++] = temp->key;
		}
		i++;
	}
	i = 0;
	while (j > i)
	{
		temp = ht->array[key_index((const unsigned char *)keys[i], ht->size)]->next;

		while (temp)
		{
			printf("'%s': '%s', ", temp->key, temp->value);
			temp = temp->next;
		}
		i++;
	}
	printf("}\n");
}
