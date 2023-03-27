/**
 * rev_string - reverses a string
 * @s: a string
 */
void rev_string(char *s)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char c;

	while (s[k])
		k++;
	i = --k;

	while (i > k / 2)
	{
		c = s[j];
		*(s + j) = s[i];
		*(s + i) = c;
		i--;
		j++;
	}
}
