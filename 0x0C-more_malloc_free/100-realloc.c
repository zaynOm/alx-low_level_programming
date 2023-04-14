#include <stdlib.h>
/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: the size of the allocated space for ptr
 * @new_size: the new size of the new memory block
 *
 * Return: a pointer with the new size, NULL if new_size is 0 and ptr no null
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *s;
	char *p = ptr;
	unsigned int i, len;
	
	if (old_size == new_size)
		return (ptr);

	s = malloc(sizeof(char) * new_size);
	
	if (ptr == NULL)
		return (s);

	if (!s || (ptr != NULL && new_size == 0))
	{
		free(ptr);
		return (NULL);
	}

	len = (old_size < new_size) ? old_size : new_size;
	for (i = 0; i < len; i++)
		s[i] = p[i];
	free(ptr);
	return (s);
}
