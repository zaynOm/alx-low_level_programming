/**
 * _isdigit - checks whether the given number is a  digit or not
 * @c: the number to check
 *
 * Return: (1) if it's a digit, otherwise (0).
 */
int _isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);

	return (0);
}
