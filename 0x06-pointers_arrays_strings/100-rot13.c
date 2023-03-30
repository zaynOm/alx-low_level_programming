/**
 * rot13 - encodes a string using rot13
 *
 * @s: string to encode
 *
 * Return: a pointer to s
 */
char *rot13(char *s)
{
	int i = 0, j;
	char alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (; s[i]; i++)
	{
		j = 0;
		for (; alph[j]; j++)
		{
			if (s[i] == alph[j])
			{
				s[i] = rot13[j];
				break;
			}
		}

	}
	return (s);
}
