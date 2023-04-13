#include <stdlib.h>
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
	unsigned int i, j, lens1, lens2, len;

	lens1 = lens2 = 0;

	while (s1[lens1])
		lens1++;

	while (s2[lens2])
		lens2++;

	len = (lens2 < n) ? lens2 : n;

	str = malloc(sizeof(*str) * (lens1 + len + 1));

	if (!str)
		return (NULL);

	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}

	while (s2 && j < len)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';

	return (str);
}
