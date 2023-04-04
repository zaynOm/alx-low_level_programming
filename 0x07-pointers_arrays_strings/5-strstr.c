/**
 */
char *_strstr(char *haystack, char *needle)
{
	int i, count = 0;

	while (*haystack)
	{
		i = 0;
		while (needle[i])
		{
			if (*haystack == needle[i])
			{
				count += 1;
				haystack++;
				i++;
			}
			i++;
		}
		haystack++;
	}
	return (i == count) ? 1 : 0;

}
