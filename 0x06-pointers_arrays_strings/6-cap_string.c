/**
 * cap_string - capitalizes all words of a string
 *
 * @s: a given string
 *
 * Return: a pointer to the string
 */
char *cap_string(char *s)
{
	int i = 0, j;
	char sepr[] = " ,;.!?\"(){}\n";

	while (s[i])
	{
		j = 0;

		if (s[i] == '\t')
			s[i] = ' ';

		while (sepr[j])
		{
			if (s[i] == sepr[j])
				if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
					s[i + 1] -= 32;
			j++;
		}
		i++;
	}
	return (s);

}
