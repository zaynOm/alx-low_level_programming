#define _GNU_SOURCE
#include "hash_tables.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * shash_table_create - allocates space for a sorted hash table
 *
 * @size: size of table
 *
 * Return: address of new table, or NULL if failed
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *newtable;
	unsigned long int idx;

	if (size == 0)
		return (NULL);
	newtable = malloc(sizeof(shash_table_t));
	if (newtable == NULL)
		return (NULL);
	newtable->array = malloc(sizeof(shash_node_t) * size);
	if (newtable->array == NULL)
	{
		free(newtable);
		return (NULL);
	}
	for (idx = 0; idx < size; idx++)
		newtable->array[idx] = NULL;
	newtable->shead = NULL;
	newtable->stail = NULL;
	newtable->size = size;
	return (newtable);
}

/**
 * hashdllsort - sort a node into the proper place in the
 * hash table's sorted list
 *
 * @ht: hash table with sorted dll
 * @movnode: address of node
 *
 * Return: void
 */
void hashdllsort(shash_table_t *ht, shash_node_t *movnode)
{
	shash_node_t *ptr;

	if (movnode->snext != NULL)
		movnode->snext->sprev = movnode->sprev;
	if (movnode->sprev != NULL)
		movnode->sprev->snext = movnode->snext;
	if (ht->shead == NULL)
	{
		ht->shead = ht->stail = movnode;
		return;
	}
	ptr = ht->shead;
	if (strcmp(movnode->key, ptr->key) < 0)
	{
		movnode->snext = ht->shead;
		ht->shead = ht->shead->sprev = movnode;
		return;
	}
	ptr = ptr->snext;
	while (ptr != NULL)
	{
		if (strcmp(movnode->key, ptr->key) < 0)
		{
			movnode->snext = ptr;
			movnode->sprev = ptr->sprev;
			ptr->sprev = movnode;
			if (movnode->sprev != NULL)
				movnode->sprev->snext = movnode;
			return;
		}
		ptr = ptr->snext;
	}
	movnode->sprev = ht->stail;
	ht->stail->snext = movnode;
	ht->stail = movnode;
}

/**
 * hash_table_set - short description
 *
 * Description: long description
 *
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: return description
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	hash_node_t *new_node = NULL, *old_head = NULL;

	if (key == NULL || value == NULL || ht == NULL)
		return (0);
	if (strlen(key) == 0)
		return (0);
	new_node = (hash_node_t *) malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	index = key_index((const unsigned char *) key, ht->size);
	new_node->key = (char *) strdup(key);
	new_node->value = (char *) strdup(value);
	new_node->next = NULL;
	if ((ht->array)[index] == NULL)
	{
		(ht->array)[index] = new_node;
		return (1);
	}
	else
	{
		old_head = (ht->array)[index];
		while (old_head)
		{
			if (strcmp(old_head->key, key) == 0)
			{
				free(old_head->value);
				old_head->value = (char *) strdup(value);
				free(new_node->key);
				free(new_node->value);
				free(new_node);
				return (1);
			}
			old_head = old_head->next;
		}
		old_head = (ht->array)[index];
		new_node->next = old_head;
		(ht->array)[index] = new_node;
		return (1);
	}
}

/**
 * shash_table_get - get value at key
 *
 * @ht: hash table to search
 * @key: key to look up
 *
 * Return: key value if successful, NULL if not
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *ptr;
	unsigned long int idx;

	idx = key_index((const unsigned char *) key, ht->size);
	ptr = ht->array[idx];
	while (ptr != NULL)
		if (strcmp(ptr->key, key) == 0)
			return (strdup(ptr->value));
	return (NULL);
}

/**
 * shash_table_print - print sorted hash table by linked list
 *
 * @ht: hash table to print
 *
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *ptr;

	ptr = ht->shead;
	printf("{");
	if (ptr != NULL)
	{
		printf("'%s': '%s'", ptr->key, ptr->value);
		ptr = ptr->snext;
	}
	while (ptr != NULL)
	{
		printf(", '%s': '%s'", ptr->key, ptr->value);
		ptr = ptr->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - print hash table in reverse by linked list
 *
 * @ht: hast table to print
 *
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *ptr;

	ptr = ht->stail;
	printf("{");
	if (ptr != NULL)
	{
		printf("'%s': '%s'", ptr->key, ptr->value);
		ptr = ptr->sprev;
	}
	while (ptr != NULL)
	{
		printf(", '%s': '%s'", ptr->key, ptr->value);
		ptr = ptr->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - ....
 * @ht: ...
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *ptr, *next;

	if (ht == NULL)
		return;
	ptr = ht->shead;
	while (ptr != NULL)
	{
		next = ptr->snext;
		free(ptr->key);
		free(ptr->value);
		free(ptr);
		ptr = next;
	}
	free(ht->array);
	free(ht);
}
