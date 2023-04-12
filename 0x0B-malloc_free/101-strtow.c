#include <stdlib.h>
/**
 * len - counts number of characters & number of words
 * @s: a string
 * @wc: a pointer to an integer
 *
 * Return: length of a string
 */
int len(char *s, int *wc)
{
	int i, sum = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] != ' ')
			sum++;
		if (s[i] != ' ' && s[i + 1] == ' ')
			*wc += 1;
	}

	return (sum + *wc + 1);
}

/**
 * strtow - splits a string into words
 * @str: a string
 *
 * Return: a pointer to an array of strings, or NULL if str is NULL or empty
 */
char **strtow(char *str)
{
	char **s;
	int i, wlen, j = 0;
	int l;
	int wcount = 0;
	int length;

	length = len(str, &wcount);

	s = malloc(wcount + 1 * sizeof(char *));

	if (str == NULL || length == 0 || s == NULL)
		return (NULL);

	for (i = 0; i < wcount; i++)
	{
		wlen = 0;
		for (; str[j]; j++)
		{
			if (str[j] != ' ')
				wlen++;

			if (str[j] != ' ' && str[j + 1] == ' ')
			{
				wlen++;
				j++;
				break;
			}
		}
		s[i] = malloc(sizeof(char) * wlen);

		for (l = 0; str[j - wlen + 1] != ' '; l++)
		{
			s[i][l] = str[j - wlen + 1];
			wlen--;
		}
	}
	s[i] = NULL;
	return (s);
}
