/**
 * _atoi - converts a string to an integer
 *
 * @s: the string to convert
 *
 * Return: an integer
 */
int _atoi(char *s)
{
	int i = 0;
	int num = 0;
	int sign = 1;

	while (s[i])
	{
		if (num != 0 && (s[i] < 48 || s[i] > 58))
			break;

		if (s[i] == '-')
			sign *= -1;

		if (s[i] > 47 && s[i] < 58)
		{
			num = (num * 10) + s[i] - 48;
		}
		i++;
	}
	return (num * sign);
}
