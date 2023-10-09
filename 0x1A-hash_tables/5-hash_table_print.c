#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table.
 * @ht: the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *temp;
	char *sep = "";
	unsigned long int i = 0;

	if (!ht)
		return;

	printf("{");
	while (ht->size > i)
	{
		temp = ht->array[i];

		while (temp)
		{
			printf("%s'%s': '%s'", sep, temp->key, temp->value);
			sep = ", ";
			temp = temp->next;
		}
		i++;
	}

	printf("}\n");
}
