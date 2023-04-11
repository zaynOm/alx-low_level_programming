#include <stdlib.h>

/**
 * _strlen - count the length of a string
 * @str: a string
 *
 * Return: the length of str
 */
unsigned int _strlen(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{}

	return (i);
}




/**
 * _strdup - allocates a space in memory and copy the given string on it.
 * @str: a string
 *
 * Return: a pointer to the dupicate of str, or NULL if str is NULL.
 */
char *_strdup(char *str)
{
	char *s;
	int i;
	unsigned int size;

	size = _strlen(str);

	s = malloc(size);

	if (s == NULL)
		return (NULL);

	for (i = 0; i < (int)size; i++)
		s[i] = str[i];

	return (s);
}
