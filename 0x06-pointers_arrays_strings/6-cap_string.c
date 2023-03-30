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
	char c;
	char sepr[] = " ,;.!?\"(){}\t\n";

	while (s[i])
	{
		j = 0;
		c = s[i];
		while (sepr[j])
		{
			if (c == sepr[j])
				if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
					s[i + 1] -= 32;
			j++;
		}
		i++;
	}
	return (s);

}
