/**
 * leet - encodes a string into 1337
 *
 * @s: string to encode
 *
 * Return: a pointer to the string
 */
char *leet(char *s)
{
	int i = 0, j;
	char alph[] = "AaEeOoTtLl";
	char num[] = "43071";

	for (; s[i]; i++)
	{
		j = 0;
		for (; alph[j]; j++)
		{
			if (s[i] == alph[j])
				s[i] = num[j / 2];
		}
	}
	return (s);
}
