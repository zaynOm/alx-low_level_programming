#include <stdlib.h>
/**
 * _ptrncpy - copys the values from a pointer to another one
 * @s: pointer to copy to
 * @ptr: pointer to copy from
 * @len: number of values to copy
 */
void _ptrncpy(char *s, char *ptr, int len)
{
	int i = 0;

	while (i < len)
	{
		s[i] = ptr[i];
		i++;
	}
}

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
	unsigned int len;

	s = malloc(sizeof(char) * new_size);

	if (!s || new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	len = (old_size < new_size) ? old_size : new_size;
	_ptrncpy(s, ptr, len);
	free(ptr);
	return ((void *)s);
}
