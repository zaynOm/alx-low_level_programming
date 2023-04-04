/**
 * _strstr - locates a substring
 * @haystack: the string to look in
 * @needle: the string to look for
 *
 * Return: a pointer to the beginning of the located substring,
 * NULL if not found
 */
char *_strstr(char *haystack, char *needle)
{
	char *a, *b;

	while (*haystack)
	{
		a = haystack;
		b = needle;
		while (*b && *haystack == *b)
		{
			haystack++;
			b++;
		}
		
		if (!*b)
			return (a);
		
		haystack++;
	}
	return ('\0');
}

















