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
	char sepr[] = " ,;.!?\"()\t{}\n";

	if (s[0] >= 'a' && s[0] <= 'z')
		s[0] -= 32;

	while (s[i])
	{
		j = 0;

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
