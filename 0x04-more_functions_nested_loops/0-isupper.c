/**
 * _isupper - checks for uppercase character
 * @c: the character to check
 *
 * Return: (1) if c is uppercase, (0) if not
 */
int _isupper(int c)
{
	if (c > 64 && c < 91)
		return (1);

	return (0);
}
