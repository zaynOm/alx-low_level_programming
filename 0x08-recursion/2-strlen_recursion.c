/**
 * length - finds the length of a string
 * @s: a string
 * @l: integer
 *
 * Return: the length
 */

int length(char *s, int l)
{
	if (!*s)
		return (l);

	return (length(s + 1, l + 1));

}

/**
 * _strlen_recursion - returns the length of s
 * @s: string
 *
 * Return: the lenght of s
 */
int _strlen_recursion(char *s)
{
	return (length(s, 0));

}
