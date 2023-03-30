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
	char alph[] = "Aa4Ee3Oo0Tt7Ll1";

	while (s[i])
	{
		j = 0;
		while (alph[j])
		{
			if (s[i] == alph[j])
			{
				s[i] = alph[j + 1];
				break;
			}
			j++;
		}
		i++;
	}
	s[0] = '3';
	return (s);
}
