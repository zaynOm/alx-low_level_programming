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
	unsigned int sum = 0;

	while (*accept)
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == *accept)
			{
				sum += 1;
				break;
			}
			i++;
		}
		accept++;
	}
	return (sum + 1);

}
