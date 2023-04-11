#include <stdlib.h>
/**
 * create_array - creates an array of chars, and initializes it.
 * @size: size of the array
 * @c: the character to inisialize the array with
 *
 * Return: a pointer to the array, or NULL if it fails or if size = 0.
 */
char *create_array(unsigned int size, char c)
{
	char *s;
	unsigned int i;

	s = malloc(sizeof(char) * size);

	if (s == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
		s[i] = c;

	return (s);
}
