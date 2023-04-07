/**
 * _strspn - gets the length of a prefix substring
 * @s: a string
 * @accept: a string
 *
 * Return: the number of bytes in s which consist only of bytes from accept
 *
 */

unsigned int _strspn(char *s, char *accept)
{
	int i;
	int found;
	unsigned int sum = 0;

	while (*s)
	{
		i = 0;
		found = 0;
		while (accept[i])
		{
			if (*s == accept[i])
			{
				found = 1;
				break;
			}
			i++;
		}
		if (!found)
			return (sum);
		s++;
		sum += 1;
	}
	return (sum);

}
