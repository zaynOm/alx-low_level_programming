/**
 * _strncpy - copies a string
 *
 * @dest: a string
 * @src: the string to copy
 *
 * Return: a pointer
 */
char *_strncpy(char *dest, char *src, int n)
{
	char s[98];
	int i = 0, j = 0;

	while (dest[i])
	{
		s[i] = dest[i];
		i++;
	}
	i = 0;

	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (s[j])
	{
		dest[i] = s[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
