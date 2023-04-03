#include <stdio.h>
/**
 * _strchr - locates a character in a string
 * @s: the string to look in
 * @c: the char to look for
 *
 * Return: a pointer to the first occurrence of c in s
 */
char *_strchr(char *s, char c)
{
	int i = 0;
	char *p = NULL;

	while (s[i])
	{
		if (s[i] == c)
			p = s + i - 1;
		i++;
	}
	return (p);
}
