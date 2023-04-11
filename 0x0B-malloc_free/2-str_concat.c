#include <stdlib.h>

/**
 * _strlen - counts the length of a string
 * @s: string
 *
 * Return: the length of s
 */
int _strlen(char *s)
{
	int i;

	if (s == NULL)
		return (0);

	for (i = 0; s[i]; i++)
	{}

	return (i);
}

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: a pointer to the concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	int size1 = _strlen(s1);
	int size2 = _strlen(s2) + 1;
	int i, j;
	char *s;

	s = malloc(size1 + size2);

	if (s == NULL)
		return (NULL);

	for (i = 0; i < size1; i++)
		s[i] = s1[i];

	for (j = 0; j < size2; i++, j++)
		s[i] = s2[j];

	return (s);
}
