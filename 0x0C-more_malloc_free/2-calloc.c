#include <stdlib.h>
/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: number of elements
 * @size: bytes needed for each element
 *
 * Return: a pointer to the allocated memory, NULL if nmemb or size is 0
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i = 0;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc((nmemb * size));

	if (!ptr)
		return (NULL);

	while (ptr[i])
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
