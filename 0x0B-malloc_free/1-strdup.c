#include <stdlib.h>
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

	if (str == NULL)
		return (NULL);

	s = malloc(sizeof(str) - 1);

	if (s == NULL)
		return (NULL);

	for (i = 0; i < (int)sizeof(str) - 1; i++)
		s[i] = str[i];

	return (s);
}
