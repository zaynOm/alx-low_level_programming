#include <stdlib.h>

/**
 * len - counts the length of a string
 * @str: string
 *
 * Return: length of str
 */
int len(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{}

	return (i);
}

/**
 * argstostr - concatenates all the arguments of your program
 * @ac: arguments count
 * @av: array of arguments
 *
 * Return: a pointer to a new string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *s;
	int i, j, k = 0;
	int memsum = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
		memsum += len(av[i]);

	s = malloc(sizeof(char) * memsum + ac + 1);

	if (!s)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; j < len(av[i]); j++, k++)
			s[k] = av[i][j];
		s[k] = '\n';
		k++;
	}
	s[k] = '\0';
	return (s);
}
