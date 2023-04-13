#include <stdlib.h>
/**
 * _strlen - countes the length of a string
 * @s: a string
 *
 * Return: the length
 */
unsigned int _strlen(char *s)
{
	unsigned int i = 0;

	while (s && s[i])
		i++;

	return (i);
}

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: how much chars to take from s2
 *
 * Return: a pointer to the new string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;
	unsigned int i = 0, j = 0;
	
	str = malloc(sizeof(*str) * (_strlen(s1) + n + 1));

	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}

	while (s2 && j < n)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';

	return (str);
}
