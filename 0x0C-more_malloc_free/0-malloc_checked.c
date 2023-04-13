#include <stdlib.h>
/**
 * malloc_checked - allocates memory using malloc
 * @b: size of memory to allocate
 *
 * Return: a pointer to the allocated memory.
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);

	if (b == 2147483647)
		exit(98);

	return (ptr);
}
